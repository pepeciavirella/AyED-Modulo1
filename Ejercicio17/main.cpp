#include <iostream>

/// ---------Ej.MI-17---------
/// Se ingresa un conjunto de valores float, cada uno de los cuales representan el
/// sueldo de un empleado, excepto el último valor que es cero e indica el fin del
/// conjunto. Se pide desarrollar un programa que determine e informe:
/// a) Cuántos empleados ganan menos $1.520.
/// b) Cuántos ganan $1.520 o más pero menos de $2.780.
/// c) Cuántos ganan $2.780 o más pero menos de $5.999.
/// d) Cuántos ganan $5.999 o más.
/// Autor: Giuseppe Ciavirella

//NOTA: Se resuelve usando un ciclo 0-n; se usará uno 1-n más adelante

using namespace std;

int main()
{
    float sueldo;
    int cantMenos1520, cantMenos2780, cantMenos5999, cantMas5999;
    cantMenos1520 = 0;
    cantMenos2780 = 0;
    cantMenos5999 = 0;
    cantMas5999 = 0;
    cout << "Ingrese el sueldo del primer empleado" << endl;
    cin >> sueldo;
    while(sueldo != 0)
    {
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
        cout << "Ingrese el sueldo de otro empleado" << endl;
        cin >> sueldo;
    }
    cout << endl << "-----TOTALES-----" << endl;
    cout << cantMenos1520 << " empleados ganan menos de $1520" << endl;
    cout << cantMenos2780 << " empleados ganan entre $1520 y $2779" << endl;
    cout << cantMenos5999 << " empleados ganan entre $2780 y $5998" << endl;
    cout << cantMas5999 << " empleados ganan $ 5999 o mas" << endl;
    return 0;
}
