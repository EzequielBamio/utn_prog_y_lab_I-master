#include "eb_INPUT.h"

#ifndef HPARCIAL_H_
#define HPARCIAL_H_

typedef struct
{
	int id;
	char marca[ARRAY_SIZE];
	int cantidadTinta;

}eImpresora;

eImpresora* eImpresora_new();
eImpresora* eImpresora_newParametros(char* id, char* marca, char* cantidadTinta);
int eImpresora_saveAsBinary(char* path , eImpresora* pArrayListImpresora);
int controller_loadFromBinary(char* path , eImpresora* pArrayListImpresora);
int parser_ImpresoraFromBinary(FILE* pArchivo,  eImpresora* pArrayListImpresora);
int eImpresora_getid(eImpresora* this, int* id);
int eImpresora_setid(eImpresora* this,int id);
int eImpresora_getMarca(eImpresora* this,char* marca);
int eImpresora_setMarca(eImpresora* this,char* marca);
int eImpresora_getCantidadTinta(eImpresora* this,int* cantidadTinta);
int eImpresora_setCantidadTinta(eImpresora* this,int cantidadTinta);

#endif /* HPARCIAL_H_ */
