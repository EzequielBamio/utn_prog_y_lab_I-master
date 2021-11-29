#include "Struct.h"
#include "utn.Get.h"

int Producto_Producto_BuscarLibre(eProducto pListaProducto[], int tProducto)
{
	int i;
	int index;
	index = -1;
	for(i=0; i<tProducto; i++)
	{
		if(pListaProducto[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}


int Producto_MostrarID(eProducto pListaProducto[], int tProducto)
{
	int i;
	int rtn;

	printf("Ingrese el ID\n");
	for(i = 0; i < tProducto; i++)
	{
		if(pListaProducto[i].isEmpty != VACIO)
		{
			printf("ID: %d\n", pListaProducto[i].idProducto);
		}
	}
	scanf("%d", &rtn);

	return rtn;
}


int Tipo_CalcularPromedio(eProducto pListaProducto[], int tipo, int tProducto)
{
	int i;
	int acumuladorPrecios;
	int promedioPrecios;
	int contadorTipo;

	promedioPrecios = -1;
	contadorTipo = 0;
	acumuladorPrecios = 0;

	for(i = 0; i < tProducto; i++)
	{
		if(tipo == pListaProducto[i].tipo)
		{
			acumuladorPrecios += pListaProducto[i].precio;
			contadorTipo++;
		}
	}

	promedioPrecios = acumuladorPrecios / contadorTipo;

	return promedioPrecios;
}


int Producto_CalcularMasCaro(eProducto pListaProducto[], int tProducto)
{
    int i;
    int j;
    int rtn;
    eProducto auxiliar;
    rtn = 0;

    for(i=0; i<tProducto-1; i++)
    {
        for(j=i+1; j<tProducto; j++)
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
    Producto_MostrarUno(auxiliar);

    return rtn;
}


void Producto_OrdenarDescripcion(eProducto pListaProducto[], int tProducto)
{
    int i;
    int j;
    eProducto auxiliar;
    for(i=0; i < tProducto-1; i++)
    {
        for(j=i+1; j < tProducto; j++)
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


void Producto_OrdenarPrecio(eProducto pListaProducto[], int tProducto)
{
    int i;
    int j;
    eProducto auxiliar;
    for(i=0; i<tProducto-1; i++)
    {
        for(j=i+1; j<tProducto; j++)
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


int Producto_Modificar(eProducto pListaProducto[], int tProducto)
{
	int i;
	int rtn;
	int modificarAlumno;
	int opcionModificar;
	int nuevoTipo;
	float nuevoPrecio;
	rtn = 0;

	modificarAlumno = Producto_MostrarID(pListaProducto, tProducto);
	for(i = 0; i < tProducto; i++)
	{
		if(modificarAlumno == pListaProducto[i].idProducto)
		{

			printf("Que desea modificar: \n1. Tipo\n2. Precio\n");
			scanf("%d", &opcionModificar);

			switch(opcionModificar)
			{
			case 1:
				utn_getNumero(&nuevoTipo ,"Ingrese el tipo de producto 1. IPHONE 2. MAC 3. IPAD 4. ACCESORIOS:  ", 1, 4);
				if(Confirmar_Respuesta("Seguro que desea modificar este Alumno? 1. Si 0. No", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
				{
					pListaProducto[i].tipo = nuevoTipo;
					rtn = 1;
				}
				break;
			case 2:
				getFloat(&nuevoPrecio, "Ingrese el nuevo precio del producto: ");
				if(Confirmar_Respuesta("Seguro que desea modificar este Alumno? 1. Si 0. No", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
				{
					pListaProducto[i].precio = nuevoPrecio;
					rtn = 1;
				}
				break;
			}
		}
	}
	return rtn;
}


int Producto_Eliminar(eProducto pListaProducto[], int tProducto)
{
	int i;
	int rtn;
	int eliminarID;
	rtn = 0;

	eliminarID = Producto_MostrarID(pListaProducto, tProducto);
	for(i = 0; i < tProducto; i++)
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
			}

		}
	}
	return rtn;

}


int Producto_MostrarTodos(eProducto pListaProducto[], int tProducto)
{
    int i;
    int rtn;
    rtn = 0;

    for(i=0; i<tProducto; i++)
    {
    	if(pListaProducto[i].isEmpty != VACIO)
    	{
    		Producto_MostrarUno(pListaProducto[i]);
     		rtn = 1;
    	}
    }
    return rtn;
}


void Producto_MostrarUno(eProducto unProducto)
{
	char auxiliarTipo[20];
	char auxiliarNacionalidad[20];
	switch(unProducto.nacionalidad)
	{
	case EEUU:
		strcpy(auxiliarNacionalidad, "ESTADOS UNIDOS");
		break;
	case CHINA:
		strcpy(auxiliarNacionalidad, "CHINA");
		break;
	case OTRO:
		strcpy(auxiliarNacionalidad, "OTRO");
		break;
	}
	switch(unProducto.tipo)
	{
	case IPHONE:
		strcpy(auxiliarTipo, "IPHONE");
		break;
	case MAC:
		strcpy(auxiliarTipo, "MAC");
		break;
	case IPAD:
		strcpy(auxiliarTipo, "IPAD");
		break;
	case ACCESORIOS:
		strcpy(auxiliarTipo, "ACCESORIOS");
		break;
	}
    printf("\nID Producto: %d Descripcion: %s Nacionalidad: %s Tipo: %s Precio: %.2f\n", unProducto.idProducto,
    							unProducto.descripcion,
							   auxiliarNacionalidad,
							   auxiliarTipo,
							   unProducto.precio);
}


eProducto Producto_Producto_PedirDatos()
{
	eProducto productoIngresado;

	getInt(&productoIngresado.idProducto ,"Ingrese el Id del producto: ");

	myGets(productoIngresado.descripcion, 100,"Ingrese la descripcion del producto: ");

	utn_getNumero(&productoIngresado.nacionalidad ,"Ingrese la nacionaldad del producto 1.EEUU 2. CHINA 3. OTRO: ", 1, 3);

    utn_getNumero(&productoIngresado.tipo,"Ingrese el tipo de producto 1. IPHONE 2. MAC 3. IPAD 4. ACCESORIOS:  ", 1, 4);

    getFloat(&productoIngresado.precio, "Ingrese el precio del producto: ");

    productoIngresado.isEmpty = OCUPADO;

    return productoIngresado;
}



int Producto_Cargar(eProducto pListaProducto[], int tProducto)
{
    int i;
    int rtn;
    rtn = -1;
    i = Producto_BuscarLibre(pListaProducto, tProducto);
    if(i != -1)
    {
    	 pListaProducto[i] = Producto_PedirDatos();
    	 for(i = 0; i < tProducto; i++)
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



void Producto_Inicializar(eProducto pListaProducto[], int tProducto)
{
	int i;

	for(i=0; i<tProducto; i++)
	{
		pListaProducto[i].isEmpty = VACIO;
	}
}
