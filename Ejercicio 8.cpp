/* Implementa una lista enlazada circular con las funciones de añadir, eliminar y buscar elementos,
   no esta permitido modificar los valores ni crear LEC idénticas a la original. También se debe implementar
   el destructor usando la función eliminar. */

#include <iostream>

template <class T>
struct nodo {
    T value;
    nodo<T>* next;
    nodo(T v, nodo<T>* n = nullptr) {
        value = v;
        next = n;
    }
};

template <class T>
class LEC {
    nodo<T>* HEAD = nullptr;
public:
    void ADD(T value);
    void DEL(T value);
    bool find(T value, nodo<T>*& pos);
    void print();
    ~LEC();
};

template <class T>
void LEC<T>::ADD(T value) {
    nodo<T>* pos;
    std::cout << "obj.ADD(" << value << ")" << std::endl;
    if (!find(value, pos)) {
        if (!pos) {
            if (!HEAD) {
                HEAD = new nodo<T>(value, HEAD);
                HEAD->next = HEAD;
            }
            else {
                nodo<T>* tmp = HEAD;
                nodo<T>* p = tmp->next;
                HEAD = new nodo<T>(value, HEAD);
                while (p->next != tmp) {
                    p = p->next;
                }
                p->next = HEAD;
            }
        }
        else {
            pos->next = new nodo<T>(value, pos->next);
        }
    }
    else {
        std::cout << "El elemento " << value << " ya se encuentra en la lista" << std::endl;
    }
}

template <class T>
void LEC<T>::DEL(T value) {
    nodo<T>* tmp, * pos;
    std::cout << "obj.DEL(" << value << ")" << std::endl;
    if (find(value, pos)) {
        if (!pos) {
            if (HEAD->next == HEAD) {
                tmp = HEAD;
                HEAD->next = nullptr;
                HEAD = HEAD->next;
                delete tmp;
            }
            else {
                tmp = HEAD;
                HEAD = tmp->next;
                nodo<T>* p = tmp->next;
                while (p->next != tmp) {
                    p = p->next;
                }
                p->next = HEAD;
                delete tmp;
            }
        }
        else {
            tmp = pos->next;
            pos->next = tmp->next;
            delete tmp;
        }
    }
    else {
        std::cout << "El elemento " << value << " no se encuentra en la lista" << std::endl;
    }
}

template <class T>
bool LEC<T>::find(T value, nodo<T>*& pos) {
    pos = nullptr;
    nodo<T>* q = nullptr;
    for (nodo<T>* p = HEAD; p != q && p->value <= value; pos = p, p = p->next) {
        q = HEAD;
        if (p->value == value) {
            return true;
        }
    }
    return false;
}

template <class T>
void LEC<T>::print() {
    std::cout << "HEAD -> ";
    nodo<T>* q = nullptr;
    for (nodo<T>* p = HEAD; p != q; p = p->next) {
        q = HEAD;
        std::cout << p->value << " -> ";
    }
    if (!HEAD) {
        std::cout << "NULL" << std::endl;
    }
    else {
        std::cout << "HEAD" << std::endl;
    }
}

template <class T>
LEC<T>::~LEC() {
    nodo<T>* q = nullptr;
    std::cout << "\nLlamada al destructor" << std::endl;
    print();
    while (HEAD) {
        DEL(HEAD->value);
        print();
    }
}

int main() {
    std::cout << "Creacion de objeto de la clase LEC" << std::endl;
    LEC <int> obj;
    obj.print();

    std::cout << "\nLlenado del objeto de clase LEC" << std::endl;
    int array[] = { 9,3,7,-1,10,10,1 };
    int size = sizeof(array) / sizeof(array[0]) - 1;
    obj.print();
    for (int* a = array; a <= array + size; a++) {
        obj.ADD(*a);
        obj.print();
    }

    std::cout << "\nLlamada al metodo DEL" << std::endl;
    obj.print();
    obj.DEL(-1);
    obj.print();
    obj.DEL(-2);
    obj.print();
}