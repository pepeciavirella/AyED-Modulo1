#include <iostream>

/// ---------Ej.MI-19.A---------
/// Reescribir el algoritmo 16, utilizando un ciclo 1-n
/// Autor: Giuseppe Ciavirella

//NOTA: La idea era hacerlo con un ciclo 0-n, es decir while, y hacer su versión do-while más adelante

using namespace std;

int main()
{
    float numero;
    int cantidad = -1; //Inicializo asi para no contar el numero negativo
    do{
        cout << "Ingrese un numero no negativo, o bien uno negativo para detener el ingreso" << endl;
        cin >> numero;
        cantidad++; //HIPÓTESIS: El negativo que frene el ingreso no cuenta
    }while(numero >= 0);
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
