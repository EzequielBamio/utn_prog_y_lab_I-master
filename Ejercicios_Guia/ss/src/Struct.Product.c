#include "Struct.Product.h"
#include "utn.Get.h"

int Producto_BuscarLibre(eProducto pListaProducto[], int tProducto)
{
	int i;
	int index;
	index = -1;
	for(i = 0; i < tProducto; i++)
	{
		if(pListaProducto[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}
int Producto_BuscarIdNacionalidad(eProducto pListaProducto[], int tProducto, int id)
{
	int i;
	int rtn;
	rtn = -1;

	for(i = 0; i < tProducto; i++)
	{
		if(pListaProducto[i].nacionalidad == id && pListaProducto[i].isEmpty == OCUPADO)
		{
			rtn = i;
			break;
		}
	}

	return rtn;
}
int Producto_BuscarIdTipo(eProducto pListaProducto[], int tProducto, int id)
{
	int i;
	int rtn;
	rtn = -1;

	for(i = 0; i < tProducto; i++)
	{
		if(pListaProducto[i].tipo == id && pListaProducto[i].isEmpty == OCUPADO)
		{
			rtn = i;
			break;
		}
	}

	return rtn;
}


int Producto_BuscarID(eProducto pListaProducto[], int tProducto, int id)
{
	int i;
	int rtn;
	rtn = -1;

	for(i = 0; i < tProducto; i++)
	{
		if(pListaProducto[i].idProducto == id && pListaProducto[i].isEmpty == OCUPADO)
		{
			rtn = i;
			break;
		}
	}

	return rtn;
}


//int Producto_Modificar(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo)
//{
//	int index;
//	int rtn;
//	int idModificar;
//	int opcionModificar;
//	int nuevoTipo;
//	float nuevoPrecio;
//	rtn = 0;
//
//	Producto_MostrarTodos(pListaProducto, tProducto);
//
//	getInt(&idModificar, "* Ingrese el ID del producto que desea eliminar: ");
//	index = Producto_BuscarID(pListaProducto, tProducto, idModificar);
//
//	if(index != -1)
//	{
//			utn_getNumero(&opcionModificar, "* Que desea modificar: \n1. Tipo\n2. Precio\n", 1, 2);
//			switch(opcionModificar)
//			{
//			case 1:
//				Tipo_MostrarTodos(pListaTipo, tTipo);
//
//			    getInt(&nuevoTipo,"* Ingrese el tipo de producto: ");
//				if(Confirmar_Respuesta("* Seguro que desea modificar este Alumno? 1. Si 0. No", "* ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
//				{
//					pListaProducto[index].tipo = nuevoTipo;
//					rtn = 1;
//				}
//				break;
//			case 2:
//				getFloat(&nuevoPrecio, "* Ingrese el nuevo precio del producto: ");
//				if(Confirmar_Respuesta("* Seguro que desea modificar este Alumno? 1. Si 0. No", "* ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
//				{
//					pListaProducto[index].precio = nuevoPrecio;
//					rtn = 1;
//				}
//				break;
//			}
//	}
//	return rtn;
//}

void Producto_GetId(eProducto pListaProducto[], int tProducto, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < tProducto; i++)
	{
		if(pListaProducto[i].idProducto > mayor || i == 0)
		{
			mayor = pListaProducto[i].idProducto;
		}
		if(pListaProducto[i].idProducto < menor || i == 0)
		{
			menor = pListaProducto[i].idProducto;
		}
	}

	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);

	*pResultado = numeroIngresado;

}

int Producto_Eliminar(eProducto pListaProducto[], int tProducto)
{
	int index;
	int rtn;
	int idEliminar;
	rtn = 0;

	Producto_MostrarTodos(pListaProducto, tProducto);
	if(Confirmar_Respuesta("* Seguro que desea eliminar? 1. Si 0. No: ", "* ERROR: Seguro que desea eliminar?\nIngrese 1. Si 0. No: ") == 1)
	{
		Producto_GetId(pListaProducto, tProducto, "* Ingrese la ID del producto que desea eliminar: \n", &idEliminar);
		index = Producto_BuscarID(pListaProducto, tProducto, idEliminar);
	}
	if(index != -1)
	{
		pListaProducto[index].isEmpty = VACIO;
		rtn = 1;
	}

	return rtn;

}


int Producto_MostrarTodos(eProducto pListaProducto[], int tProducto)
{
    int i;
    int rtn;
    rtn = 0;

    printf("%5s %15s %15s %15s %11s", "ID", "DESCRIPCION", "NACIONALIDAD", "TIPO", "PRECIO\n");

    for(i=0; i < tProducto; i++)
    {
    	if(pListaProducto[i].isEmpty != VACIO)
    	{
    		Producto_MostrarUno(pListaProducto[i]);
     		rtn = 1;
    	}
    }
    return rtn;
}


void Producto_MostrarUno(eProducto pListaProducto)
{

    printf("\n%5d %10s %15d %21d %10.2f\n", pListaProducto.idProducto,
											pListaProducto.descripcion,
											pListaProducto.nacionalidad,
											pListaProducto.tipo,
											pListaProducto.precio);
}


//int Producto_Cargar(eProducto pListaProducto[], int tProducto)
//{
//    int i;
//    int rtn;
//    int auxiliar;
//    rtn = -1;
//
//    i = Producto_BuscarLibre(pListaProducto, tProducto);
//    if(i != -1)
//    {
//    	getInt(&auxiliar, "Ingrese el Id del producto: ");
//
//    	while(Producto_BuscarID(pListaProducto, tProducto, auxiliar) != -1)
//    	{
//    		getInt(&auxiliar, "ERROR: El ID ya existe, Ingrese otro: ");
//    	}
//		pListaProducto[i] = Producto_PedirDatos();
//		pListaProducto[i].idProducto = auxiliar;
//		rtn = 1;
//    }
//
//    return rtn;
//}


//eProducto Producto_PedirDatos()
//{
//	eProducto productoIngresado;
//
//	myGets(productoIngresado.descripcion, 100,"Ingrese la descripcion del producto: ");
//
//	utn_getNumero(&productoIngresado.nacionalidad ,"Ingrese la nacionaldad del producto: ", 1, 3);
//
//	utn_getNumero(&productoIngresado.tipo,"Ingrese el tipo de producto: ", 1000, 1003);
//
//    getFloat(&productoIngresado.precio, "Ingrese el precio del producto: ");
//
//    productoIngresado.isEmpty = OCUPADO;
//
//    return productoIngresado;
//}


void Producto_Inicializar(eProducto pListaProducto[], int tProducto)
{
	int i;

	for(i=0; i<tProducto; i++)
	{
		pListaProducto[i].isEmpty = VACIO;
	}
}


