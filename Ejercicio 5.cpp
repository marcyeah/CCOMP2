/* Crea un programa que ordene una lista usando el algoritmo de ordenamiento cocktail, usando punteros. */

#include <iostream>
using namespace std;

static void print(int a[], int n);
static void cocktail(int* p, int* q);

int main() {
    int A[10] = { 10,9,8,7,5,4,3,2,1 };
    int size = sizeof(A) / sizeof(A[0]);
    int* start = A;
    int* end = A + size - 1;

    print(A, size);
    cocktail(start, end);
    print(A, size);
}

static void print(int a[], int n) {
    for (int* p = a; p < a + n; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

static void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

static void cocktail(int* p, int* q) {
    bool ord = false;
    while (p < q && !ord) {
        ord = true;
        for (int* r = p; r < q; r++) {
             if (*r > *(r + 1)) {
                 swap(*r, *(r + 1));
                 ord = false;
             }
        }

        for (int* r = q; r > p; r--) {
            if (*r < *(r - 1)) {
                swap(*r, *(r - 1));
                ord = false;
            }
        }
    }
}