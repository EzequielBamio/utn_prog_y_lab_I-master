#include "Struct.Servicio.h"
#include "Struct.Trabajo.h"
#include "Struct.Marca.h"
#include "utn.Get.h"

#ifndef STRUCT_GENERAL_H_
#define STRUCT_GENERAL_H_

typedef struct
{
	int id;
	int contador;


}eAuxiliar;

void aux_Inicializar(eAuxiliar auxiliar[], eServicio pListaServicio[], int tServicio);

int aux_BuscarId(eAuxiliar auxiliar[], int tAuxiliar, int id);

void aux_Contador(eTrabajo pListaTrabajo[], int tTrabajo, eAuxiliar auxiliar[], eServicio pListaServicio[], int tServicio);

int aux_calcularMaximo(eAuxiliar auxiliar[], int tAuxiliar);

void aux_MostrarMayor(eAuxiliar auxiliar[], eServicio pListaServicio[], int tServicio, int maximo);

int eTrabajo_ConMasServiciosPrestados(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio);



// FUNCIONES MENU - INICIO
void Sub_MenuTrabajos(eServicio pListaServicio[], int tServicio, eTrabajo pListaTrabajo[], int tTrabajo, eMarca pListaMarca[], int tMarca);
void Sub_MenuServicios(eServicio pListaServicio[], int tServicio);
void Sub_MenuMarca(eMarca pListaMarca[], int tMarca);
// FUNCIONES MENU - FIN


// FUNCIONES TRABAJO - INICIO

void eTrabajo_Ordenamiento(eTrabajo pListaTrabajo[], int tTrabajo, eMarca pListaMarca[], int tMarca);

/**
 * @fn void eTrabajo_MostrarUno(eTrabajo)
 * @brief Muestra un trabajo si el estado es ocupado.
 *
 * @param pListaTrabajo Array de trabajo con el tipo de dato eTrabajo
 */
void eTrabajo_MostrarUno(eTrabajo pListaTrabajo, eServicio pListaServicio, eMarca pListaMarc);
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
int eTrabajo_MostrarTodos(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca);
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
int eTrabajo_Baja(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca);
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
int eTrabajo_Modificar(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca);
/**
 * @fn eTrabajo eTrabajo_CargarDatos(eServicio[], int)
 * @brief Pide los datos a cargar en el array trabajo
 *
 * @param pListaServicio. Array de servicios con el tipo de dato eServicios
 * @param tServicio. Tamanio del array
 * @return Devuelve un array cargado del tipo de dato eTrabajo
 */
eTrabajo eTrabajo_CargarDatos(eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca);
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
int eTrabajo_Alta(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca, int* id);

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
int Total_ServiciosPrestados(float* totalPrecio, eServicio pListaServicio[], int tServicio, eTrabajo pListaTrabajo[], int tTrabajo);

#endif /* STRUCT_GENERAL_H_ */
