#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"




/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return max index, -1 if error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	// puntero a archivo
	FILE* pFileTxt;



	// variables tipo caracter donde recibir los datos del archivo
	char str_id[10];
	char str_name[NOMBRE_APELLIDO];
	char str_lastName[NOMBRE_APELLIDO];
	char str_flycode[CODIGO_VUELO];
	char str_price[20];
	char str_typePassenger[20];
	char str_statusFlight[20];

	int typeAux, statusAux, i;

	// pasajero auxiliar
	Passenger* passengerAux;
	//Passenger* passengerAux0;

	//size of Passenger
	static int size_Passenger= sizeof(Passenger);






	// apertura de archivo
	pFileTxt = fopen(path, "r");


	// Falso escaneo para titulo
	fscanf(pFileTxt, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );


	i=0;
	while(!feof(pFileTxt)){

		   /* Lee los datos */
		fscanf(pFileTxt, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );


		// se inicializa un puntero tipo passenger dinamicamente.
		passengerAux= (Passenger*) malloc( size_Passenger );


		// codificacion del estado de vuelo y del tipo de pasajero
		typeAux= passenger_typeEncoder(str_typePassenger);
		statusAux= passenger_statusEncoder(str_statusFlight);



		// una vez asignada la direccion de memoria y decodificados el tipo de pasajero y el estado de vuelo, se rellenan los datos
		passengerAux= Passenger_newParametros(str_id, str_name, str_lastName, str_flycode, str_price, typeAux, statusAux );



		// se agregan los datos a la lista
		ll_add(pArrayListPassenger, (Passenger*) passengerAux);


//		/*
//		 * mostrar datos
//		 */
//
//		// optener el puntero de la posicion i de la lista
//		passengerAux0= (Passenger*) ll_get(pArrayListPassenger , i);
//
//		// mostrar el contenido del puntero tipo Passenger en la posicion i de la lista
//		printOnePassenger(*passengerAux0);
//

		i++;
	   }



	fclose(pFileTxt);


    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

