/*
 * FilesInit.h
 *
 *  Created on: 15 jun 2022
 *      Author: Cajlo
 */

#ifndef SETUPS_H_
#define SETUPS_H_


#include "setups.h"

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
struct
{

	int idTxt;
	int idBin;


}typedef Config;

/**
 * @brief set's initial data for csv file and future id's
 *
 * @param path txt path file
 * @return max saved id, -1 if error
 */
int initCsvFile(char* path);


/**
 * @brief set's initial data for binary file and future id's
 *
 * @param path binary path file
 * @return max saved id, -1 if error
 */
int initBinFile(char* path);

/**
 * @brief makes initial settings between files and future id's
 *
 * @param path config path
 * @param pathCsv data.csv path
 * @param pathBin data.dat path
 * @return Config data
 */
Config configFile(char* path, char* pathCsv, char* pathBin);


int configIdCurrent( LinkedList* listaPasajeros_buffer, Config config);

#endif /* SETUPS_H_ */
