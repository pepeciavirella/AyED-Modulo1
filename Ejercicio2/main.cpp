#include <iostream>

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
