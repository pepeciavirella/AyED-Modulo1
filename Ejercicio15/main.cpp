#include <iostream>
#define TAMMOTIVO 100

/// ---------Ej.MI-15---------
/// Se realiza una inspección en una fábrica de pinturas, y se detectaron 20
/// infracciones. De cada infracción se tomó nota de los siguientes datos:
/// - Tipo de Infracción (1, 2, 3, ó 4)
/// - Motivo de la infracción
/// - Valor de la multa
/// - Gravedad de la infracción (‘L’,‘M’, ‘G’)
/// Se pide informar al final del proceso:
///  Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
///  La leyenda “Clausurar fábrica” si la cantidad de infracciones
/// 3 y 4 con gravedad “G” sean mayor a 3.
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int contador, tipoInfraccion, cantGravesTipo3, cantGravesTipo4;
    float valorMulta, multaTotalL, multaTotalM, multaTotalG;
    char motivo[TAMMOTIVO];
    char gravedad;
    multaTotalL = 0;
    multaTotalM = 0;
    multaTotalG = 0;
    cantGravesTipo3 = 0;
    cantGravesTipo4 = 0;
    for(contador = 1; contador <= 8; contador++)
    {
        cout << "--Ingrese los datos de la infraccion " << contador << "--" << endl << endl;
        cout << "Tipo: ";
        cin >> tipoInfraccion;
        cout << "Motivo: ";
        cin >> motivo;
        cout << "Valor de multa asociada: ";
        cin >> valorMulta;
        cout << "Gravedad de la infraccion: ";
        cin >> gravedad;
        cout << endl;
        switch(gravedad)                              //Puedo hacerlo porque gravedad es un char, y los char son ints
        {
            case 'l': case 'L':
                multaTotalL += valorMulta;
                break;
            case 'm': case 'M':
                multaTotalM += valorMulta;
                break;
            case 'g': case 'G':
                multaTotalG += valorMulta;
                if(tipoInfraccion == 3)
                {
                    cantGravesTipo3++;
                }
                else if(tipoInfraccion == 4)
                {
                    cantGravesTipo4++;
                }
        }
    }
    cout << "----RESULTADOS----" << endl;
    cout << "Total de multas por infracciones de gravedad L: " << multaTotalL << endl;
    cout << "Total de multas por infracciones de gravedad M: " << multaTotalM << endl;
    cout << "Total de multas por infracciones de gravedad G: " << multaTotalG << endl;
    if(cantGravesTipo3 > 3 && cantGravesTipo4 > 3)    //No pongo parentesis en el if, la precedencia de && es mayor que la de >
    {
        cout << "Clausurar fabrica" << endl;
    }
    return 0;
}
