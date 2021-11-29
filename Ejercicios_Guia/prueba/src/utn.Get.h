#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#ifndef UTN_GET_H_
#define UTN_GET_H_

void getInt(int* pResultado, char* mensaje);
void getFloat(float* pResultado, char* mensaje);
void utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
void utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);
void myGets(char* cadena, int longitud, char* mensaje);

#endif /* UTN_GET_H_ */

