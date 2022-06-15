/*
 * FilesInit.c
 *
 *  Created on: 15 jun 2022
 *      Author: Cajlo
 */
#include "setups.h"

int initCsvFile(char* path)
{
	// variables genericas

	int cant, i;
	int idTxt;

	// declaracion e inicializacion de punteros
	FILE* pArch= NULL;


	// variables tipo caracter donde recibir los datos del archivo
	char str_id[10];
	char str_name[NOMBRE_APELLIDO];
	char str_lastName[NOMBRE_APELLIDO];
	char str_flycode[CODIGO_VUELO];
	char str_price[20];
	char str_typePassenger[20];
	char str_statusFlight[20];


	/*
	 * verificaciones de archivo csv
	 */

	// apertura del archivo con "r"
	pArch =fopen(path, "r");
	if( pArch==NULL )
	{
		// si el archivo no existe debe anunciarse y crearse con "w"
		printf("\nNo existe archivo csv");
		pArch=fopen(path, "w");

		if( pArch==NULL )
		{
			printf( "\nError en creacion de archivo csv, reintente luego" );

			idTxt= -1;
		}
		else
		{
			// se creo el archivo y se agregan los titulos
			fprintf(pArch, "id,name,lastname,price,flycode,typePassenger,statusFlight");
			printf("\nSe creo archivo csv");

			// cierre de archivo en "w"
			if((fclose(pArch))==-1)
			{
			printf("\nNo se pudo cerrar el archivo csv");
			}


			idTxt= 0;
		}

	}
	else
	{

		//lectura de archivo, no importan titulos
		i=0;
		while(!feof(pArch ))
		{

			   /* Lee los datos */

			cant=fscanf(pArch, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", str_id, str_name, str_lastName,str_price, str_flycode, str_typePassenger,str_statusFlight );
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
		if((fclose(pArch))==-1)
		{
		printf("\nNo se pudo cerrar el archivo csv");
		}

	}


	return idTxt;
}


int initBinFile(char* path)
{

	FILE* pArch;
	int idBin, cant;
	Passenger* passengerAux0= Passenger_new();
	static int sizeOfPassenger= sizeof(Passenger);

	/*
	 * verificaciones de archivo binario
	 */


	// apertura del archivo con "rb"
	pArch =fopen(path, "rb");
	if( pArch==NULL )
	{

		// si el archivo no existe se anuncia y debe crearse con "wb"
		printf("\nNo existe archivo bin");
		pArch=fopen(path, "wb");

		if( pArch==NULL )
		{
			printf( "\nError en creacion de archivo binario, reintente luego" );
			idBin= -1;
		}
		else
		{
			//
			printf("\nSe creo archivo binario");

			// cierre de archivo en "wb"
			if((fclose(pArch))==-1)
			{
			printf("\nNo se pudo cerrar el archivo binario");
			}
			else



			idBin= 0;
		}

	}
	else
	{

		// se busca una posicion antes de ultima estructura guardada
		fseek ( pArch , 0L , SEEK_END );
		fseek ( pArch , (long) (-1)*sizeOfPassenger , SEEK_CUR );


		// se guardan datos de pasajero en nueva direccion
		cant=fread(passengerAux0,sizeOfPassenger, 1,pArch);

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

		if((fclose(pArch))==-1)
		{
		printf("\nNo se pudo cerrar el archivo binario");
		}





	}

	// liberacion de puntero auxiliar
	pFree(passengerAux0);


	return idBin;
}


Config configFile(char* path, char* pathCsv, char* pathBin)
{


	FILE* pArch= NULL;
	Config config;
	static int sizeOfConfig= sizeof(Config);

	int cant;

	/*
	 * verificaciones de archivo config
	 */

	// apertura del archivo con "rb"
	pArch =fopen(path, "rb");
	if( pArch==NULL )
	{

		// si el archivo no existe se anuncia y debe crearse con "wb"
		printf("\nNo existe archivo config");
		pArch=fopen(path, "wb");
		if( pArch==NULL )
		{
			printf( "\nError en creacion de archivo config, reintente luego" );
			config.idBin= -1;
			config.idTxt= -1;
		}
		else
		{
			// si no existe archivo config, se respalda con la informacion almacenada en los archivos .csv y .dat actuales
			printf("\nSe creo archivo config");
			config.idBin= initBinFile(pathBin);
			config.idTxt= initCsvFile(pathCsv);

			fwrite ( &config , sizeOfConfig , 1 , pArch );



			// cierre de archivo en "wb"
			if((fclose(pArch))==-1)
			{
			printf("\nNo se pudo cerrar el archivo config");
			}

		}

	}
	else
	{


		// se guardan datos almacenados
		cant= fread(&config, sizeOfConfig, 1, pArch);
		printf("\n cant: %d", cant);

		// se verifica posibilidad de guardar el dato
		if(cant!=1)
		{
			printf("\nProblemas de lectura con archivo config");
			config.idBin= -1;
			config.idTxt= -1;
		}
		else
		{
			printf("\nse leyo archivo config");
			//idBinAux= initBinFile(pathBin);
			//idTxtAux= initCsvFile(pathCsv);
		}


		// cierre de archivo en "rb"
		if((fclose(pArch))==-1)
		{
		printf("\nNo se pudo cerrar el archivo config");
		}


	}


	//en caso de primera lectura, se solucionan datos
	if(config.idBin<0 && config.idTxt>=0)
	{
		printf("\nconfig.idBin: %d", config.idBin);																	// debug
		config.idBin=0;
	}

	if ( config.idTxt>=config.idBin )
	{
		printf("\nConfiguracion lista");
	}


	printf("\nconfig.idBin: %d\t|config.idTxt: %d", config.idBin, config.idTxt);
	return config;
}

/**
 * @brief sets next passenger's ID
 *
 * @param listaPasajeros_buffer LinkedList*
 * @param config id's saved data
 * @return current id if ok, -1 if error
 */
int configIdCurrent( LinkedList* listaPasajeros_buffer, Config config)
{

	int retorno;
	Passenger* passengerAux= NULL;

	// chequea cual es el id actual, que el csv tendra ventaja por poderse editar directamente desde el archivo
	if ( config.idTxt>=config.idBin )
	{
		// crea un nuevo passenger que tiene seteado el mismo id que el passenger anterior y lo agrega al linkedlist
		passengerAux= Passenger_new();
		if (Passenger_setId(passengerAux, config.idTxt) )
		{
			ll_add(listaPasajeros_buffer, passengerAux);
			retorno= config.idTxt;
		}
		else
		{
			retorno= -1;
		}
	}
	else //retorna -1 en caso de error en informacion guardada
	{
		retorno= -1;
	}


	return retorno;
}




