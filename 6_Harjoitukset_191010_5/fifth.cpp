#define DEBUG_MODE true
#ifdef DEBUG_MODE
#  define DEBUG(x) do {std::cerr << x << std::endl;} while (0)
#else
#  define DEBUG(x)  do {} while (0)
#endif

#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <future>

using std::vector;

// A workaround for threads only accepting one argument
struct StartStop {
	size_t start;
	size_t stop;
};


long double count_pi_range(StartStop start_stop) {
	// Calculates the pi sequence in a given range
	long double result = 0.0;

	size_t start=start_stop.start, stop=start_stop.stop;

	for (start; start <= stop; ++start) {
		if (start % 2 && start != 0) {
			result += (4. / ((long double)start * 2. - 1.));
		}
		else {
			result -= (4. / ((long double)start * 2. - 1.));
		}

	}

	return result;
}

long double count_pi_multithreaded(size_t n) {
	// Calculates pi using the sequence technique by pooling all available threads

	if (n <= .0) {
		return .0;
	}

	long double result = 0.0;

	unsigned long nthreads = std::thread::hardware_concurrency();
	if (nthreads == 0UL) { // If failed to detect hardware threads, fall back to 2, as it's almost guaranteed to be available
		nthreads = 2UL;
	}

	DEBUG(nthreads);

	vector<std::future<long double>> threadpool;
	threadpool.reserve(nthreads);

	// Populate the threadpool
	for (unsigned int i = 0; i < nthreads; ++i) {
		size_t start, stop;
		start = (n / nthreads) * i + 1;
		stop = (n / nthreads) * (i + 1);
		DEBUG("Thread #" << i + 1 << ": start: " << start << " stop: " << stop);
		threadpool.push_back(std::async(count_pi_range, StartStop{ start, stop }));
	}

	// Join the results of the threadpool
	for (auto &thread : threadpool) {
		auto thread_result = thread.get();
		DEBUG(thread_result);
		result += thread_result;
	}

	return result;

}

int main(void) {
	size_t terms;
	std::cout << "Enter number of terms: ";
	std::cin >> terms;

	std::cout << "Pi: " << std::setprecision(32) << count_pi_multithreaded(terms) << std::endl;
}
