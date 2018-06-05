#include <iostream>

using namespace std;

int main()
{
    int numero;
    float quintaParte;
    cout << "Ingrese un entero" << endl;
    cin >> numero;
    quintaParte = (float) numero/5;
    cout << "La quinta parte del numero es " << quintaParte << endl;
    cout << "El resto de dividirlo por 5 es " << numero%5 << endl;
    cout << "La septima parte de la quinta parte es " << quintaParte/7 << endl;
    return 0;
}
