#include <stdio.h>
#include <stdlib.h>
#include "inc/Controller.h"
#include "inc/parser.h"
#include "inc/Vuelos.h"
#include "inc/Pilotos.h"
#include "inc/eb_INPUT.h"
#include "inc/LinkedList.h"



/** \brief Carga los datos de los Pilotos desde el archivo ingresado por el usuario (modo texto).
 *
 * \param path char*
 * \param pArrayListeVuelos LinkedList*
 * \return int
 *
 */
int controller_loadPilotosFromText(char* path , LinkedList* pArrayListPilotos)
{
	FILE* pArchivo;
	int rtn;
	rtn = FALSE;
	if(pArrayListPilotos != NULL)
	{
		//abre el archivo en modo lectura
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			rtn = parser_PilotosFromText(pArchivo, pArrayListPilotos);
			fclose(pArchivo);
		}
	}
    return rtn;
}


/** \brief Carga los datos de los Vuelos desde el archivo ingresado por el usuario (modo texto).
 *
 * \param path char*
 * \param pArrayListeVuelos LinkedList*
 * \return int
 *
 */
int controller_loadVuelosFromText(char* path , LinkedList* pArrayListVuelos)
{
	FILE* pArchivo;
	int rtn;
	rtn = FALSE;
	if(pArrayListVuelos != NULL)
	{
		//abre el archivo en modo lectura
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			rtn = parser_VuelosFromText(pArchivo, pArrayListVuelos);
			fclose(pArchivo);
		}
	}
    return rtn;
}


/** \brief Listar Vueloss
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int controller_ListVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
	eVuelos* pAuxVuelos;
	ePilotos* pAuxPilotos;
	int tVuelos;
	int tPilotos;
	int rtn;
	int i;
	int j;

	rtn = FALSE;
	tPilotos = ll_len(pArrayListPilotos);
	tVuelos = ll_len(pArrayListVuelos);
	if(tVuelos > 0)
	{
		List_Headboard();

		for(i = 0; i < tVuelos; i++)
		{
			pAuxVuelos = (eVuelos*) ll_get(pArrayListVuelos, i);

			for(j = 0; j < tPilotos; j++)
			{
				pAuxPilotos = ll_get(pArrayListPilotos, j);
				if(pAuxVuelos->idPiloto == pAuxPilotos->idPiloto)
				{
					if(controller_OneListVuelos(pAuxVuelos, pAuxPilotos) == TRUE)
					{
						rtn = TRUE;
					}
				}
			}
		}
	}

    return rtn;
}

//---------------------------------------\ * /----------------------------------------//



//List INICIO
int controller_OneListVuelos(void* pVuelo, void* pPiloto)
{
	eVuelos* pAuxVuelos;
	ePilotos* pAuxPiloto;
	pAuxVuelos = (eVuelos*) pVuelo;
	pAuxPiloto = (ePilotos*) pPiloto;
	int rtn;
	int list_idVuelos;
	int list_idAvion;
	char list_NombrePiloto[ARRAY_SIZE];
	int list_fDia;
	int list_fMes;
	int list_fAnio;
	char list_Destino[ARRAY_SIZE];
	int list_cantPasajeros;
	int list_horaDespegue;
	int list_horaLlegada;

	rtn = FALSE;

	if(eVuelos_getIdVuelo(pAuxVuelos, &list_idVuelos) &&
	eVuelos_getIdAvion(pAuxVuelos, &list_idAvion) &&
	ePilotos_getNombre(pAuxPiloto, list_NombrePiloto) &&
	eVuelos_getDia(pAuxVuelos, &list_fDia) &&
	eVuelos_getMes(pAuxVuelos, &list_fMes) &&
	eVuelos_getAnio(pAuxVuelos, &list_fAnio) &&
	eVuelos_getDestino(pAuxVuelos, list_Destino) &&
	eVuelos_getCantPasajeros(pAuxVuelos, &list_cantPasajeros) &&
	eVuelos_getHoraDespegue(pAuxVuelos, &list_horaDespegue) &&
	eVuelos_getHoraLlegada(pAuxVuelos, &list_horaLlegada))
	{
		printf("| %-11d | %-12d | %-17s | %d/%d/%-4d | %-10s | %-6d | %-6d | %-6d |\n", list_idVuelos, list_idAvion, list_NombrePiloto, list_fDia, list_fMes, list_fAnio, list_Destino, list_cantPasajeros, list_horaDespegue, list_horaLlegada);
		rtn = TRUE;
	}


	return rtn;
}
//List FIN

/** \brief Guarda la cantidad de pasajeros que hay en un elemento y retorna la cantidad
 *
 * \param pElement LinkedList*
 * \return [FALSE] si el elemento es null [CANTIDAD DE PASAJEROS] si ok
 *
 */
int controller_CantidadPasajeros(void* pElement)
{
	int rtn;
	int cantPasajeros;
	eVuelos* pAuxElement;
	pAuxElement = (eVuelos*) pElement;
	rtn = FALSE;

	if(pElement != NULL)
	{
		rtn = eVuelos_getCantPasajeros(pAuxElement, &cantPasajeros);
		if(rtn != 0)
		{
			rtn = cantPasajeros;
		}
	}

	return rtn;
}

/** \brief Guarda la cantidad de pasajeros que viajan a China en un elemento y retorna la cantidad
 *
 * \param pElement LinkedList*
 * \return [FALSE] si el elemento es null [CANTIDAD DE PASAJEROS A CHINA] si ok
 *
 */
int controller_CantidadPasajerosChina(void* pElement)
{
	int rtn;
	char auxDestino[ARRAY_SIZE];
	eVuelos* pAuxElement;
	pAuxElement = (eVuelos*) pElement;
	rtn = FALSE;

	if(pElement != NULL)
	{
		if(eVuelos_getDestino(pAuxElement, auxDestino) != FALSE)
		{
			if(strcmp(auxDestino, "China") == 0)
			{
				rtn = controller_CantidadPasajeros(pAuxElement);
			}
		}
	}

	return rtn;
}

/***/

int controller_VuelosPortugal(void* pElement)
{
	int rtn;
	char auxDestino[ARRAY_SIZE];
	eVuelos* pAuxElement;
	pAuxElement = (eVuelos*) pElement;
	rtn = 0;

	if(eVuelos_getDestino(pAuxElement, auxDestino) != FALSE)
	{
		if(strcmp(auxDestino, "Portugal") == 0)
		{
			rtn = 1;
		}
	}

	return rtn;
}

int controller_FilterPilotos(void* pElement)
{
	int rtn;
	int piloto;
	eVuelos* pAuxElement;
	pAuxElement = (eVuelos*) pElement;

	rtn = 0;
	if(eVuelos_getIdPiloto(pAuxElement, &piloto) != FALSE)
	{
		if(piloto != 1 && piloto != 2)
		{
			rtn = 1;
		}
	}

	return rtn;
}

int controller_FilterDuracionVuelo(void* pElement)
{
	int rtn;
	int horaDespegue;
	int horaLlegada;
	int duracionVuelo;
	eVuelos* pAuxElement;
	pAuxElement = (eVuelos*) pElement;
	rtn = 0;

	if(eVuelos_getHoraDespegue(pAuxElement, &horaDespegue) != FALSE)
	{
		if(eVuelos_getHoraLlegada(pAuxElement, &horaLlegada) != FALSE)
		{
			duracionVuelo = horaLlegada - horaDespegue;
			if(duracionVuelo > 5)
			{
				rtn = 1;
			}
		}
	}

	return rtn;
}

LinkedList* controller_ListVuelosDuracionVuelo(LinkedList* this)
{
	LinkedList* this2;
	this2 = ll_newLinkedList();
	if(this != NULL && this2 != NULL)
	{
		this2 = ll_filter(this, controller_FilterDuracionVuelo);
	}

	return this2;
}

LinkedList* controller_ListVuelosPilotos(LinkedList* this)
{
	LinkedList* this2;
	this2 = ll_newLinkedList();
	if(this != NULL && this2 != NULL)
	{
		this2 = ll_filter(this, controller_FilterPilotos);
	}


	return this2;
}

LinkedList* controller_ListVuelosPortugal(LinkedList* this)
{
	LinkedList* this2;
	this2 = ll_newLinkedList();
	if(this != NULL && this2 != NULL)
	{
		this2 = ll_filter(this, controller_VuelosPortugal);
	}


	return this2;
}

int controller_saveAsText(char* path , LinkedList* pArrayListVuelos)
{
	FILE* pArchivo;
	eVuelos* pAuxVuelos;
	int rtn;
	int i;
	int idVuelos;
	int idAvion;
	int idPiloto;
	int fDia;
	int fMes;
	int fAnio;
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;
	char destino[ARRAY_SIZE];
	int tVuelos;

	rtn = FALSE;
	pArchivo = fopen(path, "w");

	if(pArchivo != NULL && pArrayListVuelos != NULL)
	{
		tVuelos = ll_len(pArrayListVuelos);

		if(tVuelos == 0)
		{
			printf("\n[ERROR] NO SE PUEDE GUARDAR SI NO HAY AL MENOS 1 VUELO CARGADO.\n");
		}else
		{
			fprintf(pArchivo, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");

			for(i = 0; i < tVuelos; i++)
			{
				pAuxVuelos = (eVuelos*) ll_get(pArrayListVuelos, i);

				if(eVuelos_getIdVuelo(pAuxVuelos, &idVuelos) &&
				eVuelos_getIdAvion(pAuxVuelos, &idAvion) &&
				eVuelos_getIdPiloto(pAuxVuelos, &idPiloto) &&
				eVuelos_getDia(pAuxVuelos, &fDia) &&
				eVuelos_getMes(pAuxVuelos, &fMes) &&
				eVuelos_getAnio(pAuxVuelos, &fAnio) &&
				eVuelos_getDestino(pAuxVuelos, destino) &&
				eVuelos_getCantPasajeros(pAuxVuelos, &cantPasajeros) &&
				eVuelos_getHoraDespegue(pAuxVuelos, &horaDespegue) &&
				eVuelos_getHoraLlegada(pAuxVuelos, &horaLlegada))
				{
					fprintf(pArchivo, "%d,%d,%d,%d/%d/%d,%s,%d,%d,%d,\n", idVuelos, idAvion, idPiloto, fDia, fMes, fAnio, destino, cantPasajeros, horaDespegue, horaLlegada);
				}


			}
			rtn = TRUE;
		}
	}

	fclose(pArchivo);

	return rtn;
}
