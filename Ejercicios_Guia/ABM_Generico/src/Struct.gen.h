#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_GEN_H_
#define STRUCT_GEN_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct
{
	int idGen;
	int isEmpty;

} eGen;
//***

/** INICIO CABECERAS DE FUNCION*/
void eGen_Inicializar(eGen pArray[], int tArray);
int eGen_ObtenerID(void);
int eGen_ObtenerIndexLibre(eGen pArray[], int tArray);
int eGen_BuscarPorID(eGen pArray[], int tArray, int ID);
void eGen_MostrarUno(eGen Gen);
int eGen_MostrarTodos(eGen pArray[], int tArray);
int eGen_MostrarDadosDeBaja(eGen pArray[], int tArray);
void eGen_ValidarId(eGen pppArray[], int tArray, char mensaje[], int* pResultado);


/** ORDENAMIENTO */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eGen_Ordenamiento(eGen pArray[], int tArray, int criterio);

//ABM
eGen eGen_CargarDatos(void);
eGen eGen_ModificarUno(eGen Gen);
int eGen_Alta(eGen pArray[], int tArray);
int eGen_Baja(eGen pArray[], int tArray);
int eGen_Modificacion(eGen pArray[], int tArray);
/** FIN CABECERAS DE FUNCION*/
#endif
