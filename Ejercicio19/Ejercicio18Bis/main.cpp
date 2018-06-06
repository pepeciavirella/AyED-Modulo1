#include <iostream>

/// ---------Ej.MI-19.C---------
/// Reescribir el algoritmo 18, utilizando un ciclo 1-n
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
    do{
        if((n%3 == 0) && (n%5 != 0))
        {
            cout << n << endl;
            contador++;                 //Solo aumento el contador si es un numero que me interesa
        }
        n++;
    }while(contador <= m);
    return 0;
}
