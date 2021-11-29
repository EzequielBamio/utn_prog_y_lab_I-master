#include <stdlib.h>
#include "eb_INPUT.h"

#ifndef ePilotos_H_INCLUDED
#define ePilotos_H_INCLUDED

typedef struct
{
    int idPiloto;
    char nombre[ARRAY_SIZE];


}ePilotos;

ePilotos* ePilotos_new();
ePilotos* ePilotos_newParametros(char* idStr,char* nombreStr);
int ePilotos_delete(ePilotos*);

int ePilotos_setId(ePilotos* this,int id);
int ePilotos_getId(ePilotos* this,int* id);

int ePilotos_setNombre(ePilotos* this,char* nombre);
int ePilotos_getNombre(ePilotos* this,char* nombre);


int ePilotos_IDincrease(int* id);
ePilotos* ePilotos_BuscarID(LinkedList* this, int id);

#endif // ePilotos_H_INCLUDED
