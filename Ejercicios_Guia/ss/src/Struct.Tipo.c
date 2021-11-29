#include "Struct.Tipo.h"
#include "utn.Get.h"

void Tipo_GetId(eTipoProducto pListaTipo[], int tTipo, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < tTipo; i++)
	{
		if(pListaTipo[i].idTipo > mayor || i == 0)
		{
			mayor = pListaTipo[i].idTipo;
		}
		if(pListaTipo[i].idTipo < menor || i == 0)
		{
			menor = pListaTipo[i].idTipo;
		}
	}

	Tipo_MostrarTodos(pListaTipo, tTipo);
	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);
	*pResultado = numeroIngresado;

}


//ABM -------------
int Tipo_BuscarLibre(eTipoProducto pListaTipo[], int tTipo)
{
	int i;
	int index;
	index = -1;
	for(i = 0; i < tTipo; i++)
	{
		if(pListaTipo[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int Tipo_BuscarID(eTipoProducto pListaTipo[], int tTipo, int id)
{
	int i;
	int rtn;
	rtn = -1;

	for(i = 0; i < tTipo; i++)
	{
		if(pListaTipo[i].idTipo == id && pListaTipo[i].isEmpty == OCUPADO)
		{
			rtn = i;
			break;
		}
	}

	return rtn;
}



//int Tipo_Modificar(eTipoProducto pListaTipo[], int tTipo)
//{
//	int index;
//	int rtn;
//	int idModificar;
//	char auxiliarDescripcion[SIZE_ARRAY];
//	rtn = 0;
//
//	Tipo_MostrarTodos(pListaTipo, tTipo);
//
//	getInt(&idModificar, "* Ingrese el ID del Tipo que desea eliminar\n");
//	index = Tipo_BuscarID(pListaTipo, tTipo, idModificar);
//
//	if(index != -1)
//	{
//		myGets(auxiliarDescripcion, SIZE_ARRAY, "Ingrese la nueva descripcion: ");
//
//		if(Confirmar_Respuesta("Seguro que desea modificarlo? 1. Si 0. No: ", "ERROR: Seguro que desea modificarlo?\nIngrese 1. Si 0. No: ") == 1)
//		{
//			strncpy(pListaTipo[index].descripcionTipo, auxiliarDescripcion, SIZE_ARRAY);
//			rtn = 1;
//		}
//
//	}
//
//	return rtn;
//}


int Tipo_MostrarTodos(eTipoProducto pListaTipo[], int tTipo)
{
    int i;
    int rtn;
    rtn = 0;

    printf("%4s %15s", "ID", "DESCRIPCION \n");

    for(i=0; i < tTipo; i++)
    {
    	if(pListaTipo[i].isEmpty != VACIO)
    	{
    		Tipo_MostrarUno(pListaTipo[i]);
     		rtn = 1;
    	}
    }
    return rtn;
}


void Tipo_MostrarUno(eTipoProducto pListaTipo)
{

    printf("\n%5d %10s\n", pListaTipo.idTipo,
    					pListaTipo.descripcionTipo);
}


//int Tipo_Cargar(eTipoProducto pListaTipo[], int tTipo)
//{
//    int i;
//    int rtn;
//    int auxiliar;
//    rtn = -1;
//
//    i = Tipo_BuscarLibre(pListaTipo, tTipo);
//    if(i != -1)
//    {
//    	getInt(&auxiliar, "Ingrese el Id del Tipo: ");
//
//    	while(Tipo_BuscarID(pListaTipo, tTipo, auxiliar) != -1)
//    	{
//    		getInt(&auxiliar, "ERROR: El ID ya existe, Ingrese otro: ");
//    	}
//		pListaTipo[i] = Tipo_PedirDatos();
//		pListaTipo[i].idTipo = auxiliar;
//		rtn = 1;
//    }
//
//    return rtn;
//}


eTipoProducto Tipo_PedirDatos()
{
	eTipoProducto TipoIngresado;

	myGets(TipoIngresado.descripcionTipo, 100,"Ingrese la descripcion del Tipo: ");

    TipoIngresado.isEmpty = OCUPADO;

    return TipoIngresado;
}


void Tipo_Inicializar(eTipoProducto pListaTipo[], int tTipo)
{
	int i;

	for(i=0; i<tTipo; i++)
	{
		pListaTipo[i].isEmpty = VACIO;
	}
}
