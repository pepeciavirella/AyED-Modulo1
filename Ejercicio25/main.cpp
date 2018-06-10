#include <iostream>

///---------Ej.MI-25---------
/// Dada una serie de M pares {color, número} que corresponden a los tiros de una
/// ruleta. Se pide informar:
/// a) cuántas veces salió el número cero y el número anterior a cada cero
/// b) cuántas veces seguidas llegó a repetirse el color negro
/// c) cuántas veces seguidas llegó a repetirse el mismo número y cuál fue
/// d) el mayor número de veces seguidas que salieron alternados el rojo y el negro
/// e) el mayor número de veces seguidas que se negó la segunda docenas
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int m, cantidadCeros, numeroIngresado, numeroAnterior, negrosSeguidos, numeroMasRepetido, repeticionesMasRepetido;
    int repeticionesActual, rojoNegroAlternado,segundaDocenaNegadaActual, maxNegrosSeguidos, maxRojoNegroAlternado;
    int maxSegundaDocenaNegada, i; //i es un contador para el for
    char color, colorAnterior;
    cantidadCeros = 0;                  //Cantidad de veces que salio cero
    negrosSeguidos = 0;                 //Cantidad de veces seguidas que salio el negro
    maxNegrosSeguidos = 0;              //Mayor cantidad de veces seguidas que salio el negro
    repeticionesMasRepetido = 0;        //Cantidad de veces que se repitio el numero mas repetido
    repeticionesActual = 0;             //Cantidad de veces que se repitio el numero actual
    rojoNegroAlternado = 0;             //Cantidad de veces seguidas que se alternaron negro y rojo
    maxRojoNegroAlternado = 0;          //Mayor cCantidad de veces seguidas que se alternaron negro y rojo
    segundaDocenaNegadaActual = 0;      //Cantidad de veces seguidas que se nego la segunda docena
    maxSegundaDocenaNegada = 0;         //Mayor cantidad de veces seguidas que se nego la segunda docena

    cout << "Cuantos pares (color;numero) quiere ingresar?" << endl;
    cin >> m;
    cout << "REGLAS: 'R' significa rojo; 'N' significa negro; las minusculas no cuentan" << endl;
    cout << "Ingrese el color, y luego el numero, del primer tiro:" << endl;
    cin >> color;
    cin >> numeroIngresado;
    if(numeroIngresado == 0)
    {
        cantidadCeros++;
    }
    numeroAnterior = numeroIngresado;
    if(color == 'N')
    {
        negrosSeguidos++;
        maxNegrosSeguidos = negrosSeguidos;
    }
    repeticionesActual++;
    repeticionesMasRepetido = repeticionesActual;
    numeroMasRepetido = numeroIngresado;
    colorAnterior = color;
    if(numeroIngresado < 12 || numeroIngresado > 23)        //Entiendo que la segunda docena es del 12 al 23 inclusive
    {
        segundaDocenaNegadaActual++;
        maxSegundaDocenaNegada = segundaDocenaNegadaActual;
    }

    for(i = 1; i < m; i++)      //Hago <= m e inicializo en 1, ya que debia ingresar m pares y ya ingrese el primero
    {
        cout << "Ingrese el color, y luego el numero, de otro tiro:" << endl;
        cin >> color;
        cin >> numeroIngresado;

        if(numeroIngresado == 0)
        {
            cantidadCeros++;
            cout << "Se ingreso un 0! El numero anterior habia sido un " << numeroAnterior << endl;
        }
        if(color == 'N')
        {
            negrosSeguidos++;
            if(negrosSeguidos > maxNegrosSeguidos)
            {
                maxNegrosSeguidos = negrosSeguidos;     //Si supera la seguidilla anterior, la actualizo
            }
        }
        else
        {
            negrosSeguidos = 0;         //Si salio rojo, reseteo la cantidad de tiros negros seguidos
        }
        if(numeroIngresado == numeroAnterior)
        {
            repeticionesActual++;
            if(repeticionesActual > repeticionesMasRepetido)
            {
                numeroMasRepetido = numeroIngresado;            //HACK: Si dos numeros son los mas repetidos, solo informa uno
                repeticionesMasRepetido = repeticionesActual;   //(el que primero obtuvo la marca)
            }
        }
        else
        {
            repeticionesActual = 1;    //Si no es igual al anterior, vuelvo el contador de repetidos actuales de este numero a 1
        }
        if(color != colorAnterior)     //Si los colores difieren, se alternaron
        {
            rojoNegroAlternado++;      //Aumento la cantidad de alternaciones actual
            if(rojoNegroAlternado > maxRojoNegroAlternado)
            {
                maxRojoNegroAlternado = rojoNegroAlternado;     //Actualizo si es necesario
            }
        }
        else
        {
            rojoNegroAlternado = 0;
        }
        if(numeroIngresado < 12 && numeroIngresado > 23)        //Verifico y actualizo las repeticiones de 2da docena negada
        {
            segundaDocenaNegadaActual++;
            if(segundaDocenaNegadaActual > maxSegundaDocenaNegada)
            {
                maxSegundaDocenaNegada = segundaDocenaNegadaActual;
            }
        }
        else
        {
            segundaDocenaNegadaActual = 0;
        }

        numeroAnterior = numeroIngresado;
        colorAnterior = color;
    }

    cout << endl << "--FIN DEL INGRESO DE PARES. RESUMEN DE LOS TIROS--" << endl << endl;
    if(cantidadCeros == 0)
    {
        cout << "El numero 0 no salio en ningun tiro" << endl;
    }
    else if(cantidadCeros == 1)
    {
        cout << "El numero 0 salio una sola vez" << endl;
    }
    else
    {
        cout << "El numero 0 salio un total de " << cantidadCeros << " veces" << endl;
    }
    if(maxNegrosSeguidos == 0)
    {
        cout << "El color negro no salio en ningun tiro" << endl;
    }
    else if(maxNegrosSeguidos == 1)
    {
        cout << "Cada tiro que contenia al color negro fue aislado" << endl;
    }
    else
    {
           cout << "Se repitio el color negro un maximo de " << maxNegrosSeguidos << " veces seguidas" << endl;
    }
    if(repeticionesMasRepetido == 1)
    {
        cout << "El numero que mas veces seguidas salio fue el " << numeroMasRepetido << ", una sola vez" << endl;
    }
    else
    {
        cout << "El numero que mas veces seguidas se repitio fue el " << numeroMasRepetido << ", unas " << repeticionesMasRepetido << " veces" << endl;
    }
    if(maxRojoNegroAlternado == 0)
    {
        cout << "Los colores nunca se alternaron, todos los tiros fueron del mismo color" << endl;
    }
    else if(maxRojoNegroAlternado == 1)
    {
        cout << "Los colores se alternaron una sola vez" << endl;
    }
    else
    {
        cout << "Se alternaron los colores un maximo de " << maxRojoNegroAlternado << " veces seguidas" << endl;
    }
    if(maxSegundaDocenaNegada == 0)
    {
        cout << "Nunca se nego la segunda docena" << endl;
    }
    else if(maxSegundaDocenaNegada == 1)
    {
        cout << "Cada vez que se nego la segunda docena, fue de manera aislada" << endl;
    }
    else
    {
        cout << "La segunda docena llego a negarse " << maxSegundaDocenaNegada << " veces seguidas" << endl;
    }
    return 0;
}
