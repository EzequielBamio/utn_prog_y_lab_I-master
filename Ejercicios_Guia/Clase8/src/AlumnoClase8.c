#include "AlumnoClase8.h"
#include <string.h>

int MostrarID(eAlumno lista[], int tam)
{
	int i;
	int rtn;

	printf("Ingrese el ID\n");
	for(i = 0; i < tam; i++)
	{
		if(lista[i].isEmpty != VACIO)
		{
			printf("ID: %d\n", lista[i].isEmpty);
		}
	}
	scanf("%d", &rtn);

	return rtn;
}

int ModificarUnAlumno(eAlumno lista[], int tam)
{
	int i;
	int rtn;
	int modificarAlumno;
	int opcionModificar;
	int nuevaNota;
	char nuevoNombre[100];
	rtn = 0;

	modificarAlumno = MostrarID(lista, tam);
	for(i = 0; i < tam; i++)
	{
		if(modificarAlumno == lista[i].isEmpty)
		{

			printf("Que desea modificar: \n1. Nota 1\n2. Nota 2\n3. Nombre\n");
			scanf("%d", &opcionModificar);

			switch(opcionModificar)
			{
			case 1:
				printf("Ingrese la nueva nota");
				scanf("%d", &nuevaNota);
				if(ConfirmarRespuesta("Seguro que desea modificar este Alumno? 1. Si 0. No", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
				{
					lista[i].nota1 = nuevaNota;
					rtn = 1;
				}
				break;
			case 2:
				printf("Ingrese la nueva nota");
				scanf("%d", &nuevaNota);
				if(ConfirmarRespuesta("Seguro que desea modificar este Alumno? 1. Si 0. No", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
				{

					lista[i].nota2 = nuevaNota;
					rtn = 1;
				}
				break;
			case 3:
				printf("Ingrese el nuevo nombre ");
				scanf("%[^\n]", nuevoNombre);
				if(ConfirmarRespuesta("Seguro que desea modificar este Alumno? 1. Si 0. No: ", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No: ") == 1)
				{
					//MAL
					strcpy(lista[i].nombre, nuevoNombre);
					rtn = 1;
				}
				break;
			}
		}
	    lista[i].promedio = (float)(lista[i].nota1 + lista[i].nota2)/2;
	}
	return rtn;
}

int EliminarUnAlumno(eAlumno lista[], int tam)
{
	int i;
	int rtn;
	int eliminarID;
	rtn = 0;

	eliminarID = MostrarID(lista, tam);
	for(i = 0; i < tam; i++)
	{
		if(eliminarID == lista[i].isEmpty)
		{
			if(ConfirmarRespuesta("Seguro que desea eliminar este Alumno? 1. Si 0. No: ", "ERROR: Seguro que desea eliminar este Alumno?\nIngrese 1. Si 0. No: ") == 1)
			{
				lista[i].isEmpty = VACIO;
				rtn = 1;
				break;
			}else
			{
				rtn = 0;
			}

		}
	}
	return rtn;

}

void MostrarUnAlumno(eAlumno unAlumno)
{
    printf("%d %d %d %.2f %s\n", unAlumno.legajo,
                               unAlumno.nota1,
                               unAlumno.nota2,
                               unAlumno.promedio,
                               unAlumno.nombre);
}
int MostrarTodosLosAlumnos(eAlumno lista[], int tam)
{
    int i;
    int rtn;
    rtn = 0;

    for(i=0; i<tam; i++)
    {
    	if(lista[i].isEmpty != VACIO)
    	{
    		 MostrarUnAlumno(lista[i]);
     		rtn = 1;

    	}
    }
    return rtn;
}

eAlumno PedirDatos()
{
    eAlumno alumnoIngresado;

    printf("Ingrese legajo: ");
    scanf("%d", &alumnoIngresado.legajo);
    printf("Ingrese Nota 1: ");
    scanf("%d", &alumnoIngresado.nota1);
    printf("Ingrese Nota 2: ");
    scanf("%d", &alumnoIngresado.nota2);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", alumnoIngresado.nombre);

    alumnoIngresado.promedio = (float)(alumnoIngresado.nota1 + alumnoIngresado.nota2)/2;

    alumnoIngresado.isEmpty = OCUPADO;

    return alumnoIngresado;
}
/*convertir en int*/
int CargarAlumno(eAlumno lista[], int tam)
{
    int i;
    int rtn;
    rtn = -1;
    i = BuscarLibre(lista, tam);
    if(i != -1)
    {
    	 lista[i] = PedirDatos();
    	 for(i = 0; i < tam; i++)
    	 {
    		 if(lista[i].isEmpty != VACIO)
    		 {
    			 lista[i].isEmpty = i;
    		 }
    	 }

    	 rtn = 1;
    }

    return rtn;
}

void OrdenarAlumnosPorLegajo(eAlumno lista[], int tam)
{
    int i;
    int j;
    eAlumno auxiliar;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].legajo<lista[j].legajo)
            {
               auxiliar = lista[i];
               lista[i] = lista[j];
               lista[j] = auxiliar;
            }
        }
    }
}


void InicializarAlumnos(eAlumno lista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		lista[i].isEmpty = VACIO;
	}
}

int BuscarLibre(eAlumno lista[], int tam)
{
	int i;
	int index;
	index = -1;
	for(i=0; i<tam; i++)
	{
		if(lista[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
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


