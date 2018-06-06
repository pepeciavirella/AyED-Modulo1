#include <iostream>

/// ---------Ej.MI-13---------
/// Dados N y M números naturales, informar su producto por sumas sucesivas
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    unsigned int n, m, contador, producto; // Use unsigned para asegurarme que sean naturales, enteros sin signo
    cout << "Ingrese dos numeros" << endl;
    cin >> n >> m;
    producto = 0;
    for(contador = 1; contador <= m; contador++)
    {
        producto += n;
    }
    cout << "El producto entre ambos es " << producto << endl;
    return 0;
}
