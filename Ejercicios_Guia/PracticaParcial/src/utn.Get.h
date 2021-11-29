#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Struct.General.h"

#ifndef UTN_GET_H_
#define UTN_GET_H_

/******/
//void Producto_GetId(eProducto pListaProducto[], int tProducto, char mensaje[], int* pResultado);


int Confirmar_Respuesta(char mensaje[]);
void get_Tipo(char pTipo[], char mensaje[]);
void get_Sexo(char* pSexo, char mensaje[]);
void get_Nombre(char* nombre, int tResultado, char mensaje[]);
void get_Descripcion(char pResultado[], int tResultado, char mensaje[]);
void get_Apellido(char* apellido, int TAM);
void concatenar_NombreApellido(char nombreCompleto[], char cadenaApellido[], char cadenaNombre[]);
void getChar(char* letra, char mensaje[]);
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
