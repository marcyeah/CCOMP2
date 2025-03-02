/* Implemente un programa que reciba un monto y señale la cantidad minima de billetes y/o monedas necesarias
   de cada monto, para completar el pago. */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int x;
    int n = 200;
    int o = 1;
    float y;
    string p = "";
    string q = "";
    string mon = " sol";
    
    cout << "Ingresa un monto en el formato " << '"' << "sol.cent" << '"' << ": ";
    cin >> y;
    cout << "Para llegar al monto deseado, se necesita: " << endl;
    x = (int)y;
    y = y - x;
    
    while (n) {
        if (x/n > 1 || x/n == 0) {
            p = "s";
            q = "es";
        }
        if (n >= 10) {
            cout << x / n << " billete" << p << " de " << n << ".00" << mon << q << endl;
        }
        if (n < 10) {
            cout << x / n << " moneda" << p << " de " << n << ".00" << mon << q << endl;
        }
        
        x = x - ((x / n) * n);
        n = n / 2;
        if (n >= 10) {
            n = n - n % 10;
        }
    }

    o = 50;
    x = round(y * 10) * 10;
    while (o > 5) {
        if (x / o > 1 || x / o == 0) {
            p = "s";
        }
        mon = " centimos";
        cout << x / o << " moneda" << p << " de " << (float)o/100 << 0 << mon << endl;
        x = x - ((x / o) * o);
        o = o / 2;
        if (o >= 10) {
            o = o - o % 10;
        }
    }
}