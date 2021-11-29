#include "Array.h"
/*
 * 1. Mostrar
    * 1.1: MostrarLista_Entero
    * 1.2: MostrarLista_Decimal
 * 3. Ordenamiento
    * 3.1: Ordernar_NombreCompleto
    * 3.2: OrdernarLista_Decimal
    * 3.3: OrdernarLista_Entero
 */

void MostrarLista_Enteros(int listaNumeros[], int tam)
{
    int i;

	for(i = 0; i < tam; i++)
	{
		printf("%d\n", listaNumeros[i]);
	}
}

void MostrarLista_Decimal(float listaNumeros[], int tam)
{
    int i;

	for(i = 0; i < tam; i++)
	{
		printf("%.2f\n", listaNumeros[i]);
	}
}
void Ordenar_NombreCompleto(char nombre[], char apellido[], char nombreCompleto[])
{
	int i;

	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ", ");
	strcat(nombreCompleto, apellido);

	strlwr(nombreCompleto);

	if(strlen(nombre) > 0 && strlen(apellido) > 0)
	{
		for(i = 0; i < strlen(nombreCompleto); i++)
		{
			if(i == 0 && isspace(nombreCompleto[i]) == 0)
			{
				nombreCompleto[0]=toupper(nombreCompleto[0]);
			}else
			{
				if(isspace(nombreCompleto[i]) && i < strlen(nombreCompleto)-1)
				{
					nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
				}
			}
		}
	}
}
int OrdenarLista_Decimal(float listaNumeros[], int tam, int criterio)
{
	int i;
	int j;
	int rtn = 0;
	float auxiliar;

	if(listaNumeros != NULL && tam > 0)
	{
		switch(criterio){
			case -1:
				for(i = 0; i < tam-1; i++)
				{
					for(j = i+1; j < tam; j++)
					{
						if(listaNumeros[i] > listaNumeros[j])
						{
							auxiliar = listaNumeros[i];
							listaNumeros[i] = listaNumeros[j];
							listaNumeros[j] = auxiliar;
						}
					}
				}
				rtn = 1;
				break;
			case 1:
				for(int i = 0; i < tam-1; i++)
				{
					for(int j = i+1; j < tam; j++)
					{
						if(listaNumeros[i] < listaNumeros[j])
						{
							auxiliar = listaNumeros[i];
							listaNumeros[i] = listaNumeros[j];
							listaNumeros[j] = auxiliar;
						}
					}
				}
				rtn = 1;
				break;
			default:
				rtn = 0;
				break;
		}
	}

	return rtn;
}
int OrdenarLista_Enteros(int listaNumeros[], int tam, int criterio)
{
	int i;
	int j;
	int rtn = 0;
	int auxiliar;

	if(listaNumeros != NULL && tam > 0)
	{
		switch(criterio)
		{
			case -1:
				for(i = 0; i < tam-1; i++)
				{
					for(j = i+1; j < tam; j++)
					{
						if(listaNumeros[i] > listaNumeros[j])
						{
							auxiliar = listaNumeros[i];
							listaNumeros[i] = listaNumeros[j];
							listaNumeros[j] = auxiliar;
						}
					}
				}
				rtn = 1;
				break;
			case 1:
				for(i = 0; i < tam-1; i++)
				{
					for(j = i+1; j < tam; j++)
					{
						if(listaNumeros[i] < listaNumeros[j])
						{
							auxiliar = listaNumeros[i];
							listaNumeros[i] = listaNumeros[j];
							listaNumeros[j] = auxiliar;
						}
					}
				}
				rtn = 1;
				break;
			default:
				rtn = 0;
				break;
		}
	}

	return rtn;
}


