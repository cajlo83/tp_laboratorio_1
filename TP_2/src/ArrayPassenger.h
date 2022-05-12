/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may 2022
 *      Author: Cajlo
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define NOMBRE_APELLIDO 51
#define CODIGO_VUELO 10
#define DESCRIPTION 15

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "personalio.h"

struct
{
char name[NOMBRE_APELLIDO];
char lastName[NOMBRE_APELLIDO];
char flycode[CODIGO_VUELO];

float price;

int id;
int typePassenger;
int isEmpty;


}typedef Passenger;


struct
{
int id;
char description[DESCRIPTION];

}typedef eTipo;

// estados de vuelos:
//1 en espera; 2 retrasado; 3 abordando; 4 listo para salir; 5 por despegar; 6 en vuelo
struct
{
int id;
char code[CODIGO_VUELO];
int estado;

}typedef eVuelo;



int initPassengers(Passenger* list, int len);

int searchEmptyPassenger(Passenger* list, int len);

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);

void printTipos( eTipo *list, int len );

int elijeTipos( eTipo *list, int len );


int alta( Passenger* list, int len, int id, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos );

int findPassengerById(Passenger* list, int len,int id);

void printOnePassenger(Passenger ticket);

void modificar( Passenger* list, int len, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos  );

int removePassenger(Passenger* list, int len, int id);

int baja(Passenger* list, int len);

int sortPassengers(Passenger* list, int len, int order);

void informar( Passenger* list, int len);

int printPassenger(Passenger* list, int length);

void passangersData( Passenger* list, int len);

void printVuelos( eVuelo *list, int len );

void elijeVuelos( char* dest, eVuelo *list, int len );

void elijeVuelosRandom( char* dest, eVuelo *list, int len );

int forceData ( Passenger* list, int len, int id, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos );




#endif /* ARRAYPASSENGER_H_ */
