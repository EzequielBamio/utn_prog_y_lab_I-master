#include "Struct.Nacionalidad.h"
#include "utn.Get.h"


void Nacionalidad_GetId(eNacionalidad pListaNacionalidad[], int tNacionalidad, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < tNacionalidad; i++)
	{
		if(pListaNacionalidad[i].idNacionalidad > mayor || i == 0)
		{
			mayor = pListaNacionalidad[i].idNacionalidad;
		}
		if(pListaNacionalidad[i].idNacionalidad < menor || i == 0)
		{
			menor = pListaNacionalidad[i].idNacionalidad;
		}
	}

	Nacionalidad_MostrarTodos(pListaNacionalidad, tNacionalidad);
	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);
	*pResultado = numeroIngresado;

}


//ABM -------------
int Nacionalidad_BuscarLibre(eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int i;
	int index;
	index = -1;
	for(i = 0; i < tNacionalidad; i++)
	{
		if(pListaNacionalidad[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}


int Nacionalidad_BuscarID(eNacionalidad pListaNacionalidad[], int tNacionalidad, int id)
{
	int i;
	int rtn;
	rtn = -1;

	for(i = 0; i < tNacionalidad; i++)
	{
		if(pListaNacionalidad[i].idNacionalidad == id && pListaNacionalidad[i].isEmpty == OCUPADO)
		{
			rtn = i;
			break;
		}
	}

	return rtn;
}


//int Nacionalidad_Modificar(eNacionalidad pListaNacionalidad[], int tNacionalidad)
//{
//	int index;
//	int rtn;
//	int idModificar;
//	char auxiliarDescripcion[SIZE_ARRAY];
//	rtn = 0;
//
//	Nacionalidad_MostrarTodos(pListaNacionalidad, tNacionalidad);
//
//	getInt(&idModificar, "* Ingrese el ID del Nacionalidad que desea eliminar\n");
//	//index = Producto_BuscarIdNacionalidad(pListaProducto, tProducto, idModificar); AGREGAR LA LISTA PRODUCTO
//
//	if(index != -1)
//	{
//		myGets(auxiliarDescripcion, SIZE_ARRAY, "Ingrese la nueva descripcion: ");
//
//		if(Confirmar_Respuesta("Seguro que desea modificarlo? 1. Si 0. No", "ERROR: Seguro que desea modificarlo?\nIngrese 1. Si 0. No") == 1)
//		{
//			strncpy(pListaNacionalidad[index].descripcionNacionalidad, auxiliarDescripcion, SIZE_ARRAY);
//			rtn = 1;
//		}
//
//	}
//
//	return rtn;
//}


int Nacionalidad_MostrarTodos(eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
    int i;
    int rtn;
    rtn = 0;

    printf("%4s %15s", "ID", "DESCRIPCION \n");

    for(i=0; i < tNacionalidad; i++)
    {
    	if(pListaNacionalidad[i].isEmpty != VACIO)
    	{
    		Nacionalidad_MostrarUno(pListaNacionalidad[i]);
     		rtn = 1;
    	}
    }
    return rtn;
}


void Nacionalidad_MostrarUno(eNacionalidad pListaNacionalidad)
{

    printf("\n%5d %10s\n", pListaNacionalidad.idNacionalidad,
    					pListaNacionalidad.descripcionNacionalidad);
}


int Nacionalidad_Cargar(eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
    int i;
    int rtn;
    int auxiliar;
    rtn = -1;

    i = Nacionalidad_BuscarLibre(pListaNacionalidad, tNacionalidad);
    if(i != -1)
    {
    	getInt(&auxiliar, "Ingrese el Id del Nacionalidad: ");

    	//while(Producto_BuscarIdNacionalidad(pListaProducto, tProducto, auxiliar) != -1) agregar las listas producto
    	//{
    	//	getInt(&auxiliar, "ERROR: El ID ya existe, Ingrese otro: ");
    	//}
		pListaNacionalidad[i] = Nacionalidad_PedirDatos();
		pListaNacionalidad[i].idNacionalidad = auxiliar;
		rtn = 1;
    }

    return rtn;
}


eNacionalidad Nacionalidad_PedirDatos()
{
	eNacionalidad NacionalidadIngresado;

	myGets(NacionalidadIngresado.descripcionNacionalidad, 100,"Ingrese la descripcion del Nacionalidad: ");

    NacionalidadIngresado.isEmpty = OCUPADO;

    return NacionalidadIngresado;
}


void Nacionalidad_Inicializar(eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int i;

	for(i=0; i<tNacionalidad; i++)
	{
		pListaNacionalidad[i].isEmpty = VACIO;
	}
}

