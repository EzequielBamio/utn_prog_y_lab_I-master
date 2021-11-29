#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef EB_INPUT_H_
#define EB_INPUT_H_

#define ARRAY_SIZE 100
#define TRUE 1
#define FALSE -1
#define NO 0
#define SI 1
#define SALIR 2

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

void List_Headboard();
int eb_getArchivo(char* pString, char* mensaje, int tString);


int eb_subMenu(char mensaje[]);
int eb_getIntPositive(int* pResultado, char mensaje[]);
int eb_getContinuar(char mensaje[]);
int eb_getNombre(char* pString, char* mensaje, int tString);
void eb_pulseToContinue();


/******/
//void Producto_GetId(eProducto pListaProducto[], int tProducto, char mensaje[], int* pResultado);
/**
 * @fn int eTrabajo_ObtenerID(int*)
 * @brief Incrementa la variable +1
 *
 * @param id. variable a la cual se le va a incrementar 1
 * @return devuelve la variable +1
 */
int get_Tipo(char pTipo[], char mensaje[]);
int get_Sexo(char* pSexo, char mensaje[]);
int get_String(char pResultado[], int tResultado, char mensaje[], char mensajeError[]);
int concatenar_NombreApellido(char nombreCompleto[], char cadenaApellido[], char cadenaNombre[]);
int getChar(char* , char []);
int myGets(char [], int , char []);
int getInt(int*, char []);
int eb_getNumero(int*, char [], int , int );
int getFloat(float*, char []);
int eb_getNumeroFlotante(float*, char [], float , float );

int esNumerica(char []);
int esFlotante(char []);
int esCaracterConEspacio(char []);
int esCaracter(char pResultado[]);
#endif /* EB_INPUT_H_ */
