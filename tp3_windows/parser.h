
#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ArrayPassenger.h"








/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListPassenger LinkedList*
 * \return max id. -1 if error
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayListPassenger LinkedList*
 * \return max id, -1 if error
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);


/**
 * @brief saves data from buffer to pFile
 *
 * @param pFile FILE*
 * @param pArrayListPassenger data in buffer
 * @return max saved id
 */
int parser_PassengerToText( FILE* pFile , LinkedList* pArrayListPassenger);


/**
 * @brief saves data from buffer to pFile
 *
 * @param pFile FILE*
 * @param pArrayListPassenger data in buffer
 * @return max saved id
 */
int parser_PassengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger);













#endif /* PARSER_H_ */
