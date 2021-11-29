/*
 * clase5.c
 *
 *  Created on: 30 mar. 2021
 *      Author: ezequ
 */

#include "clase5.h"


int PedirEntero(char mensaje [], char mensajeError[], int distinto)
{
	int numeroIngresado;
	printf("%s ", mensaje);
	scanf("%d", &numeroIngresado);

	while (numeroIngresado == distinto)
	{
		printf("%s ", mensajeError);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}
