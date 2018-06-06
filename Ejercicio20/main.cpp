#include <iostream>

/// ---------Ej.MI-20---------
/// Dados 10 valores informar el mayor
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int i;
    float valor, mayor;
    cout << "Ingrese un valor" << endl;  //Para que el primero ya sea el mayor, y pueda ingresar cualquier numero, positivo o negativo
    cin >> valor;
    mayor = valor;
    for(i = 1; i <= 9; i++)
    {
        cout << "Ingrese un valor" << endl;
        cin >> valor;
        if(valor > mayor)
        {
            mayor = valor;
        }
    }
    cout << "El mayor numero ingresado fue " << mayor << endl;
    return 0;
}
