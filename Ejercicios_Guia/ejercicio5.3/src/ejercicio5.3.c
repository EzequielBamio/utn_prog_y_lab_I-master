/*
 ============================================================================
Realizar un programa que permita el ingreso de 10 números enteros distintos de cero. La carga deberá ser aleatoria
(todos los elementos se inicializaran en cero por default.
 Determinar el promedio de los positivos, y del menor de los negativos la suma de los antecesores.
 ============================================================================
 */

#include <stdlib.h>
#include "utnClase5.h"

#define L 5

int main(void) {

	setbuf(stdout,NULL);

	int i;
	int listaNumeros[L] = {0};
	int posicion;
	int auxiliar;
	int promedio;
	int menorNegativo;
	int sumaAntecesores;

	for(i = 0; i < L; i++)
	{
		posicion = PedirEntero("Ingrese una posicion 1-10:", "ERROR: Reingrese una posicion entre 1 - 10:", 1, L);
		auxiliar = PedirNumeroDistinto("Ingrese un numero:", "ERROR: Reingrese un numero:", 0);

		listaNumeros[posicion-1] = auxiliar;
	}

	promedio = PromedioPositivos(listaNumeros, L);
	printf("El promedio de los positivos es: %d \n", promedio);
	menorNegativo = MenorNegativo(listaNumeros, L);
	sumaAntecesores = SumarAntecesores(menorNegativo);
	printf("El menor de los negativos es: %d y la suma de sus Antecesores es: %d \n", menorNegativo, sumaAntecesores);













	return EXIT_SUCCESS;
}
