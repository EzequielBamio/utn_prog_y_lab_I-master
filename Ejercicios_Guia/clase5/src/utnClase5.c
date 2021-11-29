/*
 * utnClase5.c
 *
 *  Created on: 29 mar. 2021
 *      Author: ezequ
 */

#include "utnClase5.h"
//Listado de los números de las posiciones impares.
void MostrarNumerosImpares(int numeros[], int cantidad)
{
	int i;
	int esImpar;

	for(i = 0; i < cantidad; i++)
	{
		esImpar = ValidarParidad(numeros[i]);
		if(esImpar == 0)
		{
			printf("%d. Los numeros impares son: %d\n", i, numeros[i]);
		}
	}

}
//Listado de los números pares.
void MostrarNumerosPares(int numeros[], int cantidad)
{
	int i;
	int esPar;

	for(i = 0; i < cantidad; i++)
	{
		esPar = ValidarParidad(numeros[i]);
		if(esPar == 1)
		{
			printf("Los numeros Pares son: %d\n", numeros[i]);
		}
	}

}
//Listado de los números ingresados.
void MostrarNumerosIngresados(int numeros[], int cantidad)
{
	int i;

	for(i = 0; i < cantidad; i++)
	{
		printf("Los numeros ingresados son: %d\n", numeros[i]);
	}
}


//El mayor de los impares.
int MayorImpares(int numeros[], int cantidad)
{
	int i;
	int mayorImpar;
	int esImpar;

	mayorImpar = -1;

	for(i = 0; i < cantidad; i++)
	{
		esImpar = ValidarParidad(numeros[i]);
		if(numeros[i] > mayorImpar || i == 0)
		{
			if(esImpar == 0)
			{
				mayorImpar = numeros[i];
			}
		}
	}

	return mayorImpar;
}
//Sumatoria de los pares.
int SumarPares(int numeros[], int cantidad)
{
	int i;
	int acumuladorPar;
	int esPar;

	acumuladorPar = 0;

	for(i = 0; i < cantidad; i++)
	{
		esPar = ValidarParidad(numeros[i]);
		if(esPar == 1)
		{
			acumuladorPar += numeros[i];
		}
	}

	return acumuladorPar;
}
//Cantidad de negativos
int ContadorNegativos(int numeros[], int cantidad)
{
	int i;
	int valor;
	int contadorNegativos;
	contadorNegativos = 0;

	for(i = 0; i < cantidad; i++)
	{
		valor = EsPositivo(numeros[i]);
		if(valor == -1)
		{
			contadorNegativos++;
		}
	}
	return contadorNegativos;
}
//Cantidad de positivos
int ContadorPositivos(int numeros[], int cantidad)
{
	int i;
	int valor;
	int contadorPositivos;
	contadorPositivos = 0;

	for(i = 0; i < cantidad; i++)
	{
		valor = EsPositivo(numeros[i]);
		if(valor == 1)
		{
			contadorPositivos++;
		}
	}
	return contadorPositivos;
}

//EsPositivo{ 1: positivo 0: cero  -1: negativo}
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
//ValidarParidad{ 1: par 0 impar}
int ValidarParidad(int numero)
{
	int resultado;

	if(numero % 2 == 0)
	{
		resultado = 1;
	}else
	{
		resultado = 0;
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
