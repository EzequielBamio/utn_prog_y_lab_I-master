/*
 ============================================================================
Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
Por ejemplo:
5! = 5*4*3*2*1 = 120

	Bamio Ezequiel

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int i;
	int numeroIngresado;

	int factorial;

	factorial = 1;

	printf("Ingrese un numero ");
	scanf("%d", &numeroIngresado);

	for(i = numeroIngresado; i > 1; i--)
	{
		factorial = factorial * i;
	}

	printf("Resultado %d", factorial);

	return EXIT_SUCCESS;
}
