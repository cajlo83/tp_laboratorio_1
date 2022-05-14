/*
 * personalio.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Cajlo
 */

#ifndef PERSONALIO_H_
#define PERSONALIO_H_


/*
 * CONSTANTES
 */
#define STRING_SCAN 1024


/*
 * BIBLIOTECAS
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief verifica si un numero entero esta en el intervalo dado. el intervalo [1;0] verifica si es positivo, el intervalo [0;-1] verifica si es negativo
 *
 * @param numero valor a evaluar
 * @param minimo minimo del intervalo
 * @param maximo maximo del intervalo
 * @return verdadero o falso
 */
int intVerify(int numero, int minimo, int maximo);

/**
 * @brief verifica si un numero real esta en el intervalo dado. el intervalo [1;0] verifica si es positivo, el intervalo [0;-1] verifica si es negativo
 *
 * @param numero valor a evaluar
 * @param minimo minimo del intervalo
 * @param maximo maximo del intervalo
 * @return verdadero o falso
 */
int floatVerify(float numero, int minimo, int maximo);

/**
 * @brief hace un calculo correspondiente entre a y b dependiendo del parametro de operacion
 *
 * @param a valor a
 * @param b valor b
 * @param operacion recibe un caracter con el tipo de operacion ('+', '-', '/', '*')
 * @return a [operacion] b
 */
float basicMath(float a, float b, char operacion);

/**
 * @brief scanea una cadena de caracteres verificando que no se excedan las posiciones de memorias de la variable receptora de datos.
 *
 * @param string cadena de caracteres que se desea llenar
 * @param longitud lungitud de la cadena a llenar
 * @param mensaje mensaje para el usuario
 */
void stringScan(char string[], int longitud, char *mensaje);

/**
 * @brief muestra un mensaje y luego queda a la espera del ingreso de un numero entero para luego retornarlo
 *
 * @param mensaje mensaje a mostrar
 * @return retorna el numero entero ingresado
 */
int intScan(char *mensaje);


/**
 * @brief muestra un mensaje y luego queda a la espera del ingreso de un numero real para luego retornarlo
 *
 * @param mensaje mensaje a mostrar
 * @return retorna el numero entero ingresado
 */
float floatScan(char *mensaje);

/**
 * @brief muestra un mensaje y luego pausa el programa esperando que presiones una tecla en el teclado
 *
 * @param mensaje mensaje de aviso de modo espera
 */
void introContinue(char *mensaje);

/**
 * @brief carga continua de datos para un vector tipo entero
 *
 * @param vector nombre del vector
 * @param size tamaño del vector
 */
void vecIntScan(int vector[], int size);

/**
 * @brief recorre un vector tipo int desde la posicion start hasta la posicion finish y muestra su contenido
 *
 * @param vector nombre del vector
 * @param start posicion de inicio de impresion
 * @param finish posicion de fin de impresion
 */
void vecIntShow(int vector[],int start, int finish);

/**
 * @brief verifica si un numero es par o no.
 *
 * @param num numero a verificar
 * @return  retorna 1 de ser verdadero o 0 de lo contrario
 */
int isPair(int num);

/**
 * @brief ordena un vector tipo int,
 *
 * @param vector nombre del vector
 * @param len tamaño del vector
 * @param dir ordenamiento ascendente si dir>=0, descendente si dir<0
 */
void vecIntSort(int vector[], int len, int dir);

/**
 * @brief muestra los valores repetidos en un arreglo de enteros
 *
 * @param vector nombre del vector
 * @param len tamaño del vector
 */
void repetidosVectorEntero(int vector[], int len);

/**
 * @brief sets all vector's slots with num
 *
 * @param vector int*
 * @param len vector's length
 * @param num int
 */
void cleanIntArray(int vector[], int len, int num);

/**
 * @brief sets
 *
 * @param vector
 * @param len
 */
void cleanCharArray(char vector[], int len);

/**
 * @brief retorna un entero random en un intervalo dado (inclusive).
 * recordar combinar con {#include <time.h>} y {srand(time(NULL));}
 *
 * @param random
 * @param minimo valor minimo del intervalo
 * @param maximo valor maximo del intervalo
 * @return random controlado
 */
int randomInt(int minimo, int maximo);

/**
 * @brief checks if a pointer is NULL
 *
 * @param p pointer
 * @return 1 if pointer=FALSE or returns 0 if pointer!=FALSE
 */
int pointerIsNull(void *p);

/**
 * @brief validates each character of a string checking if are all numeric chars
 *
 * @param string char*
 * @return 1 if true, 0 if false
 */
int numericString(char string[]);

/**
 * @brief removes not alpha character in the left side of a string
 *
 * @param string char*
 * @param len string's length
 */
void strCleanLeft(char* string, int len );

/**
 * @brief removes not alpha and not ' ' character in the middle side of a string
 *
 * @param string char*
 * @param len string's length
 */
void strCleanMid(char* string, int len );

/**
 * @brief removes extra ' ' character in the middle side of a string
 *
 * @param string char*
 * @param len string's length
 */
void strSpcNot(char* string, int len);

/**
 * @brief sets string from "this format" to "This Format"
 *
 * @param string char*
 * @param len string's length
 */
void upperStartName( char* string, int len );

/**
 * @brief sets string from "laST_NamE naMe" to "Last_name Name"
 *
 * @param string char*
 * @param len string's length
 */
void stringNameFormat(char* string, int len);

/**
 * @brief sets a random string
 *
 * @param string char*
 * @param len string's length
 */
void randomString(char* string, int len);

#endif /* PERSONALIO_H_ */
