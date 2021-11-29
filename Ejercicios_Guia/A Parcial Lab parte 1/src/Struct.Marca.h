#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_MARCA_H_
#define STRUCT_MARCA_H_

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct
{
	int id;
	char descripcion[MAX_CHARS_CADENAS];
	int isEmpty;

} eMarca;

/**
 * @fn void eMarca_Inicializar(eMarca[], int)
 * @brief Inicializa el array en -1
 *
 * @param pListaMarca Array de trabajo con el tipo de dato eMarca
 * @param tMarca Tamanio del array
 */
void eMarca_Inicializar(eMarca pListaMarca[], int tMarca);
/**
 * @fn void eMarca_ValidarId(eMarca[], int, char[], int*)
 * @brief Busca la id menor y mayor, cuando lo encuentra pide el numero con rango
 *
 * @param pListaMarca. Array de marcas con el tipo de dato eMarcas
 * @param tMarca. Tamanio del array
 * @param mensaje. Mensaje que se usa en la funcion pedir numero
 * @param pResultado. Puntero donde se va a guardar el numero ingresado
 */
void eMarca_ValidarId(eMarca pListaMarca[], int tMarca, char mensaje[], int* pResultado);
/**
 * @fn int eMarca_BuscarPorID(eMarca[], int, int)
 * @brief Busca el id ingresado por parametro con el id del array de marcas
 *
 * @param pListaMarca. Array de marcas con el tipo de dato eMarcas
 * @param tMarca. Tamanio del array
 * @param ID. id que ingresa por parametro para comparar con los id de marcas
 * @return devuelve la posicion de donde se cumplio la condicion o -1 si no hay se cumple la condicion
 */
int eMarca_BuscarPorID(eMarca pListaMarca[], int tMarca, int ID);
/**
 * @fn void eMarca_MostrarUno(eMarca)
 * @brief Muestra un servicio que el estado sea ocupado
 *
 * @param pListaMarca. Array de marcas con el tipo de dato eMarcas
 */
void eMarca_MostrarUno(eMarca pListaMarca);
/**
 * @fn int eMarca_MostrarTodos(eMarca[], int)
 * @brief Muestra todos los marcas cargados que esten ocupados
 *
 * @param pListaMarca. Array de marcas con el tipo de dato eMarcas
 * @param tMarca. Tamanio del array
 * @return devuelve 1 si hay servicio para mostrar, 0 si no hay marcas para mostrar
 */
void eMarca_Inicializar(eMarca pListaMarca[], int tMarca);
int eMarca_MostrarTodos(eMarca pListaMarca[], int tMarca);
int eMarca_Baja(eMarca pListaMarca[], int tMarca);
int eMarca_Modificar(eMarca pListaMarca[], int tMarca);
eMarca eMarca_CargarDatos(eMarca pListaMarca[], int tMarca);
int eMarca_Alta(eMarca pListaMarca[], int tMarca, int* id);
int eMarca_ObtenerIndexLibre(eMarca pListaMarca[], int tMarca);

#endif /* STRUCT_MARCA_H_ */
