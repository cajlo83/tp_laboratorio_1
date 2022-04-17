/*
 * tp1.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Cajlo
 */

#ifndef TP1_H_
#define TP1_H_

///
///  Evalua las variables recibidas para decidir como mostrar el menu
///
/// @param aerolineas Recibe el precio de aerolineas
///  @param latam Recibe el precio de latam
///  @param kmts Recobe la cantidad de kilometros
///
void showMenu(int menu, float aerolineas, float latam, int kmts, float precioBTC);						//imprime el menu con datos actualizados






///
/// recibe por valor los datos iniciales, hace calculos correspondiente y guarda los resultados en sus respectivas varaibles por referencia
///
/// @param debitoA Precio debito aerolineas
/// @param debitoL Precio debito latam
/// @param creditoA precio credito aerolineas
/// @param creditoL Precio credito latam
/// @param BTCA Precio bitcoin areolineas
/// @param BTCL Precio bitcoin latam
/// @param PPUA Precio Por Unidad aerolineas
/// @param PPUL Precio Por Unidad latam
/// @param kmts Kilometros
/// @param latam Precio base latam
/// @param aerolineas Precio base aerolineas
/// @param diferencia Diferencia de precios base de aerolineas y latam
/// @param precioBTC Precio del bitcoin
///
void findResults(float *debitoA, float *debitoL, float *creditoA, float *creditoL, float *BTCA, float *BTCL, float *PPUA, float *PPUL,
		int kmts, float latam, float aerolineas, float *diferencia, float precioBTC);		//menu 3)hace calculos y guarda los datos por referencia







/**
 * Recibe las variables calculadas e ingresadas para luego mostrarlas en pantalla con el formato correspondiente
 *
 * @param debitoA Precio debito aerolineas
 * @param debitoL Precio debito latam
 * @param creditoA Precio credito latam
 * @param creditoL Precio credito latam
 * @param BTCA Precio bitcoin areolineas
 * @param BTCL Precio bitcoin latam
 * @param PPUA Precio Por Unidad aerolineas
 * @param PPUL Precio Por Unidad latam
 * @param kmts Kilometros
 * @param latam Precio base latam
 * @param aerolineas Precio base aerolineas
 * @param diferencia Diferencia de precios base de aerolineas y latam
 */
void showResults(float debitoA, float debitoL, float creditoA, float creditoL, float BTCA, float BTCL, float PPUA, float PPUL,
		int kmts, float latam, float aerolineas, float diferencia);				//menu4) imprime resultados




/**
 * simula que se ingresaron datos especificos y los muestra. datos:
 *  Km: 7090
 * Aerolineas Argentinas: $162965
 * Latam: $ 159339
 *
 * @param precioBTC Precio del bitcoin
 *
 */
void forceData(float precioBTC);




#endif /* TP1_H_ */
