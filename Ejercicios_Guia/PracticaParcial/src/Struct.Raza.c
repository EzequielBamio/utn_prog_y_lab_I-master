#include "Struct.Raza.h"

int eRaza_BuscarPorID(eRaza pListaRaza[], int tRaza, int ID)
{
	int rtn = -1;
	int i;

	// EL LIMITE ES VALIDO
	if (tRaza > 0)
	{
		//RECORRO TODO EL pListaMascotas
		for (i = 0; i < tRaza; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (pListaRaza[i].idRaz == ID && pListaRaza[i].isEmpty == OCUPADO)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

