#include "Struct.General.h"
#include "Struct.Servicio.h"
#include "Struct.Trabajo.h"
#include "Struct.Marca.h"
#include "utn.Get.h"

//FUNCIONES - INICIO
int Total_ServiciosPrestados(float* totalPrecio, eServicio pListaServicio[], int tServicio, eTrabajo pListaTrabajo[], int tTrabajo)
{
	int i;
	int j;
	int rtn;
	float acumuladorPrecios;
	acumuladorPrecios = 0;
	rtn = 0;

	for(i = 0; i < tTrabajo; i++)
	{
		j = eServicio_BuscarPorID(pListaServicio, tServicio, pListaTrabajo[i].idServicio);
		if(j != -1)
		{
			acumuladorPrecios += pListaServicio[j].precio;
			rtn = 1;

		}
	}

	*totalPrecio = acumuladorPrecios;

	return rtn;
}








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

//FUNCIONES - FIN





// FUNCIONES MENU - INICIO

void Sub_MenuTrabajos(eServicio pListaServicio[], int tServicio, eTrabajo pListaTrabajo[], int tTrabajo, eMarca pListaMarca[], int tMarca)
{
	int opcion;
	int trabajoId;
	trabajoId = 0; //Empieza el ID en 1

	do {
	    printf("\n********************* MENU TRABAJOS *********************\n");
		//MENU PRINT
		printf("1. ALTA\n");
		printf("2. BAJA \n");
		printf("3. MODIFICACION\n");
		printf("4. LISTADO\n");

		printf(" \n");

		printf("0. Salir\n");

		utn_getNumero(&opcion, "INGRESE OPCION: ", 0, 4);
		system("cls");

		//MENU SWITCH
		switch (opcion)
		{
		case 0:
			opcion = 0;
			break;
		case 1:
			//ALTA TRABAJOS
			if (eTrabajo_Alta(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaMarca, tMarca, &trabajoId) == 1)
			{
				puts("* SE HA DADO DE ALTA EXITOSAMENTE");

			}else
			{
				puts("* ERROR. SIN ESPACIO PARA ALMACENAR");
			}

			system("pause");
			break;
		case 2:
			if (eTrabajo_Baja(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaMarca, tMarca) == 1)
			{
				puts("\n* BAJA EXITOSA");
				eTrabajo_MostrarTodos(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaMarca, tMarca);
			}else
			{
				puts("\n* BAJA CANCELADA");
			}

			system("pause");
			break;
		case 3:
			if (eTrabajo_Modificar(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaMarca, tMarca) == 1)
			{
				puts("\n* MODIFICACION EXITOSA\n");
				eTrabajo_MostrarTodos(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaMarca, tMarca);
			}else
			{
				puts("\n* MODIFICACION CANCELADA");
			}

			system("pause");
			break;
		case 4:
			if(eTrabajo_MostrarTodos(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaMarca, tMarca) == 0)
			{
				puts("* NO HAY TRABAJOS PARA MOSTRAR.");
			}

			system("pause");
			break;

		}
		system("cls");


	} while (opcion != 0);
}


void Sub_MenuServicios(eServicio pListaServicio[], int tServicio)
{
	int opcion;
	int servicioId;
	servicioId = 0; //Empieza el ID en 1

	do {
	    printf("\n********************* MENU SERVICIOS *********************\n");
		//MENU PRINT
		printf("1. ALTA\n");
		printf("2. BAJA \n");
		printf("3. MODIFICACION\n");
		printf("4. LISTADO\n");

		printf(" \n");

		printf("0. Salir\n");

		utn_getNumero(&opcion, "INGRESE OPCION: ", 0, 4);
		system("cls");

		//MENU SWITCH
		switch (opcion)
		{
		case 0:
			opcion = 0;
			break;
		case 1:
			//ALTA TRABAJOS
			if (eServicio_Alta(pListaServicio, tServicio, &servicioId) == 1)
			{
				puts("* SE HA DADO DE ALTA EXITOSAMENTE");

			}else
			{
				puts("* ERROR. SIN ESPACIO PARA ALMACENAR");
			}

			system("pause");
			break;
		case 2:
			if (eServicio_Baja(pListaServicio, tServicio) == 1)
			{
				puts("\n* BAJA EXITOSA");
				eServicio_MostrarTodos(pListaServicio, tServicio);
			}else
			{
				puts("\n* BAJA CANCELADA");
			}

			system("pause");
			break;
		case 3:
			if (eServicio_Modificar(pListaServicio, tServicio) == 1)
			{
				puts("\n* MODIFICACION EXITOSA\n");
				eServicio_MostrarTodos(pListaServicio, tServicio);
			}else
			{
				puts("\n* MODIFICACION CANCELADA");
			}

			system("pause");
			break;
		case 4:
			if(eServicio_MostrarTodos(pListaServicio, tServicio) == 0)
			{
				puts("* NO HAY SERVICIOS PARA MOSTRAR.");
			}
			system("pause");
			break;
		}
		system("cls");


	} while (opcion != 0);
}


void Sub_MenuMarca(eMarca pListaMarca[], int tMarca)
{
	int opcion;
	int marcaId;
	marcaId = 0; //Empieza el ID en 1

	do {
	    printf("\n********************* MENU MARCA *********************\n");
		//MENU PRINT
		printf("1. ALTA\n");
		printf("2. BAJA \n");
		printf("3. MODIFICACION\n");
		printf("4. LISTADO\n");

		printf(" \n");

		printf("0. Salir\n");

		utn_getNumero(&opcion, "INGRESE OPCION: ", 0, 4);
		system("cls");

		//MENU SWITCH
		switch (opcion)
		{
		case 0:
			opcion = 0;
			break;
		case 1:
			//ALTA TRABAJOS
			if (eMarca_Alta(pListaMarca, tMarca, &marcaId) == 1)
			{
				puts("* SE HA DADO DE ALTA EXITOSAMENTE");

			}else
			{
				puts("* ERROR. SIN ESPACIO PARA ALMACENAR");
			}

			system("pause");
			break;
		case 2:
			if (eMarca_Baja(pListaMarca, tMarca) == 1)
			{
				puts("\n* BAJA EXITOSA");
				eMarca_MostrarTodos(pListaMarca, tMarca);
			}else
			{
				puts("\n* BAJA CANCELADA");
			}

			system("pause");
			break;
		case 3:
			if (eMarca_Modificar(pListaMarca, tMarca) == 1)
			{
				puts("\n* MODIFICACION EXITOSA\n");
				eMarca_MostrarTodos(pListaMarca, tMarca);
			}else
			{
				puts("\n* MODIFICACION CANCELADA");
			}

			system("pause");
			break;
		case 4:
			if(eMarca_MostrarTodos(pListaMarca, tMarca) == 0)
			{
				puts("* NO HAY SERVICIOS PARA MOSTRAR.");
			}
			system("pause");
			break;
		}
		system("cls");


	} while (opcion != 0);
}

// FUNCIONES MENU - FIN




// FUNCIONES TRABAJO - INICIO
void eTrabajo_Ordenamiento(eTrabajo pListaTrabajo[], int tTrabajo, eMarca pListaMarca[], int tMarca)
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
							p = eMarca_BuscarPorID(pListaMarca, tMarca, pListaTrabajo[i].marcaBicicleta);
							x = eMarca_BuscarPorID(pListaMarca, tMarca, pListaTrabajo[j].marcaBicicleta);
							if((strcmp(pListaMarca[p].descripcion, pListaMarca[x].descripcion)) > 0)
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


void eTrabajo_MostrarUno(eTrabajo pListaTrabajo, eServicio pListaServicio, eMarca pListaMarca)
{
	//PRINTF DE UN SOLO pListaTrabajo
	printf("%-6d %-15s %-6d %-10s %d-%d-%d \n\n", pListaTrabajo.id,
												pListaMarca.descripcion,
												pListaTrabajo.rodadoBicicleta,
												pListaServicio.descripcion,
												pListaTrabajo.fecha.dia,
												pListaTrabajo.fecha.mes,
												pListaTrabajo.fecha.anio);
}


int eTrabajo_MostrarTodos(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca)
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
			p = eMarca_BuscarPorID(pListaMarca, tMarca, pListaTrabajo[i].marcaBicicleta);
			if (pListaTrabajo[i].isEmpty == OCUPADO)
			{
				eTrabajo_MostrarUno(pListaTrabajo[i], pListaServicio[j], pListaMarca[p]);
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


int eTrabajo_Baja(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca)
{
	int rtn;
	int idTra;
	int index;
	rtn = 0;

	if(eTrabajo_MostrarTodos(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaMarca, tMarca) == 1)
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
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 1)
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


int eTrabajo_Modificar(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca)
{
	int index;
	int rtn;
	int idModificar;
	int opcionModificar;
	int nuevaMarca;
	int nuevoServicio;
	rtn = 0;


	if(eTrabajo_MostrarTodos(pListaTrabajo, tTrabajo, pListaServicio, tServicio, pListaMarca, tMarca) == 1)
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
					eMarca_ValidarId(pListaMarca, tMarca, "* INGRESE EL NUEVA MARCA: ", &nuevaMarca);
					if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
					{

						pListaTrabajo[index].marcaBicicleta = nuevaMarca;
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


eTrabajo eTrabajo_CargarDatos(eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca)
{
	eTrabajo auxiliar;
	eMarca_MostrarTodos(pListaMarca, tMarca);
	eMarca_ValidarId(pListaMarca, tMarca, "* INGRESE EL ID DE LA MARCA: ", &auxiliar.marcaBicicleta);
	getInt(&auxiliar.rodadoBicicleta, "* INGRESE LA RODADO DE BICICLETA: ");
	eServicio_MostrarTodos(pListaServicio, tServicio);
	eServicio_ValidarId(pListaServicio, tServicio, "* INGRESE EL ID DEL SERVICIO: ", &auxiliar.idServicio);
	utn_getNumero(&auxiliar.fecha.dia, "* INGRESE EL DIA: ", 1, 30);
	utn_getNumero(&auxiliar.fecha.mes, "* INGRESE EL MES: ", 1, 12);
	utn_getNumero(&auxiliar.fecha.anio, "* INGRESE EL ANIO: ", 1950, 2090);

	return auxiliar;
}


int eTrabajo_Alta(eTrabajo pListaTrabajo[], int tTrabajo, eServicio pListaServicio[], int tServicio, eMarca pListaMarca[], int tMarca, int* id)
{

	int rtn;
	eTrabajo auxTra;
	rtn = 0;

	int index = eTrabajo_ObtenerIndexLibre(pListaTrabajo, tTrabajo);

	if (index != -1)
	{

		auxTra = eTrabajo_CargarDatos(pListaServicio, tServicio, pListaMarca, tMarca);
		auxTra.id = utn_ObtenerID(id);
		auxTra.isEmpty = OCUPADO;
		pListaTrabajo[index] = auxTra;

		rtn = 1;
	}

	return rtn;
}

// FUNCIONES TRABAJO - FIN

