#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct.Mascotas.h"
#include "Struct.Raza.h"

#ifndef STRUCT_GENERAL_H_
#define STRUCT_GENERAL_H_

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
void Mascotas_MostrarUno(eMascotas pListaMascotas, eRaza pListaRaza);
int Mascotas_MostrarTodos(eMascotas pListaMascotas[], int tMascotas, eRaza pListaRaza[], int tRaza);
/** FIN CABECERAS DE FUNCION*/


#endif /* STRUCT_GENERAL_H_ */
