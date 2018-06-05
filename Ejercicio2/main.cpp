#include <iostream>

///---------Ej.MI-2---------
/// Dada una terna de números naturales que representan al día, al mes y al año de una determinada
/// fecha informarla como un solo número natural de 8 dígitos con la forma (AAAAMMDD)
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int dia, mes, agno;
    long fechaUnificada;
    cout << "--INTRODUZCA UNA FECHA--" << endl << "Introduzca el dia:" << endl;
    cin >> dia;
    cout << "Introduzca el mes:" << endl;
    cin >> mes;
    cout << "Introduzca el anio:" << endl;
    cin >> agno;
    fechaUnificada = dia + mes * 100 + agno * 10000;
    cout << "La fecha, en formato AAAAMMDD, es: " << fechaUnificada << endl;
    return 0;
}
