#include <iostream>
#include <cstring>
#define TAM_NOMBRE 50 //Para definir un maximo de tamaño, usando constantes predefinidas

///---------Ej.MI-22---------
/// Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que  finaliza con
/// un Nombre = ‘FIN’, informar el nombre de la persona con mayor edad y el de la más joven
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    long nacimiento, masReciente, masAntiguo;
    char nombre[TAM_NOMBRE], masJoven[TAM_NOMBRE], masViejo[TAM_NOMBRE];
    bool huboIngresos = false;
    masReciente = 0;
    masAntiguo = 0;
    cout << "Ingrese el nombre de la primer persona, o FIN para terminar" << endl;
    cin >> nombre;
    if(strcmp(nombre,"FIN")){
        cout << "Ingrese su fecha de nacimiento en formato AAAAMMDD" << endl;
        cin >> nacimiento;
        masReciente = nacimiento;
        masAntiguo = nacimiento;
        strcpy(masJoven, nombre);
        strcpy(masViejo, nombre);           //strcpy copia una cadena en otra!
        huboIngresos = true;
    }
    while(strcmp(nombre,"FIN"))             //Para verificar que no se haya ingresado FIN (debe ser todo en mayusculas)
    {
        cout << "Ingrese el nombre de otra persona, o FIN para terminar" << endl;
        cin >> nombre;
        if(strcmp(nombre,"FIN"))
        {
            cout << "Ingrese su fecha de nacimiento en formato AAAAMMDD" << endl;
            cin >> nacimiento;
            if(nacimiento < masAntiguo)
            {
                masAntiguo = nacimiento;
                strcpy(masViejo, nombre);
            }
            if(nacimiento > masReciente)
            {
                masReciente = nacimiento;
                strcpy(masJoven, nombre);
            }
        }
    }    //Para verificar que no se haya ingresado FIN (debe ser todo en mayusculas)
    if(huboIngresos)
    {
        cout << "La persona mas joven es " << masJoven << endl;
        cout << "La persona mas vieja es " << masViejo << endl;
    }
    else{
        cout << "No se registro el ingreso de personas" << endl;
    }
    return 0;
}
