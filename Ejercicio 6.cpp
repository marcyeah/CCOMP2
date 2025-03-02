/* Crea un programa que reciba una frase y verifique si es palindromo o no. Utilice punteros char. */

#include <iostream>

static bool palindromo(char* p);

int main() {
    char a[100] = {};
    char* p = a;
    std::cout << "Ingrese una frase: ";
    std::cin.getline(a, 100, '\n');
    std::cout << '"' << a << '"';
    if (palindromo(p)) {
        std::cout << " es palindromo" << std::endl;
    }
    else {
        std::cout << " no es palindromo" << std::endl;
    }
}

static void conv(char &a) {
    if (a >= 'A' && a <= 'Z') {
        a += 32;
    }
}

static void space(char* &p, char* &q) {
    while (*p == ' ') {
        p++;
    }
    while (*q == ' ') {
        q--;
    }
}

static bool palindromo(char* p) {
    int cont = 0;
    for (char* q = p; *q; q++) {
        cont++;
    }
    char* end = p + cont;
    for (char* q = end - 1; q > p; q--) {
        space(p, q);
        conv(*p);
        conv(*q);
        if (*p != *q) {
            return false;
        }
        p++;
    }
    return true;
}