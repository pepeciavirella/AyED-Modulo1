#include <iostream>

///---------Ej.MI-3---------
/// Dada un numero entero de la forma (AAAAMMDD), que representa una
/// fecha valida mostrar el dia, mes y año que representa
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    long fechaUnificada;
    int dia, mes, agno;
    cout << "Ingrese una fecha en formato AAAAMMDD" << endl;
    cin >> fechaUnificada;
    agno = fechaUnificada / 10000;
    mes = (fechaUnificada - agno * 10000) / 100;
    dia = fechaUnificada - agno * 10000 - mes * 100;
    cout << "La fecha seria el dia " << dia << " del mes " << mes << " del anio " << agno;
    return 0;
}
