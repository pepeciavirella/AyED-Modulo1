#include <iostream>

///---------Ej.MI-26---------
/// Un buque de carga traslada 100 contenedores a tres diferentes puertos del país.
/// Los puertos se identifican con los números 1, 2 y 3.
/// De cada contenedor que el buque traslade se registran los siguientes datos:
/// - Identificación del contenedor
/// - Peso del contenedor en kg
/// - Puerto de arribo(un valor de 1 a 3).
/// Se pide calcular e informar:
/// 1) El peso total que el buque debe trasladar
/// 2) La identificación del contenedor de mayor peso
/// 3) La cantidad de contenedores que debe trasladar a cada puerto
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int i, identificador, puertoDeArribo, identificadorDelMasPesado;
    float pesoContenedor, pesoTotal, mayorPeso;
    pesoTotal = 0;                      //Es el peso total del buque a trasladar
    mayorPeso = 0;                      //Es el peso del contenedor mas pesado
    int contenedoresPuerto1 = 0;        //Cantidad de contenedores a llevar a cada puerto
    int contenedoresPuerto2 = 0;
    int contenedoresPuerto3 = 0;

    for(i = 1; i <= 100; i++)
    {
        cout << "--DATOS DEL CONTENEDOR NUMERO " << i << "--" << endl;
        cout << "Identificador   : ";
        cin >> identificador;
        cout << "Peso (en kg)    : ";
        cin >> pesoContenedor;
        cout << "Puerto de arribo: ";
        cin >> puertoDeArribo;
        pesoTotal += pesoContenedor;
        if(pesoContenedor > mayorPeso)
        {
            identificadorDelMasPesado = identificador; //HACK: si hay dos con el mayor peso, elijo el primero en ingresar
            mayorPeso = pesoContenedor;
        }
        if(puertoDeArribo == 1)
        {
            contenedoresPuerto1++;
        }
        if(puertoDeArribo == 2)
        {
            contenedoresPuerto2++;
        }
        if(puertoDeArribo == 3)
        {
            contenedoresPuerto3++;
        }
    }
    cout << endl << "--FIN DEL INGRESO--" << endl << endl;
    cout << "El buque debera trasladar un peso total de " << pesoTotal << " kg" << endl;
    cout << "El identificador del contenedor de mayor peso es " << identificadorDelMasPesado << endl;
    cout << "Se deberan trasladar " << contenedoresPuerto1 << " contenedores al puerto 1" << endl;
    cout << "Se deberan trasladar " << contenedoresPuerto2 << " contenedores al puerto 2" << endl;
    cout << "Se deberan trasladar " << contenedoresPuerto3 << " contenedores al puerto 3" << endl;
    return 0;
}
