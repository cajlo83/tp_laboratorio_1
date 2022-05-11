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

}typedef eCommon;


int initPassengers(Passenger* list, int len);

int searchEmptyPassenger(Passenger* list, int len);

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);

int alta( Passenger* list, int len, int id, eCommon* tipos, int lenTipos );

int findPassengerById(Passenger* list, int len,int id);

void printOnePassenger(Passenger ticket);



void modificar( Passenger* list, int len, eCommon* tipos, int lenTipos );

int removePassenger(Passenger* list, int len, int id);

int baja(Passenger* list, int len);

int sortPassengers(Passenger* list, int len, int order);

void informar( Passenger* list, int len);





#endif /* ARRAYPASSENGER_H_ */
