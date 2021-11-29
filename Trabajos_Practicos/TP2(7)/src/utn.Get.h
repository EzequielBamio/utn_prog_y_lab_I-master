#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef UTN_GET_H_
#define UTN_GET_H_

/******/

/**
 * @fn int eTrabajo_ObtenerID(int*)
 * @brief Incrementa la variable +1
 *
 * @param id. variable a la cual se le va a incrementar 1
 * @return devuelve la variable +1
 */
int utn_ObtenerID(int* );
int Confirmar_Respuesta(char []);
void get_Tipo(char [], char []);
void get_Sexo(char* , char []);
void get_String(char [], int , char [], char []);
void concatenar_NombreApellido(char [], char [], char []);
void getChar(char* , char []);
void myGets(char [], int , char []);
void getInt(int*, char []);
void utn_getNumero(int*, char [], int , int );
void getFloat(float*, char []);
void utn_getNumeroFlotante(float*, char [], float , float );

int esNumerica(char []);
int esFlotante(char []);
int esCaracterConEspacio(char []);
int esCaracter(char pResultado[]);
#endif /* UTN_GET_H_ */
