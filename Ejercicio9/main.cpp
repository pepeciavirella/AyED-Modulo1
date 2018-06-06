#include <iostream>

/// ---------Ej.MI-9---------
/// Dados un mes y el año correspondiente informar cuantos días tiene el mes
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int mes, agno;
    cout << "Ingrese, en numeros, un anio y luego un mes" << endl;
    cin >> agno >> mes;
    switch(mes)
    {
        case 1: case 3: case 5: case 7:                // Todos estos meses tienen 31 dias siempre
        case 8: case 10: case 12:
            cout << "El mes tiene 31 dias" << endl;
            break;
        case 4: case 6: case 9: case 11:               // Y todos estos siempre 30!
            cout << "El mes tiene 30 dias" << endl;
            break;
        case 2:                                        // Pero febrero depende del año y si es bisiesto
            if((agno%400 == 0) || ((agno%4 == 0) && (agno % 100 != 0)))
            {
                cout << "El mes tiene 29 dias" << endl;
            }
            else
            {
                cout << "El mes tiene 28 dias" << endl;
            }
    }
    return 0;
}
