/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may 2022
 *      Author: Cajlo
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

//#define NOMBRE_APELLIDO 51
//#define CODIGO_VUELO 10
#define DESCRIPTION 20

#define ESTADO_BIEN 100
#define ESTADO_DEMORADO 200
#define ESTADO_ABORDADO 300
#define ESTADO_NO_ABORDADO 400
#define ESTADO_OTRO 500
#define ESTADO_ACTIVO 600


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "personalio.h"
#include "Passenger.h"


//
//struct
//{
//char name[NOMBRE_APELLIDO];
//char lastName[NOMBRE_APELLIDO];
//char flycode[CODIGO_VUELO];
//float price;
//int id;
//int typePassenger;
//int flyState;
//int isEmpty;
//
//}typedef Passenger;


struct
{
	char description[DESCRIPTION];
	int id;

}typedef eTipo;

struct
{
	char description[DESCRIPTION];
	int id;


}typedef eStatus;



struct
{
	int id;
	char code[CODIGO_VUELO];
	int estado;

}typedef eVuelo;




/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);

/**
 * @brief seeks for an empty spot in the arrray
 *
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
 * @return return (-1) if no empty space found, if ok returns the seeked position
 */
int searchEmptyPassenger(Passenger* list, int len);

/** \brief add's data for a new passenger
* \param pPassenger passenger*
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
* free space] - (0) if Ok
*/
int Passenger_NewAdition(Passenger* pPassenger, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight );

/** \brief print the content of eTipo array
*
* \param list list
* \param length int
*/
void Tipo_printAll( eTipo *list, int len );


/**
 * @brief validates if idAux belongs to any of the element of list
 *
 * @param list eTipo*
 * @param len list's length
 * @param idAux id to check
 * @return an index from list, -1 if not ok
 */
int Tipo_validarID(eTipo *list, int len, int idAux );

/**
 * @brief validates if descAux belongs to any of the element of list
 *
 * @param list eTipo*
 * @param len list's length
 * @param descAux description to check
 * @return an index from list, -1 if not ok
 */
int Tipo_validarDescription(eTipo *list, int len, char* descAux );

/**
 * @brief encodes the type of passenger as an int
 *
 * @param str_typePassenger decoded type
 * @return encoded type, -1 if error
 */
int passenger_typeEncoder(char* str_typePassenger);

/**
 * @brief
 * @param int_type
 * @param str
 * @return
 */
int passenger_typeDecoder( int int_type, char* str );

/**
 * @brief encodes the status of flight as an int
 *
 * @param str_statusFlight decoded status
 * @return encoded status, -1 if error
 */
int passenger_statusEncoder(char* str_statusFlight);

/**
 * @brief decodes status flight
 *
 * @param int_status coded status
 * @param str decoded status
 * @return 1 if ok, 0 if not
 */
int passenger_statusDecoder(int int_status, char* str );

/**
 * @brief select the type ID shown from a list
 *
 * @param list eTipo*
 * @param len	list's lenght
 * @return the type's ID
 */
int Tipo_elegir( eTipo *list, int len );

/**
 * @brief select the FlyStatus shown from a list
 *
 * @return int
 */
int elijeEstadoVuelo( void );

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
int alta( Passenger* list, int len, int id, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos );

/** \brief find a Passenger by Id and returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);


/**
 * @brief print's the data from a Passenger struct
 *
 * @param ticket Passenger struct
 */
void printOnePassenger(Passenger ticket);

/**
 * @brief Passemger's modification procces
 *
 * @param list Passenger*
 * @param len list's lenght
 * @param tipos eTipos*
 * @param lenTipos tipo's lenght
 */
void modificar( Passenger* list, int len, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos  );

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);

/** \brief Passemger's signing down procces
*
* \param list Passenger*
* \param len int
*/
int baja(Passenger* list, int len);

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
int sortPassengers(Passenger* list, int len, int order);

/**
 * @brief Passemger's data analysis/information procces
 *
 * @param list
 * @param len
 */
void informar( Passenger* list, int len, eVuelo* vuelos, int lenVuelos);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length);

/**
 * @brief show's financial data from list
 *
 * @param list Passenger*
 * @param len list's lenght
 */
void passangersData( Passenger* list, int len);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);

/** \brief print the content of eTipo array
*
* \param list list
* \param length int
*/
void printVuelos( eVuelo *list, int len );


/**
 * @brief select the flight ID shown from a list
 *
 * @param list eTipo*
 * @param len	list's lenght
 *
 * @return selected flight
 */
eVuelo elijeVuelos( char* dest, eVuelo *list, int len );

/**
 * @brief randomly select the flight ID shown from a list
 *
 * @param list eTipo*
 * @param len	list's lenght
 */
void elijeVuelosRandom( char* dest, eVuelo *list, int len );

/**
 * @brief adds 1 passenger with random data
 *
 * @param list Passenger*
 * @param len list's length
 * @param id id
 * @param tipos eTipo*
 * @param lenTipos tipos'es length
 * @param vuelos eVuelo*
 * @param lenVuelos vuelos'es length
 * @return 1 if ok, -1 if error
 */
int forceData ( Passenger* list, int len, int id, eTipo* tipos, int lenTipos, eVuelo* vuelos, int lenVuelos );




#endif /* ARRAYPASSENGER_H_ */
