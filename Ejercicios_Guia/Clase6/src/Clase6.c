/*
 ============================================================================
 Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
 Necesito generar un listado de los números positivos de manera creciente y negativos de manera decreciente.

 	 Bamio Ezequiel

 ============================================================================
 */

#include <stdlib.h>
#include "claseSeis.h"

#define L 5

int main(void) {

	setbuf(stdout,NULL);

	int listaNumeros[L];
		int i;
		int p;
		int positivo;
		int auxiliar;

		CargarNumeros(listaNumeros, L);

		for(i = 0; i < L-1; i++)
		{
			positivo = EsPositivo(listaNumeros[i]);
			if(positivo == 1)
			{
				for(p = i+1; p < L; p++)
				{
					if(listaNumeros[i] > listaNumeros[p])
					{
						auxiliar = listaNumeros[i];
						listaNumeros[i] = listaNumeros[p];
						listaNumeros[p] = auxiliar;
					}
				}
			}else
			{
				if(positivo == -1)
				{
						if(listaNumeros[i] < listaNumeros[p])
						{
							auxiliar = listaNumeros[i];
							listaNumeros[i] = listaNumeros[p];
							listaNumeros[p] = auxiliar;
					}
				}
			}
		}

		for(i = 0; i < L; i++)
		{
			printf("%d\n", listaNumeros[i]);
		}

	return EXIT_SUCCESS;
}
