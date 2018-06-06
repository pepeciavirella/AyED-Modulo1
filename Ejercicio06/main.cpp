#include <iostream>

/// ---------Ej.MI-6---------
/// Dadas dos fechas informar cual es la más reciente. Determine cuales serían los
/// datos de entrada y las leyendas a informar de acuerdo al proceso solicitado
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int dia1, dia2, mes1, mes2, agno1, agno2;
    cout << "Ingrese una fecha (en numeros): primero dia, luego mes, luego anio" << endl;
    cin >> dia1 >> mes1 >> agno1;
    cout << "Ingrese otra fecha (en numeros): primero dia, luego mes, luego anio" << endl;
    cin >> dia2 >> mes2 >> agno2;
    if(agno1 == agno2)
    {
        if(mes1 == mes2)
        {
            if(dia1 == dia2)
            {
                cout << "Ambas fechas coinciden" << endl;
            }
            else if(dia1 > dia2)
            {
                cout << "La primer fecha es la mas reciente" << endl;
            }
            else
            {
                cout << "La segunda fecha es la mas reciente" << endl;
            }
        }
        else if(mes1 > mes2)
        {
            cout << "La primer fecha es la mas reciente" << endl;
        }
        else
        {
            cout << "La segunda fecha es la mas reciente" << endl;
        }
    }
    else if(agno1 > agno2)
    {
        cout << "La primer fecha es la mas reciente" << endl;
    }
    else
    {
        cout << "La segunda fecha es la mas reciente" << endl;
    }
    return 0;
}
