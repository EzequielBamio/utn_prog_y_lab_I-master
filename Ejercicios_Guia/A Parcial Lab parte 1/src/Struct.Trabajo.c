#include "Struct.Trabajo.h"
#include "Struct.Servicio.h"
#include "utn.Get.h"

void eTrabajo_ValidarId(eTrabajo pListaTrabajo[], int tTrabajo, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < tTrabajo; i++)
	{
		if(pListaTrabajo[i].id > mayor || i == 0)
		{
			mayor = pListaTrabajo[i].id;
		}
		if(pListaTrabajo[i].id < menor || i == 0)
		{
			menor = pListaTrabajo[i].id;
		}
	}

	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);

	*pResultado = numeroIngresado;

}


int eTrabajo_BuscarPorID(eTrabajo pListaTrabajo[], int tTrabajo, int ID)
{
	int rtn;
	int i;
	rtn = -1;

	if (tTrabajo > 0)
	{
		for (i = 0; i < tTrabajo; i++)
		{
			if (pListaTrabajo[i].id == ID && pListaTrabajo[i].isEmpty == OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


void eTrabajo_Inicializar(eTrabajo pListaTrabajo[], int tTrabajo)
{
	int i;

	if (tTrabajo > 0)
	{
		for (i = 0; i < tTrabajo; i++)
		{
			pListaTrabajo[i].isEmpty = LIBRE;
		}
	}
}



int eTrabajo_ObtenerIndexLibre(eTrabajo pListaTrabajo[], int tTrabajo)
{
	int rtn;
	int i;
	rtn = -1;

	if (tTrabajo > 0)
	{

		for (i = 0; i < tTrabajo; i++)
		{
			if (pListaTrabajo[i].isEmpty == LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


