#include <iostream>
#include <iomanip>          //Para darle el formato que quiero a la hora actualizada y usar setfill y setw

///---------Ej.MI-39---------
/// Desarrollar un procedimiento tal que dada una hora (HHMMSS) y un tiempo
/// también en formato HHMMSS devuelva la nueva hora que surge de sumar el tiempo a la hora
/// inicial, considere también si cambió el día
/// Autor: Giuseppe Ciavirella

//NOTA: Dice procedimiento, pero si devuelve una nueva hora, es porque debe ser yba funcion

using namespace std;

long actualizarHora(long tiempoOriginal,long tiempoTranscurrido)
{
    int segundosOriginal, segundosTranscurrido, minutosOriginal, minutosTranscurrido, horasOriginal, horasTranscurrido;
    int sumaSegundos, sumaMinutos, sumaHoras;
    long tiempoActualizado;
    horasOriginal = tiempoOriginal / 10000;
    horasTranscurrido = tiempoTranscurrido / 10000;
    minutosOriginal = (tiempoOriginal - horasOriginal * 10000) / 100;
    minutosTranscurrido = (tiempoTranscurrido - horasTranscurrido * 10000) / 100;
    segundosOriginal = tiempoOriginal - horasOriginal * 10000 - minutosOriginal * 100;
    segundosTranscurrido = tiempoTranscurrido - horasTranscurrido * 10000 - minutosTranscurrido * 100;
    sumaSegundos = segundosOriginal + segundosTranscurrido;
    sumaMinutos = minutosOriginal + minutosTranscurrido;
    if(sumaSegundos >= 60)
    {
        sumaMinutos ++;           //No deberian adicionar nunca dos minutos o mas
        sumaSegundos = sumaSegundos - 60;
    }
    sumaHoras = horasOriginal + horasTranscurrido;
    if(sumaMinutos >= 60)
    {
        sumaHoras++;              //Tampoco deberian adicionar dos horas o mas
        sumaMinutos -= 60;        //Analogo a hacer sumaMinutos = sumaMinutos - 60;
    }
    if(sumaHoras >= 24)
    {
        sumaHoras -= 24;
    }
    tiempoActualizado = sumaHoras * 10000 + sumaMinutos * 100 + sumaSegundos;
    return tiempoActualizado;
}

int main()
{
    long horaInicio, incremento, horaFinal;
    cout << "Ingrese la hora de inicio, en formato HHMMSS" << endl;
    cin >> horaInicio;
    cout << "Ingrese el incremento de tiempo, tambien en formato HHMMSS" << endl;
    cin >> incremento;
    horaFinal = actualizarHora(horaInicio,incremento);
    cout << "La hora final, al agregar el incremento a la inicial, es " << setfill('0') << setw(6) << horaFinal << endl;
    //NOTA: setfill(char unCaracter) es para rellenar con unCaracter los espacios vacios; la cantidad total de espacios
    //esta determinada por setw(int unaCantidad)
    return 0;
}
