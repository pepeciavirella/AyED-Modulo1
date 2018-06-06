#include <iostream>

/// ---------Ej.MI-12---------
/// Informar los primeros 100 números naturales y su sumatoria
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int i, sumatoria;
    sumatoria = 0;
    for(i = 1; i <= 100; i++)
    {
        cout << i << endl;
        sumatoria += i;
    }
    cout << "La suma de todos ellos es " << sumatoria << endl;
    return 0;
}
