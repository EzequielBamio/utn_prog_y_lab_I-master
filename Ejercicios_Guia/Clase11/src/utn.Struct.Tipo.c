#include "utn.Struct.Tipo.h"
#include "utn.Struct.Nacionalidad.h"

int Listado_Tipo_Con_Mas_Productos(eProducto pListaProducto[], int tProducto, eTipoProducto pTipo[], int tTipo, char* tipoMayor)
{
	int i;
	int contadorIphone;
	int contadorIpad;
	int contadorMac;
	int contadorAccesorios;
	int rtn;
	contadorIphone = 0;
	contadorIpad = 0;
	contadorMac = 0;
	contadorAccesorios = 0;

	for (i = 0; i < tProducto; ++i)
	{
		switch(pListaProducto[i].idTipo)
		{
		case 1000:
			contadorIphone++;
			rtn = 1;
			break;
		case 1001:
			contadorIpad++;
			rtn = 1;
			break;
		case 1002:
			contadorMac++;
			rtn = 1;
			break;
		case 1003:
			contadorAccesorios++;
			rtn = 1;
			break;
		}
	}
	if(contadorIphone > contadorIpad && contadorIphone > contadorMac && contadorIphone > contadorAccesorios)
	{
		strcpy(tipoMayor, pTipo[0].descripcionTipo);
	}else
	{
		if(contadorIpad > contadorMac && contadorIpad > contadorAccesorios)
		{
			strcpy(tipoMayor, pTipo[1].descripcionTipo);
		}else
		{
			if(contadorMac > contadorAccesorios)
			{
				strcpy(tipoMayor, pTipo[2].descripcionTipo);
			}else
			{
				strcpy(tipoMayor, pTipo[3].descripcionTipo);
			}
		}
	}
	return rtn;
}
int Buscar_Tipo(eTipoProducto pTipo[], int tTipo, int pId)
{
	int i;
	int rtn;
	rtn = -1;

	for (i = 0; i < tTipo; i++)
	{
		if(pId == pTipo[i].idTipo)
		{
			rtn = i;
			break;
		}
	}
	return rtn;
}
int Listado_Tipo_Producto(eProducto pListaProducto[], int tProducto, eNacionalidad pNacionalidad[], int tNacionalidad, eTipoProducto pTipo[], int tTipo)
{
	int i;
	int indexProducto;
	int indexNacionalidad;
	int rtn;
	rtn = 0;

		for(i = 0; i < tTipo; i++)
		{
			indexProducto = Buscar_Productos(pListaProducto, tProducto, pTipo[i].idTipo);
				if(pListaProducto[indexProducto].idTipo == pTipo[i].idTipo)
				{
					indexNacionalidad = Buscar_Nacionalidad(pNacionalidad, tNacionalidad, indexProducto);
					if(indexProducto != -1)
					{
						rtn = 1;
						printf("\nID Tipo: %d Descripcion: %s ID Producto: %d Descripcion: %s Nacionalidad: %s Precio: %.2f\n", pTipo[i].idTipo,
																												pTipo[i].descripcionTipo,
																												pListaProducto[indexProducto].idProducto,
																												pListaProducto[indexProducto].descripcion,
																												pNacionalidad[indexNacionalidad].descripcionNacionalidad,
																												pListaProducto[indexProducto].precio);
					}
			}
		}
	return rtn;
}
int Listado_Productos_Con_Descripcion(eProducto pListaProducto[], eNacionalidad pNacionalidad[], int tNacionalidad, int tProducto, eTipoProducto pTipo[], int tTipo)
{
	int i;
	int j;
	int p;
	int rtn;
	rtn = 0;
	for(i = 0; i < tProducto; i++)
	{
		if(pListaProducto[i].isEmpty == OCUPADO)
		{
			for(j = 0; j < tTipo; j++)
			{
				for(p = 0; p < tNacionalidad; p++)
				{
					if(pListaProducto[i].idTipo == pTipo[j].idTipo)
					{
						if(pListaProducto[i].idNacionalidad == pNacionalidad[p].idNacionalidad)
						{
							rtn = 1;
							printf("\nID Producto: %d Descripcion: %s Nacionalidad: %s Tipo: %s Precio: %.2f\n", pListaProducto[i].idProducto,
																												pListaProducto[i].descripcion,
																												pNacionalidad[p].descripcionNacionalidad,
																												pTipo[j].descripcionTipo,
																												pListaProducto[i].precio);
						}
					}
				}
			}
		}
	}

	return rtn;

}
int Mostrar_Promedio(eProducto pListaProducto[], int tProducto, eTipoProducto pTipo[], int tTipo)
{
	int j;
	float promedio;
	for (j = 0; j < tTipo ; j++)
	{
		promedio = Promedio_Tipo_Productos(pListaProducto, pTipo[j].idTipo, tProducto);
		if(promedio != -1)
		{
			printf("%s: %.2f\n", pTipo[j].descripcionTipo, promedio);
		}
	}
	return promedio;
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
