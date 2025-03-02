/* Implemente un programa que separe los elementos de un arreglo de enteros, en pares e impares, sin alterar su orden
   inicial. La función split recibe dos punteros, uno que punte al inicio de la lista y otro al final. */

#include <iostream>
using namespace std;

static void print(int a[], int n);
static void split(int* p, int* q);

int main() {
    int A[] = { 11,12,13,14,15,10,20,30,40,50 };
    int size = sizeof(A) / sizeof(A[0]);
    int* start = A;
    int* end = A + (size - 1);

    print(A, size);
    split(start, end);
    print(A, size);
}

static void print(int a[], int n) {
    for (int* p = a; p < a + n; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

static int odd(int* p, int* q) {
    int cont = 0;
    while (p <= q) {
        if (*p % 2) {
            cont++;
        }
        p++;
    }
    return cont;
}

static void quick_sort(int* p, int* q) {
    if (q <= p) {
        return;
    }
    int* i = p - 1;
    for (int* j = p; j <= q; j++) {
        if (*j < *q) {
            i++;
            swap(*i, *j);
        }
    }
    i++;
    swap(*i, *q);
    quick_sort(p, i - 1);
    quick_sort(i + 1, q);
}

static void split(int* p, int* q) {
    //quick_sort(p, q); // Habilita esta línea de comando si quieres ordenar la lista, el profesor no fue muy específico ese día XD
    int cont = odd(p, q);
    unsigned int contp = q - p - cont + 1;
    while (cont) {
        if (*p % 2) {
            swap(*p, *q);
            if (!contp) {
                break;
            }
            for (int* r = q - 1; r > p; r--) {
                swap(*p, *r);
            }
        }
        else {
            p++;
            continue;
        }
        cont--;
        contp--;
    }
}