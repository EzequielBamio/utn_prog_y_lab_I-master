#include "hParcial.h"
#include "eb_INPUT.h"
/*
 ============================================================================
 EJERCICIOS DEL SEGUNDO PARCIAL PROGRAMACIÓN.

Diseñar la estructura (según el tema otorgado). Realizar un constructor por defecto y uno parametrizado para dicha estructura.
 Respetar las reglas de estilo vistas en la cátedra. Crear un dato de este tipo en el main y mostrarlo a través de una función

 ============================================================================
 */

eImpresora* eImpresora_new()
{
	eImpresora* pImpresora;

	pImpresora = (eImpresora*) malloc(sizeof(eImpresora));

	return pImpresora;
}

eImpresora* eImpresora_newParametros(char* id, char* marca, char* cantidadTinta)
{
	 eImpresora* pAuxImpresora;
	 pAuxImpresora = eImpresora_new();

	 if(pAuxImpresora != NULL)
	 {
		 eImpresora_setid(pAuxImpresora, atoi(id));
		 eImpresora_setMarca(pAuxImpresora, marca);
		 eImpresora_setCantidadTinta(pAuxImpresora, atoi(cantidadTinta));
	 }

	 return pAuxImpresora;
}

//
int eImpresora_setCantidadTinta(eImpresora* this,int cantidadTinta)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && cantidadTinta > 0)
	{
		this->cantidadTinta = cantidadTinta;
		rtn = TRUE;
	}

	return rtn;
}
int eImpresora_getCantidadTinta(eImpresora* this,int* cantidadTinta)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && cantidadTinta > 0)
	{
		*cantidadTinta = this->cantidadTinta;
		rtn = TRUE;
	}

	return rtn;
}
//
//
int eImpresora_setMarca(eImpresora* this,char* marca)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(this->marca, marca);
		rtn = TRUE;
	}

	return rtn;
}
int eImpresora_getMarca(eImpresora* this,char* marca)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(marca, this->marca);
		rtn = TRUE;
	}

	return rtn;
}
//
//
int eImpresora_setid(eImpresora* this,int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = TRUE;
	}

	return rtn;
}
int eImpresora_getid(eImpresora* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		*id = this->id;
		rtn = TRUE;
	}

	return rtn;
}
//

int eImpresora_saveAsBinary(char* path , eImpresora* pArrayListImpresora)
{
	FILE* pArchivo;
	int rtn;

	rtn = FALSE;
	pArchivo = fopen(path, "wb");

	if(pArchivo != NULL )
	{
		fwrite(pArrayListImpresora, sizeof(eImpresora), 1, pArchivo);
		rtn = TRUE;
	}

	fclose(pArchivo);

    return rtn;
}

int controller_loadFromBinary(char* path , eImpresora* pArrayListImpresora)
{
	FILE* pArchivo;
	int rtn;
	rtn = FALSE;
	if(path != NULL)
	{
		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL)
		{
			rtn = controller_loadFromBinary(pArchivo, pArrayListImpresora);
		}
		fclose(pArchivo);
	}

    return rtn;
}
int parser_ImpresoraFromBinary(FILE* pArchivo, eImpresora* pArrayListImpresora)
{
	int rtn;
	rtn = FALSE;

	eImpresora* pAuxImpresora;

	if(pArchivo != NULL && pArrayListImpresora != NULL)
	{

		//Mientras no sea el final del archivo y pArrayListEmploye sea distinto a NULL
		while(!feof(pArchivo))
		{
			pAuxImpresora = eImpresora_new();
			//lee los datos
			fread(pAuxImpresora, sizeof(eImpresora), 1, pArchivo);

			//Si es el final del archivo sale del programa(Evitamos que se carguen datos basuras)
			if(feof(pArchivo))
			{
				break;
			}
		}

	rtn = TRUE;
	}

    return rtn;
}

