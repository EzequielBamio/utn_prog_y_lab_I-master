/*
 ============================================================================
Crear la estructura empleado con idEmpleado, nombre, sueldo y puesto (programador,
analista, tester).
Crear un menu con las siguientes opciones:
1. Cargar empleados. Carga secuencial.
2. Mostrar empleados. Ordenados por puesto.
3. Mostrar solo los empleados analistas.
4. Mostrar cuantos empleados tester hay.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesRepaso.h"
#define T 2

int main(void) {
	setbuf(stdout, NULL);

	eEmpleado listaEmpleados[T];
	int opcion;

	IniciarlizarEmpleados(listaEmpleados, T);

	do
	{
		opcion = Pedir_Entero_Con_Rango("* 1. Cargar empleados.\n* 2. Mostrar empleados.\n* 3.Mostrar solo los empleados analistas\n* 4. Mostrar cantidad empleados tester\n\n* 5. Salir\n",
										"ERROR: * 1. Cargar empleados.\n* 2. Mostrar empleados.\n* 3.Mostrar solo los empleados analistas\n* 4. Mostrar cantidad empleados tester\n\n* 5. Salir\n",
										1, 5);

		switch(opcion)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}

	}while(opcion != 5);






	return EXIT_SUCCESS;
}
