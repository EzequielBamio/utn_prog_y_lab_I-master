/*
 * utn.h
 *
 *  Created on: 6 abr. 2021
 *      Author: ezequ
 */
#include <stdio.h>

#ifndef UTN_H_
#define UTN_H_

int PedirEntero(char mensaje[]);
void PedirCadena(char mensaje[],char cadena[]);
float PedirDecimal(char mensaje[]);
void InicializarAlumnos(int[], int);
int BuscarLibre(int[], int);
void MostrarUnAlumno(int, float, float, float, char[]);
void OrdenarAlumnos(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam);
void MostrarTodosLosAlumnos(int[], float[], float[], float[], char[][30], int);
/*-1 si no encontro espacio disponible */
float CalcularPromedio(float nota1, float nota2);
int CargarUnAlumno(int[], float[], float[], float[], char[][30], int);
int ConfirmarRespuesta(char mensaje[], char mensajeError[]);
int ModificarAlumno(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam);
int EliminarAlumno(int[], float[], float[], float[], char[][30], int);


#endif /* UTN_H_ */
