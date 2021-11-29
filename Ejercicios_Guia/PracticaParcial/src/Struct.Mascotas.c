#include "Struct.Mascotas.h"
#include "utn.get.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
static int pListaMascotas_idIncremental = 0;

void eMascotas_Inicializar(eMascotas pListaMascotas[], int tMascotas) {
	int i;

	//EL LIMITE ES VALIDO
	if (tMascotas > 0)
	{
		//RECORRO TODO EL pListaMascotas
		for (i = 0; i < tMascotas; i++)
		{
			//SET ESTADO DE "LIBRE"
			pListaMascotas[i].isEmpty = LIBRE;
		}
	}
}


int eMascotas_ObtenerID()
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return pListaMascotas_idIncremental += 1;
}


int eMascotas_ObtenerIndexLibre(eMascotas pListaMascotas[], int tMascotas)
{
	int rtn = -1;
	int i;

	// EL LIMITE ES VALIDO
	if (tMascotas > 0)
	{
		//RECORRO TODO EL pListaMascotas
		for (i = 0; i < tMascotas; i++)
		{
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (pListaMascotas[i].isEmpty == LIBRE)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


int eMascotas_BuscarPorID(eMascotas pListaMascotas[], int tMascotas, int ID)
{
	int rtn = -1;
	int i;

	// EL LIMITE ES VALIDO
	if (tMascotas > 0)
	{
		//RECORRO TODO EL pListaMascotas
		for (i = 0; i < tMascotas; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (pListaMascotas[i].idMas == ID && pListaMascotas[i].isEmpty == OCUPADO)
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


void eMascotas_MostrarUno(eMascotas pListaMascotas)
{
	//PRINTF DE UN SOLO pListaMascotas
	printf("%-6d %-15s %-6d %-5c %-14s \n\n", pListaMascotas.idMas, pListaMascotas.nombre, pListaMascotas.edad, pListaMascotas.sexo, pListaMascotas.tipo);
}


int eMascotas_MostrarTodos(eMascotas pListaMascotas[], int tMascotas)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO pListaMascotas");
	printf("|ID   |NOMBRE        |EDAD  |SEXO  |TIPO           \n\n");
	//printf("%6s %13s %15s %15s %13s\n\n", "ID ", "NOMBRE ", "EDAD ", "SEXO ", "TIPO "); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	// EL LIMITE ES VALIDO
	if (tMascotas > 0)
	{
		//RECORRO TODO EL pListaMascotas
		for (i = 0; i < tMascotas; i++)
		{
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (pListaMascotas[i].isEmpty == OCUPADO)
			{
				//MUESTRO UN SOLO pListaMascotas
				eMascotas_MostrarUno(pListaMascotas[i]);
				//CONTADOR DE pListaMascotas
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO pListaMascotas PARA MOSTRAR (pListaMascotas SIN ALTAS)
	if (cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}


int eMascotas_MostrarDadosDeBaja(eMascotas pListaMascotas[], int tMascotas)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> pListaMascotas\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	// EL LIMITE ES VALIDO
	if (tMascotas > 0)
	{
		//RECORRO TODO EL pListaMascotas
		for (i = 0; i < tMascotas; i++)
		{
			//PREGUNTO POR SU ESTADO "BAJA"
			if (pListaMascotas[i].isEmpty == BAJA)
			{
				//MUESTRO UN SOLO pListaMascotas
				eMascotas_MostrarUno(pListaMascotas[i]);
				//CONTADOR DE pListaMascotas
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO pListaMascotas PARA MOSTRAR (pListaMascotas SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}


eMascotas eMascotas_CargarDatos(void)
{
	eMascotas auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/

	get_Nombre(auxiliar.nombre, 100, "* INGRESE EL NOMBRE: ");
	getInt(&auxiliar.edad, "* INGRESE LA EDAD: ");
	get_Sexo(&auxiliar.sexo, "* INGRESE EL SEXO 1. Masculino 0. Femenino: ");
	get_Tipo(auxiliar.tipo, "* INGRESE EL TIPO DE MASCOTA 1. Perro 2. Gato 3. RARO: ");
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */

	return auxiliar;
}


eMascotas eMascotas_ModificarUno(eMascotas pListaMascotas)
{
	eMascotas auxiliar = pListaMascotas;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}


int eMascotas_Alta(eMascotas pListaMascotas[], int tMascotas)
{

	int rtn = 0;
	eMascotas auxpListaMascotas;

	//BUSCO ESPACIO EN pListaMascotas
	int index = eMascotas_ObtenerIndexLibre(pListaMascotas, tMascotas);

	//SI INDEX == -1 pListaMascotas LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE pListaMascotas LIBRE
	if (index != -1)
	{
		//PIDO DATOS - CARGO pListaMascotas AUXILIAR
		auxpListaMascotas = eMascotas_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxpListaMascotas.idMas = eMascotas_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxpListaMascotas.isEmpty = OCUPADO;
		//SETEO EL pListaMascotas CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		pListaMascotas[index] = auxpListaMascotas;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}


int eMascotas_Baja(eMascotas pListaMascotas[], int tMascotas)
{
	int rtn = 0;
	int idMas;
	int index;
	int flag = 0;

	//LISTO TODOS LOS pListaMascotas
	if (eMascotas_MostrarTodos(pListaMascotas, tMascotas))
	{
		//BANDERA EN 1 SI HAY pListaMascotas DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY pListaMascotas PARA DAR DE BAJA
	if (flag == 1)
	{
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idMas);

		//BUSCO INDEX POR ID EN pListaMascotas
		while (eMascotas_BuscarPorID(pListaMascotas, tMascotas, idMas) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idMas);
		}

		//OBTENGO INDEX DEL pListaMascotas DE pListaMascotas A DAR DE BAJA
		index = eMascotas_BuscarPorID(pListaMascotas, tMascotas, idMas);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		pListaMascotas[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECtMascotasENTE
		rtn = 1;
	}

	return rtn;
}


int eMascotas_Modificacion(eMascotas pListaMascotas[], int tMascotas)
{
	int rtn = 0;
	int idMas;
	int index;
	int flag = 0;
	eMascotas auxiliar;

	//LISTO TODOS LOS pListaMascotas
	if (eMascotas_MostrarTodos(pListaMascotas, tMascotas)) {
		//BANDERA EN 1 SI HAY pListaMascotas DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY pListaMascotas PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		eMascotas_ValidarId(pListaMascotas, tMascotas, "INGRESE ID A DAR DE BAJA: ", &idMas);

		//BUSCO INDEX POR ID EN pListaMascotas
		while (eMascotas_BuscarPorID(pListaMascotas, tMascotas, idMas) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			eMascotas_ValidarId(pListaMascotas, tMascotas, "INGRESE ID A DAR DE BAJA: ", &idMas);

		}

		//OBTENGO INDEX DEL pListaMascotas DE pListaMascotas A MODIFICAR
		index = eMascotas_BuscarPorID(pListaMascotas, tMascotas, idMas);

		//LLAMO A FUNCION QUE MODIFICA pListaMascotas
		auxiliar = eMascotas_ModificarUno(pListaMascotas[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		pListaMascotas[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECtMascotasENTE
		rtn = 1;
	}

	return rtn;
}


void eMascotas_ValidarId(eMascotas ppListaMascotas[], int tMascotas, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < tMascotas; i++)
	{
		if(ppListaMascotas[i].idMas > mayor || i == 0)
		{
			mayor = ppListaMascotas[i].idMas;
		}
		if(ppListaMascotas[i].idMas < menor || i == 0)
		{
			menor = ppListaMascotas[i].idMas;
		}
	}

	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);

	*pResultado = numeroIngresado;

}


int eMascotas_Ordenamiento(eMascotas pListaMascotas[], int tMascotas, int criterio)
{
	int rtn = 0;
	int i;
	int j;
	eMascotas aux;

	/** EJEMPLO DE SORT CON ID DE pListaMascotas
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	// EL LIMITE ES VALIDO
	if (tMascotas > 0) {
		switch (criterio)
		{
		case -1:
			for (i = 0; i < tMascotas-1; i++)
			{
				for (j = i+1; j < tMascotas; j++)
				{
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (pListaMascotas[i].isEmpty == OCUPADO && pListaMascotas[j].isEmpty == OCUPADO)
					{
						//CRITERIO DE ORDENAMIENTO
						if (pListaMascotas[i].idMas > pListaMascotas[j].idMas)
						{
							//INTERCAMBIO POSICIONES EN pListaMascotas
							aux = pListaMascotas[i];
							pListaMascotas[i] = pListaMascotas[j];
							pListaMascotas[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < tMascotas-1; i++)
			{
				for (j = i+1; j < tMascotas; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (pListaMascotas[i].isEmpty == OCUPADO && pListaMascotas[j].isEmpty == OCUPADO)
					{
						//CRITERIO DE ORDENAMIENTO
						if (pListaMascotas[i].idMas < pListaMascotas[j].idMas)
						{
							//INTERCAMBIO POSICIONES EN pListaMascotas
							aux = pListaMascotas[i];
							pListaMascotas[i] = pListaMascotas[j];
							pListaMascotas[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}


