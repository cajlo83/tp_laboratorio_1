
#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ArrayPassenger.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);


int parser_PassengerToText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger);













#endif /* PARSER_H_ */
