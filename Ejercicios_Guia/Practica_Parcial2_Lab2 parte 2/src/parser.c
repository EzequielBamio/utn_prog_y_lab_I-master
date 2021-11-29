#include <stdio.h>
#include <stdlib.h>
#include "inc/parser.h"
#include "inc/Vuelos.h"
#include "inc/Pilotos.h"
#include "inc/Aviones.h"
#include "inc/eb_INPUT.h"
#include "inc/LinkedList.h"

/** \brief Parsea los datos los datos de los Aviones desde el archivo ingresado por el usuario (modo texto).
 *
 * \param path char*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int parser_AvionesFromText(FILE* pArchivo, LinkedList* pArrayListAviones)
{
	eAviones* pAuxAviones;

	int rtn;
	char id[ARRAY_SIZE];
	char marca[ARRAY_SIZE];
	char cantButacas[ARRAY_SIZE];

	rtn = FALSE;

	if(pArchivo != NULL && pArrayListAviones != NULL)
	{

		//falsa lectura
		fscanf(pArchivo, "%[^,], %[^,], %[^\n]\n", id, marca, cantButacas);

		//Mientras no sea el final del archivo
		while(!feof(pArchivo))
		{
			pAuxAviones = eAviones_new();

			fscanf(pArchivo, "%[^,], %[^,], %[^\n]\n", id, marca, cantButacas);
			pAuxAviones = eAviones_newParametros(id, marca, cantButacas);

			ll_add(pArrayListAviones, pAuxAviones);

		}
		rtn = TRUE;
	}

    return rtn;
}

/** \brief Parsea los datos los datos de los Pilotos desde el archivo ingresado por el usuario (modo texto).
 *
 * \param path char*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */

int parser_PilotosFromText(FILE* pArchivo, LinkedList* pArrayListPilotos)
{
	ePilotos* pAuxPilotos;

	int rtn;
	char id[ARRAY_SIZE];
	char nombre[ARRAY_SIZE];

	rtn = FALSE;

	if(pArchivo != NULL && pArrayListPilotos != NULL)
	{

		//falsa lectura
		fscanf(pArchivo, "%[^,], %[^\n]\n", id, nombre);

		//Mientras no sea el final del archivo
		while(!feof(pArchivo))
		{
			pAuxPilotos = ePilotos_new();

			fscanf(pArchivo, "%[^,], %[^\n]\n", id, nombre);

			pAuxPilotos = ePilotos_newParametros(id, nombre);

			ll_add(pArrayListPilotos, pAuxPilotos);

		}
		rtn = TRUE;
	}

    return rtn;
}

/** \brief Parsea los datos los datos de los Vuelos desde el archivo ingresado por el usuario (modo texto).
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */

int parser_VuelosFromText(FILE* pArchivo, LinkedList* pArrayListVuelos)
{
	eVuelos* pAuxVuelos;

	int rtn;
	char idVuelo[ARRAY_SIZE];
	char idAvion[ARRAY_SIZE];
	char idPiloto[ARRAY_SIZE];
	char fFecha[ARRAY_SIZE];
	char destino[ARRAY_SIZE];
	char cantPasajeros[ARRAY_SIZE];
	char horaDespegue[ARRAY_SIZE];
	char horasLlegada[ARRAY_SIZE];

	rtn = FALSE;

	if(pArchivo != NULL && pArrayListVuelos != NULL)
	{

		//falsa lectura
		fscanf(pArchivo, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idVuelo, idAvion, idPiloto, fFecha, destino, cantPasajeros, horaDespegue, horasLlegada);

		//Mientras no sea el final del archivo
		while(!feof(pArchivo))
		{

				pAuxVuelos = eVuelos_new();

				fscanf(pArchivo, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idVuelo, idAvion, idPiloto, fFecha, destino, cantPasajeros, horaDespegue, horasLlegada);

				pAuxVuelos = eVuelos_newParametros(idVuelo, idAvion, idPiloto, fFecha, destino, cantPasajeros, horaDespegue, horasLlegada);

				ll_add(pArrayListVuelos, pAuxVuelos);
		}
		rtn = TRUE;
	}


    return rtn;
}

/** \brief Parsea la fecha ingresado por el usuario (modo texto).
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int parser_Fecha(char* fecha, int* fDia, int* fMes, int* fAnio)
{
	int rtn;
	rtn = FALSE;
	if(fecha != NULL)
	{
		sscanf(fecha, "%d/%d/%d", fDia, fMes, fAnio);
		rtn = TRUE;
	}

	return rtn;
}
