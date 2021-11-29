#include "General.h"
/*
 * 2. Contadores && Acumuladores
    * 2.1: Cantidad_Positivos
    * 2.2: Cantidad_Negativos
 */

void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

int Cantidad_Positivos(int numero[], int cantidad)
{
	int i;
	int contadorPositivos;
	int positivo;
	contadorPositivos = 0;

	for(i = 0; i < cantidad; i++)
	{
		positivo = Validar_Positivo(numero[i]);
		if(positivo == 1)
		{
			contadorPositivos++;
		}
	}

	return contadorPositivos;
}

int Cantidad_Negativos(int numero[], int cantidad)
{
	int i;
	int contadorNegativos;
	int negativo;
	contadorNegativos = 0;

	for(i = 0; i < cantidad; i++)
	{
		negativo = Validar_Positivo(numero[i]);

		if(negativo == -1)
		{
			contadorNegativos++;
		}
	}

	return contadorNegativos;
}


