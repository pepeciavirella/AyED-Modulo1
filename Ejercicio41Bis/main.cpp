#include <iostream>
#include <ctype.h>                              //Para LONG_MAX

///---------Ej.MI-41Bis---------
/// De un censo realizado en una población se conocen los siguientes datos:
/// - Día de nacimiento (2 dig.)
/// - Mes (2 dig.)
/// - Año (4 dig.)
/// - Sexo ('M'=masc. 'F'=fem.)
/// Con estos datos de cada habitante se forma un lote finalizado con un día cero.
/// Desarrollar el programa que determine e imprima:
/// 1) Cuántos nacimientos hubo en el mes de octubre de todos los años.
/// 2) Cuántos nacimientos hubo antes del 9 de julio de 1990.
/// 3) Cuántos nacimientos de mujeres hubo en la primavera del 1982.
/// 4) Sexo de la persona más vieja (solo existe una)
/// Autor: Giuseppe Ciavirella

using namespace std;

long obtenerFecha(int dia, int mes, int agno)
{
    long fecha;
    fecha = dia + mes * 100 + agno * 10000;
    return fecha;
}

bool esEnPrimavera1982(long fecha)
{
    if(fecha >= 19820921 && fecha <= 19821221)
    {
        return true;                                    //Aca ya cortaria
    }
    return false;
}

int main()
{
    int dia, mes, agno;
    int cantNacimientosOctubre, cantNacimientosAntesDel9DeJulio, cantNacimientosMujeresPrimavera82;
    char sexo;
    char sexoMasViejo;
    long fecha, fechaMasVieja;
    cantNacimientosOctubre = 0;                                 //Inicializo las variables contadoras
    cantNacimientosAntesDel9DeJulio = 0;
    cantNacimientosMujeresPrimavera82 = 0;
    fechaMasVieja = LONG_MAX;
    bool huboIngresos = false;                                  //Para couts del final
    cout << "--INGRESO DE PERSONAS CENSADAS--" << endl << endl;
    cout << "Dia de nacimiento: ";
    cin >> dia;
    if(dia > 0)
    {
        huboIngresos = true;
    }

    while(dia > 0)
    {
        cout << "Mes de nacimiento: ";
        cin >> mes;
        cout << "Anio de nacimiento: ";
        cin >> agno;
        fecha = obtenerFecha(dia, mes, agno);
        cout << "Sexo ('F' o 'M'): ";
        cin >> sexo;
        if(mes == 10)
        {
            cantNacimientosOctubre++;
        }
        if(fecha < 19900709)
        {
            cantNacimientosAntesDel9DeJulio++;
        }
        if(sexo == 'F' && esEnPrimavera1982(fecha))
        {
            cantNacimientosMujeresPrimavera82++;
        }
        if(fecha < fechaMasVieja)
        {
            fechaMasVieja = fecha;
            sexoMasViejo = sexo;
        }
        cout << endl << "Dia de nacimiento: ";
        cin >> dia;
    }

    cout << endl << "--FIN DEL INGRESO DE CENSADOS--" << endl << endl;
    if(huboIngresos)                                //Si es verdadero
    {
        cout << cantNacimientosOctubre << " personas nacieron en el mes de octubre" << endl;
        cout << cantNacimientosAntesDel9DeJulio << " personas nacieron antes del 09/07/1990" << endl;
        cout << cantNacimientosMujeresPrimavera82 << " mujeres nacieron en la primavera de 1982" << endl;
        if(sexoMasViejo == 'F')
        {
            cout << "La persona mas vieja fue una mujer" << endl;
        }
        else if(sexoMasViejo == 'M')
        {
            cout << "La persona mas vieja fue un hombre" << endl;
        }
    }
    else
    {
        cout << "No se registro el ingreso de ninguna persona" << endl;
    }
    return 0;
}
