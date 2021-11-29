#include "Struct.Servicio.h"
#include "Struct.Trabajo.h"
#include "Struct.Bicicleta.h"
#include "utn.Get.h"

#ifndef STRUCT_GENERAL_H_
#define STRUCT_GENERAL_H_
typedef struct
{
	int id;
	int contador;

}eAuxiliar;

//j inicio

int eTrabajos_CantidadBicicletasRojo(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta);

//j fin
void eServicios_MostrarUnListadoServicioConBicicleta(eTrabajo pListaTrabajo, eServicio pListaServicio, eBicicleta pListaBicicleta);
void eServicios_MostrarTodosListadoServicioConBicicleta(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta);

//H INICIO

void aux_Inicializar(eAuxiliar auxiliar[], eServicio pListaServicio[], int tServicio);

int aux_BuscarId(eAuxiliar auxiliar[], int tAuxiliar, int id);

void aux_Contador(eTrabajo pListaTrabajo[], int tTrabajo, eAuxiliar auxiliar[], eServicio pListaServicio[], int tServicio);

int aux_calcularMaximo(eAuxiliar auxiliar[], int tAuxiliar);

void aux_MostrarMayor(eAuxiliar auxiliar[], eServicio pListaServicio[], int tServicio, int maximo);

int eTrabajo_ConMasServiciosPrestados(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio);

//H FIN


void eTrabajo_OrdenamientoMarcaBicicleta(eTrabajo pListaTrabajo[], int tTrabajo, eBicicleta pListaBicicleta[], int tBicicleta);

// FUNCIONES TRABAJO - INICIO
/**
 * @fn int eTrabajo_Ordenamiento(eTrabajo[], int)
 * @brief Ordena los trabajos por anio, si hay varios anios iguales, los ordena por marca
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 */
void eTrabajo_Ordenamiento(eTrabajo pListaTrabajo[], int tTrabajo, eBicicleta pListaBicicleta[], int tBicicleta);


/**
 * @fn void eTrabajo_MostrarUno(eTrabajo)
 * @brief Muestra un trabajo si el estado es ocupado.
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 */
void eTrabajo_MostrarUno(eTrabajo pListaTrabajo, eServicio pListaServicio, eBicicleta pListaBicicleta);
/**
 * @fn int eTrabajo_MostrarTodos(eTrabajo[], int, eServicio[], int)
 * @brief Muestra todos los trabajos cargados, que su estado sea ocupado
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @return devuelve 1 si hay trabajos para mostrar, 0 si no hay nada cargado
 */
int eTrabajo_MostrarTodos(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta);
/**
 * @fn int eTrabajo_Baja(eTrabajo[], int, eServicio[], int)
 * @brief Da de baja un trabajo
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @return devuelve 1 si se elimino, 0 si se cancelo la baja
 */
int eTrabajo_Baja(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta);
/**
 * @fn int eTrabajo_Modificar(eTrabajo[], int, eServicio[], int)
 * @brief Modifica una marca o un servicio del array trabajo
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @return Devuelve 1 si se modifico, 0 si se cancelo la modificacion
 */
int eTrabajo_Modificar(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta);
/**
 * @fn eTrabajo eTrabajo_CargarDatos(eServicio[], int)
 * @brief Pide los datos a cargar en el array trabajo
 *
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @return Devuelve un array cargado del tipo de dato eTrabajo
 */
eTrabajo eTrabajo_CargarDatos(eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta);
/**
 * @fn int eTrabajo_Alta(eTrabajo[], int, eServicio[], int, int*)
 * @brief
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @param id. variable id para incrementar automaticamente
 * @return devuelve 1 si se cargaron los datos, 0 si no hay espacio en el array
 */
int eTrabajo_Alta(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta, int* id);

// FUNCIONES TRABAJO - FIN

/**
 * @fn int Total_ServiosPrestados(eServicio[], int, eTrabajo[], int)
 * @brief Suma los precios por los servicios cargados en el array de trabajo
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 * @param tTrabajo Tamanio del array
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @return Devuelve el precio total de los servicios prestados
 */
int Total_ServiciosPrestados(eServicio pListaServicio[], int tServicio, eTrabajo pListaTrabajo[], int tTrabajo);

#endif /* STRUCT_GENERAL_H_ */
