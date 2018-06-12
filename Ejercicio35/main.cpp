#include <iostream>

///---------Ej.MI-35---------
/// Dada una serie de números enteros, informar:
/// a) su factorial
/// b) cuantos múltiplos de 3
/// c) cuantos múltiplos de 5
/// d) cuantos múltiplos de 3 y de 5
/// Utilice las funciones de ejercicios anteriores
/// Autor: Giuseppe Ciavirella

//HIPOTESIS: El factorial de cada numero se muestra ni bien se ingresa; una vez finalizado el ingreso, se muestran los contadores

using namespace std;

long factorial(int unNumero)                //Tal cual esta en el ejercicio MI-34
{
    int contador;
    long fact;
    fact = 1;
    for (contador = 2; contador <= unNumero; contador++)
    {
        fact *= contador;
    }
    return fact;
}

bool esMultiploDe(int a, int b)  //Devuelve true si a es multiplo de b, no viceversa; hecho para no hacer dos funciones identicas
{
    int resto = a % b;
    if(resto == 0)
    {
        return true;
    }
    return false;         //No hace falta ponerlo en un if, ya que si entra al anterior, retornara true y se ira de la funcion
}

int main()
{
    int cantidad, i, numeroIngresado, cantidadMultiplosDe3, cantidadMultiplosDe5, cantidadMultiplosDeAmbos;
    cantidadMultiplosDe3 = 0;
    cantidadMultiplosDe5 = 0;
    cantidadMultiplosDeAmbos = 0;
    cout << "Cuantos numeros enteros quiere ingresar?" << endl; //Tambien podria ser un while o do-while, es a eleccion
    cin >> cantidad;
    for(i = 1; i <= cantidad; i++)
    {
        cout << "Ingrese un entero: ";
        cin >> numeroIngresado;
        cout << "Su factorial es: " << factorial(numeroIngresado) << endl;
        if(esMultiploDe(numeroIngresado,3))
        {
            cantidadMultiplosDe3++;
            if(esMultiploDe(numeroIngresado,5))     //Solo entra aca si tambien es multiplo de 3
            {
                cantidadMultiplosDeAmbos++;
            }
        }
        else if(esMultiploDe(numeroIngresado,5))    //No es multiplo de 3, pero si de 5
        {
            cantidadMultiplosDe5++;
        }
    }
    cout << endl << "--RESULTADOS DEL INGRESO--" << endl;
    cout << "Se ingresaron " << cantidadMultiplosDe3 << " multiplos de 3" << endl;
    cout << "Se ingresaron " << cantidadMultiplosDe5 << " multiplos de 5" << endl;
    cout << "Se ingresaron " << cantidadMultiplosDeAmbos << " multiplos de 3 y de 5 a la vez" << endl;
    return 0;
}
