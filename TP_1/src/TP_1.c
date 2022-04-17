
/*
 ============================================================================
 Name        : TP_1.c
 Author      : Carlo Morici
 Version     : 08/04/2022
 Copyright   : Your copyright notice
 Description :

1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.  El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:

3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 Aerolíneas:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 La diferencia de precio es : r “
5. *9-+
6. Salir
Aclaraciones del funcionamiento:
El menú se tiene que ver tal cual está descrito en la consigna. Los resultados se tienen que mostrar con el mismo formato. Se puede realizar un submenú para ingresar los km y los precios.
Los resultados se tienen que ver con el formato presentado en el menú. De la siguiente  manera.

La carga forzada se tiene que mostrar exactamente igual a la pantalla de resultados sin ingresar ninguna opción previamente. Tiene que calcular todo al momento de apretar el botón con los siguientes datos:
Km: 7090
Aerolineas Argentinas: $162965
Latam: $ 159339
(solo mostrar los resultados ya calculados)
Se deben realizar todas las validaciones necesarias para que el programa funcione  correctamente. Por ej: no se puede realizar cálculos si no hay vuelos ingresados.
Todas las funciones que realizarán los cálculos del menú se deberán realizar en una biblioteca aparte, que contenga las funciones para realizar todas las operaciones.
En el menú deberán aparecer los valores actuales cargados en los vuelos de Latam y Aerolineas (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "personalio.h"
#include "tp1.h"

#define P_BTC 4606954.55	//se controla el precio del BTC por medio de un define por su naturaleza cambiaria

int main(void) {
	setbuf(stdout, NULL);

	int menu=-1;				//
	int kmts=-1;				//
	float aerolineas=-1;		//inician en -1 para hacer verificaciones posteriores
	float latam=-1;				//
	float debitoA=-1;			//


	float debitoL;
	float creditoA;
	float creditoL;
	float BTCA;
	float BTCL;
	float PPUA;
	float PPUL;
	float diferencia;

	do
	{
		showMenu(menu, aerolineas, latam, kmts, P_BTC);		//muestra distintos datos en el menu segun los datos ingresados

		do{
			menu=intScan("\ningrese una opcion del 1 al 6 para proceder: ");
		}while(!intVerify(menu, 1, 6));

		switch (menu){		//swtich-case que controla las opciones del menu
			case 1:
			{
				do{
					kmts=intScan("\ningrese los kilometros del recorrido (entre 70 y 16700): ");		//las rutas de vuelo mas corta y mas larga del planeta respectivamente segun google.
				}while(!intVerify(kmts, 70, 16700));
				break;
			}
			case 2:
			{
				do{
					aerolineas=floatScan("\ningrese el precio de aerolineas: ");
				}while(!floatVerify(aerolineas, 1, 0));	//precios positivos

				do{
					latam=floatScan("\ningrese el precio de latam: ");
				}while(!floatVerify(latam, 1, 0));		//precios deben ser positivos

				break;
			}
			case 3:
			{
				findResults(&debitoA, &debitoL, &creditoA, &creditoL, &BTCA, &BTCL, &PPUA, &PPUL, kmts, latam, aerolineas, &diferencia, P_BTC);
				break;
			}
			case 4:
			{
				showResults( debitoA,  debitoL,  creditoA,  creditoL,  BTCA,  BTCL,  PPUA,  PPUL,  kmts,  latam,  aerolineas, diferencia);
				break;
			}
			case 5:{
				forceData(P_BTC);
			}
		}
		//printf("1");
	}while(menu!=6);
	return 1;
}

