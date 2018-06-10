#include <iostream>

///---------Ej.MI-24---------
/// Se dispone de un lote de valores enteros positivos que finaliza con un número negativo
/// El lote está dividido en sublotes por medio de valores cero. Desarrollar un programa que
/// determine e informe:
/// a) por cada sublote el promedio de valores
/// b) el total de sublotes procesados
/// c) el valor máximo del conjunto, indicando en que sublote se encontró y la posición
/// relativa del mismo dentro del sublote
/// d) valor mínimo de cada sublote
/// Nota: el lote puede estar vacío (primer valor negativo), o puede haber uno, varios o todos los
/// sublotes vacíos (ceros consecutivos)
/// Autor: Pablo Mendez (version adaptada por Giuseppe Ciavirella)

using namespace std;

int main()
{
    int cantidadDeValoresDelSublote, cantidadDeSublotes, subloteDelMaximo, posicionDelMaximo;
    float numeroIngresado, sumatoria, maximoDelLote, minimoDelSublote;
    cantidadDeSublotes = 1;      //Contador para la cantidad de sublotes, y para el sublote actual
    maximoDelLote = -1;        //Lo inicializo asi, ya que nunca podre asignarle un valor negativo; servira
                               //para saber si se ingresaron numeros
    do
    {
        cantidadDeValoresDelSublote = 0;    //Tambien sirve para conocer la posicion del elemento actual en el sublote
        sumatoria = 0;                      //Sumatoria de los valores ingresados hasta el momento en el sublote
        cout << "Ingrese un valor para el sublote " << cantidadDeSublotes << ":" << endl;
        cin >> numeroIngresado;
        minimoDelSublote = numeroIngresado; //Al ser el primero, ya sera el minimo

        while (numeroIngresado > 0)
        {
            sumatoria += numeroIngresado;
            cantidadDeValoresDelSublote++;
            if (numeroIngresado > maximoDelLote)
            {
                maximoDelLote = numeroIngresado;
                subloteDelMaximo = cantidadDeSublotes;
                posicionDelMaximo = cantidadDeValoresDelSublote;
            }
            if (numeroIngresado < minimoDelSublote)
            {
                minimoDelSublote = numeroIngresado;
            }
            cout << "Ingrese un valor para el sublote " << cantidadDeSublotes << ":" << endl;
            cin >> numeroIngresado;              //Lo hago al final, para asi tener el valor a comparar en la proxima iteracion
        }
        cout << endl << "--FIN DEL INGRESO DE VALORES DEL SUBLOTE " << cantidadDeSublotes << "--" << endl;
        if (cantidadDeValoresDelSublote)
        {                                               //Casteo para que el promedio sea un valor con coma si es necesario
            cout << "El promedio del sublote fue: " << (float) sumatoria / cantidadDeValoresDelSublote << endl;
            cout << "Y el minimo del sublote fue: " << minimoDelSublote << endl << endl;
        }
        else
            cout << "Sublote vacio" << endl << endl;
        cantidadDeSublotes++;
    }
    while (numeroIngresado >= 0);
    cout << endl << "-------------------" << endl;           //Por estetica :P
    if (maximoDelLote != -1)
    {
        cout << "En total, se procesaron " << cantidadDeSublotes -1 << " sublotes" << endl;
        cout << "El maximo valor ingresado fue " << maximoDelLote << ", en el sublote " << subloteDelMaximo << ", en la posicion " << posicionDelMaximo << endl;
    }
    else
    {
        cout << "Lote vacio, no se registro el ingreso de valores no negativos" << endl;
    }

    return 0;
}
