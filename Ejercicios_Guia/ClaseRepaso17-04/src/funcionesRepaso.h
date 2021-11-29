#include <stdio.h>
#define VACIO 0
#define OCUPADO 1

#ifndef FUNCIONESREPASO_H_
#define FUNCIONESREPASO_H_

//Crear la estructura empleado con idEmpleado, nombre, sueldo y puesto (programador,
//analista, tester).

typedef struct
{
	int idEmpleado;
	char nombre[50];
	float sueldo;
	char puesto[50];
	int Estado;

}eEmpleado;

void IniciarlizarEmpleados(eEmpleado lista[], int tam);
int Pedir_Entero_Con_Rango(char mensaje[], char errorMensaje[], int minimo, int maximo);
int Pedir_Entero(char mensaje[]);

#endif /* FUNCIONESREPASO_H_ */
