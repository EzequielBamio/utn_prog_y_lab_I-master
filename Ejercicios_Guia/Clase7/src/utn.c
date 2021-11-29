/*
 * utn.c
 *
 *  Created on: 6 abr. 2021
 *      Author: ezequ
 */
#include "utn.h"
#include <string.h>
#include "utnClase7.h"

void OrdenarAlumnos(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)
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

int PedirEntero(char mensaje[])
{
	int entero;

	printf("%s ", mensaje);
    scanf("%d", &entero);

	return entero;
}
void PedirCadena(char mensaje[], char cadena[])
{
	printf("%s ", mensaje);
    gets(cadena);

}
float PedirDecimal(char mensaje[])
{
	float decimal;

	printf("%s ", mensaje);
    scanf("%f", &decimal);

	return decimal;
}

void InicializarAlumnos(int legajos[], int tam)
{
     int i;

    for(i=0; i<tam; i++)
    {
        legajos[i] = -1;
    }
}

int BuscarLibre(int legajos[], int tam)
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

void MostrarUnAlumno(int legajo, float nota1, float nota2, float promedio, char nombre[])
{
     printf("Legajo: %d - Nota 1: %.2f - Nota 2: %.2f - Promedio: %.2f - Nombre: %s\n", legajo, nota1, nota2, promedio, nombre);
}

void MostrarTodosLosAlumnos(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(legajos[i] != -1)
        {
            MostrarUnAlumno(legajos[i], notas1[i], notas2[i], promedios[i], nombres[i]);
        }

    }
}
float CalcularPromedio(float nota1, float nota2)
{
	float promedio;

	promedio = (nota1 + nota2) / 2;

	return promedio;
}
int CargarUnAlumno(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)
{
    int index;
    index = BuscarLibre(legajos, tam);
    if(index!=-1) //encontro espacio
    {
        printf("Ingrese legajo: ");
		scanf("%d", &legajos[index]);

		printf("Ingrese nota 1: ");
		scanf("%f", &notas1[index]);

		printf("Ingrese nota 2: ");
		scanf("%f", &notas2[index]);

		promedios[index] = CalcularPromedio(notas1[index], notas2[index]);

		printf("Ingrese nombre: ");
		fflush(stdin);
		scanf("%[^\n]",nombres[index]);

		index = 0;
    }

    return index;
}
int ConfirmarRespuesta(char mensaje[], char mensajeError[])
{
	int respuesta;

	printf("%s", mensaje);
	scanf("%d", &respuesta);

	while(respuesta != 1 && respuesta != 0)
	{
		printf("%s", mensajeError);
		scanf("%d", &respuesta);
	}

	return respuesta;
}
int ModificarAlumno(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)//devuelvo 1 si se modifico -1 si no se modifico
{
	//int respuestaConfirmacion;
	int i;
	int registro;
	int legajoActual;
	char nombreActual[tam];
	float notaDosActual;
	float notaUnoActual;
	int nuevoLegajo;
	float nuevaNota;
	char nuevoNombre[tam];
	int opcionModificar;

	opcionModificar = PedirEntero("\nOpcion:\n1. Nota 1\n2. Nota 2\n3. Nombre\nQue desea modificar?:");
	while(opcionModificar < 0 || opcionModificar > 3)
	{
		opcionModificar = PedirEntero("\nERROR: \nOpcion:\n1. Nota 1\n2. Nota 2\n3. Nombre\nQue desea modificar?:");
	}

	switch(opcionModificar)
	{
	case 1:
		nuevaNota = ModificarNota(legajos, notas1, tam);

		for(i=0; i<tam; i++)
		{
			notas1[i] = nuevaNota;
		}

		break;

	case 2:
		nuevaNota = ModificarNota(legajos, notas2, tam);

				for(i=0; i<tam; i++)
				{
					notas2[i] = nuevaNota;
				}

				break;
		break;
	case 3:
		ModificarNombre(legajos, nombres, tam);
		/*nombreActual = PedirCadena("Ingrese la Nota 2 actual:");
				for(i=0; i<tam; i++)
				{
					while(nombreActual != notas2[i])
					{
						nombreActual = PedirCadena("ERROR: No se encontro el nombre.\nIngrese la Nota 2 actual:");
					}
					if(nombreActual == nombres[i])//lo encontre
					{
						printf("\nNombre encontrado!\n");
						nuevaNotaDos = PedirDecimal("Ingrese la nueva Nota 2:");
						respuestaConfirmacion = ConfirmarRespuesta("Seguro que desea modificar la nota 2?: 1. Si 0. No\n", "ERROR: Ingrese 1. Si 0. No\nSeguro que desea modificar la nota 2?: 1. Si 0. No");
						if(respuestaConfirmacion == 1)
						{
							notas2[i] = nuevaNotaDos;
							registro = 1;
						}else
						{
							registro = -1;
						}
						break;
					}
				}*/
		break;

	}
	//promedios[i] = CalcularPromedio(notas1[i], notas2[i]);
    return registro;

}

int EliminarAlumno(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)
{
    int legajoIngresado;
    int i;
    int respuestaConfirmacion;
    int registro;

    printf("Ingrese el legajo a eliminar: ");
    scanf("%d", &legajoIngresado);


    for(i=0; i<tam; i++)
    {
    	while(legajoIngresado != legajos[i])
    	{
    	    printf("\nNo se encontro el legajo\nIngrese el legajo a eliminar: ");
    	    scanf("%d", &legajoIngresado);
    	}

        if(legajoIngresado == legajos[i])//lo encontre
        {
        	printf("\nLegajo encontrado!\n");
        	respuestaConfirmacion = ConfirmarRespuesta("Seguro que desea eliminar el legajo?: 1. Si 0. No\n", "ERROR: Ingrese 1. Si 0. No\nSeguro que desea eliminar el legajo?: 1. Si 0. No");
        	if(respuestaConfirmacion == 1)
        	{
                legajos[i] = -1;
                registro = 1;
        	}else
        	{
        		registro = -1;
        	}
            break;
        }


    }

    return registro;

}
