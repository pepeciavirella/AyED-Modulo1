#include <iostream>

///---------Ej.MI-38---------
/// Desarrollar la función
/// Int EdadAGrupoEtario (int edad)
/// que retorne un valor de 1 a 8, de acuerdo al siguiente cuadro:
/// Hasta 14 años -> Valor = 1
/// De 15 a 21    -> Valor = 2
/// De 22 a 28    -> Valor = 3
/// De 29 a 35    -> Valor = 4
/// De 36 a 42    -> Valor = 5
/// De 43 a 49    -> Valor = 6
/// De 50 a 63    -> Valor = 7
/// Mayores de 63 -> Valor = 8
/// Autor: Giuseppe Ciavirella

using namespace std;

int edadAGrupoEtario(int edad)
{
    if(edad <= 14)
    {
        return 1;
    }
    else if(edad <= 21)
    {
        return 2;
    }
    else if(edad <= 28)
    {
        return 3;
    }
    else if(edad <= 35)
    {
        return 4;
    }
    else if(edad <= 42)
    {
        return 5;
    }
    else if(edad <= 49)
    {
        return 6;
    }
    else if(edad <= 63)
    {
        return 7;
    }
    return 8;                 //No hace falta ponerlo en un if; si llego hasta aca sin salir por el return, es porque es tipo 8
}

int main()
{
    int edad, grupoEtario;
    cout << "Ingrese la edad de la persona" << endl;
    cin >> edad;
    grupoEtario = edadAGrupoEtario(edad);
    cout << "La persona corresponde al grupo etario numero " << grupoEtario << endl;
    return 0;
}
