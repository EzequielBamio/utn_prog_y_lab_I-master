/*
 * utnClase5.c
 *
 *  Created on: 2 abr. 2021
 *      Author: ezequ
 */

#include "utnClase5.h"

int SumarAntecesores(int numero)
{
	int i;
	int acumuladorAntecesores;
	acumuladorAntecesores = 0;


	for(i = numero+1; i < 0; i++)
	{
		acumuladorAntecesores += i;
	}

	return acumuladorAntecesores;
}

int MenorNegativo(int numeros[], int cantidad)
{
	int i;
	int negativo;
	int menorNegativo;

	for(i = 0; i < cantidad; i++)
	{
		negativo = EsPositivo(numeros[i]);
		if(menorNegativo > numeros[i] || i == 0)
		{
			if(negativo == -1)
			{
				menorNegativo = numeros[i];
			}
		}
	}

	return menorNegativo;
}
int PromedioPositivos(int numeros[], int cantidad)
{
	int i;
	int positivo;
	int acumuladorPositivos;
	int promedioPositivos;
	acumuladorPositivos = 0;

	for(i = 0; i < cantidad; i++)
	{
		positivo = EsPositivo(numeros[i]);
		if(positivo == 1)
		{
			acumuladorPositivos += numeros[i];
		}
	}

	promedioPositivos = acumuladorPositivos / cantidad;

	return promedioPositivos;
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

int PedirNumeroDistinto(char mensaje[], char mensajeError[], int numero)
{
	int numeroIngresado;

	printf("%s ", mensaje);
	scanf("%d", &numeroIngresado);
	while(numeroIngresado == numero)
	{
		printf("%s ", mensajeError);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}


int PedirEntero(char mensaje [], char mensajeError[], int minimo, int maximo)
{
	int numeroIngresado;
	printf("%s ", mensaje);
	scanf("%d", &numeroIngresado);

	while (numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("%s ", mensajeError);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}
