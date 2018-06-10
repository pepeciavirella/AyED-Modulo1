#include <iostream>

///---------Ej.MI-27---------
/// En un torneo de fútbol participan K equipos. El torneo se juega con el sistema de todos
/// contra todos. Por cada partido disputado por un equipo se dispone de la siguiente información:
/// a) Nro. de equipo,
/// b) Código del resultado ('P'= Perdido, 'E'= Empatado, 'G'= Ganado).
/// Se arma un lote de datos con todos los resultados del torneo, agrupados por Nro. de equipo.
/// Desarrollar el programa que imprima:
/// Por cada equipo, su número y el puntaje total que obtuvo (suma 3 si gana, y 1 si empata)
/// Autor: Giuseppe Ciavirella

//HIPOTESIS: Por los contenidos vistos hasta el momento en el que se dio el ejercicio, los cuales no incluian arrays ni
//estructuras de tipo registro, la idea es resolver este ejercicio mostrando los puntos de cada equipo unicamente al final
//del ingreso de sus datos. Deberia haber consistencia en los ingresos de los datos, eso depende del usuario (no puedo
//primero decir que 1 y 2 empataron cuando ingreso los resultados de 1, y luego decir que gano 2 cuando ingrese los de este

using namespace std;

int main()
{
    unsigned int k;            //Puedo usar un unsigned, la cantidad siempre sera positiva
    int i, j, puntos;          //Con i recorro los ingresos de cada equipo; con j los equipos a los que se enfrentara
    char resultado;
    cout << "Ingrese la cantidad de equipos participantes" << endl;
    cin >> k;
    cout << "REGLAS: 'G' o 'g' es que gano, 'E' o 'e' que empato, y 'P' o 'p' que perdio" << endl << endl;
    for(i = 1; i <= k; i++)
    {
        puntos = 0;             //Lo reseteo al ingresar los resultados de cada equipo
        cout << "--PARTIDOS DEL EQUIPO " << i << "--" << endl;
        for(j = 1; j <= k; j++)
        {
            if(j != i)          //No puede jugar contra si mismo
            {
                cout << "Como salio contra el equipo " << j << "?" << endl;
                cin >> resultado;
                if(resultado == 'G' || resultado == 'g')        //Si perdio no lo evaluo, ya que no sumara puntos
                {
                    puntos += 3;
                }
                else if(resultado == 'E' || resultado == 'e')
                {
                    puntos++;
                }
            }
        }
        cout << "TOTAL: El equipo " << i << " obtuvo " << puntos << " puntos" << endl << endl;
    }
    return 0;
}
