/*
 ============================================================================
Ejercicio 2-2:
Realizar un programa que permita el ingreso de 10 números enteros.
Determinar el promedio de los positivos, la cantidad de ceros y del menor de
los negativos la suma de los antecesores.
Nota:
Utilizar la función del punto anterior y desarrollar funciones para resolver los
procesos que están resaltados.
 ============================================================================
 */

#include <stdlib.h>
#include "utnrepaso.h"

int main(void) {

	int i;
	int numeroIngresado;
	int numero;
	float promedio;
	int contadorCeros;
	int sumaAntecesores;
	int acumuladorPositivos;
	contadorCeros = 0;
	acumuladorPositivos = 0;

	for(i = 0; i < 5; i++)
	{
		printf("Ingrese un numero \n");
		scanf("%d", &numeroIngresado);
		numero = NumeroPositivoNegativo0(numeroIngresado);

		switch(numero)
		{
		case 1:
			acumuladorPositivos += numero;
			break;
		case 0:

			contadorCeros++;

			break;
		case -1:
			sumaAntecesores += SumarAntecesoresNegativos(numeroIngresado);
			break;
		}
	}

	promedio = promedioPositivos(acumuladorPositivos);


	printf("La promedio de los positivos es %.2f\n", promedio);
	printf("La cantidad de 0 es %d\n", contadorCeros);
	printf("La suma de los antecesores %d\n", sumaAntecesores);


	return EXIT_SUCCESS;
}
