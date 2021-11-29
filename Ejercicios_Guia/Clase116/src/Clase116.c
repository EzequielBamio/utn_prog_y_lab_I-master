/*
 ============================================================================
Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
La función calculará el valor máximo de ese array y utilizará el valor por referencia para retornar ese valor.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int Remplazar_Caracter(char*, char, char);
int Calcular_Maximo(int*, int);

int main(void) {

    setbuf(stdout, NULL);




	/*int cantidadCambios;
	char Cadena[20] = "programacion";
	char a;
	char b;
	a = 'o';
	b = 'U';

	printf("CADENA: %s\n", Cadena);
	cantidadCambios = Remplazar_Caracter(Cadena, a, b);
	printf("CADENA REMPLAZADA: %s\n", Cadena);
	printf("CANTIDAD CAMBIOS: %d\n", cantidadCambios);*/

	return EXIT_SUCCESS;
}
int Calcular_Maximo(int* pEntero, int rEntero)
{
	int i;
	for(i = 0; i < )

	return rEntero;
}

/*int Remplazar_Caracter(char* pPrimeraCadena, char caracterUno, char caracterDos)
{
	int i;
	int rtn;
	int contadorCambios;
	contadorCambios = 0;
	rtn = -1;

	if(pPrimeraCadena != NULL)
	{
		for(i = 0; i < strlen(pPrimeraCadena); i++)
		{
			if(*(pPrimeraCadena+i) == caracterUno)
			{
				*(pPrimeraCadena+i) = caracterDos;
				contadorCambios++;
			}
		}

		if(contadorCambios != 0)
		{
			rtn = contadorCambios;
		}

	}

	return rtn;
}*/
