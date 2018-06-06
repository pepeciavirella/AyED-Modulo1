#include <iostream>

/// ---------Ej.MI-7---------
/// Dados tres valores determinar e imprimir una leyenda
/// según sea: “Forman triangulo” o “No forman triangulo”
/// Autor: Giuseppe Ciavirella

// Hipotesis de trabajo: Los valores corresponden a la longitud de los lados
// Habria que verificar el Teorema de Pitagoras

using namespace std;

int main()
{
    float lado1, lado2, lado3;
    double cuadrado1, cuadrado2, cuadrado3;
    cout << "Ingrese la longitud de tres lados de un triangulo rectangulo" << endl;
    cin >> lado1 >> lado2 >> lado3;
    cuadrado1 = lado1 * lado1;
    cuadrado2 = lado2 * lado2;
    cuadrado3 = lado3 * lado3;
    if((cuadrado1 == cuadrado2+cuadrado3) || (cuadrado2 == cuadrado1+cuadrado3) || (cuadrado3 == cuadrado1 + cuadrado2))
    {
        cout << "Forman triangulo rectangulo" << endl;
    }
    else
    {
        cout << "No forman triangulo rectangulo" << endl;
    }
    return 0;
}
