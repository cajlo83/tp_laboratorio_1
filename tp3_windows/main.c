/*
 * autor: Carlo Morici
 * tittle: tp3
 * date: 08/06/2022
 *
 *
 *
 *
	1 Enunciado

	Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo, para lo cual se deberá desarrollar una solución implementando la biblioteca LinkedList. Se deberá modelar la entidad que representa un pasajero con todos sus datos asociados de tal manera que la misma permita interactuar con las estructuras de datos almacenadas en los archivos.
	Se deberá reutilizar la biblioteca del tp2 de la entidad pasajero en este tp, realizándole las modificaciones pertinentes para que funcione correctamente con los archivos y se utilice memoria dinámica.
	Nota: Si el tp2 no fue entregado el tp3 no será evaluado en la primera instancia. Se corregirá junto con los recuperatorios.


	El programa deberá tener el siguiente menú de opciones:

	1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
	2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
	3. Alta de pasajero
	4. Modificar datos de pasajero
	5. Baja de pasajero
	6. Listar pasajeros
	7. Ordenar pasajeros
	8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
	9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
	10. Salir
 *
 *
 *
 */

/*
 * INFO DE LOS VUELOS GUARDADOS
 */
/*
BA2491A - Aterrizado
IB0800A - Aterrizado
MM0987B  - En Horario
TU6789B  - Aterrizado
GU2345F  - En Vuelo
HY4567D  - Demorado
FR5678G  - En Horario
BR3456J -  Demorado
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "personalio.h"

#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "ArrayPassenger.h"

#include "setups.h"

#define CARGA_TXT 1
#define CARGA_BIN 2
#define ALTA_PASAJERO 3
#define MODIFICAR_PASAJERO 4
#define BAJA_PASAJERO 5
#define LISTAR_PASAJEROS 6
#define ORDENAR_PASAJEROS 7
#define GUARDA_TXT 8
#define GUARDA_BIN 9
#define EXIT_MAIN 10


#define RESERVA_MEMORIA 20

#define VUELOS 4
#define TIPOS 4





int main()
{
	setbuf( stdout, NULL );

	// cadenas con ubicaciones de archivos
	char* pathCsv= "data.csv";
	char* pathBin= "data.dat";
	char* pathConfig= "config.dat";

	// variables controladoras datos
	Config config;
	int idCurrent;
	int unsavedPassengerCsv= 0;
	int unsavedPassengerBin= 0;



	// variables para control del menu
	int option;
	int returned= -2;


	// declaracion e inicializacion de la listas
	LinkedList* listaPasajeros_buffer = ll_newLinkedList();

	// se lee data de configuracion guardada, si no existe se crea y se respalda con informacion de contingencia
	config= configFile(pathConfig, pathCsv, pathBin);
	idCurrent= configIdCurrent(listaPasajeros_buffer, config);




    do{




    	// despliegue de opciones del menu y validacion de seleccion
    	option= mainMenu(CARGA_TXT, EXIT_MAIN);


        switch(option)
        {
            case CARGA_TXT :

            	returned= controller_loadFromText( pathCsv,  listaPasajeros_buffer);
            	printf("\n id maximo desde csv: %d", returned);
            	returned= -2;
                break;
                /*
                 *
                 */
            case CARGA_BIN:

           	 returned= controller_loadFromBinary( "data.dat",  listaPasajeros_buffer);
           	 printf("\n indice maximo: %d", returned);
           	 returned= -2;
           	 break;
           	 /*
         	 *
         	 */
         case ALTA_PASAJERO:

         	returned= controller_addPassenger(listaPasajeros_buffer);
         	if( returned>config.idTxt )
         	{
         		unsavedPassengerBin++;
         		unsavedPassengerCsv++;
         	}

         	break;
         	/*
         	 *
         	 */
         case MODIFICAR_PASAJERO :

        	 break;
           	 /*
           	  *
           	  */
            case GUARDA_TXT :

            	if( unsavedPassengerCsv )
            	{
            		returned= controller_saveAsText( "data2222.csv", listaPasajeros_buffer);
            		printf("\nMaxima id guardada: %d", returned);
            	}

            	if( returned>0 )	//segun el retorno de controller, se modifican datos configuraciones y de control
				{

            		config.idTxt= returned;
            		returned= -2;
            		unsavedPassengerCsv= 0;
				}
            	break;
            	/*
            	 *
            	 */
            case GUARDA_BIN :

            	if( unsavedPassengerBin )
            	{
            		returned= controller_saveAsBinary( pathBin, listaPasajeros_buffer);
            		printf("\nMaxima id guardada: %d", returned);
            	}

            	if( returned>0 )	//segun el retorno de controller, se modifican datos configuraciones y de control
				{
            		config.idBin= returned;
            		returned= -2;
					unsavedPassengerBin= 0;
				}
            	break;
            	/*
            	 *
            	 */
            case EXIT_MAIN :

            	if( !unsavedPassengerBin && !unsavedPassengerCsv )
            	{
            		option =11;
            	}
            	else
            	{
            		printf("\nTiene cambios sin aplicar a los archivos");
            		if( unsavedPassengerBin )
            		{
            			printf("\nGuarde archivo binario");
            		}
            		if( unsavedPassengerCsv )
            		{
            			printf("\nGuarde archivo de texto");
            		}
            	}

        }
    }while(option != 11);


    // liberacion de informacion
    printf("\nSe cerraron %d archivos con _fcloseall", (int) _fcloseall() );
    ll_deleteLinkedList( listaPasajeros_buffer );


    return 0;


}

