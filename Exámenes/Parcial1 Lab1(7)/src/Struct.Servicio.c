#include "Struct.Servicio.h"
#include "utn.Get.h"

void eServicio_ValidarId(eServicio pListaServicio[], int tServicio, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < tServicio; i++)
	{
		if(pListaServicio[i].id > mayor || i == 0)
		{
			mayor = pListaServicio[i].id;
		}
		if(pListaServicio[i].id < menor || i == 0)
		{
			menor = pListaServicio[i].id;
		}
	}
	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);
	*pResultado = numeroIngresado;

}


int eServicio_BuscarPorID(eServicio pListaServicio[], int tServicio, int ID)
{
	int rtn;
	int i;
	rtn = -1;

	if (tServicio > 0)
	{
		for (i = 0; i < tServicio; i++)
		{
			if (pListaServicio[i].id == ID && pListaServicio[i].isEmpty == OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


void eServicio_MostrarUno(eServicio pListaServicio)
{
	//PRINTF DE UN SOLO pListaServicio
	printf("%-6d %-15s %-11.2f \n\n", pListaServicio.id, pListaServicio.descripcion, pListaServicio.precio);
}


int eServicio_MostrarTodos(eServicio pListaServicio[], int tServicio)
{
	int i;
	int rtn;
	int cantidad;
	rtn = 0;
	cantidad = 0;

	puts("\n\t> LISTADO de Servicio");
	printf("|ID   |DESCRIPCION        |PRECIO            \n\n");

	if (tServicio > 0)
	{
		for (i = 0; i < tServicio; i++)
		{
			if (pListaServicio[i].isEmpty == OCUPADO)
			{
				eServicio_MostrarUno(pListaServicio[i]);
				cantidad++;
			}
		}
	}

	if (cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}

//*******




