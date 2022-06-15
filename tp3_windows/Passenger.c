/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


#include "Passenger.h"

Passenger* Passenger_new()
{
    return malloc(sizeof(Passenger));
}

Passenger* Passenger_newParametros(char* char_id,char* char_name,char* char_lastName,char* char_flycode,char* char_price, int typePassengerAux,int statusFlightAux ) //agregar parametros
{
	//declaracion de auxiliares
	Passenger* passengerAux;
	float priceAux;


	//int statusAux, tipoAux;

	//asignacion de memoria al auxiliar
	passengerAux= Passenger_new();

	/*
	 *  SETTERS
	 */




	Passenger_setId(passengerAux, atoi(char_id) );
	Passenger_setNombre(passengerAux, char_name );
	Passenger_setApellido(passengerAux, char_lastName);
	priceAux= atof(char_price);
	Passenger_setPrecio(passengerAux, priceAux );
	Passenger_setCodigoVuelo(passengerAux, char_flycode);




	//variables ya codificadas a entero fuera de la funcion
	Passenger_setTipoPasajero(passengerAux, typePassengerAux);
	Passenger_setStatusFlight(passengerAux, statusFlightAux);


	return passengerAux;
}

void Passenger_delete(Passenger* this)
{
	if ( this!=NULL )
    free(this);
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno;
	if (this==NULL)
	{
		retorno= 0;
	}
	else
	{
		this->id= id;
		retorno=1;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno;
	if (this==NULL || id== NULL)
	{
		retorno= 0;
	}
	else
	{
		*id= this->id;
		retorno=1;
	}
	return retorno;
}


int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;
	if (this==NULL || nombre==NULL )
	{
		printf("error en Passenger_setNombre ");
		retorno= 0;
	}
	else
	{
		strcpy( this->name, nombre );
		retorno=1;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;
	if (this==NULL || nombre==NULL )
	{
		retorno= 0;
	}
	else
	{
		strcpy( nombre, this->name );
		retorno=1;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;

	if (this==NULL || apellido==NULL )
	{
		retorno= 0;
	}
	else
	{
		strcpy( this->lastName, apellido );
		retorno=1;
	}
	return retorno;
}


int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;
	if (this==NULL || apellido==NULL )
	{
		retorno= 0;
	}
	else
	{
		strcpy( apellido, this->lastName );
		retorno=1;
	}
	return retorno;
}


int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	if (this==NULL || codigoVuelo==NULL )
	{
		retorno= 0;
		printf( "\nerror en Passenger_setCodigoVuelo" );
	}
	else
	{
		strcpy( this->flycode, codigoVuelo );
		retorno=1;
	}
	return retorno;
}


int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	if (this==NULL || codigoVuelo==NULL )
	{
		retorno= 0;
		printf( "\nerror en Passenger_getCodigoVuelo" );

	}
	else
	{
		strcpy( codigoVuelo, this->flycode );
		retorno=1;
	}
	return retorno;
}


int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno;
	if (this==NULL)
	{
		retorno= 0;
	}
	else
	{
		this->typePassenger= tipoPasajero;
		retorno=1;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno;
	if ( this==NULL || tipoPasajero==NULL )
	{
		retorno= 0;
	}
	else
	{
		*tipoPasajero= this->typePassenger;
		retorno=1;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno;

	if (this==NULL)
	{
		retorno= 0;
	}
	else
	{

		this->price= precio;
		retorno=1;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno;
	if ( this==NULL || precio==NULL )
	{
		retorno= 0;
	}
	else
	{
		*precio= this->price;
		retorno=1;
	}
	return retorno;
}


int Passenger_setStatusFlight(Passenger* this,int estado)
{
	int retorno;
	if ( this==NULL )
	{
		retorno= 0;
	}
	else
	{
		this->statusFlight= estado;
		retorno=1;
	}
	return retorno;
}


int Passenger_getStatusFlight(Passenger* this,int* estado)
{
	int retorno;
	if ( this==NULL || estado==NULL )
	{
		retorno= 0;
	}
	else
	{
		*estado= this->statusFlight;
		retorno=1;
	}
	return retorno;
}


