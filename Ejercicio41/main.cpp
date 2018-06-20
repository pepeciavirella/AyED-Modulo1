#include <iostream>

///---------Ej.MI-41---------
/// Una bodega quiere lanzar una oferta para terminar con el stock de dos productos.
/// Para ello cuenta con B cantidad de cajas de vino blanco y T cantidad de cajas de vino tinto.
/// Desea armar la mayor cantidad posible de paquetes con la oferta y que todos los paquetes
/// tengan igual cantidad de cajas de vino blanco y de vino tinto.
/// Se pide informar cuántos paquetes se podrán armar como máximo, y cuántas cajas de vino
/// blanco y cuantas de vino tinto contendrán cada uno.
/// Utilice la funciones desarrolladas en ejercicios anteriores
/// Autor: Giuseppe Ciavirella

//HIPOTESIS: La idea es usar todas las cajas, y que todos los paquetes tengan la misma cantidad de cajas de vino blanco, y la
//misma cantidad de cajas de vino tinto, PERO NO NECESARIAMENTE LAS MISMAS de ambas variedades de vino. Ojo, este enunciado es
//un poco ambiguo, opte por resolver el mas dificil (sino, seria simplemente hallar un mcd y listo)

using namespace std;

int mcd(int a,int b)                                    //Sacada del ejercicio MI-33
{
    int resto;
    resto = a%b;
    if(resto == 0)
    {
        return b;
    }
    return mcd(b,resto);
}



int menorDivisor(int unNumero, int otroNumero)          //Sacada del ejercicio 36
{
    int contador;
    int mayorDivisor = mcd(unNumero,otroNumero);
    for(contador = 2; contador <= mayorDivisor; contador++)
    {
        if((unNumero%contador == 0) && (otroNumero%contador == 0))
        {
            return contador;
        }
    }
    return mayorDivisor;
}

int main()
{
    int b, t;             //Cantidades de cajas de cada variedad (son malos nombres, pero el enunciado los designo asi)
    int cajasTintoPorPaquete, cajasBlancoPorPaquete, cantidadDePaquetes, cajasPorPaquete;
    cout << "Ingrese la cantidad de cajas de vino blanco" << endl;
    cin >> b;
    cout << "Ingrese la cantidad de cajas de vino tinto" << endl;
    cin >> t;
    cantidadDePaquetes = mcd(b, t);                     //La mayor cantidad de paquetes que pueden armarse
    cajasTintoPorPaquete = t/cantidadDePaquetes;
    cajasBlancoPorPaquete = b/cantidadDePaquetes;
    cajasPorPaquete = cajasTintoPorPaquete + cajasBlancoPorPaquete;
    cout << endl << "Se podran armar como maximo " << cantidadDePaquetes << " paquetes"  << endl;
    cout << "Cada uno tendra en total " << cajasPorPaquete << " cajas; " << cajasBlancoPorPaquete << " de vino blanco y " << cajasTintoPorPaquete << " de vino tinto" << endl;
    return 0;
}
