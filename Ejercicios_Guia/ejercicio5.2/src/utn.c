/*
 * utn.c
 *
 *  Created on: 30 mar. 2021
 *      Author: ezequ
 */

#include "utn.h"


//Listado de los números ingresados.
void MostrarNumerosIngresados(int numero[], int cantidad)
{
	int i;

	for(i = 0; i < cantidad; i++)
	{
		printf("Los numeros son: %d", numero[i]);
	}
}
//Listado de los números pares.
void MostrarNumerosIngresados(int numero[], int cantidad)
{
	int i;
	int esPar;

	for(i = 0; i < cantidad; i++)
	{
		esPar = ValidarParidad(numero[i]);
		if(esPar == 1)
		{
			printf("Los numeros Pares son: %d", numero[i]);
		}
	}
}
//Listado de los números de las posiciones impares.
void MostrarNumerosIngresados(int numero[], int cantidad)
{
	int i;
	int esImpar;

	for(i = 0; i < cantidad; i++)
	{
		esImpar = ValidarParidad(numero[i]);
		if(esImpar == 0)
		{
			printf("%d. Los numeros Impares son: %d", i, numero[i]);
		}
	}
}


//El mayor de los impares.
int MayorImpar(int numero[], int cantidad)
{
	int mayorImpar;
	int esImpar;
	int i;

	mayorImpar = -1;

	for(i = 0; i < cantidad; i++)
	{
		esImpar = ValidarParidad(numero[i]);
		if(numero[i] > mayorImpar || i == 0)
		{
			if(esImpar == 0)
			{
				mayorImpar = numero[i];
			}
		}
	}

	return mayorImpar;
}
//Sumatoria de los pares.
int SumarPares(int numero[], int cantidad)
{
	int i;
	int acumuladorPares;
	int esPar;
	acumuladorPares = 0;
	for(i = 0; i < cantidad; i++)
	{
		esPar = ValidarParidad(numero[i]);
		if(esPar == 1)
		{
			acumuladorPares += numero[i];
		}
	}

	return acumuladorPares;
}

//Cantidad de negativos.
int CantidadNegativos(int numero[], int cantidad)
{
	int i;
	int contadorNegativos;
	int negativo;
	contadorNegativos = 0;

	for(i = 0; i < cantidad; i++)
	{
		negativo = EsPositivo(numero[i]);

		if(negativo == -1)
		{
			contadorNegativos++;
		}
	}

	return contadorNegativos;
}
//Cantidad de positivos.
int CantidadPositivos(int numero[], int cantidad)
{
	int i;
	int contadorPositivos;
	int positivo;
	contadorPositivos = 0;

	for(i = 0; i < cantidad; i++)
	{
		positivo = EsPositivo(numero[i]);
		if(positivo == 1)
		{
			contadorPositivos++;
		}
	}

	return contadorPositivos;
}

//ValidarPariedad: 1: Par 0: Impar
int ValidarParidad(int numero)
{
	int resultado;
	resultado = 0;

	if(numero % 2 == 0)
	{
		resultado = 1;
	}

	return resultado;
}


//EsPositivo: 1: Positivo 0: cero -1: Negativo
int EsPositivo(int numero)
{
	int resultado;
	resultado = 0;

	if(numero > 0)
	{
		resultado = 1;
	}else
	{
		resultado = -1;
	}

	return resultado;
}

void CargarNumeros(int numero[], int cantidad)
{

	int i;


	for(i = 0; i < cantidad; i++)
	{
		numero[i] = PedirEntero("Ingrese un numero", "Error. ingrese un numero", -1000, 1000);

	}

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

