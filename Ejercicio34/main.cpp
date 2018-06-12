#include <iostream>

///---------Ej.MI-1---------
/// Desarrollar una función tal que dado un número entero positivo calcule y retorne su factorial
/// Autor: Giuseppe Ciavirella

using namespace std;

long factorial(int unNumero)
{
    int contador;
    long fact;
    fact = 1;       //Para los casos base, ya que 0! = 1! = 1; si unNumero es 0 o 1, no entrara al for
    for (contador = 2; contador <= unNumero; contador++)
    {
        fact *= contador;
    }
    return fact;
}

int main()
{
    int numero;
    long fact;       //Para cuargar el factorial, distingui el nombre; no es necesario tener esta variable, igualmente
    cout << "Ingrese un entero" << endl;
    cin >> numero;
    fact = factorial(numero);
    cout << "El factorial del numero es " << fact << endl;
    return 0;
}
