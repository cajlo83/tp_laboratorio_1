#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"

/**
 * @brief set's initial data for files and future id's
 *
 * @param pathTxt txt path file
 * @param pathBin binary path file
 * @return max id, -1 if error
 */
int initConfig(char* pathTxt, char* pathBin)
{
	int retorno;
	int cant, i;
	int idBin= -1;
	int idTxt= -1;

	FILE* pTxt= NULL;
	FILE* pBin= NULL;

	Passenger* 	passengerAux0= Passenger_new();

	static int size_Passenger= sizeof(Passenger);

	// variables tipo caracter donde recibir los datos del archivo
	char str_id[10];
	char str_name[NOMBRE_APELLIDO];
	char str_lastName[NOMBRE_APELLIDO];
	char str_flycode[CODIGO_VUELO];
	char str_price[20];
	char str_typePassenger[20];
	char str_statusFlight[20];



	/*
	 * verificaciones de archivo binario
	 */

	// apertura del archivo con "rb"
	pTxt =fopen(pathTxt, "rb");
	if( pBin==NULL )
	{
		// si el archivo no existe debe crearse con "wb"
		printf("\nNo existe archivo bin");
		pTxt=fopen(pathTxt, "wb");

		if( pTxt==NULL )
		{
			printf( "\nError en creacion de archivo binario, reintente luego" );
			idBin=-1;
		}
		else
		{
			// cierre de archivo en "wb"
			if(FILE_close( pTxt ))
			{
				printf( "\nError en cierre de archivo binario" );
			}

			idBin= 0;
		}

	}
	else
	{
		// se lee ultima estructura almacenada en el archivo
		fseek ( pBin , 0 , SEEK_END );
		fseek ( pBin , (long) (-1)*sizeof (Passenger) , SEEK_CUR );


		// se guardan datos de pasajero en nueva direccion
		cant=fread(passengerAux0,size_Passenger ,1,pBin);

		// se verifica posibilidad de guardar el dato
		if(cant==1)
		{
			Passenger_getId(passengerAux0, &idBin);
		}
		else
		{
			printf("\nProblemas de lectura con archivo binario");
			idBin= -1;
		}


		// cierre de archivo en "rb"
		if(FILE_close( pTxt ))
		{
			printf( "\nError en cierre de archivo binario" );
		}

	}


	/*
	 * verificaciones de archivo csv
	 */

	// apertura del archivo con "r"
	pTxt =fopen(pathBin, "r");
	if( pTxt==NULL )
	{
		// si el archivo no existe debe crearse con "w"
		printf("\nNo existe archivo bin");
		pTxt=fopen(pathTxt, "w");

		if( pTxt==NULL )
		{
			printf( "\nError en creacion de archivo csv, reintente luego" );

			idTxt= -1;
		}
		else
		{
			// se creo el archivo y se agregan los titulos
			fprintf(pTxt, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");

			// cierre de archivo en "w"
			if(FILE_close( pTxt  ))
			{
				printf( "\nError en cierre de archivo csv" );
			}

			idTxt= 0;
		}

	}
	else
	{

		//lectura de archivo

		// Falso escaneo para titulo
		fscanf(pTxt, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );


		i=0;
		while(!feof(pTxt ))
		{

			   /* Lee los datos */

			cant=fscanf(pTxt, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );
			if ( 7!=cant )
			{

				printf("\nError leyendo datos desde csv. iteracion: %d", i);

				// en caso de error se libera str_id
				pFree(str_id);
				break;
			}

		}

		// se guarda el ID del csv
		if( str_id!=NULL )
		{
			idTxt= atoi(str_id);
		}
		else
		{
			idTxt= -1;
		}



		// cierre de archivo en "r"
		if(FILE_close( pTxt ))
		{
			printf( "\nError en cierre de archivo binario" );
		}

	}


	free(passengerAux0);

	return retorno;
}

/**
 * @brief shows main meno and validates it selection
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

//
//	// variables tipo caracter donde recibir los datos del archivo
//	char str_id[10];
//	char str_name[NOMBRE_APELLIDO];
//	char str_lastName[NOMBRE_APELLIDO];
//	char str_flycode[CODIGO_VUELO];
//	char str_price[20];
//	char str_typePassenger[20];
//	char str_statusFlight[20];

//
//	// pasajero auxiliar
//	Passenger* passengerAux;
	//Passenger* passengerAux0;



	// variables genericas
//	int typeAux, statusAux, i, cant;
	int retorno=0;



	// apertura de archivo modo "r"
	if ( (pFileTxt = fopen(path, "r"))==NULL )
	{

		printf("\nError en apertura de %s", path);
		retorno= -1;
	}
	else
	{

		if ( !parser_PassengerFromText(pFileTxt, pArrayListPassenger) )
		{
			retorno=-1;
		}

//		// Falso escaneo para titulo
//		fscanf(pFileTxt, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );
//
//
//		i=0;
//		while(!feof(pFileTxt))
//		{
//
//			   /* Lee los datos */
//			cant=fscanf(pFileTxt, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );
//			if ( 7==cant )
//			{
//
//
//
//				// codificacion del estado de vuelo y del tipo de pasajero
//				typeAux= passenger_typeEncoder(str_typePassenger);
//				statusAux= passenger_statusEncoder(str_statusFlight);
//
//
//
//				// una vez codificados el tipo de pasajero y el estado de vuelo, se rellenan los datos
//				passengerAux= Passenger_newParametros( str_id, str_name, str_lastName, str_flycode, str_price, typeAux, statusAux );
//
//
//
//				// se verifica el resultado y de ser valido se agrega a la lista la direccion actual de passengerAux
//
//				if( passengerAux==NULL )
//				{
//					printf("\nError guardando datos desde csv en auxiliar. iteracion: %d", i);
//					retorno= -1;
//					break;
//				}
//				else
//				{
//					ll_add(pArrayListPassenger, (Passenger*) passengerAux);
//				}
//
//
//		//		/*
//		//		 * mostrar datos
//		//		 */
//		//
//		//		// optener el puntero de la posicion i de la lista
//		//		passengerAux0= (Passenger*) ll_get(pArrayListPassenger , i);
//		//
//		//		// mostrar el contenido del puntero tipo Passenger en la posicion i de la lista
//		//		printOnePassenger(*passengerAux0);
//		//
//
//				i++;
//
//			}
//			else
//			{
//				printf("\nError leyendo datos desde csv en auxiliar. iteracion: %d", i);
//				retorno= -1;
//				break;
//			}
//
//		}



		// cierre modo "r"
		if( (fclose(pFileTxt))==-1)
		{
			printf("\nNo se pudo cerrar el archivo %s", path);
			retorno=-1;
		}
		else
		{
			printf("\nSe cerro exitosamente el archivo %s", path);
		}

	}


	// verifica si hubo un error para determinar el retorno
	if( retorno!=-1 )
	{
		retorno= ll_len(pArrayListPassenger)-1;
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

	// tamaño de estructura
	static int size_Passenger= sizeof ( Passenger );

//	int lengthOfList, i;

	int retorno= 0;

	int cant=0;

	Passenger* passengerAux0;


	// apertura en modo "rb"
	if ( (pFileBin=fopen(path,"rb"))==NULL )
	{
		printf("\nNo se pudo abrir el archivo binario para mostrar datos");
		retorno=0;

	}
	else
	{

		// si el archivo no es nulo, inicia bucle de lectura
		while(!feof(pFileBin))
		{
			// se crea direccion de memoria para pasajero a leer
			passengerAux0= Passenger_new();

			// se guardan datos de pasajero en nueva direccion
			cant=fread(passengerAux0,size_Passenger ,1,pFileBin);

			// se verifica la devolucion de fread
			if(cant!=1)
			{
				if(feof(pFileBin))
				{
					printf("fin de archivo %s", path);
					break;
				}
				else
				{
					printf("No leyo el ultimo registro de %s", path);
					retorno= -1;
					break;
				}
			}

			// se agregan los datos al linkedlist
			ll_add(pArrayListPassenger , (Passenger*) passengerAux0);

			//printOnePassenger(*passengerAux0);

		}


		// cierre modo "rb"
		if( (fclose(pFileBin))==-1)
		{
			printf("\nNo se pudo cerrar el archivo %s", path);
			retorno= -1;
		}
		else
		{
			printf("\nSe cerro exitosamente el archivo %s", path);
		}

	}





	// verifica si hubo un error para determinar el retorno
	if( retorno!=-1 )
	{
		retorno= ll_len(pArrayListPassenger)-1;
	}

    return retorno;
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
	int retorno= 0;
	int index;
	FILE* pArch;

	LinkedList* listAux;

	Passenger* passengerAux0= NULL;



	//primero se verifican posibles punteros nulos
	if( path==NULL || pArrayListPassenger==NULL )
	{
		retorno= -1;
	}
	else
	{

		//primero se verifica que existe el archivo intentando abrirlo en modo "r"

		pArch=fopen(path, "r");
		if( pArch==NULL )
		{
			printf("\nNo se pudo abrir archivo %s. se creara uno nuevo", path);
			// ahora se intenta abrir el archivo en modo "w"
			pArch= fopen( path, "w" );
			if( pArch==NULL )
			{
				printf( "\nNo se pudo crear archivo %s.", path);
				retorno= -1;

			}
			else
			{
				//se abrio archivo para en "w", se procede a escribir

				//primero el titulo ya que esta en modo truncar
				fprintf( pArch,"id,name,lastname,price,flycode,typePassenger,statusFlight\n" );

				//se escribe el relleno de datos
				parser_PassengerToText(pArch, pArrayListPassenger);


			}


		}
		else
		{
			// se abrio archivo en modo "r", existe y ahora hay que cerarlo y abrirlo en modo "a"
			if (FILE_close(pArch))
			{
				pArch= fopen( path, "a" );
				if( pArch==NULL )
				{
					printf("\nNo se pudo abrir archivo %s para editar", path);

				}
				else
				{
					//se abrio archivo en "a", se procede a escribir
					//se escribe el relleno de datos
					parser_PassengerToText(pArch, pArrayListPassenger);


				}

			}
			else
			{
				printf("\nNo se pudo cerrar archivo %s en modo r", path);
				retorno= -1;
			}


		}




	}

	/*
	 * mostrar datos
	 */

	// optener el puntero de la posicion i de la lista
	//passengerAux0= (Passenger*) ll_get(pArrayListPassenger , i);

	// mostrar el contenido del puntero tipo Passenger en la posicion i de la lista
	//printOnePassenger(*passengerAux0);




	//evalua si retorno debe informar error o el numero de ID mas grande almacenado
	if (retorno!=-1)
	{
		index= ll_len(pArrayListPassenger) -1;
		passengerAux0= ll_get(pArrayListPassenger, index);

		if( !Passenger_getId(passengerAux0, &retorno) )
		{
		retorno= -1;
		}

	}

    return retorno;

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

	int retorno= 0;

		//puntero a archivo
		FILE* pFileBin;

		// tamaño de estructura
//		static int size_Passenger= sizeof ( Passenger );

	//	int lengthOfList, cant, cantAux, i;

//		Passenger* passengerAux0= Passenger_new();



		// se intenta abrir el archivo binario como lectura
		if ( (pFileBin= fopen( path, "rb" ))==NULL )
		{

			//en caso de no poder abrir "rb" se anuncia y se intenta crear el archivo
			printf("\nerror en apertura de %s", path);

			if ( (pFileBin= fopen( path, "wb" ))==NULL )
			{
				// en caso de no poder crear el archivo, se anuncia
				printf("\nerror en creacion de %s", path);
				retorno= -1;
			}
			else
			{
				// en caso de crearse el archivo, se anuncia
				printf("\nRecien se creo %s", path);



				parser_PassengerToBinary(pFileBin , pArrayListPassenger);


				//fclose( pFileBin );	// cierre para modo "wb"
				if( (fclose(pFileBin))==-1)
				{
					printf("\nNo se pudo cerrar el archivo %s", path);
					retorno=0;
				}
				else
				{
					printf("\nSe cerro exitosamente el archivo %s", path);
				}
			}

		}
		else
		{

			/*
			 * en caso de poder abrir el archivo en modo "rb", se cierra y se vuelve a abrir en modo "ab"
			 */

			// cierre modo "rb"
			if( (fclose(pFileBin))==-1)
			{
				printf("\nNo se pudo cerrar el archivo %s", path);
				retorno= -1;
			}
			else
			{
				printf("\nSe cerro exitosamente el archivo %s", path);

				// apertura modo "ab"

				if ( (pFileBin= fopen( path, "ab" ))==NULL )
				{
					printf("\nNo se puede modificar %s", path);
					retorno= -1;

				}
				else
				{

					// se escriben datos en archivo
					parser_PassengerToBinary(pFileBin , pArrayListPassenger);

					// cierre para modo "ab"
					if( (fclose(pFileBin))==-1)
					{
						printf("\nNo se pudo cerrar el archivo %s", path);
						retorno= -1;
					}
					else
					{
						printf("\nSe cerro exitosamente el archivo %s", path);
					}

				}

			}


		}

		return retorno;
}



