
#include "parser.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int retorno= -2;


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



	// Falso escaneo para titulo
	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );

	if ( feof(pFile) )
	{
		retorno= 0;
	}

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

	// verifica si hubo error o si debe retornar un id
	if ( retorno==-2 )
	{
		retorno= atoi(str_id);
	}

    return retorno;
}
/*
 *
 *
 *
 *
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno= 0;
	int idAux;
	Passenger* passengerAux0= NULL;
	static int size_Passenger= sizeof(Passenger);
	int cant;

	// se ejecuta bucle de lectura mientras no se llegue al final del archivo
	while(!feof(pFile))
	{
		// se crea direccion de memoria para pasajero a leer
		passengerAux0= Passenger_new();

		// se guardan datos de pasajero en nueva direccion
		cant=fread(passengerAux0,size_Passenger ,1,pFile);



		// se verifica la devolucion de fread

		if(cant!=1)
		{
			if(feof(pFile))
			{
				printf("fin de lectura de archivo binario");
				break;
			}
			else
			{
				printf("No leyo el ultimo registro de archivo binario");
				retorno= -1;
				break;
			}
		}

		// se agregan los datos al linkedlist
		ll_add(pArrayListPassenger , (Passenger*) passengerAux0);

		//se guarda ultimo id leido
		if (Passenger_getId( passengerAux0, &idAux))
		{
			retorno= idAux;
		}

		//printOnePassenger(*passengerAux0);

	}

    return retorno;
}
/*
 *
 *
 *
 *
 *
 */
int parser_PassengerToText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int idMax;
	int retorno;

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




	//el bucle se repetira tantas veces como elementos tenga la lista-1 por el elemento que contiene solo el ultimo id;

	for(i=0; i<lengthOfList-1; i++)
	{
		// optener el puntero de la posicion i de la lista
		passengerAux0= (Passenger*) ll_get(pArrayListPassenger , i);




		/*
		 * getters: todos deben devolver verdadero o se sale del loop
		 */

									// id										// name										// lastname													// flycode								// price							// typePassenger 													// statusFlight
		if ( !(Passenger_getId(passengerAux0, &id ) && Passenger_getNombre(passengerAux0, name) && Passenger_getApellido(passengerAux0, lastName) && Passenger_getCodigoVuelo(passengerAux0, flycode) && Passenger_getPrecio(passengerAux0, &price) && Passenger_getTipoPasajero(passengerAux0, &typePassenger) && Passenger_getStatusFlight(passengerAux0, &statusFlight) ) )
		{
			idMax= -1;
			break;
		}





		// se decodifican statusFlight y typePassenger a sus strings equivalentes
		passenger_statusDecoder(statusFlight, str_statusFlight);
		passenger_typeDecoder(typePassenger, str_typePassenger);


		// se agrega nueva linea de informacion al archivo
		fprintf( pFile,"\n%d,%s,%s,%.2f,%s,%s,%s", id,name,lastName,price,flycode,str_typePassenger,str_statusFlight );

		idMax=id;
	}


	// se verifican retorno y se anuncia resultado
	if( idMax>0)
	{
		retorno= idMax;
		printf("\nSe guardaron %d pasajeros ", i);
	}


	return retorno;
}
/*
 *
 *
 *
 */
int parser_PassengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	// variables genericas
	int retorno, idMax;
	int i, cant, cantAux;
	static int size_Passenger= sizeof ( Passenger );

	Passenger* passengerAux0;

	//se guarda la cantidad de datos que tiene la lista que se va a guardar en el archivo
	int lengthOfList = ll_len(pArrayListPassenger);


	// el bucle se repetira tantas veces como elementos tenga la lista-1 por el elemento que contiene solo el ultimo id;
	cant=0;
	for( i=0; i<lengthOfList-1; i++ )
	{


		// optener el puntero de la posicion i de la lista
		passengerAux0= (Passenger*) ll_get(pArrayListPassenger , i);


		// se ejecuta la escritura y se guarda la cantidad de datos que fueron escritos en el archivo
		fflush(stdin);
		cantAux =fwrite ( passengerAux0 , size_Passenger , 1 , pFile );


		cant+= cantAux;
	}


	// verificacion de retorno y anuncio de resultados
	if (cant<lengthOfList)
	{
		printf("\nError al escribir el archivo");
		retorno= -1;
	}
	else if( Passenger_getId(passengerAux0, &idMax) )
	{
		retorno= idMax;
		printf("\nSe escribieron %d pasajeros", cant);
	}



	return retorno;

}

