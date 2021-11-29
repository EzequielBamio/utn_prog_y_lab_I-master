#include "utn.Struct.h"
#include "utn.Struct.Tipo.h"



void Ordenar_Productos_Por_Descripcion(eProducto pListaProducto[], int tProducto)
{
    int i;
    int j;
    eProducto auxiliar;
    for(i=0; i < tProducto-1; i++)
    {
        for(j=i+1; j < tProducto; j++)
        {
            if((strncmp(pListaProducto[i].descripcion, pListaProducto[j].descripcion, 100)) > 0)
            {
            	auxiliar = pListaProducto[i];
            	pListaProducto[i] = pListaProducto[j];
            	pListaProducto[j] = auxiliar;
            }
        }
    }
}


void Ordenar_Productos_Por_Precio(eProducto pListaProducto[], int tProducto)
{
    int i;
    int j;
    eProducto auxiliar;
    for(i=0; i<tProducto-1; i++)
    {
        for(j = i+1; j < tProducto; j++)
        {
            if(pListaProducto[i].precio > pListaProducto[j].precio)
            {
               auxiliar = pListaProducto[i];
               pListaProducto[i] = pListaProducto[j];
               pListaProducto[j] = auxiliar;
            }
        }
    }
}

/******************************************************************/

int Productos_Buscar_ID(eProducto pListaProducto[], int tProducto, int valorBuscado)
{
	int i;
	int rtn;
	rtn = -1;

		for(i = 0; i < tProducto; i++)
		{
			if(valorBuscado == pListaProducto[i].idProducto)
			{
				rtn = i;
				break;
			}
		}

	return rtn;
}


int Productos_Buscar_Libre(eProducto pListaProducto[], int tProducto)
{
	int i;
	int index;
	index = -1;
	for(i=0; i < tProducto; i++)
	{
		if(pListaProducto[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

void Productos_MostrarUno(eProducto pListaProducto)
{
    printf("\nID Producto: %d Descripcion: %s Nacionalidad: %d Tipo: %d Precio: %.2f\n", pListaProducto.idProducto,
																						pListaProducto.descripcion,
																						pListaProducto.idNacionalidad,
																						pListaProducto.idTipo,
																						pListaProducto.precio);
}
int Productos_MostrarTodos(eProducto pListaProducto[], int tProducto)
{
    int i;
    int rtn;
    rtn = 0;

    for(i=0; i<tProducto; i++)
    {
    	if(pListaProducto[i].isEmpty != VACIO)
    	{
    		Productos_MostrarUno(pListaProducto[i]);
     		rtn = 1;
    	}
    }
    return rtn;
}


int Productos_Modificar(eProducto pListaProducto[], int tProducto)
{
	int rtn;
	int opcionModificar;
	int nuevoTipo;
	float nuevoPrecio;
	int index;

	rtn = 0;//Si cancelo
	//if(Productos_Mostrar_Todos(pListaProducto, tProducto) != 0)
	//{
		getInt(&index, "* Ingrese el producto que desea modificar: ");
		index = Productos_Buscar_ID(pListaProducto, tProducto, index);
		if(index != -1)
		{
			utn_getNumero(&opcionModificar, "Que desea modificar: \n1. Tipo\n2. Precio\n", 1, 2);

			switch(opcionModificar)
			{
			case 1:
				utn_getNumero(&nuevoTipo, "* Ingrese el tipo de producto: \n* 1000. IPHONE \n* 1001. MAC \n* 1002 IPAD\n* 1003. ACCESORIOS \n", 1000, 1003);
				if(Confirmar_Respuesta("Seguro que desea modificar este Producto? 1. Si 0. No", "ERROR: Seguro que desea modificar este producto?\nIngrese 1. Si 0. No") == 1)
				{
					pListaProducto[index].idTipo = nuevoTipo;
				}
				rtn = 1;//Devuelve 1 si se modifico
				break;
			case 2:
				getFloat(&nuevoPrecio, "* Ingrese el nuevo precio del producto: ");
				if(Confirmar_Respuesta("Seguro que desea modificar este Producto? 1. Si 0. No", "ERROR: Seguro que desea modificar este producto?\nIngrese 1. Si 0. No") == 1)
				{
					pListaProducto[index].precio = nuevoPrecio;
					rtn = 1;
				}

				break;
			}
		}
	//}

	return rtn;
}


int Productos_Eliminar(eProducto pListaProducto[], int tProducto)
{
	int rtn;
	int index;
	rtn = 0; //Si se cancelo la baja

	//if(Productos_Mostrar_Todos(pListaProducto, tProducto) != 0)
	//{
		getInt(&index, "* Ingrese el producto que desea eliminar: ");
		index = Productos_Buscar_ID(pListaProducto, tProducto, index);
		if(index != -1)
		{
			//Productos_Mostrar_Uno(pListaProducto[index]);
			if(Confirmar_Respuesta("Seguro que desea eliminar este producto? 1. Si 0. No: ", "ERROR: Seguro que desea eliminar este producto?\nIngrese 1. Si 0. No: ") == 1)
			{
				pListaProducto[index].isEmpty = VACIO;
				rtn = 1; //Si el confirmo la baja
			}
		//}
	}
	return rtn;
}


int Productos_Cargar(eProducto pListaProducto[], int tProducto)
{
    int i;
    int rtn;
    rtn = 0;//Si no hay espacio
    i = Productos_Buscar_Libre(pListaProducto, tProducto);
    if(i != -1)
      {
      	 pListaProducto[i] = Productos_Pedir_Datos();
      	 rtn = 1;//Se cargo correctamente
      }

    return rtn;
}


eProducto Productos_Pedir_Datos()
{
	eProducto productoIngresado;

	getInt(&productoIngresado.idProducto, "* Ingrese el Id del producto: ");

	myGets(productoIngresado.descripcion, T, "* Ingrese la descripcion: ");

    utn_getNumero(&productoIngresado.idNacionalidad, "* Ingrese la nacionaldad del producto:\n* 1. EEUU\n* 2. CHINA\n* 3. OTRO: \n", 1, 3);

    utn_getNumero(&productoIngresado.idTipo, "* Ingrese el tipo de producto: \n* 1000. IPHONE \n* 1001. MAC \n* 1002. IPAD\n* 1003. ACCESORIOS \n", 1000, 1003);

    getFloat(&productoIngresado.precio ,"* Ingrese el precio del producto: ");

    productoIngresado.isEmpty = OCUPADO;

    return productoIngresado;
}


void Productos_Inicializar(eProducto pListaProducto[], int tProducto)
{
	int i;

	for(i = 0; i < tProducto; i++)
	{
		pListaProducto[i].isEmpty = VACIO;
	}
}
