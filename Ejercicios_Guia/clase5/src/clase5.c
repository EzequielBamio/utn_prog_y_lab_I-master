/*
 ============================================================================
Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
Cantidad de positivos y negativos.
Sumatoria de los pares.
El mayor de los impares.
Listado de los números ingresados.
Listado de los números pares.
Listado de los números de las posiciones impares.
Se deberán utilizar funciones y vectores.


	Bamio Ezequiel


 ============================================================================
 */

#include <stdlib.h>
#include <windows.h>
#include "utnClase5.h"

#define L 5
#define A listaNumeros

int main(void) {

	setbuf(stdout,NULL);

	int listaNumeros[L];
	int cantidadPositivos;
	int cantidadNegativos;
	int sumaPares;
	int mayorImpar;

	CargarNumeros(A, L);

	cantidadPositivos = ContadorPositivos(listaNumeros, 10);
	printf("La cantidad de Positivos es: %d\n", cantidadPositivos);

	cantidadNegativos = ContadorNegativos(A, L);
	printf("La cantidade de Negativos es: %d\n", cantidadNegativos);

	sumaPares = SumarPares(A, L);
	printf("La suma de los Pares es: %d\n", sumaPares);

	mayorImpar = MayorImpares(A, L);
	if(mayorImpar != -1)
	{
		printf("El mayor de los Impares es: %d\n", mayorImpar);
	}

	MostrarNumerosIngresados(A, L);
	MostrarNumerosPares(A, L);
	MostrarNumerosImpares(A, L);


	system("pause");
	return EXIT_SUCCESS;
}
