#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#ifndef UTN_GET_H_
#define UTN_GET_H_

int Confirmar_Respuesta(char mensaje[], char mensajeError[]);
void myGets(char [], int , char []);
void getInt(int*, char []);
void utn_getNumero(int*, char [], int , int );
void getFloat(float*, char []);
void utn_getNumeroFlotante(float*, char [], float , float );

int esNumerica(char []);
int esFlotante(char []);
int esCaracterConEspacio(char []);
int esCaracter(char []);

#endif /* UTN_GET_H_ */

