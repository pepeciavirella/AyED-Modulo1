#include <iostream>

/// ---------Ej.MI-19.B---------
/// Reescribir el algoritmo 17, utilizando un ciclo 1-n
/// Autor: Giuseppe Ciavirella

//NOTA: Se resuelve usando un ciclo 0-n; se usará uno 1-n más adelante

using namespace std;

int main()
{
    float sueldo;
    int cantMenos1520, cantMenos2780, cantMenos5999, cantMas5999;
    cantMenos1520 = -1;                 //HACK: Para que si el primer sueldo ingresado es 0, no sume uno a esa cantidad
    cantMenos2780 = 0;                  //Otra alternativa seria hacer un if(sueldo==0){}
    cantMenos5999 = 0;
    cantMas5999 = 0;
    do{
        cout << "Ingrese el sueldo de un empleado" << endl;
        cin >> sueldo;
        if(sueldo < 1520)
        {
            cantMenos1520++;
        }
        else if(sueldo < 2780)
        {
            cantMenos2780++;
        }
        else if(sueldo < 5999)
        {
            cantMenos5999++;
        }
        else
        {
            cantMas5999++;
        }
    }while(sueldo != 0);
    cout << endl << "-----TOTALES-----" << endl;
    cout << cantMenos1520 << " empleados ganan menos de $1520" << endl;
    cout << cantMenos2780 << " empleados ganan entre $1520 y $2779" << endl;
    cout << cantMenos5999 << " empleados ganan entre $2780 y $5998" << endl;
    cout << cantMas5999 << " empleados ganan $ 5999 o mas" << endl;
    return 0;
}
