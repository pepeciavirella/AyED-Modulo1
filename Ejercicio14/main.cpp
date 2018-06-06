#include <iostream>

/// ---------Ej.MI-14---------
/// Dados 50 números enteros, informar el promedio de
/// los mayores que 100 y la suma de los menores que –10
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int i, numero, sumaMayores, cantidadMayores, sumaMenores;
    float promedioMayores;
    sumaMayores = 0;
    cantidadMayores = 0;
    sumaMenores = 0;
    cout << "Ingrese 50 enteros" << endl;
    for(i = 1; i <= 50; i++)
    {
        cin >> numero;
        if(numero > 100)
        {
            sumaMayores += numero;
            cantidadMayores++;
        }
        else if(numero < -10)
        {
            sumaMenores += numero;
        }
    }
    promedioMayores = (float) sumaMayores/cantidadMayores;
    cout << "El promedio de numeros mayores que 100 fue: " << promedioMayores << endl;
    cout << "Y la suma de numeros menores que -10 fue:   " << sumaMenores << endl;
    return 0;
}
