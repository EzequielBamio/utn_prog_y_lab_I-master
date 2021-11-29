/*
 * utnRepaso.c
 *
 *  Created on: 28 mar. 2021
 *      Author: ezequ
 */

#include "utnrepaso.h"

int PedirEntero(char mensaje [])
{
	int numeroIngresado;

	printf("%s \n", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}

float promedioPositivos(int numero)
{
	int promedioPositivos;

	promedioPositivos = (float) numero / 10;

	return promedioPositivos;
}

int SumarAntecesoresNegativos(int numero)
{
	int menorNegativo;
	int contadorNegativos;
	int antecesores;
	contadorNegativos = 0;
	antecesores = 0;

	menorNegativo = numero;

	if(numero < menorNegativo || contadorNegativos == 0)
	{
		antecesores = numero;

	}

	contadorNegativos++;

	return antecesores;
}



int NumeroPositivoNegativo0(int numero)
{
	int numeroIngresado;

	numeroIngresado = 0;

	if(numero > 0)
	{
		numeroIngresado = 1;
	}else
	{
		if(numero < 0)
		{
			numeroIngresado = -1;
		}
	}

	return numeroIngresado;


}
