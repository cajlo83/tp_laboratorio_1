/*
 * personalio.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Cajlo
 */

#ifndef PERSONALIO_H_
#define PERSONALIO_H_

/**
 * muestra un mensaje y luego pausa el programa esperando que presiones una tecla en el teclado
 *
 * @param mensaje
 */
void esperar(char *mensaje);

/**
 * verifica si un numero entero esta en un rango especifico, o si es menor o mayor que 0. retorna 1 en caso de verdadedor o0 en caso de falso
 * minimo=0 y maximo=-1 : verifica si el numero es negativo
 * minimo=1 y maximo=0 : verifica si el numero es positivo
 *
 * @param numero valor a evaluar
 * @param minimo valor minimo
 * @param maximo valor maximo
 * @return retorna verdadero o falso segun lo planteado con los argumentos
 */
int intVerify(int numero, int minimo, int maximo);


/**
 * verifica si un numero flotante esta en un rango especifico, o si es menor o mayor que 0. retorna 1 en caso de verdadedor o0 en caso de falso
 * minimo=0 y maximo=-1 : verifica si el numero es negativo
 * minimo=1 y maximo=0 : verifica si el numero es positivo
 *
 * @param numero valor a evaluar
 * @param minimo valor minimo
 * @param maximo valor maximo
 * @return retorna verdadero o falso segun lo planteado con los argumentos
 */
int floatVerify(float numero, int minimo, int maximo);


/**
 * muestra un mensaje y queda a la espera para scannear un entero
 * @param mensaje
 * @return retorna el valor escaneado
 */
int intScan(char *mensaje);


/**
 * muestra un mensaje y queda a la espera para scannear un entero
 * @param mensaje
 * @return retorna el valor escaneado
 */
int floatScan(char *mensaje);


/**
 * hace operaciones aritmeticas segun se ingrese los caracteres '*', '/', '+', '-', '%
 *
 * @param a
 * @param b
 * @param operacion espera los caracteres '*', '/', '+', '-', '%' para decidir la operacion
 * @return retorna el resultado
 */
float basicMath(float a, float b, char operacion);			//hace operaciones aritmeticas segun se ingrese los caracteres '*', '/', '+', '-', '%'






#endif /* PERSONALIO_H_ */
