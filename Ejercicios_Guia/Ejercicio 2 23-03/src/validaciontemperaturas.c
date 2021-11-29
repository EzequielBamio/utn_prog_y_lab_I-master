/*
 * validacion.c
 *
 *  Created on: 23 mar. 2021
 *      Author: ezequ
 */
#include "validaciontemperaturas.h"

float ValidarTemperatura(char mensaje [], char mensajeError[], float minimo, float maximo)
{
	float numeroIngresado;
	printf("%s\n", mensaje);
	scanf("%f", &numeroIngresado);

	while (numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("%s\n", mensajeError);
		scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}

