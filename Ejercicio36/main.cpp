#include <iostream>

///---------Ej.MI-36---------
/// Dada la fracción P/Q, para P y Q naturales informar la mayor cantidad de
/// simplificaciones. Desarrolle y utilice una función que reciba dos números naturales y
/// retorne el menor factor común. Ej: 360/60 = 180/30 = 90/15 = 30/5 = 6/1
/// Autor: Giuseppe Ciavirella

using namespace std;

int mcd(int a,int b)                //Tal cual esta en el ejercicio MI-33
{
    int resto;
    resto = a%b;
    if(resto == 0)
    {
        return b;
    }
    return mcd(b,resto);
}

int menorDivisor(int unNumero, int otroNumero)
{
    int contador;                                                   //Para recorrer el for
    int mayorDivisor = mcd(unNumero,otroNumero);                    //Tope del for, no vale la pena evaluar mas
    for(contador = 2; contador <= mayorDivisor; contador++)         //Inicializar en 2! O sino devolvera siempre 1
    {                                                               //por ser divisor universal
        if((unNumero%contador == 0) && (otroNumero%contador == 0))  //Busco el primer divisor de ambos
        {
            return contador;
        }
    }
    return mayorDivisor;                                            //Por si el mcd fuera uno y no entrase al for
}

int main()
{
    int p, q, divMenor;
    cout << "Ingrese el numerador, y luego el denominador, de una fraccion p/q" << endl;
    cin >> p >> q;
    cout << endl << "--SIMPLIFICACIONES DEL NUMERO:--" << endl << endl;
    do
    {
        cout << p << "/" << q << endl;
        divMenor = menorDivisor(p,q);
        p = p/divMenor;
        q = q/divMenor;
    }while(divMenor != 1);
    return 0;
}
