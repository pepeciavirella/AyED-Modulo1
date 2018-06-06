#include <iostream>

/// ---------Ej.MI-16---------
/// Ingresar e informar valores, mientras que el valor ingresado
/// no sea negativo. Informar la cantidad de valores ingresados
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    float numero;
    int cantidad = 0;
    do{
        cout << "Ingrese un numero no negativo, o bien uno negativo para detener el ingreso" << endl;
        cin >> numero;
        cantidad++;  //El numero negativo que frene el ingreso también contará entre la cantidad
    }while(numero >= 0);
    cout << "Se ingresaron, en total, " << cantidad << " numeros" << endl;
    return 0;
}
