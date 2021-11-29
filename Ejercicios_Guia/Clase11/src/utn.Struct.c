#include "utn.Struct.h"
int Buscar_Productos(eProducto pListaProducto[], int tProducto, int pId)
{
	int i;
	int rtn;
	rtn = -1;

	for (i = 0; i < tProducto; i++)
	{
		if(pId == pListaProducto[i].idTipo)
		{
			rtn = i;
			break;
		}
	}
	return rtn;
}


int Buscar_Libre(eProducto pListaProducto[], int tam)
{
	int i;
	int index;
	index = -1;
	for(i=0; i < tam; i++)
	{
		if(pListaProducto[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}
int Calcular_Mas_Caro(eProducto pListaProducto[], int tam)
{
    int i;
    int j;
    int rtn;
    eProducto auxiliar;
    rtn = 1;

    for(i=0; i < tam-1; i++)
    {
    	if(pListaProducto[i].isEmpty == OCUPADO)
    	{
			for(j=i+1; j<tam; j++)
			{
				if(pListaProducto[i].precio > pListaProducto[j].precio || i == 0)
				{
				   auxiliar = pListaProducto[i];
				}else
				{
					auxiliar = pListaProducto[j];
				}
			}
    	}else
    	{
    		rtn = 0;//No hay productos para mostrar
    	}
    }
    if(rtn != 0)
    {
        Mostrar_Un_Producto(auxiliar);
    }

    return rtn;
}
void Ordenar_Productos_Por_Descripcion(eProducto pListaProducto[], int tam)
{
    int i;
    int j;
    eProducto auxiliar;
    for(i=0; i < tam-1; i++)
    {
        for(j=i+1; j < tam; j++)
        {
            if((strcmp(pListaProducto[i].descripcion, pListaProducto[j].descripcion)) > 0)
            {
               auxiliar = pListaProducto[i];
               pListaProducto[i] = pListaProducto[j];
               pListaProducto[j] = auxiliar;
            }
        }
    }
}
void Ordenar_Productos_Por_Precio(eProducto pListaProducto[], int tam)
{
    int i;
    int j;
    eProducto auxiliar;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
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
void Mostrar_Un_Producto(eProducto pListaProducto)
{
    printf("\nID Producto: %d Descripcion: %s Nacionalidad: %d Tipo: %d Precio: %.2f\n", pListaProducto.idProducto,
																						pListaProducto.descripcion,
																						pListaProducto.idNacionalidad,
																						pListaProducto.idTipo,
																						pListaProducto.precio);
}
int Mostrar_Todos_Los_Productos(eProducto pListaProducto[], int tProducto)
{
    int rtn;
    int i;
    rtn = 0;

    for(i=0; i < tProducto; i++)
    {
    	if(pListaProducto[i].isEmpty != VACIO)
    	{
    		Mostrar_Un_Producto(pListaProducto[i]);
     		rtn = 1;
    	}
    }
    return rtn;
}
int buscar_Id(eProducto pListaProducto[], int tProducto, int valorBuscado)
{
	int i;
	int rtn;
	rtn = -1;

		for(i = 0; i < tProducto; i++)
		{
			if(valorBuscado == pListaProducto[i].idProducto)
			{
				rtn = i;
			}
		}

	return rtn;
}
int Modificar_Un_Producto(eProducto pListaProducto[], int tProducto)
{
	int index;
	int opcionModificar;
	int rtn;
	int nuevoTipo;
	float nuevoPrecio;

	rtn = 0;
	if(Mostrar_Todos_Los_Productos(pListaProducto, tProducto) != 0)
	{
		getInt(&index, "Ingrese el producto que desea modificar: ");
		if(buscar_Id(pListaProducto, tProducto, index))
		{
			getInt(&opcionModificar, "Que desea modificar: \n1. Tipo\n2. Precio\n");

			switch(opcionModificar)
			{
			case 1:
				if(Confirmar_Respuesta("Seguro que desea modificar este Producto? 1. Si 0. No", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
				{
					utn_getNumero(&pListaProducto[index].idTipo, "* Ingrese el tipo de producto: \n* 1000. IPHONE \n* 1001. MAC \n* 1002 IPAD\n* 1003. ACCESORIOS \n",
															  "* ERROR: Ingrese el tipo de producto:\n* 1000. IPHONE \n* 1001. MAC \n* 1002 IPAD\n* 1003. ACCESORIOS \n", 1000, 1003);
					rtn = 1;
					break;
				}
				break;
			case 2:
				if(Confirmar_Respuesta("Seguro que desea modificar este Producto? 1. Si 0. No: ", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No: ") == 1)
				{
					getFloat(&pListaProducto[index].precio, "* Ingrese el nuevo precio del producto: ");
					rtn = 1;
					break;
				}
				break;
			}
		}
	}

	return rtn;
}
int Eliminar_Un_Producto(eProducto pListaProducto[], int tProducto)
{
	int rtn;
	int index;
	rtn = 0; //Si se cancelo la baja

	if(Mostrar_Todos_Los_Productos(pListaProducto, tProducto) != 0)
	{
		getInt(&index, "Ingrese el producto que desea eliminar: ");

		if(buscar_Id(pListaProducto, tProducto, index))
		{
			Mostrar_Un_Producto(pListaProducto[index]);
			if(Confirmar_Respuesta("Seguro que desea eliminar este producto? 1. Si 0. No: ", "ERROR: Seguro que desea eliminar este Alumno?\nIngrese 1. Si 0. No: ") == 1)
			{
				pListaProducto[index].isEmpty = VACIO;
				rtn = 1; //Si el confirmo la baja
			}
		}
	}
	return rtn;

}
int Cargar_Productos(eProducto pListaProducto[], int tProducto)
{
    int i;
    int rtn;
    rtn = -1;
    i = Buscar_Libre(pListaProducto, tProducto);
    if(i != -1)
      {
      	 pListaProducto[i] = Pedir_Datos();
      	 if(!Buscar_Libre(pListaProducto, tProducto))
      	 {
  			 pListaProducto[i].isEmpty = i;
      	 }

      	 rtn = 1;
      }

    return rtn;
}
eProducto Pedir_Datos()
{
	eProducto productoIngresado;

	getInt(&productoIngresado.idProducto, "* Ingrese el Id del producto: ");
	myGets(productoIngresado.descripcion, T, "* Ingrese la descripcion: ");

    utn_getNumero(&productoIngresado.idNacionalidad, "* Ingrese la nacionaldad del producto:\n* 1. EEUU\n* 2. CHINA\n* 3. OTRO: \n",
    											  "* ERROR: Ingrese la nacionaldad del producto:\n* 1.EEUU\n* 2. CHINA\n* 3. OTRO: \n", 1, 3);

    utn_getNumero(&productoIngresado.idTipo, "* Ingrese el tipo de producto: \n* 1000. IPHONE \n* 1001. MAC \n* 1002 IPAD\n* 1003. ACCESORIOS \n",
    									   "* ERROR: Ingrese el tipo de producto:\n* 1000. IPHONE \n* 1001. MAC \n* 1002 IPAD\n* 1003. ACCESORIOS \n", 1000, 1003);

    getFloat(&productoIngresado.precio ,"* Ingrese el precio del producto: ");

    productoIngresado.isEmpty = OCUPADO;

    return productoIngresado;
}
void Inicializar_Productos(eProducto pListaProducto[], int tProducto)
{
	int i;

	for(i = 0; i < tProducto; i++)
	{
		pListaProducto[i].isEmpty = VACIO;
	}
}
int Confirmar_Respuesta(char mensaje[], char mensajeError[])
{
	int respuesta;

	getInt(&respuesta, mensaje);

	while(respuesta != 1 && respuesta != 0)
	{
		getInt(&respuesta, mensajeError);

	}

	return respuesta;
}
