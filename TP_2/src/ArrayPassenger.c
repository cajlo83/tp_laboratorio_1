/*
 * ArrayPassenger.c
 *
 *  Created on: 7 may 2022
 *      Author: Cajlo
 */


#include "ArrayPassenger.h"



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len)
{
	int i;

	//checks Invalid length
	if( len<0 )
	{
		return -1;
	}

	//checks NULL pointer

	for( i=0; i<len ; i++)
	{

		if( pointerIsNull(list+i)  )
		{
			printf("problema2");
			return -1;
		}

	}


	//sets *.isEmpty
	for( i=0; i<len ; i++)
	{
		list[i].isEmpty=1;
	}

	return 0;
}

/**
 * @brief seeks for an empty spot in the arrray
 *
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
 * @return return (-1) if no empty space found, if ok returns the seeked position
 */
int searchEmptyPassenger(Passenger* list, int len)
{
	int i;

	for( i=0; i<len; i++ )
	{
		if( list[i].isEmpty==1 )
		{
			return i;
		}
	}

	return -1;
}

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
* free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int i, pos;


	//checks Invalid length
	if( len<0 )
	{
		return -1;
	}


	//checks NULL pointer
	for( i=0; i<len ; i++)
	{
		if( (list+i) == NULL )
		{
			printf( "falla 2" );
			return -1;
		}
	}

	//checks free space
	pos=searchEmptyPassenger(list, len);

	if( pos==-1 )
	{
		printf( "falla 3" );
		return -1;
	}



	//paste data
	strcpy(list[pos].name, name );
	strcpy(list[pos].lastName, lastName );
	strcpy(list[pos].flycode, flycode );
	list[pos].price= price;
	list[pos].typePassenger= typePassenger;

	// auto ID
	list[pos].id=id;

	//no more empty
	list[pos].isEmpty=0;

	//anouncement of new ticket
	printf( "\nSe cargo el usuario:" );
	printOnePassenger(list[pos]);

	return 0;
}

/** \brief print the content of eTipo array
*
* \param list list
* \param length int
*/
void printTipos( eTipo *list, int len )
{
	int i;
	for( i=0; i<len; i++ )
	{
		printf("\nid: %d \t descripcion: %s", list[i].id, list[i].description );
	}

}

/**
 * @brief select the type ID shown from a list
 *
 * @param list eTipo*
 * @param len	list's lenght
 * @return the type's ID
 */
int elijeTipos( eTipo *list, int len )
{
	int flag, i;
	int retorno= -1;

	do
	{
			//muestra los tipos de pasajeros antes de solicitar elegir uno

		printTipos( list,  len);
		retorno= intScan("\nIngrese tipo de pasajero_ ");

		for( i=0; i<len; i++ )
		{
			if( list[i].id==retorno )
			{
				flag=0;
				break;
			}
			else
			{

				flag=1;
			}
		}
	}while( flag );

	return retorno;
}





/** \brief print the content of eTipo array
*
* \param list list
* \param length int
*/
void printVuelos( eVuelo *list, int len )
{
	int i;

	printf("\n\t**codigos de vuelo disponibles**");
	for( i=0; i<len; i++ )
	{
		printf("\nid: %d \t codigo: %s \testado: %d", list[i].id, list[i].code, list[i].estado  );
	}

}

/**
 * @brief select the flight ID shown from a list
 *
 * @param list eTipo*
 * @param len	list's lenght
 */
void elijeVuelos( char* dest, eVuelo* list, int len )
{
	int flag;
	int i, id;

	do
	{
			//muestra los codigos de vuelo antes de solicitar elegir uno

		printVuelos( list,  len);
		id= intScan("\nIngrese id de vuelo_ ");

		for( i=0; i<len; i++ )
		{

			if( list[i].id==id )
			{

				flag=0;
				break;
			}
			else
			{

				flag=1;
			}

		}
	}while( flag );


	strcpy( dest, list[i].code );

}

/**
 * @brief randomly select the flight ID shown from a list
 *
 * @param list eTipo*
 * @param len	list's lenght
 */
void elijeVuelosRandom( char* dest, eVuelo* list, int len )
{
	int flag;
	int i, id;

	do
	{

		id= randomInt(0, len-1);

		for( i=0; i<len; i++ )
		{
			if( list[i].id==id )
			{
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}

		}
	}while( flag );


	strcpy( dest, list[i].code );

}




/**
 * @brief print's the data from a Passenger struct
 *
 * @param ticket Passenger struct
 */
void printOnePassenger(Passenger ticket)
{
	printf( "\nID: %d", ticket.id );
	printf( "\tName: %s", ticket.name );
	printf( "\tLastName: %s", ticket.lastName );
	printf("\tPrice: %.2f", ticket.price);
	printf("\tTypeCode: %d", ticket.typePassenger);
	printf("\tFlyCode: %s", ticket.flycode);


}

/**
 * @brief Passemger's signing up procces
 *
 * @param list Ppassenger*
 * @param len (passenger*) lenght
 * @param id passenger's id
 * @param tipos
 * @param lenTipos
 * @return return 1 if ok, 0 if not
 */
int alta( Passenger* list, int len, int id, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos )
{

	char name[NOMBRE_APELLIDO];
	char lastName[NOMBRE_APELLIDO];
	float price;
	int typePassenger;
	char flycode[CODIGO_VUELO];


	// name
	stringScan(name, NOMBRE_APELLIDO, "\nIngrese el nombre del pasajero_ ");
	stringNameFormat( name, NOMBRE_APELLIDO );

	// last name
	stringScan(lastName, NOMBRE_APELLIDO, "\nIngrese el apellido del pasajero_ ");
	stringNameFormat( lastName, NOMBRE_APELLIDO );

	//price
	price= floatScan("\nIngrese monto a cobrar al cliente_ ");
	printf("\t**tipos de pasajeros disponibles**");

	//type
	typePassenger= elijeTipos( tipos, lenTipos );

	// flycode
	elijeVuelos(flycode, vuelos, lenVuelos);



	//2.1
	if ( addPassenger( list,  len,  id,  name, lastName, price, typePassenger,  flycode) )
	{
		printf( "\nno fue posible el alta del usuario" );
		return 0;
	}


	return 1;

}


/** \brief find a Passenger by Id and returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id)
{
	int i;


	//checks Invalid length
	if( len<0 )
	{
		return -1;
	}

	//checks if pointer received is NULL
	if( list!=NULL && len>0 )
	{
		for(i=0; i<len;i++)
		{
			if( list[i].id==id && list[i].isEmpty==0 )
			{
				return i;
			}
		}
	}


	return -1;
}

/**
 * @brief Passemger's modification procces
 *
 * @param list Passenger*
 * @param len list's lenght
 * @param tipos eTipos*
 * @param lenTipos tipo's lenght
 */
void modificar( Passenger* list, int len, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos  )
{
	int idBuscado, menu, index;

	//busqueda de datos
	idBuscado= intScan("\nIngrese el numero id de quien desee modificar_ ");
	index= findPassengerById(list, len, idBuscado);

	//validacion de resultados
	if ( list[index].isEmpty==1 || index==-1 )
	{
		printf( "\nEl usuario mencionado  no existel" );
	}
	else if( pointerIsNull( (list+index) )  )
	{
		printf( "\nEl valor ingresado no coincide con los datos almacenados"  );
	}
	else
	{



		do
		{

			//anouncement of ticket
			printf( "\nPassenger info::" );
			printOnePassenger(list[index]);

			// menu
			printf("\n\n\t ***** MENU MODIFICAR ***** ");
			printf( "\n1\t NOMBRE" );
			printf( "\n2\t APELLIDO" );
			printf( "\n3\t PRECIO" );
			printf( "\n4\t TIPO" );
			printf( "\n5\t CODIGO DE VUELO");
			printf( "\n\n6\t *SALIR* " );

			//request to user
			menu= intScan("\nOPCION_ ");


			//otions
			switch ( menu )
			{

			case 1 :
				stringScan(list[index].name, NOMBRE_APELLIDO, "\nIngrese el nuevo nombre del pasajero_ ");
				stringNameFormat( list[index].name, NOMBRE_APELLIDO );



				break;



			case 2 :
				stringScan(list[index].lastName, NOMBRE_APELLIDO, "\nIngrese el nuevo apellido del pasajero_ ");
				stringNameFormat( list[index].lastName, NOMBRE_APELLIDO );
				break;



			case 3 :
				list[index].price= floatScan("\nIngrese el nuevo monto a cobrar al cliente_ ");
				break;




			case 4:
				//muestra los tipos de pasajeros antes de solicitar elegir uno
				list[index].typePassenger= elijeTipos( tipos, lenTipos );
				break;

			case 5 :

				elijeVuelos(list[index].flycode, vuelos, lenVuelos);
				//stringScan(list[index].flycode, CODIGO_VUELO, "\nIngrese el nuevocodigo de vuelo_ ");
				break;





			case 6 :

				printf("\n\t ***** SaLIENDO DE MODIFICAR ***** ");
				break;

			default:
				printf("No se reicibio un valor esperado, reintente");
			}

		}while( menu!=6 );
	}

}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int index, conf;

	index= findPassengerById(list, len, id);


	//checks Invalid length
	if( len<0 )
	{
		return -1;
	}

	//validates results
	if ( list[index].isEmpty==1 || index==-1 )
	{
		printf( "\nEl usuario mencionado  no existe" );
	}
		//checks null pointer
	else if( (list+index) ==NULL  )
	{
		printf( "\nEl valor ingresado no coincide con los datos almacenados"  );
	}
	else
	{
		//announcement of ticket and confirmation
		printf( "\nSeguro desea eliminar a:" );
		printOnePassenger( list[index] );
		conf=intScan("\nIngrese 1 para continuar con la eliminacion o ingrese otro valor para cancelar_ ");

		if( conf==1 )
		{
			list[index].isEmpty=1;

			return 0;
		}

	}

	return -1;
}

/** \brief Passemger's signing down procces
*
* \param list Passenger*
* \param len int
*/
int baja(Passenger* list, int len )
{

	int idBuscado, conf;


		//busqueda de datos
		idBuscado= intScan("\nIngrese el numero id de quien desee dar de baja ");


		conf= removePassenger(  list,  len,  idBuscado);
		if( conf )
		{
			printf( "\nBaja abortada." );
			return 0;
		}
		else
		{
			printf( "\nBaja exitosa" );
			return 1;
		}

}



/*
 * Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
 * descendente.
 */
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order)
{

	int i, j, comp;
	Passenger eAux;

	//checks Invalid length
	if( len<0 )
	{
		return -1;
	}


	// checks null pointer
	if( pointerIsNull( (list) ) )
	{
		return -1;
	}

	// checks order
	switch( order )
	{

	// ascendant
	case 1 :
		for( i=0; i<len; i++ )
		{
			for(j=i+1;j<len;j++)
			{
				// checks null pointer
				if( pointerIsNull( (list+j) ) )
				{
					return -1;
				}
				// compares
				comp= strcmp(list[i].lastName, list[j].lastName);

				// sorts if needed
				if( comp>0 )
				{
					eAux=list[i];
					list[i]=list[j];
					list[j]=eAux;
				}
				else if( comp==0 && (list[i].typePassenger>list[j].typePassenger) )
				{
					eAux=list[i];
					list[i]=list[j];
					list[j]=eAux;
				}
			}
		}
		break;

	// descendant
	case 0 :
		for( i=len-1; i>=0; i-- )
		{
			for( j=i-1; j>=0; j-- )
			{
				// checks null pointer
				if( pointerIsNull( (list+j) ) )
				{
					return -1;
				}
				// compares
				comp= strcmp(list[i].lastName, list[j].lastName);

				// sorts if needed
				if( comp>0 )
				{
					eAux=list[i];
					list[i]=list[j];
					list[j]=eAux;
				}
				else if( comp==0 && (list[i].typePassenger>list[j].typePassenger) )
				{
					eAux=list[i];
					list[i]=list[j];
					list[j]=eAux;
				}
			}
		}
		break;

		default:
			printf( "\nParametro incorrecto para organizacion " );
			return -1;


	}

return 0;
}

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length)
{

	int i;

	for ( i=0; i<length; i++)
	{
		if( list[i].isEmpty==0 )
		{
			printOnePassenger( list[i] );
		}

	}

return 0;
}

/**
 * @brief show's financial data from list
 *
 * @param list Passenger*
 * @param len list's lenght
 */
void passangersData( Passenger* list, int len)
{

	// Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio
	int i;
	float prom, total=0;
	int cont=0;
	int fatFish=0;

	// total
	for( i=0; i<len; i++ )
	{
		if( list[i].isEmpty==0 )
		{
			total+= list[i].price;
			cont++;
		}
	}

	// promedio
	prom= total/cont;

	// big client
		for( i=0; i<len; i++ )
		{
			if( list[i].isEmpty==0 && list[i].price>prom )
			{
				fatFish++;
			}
		}

		printf("total de los pasajes= %.2f \t promedio de los pasajes= %.2f \t cantidad de pasajeros que pagaron mas del promedio: %d", total, prom, fatFish );

}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order)
{

	int i, j, comp;
	Passenger eAux;


	// checks null pointer and length
	if( pointerIsNull( (list) ) && !(len>0) )
	{
		return -1;
	}

	// checks order
	switch( order )
	{

	// ascendant
	case 1 :
		for( i=0; i<len; i++ )
		{
			for(j=i+1;j<len;j++)
			{
				// checks null pointer
				if( pointerIsNull( (list+j) ) )
				{
					return -1;
				}
				// compares
				comp= strcmp(list[i].flycode, list[j].flycode);

				// sorts if needed
				if( comp>0 )
				{
					eAux=list[i];
					list[i]=list[j];
					list[j]=eAux;
				}
				else if( comp==0 && (list[i].typePassenger>list[j].typePassenger) )
				{
					eAux=list[i];
					list[i]=list[j];
					list[j]=eAux;
				}
			}
		}
		break;

	// descendant
	case 0 :
		for( i=len-1; i>=0; i-- )
		{
			for( j=i-1; j>=0; j-- )
			{
				// checks null pointer
				if( pointerIsNull( (list+j) ) )
				{
					return -1;
				}
				// compares
				comp= strcmp(list[i].flycode, list[j].flycode);

				// sorts if needed
				if( comp>0 )
				{
					eAux=list[i];
					list[i]=list[j];
					list[j]=eAux;
				}
				else if( comp==0 && (list[i].typePassenger>list[j].typePassenger) )
				{
					eAux=list[i];
					list[i]=list[j];
					list[j]=eAux;
				}
			}
		}
		break;

		default:
			printf( "\nParametro incorrecto para organizacion " );
			return -1;


	}

return 0;
}



/**
 * @brief Passemger's data analysis/information procces
 *
 * @param list
 * @param len
 */
void informar( Passenger* list, int len, eVuelo* vuelos, int lenVuelos)
{


//	2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
//	3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’

	int menu, order, conf;

	do
	{

		// menu
		printf("\n\n\t ***** MENU INFORMAR ***** ");
		printf( "\n1\t Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero." );
		printf( "\n2\t Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio. " );
		printf( "\n3\t Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’" );
		printf( "\n\n4\t *SALIR* " );

		//request to user
		menu= intScan("\nOPCION_ ");


		//otions
		switch ( menu )
		{
		//	1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
		case 1 :
			order= intScan("\nIngrese 1 para orden ascendente, ingrese 0 para orden descendente_ ");
			conf= sortPassengers( list,  len,  order);
			if ( !conf )
			{
				 printPassenger( list, len);
			}

			break;



		//	2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
		case 2 :
			passangersData(list, len);

			break;


		//	3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
		case 3 :
			order= intScan("\nIngrese 1 para orden ascendente, ingrese 0 para orden descendente_ ");
			conf= sortPassengersByCode( list,  len,  order);
			if ( !conf )
			{
				 printPassenger( list, len);
			}
			break;



		case 4:
			printf("\n\t ***** SaLIENDO DE INFORMAR ***** ");
			break;

		default:
			printf("No se reicibio un valor esperado, reintente");
		}

	}while( menu!=4 );


}

int forceData ( Passenger* list, int len, int id, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos )
{

	char name[NOMBRE_APELLIDO];
	char lastName[NOMBRE_APELLIDO];
	float price;
	int typePassenger;
	char flycode[CODIGO_VUELO];


	// checks null pointer and length
	if( pointerIsNull( (list) ) && !(len>0) )
	{
		return -1;
	}

	// NAME
	randomString( name, NOMBRE_APELLIDO);
	stringNameFormat(name, NOMBRE_APELLIDO);

	// LASTNAME
	randomString( lastName, NOMBRE_APELLIDO);
	stringNameFormat(lastName, NOMBRE_APELLIDO);

	// price
	price= randomInt(1, 1000)*1.141592;

	//tipo
	typePassenger= randomInt(0, lenTipos-1);

	//codigo de vuelo
	elijeVuelosRandom(flycode, vuelos, lenVuelos);



	//2.1
	if ( addPassenger( list,  len,  id,  name, lastName, price, typePassenger,  flycode) )
	{
		printf( "\nno fue posible el alta del usuario" );
		return 0;
	}


	return 1;

}



