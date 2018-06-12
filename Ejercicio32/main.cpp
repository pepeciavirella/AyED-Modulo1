#include <iostream>

///---------Ej.MI-32---------
/// Una compañía aérea desea emitir un listado con los movimientos mensuales de
/// sus M vuelos al exterior. Para ello cuenta con la siguiente información. De cada vuelo
/// realizado el número de vuelo, destino, y cantidad de asientos. De cada pasajero el número de
/// pasaporte y el importe que abonó por el pasaje en dólares.
/// La información finaliza con un número de pasaporte igual a cero. Se pide emitir el siguiente listado:
/// -Total recaudado por vuelo
/// -Porcentajes de asientos libres y ocupados por vuelo
/// -Total recaudado en el mes
/// -Cantidad de veces seguidas que se dieron vuelos completos
/// -Numero de vuelo que mas recaudo
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    unsigned int m, contador;
    //Variables a ingresar por consola
    int numeroVuelo, cantidadAsientos;
    long numeroPasaporte;
    float importePasaje;
    char destino[30];
    //Variables a calcular algoritmicamente
    float recaudacionVuelo, recaudacionMensual, porcentajeLibres, porcentajeOcupados, mayorRecaudacion;
    int cantidadOcupados, cantidadLibres, vuelosSeguidosCompletosActual, maxVuelosSeguidosCompletos, vueloMasRecaudador;
    int numeroPasajero;
    bool vueloAnteriorCompleto;
    cout << "Cuantos vuelos hubo en el mes?" << endl;
    cin >> m;                                           //Nombrado asi por el enunciado (peor nombre imposible)
    //Inicializacion de variables del mes
    recaudacionMensual = 0;
    mayorRecaudacion = 0;                               //Recaudacion del vuelo que mas recaudo
    vuelosSeguidosCompletosActual = 0;                  //Contador actual de vuelos seguidos completos
    maxVuelosSeguidosCompletos = 0;                     //Mayor cantidad de vuelos seguidos completos registrada
    vueloAnteriorCompleto = false;                      //Flag para saber si el vuelo anterior estaba completo o no

    for (contador = 1; contador <= m; contador++)
    {
        cout << endl << "---DATOS DEL VUELO " << contador << "---" << endl << endl;
        cout << "Numero de vuelo: ";
        cin >> numeroVuelo;
        cout << "Destino: ";
        cin >> destino;
        cout << "Cantidad de asientos: " << endl;
        cin >> cantidadAsientos;
        //Reseteo/inicializacion de variables del vuelo
        recaudacionVuelo = 0;
        numeroPasajero = 1;                             //Para controlar de no ingresar mas pasajeros de la capacidad
        cantidadOcupados = 0;                           //Cantidad de asientos ocupados; no inicializo libres porque la calculare
        cout << endl << "--DATOS DE PASAJEROS--" << endl;
        cout << endl << "-PASAJERO " << numeroPasajero << "-" << endl;
        cout << "Numero de pasaporte: ";
        cin >> numeroPasaporte;

        while(numeroPasaporte != 0 && numeroPasajero <= cantidadAsientos)
        {
            cout << "Importe abonado (en dolares): ";
            cin >> importePasaje;
            recaudacionVuelo += importePasaje;
            cantidadOcupados++;
            numeroPasajero++;
            cout << endl << "-PASAJERO " << numeroPasajero << "-" << endl;      //Aunque no haya mas lugar, preguntara, pero
            cout << "Numero de pasaporte: ";                                    //no lo va a contar en el ingreso (sale de while)
            cin >> numeroPasaporte;
        }

        cout << endl << "--FIN DEL INGRESO DE DATOS DEL VUELO--" << endl << endl;
        cout << "Total recaudado del vuelo: " << recaudacionVuelo << endl;
        porcentajeOcupados = ((float) cantidadOcupados/cantidadAsientos) * 100;
        cantidadLibres = cantidadAsientos - cantidadOcupados;
        porcentajeLibres = ((float) cantidadLibres/cantidadAsientos) * 100;
        cout << "% de asientos libres del vuelo: " << porcentajeLibres << endl;
        cout << "% de asientos ocupados del vuelo: " << porcentajeOcupados << endl;
        recaudacionMensual += recaudacionVuelo;
        if(recaudacionMensual > mayorRecaudacion)
        {
            vueloMasRecaudador = numeroVuelo;           //Actualizo el numero de vuelo mas recaudador si fue asi
        }
        if(cantidadOcupados == cantidadAsientos)        //En otras palabras, si estuvo completo
        {
            if(vueloAnteriorCompleto)                   //Si el booleano es true, y si este estuvo completo
            {
                vuelosSeguidosCompletosActual++;        //Aumento la seguidilla actual de vuelos completos
                if(vuelosSeguidosCompletosActual > maxVuelosSeguidosCompletos)  //Si es la seguidilla mas larga, actualizo
                {
                    maxVuelosSeguidosCompletos++;
                }
            }
            vueloAnteriorCompleto = true;               //Ahora si, dejo el flag en true para el siguiente vuelo a ingresar
        }
        else
        {
            vueloAnteriorCompleto = false;              //Pero si este no estuvo completo, apago el flag (lo dejo en false)
        }
    }

    cout << endl << "---FIN DEL INGRESO DE VUELOS DEL MES. RESULTADOS---" << endl << endl;
    cout << "Total recaudado en el mes: " << recaudacionMensual << endl;
    cout << "Cantidad de veces seguidas que se dieron vuelos completos: " << maxVuelosSeguidosCompletos << endl;
    cout << "El numero de vuelo que mas recaudo: " << vueloMasRecaudador << endl;
    return 0;
}
