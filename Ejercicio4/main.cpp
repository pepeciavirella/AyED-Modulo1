#include <iostream>

///---------Ej.MI-4---------
/// A partir de un valor entero ingresado por teclado, se pide informar:
/// a) La quinta parte de dicho valor
/// b) El resto de la división por 5
/// c) La séptima parte del resultado del punto a) 
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int numero;
    float quintaParte;
    cout << "Ingrese un entero" << endl;
    cin >> numero;
    quintaParte = (float) numero/5;
    cout << "La quinta parte del numero es " << quintaParte << endl;
    cout << "El resto de dividirlo por 5 es " << numero%5 << endl;
    cout << "La septima parte de la quinta parte es " << quintaParte/7 << endl;
    return 0;
}
