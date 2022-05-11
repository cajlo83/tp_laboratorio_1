/*
 Name        : TP_2.c
 Author      : Carlo Morici
 Version     :
 Copyright   : Your copyright notice
 Description :
*/

	/*
	{
	1 Enunciado
		Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
		no puede tener m�s de 2000 pasajeros.
		Datos:

				Passenger:
				int id;
				char name[NAME_LASTNAME];
				char lastName[NAME_LASTNAME];
				float price;
				char flyCode[10];
				int TypePassenger;
				int statusFlight;
				int isEmpty;




		El sistema deber� tener el siguiente men� de opciones:
		1. ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el
		n�mero de Id. El resto de los campos se le pedir� al usuario.

		2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
		o Precio o Tipo de pasajero o C�digo de vuelo

		3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.

		4. INFORMAR:
			1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.		+
			2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio	+
			promedio.
			3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�				+

		1-NOTA:
		Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
		Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
		carga de alg�n pasajero.

		2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
		Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �ArrayPassenger� que
		facilitar� el manejo de la lista de pasajeros y su modificaci�n.

	Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �ArrayPassenger� que
	facilitar� el manejo de la lista de pasajeros y su modificaci�n. En la secci�n siguiente se
	detallan las funciones que esta biblioteca debe tener.
	*/

	/*
	3 C�mo realizar y entregar el trabajo pr�ctico
		El trabajo pr�ctico deber� ser entregado en el repositorio de GIT correspondiente al TP2 de la
		materia.
		El mismo consistir� en el proyecto de Eclipse con el programa funcionando y comentado,
		respetando las reglas de estilo de la c�tedra. La compilaci�n no deber� arrojar mensajes de
		error ni de warnings.
		El proyecto deber� contar con m�s de una biblioteca. Se tiene que encontrar la biblioteca
		pedida en el trabajo pr�ctico y una personal con funciones correspondientes al pedido de dato.
		Se deber� hacer uso de dichas funciones para resolver la l�gica del programa.
		No debe haber desarrollo de funciones en el main, solo el uso del men� y arranque del
		programa.

	3.1 Objetivo
		El objetivo del siguiente trabajo es que el alumno sea capaz de demostrar que puede integrar
		los conocimientos aprendidos hasta la clase 12. Los conocimientos necesarios para la
		realizaci�n del TP son los siguientes:

		-Manejo de arrays.
		-Manejo de pasaje por referencia.
		-Manejo de estructuras.
	}
	 ============================================================================
	 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "personalio.h"
#include "ArrayPassenger.h"

#define PASAJEROS 2000
#define TIPOS 2



int main(void) {
	setbuf(stdout, NULL);


	Passenger pasajeros[PASAJEROS];
	eCommon tipos[]={ {0,"turista"}, {1,"VIP"} };

	int idPasajero=0;
	int contadorPasajeros=0;

	int menu;

	// invocacion de int initPassengers
	if ( initPassengers( pasajeros, PASAJEROS ) )
	{
		printf( "\nERROR DE INICIALIZACION. REINTENTE LUEGO." );
	}
	else
	{

		do
		{



			//printf("\n prueba: %d", );


			//despliegue de opciones del menu
			printf("\n\n\t ***** MENU PRINCIPAL ***** ");
			printf( "\n1\t ALTA" );
			printf( "\n2\t MODIFICAR" );
			printf( "\n3\t BAJA" );
			printf( "\n4\t INFORMAR" );
			printf( "\n\n5\t CARGA FORZADA x1" );
			printf( "\n6\t *SALIR* " );

			//solicitud a usuario
			menu= intScan("\nOPCION_ ");


			//opciones
			switch ( menu )
			{

			// ALTA
			case 1 :
				if ( alta( pasajeros, PASAJEROS, idPasajero,  tipos, TIPOS ) )
				{
					idPasajero++;
					contadorPasajeros++;
				}

				break;


			// BAJA
			case 2 :
				if ( contadorPasajeros>0 )
				{
					modificar( pasajeros, PASAJEROS,  tipos, TIPOS );
				}
				else
				{
					printf( "\nNo hay pasajeros para modificar" );
				}
				break;


			// MODIFICAR
			case 3 :
				if( contadorPasajeros>0 )
				{
					if ( baja( pasajeros, PASAJEROS) )
					{
						contadorPasajeros--;
					}
				}
				else
				{
					printf( "\nNo hay pasajeros para modificar" );
				}
				break;


			// INFORMAR
			case 4 :
				if( contadorPasajeros>0 )
				{
					informar( pasajeros, PASAJEROS);
				}
				else
				{
					printf( "\nNo hay pasajeros para informar" );
				}
				break;


			// CARGA FORZADA
			case 5 :

				break;












			// SALIDA DEL PROGRAMA
			case 6 :
				printf("\n\t ***** VUELVA PRONTO ***** ");
				break;

			default:
				printf("No se reicibio un valor esperado, reintente");
			}

		}while( menu!=6 );

	}

	return EXIT_SUCCESS;
}
