#include <iostream>

using namespace std;

int main()
{
    int a, b, suma, resta1, resta2, producto;
    cout << "Ingrese dos valores enteros" << endl;
    cin >> a >> b;
    suma = a + b;
    resta1 = a - b;
    resta2 = b - a;
    producto = a * b;
    cout << "La suma entre ambos es " << suma << endl;
    cout << "Las restas entre ambos son " << resta1 << " y " << resta2 << endl;
    cout << "Y el producto entre ambos es " << producto << endl;
    return 0;
}
