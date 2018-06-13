#include <iostream>

///---------Ej.MI-40---------
/// Desarrollar el procedimiento string Tendencia(int A, int B) que,
/// dados dos valores A y B, retorne una cadena de acuerdo al siguiente cuadro:
/// Si B-A < 0       -> Decreciente
/// Si B-A < 2% de A -> Estable
/// Si B-A < 5% de A -> Leve Ascenso
/// Resto            -> Ascenso
/// Autor: Giuseppe Ciavirella

using namespace std;

string tendencia(int a,int b)
{
    int diferencia = b - a;
    if(diferencia < 0)
    {
        return "Decreciente";
    }
    else if(diferencia < (a * 0.02))
    {
        return "Estable";
    }
    else if(diferencia < (a * 0.05))
    {
        return "Leve ascenso";
    }
    return "En ascenso";                    //Si llego hasta aca, no cayo en ningun if ni retorno nada
}

int main()
{
    int unValor, otroValor;
    cout << "Ingrese dos valores enteros" << endl;
    cin >> unValor >> otroValor;
    cout << "Dados los valores, la tendencia es " << tendencia(unValor,otroValor) << endl;
    //NOTA: No guarde el retorno de tendencia en una variable, sino que simplemente lo pase al cout ;)
    return 0;
}
