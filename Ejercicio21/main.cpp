#include <iostream>

/// ---------Ej.MI-21---------
/// Dados N valores informar el mayor, el menor y en
/// que posición del conjunto fueron ingresados
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int n, posMayor, posMenor, i;
    float numero, mayor, menor;
    cout << "Cuantos numeros desea ingresar?" << endl;
    cin >> n;
    if(n > 0)
    {
        cout << "Ingrese el primer numero" << endl;
        cin >> numero;
        mayor = numero;
        menor = numero;
        posMayor = 1;
        posMenor = 2;
        i = 2;          //Porque ahora voy a ingresar el segundo, ya ingrese el primero
        while(i <= n)
        {
            cout << "Ingrese el primer numero" << endl;
            cin >> numero;
            if(numero > mayor)
            {
                mayor = numero;
                posMayor = i;
            }
            else if(numero < menor)
            {
                menor = numero;
                posMenor = i;
            }
            i++;
        }
        cout << endl << "El mayor fue " << mayor << ", en la posicion " << posMayor << endl;
        cout << "Y el menor fue " << menor << ", en la posicion " << posMenor << endl;
    }
    else
    {
        cout << "No se registro el ingreso de valores" << endl;
    }
    return 0;
}
