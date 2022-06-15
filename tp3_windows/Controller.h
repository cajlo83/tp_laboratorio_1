
#ifndef CONTROLLER_H_
#define CONTROLLER_H_




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "personalio.h"
#include "LinkedList.h"
#include "personalio.h"

#include "ArrayPassenger.h"
#include "parser.h"




int mainMenu(int min, int max);

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);




// exit value:

#endif /* CONTROLLER_H_ */
