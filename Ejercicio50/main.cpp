#include <iostream>
#include <cstring>
#include <ctype.h>

///---------Ej.MI-50---------
/// Desarrollar:
/// a) Una funci�n que reciba un n�mero natural de 4 d�gitos en formato de HHMM que
/// corresponde a un tiempo determinado en horas y minutos, retorne ese tiempo en minutos.
/// b) Un procedimiento que reciba el costo en pesos de un abono telef�nico, la cantidad de
/// minutos libres que incluye el abono, el cargo en pesos por minuto excedente y la
/// cantidad de minutos utilizados por un abonado, retorne la cantidad de minutos
/// excedidos y el monto en pesos a abonar (costo del abono m�s minutos excedidos por
/// el costo de minutos excedidos) m�s el 21% del valor del IVA
/// Desarrolle un algoritmo que resuelva la siguiente situaci�n problem�tica: Todos los fines de
/// mes, una empresa de telefon�a celular debe confeccionar las facturas con los consumos de
/// todos sus abonados, que se realizan en tres turnos de trabajo: Ma�ana, Tarde y Noche.
/// Para ello se ingresar� por teclado la siguiente informaci�n de cada celular:
/// - N�mero de celular 9 d�gitos ( 0 indica cambio de turno)
/// - Nombre del abonado 20 caracteres
/// - Direcci�n del abonado 25 caracteres
/// - Tiempo utilizado 4 d�gitos en formato HHMM
/// - Tipo de abono (car�cter, A, B, C, D o E)
/// Dependiendo del tipo de abono que se tenga, el usuario tiene cierta cantidad de minutos
/// libres, por los cuales no abona cargo extra, pero por cada minuto que se exceda debe
/// abonar una suma extra seg�n la siguiente tabla:
/// Plan A: Costo $70, Minutos libres 300, cargo por minuto excedente $0.09
/// Plan B: Costo $55, Minutos libres 200, cargo por minuto excedente $0.15
/// Plan C: Costo $40, Minutos libres 100, cargo por minuto excedente $0.21
/// Plan D: Costo $28, Minutos libres 60, cargo por minuto excedente $0.29
/// Plan E: Costo $19, Minutos libres 40, cargo por minuto excedente $0.37
/// Emitir un listado por turno, que indique Nombre del abonado, direccion, minutos libres, excedidos, y monto a abonar
/// Informar por cada turno de trabajo:
/// - El nombre del abonado que debe abonar la factura m�s costosa y el monto de �sta.
/// - El nombre y el n�mero de celular de la persona que realiz� la mayor cantidad de minutos
/// excedentes, indicando cu�ntos fueron.
/// Al final del d�a informar:
/// - El monto total facturado
/// - En que turno y en que orden dentro del turno apareci� el abonado que utiliz� la menor cantidad
/// de minutos en el mes.
/// Utilice los subprogramas a) y b)
/// Autor: Giuseppe Ciavirella

//NOTA: Para no hacerlo mucho mas largo e interminable, omiti algunos casos de comprobacion de errores (nadie en un turno, etc)

using namespace std;

int tiempoEnMinutos(int tiempoHHMM)
{
    int minutosTotales;
    minutosTotales = (tiempoHHMM % 100) + (tiempoHHMM / 100) * 60;
    return minutosTotales;
}

//NOTA: Le paso montoAAbonar por referencia para que lo modifique y pueda usarlo posteriormente, en el main
void informeMensual(float costoPlan, int minutosLibres, float cargoExcedente, int minutosUtilizados, float &montoAAbonar, int &minutosExcedidos)
{
    minutosExcedidos = minutosUtilizados - minutosLibres;
    if(minutosExcedidos < 0)
    {
        minutosExcedidos = 0;
    }
    montoAAbonar = (costoPlan + (minutosExcedidos * cargoExcedente)) * 1.21;
    cout << "Minutos Excedidos   : " << minutosExcedidos << endl;
    cout << "Monto Total a Abonar: $" << montoAAbonar << endl;
}

int main()
{
    long nroCelular;
    char nombre[20];
    char direccion[25];
    int tiempoUtilizado, minutosUtilizados, minutosLibresAbono;;
    char tipoAbono;
    float costoAbono, cargoExcedenteAbono;
    int excedidos, mayorCantidadExcedidos, menorCantidadUtilizados;
    int ordenEnTurno, ordenMenosUtilizados;                     //Para saber el orden dentro del turno del usuario actual
    float factura, facturaMasCostosa, montoTotalMensual;
    long celularMasExcedidos;
    char nombreMasCostosa[20];
    char nombreMasExcedidos[20];
    char turnoMenosUtilizados[8];
    facturaMasCostosa = 0;                                      //Las inicializo para la primera verificacion
    mayorCantidadExcedidos = -1;                                //Por si nadie se excedio (mayorCantidadExcedidos seria 0)
    montoTotalMensual = 0;
    menorCantidadUtilizados = INT_MAX;
    cout << "---SISTEMA DE FACTURACION---" << endl;
    cout << "--TURNO MANIANA--" << endl << endl;
    ordenEnTurno = 0;                                           //Lo pongo en cero antes de arrancar cada turno
    cout << "Numero de celular (0 para cambiar turno): ";
    cin >> nroCelular;
    while(nroCelular > 0)
    {
        ordenEnTurno++;
        cout << "Nombre del abonado (sin espacios): ";
        cin >> nombre;
        cout << "Direccion del abonado (sin espacios): ";
        cin >> direccion;
        cout << "Tiempo utilizado (en formato HHMM): ";
        cin >> tiempoUtilizado;
        minutosUtilizados = tiempoEnMinutos(tiempoUtilizado);
        if(minutosUtilizados < menorCantidadUtilizados)
        {
            strcpy(turnoMenosUtilizados, "Maniana");
            ordenMenosUtilizados = ordenEnTurno;
            menorCantidadUtilizados = minutosUtilizados;
        }
        cout << "Tipo de abono (A,B,C,D o E): ";
        cin >> tipoAbono;
        switch(tipoAbono)                                           //Para determinar parametros para el informe
        {
            case 'A':
                costoAbono = 70;
                minutosLibresAbono = 300;
                cargoExcedenteAbono = 0.09;
                break;
            case 'B':
                costoAbono = 55;
                minutosLibresAbono = 200;
                cargoExcedenteAbono = 0.15;
                break;
            case 'C':
                costoAbono = 40;
                minutosLibresAbono = 100;
                cargoExcedenteAbono = 0.21;
                break;
            case 'D':
                costoAbono = 28;
                minutosLibresAbono = 60;
                cargoExcedenteAbono = 0.29;
                break;
            case 'E':
                costoAbono = 19;
                minutosLibresAbono = 40;
                cargoExcedenteAbono = 0.37;
                break;
        }
        cout << endl << "Nombre              : " << nombre << endl;
        cout << "Direccion           : " << direccion << endl;
        cout << "Minutos libres      : " << minutosLibresAbono << endl;
        informeMensual(costoAbono, minutosLibresAbono, cargoExcedenteAbono, minutosUtilizados, factura, excedidos);
        montoTotalMensual += factura;
        if(factura > facturaMasCostosa)
        {
            strcpy(nombreMasCostosa, nombre);
            facturaMasCostosa = factura;
        }
        if(excedidos > mayorCantidadExcedidos)
        {
            strcpy(nombreMasExcedidos, nombre);
            celularMasExcedidos = nroCelular;
            mayorCantidadExcedidos = excedidos;
        }
        cout << endl << "Numero de celular (0 para cambiar turno): ";
        cin >> nroCelular;
    }
    cout << endl << "--RESULTADOS TURNO MANIANA--" << endl;
    cout << nombreMasCostosa << " debe abonar la factura mas costosa, de monto $" << facturaMasCostosa << endl;
    cout << nombreMasExcedidos << ", cuyo numero es " << celularMasExcedidos << ", fue el que mas minutos se excedio (" << mayorCantidadExcedidos << ")" << endl;
    cout << endl << "--TURNO TARDE--" << endl << endl;
    facturaMasCostosa = 0;                                      //Reinicializo las variables de cada turno
    mayorCantidadExcedidos = -1;
    ordenEnTurno = 0;
    cout << "Numero de celular (0 para cambiar turno): ";
    cin >> nroCelular;
    while(nroCelular > 0)
    {
        ordenEnTurno++;
        cout << "Nombre del abonado (sin espacios): ";
        cin >> nombre;
        cout << "Direccion del abonado (sin espacios): ";
        cin >> direccion;
        cout << "Tiempo utilizado (en formato HHMM): ";
        cin >> tiempoUtilizado;
        minutosUtilizados = tiempoEnMinutos(tiempoUtilizado);
        if(minutosUtilizados < menorCantidadUtilizados)
        {
            strcpy(turnoMenosUtilizados, "Tarde");
            ordenMenosUtilizados = ordenEnTurno;
            menorCantidadUtilizados = minutosUtilizados;
        }
        cout << "Tipo de abono (A,B,C,D o E): ";
        cin >> tipoAbono;
        switch(tipoAbono)
        {
            case 'A':
                costoAbono = 70;
                minutosLibresAbono = 300;
                cargoExcedenteAbono = 0.09;
                break;
            case 'B':
                costoAbono = 55;
                minutosLibresAbono = 200;
                cargoExcedenteAbono = 0.15;
                break;
            case 'C':
                costoAbono = 40;
                minutosLibresAbono = 100;
                cargoExcedenteAbono = 0.21;
                break;
            case 'D':
                costoAbono = 28;
                minutosLibresAbono = 60;
                cargoExcedenteAbono = 0.29;
                break;
            case 'E':
                costoAbono = 19;
                minutosLibresAbono = 40;
                cargoExcedenteAbono = 0.37;
                break;
        }
        cout << endl << "Nombre              : " << nombre << endl;
        cout << "Direccion           : " << direccion << endl;
        cout << "Minutos libres      : " << minutosLibresAbono << endl;
        informeMensual(costoAbono, minutosLibresAbono, cargoExcedenteAbono, minutosUtilizados, factura, excedidos);
        montoTotalMensual += factura;
        if(factura > facturaMasCostosa)
        {
            strcpy(nombreMasCostosa, nombre);
            facturaMasCostosa = factura;
        }
        if(excedidos > mayorCantidadExcedidos)
        {
            strcpy(nombreMasExcedidos, nombre);
            celularMasExcedidos = nroCelular;
            mayorCantidadExcedidos = excedidos;
        }
        cout << endl << "Numero de celular (0 para cambiar turno): ";
        cin >> nroCelular;
    }
    cout << endl << "--RESULTADOS TURNO TARDE--" << endl;
    cout << nombreMasCostosa << " debe abonar la factura mas costosa, de monto $" << facturaMasCostosa << endl;
    cout << nombreMasExcedidos << ", cuyo numero es " << celularMasExcedidos << ", fue el que mas minutos se excedio (" << mayorCantidadExcedidos << ")" << endl;
    cout << endl << "--TURNO NOCHE--" << endl << endl;
    facturaMasCostosa = 0;                                      //Reinicializo las variables de cada turno
    mayorCantidadExcedidos = -1;
    ordenEnTurno = 0;
    cout << "Numero de celular (0 para finalizar ingreso mensual): ";
    cin >> nroCelular;
    while(nroCelular > 0)
    {
        ordenEnTurno++;
        cout << "Nombre del abonado (sin espacios): ";
        cin >> nombre;
        cout << "Direccion del abonado (sin espacios): ";
        cin >> direccion;
        cout << "Tiempo utilizado (en formato HHMM): ";
        cin >> tiempoUtilizado;
        minutosUtilizados = tiempoEnMinutos(tiempoUtilizado);
        if(minutosUtilizados < menorCantidadUtilizados)
        {
            strcpy(turnoMenosUtilizados, "Noche");
            ordenMenosUtilizados = ordenEnTurno;
            menorCantidadUtilizados = minutosUtilizados;
        }
        cout << "Tipo de abono (A,B,C,D o E): ";
        cin >> tipoAbono;
        switch(tipoAbono)
        {
            case 'A':
                costoAbono = 70;
                minutosLibresAbono = 300;
                cargoExcedenteAbono = 0.09;
                break;
            case 'B':
                costoAbono = 55;
                minutosLibresAbono = 200;
                cargoExcedenteAbono = 0.15;
                break;
            case 'C':
                costoAbono = 40;
                minutosLibresAbono = 100;
                cargoExcedenteAbono = 0.21;
                break;
            case 'D':
                costoAbono = 28;
                minutosLibresAbono = 60;
                cargoExcedenteAbono = 0.29;
                break;
            case 'E':
                costoAbono = 19;
                minutosLibresAbono = 40;
                cargoExcedenteAbono = 0.37;
                break;
        }
        cout << endl << "Nombre              : " << nombre << endl;
        cout << "Direccion           : " << direccion << endl;
        cout << "Minutos libres      : " << minutosLibresAbono << endl;
        informeMensual(costoAbono, minutosLibresAbono, cargoExcedenteAbono, minutosUtilizados, factura, excedidos);
        montoTotalMensual += factura;
        if(factura > facturaMasCostosa)
        {
            strcpy(nombreMasCostosa, nombre);
            facturaMasCostosa = factura;
        }
        if(excedidos > mayorCantidadExcedidos)
        {
            strcpy(nombreMasExcedidos, nombre);
            celularMasExcedidos = nroCelular;
            mayorCantidadExcedidos = excedidos;
        }
        cout << endl << "Numero de celular (0 para finalizar ingreso mensual): ";
        cin >> nroCelular;
    }
    cout << endl << "--RESULTADOS TURNO NOCHE--" << endl;
    cout << nombreMasCostosa << " debe abonar la factura mas costosa, de monto $" << facturaMasCostosa << endl;
    cout << nombreMasExcedidos << ", cuyo numero es " << celularMasExcedidos << ", fue el que mas minutos se excedio (" << mayorCantidadExcedidos << ")" << endl;
    cout << endl << "---RESULTADOS MENSUALES---" << endl;
    cout << "El monto total mensual facturado fue de $" << montoTotalMensual << endl;
    cout << "El abonado que utilizo la menor cantidad de minutos en el mes aparecio en el Turno " << turnoMenosUtilizados << ", en el orden " << ordenMenosUtilizados << endl;
    return 0;
}
