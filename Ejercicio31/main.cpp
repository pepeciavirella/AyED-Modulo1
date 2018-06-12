#include <iostream>
#include <cstring>              //Para usar strcpy
#define TAMDOMICILIO 50         //Para las cadenas de domicilios

///---------Ej.MI-31---------
/// El gobierno de la Ciudad de Buenos Aires realiza una encuesta en casas de familia. De
/// cada familia conoce: domicilio, tipo de vivienda (‘C’:casa, ‘D’:departamento), y cantidad de integrantes.
/// De cada integrante de la familia se conoce: nombre y apellido, edad, sexo (‘F’, ‘M’), nivel de
/// estudios alcanzados (‘N’: no posee, ‘P’: primario, ‘S’: secundario, ‘T’: terciario, ‘U’:
/// universitario), y un indicador (‘I’: incompleto, ‘C’: completo) que se refiere al ítem anterior.
/// Los datos finalizan cuando la cantidad de integrantes sea igual a cero.
/// Se pide emitir un listado con los resultados:
/// a) los datos de los encuestados que hayan completado los estudios primarios
/// b) el porcentaje de analfabetismo en la ciudad (se considera analfabetos a los mayores de
/// 10 años que no posean estudios)
/// c) el domicilio de la familia con mayor cantidad de integrantes que viven en
/// departamento
/// d) edad promedio de cada familia y de la ciudad
/// e) cantidad de encuestados en cada tipo de nivel de estudios alcanzados incompletos.
/// f) porcentaje de encuestados de sexo femenino y masculino
/// Autor: Giuseppe Ciavirella

//HIPOTESIS: Para el punto a, como a este punto de la cursada no se habian visto arrays aun, se opto resolver
//mostrando un mensaje con los datos correspondientes cada vez que se ingresara un encuestado con tales condiciones

using namespace std;

int main()
{
    int cantidadEncuestados, cantidadAnalfabetos, mayorCantidadHabitantesDepto, sumaEdadesFamilia;
    int sumaEdadesCiudad, cantidadPrimarioIncompleto, cantidadSecundarioIncompleto, cantidadTerciarioIncompleto;
    int cantidadUniversitarioIncompleto, cantidadHombres, cantidadMujeres;
    float edadPromedioFamilia, edadPromedioCiudad;
    int cantidadIntegrantes, contador, edad;                //Variables a ingresar para cada familia o integrante
    char tipoVivienda, sexo, nivelEstudios, estadoEstudios;
    char domicilio[TAMDOMICILIO];
    char nombre[25];
    char apellido[25];
    char domicilioMasHabitantes[TAMDOMICILIO];     //El domicilio con mayor cantidad de habitantes
    cantidadEncuestados = 0;
    cantidadAnalfabetos = 0;
    mayorCantidadHabitantesDepto = 0;       //La cantidad de habitantes del departamento con mayor cantidad hasta el momento
    sumaEdadesFamilia = 0;                  //La suma de edades de los integrantes, propia de cada familia
    sumaEdadesCiudad = 0;                   //La suma de edades de todos los encuestados
    cantidadPrimarioIncompleto = 0;         //Contadores para los estudios incompletos
    cantidadSecundarioIncompleto = 0;
    cantidadTerciarioIncompleto = 0;
    cantidadUniversitarioIncompleto = 0;
    cantidadHombres = 0;
    cantidadMujeres = 0;
    cout << "REGLAS: No ingresar espacios, sino '/' en su lugar" << endl; //Para que el cin no tome solo hasta el espacio
    cout << endl << "---DATOS DE LA FAMILIA---" << endl;
    cout << "Domicilio: ";
    cin >> domicilio;
    cout << "Tipo de vivienda ('C' = casa; 'D' = departamento) : ";
    cin >> tipoVivienda;
    cout << "Cantidad de integrantes: ";
    cin >> cantidadIntegrantes;
    while(cantidadIntegrantes > 0)
    {
        if(cantidadIntegrantes > mayorCantidadHabitantesDepto && tipoVivienda == 'D')
        {

            mayorCantidadHabitantesDepto = cantidadIntegrantes;
            strcpy(domicilioMasHabitantes,domicilio);               //Guardo el domicilio como el de mas habitantes
        }
        for(contador = 1; contador <= cantidadIntegrantes; contador++)
        {
            cout << endl << "--DATOS DEL INTEGRANTE " << contador << "--" << endl;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;
            cout << "Edad: ";
            cin >> edad;
            cout << "Sexo ('F' = femenino; 'M' = masculino) : ";
            cin >> sexo;
            cout << "Nivel de estudios alcanzados:" << endl;
            cout << "('N' = no posee; 'P' = primario; 'S' = secundario; 'T' = terciario; 'U' = universitario)" << endl;
            cin >> nivelEstudios;
            cout << "Estadio del nivel alcanzado ('I' = incompleto; 'C' = completo): ";
            cin >> estadoEstudios;
            cantidadEncuestados++;
            sumaEdadesFamilia += edad;
            sumaEdadesCiudad += edad;
            if((nivelEstudios == 'P' && estadoEstudios == 'C') || (nivelEstudios >= 'S')) //Use una comparacion por valor ASCII
            {                                                                             //porque se prestaban las condiciones
                cout << "Felicitaciones para " << nombre << " " << apellido << " por completar el primario!" << endl;
            }
            if(edad > 10 && nivelEstudios == 'N')
            {
                cantidadAnalfabetos++;
            }
            if(estadoEstudios == 'I')
            {
                if (nivelEstudios == 'P')
                {
                    cantidadPrimarioIncompleto++;
                }
                else if (nivelEstudios == 'S')
                {
                    cantidadSecundarioIncompleto++;
                }
                else if (nivelEstudios == 'T')
                {
                    cantidadTerciarioIncompleto++;
                }
                else if (nivelEstudios == 'U')
                {
                    cantidadUniversitarioIncompleto;
                }
            }
            if(sexo == 'M')
            {
                cantidadHombres++;
            }
            else if(sexo == 'F')
            {
                cantidadMujeres++;
            }
        }
        edadPromedioFamilia = (float) sumaEdadesFamilia/cantidadIntegrantes;
        cout << "La edad promedio de la familia fue " << edadPromedioFamilia << endl ;
        sumaEdadesFamilia = 0;                  //Reseteo para el calculo de la proxima familia
        cout << endl << "---DATOS DE LA FAMILIA---" << endl;
        cout << "Domicilio: ";
        cin >> domicilio;
        cout << "Tipo de vivienda ('C' = casa; 'D' = departamento) : ";
        cin >> tipoVivienda;
        cout << "Cantidad de integrantes: ";
        cin >> cantidadIntegrantes;
    }
    cout << endl << "---FIN DEL CENSO. RESULTADOS---" << endl << endl;
    edadPromedioCiudad = (float) sumaEdadesCiudad / cantidadEncuestados;
    float porcentajeAnalfabetismo = ((float) cantidadAnalfabetos / cantidadEncuestados) * 100; //*100 para que sea porcentaje
    float porcentajeMasculino = ((float) cantidadHombres / cantidadEncuestados) * 100;
    float porcentajeFemenino = ((float) cantidadMujeres / cantidadEncuestados) * 100;
    cout << "El porcentaje de analfabetismo de la ciudad es del " << porcentajeAnalfabetismo << "%" << endl;
    cout << "La familia residente en departamento con mas integrantes vive en " << domicilioMasHabitantes << endl;
    cout << "La edad promedio de la ciudad es de " << edadPromedioCiudad << endl;
    cout << "Se encuesto a " << cantidadPrimarioIncompleto << " personas con la primaria incompleta" << endl;
    cout << "Se encuesto a " << cantidadSecundarioIncompleto << " personas con la secundaria incompleta" << endl;
    cout << "Se encuesto a " << cantidadTerciarioIncompleto << " personas con el terciario incompleta" << endl;
    cout << "Se encuesto a " << cantidadUniversitarioIncompleto << " personas con la universidad incompleta" << endl;
    cout << "El " << porcentajeFemenino << "% de los encuestados eran mujeres" << endl;
    cout << "El " << porcentajeMasculino << "% de los encuestados eran hombres" << endl;
    return 0;
}
