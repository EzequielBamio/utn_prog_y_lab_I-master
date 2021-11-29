/*
 * claseSeis.c
 *
 *  Created on: 30 mar. 2021
 *      Author: ezequ
 */

#include "claseSeis.h"

void PedirCandenaCaracteres(char mensaje[], char cadena[])
{

	printf("%s", mensaje);
	scanf("%s", cadena);
}




int EsPositivo(int numero)
{
	int resultado;
	resultado = 0;

	if(numero > 0)
	{
		resultado = 1;
	}else
	{
		if(numero < 0)
		{
			resultado = -1;
		}
	}

	return resultado;
}
// Realizar un algoritmo que permita el intercambio de valores de dichas variables.

void CargarNumeros(int numero[], int cantidad)
{

	int i;


	for(i = 0; i < cantidad; i++)
	{
		numero[i] = PedirEntero("Ingrese un numero", "Error. ingrese un numero");

	}
}

int PedirEntero(char mensaje [], char mensajeError[])
{
	int numeroIngresado;
	printf("%s ", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
