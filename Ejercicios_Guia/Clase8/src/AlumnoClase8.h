#include <stdio.h>

#define VACIO -1
#define OCUPADO 0

#ifndef ALUMNOS_H_
#define ALUMNOS_H_

typedef struct
{
    //campos o atributos
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[25];
    int isEmpty;

}eAlumno;

int MostrarID(eAlumno lista[], int tam);

int ModificarUnAlumno(eAlumno lista[], int tam);

int ConfirmarRespuesta(char mensaje[], char mensajeError[]);

int EliminarUnAlumno(eAlumno lista[], int tam);

void MostrarUnAlumno(eAlumno);

int MostrarTodosLosAlumnos(eAlumno[], int);

eAlumno PedirDatos();

int CargarAlumno(eAlumno[], int);

void OrdenarAlumnosPorLegajo(eAlumno[], int);

void InicializarAlumnos(eAlumno[], int);

int BuscarLibre(eAlumno[], int);

#endif /* ALUMNOS_H_ */
