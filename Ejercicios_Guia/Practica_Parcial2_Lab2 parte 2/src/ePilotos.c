#include <string.h>
#include "inc/Pilotos.h"
#include "inc/LinkedList.h"
#include "inc/eb_INPUT.h"

ePilotos* ePilotos_new()
{
	ePilotos* pPilotos;

	pPilotos = (ePilotos*) malloc(sizeof(ePilotos));

	return pPilotos;
}

ePilotos* ePilotos_newParametros(char* idStr,char* nombreStr)
{
	 ePilotos* pAuxPilotos;
	 pAuxPilotos = ePilotos_new();

	 if(pAuxPilotos != NULL)
	 {
		 ePilotos_setId(pAuxPilotos, atoi(idStr));
		 ePilotos_setNombre(pAuxPilotos, nombreStr);
	 }

	 return pAuxPilotos;
}

int ePilotos_delete(ePilotos* this)
{
	int rtn;
	rtn = FALSE;
	if(this != NULL)
	{
		free(this);
		rtn = TRUE;
	}

	return rtn;
}

//
int ePilotos_setId(ePilotos* this,int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		this->idPiloto = id;
		rtn = TRUE;
	}

	return rtn;
}
int ePilotos_getId(ePilotos* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		*id = this->idPiloto;
		rtn = TRUE;
	}

	return rtn;
}
//
int ePilotos_setNombre(ePilotos* this,char* nombre)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(this->nombre, nombre);
		rtn = TRUE;
	}

	return rtn;
}
int ePilotos_getNombre(ePilotos* this,char* nombre)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		rtn = TRUE;
	}

	return rtn;
}

//---------------------------------------\ * /----------------------------------------//


ePilotos* ePilotos_BuscarID(LinkedList* this, int id)
{
	int i;
	int tList;
	ePilotos* pAuxPilotos;
	pAuxPilotos = NULL;
	tList = ll_len(this);

	if(this != NULL && id > 0)
	{
		for(i = 0; i < tList; i++)
		{
			pAuxPilotos = (ePilotos*) ll_get(this, i);
			if(pAuxPilotos->idPiloto == id)
			{
				break;
			}
		}
	}
	return pAuxPilotos;
}
