#include "utn.Struct.Tipo.h"

int Tipo_Mostrar_Promedio(eTipo pListaTipo[], int tTipo, eProducto pListaProducto[], int tProducto)
{
	int i;
	float promedio;
	int rtn;
	rtn = 0;

	for(i = 0; i < tTipo; i++)
	{
		promedio = Tipo_Calcular_Promedio(pListaTipo, tTipo, pListaProducto, tProducto, pListaTipo[i].idTipo);
		if(promedio != -1)
		{
			printf("* El promedio de %s es: %.2f\n", pListaTipo[i].descripcionTipo, promedio);
			rtn = 1;
		}
	}

	return rtn;
}


float Tipo_Calcular_Promedio(eTipo pListaTipo[], int tTipo, eProducto pListaProducto[], int tProducto, int id)
{
	int i;
	float acumuladorPrecios;
	int contadorTipo;
	float promedio;
	promedio = -1;

	acumuladorPrecios = 0;
	contadorTipo = 0;

	for(i = 0; i < tTipo; i++)
	{
		if(pListaProducto[i].idTipo == id)
		{
			acumuladorPrecios += pListaProducto[i].precio;
			contadorTipo++;
		}

	}
	if(contadorTipo != 0)
	{
		promedio = acumuladorPrecios / contadorTipo;
	}
	return promedio;
}


int Tipo_Buscar_ID(eTipo pListaTipo[], int tTipo, int valorBuscado)
{
	int i;
	int rtn;
	rtn = -1;

		for(i = 0; i < tTipo; i++)
		{
			if(valorBuscado == pListaTipo[i].idTipo)
			{
				rtn = i;
				break;
			}
		}

	return rtn;
}


int Tipo_Buscar_Libre(eTipo pListaTipo[], int tTipo)
{
	int i;
	int index;
	index = -1;
	for(i=0; i < tTipo; i++)
	{
		if(pListaTipo[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}


void Tipo_Mostrar_Uno(eTipo pListaTipo)
{
	printf("\nID Tipo | Descripcion ");
    printf("\n %5d  %10s\n", pListaTipo.idTipo,
    						pListaTipo.descripcionTipo);

}


int Tipo_Mostrar_Todos(eTipo pListaTipo[], int tTipo)
{
    int rtn;
    int i;
    rtn = 0;

    for(i=0; i < tTipo; i++)
    {
    	if(pListaTipo[i].isEmpty != VACIO)
    	{
    		Tipo_Mostrar_Uno(pListaTipo[i]);
     		rtn = 1;
    	}
    }
    return rtn;
}


int Tipo_Modificar(eTipo pListaTipo[], int tTipo)
{
	int rtn;
	char nuevaDescripcion[100];
	int index;

	rtn = 0;
	if(Tipo_Mostrar_Todos(pListaTipo, tTipo) != 0)
	{
		printf("Estoy aca");
		getInt(&index, "* Ingrese el tipo que desea modificar: ");
		index = Tipo_Buscar_ID(pListaTipo, tTipo, index);
		if(index != -1)
		{
				myGets(nuevaDescripcion, 100, "Ingrese el nuevo precio del producto: ");
				if(Confirmar_Respuesta("Seguro que desea modificar este tipo? 1. Si 0. No", "ERROR: Seguro que desea modificar este tipo?\nIngrese 1. Si 0. No") == 1)
				{
					strncpy(pListaTipo[index].descripcionTipo, nuevaDescripcion, 100);
					rtn = 1;
				}
		}
	}

	return rtn;
}


int Tipo_Eliminar(eTipo pListaTipo[], int tTipo)
{
	int rtn;
	int index;
	rtn = 0; //Si se cancelo la baja

	if(Tipo_Mostrar_Todos(pListaTipo, tTipo) != 0)
	{
		getInt(&index, "* Ingrese el tipo que desea eliminar: ");
		index = Tipo_Buscar_ID(pListaTipo, tTipo, index);
		if(index != -1)
		{
			Tipo_Mostrar_Uno(pListaTipo[index]);
			if(Confirmar_Respuesta("Seguro que desea eliminar este tipo? 1. Si 0. No: ", "ERROR: Seguro que desea eliminar este tipo?\nIngrese 1. Si 0. No: ") == 1)
			{
				pListaTipo[index].isEmpty = VACIO;
				rtn = 1; //Si el confirmo la baja
			}
		}
	}
	return rtn;
}


int Tipo_Cargar(eTipo pListaTipo[], int tTipo)
{
    int i;
    int rtn;
    rtn = 0;//Si no hay espacio
    i = Tipo_Buscar_Libre(pListaTipo, tTipo);
    if(i != -1)
	{
		pListaTipo[i] = Tipo_Pedir_Datos();
		if(!Tipo_Buscar_Libre(pListaTipo, tTipo))
		{
			pListaTipo[i].isEmpty = i;
		}

		rtn = 1;//Se cargo correctamente
	  }

    return rtn;
}


eTipo Tipo_Pedir_Datos()
{
	eTipo tipoIngresado;

	getInt(&tipoIngresado.idTipo, "* Ingrese el Id del Tipo: ");
	myGets(tipoIngresado.descripcionTipo, T, "* Ingrese la descripcion: ");

	tipoIngresado.isEmpty = OCUPADO;

    return tipoIngresado;
}


void Tipo_Inicializar(eTipo pListaTipo[], int tTipo)
{
	int i;

	for(i = 0; i < tTipo; i++)
	{
		pListaTipo[i].isEmpty = VACIO;
	}
}
