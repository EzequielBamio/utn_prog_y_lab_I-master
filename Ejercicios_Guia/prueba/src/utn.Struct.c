#include "utn.Struct.h"
void Listado_Tipo_Producto(eProducto pListaProducto[], int tProducto, eTipoProducto pTipo[], int tTipo)
{
	int i;
		int j;

		for(i = 0; i < tTipo; i++)
		{

			for(j = 0; j < tProducto; j++)
			{
				if(pListaProducto[j].idTipo == pTipo[i].idTipo)
				{
					printf("\nID Tipo: %d Descripcion: %s ID Producto: %d Descripcion: %s Precio: %.2f\n", pTipo[i].idTipo,
																										pTipo[i].descripcionTipo,
																										pListaProducto[j].idProducto,
																										pListaProducto[j].descripcion,
																										pListaProducto[j].precio);
				}
			}
		}
}
void Listado_Productos_Con_Descripcion(eProducto pListaProducto[], int tProducto, eTipoProducto pTipo[], int tTipo)
{
	int i;
	int j;

	for(i = 0; i < tProducto; i++)
	{
		for(j = 0; j < tTipo; j++)
		{
			if(pListaProducto[i].idTipo == pTipo[j].idTipo)
			{
				printf("\nID Producto: %d Descripcion: %s Nacionalidad: %d Tipo: %s Precio: %.2f\n", pListaProducto[i].idProducto,
																									pListaProducto[i].descripcion,
																									pListaProducto[i].nacionalidad,
																									pTipo[j].descripcionTipo,
																									pListaProducto[i].precio);
			}
		}
	}

}
void Mostrar_Promedio(eProducto pListaProducto[], int tProducto, eTipoProducto pTipo[], int tTipo)
{
	int i;
	int j;
	float promedio;
	for (i = 0; i < tProducto; i++)
	{
		for (j = 0; j < tTipo ; j++)
		{
		    promedio = Promedio_Tipo_Productos(pListaProducto, pTipo[j].idTipo, tProducto);
            if(promedio != -1)
            {
               	printf("%s: %.2f\n", pTipo[j].descripcionTipo, promedio);
            }
		}
		break;
	}
}
int Promedio_Tipo_Productos(eProducto pListaProducto[], int tipo, int tam)
{
	int i;
	int acumuladorPrecios;
	int promedioPrecios;
	int contadorTipo;

	promedioPrecios = -1;
	contadorTipo = 0;
	acumuladorPrecios = 0;

	for(i = 0; i < tam; i++)
	{
		if(pListaProducto[i].idTipo == tipo)
		{
			acumuladorPrecios += pListaProducto[i].precio;
			contadorTipo++;
		}
	}
	if(contadorTipo != 0)
	{
		promedioPrecios = acumuladorPrecios / contadorTipo;
	}

	return promedioPrecios;
}
int Calcular_Mas_Caro(eProducto pListaProducto[], int tam)
{
    int i;
    int j;
    int rtn;
    eProducto auxiliar;
    rtn = 0;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(pListaProducto[i].precio > pListaProducto[j].precio || i == 0)
            {
               auxiliar = pListaProducto[i];
               rtn = 1;
            }else
            {
            	auxiliar = pListaProducto[j];
            	rtn = 1;
            }
        }
    }
    Mostrar_Un_Producto(auxiliar);

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
																						pListaProducto.nacionalidad,
																						pListaProducto.idTipo,
																						pListaProducto.precio);
}
int Mostrar_Todos_Los_Productos(eProducto pListaProducto[], int tam)
{
    int i;
    int rtn;
    rtn = 0;

    for(i=0; i<tam; i++)
    {
    	if(pListaProducto[i].isEmpty != VACIO)
    	{
    		Mostrar_Un_Producto(pListaProducto[i]);
     		rtn = 1;
    	}
    }
    return rtn;
}

int MostrarID(eProducto pListaProducto[], int tam)
{
	int i;
	int rtn;

	printf("Ingrese el ID\n");
	for(i = 0; i < tam; i++)
	{
		if(pListaProducto[i].isEmpty != VACIO)
		{
			printf("ID: %d\n", pListaProducto[i].idProducto);
		}
	}
	scanf("%d", &rtn);

	return rtn;
}
int Modificar_Un_Producto(eProducto pListaProducto[], int tam)
{
	int i;
	int rtn;
	int modificarProducto;
	int opcionModificar;
	int nuevoTipo;
	float nuevoPrecio;

	modificarProducto = MostrarID(pListaProducto, tam);
	for(i = 0; i < tam; i++)
	{
		if(modificarProducto == pListaProducto[i].idProducto)
		{
			getInt(&opcionModificar, "Que desea modificar: \n1. Tipo\n2. Precio\n");

			switch(opcionModificar)
			{
			case 1:
			    utn_getNumero(&nuevoTipo, "* Ingrese el tipo de producto: \n* 1000. IPHONE \n* 1001. MAC \n* 1002 IPAD\n* 1003. ACCESORIOS \n",
			    						  "* ERROR: Ingrese el tipo de producto:\n* 1000. IPHONE \n* 1001. MAC \n* 1002 IPAD\n* 1003. ACCESORIOS \n", 1000, 1003);
				if(Confirmar_Respuesta("Seguro que desea modificar este Producto? 1. Si 0. No", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
				{
					pListaProducto[i].idTipo = nuevoTipo;
					rtn = 1;
					break;
				}else
				{
					rtn = 0;
					break;
				}
				break;
			case 2:
				getFloat(&nuevoPrecio, "Ingrese el nuevo precio del producto: ");
				if(Confirmar_Respuesta("Seguro que desea modificar este Producto? 1. Si 0. No", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
				{
					pListaProducto[i].precio = nuevoPrecio;
					rtn = 1;
					break;
				}else
				{
					rtn = 0;
					break;
				}
				break;
			}
		}else
		{
			rtn = -1;
		}
	}
	return rtn;
}
int Eliminar_Un_Producto(eProducto pListaProducto[], int tam)
{
	int i;
	int rtn;
	int eliminarID;
	rtn = 0;

	eliminarID = MostrarID(pListaProducto, tam);
	for(i = 0; i < tam; i++)
	{
		if(eliminarID == pListaProducto[i].idProducto)
		{
			if(Confirmar_Respuesta("Seguro que desea eliminar este Alumno? 1. Si 0. No: ", "ERROR: Seguro que desea eliminar este Alumno?\nIngrese 1. Si 0. No: ") == 1)
			{
				pListaProducto[i].isEmpty = VACIO;
				rtn = 1;
				break;
			}else
			{
				rtn = 0;
				break;
			}

		}else
		{
			rtn = -1;
		}
	}
	return rtn;

}
int Cargar_Productos(eProducto pListaProducto[], int tam)
{
    int i;
    int rtn;
    rtn = -1;
    i = Buscar_Libre(pListaProducto, tam);
    if(i != -1)
    {
    	 pListaProducto[i] = Pedir_Datos();
    	 for(i = 0; i < tam; i++)
    	 {
    		 if(pListaProducto[i].isEmpty != VACIO)
    		 {
    			 pListaProducto[i].isEmpty = i;
    		 }
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

    utn_getNumero(&productoIngresado.nacionalidad, "* Ingrese la nacionaldad del producto:\n* 1. EEUU\n* 2. CHINA\n* 3. OTRO: \n",
    											  "* ERROR: Ingrese la nacionaldad del producto:\n* 1.EEUU\n* 2. CHINA\n* 3. OTRO: \n", 1, 3);

    utn_getNumero(&productoIngresado.idTipo, "* Ingrese el tipo de producto: \n* 1000. IPHONE \n* 1001. MAC \n* 1002 IPAD\n* 1003. ACCESORIOS \n",
    									   "* ERROR: Ingrese el tipo de producto:\n* 1000. IPHONE \n* 1001. MAC \n* 1002 IPAD\n* 1003. ACCESORIOS \n", 1000, 1003);

    getFloat(&productoIngresado.precio ,"* Ingrese el precio del producto: ");

    productoIngresado.isEmpty = OCUPADO;

    return productoIngresado;
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
void Inicializar_Productos(eProducto pListaProducto[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		pListaProducto[i].isEmpty = VACIO;
	}
}
int Confirmar_Respuesta(char mensaje[], char mensajeError[])
{
	int respuesta;

	printf("%s", mensaje);
	scanf("%d", &respuesta);

	while(respuesta != 1 && respuesta != 0)
	{
		printf("%s", mensajeError);
		scanf("%d", &respuesta);
	}

	return respuesta;
}
