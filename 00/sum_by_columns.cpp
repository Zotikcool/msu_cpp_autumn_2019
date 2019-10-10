#include <chrono>
#include <iostream>
using namespace std;
class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using microseconds = std::chrono::microseconds;
public:
	Timer()
		: start_(clock_t::now())
	{
	}

	~Timer()
	{
		const auto finish = clock_t::now();
		const auto us =
			std::chrono::duration_cast<microseconds>
			(finish - start_).count();
		std::cout << us << " us" << std::endl;
	}

private:
	const clock_t::time_point start_;
};

enum { MATRIX_SIZE = 10000 };

int main() {
	volatile unsigned int sum = 0;
	unsigned int **matrix = new unsigned int *[MATRIX_SIZE];
	unsigned int *store = new unsigned int[MATRIX_SIZE * MATRIX_SIZE];
	for (int i = 0; i < MATRIX_SIZE; ++i) {
		matrix[i] = store + i * MATRIX_SIZE;
	}
	Timer t;
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			sum += matrix[i][j];
		}
	}
	return 0;
}
