/*
 * utnClase7.c
 *
 *  Created on: 6 abr. 2021
 *      Author: ezequ
 */
#include "utnClase7.h"
#include "utn.h"
#include <string.h>

void ModificarNombre(int legajos[], char nombres[], int tam)
{
	int legajo;
	int i;
	char nuevoNombre[tam];
	int respuestaConfirmacion;

	legajo = PedirEntero("Ingrese el legajo que quiere modificar:");
		for(i=0; i<tam; i++)
		{
			while(legajo != legajos[i])
			{
				printf("\nNo se encontro el legajo\nIngrese el legajo que quiere modificar: ");
				scanf("%d", &legajo);
			}
			if(legajo == legajos[i])//lo encontre
			{
				printf("\nLegajo encontrado!\n");

				respuestaConfirmacion = ConfirmarRespuesta("Seguro que desea modificar?: 1. Si 0. No\n", "ERROR: Ingrese 1. Si 0. No\nSeguro que desea modificar?: 1. Si 0. No");
				if(respuestaConfirmacion == 1)
				{
					strncpy(nombres, nuevoNombre);

				}else
				{
				}
				break;
			}
		}
}

int ModificarNota(int legajos[], float notas[], int tam)
{
	int i;
	int legajo;
	int nuevaNota;
	int nota;
	int respuestaConfirmacion;

	legajo = PedirEntero("Ingrese el legajo que quiere modificar:");
	for(i=0; i<tam; i++)
	{
		while(legajo != legajos[i])
		{
			printf("\nNo se encontro el legajo\nIngrese el legajo que quiere modificar: ");
			scanf("%d", &legajo);
		}
		if(legajo == legajos[i])//lo encontre
		{
			printf("\nLegajo encontrado!\n");
			nuevaNota = PedirDecimal("Ingrese la nueva Nota:");
			respuestaConfirmacion = ConfirmarRespuesta("Seguro que desea modificar?: 1. Si 0. No\n", "ERROR: Ingrese 1. Si 0. No\nSeguro que desea modificar?: 1. Si 0. No");
			if(respuestaConfirmacion == 1)
			{
				nota = nuevaNota;
			}else
			{
			}
			break;
		}
	}
	return nota;
}
