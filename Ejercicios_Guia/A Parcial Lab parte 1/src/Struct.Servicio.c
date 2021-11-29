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
	printf("%-6d %-19s %-11.2f \n\n", pListaServicio.id, pListaServicio.descripcion, pListaServicio.precio);
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
void eServicio_Inicializar(eServicio pListaServicio[], int tServicio)
{
	int i;

	if (tServicio > 0)
	{
		for (i = 0; i < tServicio; i++)
		{
			pListaServicio[i].isEmpty = LIBRE;
		}
	}
}


int eServicio_Baja(eServicio pListaServicio[], int tServicio)
{
	int rtn;
	int idTra;
	int index;
	rtn = 0;

	if(eServicio_MostrarTodos(pListaServicio, tServicio) == 1)
	{
		eServicio_ValidarId(pListaServicio, tServicio, "INGRESE ID A DAR DE BAJA: ", &idTra);

		while (eServicio_BuscarPorID(pListaServicio, tServicio, idTra) == -1)
		{
			printf("EL ID '%d' NO EXISTE.\n", idTra);
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 0)
			{
				break;
			}

			eServicio_ValidarId(pListaServicio, tServicio, "INGRESE ID A DAR DE BAJA: ", &idTra);

		}

		index = eServicio_BuscarPorID(pListaServicio, tServicio, idTra);
		if(index != -1)
		{
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 1)
			{
				pListaServicio[index].isEmpty = BAJA;
				rtn = 1;
			}
		}

	}else
	{
		puts("\n* NO HAY TRABAJOS CARGADOS.");
	}

	return rtn;
}


int eServicio_Modificar(eServicio pListaServicio[], int tServicio)
{
	int index;
	int rtn;
	int opcionModificar;
	int idModificar;
	float nuevoPrecio;
	char nuevaDescripcion[100];
	rtn = 0;


	if(eServicio_MostrarTodos(pListaServicio, tServicio) == 1)
	{
		eServicio_ValidarId(pListaServicio, tServicio,  "* INGRESE EL ID QUE DESEA MODIFICAR: \n", &idModificar);

		while (eServicio_BuscarPorID(pListaServicio, tServicio, idModificar) == -1)
		{
			printf("EL ID '%d' NO EXISTE.\n", idModificar);
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 0)
			{
				break;
			}

			eServicio_ValidarId(pListaServicio, tServicio,  "* INGRESE EL ID QUE DESEA MODIFICAR: \n", &idModificar);
		}

		index = eServicio_BuscarPorID(pListaServicio, tServicio, idModificar);

		if(index != -1)
		{
			utn_getNumero(&opcionModificar, "* Que desea modificar: \n1. DESCRIPCION \n2. PRECIO\n", 1, 2);

			switch(opcionModificar)
			{
			case 1:
				eServicio_MostrarUno(pListaServicio[index]);
				get_String(nuevaDescripcion, 100, "* INGRESE LA NUEVA DESCRIPCION: ", "REINGRESE DESCRIPCION");
				if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
				{
					strcpy(pListaServicio[index].descripcion, nuevaDescripcion);
					rtn = 1;
				}
				break;

			case 2:
				eServicio_MostrarUno(pListaServicio[index]);
				getFloat(&nuevoPrecio, "* INGRESE EL NUEVO PRECIO: ");

				if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
				{
					pListaServicio[index].precio = nuevoPrecio;
					rtn = 1;
				}
				break;
			}
		}
	}else
	{
		puts("\n* NO HAY TRABAJOS CARGADOS.");
	}
	return rtn;
}


eServicio eServicio_CargarDatos(eServicio pListaServicio[], int tServicio)
{
	eServicio auxiliar;

	get_String(auxiliar.descripcion, 100, "* INGRESE DESCRIPCION: ", "REINGRESE DESCRIPCION");
	getFloat(&auxiliar.precio, "* INGRESE EL PRECIO: ");

	return auxiliar;
}


int eServicio_ObtenerIndexLibre(eServicio pListaServicio[], int tServicio)
{
	int rtn;
	int i;
	rtn = -1;

	if (tServicio > 0)
	{

		for (i = 0; i < tServicio; i++)
		{
			if (pListaServicio[i].isEmpty == LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


int eServicio_Alta(eServicio pListaServicio[], int tServicio, int* id)
{

	int rtn;
	int index;
	eServicio auxTra;
	rtn = 0;

	index = eServicio_ObtenerIndexLibre(pListaServicio, tServicio);

	if (index != -1)
	{

		auxTra = eServicio_CargarDatos(pListaServicio, tServicio);
		auxTra.id = utn_ObtenerID(id);
		auxTra.isEmpty = OCUPADO;
		pListaServicio[index] = auxTra;

		rtn = 1;
	}

	return rtn;
}

