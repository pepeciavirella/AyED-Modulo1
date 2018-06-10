#include <iostream>
#include <climits>          //Biblioteca que contiene los maximos y minimos valores de cada tipo de dato; contiene definidas las
                            //constante INT_MIN, cuyo valor es -32767, e INT_MAX = 32767, entre otros

///---------Ej.MI-23---------
/// Dado un conjunto de valores, que finaliza con un valor nulo,
/// determinar e imprimir (si hubo valores):
/// a) El valor máximo negativo
/// b) El valor mínimo positivo
/// c) El valor mínimo dentro del rango -17.3 y 26.9
/// d) El promedio de todos los valores
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    float numero, maximoNegativo, minimoPositivo, minimoRango, suma, promedio;
    int cantidad;
    bool huboEnRango, huboPositivo, huboNegativo;               //Estos tres bool son flags para saber si imprimir su valor o un mensaje
    minimoPositivo = INT_MAX;                                   //Los inicializos para el chequeo del do-while; si no ingresase ninguno
    maximoNegativo = INT_MIN;                                   //que lo cambie, no lo imprimire al estar el flag en false
    minimoRango = -17.3;                                        //Seria el valor minimo posible; si el flag esta en false, no imprimira
    huboEnRango = false;                                        //Arrancan siendo falsos, no hubo ingreso aun
    huboPositivo = false;
    huboNegativo = false;
    suma = 0;
    cout << "Ingrese un numero, o 0 para terminar el ingreso" << endl;
    cin >> numero;
    if(numero == 0)
    {
        cout << "Fin del ingreso, no se registraron valores" << endl;
    }
    else
    {
        cantidad++;
        suma += numero;
        if(numero > 0)
        {
            minimoPositivo = numero;
            huboPositivo = true;
        }
        else if(numero < 0)
        {
            maximoNegativo = numero;
            huboNegativo = true;
        }
        if(numero >= -17.3 && numero <= 26.9) //No necesito parentesis en las condiciones, la precedencia de && es mayor
        {
            huboEnRango = true;
            minimoRango = numero;
        }
        do{
            cout << "Ingrese otro numero, o 0 para terminar el ingreso" << endl;
            cin >> numero;
            cantidad++;
            suma += numero;
            if(numero > 0 && numero < minimoPositivo)       //Ahora tambien verifico que sea menor al minimo registrado (si no hubo, sera 0)
            {
                minimoPositivo = numero;
                huboPositivo = true;
            }
            else if(numero < 0 && numero > maximoNegativo)
            {
                maximoNegativo = numero;
                huboNegativo = true;
            }
            if(numero >= -17.3 && numero <= 26.9 && numero < minimoRango)
            {
                minimoRango = numero;
                huboEnRango = true;
            }
        }while(numero);                     //Equivalente a hacer while(numero != 0)
        promedio = suma/cantidad;
        cout << endl << "---FIN DEL INGRESO---" << endl << endl;
        cout << "El promedio de los valores ingresados fue " << promedio << endl;
        if(huboNegativo)
        {
            cout << "El valor maximo negativo ingresado fue " << maximoNegativo << endl;
        }
        else
        {
            cout << "No se ingresaron valores negativos" << endl;
        }
        if(huboPositivo)
        {
            cout << "El valor minimo positivo ingresado fue " << minimoPositivo << endl;
        }
        else
        {
            cout << "No se ingresaron valores positivos" << endl;
        }
        if(huboEnRango)
        {
            cout << "El valor minimo dentro del rango [-17.3,26.9] fue " << minimoRango << endl;
        }
        else
        {
            cout << "No se ingresaron valores dentro del rango [-17.3,26.9]" << endl;
        }
    }
    return 0;
}
