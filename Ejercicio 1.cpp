/* Implemente un programa que reciba un numero entre el 1 y el 999999 y regrese el nombre del mismo. */

#include <iostream>
#include <string>;
using namespace std;

int main()
{
    int x, y, p;
    int cen = 0;
    int mil = 0;
    string n;
    string c = "";
    cout << "Ingrese un numero entero entre 1 - 999999: ";
    cin >> x;
    y = x;
    p = y;

    if (x > 999999) {
        x = 0;
        cout << "El valor ingresado no es valido" << endl;
    }

    while (x) {
        if (x > 15 && x < 20) {
            cout << "DIECI";
            x = y % 10;
            continue;
        }
        if (x > 20 && x < 30) {
            cout << "VEINTI";
            x = y % 10;
            continue;
        }
        if (x > 100 && x < 200) {
            cout << "CIENTO ";
            x = y % 100;
            continue;
        }

        if (mil == 2 && x == 1) {
            x = 1000;
            y = p;
            mil = 1;
            c = " ";
            cout << "UN" << c;
            continue;
        }

        if (x > 30 && x < 100 && y % 10) {
            c = " Y ";
            x = x - (x % 10);
        }

        if (x >= 200 && x < 900 && !(x / 100 % 2) || x/100 == 3) {
            x = x / 100;
        }

        if (x > 500 && x < 1000 && x/100 % 2) {
            x = x - (x % 100);
            cen = 1;
        }

        if (x > 1000 && x < 2000) {
            x = 1000;
            mil = 1;
            y = y % 1000;
        }

        if (x >= 2000) {
            x = y / 1000;
            y /= 1000;
            mil = 2;
            continue;
        }

        switch (x) {
            case 1: n = "UNO";
                break;
            case 2: n = "DOS";
                break;
            case 3: n = "TRES";
                break;
            case 4: n = "CUATRO";
                break;
            case 5: n = "CINCO";
                break;
            case 6: n = "SEIS";
                break;
            case 7: n = "SIETE";
                break;
            case 8: n = "OCHO";
                break;
            case 9: n = "NUEVE";
                break;
            case 10: n = "DIEZ";
                break;
            case 11: n = "ONCE";
                break;
            case 12: n = "DOCE";
                break;
            case 13: n = "TRECE";
                break;
            case 14: n = "CATORCE";
                break;
            case 15: n = "QUINCE";
                break;
            case 20: n = "VEINTE";
                break;
            case 30: n = "TREINTA";
                break;
            case 40: n = "CUARENTA";
                break;
            case 50: n = "CINCUENTA";
                break;
            case 60: n = "SESENTA";
                break;
            case 70: n = "SETENTA";
                break;
            case 80: n = "OCHENTA";
                break;
            case 90: n = "NOVENTA";
                break;
            case 100: n = "CIEN";
                break;
            case 500: n = "QUINIENTOS";
                break;
            case 700: n = "SETECIENTOS";
                break;
            case 900: n = "NOVECIENTOS";
                break;
            case 1000: n = "MIL";
                break;
            default: 
                if (!x) break;
        }

        if (y >= 200 && y < 900 && x < 10 && !cen) {
            cout << n << "CIENTOS ";
            x = y % 100;
            cen = 1;
            if (mil == 2 && x == 0) {
                x = 1000;
                y = p;
                mil = 1;
            }
            continue;
        }

        if (mil == 2 && (x <= 15 || !(y % 100) || (x < 100 && !(y % 10)))) {
            x = 1000;
            y = p;
            mil = 1;
            c = " ";
            cout << n << c;
            continue;
        }

        if (mil == 1) {
            x = y % 1000;
            y = y % 1000;
            c = " ";
            cout << n << c;
            mil = 0;
            cen = 0;
            continue;
        }
        if (x > 100) {
            x = y % 100;
            c = " ";
            cout << n << c;
            continue;
        }
        if (x > 15 && y % 10) {
            x = y % 10;
            cout << n << c;
            continue;
        }
        cout << n << endl;
        break;
    }
}