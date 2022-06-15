#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"


/**
 * @brief shows main menu and validates it selection
 *
 * @param min min value
 * @param max max value
 * @return validated int
 */
int mainMenu(int min, int max)
{
	int opcion, flag= 0;

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


	do
	{

		if( flag )
			{
				printf("\nNo ingreso un valor valido, reintente.");
			}

		opcion= intScan("\n\tOpcion_ ");

		flag= !intVerify(opcion, min, max);




	}while ( flag );


	return opcion;
}




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

	int idMax;
	int retorno= -2;




	// apertura de archivo modo "r"
	pFileTxt= fopen(path, "r");
	if ( pFileTxt==NULL )
	{

		printf("\nError en apertura de %s", path);
		retorno= -1;
	}
	else
	{


		idMax= parser_PassengerFromText(pFileTxt, pArrayListPassenger);


		// cierre modo "r"
		if((fclose(pFileTxt))==-1) //Se cierra el archivo
		{
		printf("\nNo se pudo cerrar el archivo csv");
		retorno= -1;
		}


	}


	// verifica si hubo un error para determinar el retorno
	if( retorno==-2 )
	{
		retorno= idMax;
	}
    return retorno;
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
	//puntero a archivo
	FILE* pFileBin;

	int idMax;
	int retorno= -2;

	// apertura en modo "rb"
	if ( (pFileBin=fopen(path,"rb"))==NULL )
	{
		printf("\nNo se pudo abrir el archivo binario para mostrar datos");
		retorno= -1;

	}
	else
	{

		idMax= parser_PassengerFromBinary( pFileBin , pArrayListPassenger);


		// cierre modo "rb"
		if((fclose(pFileBin))==-1) //Se cierra el archivo
		{
		printf("\nNo se pudo cerrar el archivo dat");
		retorno= -1;
		}
		else
		{
		printf("\nEl archivo dat se cerro exitosamente");
		}



	}





	// verifica si hubo un error para determinar el retorno
	if( retorno==-2 )
	{
		retorno= idMax;
	}

    return retorno;
}


/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return last added ID
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	// variables de control de entrada y salida de datos
	int retorno, idCurrent;

	// varaibles de almacenamiento de nuevos datos
	char name[NOMBRE_APELLIDO];
	char lastName[NOMBRE_APELLIDO];
	char flycode[CODIGO_VUELO];
	float price;
	int typePassenger;
	int statusFlight;

	// se crea puntero auxiliar de pasajero
	Passenger* passengerAux;

	// estrucutras de tipo y estado de vuelo

	int lenTipos=3;
	eTipo tipos[]={ {"EconomyClass", CLASE_ECONOMICA},{"ExecutiveClass", CLASE_EJECUTIVO},{"FirstClass", CLASE_PRIMERA} };
	eTipo tipoAux;

			/*
			1- BA2491A - Aterrizado
			2- IB0800A - Aterrizado
			3- TU6789B  - Aterrizado

			4- MM0987B  - En Horario
			5- FR5678G  - En Horario

			6- GU2345F  - En Vuelo

			7- HY4567D  - Demorado
			8- BR3456J -  Demorado
			*/
	int lenVuelos= 8;
	eVuelo vuelos[]= { {1 ,"BA2491A",STATUS_ATERRIZADO }, {2 ,"IB0800A",STATUS_ATERRIZADO }, {3 ,"TU6789B",STATUS_ATERRIZADO }, {4 ,"MM0987B",STATUS_EN_HORARIO }, {5 ,"FR5678G",STATUS_EN_HORARIO }, {6 ,"GU2345F",STATUS_EN_VUELO }, {7 ,"HY4567D",STATUS_DEMORADO }, {8 ,"BR3456J",STATUS_DEMORADO } };
	eVuelo vueloAux;


	// se calcula el tamaño de la linkedlist actual
	int pArrayListPassenger_len =ll_len(pArrayListPassenger);

	// se accede a la ultimo puntero almacenado en lista, previamente preseteada con informacion del ultimo id que ya se uso y se almacena en auxiliar
	passengerAux= ll_get(pArrayListPassenger, pArrayListPassenger_len-1 );

	// si se puede leer el id almacenado, inicia proceso de pedido de datos
	if( Passenger_getId(passengerAux, &idCurrent) )
	{

			// name
			stringScan(name, NOMBRE_APELLIDO, "\nIngrese el nombre del pasajero_ ");
			stringNameFormat( name, NOMBRE_APELLIDO );

			// last name
			stringScan(lastName, NOMBRE_APELLIDO, "\nIngrese el apellido del pasajero_ ");
			stringNameFormat( lastName, NOMBRE_APELLIDO );

			//price
			price= floatScan("\nIngrese monto a cobrar al cliente_ ");


			//type
			printf("\t**tipos de pasajeros disponibles**");
			typePassenger= Tipo_elegir( tipos, lenTipos );

			// select flight

				// flycode
			vueloAux= elijeVuelos(flycode, vuelos, lenVuelos);

			strcpy( flycode, vueloAux.code );


				// statusFlight
			statusFlight= vueloAux.estado;



			// se guardan datos solicitados en el puntero auxilia de Passenger, con la id preseteada+1, debe devolver dicha id+1
			idCurrent = Passenger_NewAdition(passengerAux, idCurrent +1, name, lastName,price, typePassenger,  flycode);
			if ( idCurrent>0 )
			{

				//anouncement of new ticket
				printf( "\nSe cargo el usuario:" );
				printOnePassenger( passengerAux );

				// una vez guardado el usuario, se agrega informacion del proximo id a la linkedlist con otro nuevo usuario
				passengerAux= Passenger_new();
				Passenger_setId(passengerAux, idCurrent);
				ll_add(pArrayListPassenger, passengerAux);

				retorno= idCurrent;
			}
			else
			{
				printf( "\nno fue posible el alta del usuario" );
				retorno= 0;
			}

	}

    return retorno;
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
	int retorno;
	int idMax= 0;
	int index;
	FILE* pArch;

	//LinkedList* listAux;

	Passenger* passengerAux0= NULL;



	//primero se verifican posibles punteros nulos
	if( path==NULL || pArrayListPassenger==NULL )
	{
		retorno= -1;
	}
	else
	{

		// se abre archivo en modo "a"
		pArch= fopen( path, "a" );
		if( pArch==NULL )
		{
			printf("\nNo se pudo abrir archivo %s para editar", path);

		}
		else
		{
			//se abrio archivo en "a", se procede a escribir
			//se escribe el relleno de datos
			idMax= parser_PassengerToText(pArch, pArrayListPassenger);


			// cierre para modo "a"
			if( (fclose(pArch))==-1)
			{
				printf("\nNo se pudo cerrar el archivo %s", path);
				retorno= -1;
			}


		}



//
//		//primero se verifica que existe el archivo intentando abrirlo en modo "r"
//
//		pArch=fopen(path, "r");
//		if( pArch==NULL )
//		{
//			printf("\nNo se pudo abrir archivo %s. se creara uno nuevo", path);
//			// ahora se intenta abrir el archivo en modo "w"
//			pArch= fopen( path, "w" );
//			if( pArch==NULL )
//			{
//				printf( "\nNo se pudo crear archivo %s.", path);
//				retorno= -1;
//
//			}
//			else
//			{
//				//se abrio archivo para en "w", se procede a escribir
//
//				//primero el titulo ya que esta en modo truncar
//				fprintf( pArch,"id,name,lastname,price,flycode,typePassenger,statusFlight\n" );
//
//				//se escribe el relleno de datos
//				idMax= parser_PassengerToText(pArch, pArrayListPassenger);
//
//
//			}
//
//
//		}
//		else
//		{
//			// se abrio archivo en modo "r", existe y ahora hay que cerarlo y abrirlo en modo "a"
//			if (FILE_close(pArch))
//			{
//
//				// se abre archivo en modo "a"
//				pArch= fopen( path, "a" );
//				if( pArch==NULL )
//				{
//					printf("\nNo se pudo abrir archivo %s para editar", path);
//
//				}
//				else
//				{
//					//se abrio archivo en "a", se procede a escribir
//					//se escribe el relleno de datos
//					idMax= parser_PassengerToText(pArch, pArrayListPassenger);
//
//
//				}
//
//			}
//			else
//			{
//				printf("\nNo se pudo cerrar archivo %s en modo r", path);
//				retorno= -1;
//			}
//
//
//		}




	}

	/*
	 * mostrar datos
	 */

	// optener el puntero de la posicion i de la lista
	//passengerAux0= (Passenger*) ll_get(pArrayListPassenger , i);

	// mostrar el contenido del puntero tipo Passenger en la posicion i de la lista
	//printOnePassenger(*passengerAux0);




	//evalua si retorno debe informar error o el numero de ID mas grande almacenado
	if (idMax>0)
	{

		retorno= idMax;

	}

    return retorno;

}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int max saved id
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{

	int retorno= 0;

	//puntero a archivo
	FILE* pFileBin;
	int idMax=0;

	// apertura modo "ab"
	pFileBin= fopen( path, "ab" );
	if ( pFileBin==NULL )
	{
		printf("\nNo se puede modificar %s", path);
		retorno= -1;

	}
	else
	{

		// se escriben datos en archivo
		idMax= parser_PassengerToBinary(pFileBin , pArrayListPassenger);


		// cierre para modo "ab"
		if( (fclose(pFileBin))==-1)
		{
			printf("\nNo se pudo cerrar el archivo %s", path);
			retorno= -1;
		}


	}



	// se verifican resultados antes de hacer retorno
	if (idMax>0)
	{
		retorno= idMax;
	}

	return retorno;
}



