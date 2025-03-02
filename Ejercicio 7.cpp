/* Crea una función merge que reciba dos listas enlazadas ordenadas de forma ascendente y une los nodos que
   correspondan, de manera que se mantengan ordenados, al final todos los elementos deben estar en la primera lista,
   dejando a la segunda lista vacía. */

#include <iostream>

struct comp {
    bool operator() (int a, int b) {
        return a > b;
    }
};

struct nodo {
    int value;
    nodo* next;
    nodo(int v, nodo* n = nullptr) {
        value = v;
        next = n;
    }
};

static void arratole(int* begin, int* end, nodo*& HEAD) {
    for (int* i = end; i >= begin; i--) {
        HEAD = new nodo(*i, HEAD);
    }
}

static void printle(nodo* lista, char n) {
    std::cout << "le" << n << " -> ";
    nodo* tmp = lista;
    while (tmp) {
        std::cout << tmp->value << " -> ";
        tmp = tmp->next;
    }
    std::cout << "NULL" << std::endl;
}

static void merge(nodo*& A, nodo*& B) {
    comp comp;
    nodo *p, *r, *ar;
    p = A;
    ar = nullptr;
    while (true) {
        if (comp(p->value, B->value)) {
            r = B;
            if (!ar) {
                A = B;
            }
            else {
                ar->next = r;
            }
            if (B->next) {
                B = B->next;
            }
            else {
                B->next = p;
                break;
            }
        }
        else {
            r = p;
            if (ar) {
                ar->next = r;
            }
            if (p->next) {
                p = p->next;
            }
            else {
                p->next = B;
                break;
            }
        }
        ar = r;
    }
    B = nullptr;
}

int main() {
    nodo* lea = nullptr;
    nodo* leb = nullptr;
    int sizea, sizeb;
    int arra[] = { 1,8,13,20,23,31,38,40,53 };
    int arrb[] = { 13,17,20,25,30,38 };
    sizea = sizeof(arra) / sizeof(arra[0]) - 1;
    sizeb = sizeof(arrb) / sizeof(arra[0]) - 1;

    arratole(arra, arra + sizea, lea);
    printle(lea,'a');

    arratole(arrb, arrb + sizeb, leb);
    printle(leb, 'b');

    merge(lea, leb);
    printle(lea, 'a');

    printle(leb, 'b');
}