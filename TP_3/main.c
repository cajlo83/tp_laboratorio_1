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

	int returned;
//	FILE* fileBin;


	// variables genericas
	int option;


	// declaracion e inicializacion de las listas
	LinkedList* listaPasajeros_txt = ll_newLinkedList();;
	LinkedList* listaPasajeros_bin = ll_newLinkedList();;
	//Passenger** aux_PassengerPointPoint;




    do{






    	// despliegue de opciones del menu y validacion de seleccion
    	option= mainMenu(CARGA_TXT, EXIT_MAIN);


        switch(option)
        {
            case CARGA_TXT :
            	returned= controller_loadFromText( "data.csv",  listaPasajeros_txt);
            	printf("\n indice maximo: %d", returned);
                break;




            case CARGA_BIN:

           	 returned= controller_loadFromBinary( "data.dat",  listaPasajeros_txt);
           	 printf("\n indice maximo: %d", returned);
           	 break;



            case GUARDA_TXT :

            	returned= controller_saveAsText( "data2222.csv", listaPasajeros_txt);
            	printf("\nMaxima id guardada: %d", returned);

            	break;



            case GUARDA_BIN :

            	returned= controller_saveAsBinary( "data.dat", listaPasajeros_txt);


            	break;
        }
    }while(option != 10);

    if((int) _fcloseall())
    {
    	printf("\nError en cierre de archivos");
    }

    ll_deleteLinkedList( listaPasajeros_bin );
    ll_deleteLinkedList( listaPasajeros_txt );


    return 0;


}

