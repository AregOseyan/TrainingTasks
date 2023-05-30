#include <iostream>
#include <chrono>

void mul(int matrix1[2][2], int matrix2[2][2]) {
	int tmp1 = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0];
	int tmp2 = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1];
	int tmp3 = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0];
	int tmp4 = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1];
	matrix1[0][0] = tmp1;
	matrix1[0][1] = tmp2;
	matrix1[1][0] = tmp3;
	matrix1[1][1] = tmp4;
}

void power(int matrix[2][2], int n) {
	if (n == 0 || n == 1) { return; }
	int matrix1[2][2] = {{1, 1}, {1, 0}};
	power(matrix, n / 2);
	mul(matrix, matrix);
	if (n % 2) {
		mul(matrix, matrix1);
	}
}

int fibonacci_with_matrix(int n) {
	int matrix[2][2] = {{1, 1}, {1, 0}};
	if (n == 0) {
		return 0;
	}
	power(matrix, n - 1);
	return matrix[0][0];
}

int fibonacci(int n) {
	if (n <= 2) { return 1; }
	return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
	std::cout << "Enter number of Fibonacci: ";
	int n;
	std::cin >> n;
	if (n < 0) {
		std::cout << "Error!! : Invalid input parameter\n";
		return {};
	}
	std::cout << std::endl;
	auto start_time = std::chrono::steady_clock::now();
	std::cout << "Result is(with using matrix): " << fibonacci_with_matrix(n);	
	std::cout << std::endl;
	auto end_time = std::chrono::steady_clock::now();
	std::cout << "Amazing time is : ";
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() 
		<< " nanoseconds\n";
	std::cout << std::endl;
	auto start_time1 = std::chrono::steady_clock::now();
	std::cout << "Result is: " << fibonacci(n);
	std::cout << std::endl;
	auto end_time1 = std::chrono::steady_clock::now();
	std::cout << "Amazing time is : ";
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1).count() 
		<< " nanoseconds\n";

	return {};
}
