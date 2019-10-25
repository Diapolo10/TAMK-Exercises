//#define DEBUG_MODE true
#ifdef DEBUG_MODE
#  define DEBUG(x) do {std::cerr << x << std::endl;} while (0)
#else
#  define DEBUG_MODE false
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
	unsigned long long start;
	unsigned long long stop;
	unsigned long long thread_num;
};


long double count_pi_range(StartStop start_stop) {
	// Calculates the pi sequence in a given range

	long double result = 0.0;
	unsigned long long start=start_stop.start, stop=start_stop.stop;

	unsigned long long quarter = stop - start / 4;
	unsigned long long half    = stop - start / 2;
	unsigned long long three_quarters = ((stop - start) * 3) / 4;

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

	long double result = 0.0L;

	unsigned long long nthreads = std::thread::hardware_concurrency();
	if (nthreads == 0UL) { // If failed to detect hardware threads, fall back to 2, as it's almost guaranteed to be available
		nthreads = 2UL;
	}

	DEBUG("Number of hardware threads: " << nthreads);

	vector<std::future<long double>> threadpool;
	threadpool.reserve(nthreads);

	// Populate the threadpool
	for (unsigned long long i = 0; i < nthreads; ++i) {
		unsigned long long start, stop;
		start = (n / nthreads) * i + 1;
		if (nthreads - 1 == i) {
			stop = n;
		}
		else {
		DEBUG(thread_result);
		result += thread_result;
	}

	return result;

}

int main(void) {

	// Check if program was compiled with x86 instead of x86_64
	size_t test_num = 4294967295U;
	const int BITS = 64;
	if (test_num > test_num+1) {
		const int BITS = 32;
		DEBUG("Warning: accuracy of results may vary, as the program was compiled in 32-bit mode");
	}

	unsigned long long terms;
	std::cout << "Enter number of terms: ";
	std::cin >> terms;

	auto pi = count_pi_multithreaded(terms);

	std::cout << "Pi: " << std::setprecision(BITS) << pi << std::endl;
	
	return EXIT_SUCCESS;
}
