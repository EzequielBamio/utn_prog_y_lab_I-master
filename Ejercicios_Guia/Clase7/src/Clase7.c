/*
 ============================================================================
Crear una función que pida el ingreso de un entero y lo retorne.

PedirEntero X
PedirFloat X
PedirChar X
PedirDouble X
============================================================================
*/
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "utnClase7.h"


#define MAX_ALUMNOS 3
#define MAX_CADENA 30

int main()
{
	setbuf(stdout,NULL);

    int legajos[MAX_ALUMNOS] = {1000, 1004, 1100};
	float notas1[MAX_ALUMNOS]  = {10, 5.5, 7.5};
	float notas2[MAX_ALUMNOS]  = {5, 10, 5.5};
	float promedio[MAX_ALUMNOS];
	//char nombres[FILAS][COLUMNAS];
	char nombres[MAX_ALUMNOS][MAX_CADENA];// = {"Juan", "Pepe", "Ana"};

    int opcion;
    int index;
    int registro;

    InicializarAlumnos(legajos, MAX_ALUMNOS);

    do
    {
    	opcion = PedirEntero("1. ALTA \n2. BAJA\n3. MODIFICACION\n4. ORDENAR y MOSTRAR\n10. Salir\nElija una opcion:");

        switch(opcion)
        {
            case 1:

            	index = CargarUnAlumno(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
	            if(index==-1)
	            {
	                printf("\nNo hay espacio disponible en la lista...\n");
	            }
	            else
	            {
	                printf("\nAlumno cargado con exito!!!\n");
	            }

            break;
            case 2:
                registro = EliminarAlumno(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
                if(registro == 1)
                {
                    printf("\nSe elimino el legajo\n\n");
                }else
                {
                	printf("\nLa baja ha sido cancelada.\n\n");
                }

            break;
            case 3:
            	ModificarAlumno(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
            break;
            case 4:
                OrdenarAlumnos(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
                MostrarTodosLosAlumnos(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
            break;
        }

    }while(opcion!=10);

    return 0;
}



