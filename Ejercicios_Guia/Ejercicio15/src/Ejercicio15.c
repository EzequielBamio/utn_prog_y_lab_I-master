/*
 ============================================================================

Realizar una función que reciba como parámetro un puntero a entero.
La función le pedirá al usuario que cargue un valor por medio del puntero. Retornara si pudo cargarlo o no.


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.get.h"

int MostrarPuntero(int*);
int PedirPuntero(int*);

int main(void) {

	setbuf(stdout, NULL);

	int unEntero;

	if(PedirPuntero(&unEntero))
	{
		if(MostrarPuntero(&unEntero))
		{
			printf("Error al mostrar el dato...");
		}
	}

	return EXIT_SUCCESS;
}

int PedirPuntero(int* pEntero)
{
	int rtn = 0;

	if(pEntero != NULL)
	{
		printf("Ingrese un numero entero ");
		scanf("%d", pEntero);
		rtn = 1;
	}

	return rtn;
}
int MostrarPuntero(int* pEntero)
{
	int retorno = 1;
	if(pEntero!=NULL)
	{
		printf("El valor es: %d\n", *pEntero);
		retorno = 0;
	}

	return retorno;
}

