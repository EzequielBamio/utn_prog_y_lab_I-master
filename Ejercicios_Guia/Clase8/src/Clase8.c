#include "AlumnoClase8.h"
#include <stdlib.h>
#include <string.h>

#define T 3

int main(void)
{
    setbuf(stdout, NULL);
    eAlumno listaAlumnos[T];//={{100,5,9,7,"Juan"},{101,9,8,8.5,"Maria"},{103,9,7,7.5,"Ana"}};

    int opcion;
    int alumnoBaja;
    int noHayAlumnos;
    int alumnoCargado;
    int alumnoModificado;

    InicializarAlumnos(listaAlumnos, T);

    do
    {
        printf("1. ALTA\n");
        printf("2. BAJA\n");
        printf("3. MODIFICACION\n");
        printf("4. ORDENAR y MOSTRAR\n");
        printf("10. Salir\n");
        printf("Elija una opcion:");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                alumnoCargado = CargarAlumno(listaAlumnos, T);
                if(alumnoCargado == 1)
                {
                	printf("Dato generado con exito\n\n");
                }else
                {
                	printf("No hay espacio!!!\n\n");
                }
            break;
            case 2:
            	alumnoBaja = EliminarUnAlumno(listaAlumnos, T);
            	if(alumnoBaja == 1)
            	{
            		printf("El Alumno ha sido eliminado!\n\n");
            	}else
            	{
            		printf("Se cancelo la baja del alumno.\n\n");
            	}
            break;
            case 3:
            	alumnoModificado = ModificarUnAlumno(listaAlumnos, T);
            	if(alumnoModificado == 1)
            	{
            		printf("El Alumno ha sido modificado!\n\n");
            	}else
            	{
            		printf("Se cancelo la modificacion del alumno.\n\n");
            	}
            break;
            case 4:
            	OrdenarAlumnosPorLegajo(listaAlumnos, T);
                printf("\nLista Ordenada por legajo:\n\n");
                noHayAlumnos = MostrarTodosLosAlumnos(listaAlumnos, T);
                printf("\n");
                if(noHayAlumnos == 0)
                {
            	   printf("No hay alumnos para mostrar\n\n");
                }
            break;
        }
    }while(opcion!=10);

	return EXIT_SUCCESS;

}
