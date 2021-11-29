#include "Struct.Marca.h"
#include "utn.Get.h"

void eMarca_ValidarId(eMarca pListaMarca[], int tMarca, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < tMarca; i++)
	{
		if(pListaMarca[i].id > mayor || i == 0)
		{
			mayor = pListaMarca[i].id;
		}
		if(pListaMarca[i].id < menor || i == 0)
		{
			menor = pListaMarca[i].id;
		}
	}

	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);
	*pResultado = numeroIngresado;

}


int eMarca_BuscarPorID(eMarca pListaMarca[], int tMarca, int ID)
{
	int rtn;
	int i;
	rtn = -1;

	if (tMarca > 0)
	{
		for (i = 0; i < tMarca; i++)
		{
			if (pListaMarca[i].id == ID && pListaMarca[i].isEmpty == OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


void eMarca_MostrarUno(eMarca pListaMarca)
{
	//PRINTF DE UN SOLO pListaMarca
	printf("%-6d %-19s \n\n", pListaMarca.id, pListaMarca.descripcion);
}


int eMarca_MostrarTodos(eMarca pListaMarca[], int tMarca)
{
	int i;
	int rtn;
	int cantidad;
	rtn = 0;
	cantidad = 0;

	puts("\n\t> LISTADO de Marcas");
	printf("|ID   |DESCRIPCION        \n\n");

	if (tMarca > 0)
	{
		for (i = 0; i < tMarca; i++)
		{
			if (pListaMarca[i].isEmpty == OCUPADO)
			{
				eMarca_MostrarUno(pListaMarca[i]);
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
void eMarca_Inicializar(eMarca pListaMarca[], int tMarca)
{
	int i;

	if (tMarca > 0)
	{
		for (i = 0; i < tMarca; i++)
		{
			pListaMarca[i].isEmpty = LIBRE;
		}
	}
}


int eMarca_Baja(eMarca pListaMarca[], int tMarca)
{
	int rtn;
	int idTra;
	int index;
	rtn = 0;

	if(eMarca_MostrarTodos(pListaMarca, tMarca) == 1)
	{
		eMarca_ValidarId(pListaMarca, tMarca, "INGRESE ID A DAR DE BAJA: ", &idTra);

		while (eMarca_BuscarPorID(pListaMarca, tMarca, idTra) == -1)
		{
			printf("EL ID '%d' NO EXISTE.\n", idTra);
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 0)
			{
				break;
			}

			eMarca_ValidarId(pListaMarca, tMarca, "INGRESE ID A DAR DE BAJA: ", &idTra);

		}

		index = eMarca_BuscarPorID(pListaMarca, tMarca, idTra);
		if(index != -1)
		{
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 1)
			{
				pListaMarca[index].isEmpty = BAJA;
				rtn = 1;
			}
		}

	}else
	{
		puts("\n* NO HAY TRABAJOS CARGADOS.");
	}

	return rtn;
}


int eMarca_Modificar(eMarca pListaMarca[], int tMarca)
{
	int index;
	int rtn;
	int idModificar;
	char nuevaDescripcion[100];
	rtn = 0;


	if(eMarca_MostrarTodos(pListaMarca, tMarca) == 1)
	{
		eMarca_ValidarId(pListaMarca, tMarca,  "* INGRESE EL ID QUE DESEA MODIFICAR: \n", &idModificar);

		while (eMarca_BuscarPorID(pListaMarca, tMarca, idModificar) == -1)
		{
			printf("EL ID '%d' NO EXISTE.\n", idModificar);
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 0)
			{
				break;
			}

			eMarca_ValidarId(pListaMarca, tMarca,  "* INGRESE EL ID QUE DESEA MODIFICAR: \n", &idModificar);
		}

		index = eMarca_BuscarPorID(pListaMarca, tMarca, idModificar);

		if(index != -1)
		{
			eMarca_MostrarUno(pListaMarca[index]);
			get_String(nuevaDescripcion, 100, "* INGRESE LA NUEVA DESCRIPCION: ", "REINGRESE DESCRIPCION");
			if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
			{
				strcpy(pListaMarca[index].descripcion, nuevaDescripcion);
				rtn = 1;
			}
		}
	}else
	{
		puts("\n* NO HAY TRABAJOS CARGADOS.");
	}
	return rtn;
}


eMarca eMarca_CargarDatos(eMarca pListaMarca[], int tMarca)
{
	eMarca auxiliar;

	get_String(auxiliar.descripcion, 100, "* INGRESE DESCRIPCION: ", "REINGRESE DESCRIPCION");

	return auxiliar;
}


int eMarca_ObtenerIndexLibre(eMarca pListaMarca[], int tMarca)
{
	int rtn;
	int i;
	rtn = -1;

	if (tMarca > 0)
	{

		for (i = 0; i < tMarca; i++)
		{
			if (pListaMarca[i].isEmpty == LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


int eMarca_Alta(eMarca pListaMarca[], int tMarca, int* id)
{

	int rtn;
	int index;
	eMarca auxTra;
	rtn = 0;

	index = eMarca_ObtenerIndexLibre(pListaMarca, tMarca);

	if (index != -1)
	{

		auxTra = eMarca_CargarDatos(pListaMarca, tMarca);
		auxTra.id = utn_ObtenerID(id);
		auxTra.isEmpty = OCUPADO;
		pListaMarca[index] = auxTra;

		rtn = 1;
	}

	return rtn;
}
