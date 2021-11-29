/*
 * utn.Get.h
 *
 *  Created on: 14 abr. 2021
 *      Author: ezequ
 */

#ifndef UTN_GET_H_
#define UTN_GET_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int myGets(char* cadena, int longitud);

#endif /* UTN_GET_H_ */
