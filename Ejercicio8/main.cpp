#include <iostream>

/// ---------Ej.MI-8---------
/// Dado un triángulo representado por sus lados L1, L2, L3, determinar
/// e imprimir una leyenda según sea: equilátero, isósceles o escálenos
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    float l1, l2, l3;
    cout << "Ingrese la longitud de los tres lados de un triangulo" << endl;
    cin >> l1 >> l2 >> l3;
    if((l1 == l2) && (l1 == l3))
    {
        cout << "El triangulo es equilatero" << endl;
    }
    else if((l1 == l2) || (l2 == l3) || (l1 == l3))
    {
        cout << "El triangulo es isosceles" << endl;
    }
    else
    {
        cout << "El triangulo es escaleno" << endl;
    }
    return 0;
}
