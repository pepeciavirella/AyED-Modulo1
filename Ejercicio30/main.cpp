#include <iostream>

///---------Ej.MI-30---------
/// Dado un conjunto de valores enteros, calcular e informar a) cuántos valores cero
/// hubo, b) promedio de valores positivos, c) sumatoria de valores negativos.
/// Resolver el ejercicio para los siguientes lotes de datos:
/// 1) 167 valores enteros
/// 2) N valores, donde el valor de N debe ser leído previamente
/// 3) El conjunto de valores termina con un valor igual al anterior
/// 4) Se dan N valores, pero el proceso deberá finalizar si se procesan todos los valores o si
/// la cantidad de ceros supera a cuatro
/// 5) Se dan N valores, pero el proceso deberá finalizar si se cumple alguna de las
/// condiciones de 4) o si el promedio de positivos resulta mayor que seis
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int cantidadCeros, cantidadPositivos, contador;
    float numeroIngresado, sumaPositivos, sumaNegativos, promedioPositivos;
    cout << "---PARTE 1---" << endl << endl;
    cantidadCeros = 0;
    cantidadPositivos = 0;
    sumaPositivos = 0;
    sumaNegativos = 0;
    for(contador = 0; contador < 5; contador++)
    {
        cout << "Ingrese un numero: ";
        cin >> numeroIngresado;
        if(!numeroIngresado)    //Analogo a if(numeroIngresado == 0)
        {
            cantidadCeros++;
        }
        else if(numeroIngresado > 0)
        {
            cantidadPositivos++;
            sumaPositivos += numeroIngresado;
        }
        else                    //El unico caso restante es que sea negativo
        {
           sumaNegativos += numeroIngresado;
        }
    }
    promedioPositivos = sumaPositivos / cantidadPositivos;
    cout << "--FIN DEL INGRESO--" << endl;
    cout << "Se ingresaron, en total " << cantidadCeros << " ceros" << endl;
    cout << "El promedio de los valores positivos ingresados fue " << promedioPositivos << endl;
    cout << "La sumatoria de los valores negativos ingresados fue " << sumaNegativos << endl << endl;
    cout << "---PARTE 2---" << endl << endl;
    cantidadCeros = 0;                  //Reseteo los contadores
    cantidadPositivos = 0;
    sumaPositivos = 0;
    sumaNegativos = 0;
    cout << "Cuantos valores quiere ingresar?" << endl;
    int n;                              //Cantidad de valores a ingresar
    cin >> n;
    for(contador = 0; contador < n; contador++)  //Vuelvo a usar la variable contador; el for la inicializa en 0 en el primer ciclo
    {
        cout << "Ingrese un numero: ";
        cin >> numeroIngresado;
        if(!numeroIngresado)
        {
            cantidadCeros++;
        }
        else if(numeroIngresado > 0)
        {
            cantidadPositivos++;
            sumaPositivos += numeroIngresado;
        }
        else
        {
           sumaNegativos += numeroIngresado;
        }
    }
    promedioPositivos = sumaPositivos / cantidadPositivos;
    cout << "--FIN DEL INGRESO--" << endl;
    cout << "Se ingresaron, en total " << cantidadCeros << " ceros" << endl;
    cout << "El promedio de los valores positivos ingresados fue " << promedioPositivos << endl;
    cout << "La sumatoria de los valores negativos ingresados fue " << sumaNegativos << endl << endl;
    cout << "---PARTE 3---" << endl << endl;
    cantidadCeros = 0;
    cantidadPositivos = 0;
    sumaPositivos = 0;
    sumaNegativos = 0;
    float valorAnterior;                     //Lo necesito para saber cuando finalizar
    cout << "Ingrese un numero: ";
    cin >> numeroIngresado;
    if(!numeroIngresado)
    {
        cantidadCeros++;
    }
    else if(numeroIngresado > 0)
    {
        sumaPositivos += numeroIngresado;
        cantidadPositivos++;
    }
    else
    {
        sumaNegativos += numeroIngresado;
    }
    valorAnterior = numeroIngresado;            //Va a ser el primer valor anterior
    cout << "Ingrese otro numero: ";
    cin >> numeroIngresado;
    while(numeroIngresado != valorAnterior)         //Si ingreso uno igual al anterior corto el ingreso; no lo tengo en cuenta
    {
        if(!numeroIngresado)
        {
            cantidadCeros++;
        }
        else if(numeroIngresado > 0)
        {
            sumaPositivos += numeroIngresado;
            cantidadPositivos++;
        }
        else
        {
            sumaNegativos += numeroIngresado;
        }
        valorAnterior = numeroIngresado;
        cout << "Ingrese otro numero: ";            //A lo ultimo, para evaluar antes de actualizar los contadores
        cin >> numeroIngresado;
    }
    promedioPositivos = sumaPositivos / cantidadPositivos;
    cout << "--FIN DEL INGRESO--" << endl;
    cout << "Se ingresaron, en total " << cantidadCeros << " ceros" << endl;
    cout << "El promedio de los valores positivos ingresados fue " << promedioPositivos << endl;
    cout << "La sumatoria de los valores negativos ingresados fue " << sumaNegativos << endl << endl;
    cout << "---PARTE 4---" << endl << endl;
    cantidadCeros = 0;
    cantidadPositivos = 0;
    sumaPositivos = 0;
    sumaNegativos = 0;
    cout << "Cuantos valores quiere ingresar?" << endl;
    cin >> n;                                //Reutilizo la n que habia usado para la parte 2, la sobreescribo
    contador = 1;                            //Y tambien reutilizo esta, para evaluar no pasarme de los n ingresos
    while(contador <= n && cantidadCeros <= 4)
    {
        cout << "Ingrese un numero: ";
        cin >> numeroIngresado;
        if(!numeroIngresado)
        {
            cantidadCeros++;
        }
        else if(numeroIngresado > 0)
        {
            cantidadPositivos++;
            sumaPositivos += numeroIngresado;
        }
        else
        {
           sumaNegativos += numeroIngresado;
        }
    }
    promedioPositivos = sumaPositivos / cantidadPositivos;
    cout << "--FIN DEL INGRESO--" << endl;
    cout << "Se ingresaron, en total " << cantidadCeros << " ceros" << endl;
    cout << "El promedio de los valores positivos ingresados fue " << promedioPositivos << endl;
    cout << "La sumatoria de los valores negativos ingresados fue " << sumaNegativos << endl << endl;
    cout << "---PARTE 5---" << endl << endl;
    cantidadCeros = 0;
    cantidadPositivos = 0;
    sumaPositivos = 0;
    sumaNegativos = 0;
    cout << "Cuantos valores quiere ingresar?" << endl;
    cin >> n;
    contador = 1;
    float promedioParcial;              //Variable que voy a usar para evaluar el promedio actual en cada iteracion
    promedioParcial = 0;                //Lo inicializo asi para poder entrar al primer while
    while(contador <= n && cantidadCeros <= 4 && promedioParcial < 6)
    {
        cout << "Ingrese un numero: ";
        cin >> numeroIngresado;
        if(!numeroIngresado)
        {
            cantidadCeros++;
        }
        else if(numeroIngresado > 0)
        {
            cantidadPositivos++;
            sumaPositivos += numeroIngresado;
            promedioParcial = sumaPositivos/cantidadPositivos;
        }
        else
        {
           sumaNegativos += numeroIngresado;
        }
    }
    promedioPositivos = promedioParcial;   //No hace falta calcularlo de nuevo, deberia ser el ultimo que valio para el while
    cout << "--FIN DEL INGRESO--" << endl;
    cout << "Se ingresaron, en total " << cantidadCeros << " ceros" << endl;
    cout << "El promedio de los valores positivos ingresados fue " << promedioPositivos << endl;
    cout << "La sumatoria de los valores negativos ingresados fue " << sumaNegativos << endl << endl;
    return 0;
}
