/* Implementar una lista doblemente enlazada circular con un iterador para recorrer e insertar elementos ordenadamente. */

#include <iostream>

template <class T>
struct nodo {
    T value;
    nodo<T>* next;
    nodo<T>* prev;
    nodo(T v, nodo<T>* n = nullptr, nodo<T>* p = nullptr){
        value = v;
        next = n;
        prev = p;
    }
};

template <class T>
class Iterator {
    nodo<T>* it;
public:
    void operator =(nodo<T>* pointer) {
        it = pointer;
    }

    bool operator !=(nodo<T>* otro) {
        return it != otro;
    }

    void operator =(T value) {
        it->value = value;
    }

    nodo<T>* operator++(int) {
        it = it->next;
        return it;
    }

    nodo<T>* operator--(int) {
        it = it->prev;
        return it;
    }

    T operator*() {
        return it->value;
    }

    bool operator<=(nodo<T>* otro) {
        return it <= otro;
    }

    static friend std::istream& operator>>(std::istream& input, Iterator D) {
        input >> (D.it->value);
        return input;
    }
};

template <class T, class I>
class LDEC {
    nodo<T>* HEAD = nullptr;
public:
    I It{};
    void ADD(T value);
    void DEL(T value);
    bool find(T value, nodo<T>*& pos);
    void printasc();
    void printdesc();
    ~LDEC();
};

template <class T, class I>
void LDEC<T,I>::ADD(T value) {
    nodo<T>* pos;
    std::cout << "obj.ADD(" << value << ")" << std::endl;
    if (!find(value, pos)) {
        if (!pos) {
            if (!HEAD) {
                HEAD = new nodo<T>(value, HEAD, HEAD);
                HEAD->next = HEAD;
                HEAD->prev = HEAD;
            }
            else {
                nodo<T>* tmp = HEAD;
                nodo<T>* p = tmp->prev;
                HEAD = new nodo<T>(value, HEAD);
                p->next = HEAD;
                tmp->prev = HEAD;
                HEAD->prev = p;
            }
        }
        else {
            nodo<T>* tmp = pos->next;
            pos->next = new nodo<T>(value, pos->next, pos);
            tmp->prev = pos->next;
        }
    }
    else {
        std::cout << "El elemento " << value << " ya se encuentra en la lista" << std::endl;
    }
}

template <class T, class I>
void LDEC<T,I>::DEL(T value) {
    nodo<T>* tmp, * pos;
    std::cout << "obj.DEL(" << value << ")" << std::endl;
    if (find(value, pos)) {
        if (!pos) {
            if (HEAD->next == HEAD) {
                tmp = HEAD;
                HEAD->next = nullptr;
                HEAD->prev = nullptr;
                HEAD = HEAD->next;
                delete tmp;
            }
            else {
                tmp = HEAD;
                HEAD = HEAD->next;
                nodo<T>* p = tmp->prev;
                p->next = HEAD;
                HEAD->prev = p;
                delete tmp;
            }
        }
        else {
            tmp = pos->next;
            pos->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
        }
    }
    else {
        std::cout << "El elemento " << value << " no se encuentra en la lista" << std::endl;
    }
}

template <class T, class I>
bool LDEC<T,I>::find(T value, nodo<T>*& pos) {
    pos = nullptr;
    nodo<T>* q = nullptr;
    for (nodo<T>* p = HEAD; p != q && p->value <= value; p = p->next, pos = p->prev) {
        q = HEAD;
        if (p->value == value) {
            return true;
        }
        
    }
    return false;
}

template <class T, class I>
void LDEC<T,I>::printasc() {
    std::cout << "HEAD -> ";
    nodo<T>* q = nullptr;
    for (It = HEAD; It != q; It++) {
        q = HEAD;
        std::cout << *It << " -> ";
    }
    if (!HEAD) {
        std::cout << "NULL" << std::endl;
    }
    else {
        std::cout << "HEAD" << std::endl;
    }
}

template <class T, class I>
void LDEC<T, I>::printdesc() {
    std::cout << "HEAD <- ";
    nodo<T>* q = nullptr;
    for (It = HEAD->prev; It != q; It--) {
        q = HEAD->prev;
        std::cout << *It << " <- ";
    }
    if (!HEAD) {
        std::cout << "NULL" << std::endl;
    }
    else {
        std::cout << "HEAD" << std::endl;
    }
}

template <class T, class I>
LDEC<T,I>::~LDEC() {
    nodo<T>* q = nullptr;
    std::cout << "\nLlamada al destructor" << std::endl;
    printasc();
    while (HEAD) {
        printdesc();
        DEL(HEAD->value);
        printasc();
    }
}

int main() {
    std::cout << "Creacion de objeto de la clase LDEC" << std::endl;
    LDEC <int, Iterator<int>> obj;
    obj.printasc();

    std::cout << "\nLlenado del objeto de clase LDEC" << std::endl;
    int array[] = { 9,3,7,-1,10,10,1 };
    int size = sizeof(array) / sizeof(array[0]) - 1;
    obj.printasc();
    for (int* a = array; a <= array + size; a++) {
        obj.ADD(*a);
        obj.printasc();
        obj.printdesc();
    }

    std::cout << "\nLlamada al metodo DEL" << std::endl;
    obj.printasc();
    obj.printdesc();
    obj.DEL(7);
    obj.printasc();
    obj.printdesc();
    obj.DEL(10);
    obj.printasc();
    obj.printdesc();
}