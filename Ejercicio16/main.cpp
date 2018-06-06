#include <iostream>

/// ---------Ej.MI-16---------
/// Ingresar e informar valores, mientras que el valor ingresado
/// no sea negativo. Informar la cantidad de valores ingresados
/// Autor: Giuseppe Ciavirella

//NOTA: La idea era hacerlo con un ciclo 0-n, es decir while, y hacer su versión do-while más adelante

using namespace std;

int main()
{
    float numero;
    int cantidad = 0;
    cout << "Ingrese un numero no negativo, o bien uno negativo para detener el ingreso" << endl;
    cin >> numero;
    while(numero >= 0)
    {
        cantidad++; //HIPÓTESIS: El negativo que frene el ingreso no cuenta
        cout << "Ingrese un numero no negativo, o bien uno negativo para detener el ingreso" << endl;
        cin >> numero;
    }
    if(cantidad == 0)
    {
        cout << "No se ingresaron numeros no negativos" << endl;
    }
    else if(cantidad == 1)
    {
        cout << "Se ingreso un solo numero no negativo" << endl;
    }
    else
    {
        cout << "Se ingresaron " << cantidad << " numeros no negativos" << endl;
    }
    return 0;
}
