/*#include "utn.Array.h"

void Ordenar_Alumnos(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)
{
	int auxInt;
	float auxFloat;
	char auxString[tam];
	int i;
	int j;

	for(i = 0; i < tam-1; i++)
	{
		for(j = i+1; j < tam; j++)
		{
			if(strcmp(nombres[i], nombres[j]) > 0)
			{
				auxInt = legajos[i];
				legajos[i] = legajos[j];
				legajos[j] = auxInt;

				strcpy(auxString, nombres[i]);
				strcpy(nombres[i], nombres[j]);
				strcpy(nombres[j],auxString);

				auxFloat = notas1[i];
				notas1[i] = notas1[j];
				notas1[j] = auxFloat;

				auxFloat = notas2[i];
				notas2[i] = notas2[j];
				notas2[j] = auxFloat;

				auxFloat = promedios[i];
				promedios[i] = promedios[j];
				promedios[j] = auxFloat;

			}
		}
	}
}

void Inicializar_Alumnos(int legajos[], int tam)
{
     int i;

    for(i=0; i<tam; i++)
    {
        legajos[i] = -1;
    }
}

int Buscar_Libre(int legajos[], int tam)
{
    int i;
    int index;

    index = -1;

    for(i=0; i<tam; i++)
    {
        if(legajos[i]==-1)//encontre espacio libre
        {
            index = i;
            break;
        }
    }

    return index;
}

void Mostrar_Un_Alumno(int legajo, float nota1, float nota2, float promedio, char nombre[])
{
     printf("Legajo: %d - Nota 1: %.2f - Nota 2: %.2f - Promedio: %.2f - Nombre: %s\n", legajo, nota1, nota2, promedio, nombre);
}

void Mostrar_Todos_Los_Alumnos(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(legajos[i] != -1)
        {
            Mostrar_Un_Alumno(legajos[i], notas1[i], notas2[i], promedios[i], nombres[i]);
        }

    }
}
int Cargar_Un_Alumno(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)
{
    int index;
    index = Buscar_Libre(legajos, tam);
    if(index!=-1) //encontro espacio
    {
    	getInt(&legajos[index], "Ingrese legajo: ");

    	getFloat(&notas1[index], "Ingrese  nota 1: ");

    	getFloat(&notas2[index], "Ingrese  nota 2: ");

		promedios[index] = Calcular_Promedio(notas1[index], notas2[index]);

		myGets(nombres[index], tam, "Ingrese nombre: ");

		index = 0;
    }

    return index;
}*/
