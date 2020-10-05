/*
This program approximates Pi using the Leibniz method, or

Pi = 4/1 - 4/2 + 4/3 - 4/4 + ... + 4/n

Since the program uses the long double type, perfect precision is impossible.
For any practical use the program needs to be modified to use an arbitratry
precision floating point implementation, such as Boost.Multiprecision.

The program has been optimised to simply add up all pairs that are subtracted
from each other and it can make use of an arbitrary number of hardware threads.
This means that it could theoretically fully scale on a supercomputer with
thousands of cores - though of course the aforementioned precision problem
makes that rather pointless anyway unless fixed.

While I could've made the program use as many threads as I would've liked,
the scaling curve really drops off beyond the hardware thread count on an intense
calculation program like this so I decided to just hook up to that. On cases
where the program is unable to determine how many threads are available, it will
automatically use only two threads to avoid locking up the system. Most
hardware should be able to handle that much.

The program was tested on a system running an i9-9900k at a 5.1 GHz all-core overclock.
That is, 16 threads in total, and with 32 GB (4x 8 GB) of system RAM.
 -L
*/

#define DEBUG_MODE true
#ifdef DEBUG_MODE
#  define DEBUG(x) do {std::cerr << "DEBUG: " << x << std::endl;} while (0)
#else
#  define DEBUG_MODE false
#  define DEBUG(x)  do {} while (0)
#endif

#include <chrono>   // std::chrono::{time_point, high_resolution_clock}
#include <iostream> // std::{cin, cout, cerr, endl}
#include <iomanip>  // std::setprecision
#include <vector>   // std::vector
#include <thread>   // std::thread::hardware_concurrency
#include <future>   // std::future

using std::vector;

// A workaround for thread workers only accepting one argument
struct WorkerData {
	unsigned long long start;
	unsigned long long stop;
	std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

struct Result {
	long double return_value;
	std::chrono::duration<double> elapsed_time;
};

Result count_pi_range(WorkerData start_stop) {
	// Calculates the pi sequence in a given range

	long double result{};
	unsigned long long start{ start_stop.start };
	unsigned long long stop{ start_stop.stop };

	for (start; start <= stop; ++start) {

		if (start % 2 && start != 0) {
			result += (4. / ((long double)start * 2.0L - 1.0L));
		}
		else {
			result -= (4. / ((long double)start * 2.0L - 1.0L));
		}

	}

	return Result{ result, std::chrono::high_resolution_clock::now() - start_stop.start_time };
}

long double count_pi_multithreaded(size_t n) {
	// Calculates pi using the sequence technique by pooling all available hardware threads

	if (n <= 0) {
		return .0L;
	}

	long double result{};

	unsigned long long nthreads = std::thread::hardware_concurrency();
	if (nthreads == 0UL) { // If failed to detect hardware threads, fall back to 2, as it's almost guaranteed to be available
		nthreads = 2UL;
	}

	DEBUG("Number of hardware threads: " << nthreads);

	vector<std::future<Result>> threadpool;
	threadpool.reserve(nthreads);

	// Populate the threadpool
	for (unsigned long long i{}; i < nthreads; ++i) {

		unsigned long long start, stop;
		start = (n / nthreads) * i + 1;

		if (nthreads - 1 == i) {
			stop = n;
		}
		else {
			stop = (n / nthreads) * (i + 1ULL);
		}

		DEBUG("Thread #" << i + 1 << ": start: " << start << " stop: " << stop);

		threadpool.push_back(std::async(
			count_pi_range,
			WorkerData{
				start,
				stop,
				std::chrono::high_resolution_clock::now()
			}
		));
	}

	std::cout << std::endl;

	// Join the results of the threadpool
	int t_num{ 1 };
	for (auto& thread : threadpool) {

		auto thread_result = thread.get();

		DEBUG("Result from thread #" << t_num++ << ": " << thread_result.return_value);
		DEBUG("Thread finished in " << thread_result.elapsed_time.count() << " seconds.\n");

		result += thread_result.return_value;

	}

	return result;

}

int main() {

	// Check if the program is running on / compiled for hardware that supports 64-bit accuracy
	const int BITS = [](size_t size) {

		switch (size) {

		case 8:
			DEBUG("Using 64-bit accuracy");
			return 64;

		case 4:
		case 5:
		case 6:
		case 7:
			DEBUG("Warning: using 32-bit accuracy");
			return 32;

		case 2:
		case 3:
			DEBUG("Warning: using 16-bit accuracy");
			return 16;

		default:
			DEBUG("Warning: using 8-bit accuracy");
			return 8;

		}

	}(sizeof(void*));

	unsigned long long terms;
	std::cout << "Enter number of terms: ";
	std::cin >> terms;

	auto pi = count_pi_multithreaded(terms);

	std::cout << "Pi: " << std::setprecision(BITS) << pi << std::endl;

	return 0;
}
