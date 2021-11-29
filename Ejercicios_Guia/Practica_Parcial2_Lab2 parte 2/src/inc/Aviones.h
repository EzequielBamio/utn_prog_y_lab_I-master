#include <stdlib.h>
#include "eb_INPUT.h"

#ifndef eAviones_H_INCLUDED
#define eAviones_H_INCLUDED

typedef struct
{
    int idAvion;
    char modelo[ARRAY_SIZE];
    int cantButacas;

}eAviones;

eAviones* eAviones_new();
eAviones* eAviones_newParametros(char* idStr,char* modeloStr,char* cantButacasStr);
int eAviones_delete(eAviones*);

int eAviones_setId(eAviones* this,int id);
int eAviones_getId(eAviones* this,int* id);

int eAviones_setModelo(eAviones* this,char* modelo);
int eAviones_getModelo(eAviones* this,char* modelo);

int eAviones_setCantButacas(eAviones* this,int cantButacas);
int eAviones_getCantButacas(eAviones* this,int* cantButacas);


int eAviones_IDincrease(int* id);
eAviones* eAviones_BuscarID(LinkedList* this, int id);

#endif // eAviones_H_INCLUDED
