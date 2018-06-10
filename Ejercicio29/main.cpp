#include <iostream>

///---------Ej.MI-29---------
/// Dado un n�mero entero positivo entre 1 y 3999 informar su correspondiente numero Romano
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    unsigned int numeroArabigo;             //#Dato: Se llaman asi :D
    int unidadesDeMil, centenas, decenas, unidades;
    cout << "Ingrese un numero entre 1 y 3999" << endl;
    cin >> numeroArabigo;
    unidadesDeMil = numeroArabigo / 1000;
    centenas = (numeroArabigo - unidadesDeMil * 1000) / 100;
    decenas = (numeroArabigo - unidadesDeMil * 1000 - centenas * 100) / 10;
    unidades = (numeroArabigo - unidadesDeMil * 1000 - centenas * 100 - decenas * 10);
    cout << "El numero romano equivalente es: ";   //No pongo endl para ir poniendo las letras en ese renglon, y a continuacion
    //NOTA: No pongo casos default en los switch, no seria necesario en este caso
    switch(unidadesDeMil)
    {
        case 1:
            cout << "M";
            break;
        case 2:
            cout << "MM";
            break;
        case 3:
            cout << "MMM";
            break;
    }
    switch(centenas)
    {
        case 1:
            cout << "C";
            break;
        case 2:
            cout << "CC";
            break;
        case 3:
            cout << "CCC";
            break;
        case 4:
            cout << "CD";
            break;
        case 5:
            cout << "D";
            break;
        case 6:
            cout << "DC";
            break;
        case 7:
            cout << "DCC";
            break;
        case 8:
            cout << "DCCC";
            break;
        case 9:
            cout << "CM";
            break;
    }
    switch(decenas)
    {
        case 1:
            cout << "X";
            break;
        case 2:
            cout << "XX";
            break;
        case 3:
            cout << "XXX";
            break;
        case 4:
            cout << "XL";
            break;
        case 5:
            cout << "L";
            break;
        case 6:
            cout << "LX";
            break;
        case 7:
            cout << "LXX";
            break;
        case 8:
            cout << "LXXX";
            break;
        case 9:
            cout << "XC";
            break;
    }
    switch(unidades)
    {
        case 1:
            cout << "I";
            break;
        case 2:
            cout << "II";
            break;
        case 3:
            cout << "III";
            break;
        case 4:
            cout << "IV";
            break;
        case 5:
            cout << "V";
            break;
        case 6:
            cout << "VI";
            break;
        case 7:
            cout << "VII";
            break;
        case 8:
            cout << "VIII";
            break;
        case 9:
            cout << "IX";
            break;
    }
    return 0;
}
