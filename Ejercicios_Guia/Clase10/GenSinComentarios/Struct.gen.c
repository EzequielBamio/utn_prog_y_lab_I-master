#include "Struct.gen.h"
#include "utn.get.h"

void eGen_Inicializar(eGen pArray[], int tArray) {
	int i;

	if (tArray > 0)
	{
		for (i = 0; i < tArray; i++)
		{
			pArray[i].isEmpty = LIBRE;
		}
	}
}

int eGen_ObtenerIndexLibre(eGen pArray[], int tArray)
{
	int rtn = -1;
	int i;

	if (tArray > 0)
	{

		for (i = 0; i < tArray; i++)
		{
			if (pArray[i].isEmpty == LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


int eGen_BuscarPorID(eGen pArray[], int tArray, int ID)
{
	int rtn = -1;
	int i;

	if (tArray > 0)
	{

		for (i = 0; i < tArray; i++)
		{
			if (pArray[i].idGen == ID && pArray[i].isEmpty == OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


void eGen_MostrarUno(eGen Gen)
{
	//PRINTF DE UN SOLO Gen
	printf("%5d\n", Gen.idGen);
}


int eGen_MostrarTodos(eGen pArray[], int tArray)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Gen");
	printf("%5s\n\n", "ID");

	if (tArray > 0)
	{

		for (i = 0; i < tArray; i++)
		{
			if (pArray[i].isEmpty == OCUPADO)
			{

				eGen_MostrarUno(pArray[i]);

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


int eGen_MostrarDadosDeBaja(eGen pArray[], int tArray)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\t> Gen\n");
	printf("%5s\n\n", "ID");

	if (tArray > 0)
	{

		for (i = 0; i < tArray; i++)
		{

			if (pArray[i].isEmpty == BAJA)
			{

				eGen_MostrarUno(pArray[i]);

				cantidad++;
			}
		}
	}


	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}


eGen eGen_CargarDatos(void)
{
	eGen auxiliar;

	return auxiliar;
}


eGen eGen_ModificarUno(eGen Gen)
{
	eGen auxiliar = Gen;

	return auxiliar;
}


int eGen_Alta(eGen pArray[], int tArray)
{

	int rtn;
	rtn = 0;
	int auxiliar;
	eGen auxGen;

	int index = eGen_ObtenerIndexLibre(pArray, tArray);

	if (index != -1)
	{
		getInt(&auxiliar, "Ingrese el Id del producto: ");

		while(eGen_BuscarPorID(pArray, tArray, auxiliar) != -1)
		{
			getInt(&auxiliar, "ERROR: El ID ya existe, Ingrese otro: ");
		}
		auxGen = eGen_CargarDatos();
		auxGen.idGen = auxiliar;
		auxGen.isEmpty = OCUPADO;
		pArray[index] = auxGen;

		rtn = 1;
	}

	return rtn;
}


int eGen_Baja(eGen pArray[], int tArray)
{
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;

	if (eGen_MostrarTodos(pArray, tArray))
	{
		flag = 1;
	}

	if (flag == 1)
	{
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idGen);

		while (eGen_BuscarPorID(pArray, tArray, idGen) == -1) {
			puts("NO EXISTE ID.");

			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idGen);
		}

		index = eGen_BuscarPorID(pArray, tArray, idGen);

		pArray[index].isEmpty = BAJA;

		rtn = 1;
	}

	return rtn;
}


int eGen_Modificacion(eGen pArray[], int tArray)
{
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;
	eGen auxiliar;

	if(eGen_MostrarTodos(pArray, tArray)) {
		flag = 1;
	}

	if(flag) {
		eGen_ValidarId(pArray, tArray, "INGRESE ID A DAR DE BAJA: ", &idGen);

		while (eGen_BuscarPorID(pArray, tArray, idGen) == -1) {
			puts("NO EXISTE ID.");

			eGen_ValidarId(pArray, tArray, "INGRESE ID A DAR DE BAJA: ", &idGen);

		}

		index = eGen_BuscarPorID(pArray, tArray, idGen);

		auxiliar = eGen_ModificarUno(pArray[index]);

		pArray[index] = auxiliar;

		rtn = 1;
	}

	return rtn;
}


void eGen_ValidarId(eGen ppArray[], int tArray, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < tArray; i++)
	{
		if(ppArray[i].idGen > mayor || i == 0)
		{
			mayor = ppArray[i].idGen;
		}
		if(ppArray[i].idGen < menor || i == 0)
		{
			menor = ppArray[i].idGen;
		}
	}

	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);

	*pResultado = numeroIngresado;

}


int eGen_Ordenamiento(eGen pArray[], int tArray, int criterio)
{
	int rtn = 0;
	int i;
	int j;
	eGen aux;

	if (tArray > 0) {
		switch (criterio)
		{
		case -1:
			for (i = 0; i < tArray-1; i++)
			{
				for (j = i+1; j < tArray; j++)
				{
					if (pArray[i].isEmpty == OCUPADO && pArray[j].isEmpty == OCUPADO)
					{
						if (pArray[i].idGen > pArray[j].idGen)
						{
							aux = pArray[i];
							pArray[i] = pArray[j];
							pArray[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < tArray-1; i++)
			{
				for (j = i+1; j < tArray; j++) {
					if (pArray[i].isEmpty == OCUPADO && pArray[j].isEmpty == OCUPADO)
					{
						if (pArray[i].idGen < pArray[j].idGen)
						{
							aux = pArray[i];
							pArray[i] = pArray[j];
							pArray[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			rtn = 0;
			break;
		}
	}
	return rtn;
}
