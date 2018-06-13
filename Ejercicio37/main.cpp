#include <iostream>

///---------Ej.MI-37---------
/// Desarrolle la función float CalcularPorcentajeDiferencia(int A ,int B)
/// que recibe dos valores y retorne el siguiente cálculo: (B-A) *100 / (A+B)
/// Autor: Giuseppe Ciavirella

using namespace std;

float calcularPorcentajeDiferencia(int a,int b)
{
    return (float) (((b-a)*100)/(a+b));
}

int main()
{
    int unValor, otroValor;
    float porcentajeDiferencia;
    cout << "Ingrese dos valores enteros" << endl;
    cin >> unValor >> otroValor;
    porcentajeDiferencia = calcularPorcentajeDiferencia(unValor,otroValor);
    cout << "El porcentaje diferencial entre ambos es del " << porcentajeDiferencia << "%";
    return 0;
}
