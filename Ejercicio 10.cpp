/* Implementar una función que reorganice un arreglo en torno a un pivote según un criterio ascendente o descendente
   para esto se deben crear tres clases con template, una para arreglos ascendentes y otra para descendentes, también
   se debe crear una tercera clase para el objeto pivot y una función llamada transformador que debe contener la lógica
   de ordenamiento usando solo el criterio del pivot (may - piv - min / min - piv - may) no es necesario que el arreglo
   esté ordenado sucesivamente. */

#include <iostream>

template <class T>
class ASC {
    T x;
public:
    ASC(T a) :x(a) {};
    void operator=(T v) {
        x = v;
    }
    bool operator()(T otro) {
        return x > otro;
    }
};

template <class T>
class DESC {
    T x;
public:
    DESC(T a) :x(a) {};
    void operator=(T v) {
        x = v;
    }
    bool operator()(T otro) {
        return x < otro;
    }
};

template <class T>
class pivot {
public:
    int value;
    T op{0};
    pivot(int val = 0) :value(val) {};
    bool operator()(int v) {
        op = value;
        return op(v);
    }
    int operator()() {
        return value;
    }
};

static void print(int* begin, int* end) {
    for (int* i = begin; i <= end; i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

template <class T>
void transform(int* begin, int* end, T piv) {
    int* pos = nullptr;
    int* p = begin;
    int* q = end;
    while (p < q) {
        bool min{1}, max{1};
        if (*p == piv()) {
            pos = p;
        }
        if (piv(*p)) {
            p++;
            min = 0;
        }
        if (*q == piv()) {
            pos = q;
        }
        if (!piv(*q)) {
            q--;
            max = 0;
        }
        if (min && max) {
            std::swap(*p, *q);
            p++;
            q--;
        }
    }
    if (*q == piv()) {
        pos = q;
    }
    if (!pos) {
        std::cout << "El pivot no se ha encontrado en el arreglo" << std::endl;
        return;
    }
    if (!piv(*q)) {
        std::swap(*q, *pos);
    }
    print(begin, end);
}

int main() {
    pivot<ASC<int>> asc(2);
    pivot<DESC<int>> desc(2);
    int a[] = { 10, 2, 1, 3 };
    int size = sizeof(a) / sizeof(a[0]) - 1;

    print(a, a + size);
    transform(a, a + size, asc);
    transform(a, a + size, desc);
}