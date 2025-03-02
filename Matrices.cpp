/* Escriba un programa que multiplique dos matrices 3x3 y almacene el resultado en una tercera matriz usando punteros. */ 

#include <iostream>

static void mult_matrix(int (*p)[3][3]);
static void print(int (*p)[3][3]);

int main() {
	int matrix[3][3][3] = { {{1,4,7}, {2,5,8}, {3,6,9}} , {{1,-1,2}, {2,-1,2}, {3,-3,0}} , {} };
	mult_matrix(matrix);
	print(matrix);
}

static void mult_matrix(int (*p)[3][3]) {
	int i{0}, k{0};
	while (k < 3) {
		for (int (*q)[3] = *p; q < *p + 1; q++, k++) {
			int c = 0;
			while (c < 3) {
				for (int* j = **(p + 1) + c; j < **(p + 2); c++, i++) {
					int suma = 0;
					for (int* r = *(q + k); r < *(q + k + 1); r++, j+=3) {
						suma += *r * *j;
					}
					*(**(p + 2) + i) = suma;
				}
			}
		}
	}
}

static void print(int (*p)[3][3]) {
	for (int i = 0; i < 3; i++) {
		char arr[] = { 'A', 'B'};
		if (i < 2) {
			std::cout << "Matriz " << arr[i] << std::endl;
		}
		else {
			std::cout << "Matriz " << arr[0] << " * " << arr[1] << std::endl;
		}
		for (int (*q)[3] = *(p + i); q < *(p + i + 1); q++) {
			for (int* r = *q; r < *(q + 1); r++) {
				std::cout << *r << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}