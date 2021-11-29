#include "funcionesRepaso.h"
int Cargar_Empleado(eEmpleado lista)
{
	eEmpleado empleadosIngresados;
	int idEmpleado;
	char nombre[50];
	Pedir_Entero("Ingrese la id: ");
	printf("Ingrese el nombre: ");
	gets(nombre);
}

void Mostrar_Un_Empleado(eEmpleado lista)
{
	printf("%5d %5s %5.2f %5s", lista.idEmpleado,
								lista.nombre,
								lista.sueldo,
								lista.puesto);
}

int Buscar_Empleado(eEmpleado lista[], int tam)
{
	int rtn;
	int i;
	rtn = OCUPADO;

	for(i = 0; i < tam; i++)
	{
		if(lista[i].Estado == VACIO)
		{
			rtn = i;
		}
	}

	return rtn;
}

void Iniciarlizar_Empleados(eEmpleado lista, int tam)
{
	int i;
	for(i = 0; i < tam; i++)
	{
		lista[i] = VACIO;
	}
}


//***********************//
int Pedir_Entero_Con_Rango(char mensaje[], char errorMensaje[], int minimo, int maximo)
{
	int numeroIngresado;

	numeroIngresado = Pedir_Entero(mensaje);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR: Ingrese un numero entre %d y %d.\n", minimo, maximo);
    	numeroIngresado = Pedir_Entero(mensaje);
	}

	return numeroIngresado;
}
int Pedir_Entero(char mensaje[])
{
	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
