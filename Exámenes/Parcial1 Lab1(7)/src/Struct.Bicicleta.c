#include "Struct.Bicicleta.h"
#include "utn.Get.h"

void eBicicleta_ValidarId(eBicicleta pListaBicicleta[], int tBicicleta, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < tBicicleta; i++)
	{
		if(pListaBicicleta[i].id > mayor || i == 0)
		{
			mayor = pListaBicicleta[i].id;
		}
		if(pListaBicicleta[i].id < menor || i == 0)
		{
			menor = pListaBicicleta[i].id;
		}
	}
	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);
	*pResultado = numeroIngresado;

}


int eBicicleta_BuscarPorID(eBicicleta pListaBicicleta[], int tBicicleta, int ID)
{
	int rtn;
	int i;
	rtn = -1;

	if (tBicicleta > 0)
	{
		for (i = 0; i < tBicicleta; i++)
		{
			if (pListaBicicleta[i].id == ID && pListaBicicleta[i].isEmpty == OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


void eBicicleta_MostrarUno(eBicicleta pListaBicicleta)
{
	//PRINTF DE UN SOLO pListaBicicleta
	printf("%-6d %-19s %-15d %s\n\n", pListaBicicleta.id, pListaBicicleta.marca, pListaBicicleta.rodado, pListaBicicleta.color);
}


int eBicicleta_MostrarTodos(eBicicleta pListaBicicleta[], int tBicicleta)
{
	int i;
	int rtn;
	int cantidad;
	rtn = 0;
	cantidad = 0;

	puts("\n\t> LISTADO de Bicicleta");
	printf("|ID   |MARCA        |RODADO  |COLOR           \n\n");

	if (tBicicleta > 0)
	{
		for (i = 0; i < tBicicleta; i++)
		{
			if (pListaBicicleta[i].isEmpty == OCUPADO)
			{
				eBicicleta_MostrarUno(pListaBicicleta[i]);
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
