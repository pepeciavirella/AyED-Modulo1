#include <iostream>
#include <ctype.h>

///---------Ej.MI-28---------
/// Dada una serie de caracteres que conforman una oración, donde cada palabra está separada
/// de la siguiente por un carácter blanco y la oración finaliza con un punto. Se pide informar:
/// a) cantidad de veces que apareció cada vocal
/// b) cantidad de palabras que contiene la oración
/// c) cantidad de letras que posee la palabra más larga.
/// Autor: Giuseppe Ciavirella

//HIPOTESIS: La idea de este ejercicio es ingresar los caracteres uno por uno, hasta ingresar un punto y terminar la oracion

using namespace std;

int main()
{
    char caracter, caracterAnterior;               //caracterAnterior es para verificar si es una nueva palabra o no
    int cantidadA, cantidadE, cantidadI, cantidadO, cantidadU, cantidadPalabras, largoPalabraMasLarga, largoActual;
    caracterAnterior = ' ';                       //El caracter anterior a la primera palabra es nulo
    cantidadA = 0;
    cantidadE = 0;
    cantidadI = 0;
    cantidadO = 0;
    cantidadU = 0;
    cantidadPalabras = 0;
    largoPalabraMasLarga = 0;                      //Cantidad de letras de la palabra mas larga
    largoActual = 0;                               //Cantidad de letras de la palabra actual
    cout << "Ingrese los caracteres de la oracion, uno por uno, o bien un '.' para finalizar" << endl;
    cout << "Para ingresar espacios entre palabras, use el caracter '/'" << endl;
    //NOTA: Por cuestiones de la entrada estandar de C++, ignora espacios en blanco, lo cual hacia que nunca se cuenten palabras
    //Una posible solucion era usar el flag noskipws, lo cual hacia que se ingresaran caracteres de a dos, y tampoco funcionaba
    //ESTA SOLUCION PUEDE MEJORARSE, se decidio lo de la / como espacio para cumplir los fines logicos

    do
    {
        cin >> caracter;
        switch(caracter)
        {
            case 'A': case 'a':
                cantidadA++;
                break;
            case 'E': case 'e':
                cantidadE++;
                break;
            case 'I': case 'i':
                cantidadI++;
                break;
            case 'O': case 'o':
                cantidadO++;
                break;
            case 'U': case 'u':
                cantidadU++;
                break;
        }
        if(isalnum(caracter))
        {
            largoActual++;                  //Si es una letra o digito, sumo al largo de la palabra
            if(!isalnum(caracterAnterior))
            {
                cantidadPalabras++;         //Y si antes habia un espacio, es porque arranco una nueva palabra
            }
            if(largoActual > largoPalabraMasLarga)
            {
                largoPalabraMasLarga = largoActual;     //Actualizo el largo de la palabra mas larga
            }
        }
        else                                //Si no es letra o digito, reseteo el largo actual (puede empezar una nueva palabra)
        {
            largoActual = 0;
        }
        caracterAnterior = caracter;
    }while(caracter != '.');

    cout << endl << "--FIN DEL INGRESO DE LA ORACION--" << endl << endl;
    cout << "Se ingresaron " << cantidadA << " aes en total" << endl;
    cout << "Se ingresaron " << cantidadE << " es en total" << endl;
    cout << "Se ingresaron " << cantidadI << " ies en total" << endl;
    cout << "Se ingresaron " << cantidadO << " oes en total" << endl;
    cout << "Se ingresaron " << cantidadU << " ues en total" << endl;
    cout << "La oracion contiene un total de " << cantidadPalabras << " palabras" << endl;
    cout << "La palabra mas larga posee " << largoPalabraMasLarga << " letras" << endl;
    return 0;
}
