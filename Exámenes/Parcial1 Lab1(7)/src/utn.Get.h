#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef UTN_GET_H_
#define UTN_GET_H_

/******/
//void Producto_GetId(eProducto pListaProducto[], int tProducto, char mensaje[], int* pResultado);
/**
 * @fn int eTrabajo_ObtenerID(int*)
 * @brief Incrementa la variable +1
 *
 * @param id. variable a la cual se le va a incrementar 1
 * @return devuelve la variable +1
 */
int utn_ObtenerID(int* id);
int Confirmar_Respuesta(char mensaje[]);
void get_Tipo(char pTipo[], char mensaje[]);
void get_Sexo(char* pSexo, char mensaje[]);
void get_String(char pResultado[], int tResultado, char mensaje[], char mensajeError[]);
void concatenar_NombreApellido(char nombreCompleto[], char cadenaApellido[], char cadenaNombre[]);
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
