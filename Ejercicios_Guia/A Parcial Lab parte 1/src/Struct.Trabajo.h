#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_TRABAJO_H_
#define STRUCT_TRABAJO_H_
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;
typedef struct
{
	int id;
	int marcaBicicleta;
	int rodadoBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;

} eTrabajo;
//***
/**
 * @fn int eTrabajo_BuscarPorID(eTrabajo[], int, int)
 * @brief  Busca el id ingresado por parametro con el id del array de trabajo
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 * @param ID id que ingresa por parametro para comparar con los id de trabajos
 * @return devuelve la posicion de donde se cumplio la condicion o -1 si no hay se cumple la condicion
 */
int eTrabajo_BuscarPorID(eTrabajo pListaTrabajo[], int tTrabajo, int ID);
/**
 * @fn void eTrabajo_ValidarId(eTrabajo[], int, char[], int*)
 * @brief Busca la id menor y mayor, cuando lo encuentra pide el numero con rango
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 * @param mensaje. Mensaje que se usa en la funcion pedir numero
 * @param pResultado. Puntero donde se va a guardar el numero ingresado
 */
void eTrabajo_ValidarId(eTrabajo pListaTrabajo[], int tTrabajo, char mensaje[], int* pResultado);
/**
 * @fn void eTrabajo_Inicializar(eTrabajo[], int)
 * @brief Inicializa el array en -1
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 */
void eTrabajo_Inicializar(eTrabajo pListaTrabajo[], int tTrabajo);

/**
 * @fn int eTrabajo_ObtenerIndexLibre(eTrabajo[], int)
 * @brief Busca un espacio libre adentro del array
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 * @return devuelve la posicion del espacio libre, sino devuelve -1.
 */
int eTrabajo_ObtenerIndexLibre(eTrabajo pListaTrabajo[], int tTrabajo);

#endif /* STRUCT_TRABAJO_H_ */
