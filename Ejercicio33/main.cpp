#include <iostream>

///---------Ej.MI-33---------
/// Desarrollar una funci�n que calcule el m�ximo com�n divisor de dos n�meros
/// enteros A, B con el siguiente algoritmo:
/// 1) Dividir A por B, y calcular el resto (0 < R < B)
/// 2) Si R = 0, el MCD es B, si no seguir en 3)
/// 3) Reemplazar A por B, B por R, y volver al paso 1)
/// Autor: Giuseppe Ciavirella

using namespace std;

int mcd(int a,int b)
{
    int resto;
    resto = a%b;
    if(resto == 0)
    {
        return b;
    }
    return mcd(b,resto);
}

int main()
{
    int unNumero, otroNumero;
    cout << "Ingrese dos numeros enteros" << endl;
    cin >> unNumero >> otroNumero;
    cout << "Su maximo comun divisor es " << mcd(unNumero,otroNumero) << endl;
    return 0;
}
