#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_SERVICIO_H_
#define STRUCT_SERVICIO_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct
{
	int id;
	char descripcion[25];
	float precio;
	int isEmpty;

} eServicio;
//***
/**
 * @fn void eServicio_ValidarId(eServicio[], int, char[], int*)
 * @brief Busca la id menor y mayor, cuando lo encuentra pide el numero con rango
 *
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @param mensaje. Mensaje que se usa en la funcion pedir numero
 * @param pResultado. Puntero donde se va a guardar el numero ingresado
 */
void eServicio_ValidarId(eServicio pListaServicio[], int tServicio, char mensaje[], int* pResultado);
/**
 * @fn int eServicio_BuscarPorID(eServicio[], int, int)
 * @brief Busca el id ingresado por parametro con el id del array de servicios
 *
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @param ID. id que ingresa por parametro para comparar con los id de servicios
 * @return devuelve la posicion de donde se cumplio la condicion o -1 si no hay se cumple la condicion
 */
int eServicio_BuscarPorID(eServicio pListaServicio[], int tServicio, int ID);
/**
 * @fn void eServicio_MostrarUno(eServicio)
 * @brief Muestra un servicio que el estado sea ocupado
 *
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 */
void eServicio_MostrarUno(eServicio pListaServicio);
/**
 * @fn int eServicio_MostrarTodos(eServicio[], int)
 * @brief Muestra todos los servicios cargados que esten ocupados
 *
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @return devuelve 1 si hay servicio para mostrar, 0 si no hay servicios para mostrar
 */
int eServicio_MostrarTodos(eServicio pListaServicio[], int tServicio);


#endif /* STRUCT_SERVICIO_H_ */
