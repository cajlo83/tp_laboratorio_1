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
		Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
		no puede tener más de 2000 pasajeros.
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




		El sistema deberá tener el siguiente menú de opciones:
		1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
		número de Id. El resto de los campos se le pedirá al usuario.

		2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
		o Precio o Tipo de pasajero o Código de vuelo

		3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

		4. INFORMAR:
			1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.		+
			2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio	+
			promedio.
			3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’				+

		1-NOTA:
		Se deberá realizar el menú de opciones y las validaciones a través de funciones.
		Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
		carga de algún pasajero.

		2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
		Para la realización de este programa, se utilizará una biblioteca llamada “ArrayPassenger” que
		facilitará el manejo de la lista de pasajeros y su modificación.

	Para la realización de este programa, se utilizará una biblioteca llamada “ArrayPassenger” que
	facilitará el manejo de la lista de pasajeros y su modificación. En la sección siguiente se
	detallan las funciones que esta biblioteca debe tener.
	*/

	/*
	3 Cómo realizar y entregar el trabajo práctico
		El trabajo práctico deberá ser entregado en el repositorio de GIT correspondiente al TP2 de la
		materia.
		El mismo consistirá en el proyecto de Eclipse con el programa funcionando y comentado,
		respetando las reglas de estilo de la cátedra. La compilación no deberá arrojar mensajes de
		error ni de warnings.
		El proyecto deberá contar con más de una biblioteca. Se tiene que encontrar la biblioteca
		pedida en el trabajo práctico y una personal con funciones correspondientes al pedido de dato.
		Se deberá hacer uso de dichas funciones para resolver la lógica del programa.
		No debe haber desarrollo de funciones en el main, solo el uso del menú y arranque del
		programa.

	3.1 Objetivo
		El objetivo del siguiente trabajo es que el alumno sea capaz de demostrar que puede integrar
		los conocimientos aprendidos hasta la clase 12. Los conocimientos necesarios para la
		realización del TP son los siguientes:

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
