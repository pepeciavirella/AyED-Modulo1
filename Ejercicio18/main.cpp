#include <iostream>

/// ---------Ej.MI-18---------
/// Dado un valor M determinar y emitir un listado con los M primeros múltiplos de
/// 3 que no lo sean de 5, dentro del conjunto de los números naturales.
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    unsigned int m, contador, n;
    contador = 1;
    n = 1;
    cout << "Ingrese la cantidad de multiplos de 3 y no de 5 a listar" << endl;
    cin >> m;
    cout << endl;                       //Por estetica :P
    while(contador <= m)
    {
        if((n%3 == 0) && (n%5 != 0))
        {
            cout << n << endl;
            contador++;                 //Solo aumento el contador si es un numero que me interesa
        }
        n++;
    }
    return 0;
}
