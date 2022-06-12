/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define NOMBRE_APELLIDO 50
#define CODIGO_VUELO 10

#define CLASE_PRIMERA 10
#define CLASE_EJECUTIVO 20
#define CLASE_ECONOMICA 30
#define CLASE_OTRO 99


#define STATUS_EN_HORARIO 100
#define STATUS_EN_VUELO 200
#define STATUS_DEMORADO 300
#define STATUS_ATERRIZADO 400
#define STATUS_OTRO 999


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "personalio.h"
//#include "ArrayPassenger.h"


struct
{

	int id;
	char name[NOMBRE_APELLIDO];
	char lastName[NOMBRE_APELLIDO];
	char flycode[CODIGO_VUELO];
	float price;
	int typePassenger;
	int statusFlight; // antes llamado flyState
	//int isEmpty;

}typedef Passenger;



Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* char_id,char* char_name,char* char_lastName,char* char_flycode,char* char_price, int typePassengerAux,int statusFlightAux ); //agregar parametros
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatusFlight(Passenger* this,int estado);
int Passenger_getStatusFlight(Passenger* this,int* estado);



#endif /* PASSENGER_H_ */
