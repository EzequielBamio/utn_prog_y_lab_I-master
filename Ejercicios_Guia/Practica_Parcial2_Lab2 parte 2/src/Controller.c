#include <stdio.h>
#include <stdlib.h>
#include "inc/Controller.h"
#include "inc/parser.h"
#include "inc/Vuelos.h"
#include "inc/Aviones.h"
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

/** \brief Carga los datos de los Aviones desde el archivo ingresado por el usuario (modo texto).
 *
 * \param path char*
 * \param pArrayListeVuelos LinkedList*
 * \return int
 *
 */
int controller_loadAvionesFromText(char* path , LinkedList* pArrayListAviones)
{
	FILE* pArchivo;
	int rtn;
	rtn = FALSE;
	if(pArrayListAviones != NULL)
	{
		//abre el archivo en modo lectura
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			rtn = parser_AvionesFromText(pArchivo, pArrayListAviones);
			fclose(pArchivo);
		}
	}
    return rtn;
}

/** \brief Listar Vuelos
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int controller_ListVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos, LinkedList* pArrayListAviones)
{
	eVuelos* pAuxVuelos;
	ePilotos* pAuxPilotos;
	eAviones* pAuxAviones;
	int tVuelos;
	int idAux;
	int rtn;
	int i;

	rtn = FALSE;
	tVuelos = ll_len(pArrayListVuelos);

	if(tVuelos > 0)
	{
		List_Headboard();

		for(i = 0; i < tVuelos; i++)
		{
			pAuxVuelos = (eVuelos*) ll_get(pArrayListVuelos, i);
			eVuelos_getIdPiloto(pAuxVuelos, &idAux);
			pAuxPilotos	= ePilotos_BuscarID(pArrayListPilotos, idAux);
			eVuelos_getIdAvion(pAuxVuelos, &idAux);
			pAuxAviones = eAviones_BuscarID(pArrayListAviones, idAux);
			if(pAuxPilotos != NULL && pAuxAviones != NULL)
			{
				if(controller_OneListVuelos(pAuxVuelos, pAuxPilotos, pAuxAviones) == TRUE)
				{
					rtn = TRUE;
				}
			}
		}
	}

    return rtn;
}

/** \brief Ordenar vuelos
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int controller_sortVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos, LinkedList* pArrayListAviones)
{
	int rtn;
	int opcion;
	int criterio;
	rtn = FALSE;

	if(ll_len(pArrayListVuelos) > 0)
	{
		eb_getNumero(&opcion, "[ORDENAR] INGRESE COMO DESEA FILTRAR LA LISTA: \n[*] (1) ID \n[*] (2) DESTINO \n[*] (3) FECHA(dia) \n\n[*] 0. SALIR \n->  ", 0, 3);
		if(opcion != 2)
		{
			eb_getNumero(&criterio, "[*] INGRESE EL ORDEN:\n[*] (0) MAYOR A MENOR \n[*] (1) MENOR A MAYOR \n-> ", 0, 1);
		}else
		{
			eb_getNumero(&criterio, "[*] INGRESE EL ORDEN:\n[*] (0) A-Z \n[*] (1) Z-A \n-> ", 0, 1);
		}
		switch(opcion)
		{
		case 0:

			//SALIR
			break;
		case 1:
			printf("[*] UN MOMENTO, SE ESTA ORDENANDO...");
			ll_sort(pArrayListVuelos, controller_sortID, criterio);
			break;
		case 2:
			printf("[*] UN MOMENTO, SE ESTA ORDENANDO...");
			ll_sort(pArrayListVuelos, controller_sortDestino, criterio);
			break;
		case 3:
			printf("[*] UN MOMENTO, SE ESTA ORDENANDO...");
			ll_sort(pArrayListVuelos, controller_sortFecha, criterio);
			break;
		}

		if(opcion != 0)
		{
			rtn = TRUE;
		}
	}

	return rtn;
}

/** \brief Guarda los datos de los vuelos en el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
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


//---------------------------------------\ * /----------------------------------------//


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

//List INICIO
int controller_OneListVuelos(void* pVuelo, void* pPiloto, void* pAviones)
{
	eVuelos* pAuxVuelos;
	ePilotos* pAuxPiloto;
	eAviones* pAuxAviones;
	pAuxVuelos = (eVuelos*) pVuelo;
	pAuxPiloto = (ePilotos*) pPiloto;
	pAuxAviones = (eAviones*) pAviones;

	int list_idVuelos;
	char list_ModeloAvion[ARRAY_SIZE];
	char list_NombrePiloto[ARRAY_SIZE];
	char list_Destino[ARRAY_SIZE];
	int list_fDia;
	int list_fMes;
	int list_fAnio;
	int list_cantPasajeros;
	int list_horaDespegue;
	int list_horaLlegada;
	int rtn;
	rtn = FALSE;

	if(eVuelos_getIdVuelo(pAuxVuelos, &list_idVuelos) &&
	eAviones_getModelo(pAuxAviones, list_ModeloAvion) &&
	ePilotos_getNombre(pAuxPiloto, list_NombrePiloto) &&
	eVuelos_getDia(pAuxVuelos, &list_fDia) &&
	eVuelos_getMes(pAuxVuelos, &list_fMes) &&
	eVuelos_getAnio(pAuxVuelos, &list_fAnio) &&
	eVuelos_getDestino(pAuxVuelos, list_Destino) &&
	eVuelos_getCantPasajeros(pAuxVuelos, &list_cantPasajeros) &&
	eVuelos_getHoraDespegue(pAuxVuelos, &list_horaDespegue) &&
	eVuelos_getHoraLlegada(pAuxVuelos, &list_horaLlegada))
	{
		printf("| %-11d | %-12s | %-17s | %d/%d/%-4d | %-10s | %-6d | %-6d | %-6d |\n", list_idVuelos, list_ModeloAvion, list_NombrePiloto, list_fDia, list_fMes, list_fAnio, list_Destino, list_cantPasajeros, list_horaDespegue, list_horaLlegada);
		rtn = TRUE;
	}


	return rtn;
}
//List FIN

//Sort INICIO
int controller_sortID(void* pElement1 ,void* pElement2)
{
	int rtn;
	int idVuelos1;
	int idVuelos2;
	eVuelos* pAuxVuelos1;
	eVuelos* pAuxVuelos2;

	pAuxVuelos1 = (eVuelos*) pElement1;
	pAuxVuelos2 = (eVuelos*) pElement2;

	eVuelos_getIdVuelo(pAuxVuelos1, &idVuelos1);
	eVuelos_getIdVuelo(pAuxVuelos2, &idVuelos2);

	if(idVuelos1 > idVuelos2)
	{
		rtn = TRUE;
	}else
	{
		if(idVuelos1 < idVuelos2)
		{
			rtn = FALSE;
		}else
		{
			rtn = NO;
		}
	}

	return rtn;
}

int controller_sortDestino(void* pElement1 ,void* pElement2)
{
	int rtn;
	char DestinoVuelos1[ARRAY_SIZE];
	char DestinoVuelos2[ARRAY_SIZE];
	eVuelos* pAuxVuelos1;
	eVuelos* pAuxVuelos2;

	pAuxVuelos1 = (eVuelos*) pElement1;
	pAuxVuelos2 = (eVuelos*) pElement2;

	eVuelos_getDestino(pAuxVuelos1, DestinoVuelos1);
	eVuelos_getDestino(pAuxVuelos2, DestinoVuelos2);

	if(strcmp(DestinoVuelos1, DestinoVuelos2) < 0)
	{
		rtn = TRUE;
	}else
	{
		if(strcmp(DestinoVuelos1, DestinoVuelos2) > 0)
		{
			rtn = FALSE;
		}else
		{
			rtn = NO;
		}
	}

	return rtn;
}

int controller_sortFecha(void* pElement1 ,void* pElement2)
{
	int rtn;
	int FechaVueloA;
	int FechaVueloB;
	eVuelos* pAuxVuelos1;
	eVuelos* pAuxVuelos2;

	pAuxVuelos1 = (eVuelos*) pElement1;
	pAuxVuelos2 = (eVuelos*) pElement2;

	eVuelos_getDia(pAuxVuelos1, &FechaVueloA);
	eVuelos_getDia(pAuxVuelos2, &FechaVueloB);

	if(FechaVueloA > FechaVueloB)
	{
		rtn = TRUE;
	}else
	{
		if(FechaVueloA < FechaVueloB)
		{
			rtn = FALSE;
		}else
		{
			rtn = NO;
		}
	}

	return rtn;
}
//Sort FIN

