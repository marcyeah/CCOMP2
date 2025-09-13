/*Cree un programa que multiplique dos matrices 3x3 usando punteros. PD: disfruté mucho hacer este código, la primera versión, me costó
bastante, el código era más complicado y usaba contadores en vez de solo punteros, la solución resultó ser más fácil de lo que pensaba,
esto lo hice un año después de la primera versión, tal vez no sea el mejor código, pero estoy orgulloso, de todas formas no lo hubiera
terminado sin Kevin, admito que recibí un poco de su ayuda en cuanto a la sintaxis que se me había olvidado jeje.*/
#include <iostream>

static void mult_matrix(int (*A)[3], int (*B)[3], int (*C)[3]) {
    int* c = *C;
    for (int(*p)[3] = A; p < (A + 3); p++) {
        for (int* q = *B; q < *B + 3; q++, c++) {
            *c = (**p * *q) + (*(*p + 1) * *(q + 3)) + (*(*p + 2) * *(q + 6));
        }
    }
}

static void print(int (*C)[3]) {
    for (int* p = *C; p < *(C + 3); p++) {
        std::cout << *p << " ";
    }
}

int main() {
    int A[3][3] = { {2, 4, 6}, {2, 1, 4}, {9, 3, 5} };
    int B[3][3] = { {2, 4, 6}, {2, 1, 4}, {9, 3, 5} };
    int C[3][3] = {};
    mult_matrix(A, B, C);
    print(C);
}
