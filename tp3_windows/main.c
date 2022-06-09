/*
 * autor: Carlo Morici
 * tittle: tp3
 * date: 08/06/2022
 *
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





int main()
{
	setbuf( stdout, NULL );



	// variables genericas
	int option;
//	int typeAux, statusAux;

	// declaracion de la lista
	LinkedList* listaPasajeros_txt = NULL;
	LinkedList* listaPasajeros_bin = NULL;
	//Passenger** aux_PassengerPointPoint;



	/*
	 * INICIALIZO LA LINKED LIST
	 */

	listaPasajeros_txt = ll_newLinkedList();



    do{






    	// despliegue de opciones del menu
    	printf("\n\n\t ***** MENU PRINCIPAL ***** ");
    	printf( "\n1\t Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)." );
    	printf( "\n2\t Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)." );
    	printf( "\n3\t Alta de pasajero." );
    	printf( "\n4\t Modificar datos de pasajeros." );
    	printf( "\n5\t Baja de pasajero." );
    	printf( "\n6\t Listar pasajeros." );
    	printf( "\n7\t Ordenar pasajeros." );
    	printf( "\n8\t Guardar los datos de los pasajeros en el archivo data.csv (modo texto)." );
    	printf( "\n9\t Guardar los datos de los pasajeros en el archivo data.csv (modo binario)." );

    	printf( "\n\n10\t *SALIR* " );

    				//solicitud a usuario
    	option= intScan("\nOPCION_ ");


        switch(option)
        {
            case CARGA_TXT :

            	 controller_loadFromText( "data.csv" ,  listaPasajeros_txt);

                break;

            case GUARDA_BIN :

            	break;

            	break;
        }
    }while(option != 10);
    return 0;


}
/*
Passenger* Passenger_new()
{
	Passenger * puntero;


	 puntero =  (Passenger*)malloc(sizeof(Passenger));

	 if(puntero !=NULL)
	 {
		strcpy( puntero->apellido  ," ");
		strcpy( puntero->nombre ," ");
		puntero->dni = 0;


	 }




	return puntero;

}
*/
