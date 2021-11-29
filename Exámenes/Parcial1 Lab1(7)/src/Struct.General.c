#include "Struct.General.h"
#include "Struct.Servicio.h"
#include "Struct.Trabajo.h"
#include "Struct.Bicicleta.h"
#include "utn.Get.h"

//J - INICIO
int eTrabajos_CantidadBicicletasRojo(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta)
{
	int i;
	int j;
	int rtn;
	int contadorBicicletaRojo;
	contadorBicicletaRojo = 0;
	rtn = -1;

	for(i = 0; i < tTrabajo; i++)
	{
		j = eBicicleta_BuscarPorID(pListaBicicleta, tBicicleta, pListaTrabajo[i].idBicicleta);
		if(strcmp(pListaBicicleta[j].color, "Rojo") == 0)
		{
			contadorBicicletaRojo++;
		}
	}

	if(contadorBicicletaRojo != 0)
	{
		rtn = contadorBicicletaRojo;
	}

	return rtn;
}
//J - FIN


//I - INICIO
void eServicios_MostrarUnListadoServicioConBicicleta(eTrabajo pListaTrabajo, eServicio pListaServicio, eBicicleta pListaBicicleta)
{
	printf("%-6d %-19s %-15.2f | %-10d %-14s %-10d %-15s\n\n", pListaServicio.id,
																pListaServicio.descripcion,
																pListaServicio.precio,
																pListaBicicleta.id,
																pListaBicicleta.marca,
																pListaBicicleta.rodado,
																pListaBicicleta.color);
}
void eServicios_MostrarTodosListadoServicioConBicicleta(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta)
{
	int i;
	int j;
	int p;

	printf("|ID   |DESCRIPCION        |PRECIO      	   |ID         |MARCA        |RODADO      |COLOR           \n\n");

	for(i = 0; i < tTrabajo; i++)
	{
		j = eServicio_BuscarPorID(pListaServicio, tServicio, pListaTrabajo[i].idServicio);
		p = eBicicleta_BuscarPorID(pListaBicicleta, tBicicleta, pListaTrabajo[i].idBicicleta);
		if(j != -1 && p != -1)
		{
			eServicios_MostrarUnListadoServicioConBicicleta(pListaTrabajo[i], pListaServicio[j], pListaBicicleta[p]);
		}

	}
}
//I - FIN


//H - INICIO
void aux_Inicializar(eAuxiliar auxiliar[], eServicio pListaServicio[], int tServicio)
{
	int i;

	for(i = 0; i < tServicio; i++)
	{
		auxiliar[i].id = pListaServicio[i].id;
		auxiliar[i].contador = 0;
	}
}

int aux_BuscarId(eAuxiliar auxiliar[], int tAuxiliar, int id)
{
	int i;
	int rtn;
	rtn = -1;
	for(i = 0; i < tAuxiliar; i++)
	{
		if(auxiliar[i].id == id)
		{
			rtn = i;
			break;
		}
	}

	return rtn;
}

void aux_Contador(eTrabajo pListaTrabajo[], int tTrabajo, eAuxiliar auxiliar[], eServicio pListaServicio[], int tServicio)
{
	int i;
	int j;

	for(i = 0; i < tTrabajo; i++)
	{
		j = aux_BuscarId(auxiliar, tServicio, pListaTrabajo[i].idServicio);
		if(j != -1)
		{
			auxiliar[j].contador++;
		}
	}
}

int aux_calcularMaximo(eAuxiliar auxiliar[], int tAuxiliar)
{
	int maximo;
	int i;

	for(i = 0; i < tAuxiliar; i++)
		{
			if(auxiliar[i].contador > maximo || i == 0)
			{
				maximo = auxiliar[i].contador;
			}
		}

	return maximo;
}

void aux_MostrarMayor(eAuxiliar auxiliar[], eServicio pListaServicio[], int tServicio, int maximo)
{
	int i;

	for(i = 0; i < tServicio; i++)
	{
		if(maximo == auxiliar[i].contador)
		{
			eServicio_MostrarUno(pListaServicio[i]);
		}
	}
}

int eTrabajo_ConMasServiciosPrestados(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio)
{
	eAuxiliar auxiliar[tServicio];
	int maximo;
	maximo = 0;

	aux_Inicializar(auxiliar, pListaServicio, tServicio);
	aux_Contador(pListaTrabajo, tTrabajo, auxiliar, pListaServicio, tServicio);
	maximo = aux_calcularMaximo(auxiliar, tServicio);
	aux_MostrarMayor(auxiliar, pListaServicio, tServicio, maximo);

	return maximo;
}
//H - FIN


//G - INICIO
void eTrabajo_OrdenamientoMarcaBicicleta(eTrabajo pListaTrabajo[], int tTrabajo, eBicicleta pListaBicicleta[], int tBicicleta)
{
	int i;
	int j;
	int p;
	int x;
	eTrabajo aux;

	if (tTrabajo > 0)
	{
		for (i = 0; i < tTrabajo-1; i++)
		{
			for (j = i+1; j < tTrabajo; j++)
			{
				if (pListaTrabajo[i].isEmpty == OCUPADO && pListaTrabajo[j].isEmpty == OCUPADO)
				{
					p = eBicicleta_BuscarPorID(pListaBicicleta, tBicicleta, pListaTrabajo[i].idBicicleta);
					x = eBicicleta_BuscarPorID(pListaBicicleta, tBicicleta, pListaTrabajo[j].idBicicleta);
					if((strcmp(pListaBicicleta[p].marca, pListaBicicleta[x].marca)) > 0)
					{
					   aux = pListaTrabajo[i];
					   pListaTrabajo[i] = pListaTrabajo[j];
					   pListaTrabajo[j] = aux;
					}
				}
			}
		}
	}
}
//G - FIN


// FUNCIONES TRABAJO - INICIO
int Total_ServiciosPrestados(eServicio pListaServicio[], int tServicio, eTrabajo pListaTrabajo[], int tTrabajo)
{
	int i;
	int j;
	int acumuladorPrecios;
	acumuladorPrecios = 0;

	for(i = 0; i < tTrabajo; i++)
	{
		j = eServicio_BuscarPorID(pListaServicio, tServicio, pListaTrabajo[i].idServicio);
		if(j != -1)
		{
			acumuladorPrecios += pListaServicio[j].precio;

		}
	}

	return acumuladorPrecios;
}


void eTrabajo_Ordenamiento(eTrabajo pListaTrabajo[], int tTrabajo, eBicicleta pListaBicicleta[], int tBicicleta)
{
	int i;
	int j;
	int p;
	int x;
	eTrabajo aux;

	if (tTrabajo > 0)
	{
		for (i = 0; i < tTrabajo-1; i++)
		{
			for (j = i+1; j < tTrabajo; j++)
			{
				if (pListaTrabajo[i].isEmpty == OCUPADO && pListaTrabajo[j].isEmpty == OCUPADO)
				{
					if (pListaTrabajo[i].fecha.anio > pListaTrabajo[j].fecha.anio)
					{
						aux = pListaTrabajo[i];
						pListaTrabajo[i] = pListaTrabajo[j];
						pListaTrabajo[j] = aux;
					}else
					{
						if(pListaTrabajo[i].fecha.anio == pListaTrabajo[j].fecha.anio)
						{
							p = eBicicleta_BuscarPorID(pListaBicicleta, tBicicleta, pListaTrabajo[i].idBicicleta);
							x = eBicicleta_BuscarPorID(pListaBicicleta, tBicicleta, pListaTrabajo[j].idBicicleta);
							if((strcmp(pListaBicicleta[p].marca, pListaBicicleta[x].marca)) > 0)
							{
								aux = pListaTrabajo[i];
							   pListaTrabajo[i] = pListaTrabajo[j];
							   pListaTrabajo[j] = aux;
							}
						}
					}
				}
			}
		}
	}
}


void eTrabajo_MostrarUno(eTrabajo pListaTrabajo, eServicio pListaServicio, eBicicleta pListaBicicleta)
{
	//PRINTF DE UN SOLO pListaTrabajo
	printf("%-6d %-15s %-6d %-10s %d-%d-%d \n\n", pListaTrabajo.id,
												pListaBicicleta.marca,
												pListaBicicleta.rodado,
												pListaServicio.descripcion,
												pListaTrabajo.fecha.dia,
												pListaTrabajo.fecha.mes,
												pListaTrabajo.fecha.anio);
}


int eTrabajo_MostrarTodos(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta)
{
	int i;
	int j;
	int p;
	int rtn;
	int cantidad;

	rtn = 0;
	cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO de Trabajo");
	printf("|ID   |MARCA        |RODADO  |SERVICIO  |FECHA           \n\n");

	if (tTrabajo > 0)
	{
		for (i = 0; i < tTrabajo; i++)
		{
			j = eServicio_BuscarPorID(pListaServicio, tServicio, pListaTrabajo[i].idServicio);
			p = eBicicleta_BuscarPorID(pListaBicicleta, tBicicleta, pListaTrabajo[i].idBicicleta);
			if (pListaTrabajo[i].isEmpty == OCUPADO)
			{
				eTrabajo_MostrarUno(pListaTrabajo[i], pListaServicio[j], pListaBicicleta[p]);
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


int eTrabajo_Baja(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta)
{
	int rtn;
	int idTra;
	int index;
	rtn = 0;

	if(eTrabajo_MostrarTodos(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaBicicleta, tBicicleta) == 1)
	{
		eTrabajo_ValidarId(pListaTrabajo, tTrabajo, "INGRESE ID A DAR DE BAJA: ", &idTra);

		while (eTrabajo_BuscarPorID(pListaTrabajo, tTrabajo, idTra) == -1)
		{
			printf("EL ID '%d' NO EXISTE.\n", idTra);
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 0)
			{
				break;
			}

			eTrabajo_ValidarId(pListaTrabajo, tTrabajo, "INGRESE ID A DAR DE BAJA: ", &idTra);

		}

		index = eTrabajo_BuscarPorID(pListaTrabajo, tTrabajo, idTra);
		if(index != -1)
		{
			if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
			{
				pListaTrabajo[index].isEmpty = BAJA;
				rtn = 1;
			}
		}

	}else
	{
		puts("\n* NO HAY TRABAJOS CARGADOS.");
	}

	return rtn;
}


int eTrabajo_Modificar(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta)
{
	int index;
	int rtn;
	int idModificar;
	int opcionModificar;
	int nuevaMarca;
	int nuevoServicio;

	rtn = 0;


	if(eTrabajo_MostrarTodos(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaBicicleta, tBicicleta) == 1)
	{
		eTrabajo_ValidarId(pListaTrabajo, tTrabajo,  "* INGRESE EL ID QUE DESEA MODIFICAR: \n", &idModificar);

		while (eTrabajo_BuscarPorID(pListaTrabajo, tTrabajo, idModificar) == -1)
		{
			printf("EL ID '%d' NO EXISTE.\n", idModificar);
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 0)
			{
				break;
			}

			eTrabajo_ValidarId(pListaTrabajo, tTrabajo,  "* INGRESE EL ID QUE DESEA MODIFICAR: \n", &idModificar);
		}

		index = eTrabajo_BuscarPorID(pListaTrabajo, tTrabajo, idModificar);

		if(index != -1)
		{
				utn_getNumero(&opcionModificar, "* Que desea modificar: \n1. MARCA \n2. SERVICIO\n", 1, 2);

				switch(opcionModificar)
				{
				case 1:
					eBicicleta_MostrarTodos(pListaBicicleta, tBicicleta);
					eBicicleta_ValidarId(pListaBicicleta, tBicicleta, "* INGRESE EL ID DE LA NUEVA MARCA: ", &nuevaMarca);
					if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
					{
						pListaTrabajo[index].idBicicleta = nuevaMarca;
						rtn = 1;
					}
					break;

				case 2:
					eServicio_MostrarTodos(pListaServicio, tServicio);
					eServicio_ValidarId(pListaServicio, tServicio, "* INGRESE EL ID DEL NUEVO SERVICIO: ", &nuevoServicio);

					if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
					{
						pListaTrabajo[index].idServicio = nuevoServicio;
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


eTrabajo eTrabajo_CargarDatos(eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta)
{
	eTrabajo auxiliar;

	eBicicleta_MostrarTodos(pListaBicicleta, tBicicleta);
	eBicicleta_ValidarId(pListaBicicleta, tBicicleta, "* INGRESE LA ID DE LA BICICLETA: ", &auxiliar.idBicicleta);
	eServicio_MostrarTodos(pListaServicio, tServicio);
	eServicio_ValidarId(pListaServicio, tServicio, "* INGRESE EL ID DEL SERVICIO: ", &auxiliar.idServicio);
	utn_getNumero(&auxiliar.fecha.dia, "* INGRESE EL DIA: ", 1, 30);
	utn_getNumero(&auxiliar.fecha.mes, "* INGRESE EL MES: ", 1, 12);
	utn_getNumero(&auxiliar.fecha.anio, "* INGRESE EL ANIO: ", 1950, 2090);

	return auxiliar;
}


int eTrabajo_Alta(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eBicicleta pListaBicicleta[], int tBicicleta, int* id)
{

	int rtn;
	eTrabajo auxTra;
	rtn = 0;

	int index = eTrabajo_ObtenerIndexLibre(pListaTrabajo, tTrabajo);

	if (index != -1)
	{
		auxTra = eTrabajo_CargarDatos(pListaServicio, tServicio, pListaBicicleta, tBicicleta);
		auxTra.id = utn_ObtenerID(id);
		auxTra.isEmpty = OCUPADO;
		pListaTrabajo[index] = auxTra;

		rtn = 1;

	}

	return rtn;
}
// FUNCIONES TRABAJO - FIN



