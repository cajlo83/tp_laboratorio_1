/*
 * ArrayPassenger.c
 *
 *  Created on: 7 may 2022
 *      Author: Cajlo
 */


#include "ArrayPassenger.h"



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

int Passenger_NewAdition(Passenger* pPassenger, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight )
{
	int retorno= 0;

	if ( pointerIsNull(pPassenger) )
	{
		retorno= -1;
	}
	else
	{
		//setters

		Passenger_setNombre(pPassenger, name);
		Passenger_setApellido(pPassenger, lastName);
		Passenger_setCodigoVuelo(pPassenger, flycode);
		Passenger_setPrecio(pPassenger, price);
		Passenger_setTipoPasajero(pPassenger, typePassenger);
		Passenger_setStatusFlight(pPassenger, statusFlight);

		// sets id
		Passenger_setId(pPassenger, id);

		//no more empty
		pPassenger->isEmpty=0;

		retorno= id;
	}



	return retorno;
}

void Tipo_printAll( eTipo *list, int len )
{
	int i;
	for( i=0; i<len; i++ )
	{
		printf("\nid: %d \t descripcion: %s", list[i].id, list[i].description );
	}

}

int Tipo_validarID(eTipo *list, int len, int idAux )
{
	int i, retorno;

	for( i=0; i<len; i++ )
	{
		if( list[i].id==idAux )
		{
			retorno=i;
			break;
		}
		else
		{

			retorno=-1;
		}
	}



	return retorno;
}

int Tipo_validarDescription(eTipo *list, int len, char* descAux )
{
	int i, retorno;

	for( i=0; i<len; i++ )
	{
		if( 0==strcmp( descAux, list[i].description ) )
		{
			retorno=i;
			break;
		}
		else
		{

			retorno=-1;
		}
	}



	return retorno;
}

int passenger_typeEncoder(char* str_typePassenger)
{
	int typeAux;

	if( pointerIsNull(str_typePassenger) )
	{
		typeAux= -1;
	}
	else if( 0==strcmp( str_typePassenger, "FirstClass" ) )
	{
		typeAux= CLASE_PRIMERA;
	}
	else if( 0==strcmp( str_typePassenger, "ExecutiveClass" ) )
	{
		typeAux= CLASE_EJECUTIVO;
	}
	else if( 0==strcmp( str_typePassenger, "EconomyClass" ) )
	{
		typeAux= CLASE_ECONOMICA;
	}
	else
	{
		typeAux= CLASE_OTRO;
	}


	return typeAux;
}



int passenger_typeDecoder( int int_type, char* str )
{
	int retorno;
	char strAux[20];

	if( pointerIsNull(str) )
	{
	retorno=0;
	}
	else
	{

		switch( int_type )
		{

		case CLASE_PRIMERA :
			strcpy( strAux, "FirstClass" );
			break;

		case CLASE_EJECUTIVO :
			strcpy( strAux, "ExecutiveClass" );
			break;

		case CLASE_ECONOMICA :
			strcpy( strAux, "EconomyClass" );
			break;

		case CLASE_OTRO :
			strcpy( strAux, "OTRO" );
			break;

		}

		strcpy( str , strAux );

		retorno= 1;

	}
		return retorno;
}


int passenger_statusEncoder(char* str_statusFlight)
{
	int statusAux;

	if( pointerIsNull(str_statusFlight) )
	{
		statusAux= -1;
	}
	else if( 0==strcmp( str_statusFlight, "En Horario" ) )
	{
		statusAux= STATUS_EN_HORARIO;
	}
	else if( 0==strcmp( str_statusFlight, "Aterrizado" ) )
	{
		statusAux= STATUS_ATERRIZADO;
	}
	else if( 0==strcmp( str_statusFlight, "En Vuelo" ) )
	{
		statusAux= STATUS_EN_VUELO;
	}
	else if( 0==strcmp( str_statusFlight, "Demorado" ) )
	{
		statusAux= STATUS_DEMORADO;
	}
	else
	{
		statusAux= STATUS_OTRO;
	}

	return statusAux;
}



int Tipo_elegir( eTipo *list, int len )
{
	int flag, i;
	int retorno;

	if( pointerIsNull(list) ) //checks NULL pointer
	{
		retorno=-1;
	}
	else
	{

		do
		{
				//muestra los tipos de pasajeros antes de solicitar elegir uno

			Tipo_printAll( list,  len);
			retorno= intScan("\nIngrese tipo de pasajero_ ");

				//valida la seleccion
			flag= Tipo_validarID(  list,  len, retorno );


		}while( !flag );
	}

	return retorno;
}

void printVuelos( eVuelo *list, int len )
{
	int i;

	printf("\n\t**codigos de vuelo disponibles**");
	for( i=0; i<len; i++ )
	{
		printf("\nid: %d \t codigo: %s \testado: %d", list[i].id, list[i].code, list[i].estado  );
	}

}

eVuelo elijeVuelos( char* dest, eVuelo* list, int len )
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


	return list[i];

}

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

int passenger_statusDecoder(int int_status, char* str )
{
	int retorno;

	if( pointerIsNull(str) )
	{
	retorno=0;
	}
	else
	{
		switch( int_status )
		{

		case STATUS_EN_HORARIO :
			strcpy( str, "En Horario" );
			break;

		case STATUS_EN_VUELO :
			strcpy( str, "En Vuelo" );
			break;

		case STATUS_DEMORADO :
			strcpy( str, "Demorado" );
			break;

		case STATUS_ATERRIZADO :
			strcpy( str, "Aterrizado" );
			break;

		case STATUS_OTRO :
			strcpy( str, "OTRO" );
			break;



		}

		retorno= 1;
	}
		return retorno;
}

void printOnePassenger(Passenger ticket)
{

	char str_status[DESCRIPTION];
	char str_type[DESCRIPTION];


	int id;
	char name[NOMBRE_APELLIDO];
	char lastName[NOMBRE_APELLIDO];
	char flycode[CODIGO_VUELO];
	float price;
	int typePassenger;
	int statusFlight; // antes llamado flyState

	Passenger* passengerPoint= &ticket;


	// impresiones validadas con getters

	if ( Passenger_getId(passengerPoint, &id) )						// id
	{
		printf( "\nID: %d", id );
	}
	else
	{
		printf("error en Passenger_getId\n");
	}



	if ( Passenger_getNombre( passengerPoint, name) )						// name
	{
		printf( "\t|Name: %s", name );
	}
	else
	{
		printf("error en Passenger_getNombre\n");
	}




	if ( Passenger_getApellido( passengerPoint, lastName) )						// lastname
	{
		printf( "\t|LastName: %s", lastName );
	}
	else
	{
		printf("error en Passenger_getApellido\n");
	}




	if ( Passenger_getPrecio( passengerPoint, &price) )						// price
	{
		printf( "\t|Price: %.2f", price );
	}
	else
	{
		printf("error en Passenger_getPrecio\n");
	}




	if ( Passenger_getCodigoVuelo( passengerPoint, flycode) )				// flycode
	{
		printf( "\t|FlyCode: %s", flycode );
	}
	else
	{
		printf("error en Passenger_getCodigoVuelo\n");
	}



	Passenger_getTipoPasajero( passengerPoint, &typePassenger);				// type
	if ( passenger_typeDecoder( typePassenger, str_type ) )
	{
		printf( "\t|TypePassenger: %s", str_type );
	}
	else
	{
		printf("error en passenger_typeDecoder\n");
	}


	Passenger_getStatusFlight(passengerPoint, &statusFlight);				// status
	if ( passenger_statusDecoder(ticket.statusFlight, str_status) )
	{
		printf( "\t|StatusFlight: %s", str_status );
	}
	else
	{
		printf("error en passenger_statusDecoder\n");
	}




}

int elijeEstadoVuelo( void )
{
	int flag=1;
	int retorno= -1;

	do
	{
			//muestra los tipos de pasajeros antes de solicitar elegir uno

		printf("\nEstados de vuelo disponibles:");

		// ESTADO_BIEN 100
		printf("\n%d | ESTADO_BIEN",ESTADO_BIEN);
		// ESTADO_DEMORADO 200
		printf("\n%d | ESTADO_DEMORADO",ESTADO_DEMORADO);
		// ESTADO_ABORDADO 300
		printf("\n%d | ESTADO_ABORDADO",ESTADO_ABORDADO);
		// ESTADO_NO_ABORDADO 400
		printf("\n%d | ESTADO_NO_ABORDADO",ESTADO_NO_ABORDADO);
		// ESTADO_OTRO 500
		printf("\n%d | ESTADO_OTRO",ESTADO_OTRO);
		// ESTADO_ACTIVO 600
		printf("\n%d | ESTADO_ACTIVO",ESTADO_ACTIVO);

		retorno= intScan("\nIngrese estado de vuelo del pasajero_ ");


		switch( retorno )
		{
		case ESTADO_BIEN :
		case ESTADO_DEMORADO :
		case ESTADO_ABORDADO :
		case ESTADO_NO_ABORDADO :
		case ESTADO_OTRO :
		case ESTADO_ACTIVO :
			flag=0;
			break;

		default:
			printf("\nNo ingreso un estado de vuelo valido.");

		}

	}while( flag );

	return retorno;
}

int alta( Passenger* list, int len, int id, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos )
{


	char name[NOMBRE_APELLIDO];
	char lastName[NOMBRE_APELLIDO];
	char flycode[CODIGO_VUELO];
	float price;
	int typePassenger;
	int statusFlight;

	int index;


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
	typePassenger= Tipo_elegir( tipos, lenTipos );

	// flycode
	elijeVuelos(flycode, vuelos, lenVuelos);

	// statusFlight
	statusFlight= elijeEstadoVuelo();






	//2.1
	if ( addPassenger( list,  len,  id,  name, lastName, price, typePassenger,  flycode) )
	{
		printf( "\nno fue posible el alta del usuario" );
		return 0;
	}
	else
	{


		/*
		 * NOTA: el dado de statusFlight se deja por fuera de addPassenger() debido a la consigna: (!) No se deben modificar los prototipos de las funciones dadas en el enunciado
		 */

		// add FlyState
		index= findPassengerById( list,  len, id);
		list[index].statusFlight= statusFlight;


		//anouncement of new ticket
		printf( "\nSe cargo el usuario:" );
		printOnePassenger(list[index]);
	}


	return 1;

}

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

			printf( "\n\n6\t ESTADO DE VUELO");
			printf( "\n7\t *SALIR* " );

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
				list[index].typePassenger= Tipo_elegir( tipos, lenTipos );
				break;

			case 5 :

				elijeVuelos(list[index].flycode, vuelos, lenVuelos);
				break;


			case 6 :

				list[index].statusFlight= elijeEstadoVuelo(); ;
				break;





			case 7 :

				printf("\n\t ***** SaLIENDO DE MODIFICAR ***** ");
				break;

			default:
				printf("No se reicibio un valor esperado, reintente");
			}

		}while( menu!=7 );
	}

}

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

int sortPassengers(Passenger* list, int len, int order)
{

	int i, j, comp;
	Passenger eAux;


	// checks null pointer and length
	if( pointerIsNull( (list) ) || !(len>0) )
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
				// compares x2
				else if( comp==0 && (list[i].statusFlight<list[j].statusFlight) )
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
				// compares x2
				else if( comp==0 && (list[i].statusFlight>list[j].statusFlight) )
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
	int statusFlight;

	int index;


	// checks null pointer and length
	if( pointerIsNull( (list) ) || !(len>0) )
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

	// statusFlight
	statusFlight= randomInt(1, 6);
	statusFlight*= 100;





	//2.1
	if ( addPassenger( list,  len,  id,  name, lastName, price, typePassenger,  flycode) )
	{
		printf( "\nno fue posible el alta del usuario" );
		return 0;
	}
	else
		{


			/*
			 * NOTA: el dado de statusFlight se deja por fuera de addPassenger() debido a la consigna: (!) No se deben modificar los prototipos de las funciones dadas en el enunciado
			 */

			// add FlyState
			index= findPassengerById( list,  len, id);
			list[index].statusFlight= statusFlight;


			//anouncement of new ticket
			printf( "\nSe cargo el usuario:" );
			printOnePassenger(list[index]);
		}



	return 1;

}



