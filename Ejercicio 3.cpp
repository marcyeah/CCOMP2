/* Implemente un programa que ordene las dos mitades de una lista usando el algoritmo de insertion sort,
   la función merge debe recibir dos punteros, uno que apunte al inicio y otro que apunte al medio. */

#include <iostream>
using namespace std;

static void print(int a[], int n);
static void merge(int* p, int* q);

int main() {
    int A[10] = { 11,12,13,14,15,10,20,30,40,50 };
    int size = sizeof(A) / sizeof(A[0]);
    int* start = A;
    int* mid = A + (size / 2);

    print(A, size);
    merge(start, mid);
    print(A, size);
}

static void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

static void print(int a[], int n) {
    for (int* p = a; p < a + n; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

static void merge(int* p, int* q) {
    int* end = p + (((q - p) * 2) - 1);
    while (q <= end) {
        for (int* r = p; r < q; r++) {
            if (*q < *r) {
                swap(*r, *q);
            }
        }
        q++;
    }
}