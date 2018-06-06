#include <iostream>

/// ---------Ej.MI-5---------
/// Dados dos valores enteros A y B, informar la suma, la resta y el producto
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int x, y;
    cout << "Ingrese dos enteros distintos" << endl;
    cin >> x >> y;
    if(x == y)
    {
        cout << "Ambos son iguales" << endl;
    }
    else if(x > y)
    {
        cout << "El mayor entre ambos es " << x << endl;
    }
    else
    {
        cout << "El mayor entre ambos es " << y << endl;
    }
    return 0;
}
