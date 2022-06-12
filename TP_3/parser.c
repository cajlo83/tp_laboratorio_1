
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int retorno= 0;


	// variables tipo caracter donde recibir los datos del archivo
	char str_id[10];
	char str_name[NOMBRE_APELLIDO];
	char str_lastName[NOMBRE_APELLIDO];
	char str_flycode[CODIGO_VUELO];
	char str_price[20];
	char str_typePassenger[20];
	char str_statusFlight[20];


	// pasajero auxiliar
	Passenger* passengerAux;

	int typeAux, statusAux, i, cant;

	if ( !parser_PassengerFromText(pFile, pArrayListPassenger) )
	{
		retorno=-1;
	}

	// Falso escaneo para titulo
	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );


	i=0;
	while(!feof(pFile))
	{

		   /* Lee los datos */
		cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );
		if ( 7==cant )
		{



			// codificacion del estado de vuelo y del tipo de pasajero
			typeAux= passenger_typeEncoder(str_typePassenger);
			statusAux= passenger_statusEncoder(str_statusFlight);



			// una vez codificados el tipo de pasajero y el estado de vuelo, se rellenan los datos
			passengerAux= Passenger_newParametros( str_id, str_name, str_lastName, str_flycode, str_price, typeAux, statusAux );



			// se verifica el resultado y de ser valido se agrega a la lista la direccion actual de passengerAux

			if( passengerAux==NULL )
			{
				printf("\nError guardando datos desde csv en auxiliar. iteracion: %d", i);
				retorno= -1;
				break;
			}
			else
			{
				ll_add(pArrayListPassenger, (Passenger*) passengerAux);
			}


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
		else
		{
			printf("\nError leyendo datos desde csv en auxiliar. iteracion: %d", i);
			retorno= -1;
			break;
		}

	}


    return retorno;
}





/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}


int parser_PassengerToText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno= 1;

	// variables para los getters
	int id;
	char name[NOMBRE_APELLIDO];
	char lastName[NOMBRE_APELLIDO];
	char flycode[CODIGO_VUELO];
	float price;

	int typePassenger;
	char str_typePassenger[20];

	int statusFlight; // antes llamado flyState
	char str_statusFlight[20];




	int i;
	int lengthOfList;

	Passenger* passengerAux0= NULL;


	//se guarda la cantidad de datos que tiene la lista que se va a guardar en el archivo
	lengthOfList= ll_len(pArrayListPassenger);




	//el bucle se repetira tantas veces como elementos tenga la lista;

	for(i=0; i<lengthOfList; i++)
	{
		// optener el puntero de la posicion i de la lista
		passengerAux0= (Passenger*) ll_get(pArrayListPassenger , i);




		/*
		 * getters: todos deben devolver verdadero o se sale del loop
		 */

									// id										// name										// lastname													// flycode								// price							// typePassenger 													// statusFlight
		if ( !(Passenger_getId(passengerAux0, &id ) && Passenger_getNombre(passengerAux0, name) && Passenger_getApellido(passengerAux0, lastName) && Passenger_getCodigoVuelo(passengerAux0, flycode) && Passenger_getPrecio(passengerAux0, &price) && Passenger_getTipoPasajero(passengerAux0, &typePassenger) && Passenger_getStatusFlight(passengerAux0, &statusFlight) ) )
		{
			retorno= 0;
			break;
		}





		// se decodifican statusFlight y typePassenger a sus strings equivalentes
		passenger_statusDecoder(statusFlight, str_statusFlight);
		passenger_typeDecoder(typePassenger, str_typePassenger);


		// se agrega la informacion al archivo
		fprintf( pFile,"%d,%s,%s,%.2f,%s,%s,%s\n", id,name,lastName,price,flycode,str_typePassenger,str_statusFlight );
	}




	return retorno;
}

int parser_PassengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	// variables genericas
	int i, cant, cantAux;
	static int size_Passenger= sizeof ( Passenger );

	Passenger* passengerAux0;

	//se guarda la cantidad de datos que tiene la lista que se va a guardar en el archivo
	int lengthOfList = ll_len(pArrayListPassenger);


	// se controla que se repita tanta cantidad de escrituras como tamaño de la lista
	cant=0;
	for( i=0; i<lengthOfList; i++ )
	{


		// optener el puntero de la posicion i de la lista
		passengerAux0= (Passenger*) ll_get(pArrayListPassenger , i);


		// se ejecuta la escritura y se guarda la cantidad de datos que fueron escritos en el archivo
		fflush(stdin);
		cantAux =fwrite ( passengerAux0 , size_Passenger , 1 , pFile );


		cant+= cantAux;
	}


	// anuncio de resultados
	if (cant<lengthOfList)
	{
		printf("\nError al escribir el archivo");
	}
	else
	{
		printf("\nSe escribieron %d pasajeros", cant);
	}





	return 1;

}

