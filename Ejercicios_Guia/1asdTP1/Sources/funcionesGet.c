#include <stdio.h>

int getIntValidacion(char mensajeIngreso[], char errorIngreso[], int maximo, int minimo)
{
	long long int numero;

	printf("\n%s",mensajeIngreso);
	scanf("%lld",&numero);

	while (numero < minimo || numero > maximo)
	{
		printf("\n%s",errorIngreso);
		__fpurge(stdin); //Se realiza fpurge porque al ingresar un valor no númerico, quedaba en un bucle infinito.
		scanf("%lld",&numero);
	}

	return numero;
}

long long int getInt(char mensajeIngreso[])
{
	long long int numero;

	printf("\n%s",mensajeIngreso);
	scanf("%lld",&numero);

	return numero;
}
