#include <string.h>
#include "inc/Aviones.h"
#include "inc/LinkedList.h"
#include "inc/eb_INPUT.h"

eAviones* eAviones_new()
{
	eAviones* pEmpleado;

	pEmpleado = (eAviones*) malloc(sizeof(eAviones));

	return pEmpleado;
}

eAviones* eAviones_newParametros(char* idStr,char* modeloStr,char* cantButacasStr)
{
	 eAviones* pAuxEmpleado;
	 pAuxEmpleado = eAviones_new();

	 if(pAuxEmpleado != NULL)
	 {
		 eAviones_setId(pAuxEmpleado, atoi(idStr));
		 eAviones_setModelo(pAuxEmpleado, modeloStr);
		 eAviones_setCantButacas(pAuxEmpleado, atoi(cantButacasStr));

	 }

	 return pAuxEmpleado;
}

int eAviones_delete(eAviones* this)
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
int eAviones_setId(eAviones* this,int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		this->idAvion = id;
		rtn = TRUE;
	}

	return rtn;
}
int eAviones_getId(eAviones* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		*id = this->idAvion;
		rtn = TRUE;
	}

	return rtn;
}
//
int eAviones_setModelo(eAviones* this,char* modelo)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(this->modelo, modelo);
		rtn = TRUE;
	}

	return rtn;
}
int eAviones_getModelo(eAviones* this,char* modelo)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(modelo, this->modelo);
		rtn = TRUE;
	}

	return rtn;
}
//
int eAviones_setCantButacas(eAviones* this,int cantButacas)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && cantButacas > 0)
	{
		this->cantButacas = cantButacas;
		rtn = TRUE;
	}

	return rtn;
}
int eAviones_getCantButacas(eAviones* this,int* cantButacas)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && cantButacas > 0)
	{
		*cantButacas = this->cantButacas;
		rtn = TRUE;
	}

	return rtn;
}


//---------------------------------------\ * /----------------------------------------//


eAviones* eAviones_BuscarID(LinkedList* this, int id)
{
	int i;
	int tList;
	eAviones* pAuxAviones;
	pAuxAviones = NULL;
	tList = ll_len(this);

	if(this != NULL && id > 0)
	{
		for(i = 0; i < tList; i++)
		{
			pAuxAviones = (eAviones*) ll_get(this, i);

			if(pAuxAviones->idAvion == id)
			{
				break;
			}
		}
	}
	return pAuxAviones;
}
