#include "Struct.h"
#include "utn.Get.h"
#include "Struct.Product.h"
#include "Struct.Tipo.h"
#include "Struct.Nacionalidad.h"

//NACIONALIDAD -----------------------------------------------------------

//17
int Nacionalidad_Eliminar(eProducto pListaProducto[], int tProducto, eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int i;
	int index;
	int rtn;
	int idEliminar;
	rtn = 0;

	Nacionalidad_MostrarTodos(pListaNacionalidad, tNacionalidad);
	getInt(&idEliminar, "* Ingrese la ID del Nacionalidad que desea eliminar: \n");
	index = Nacionalidad_BuscarID(pListaNacionalidad, tNacionalidad, idEliminar);

	if(index != -1)
	{
		if(Confirmar_Respuesta("Seguro que desea eliminar este Nacionalidad? 1. Si 0. No: ", "ERROR: Seguro que desea eliminar este Nacionalidad?\nIngrese 1. Si 0. No: ") == 1)
		{
			pListaNacionalidad[index].isEmpty = VACIO;
			for(i = 0; i < tProducto; i++)
			{
				if(idEliminar == pListaProducto[i].nacionalidad)
				{
					pListaProducto[i].isEmpty = VACIO;
				}
			}

			rtn = 1;
		}
	}

	return rtn;

}


//15
int Nacionalidad_MostrarPromedio(eProducto pListaProducto[], int tProducto, eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int i;
	float promedio;
	int rtn;
	rtn = 0;

	for(i = 0; i < tNacionalidad; i++)
	{
		promedio = Nacionalidad_CalcularPromedio(pListaProducto, tProducto, pListaNacionalidad, tNacionalidad, pListaNacionalidad[i].idNacionalidad);
		if(promedio != -1)
		{
			printf("%s: %.2f\n", pListaNacionalidad[i].descripcionNacionalidad, promedio);
			rtn = 1;
		}
	}

	return rtn;
}


float Nacionalidad_CalcularPromedio(eProducto pListaProducto[], int tProducto, eNacionalidad pListaNacionalidad[], int tNacionalidad, int tipo)
{
	int i;
	int j;
	float acumuladorPrecios;
	float promedioPrecios;
	int contadorNacionalidad;
	promedioPrecios = -1;
	contadorNacionalidad = 0;
	acumuladorPrecios = 0;

	for(i = 0; i < tNacionalidad; i++)
	{
		for(j = 0; j < tProducto; j++)
		{
			if(tipo == pListaProducto[j].nacionalidad)
			{
				acumuladorPrecios += pListaProducto[j].precio;
				contadorNacionalidad++;
			}
		}
		break;
	}
	if(contadorNacionalidad != 0)
	{
		promedioPrecios = acumuladorPrecios / contadorNacionalidad;
	}
	return promedioPrecios;
}


//14
void aux_InicializarNacional(eAuxiliar auxiliar[], eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int i;

	for(i = 0; i < tNacionalidad; i++)
	{
		auxiliar[i].id = pListaNacionalidad[i].idNacionalidad;
		auxiliar[i].contador = 0;
	}
}
void aux_ContadorNacionalidad(eProducto pListaProducto[], int tProducto, eAuxiliar auxiliar[], eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int i;
	int j;

	for(i = 0; i < tProducto; i++)
	{
		j = Producto_BuscarIdAux(auxiliar, tNacionalidad, pListaProducto[i].nacionalidad);
		if(j != -1)
		{
			auxiliar[j].contador++;
		}
	}
}
int aux_CalcularMayor(eAuxiliar auxiliar[], eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int i;
	int mayor;

	for(i = 0; i < tNacionalidad; i++)
	{
		if(auxiliar[i].contador > mayor || i == 0)
		{
			mayor = auxiliar[i].contador;
		}
	}
	return mayor;
}
void aux_MostrarNacionalidadMayor(eAuxiliar auxiliar[], eNacionalidad pListaNacionalidad[], int tNacionalidad, int mayor)
{
	int i;

	for(i = 0; i < tNacionalidad; i++)
	{
		if(mayor == auxiliar[i].contador)
		{
			Nacionalidad_MostrarUno(pListaNacionalidad[i]);
		}
	}
}
int Nacionalidad_ConMasTipoProducto(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	eAuxiliar auxiliar[tNacionalidad];
	int mayor;

	aux_InicializarNacional(auxiliar, pListaNacionalidad, tNacionalidad);
	aux_ContadorNacionalidad(pListaProducto, tProducto, auxiliar, pListaNacionalidad, tNacionalidad);
	mayor = aux_CalcularMayor(auxiliar, pListaNacionalidad, tNacionalidad);
	aux_MostrarNacionalidadMayor(auxiliar, pListaNacionalidad, tNacionalidad, mayor);


	return 0;
}



//13
void Nacionalidad_OrdenarAlfabeticamente(eProducto pListaProducto[], int tProducto, eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int i;
	int j;
	eProducto auxiliarProducto;
	eAuxiliar auxiliar[tProducto];

	for(i = 0; i < tProducto; i++)
	{
		j = Nacionalidad_BuscarID(pListaNacionalidad, tNacionalidad, pListaProducto[i].nacionalidad);
		auxiliar[i].id = pListaProducto[i].idProducto;
		strncpy(auxiliar[i].descripcion, pListaNacionalidad[j].descripcionNacionalidad, 100);

	}


	for(i = 0; i < tProducto-1; i++)
	{
		for(j = i+1; j < tProducto; j++)
		{
				if(strcmp(auxiliar[i].descripcionNacionalidad, auxiliar[j].descripcionNacionalidad) > 0)
				{
					auxiliarProducto = pListaProducto[i];
					pListaProducto[i] = pListaProducto[j];
					pListaProducto[j] = auxiliarProducto;
				}
			}
		}

}
int Nacionalidad_MostrarProductos(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int rtn;
	int indexTipo;
	int indexNacionalidad;
	int i;

	rtn = -1;

	for(i = 0; i < tProducto; i++)
	{
		indexTipo = Tipo_BuscarID(pListaTipo, tTipo, pListaProducto[i].tipo);
		indexNacionalidad = Nacionalidad_BuscarID(pListaNacionalidad, tNacionalidad, pListaProducto[i].nacionalidad);
			rtn = 1;
			printf("\n%5d %15s %15s %15s %9.2f\n", pListaProducto[i].idProducto,
													pListaProducto[i].descripcion,
													pListaNacionalidad[indexNacionalidad].descripcionNacionalidad,
													pListaTipo[indexTipo].descripcionTipo,
													pListaProducto[i].precio);
	}

	return rtn;
}


//12
int Nacionalidad_SoloFabricaIphone(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
    int rtn;
    int i;
    int j;
    int p;
    rtn = 0;

    for(i = 0; i < tProducto; i++)
    {
    	p = Tipo_BuscarID(pListaTipo, tTipo, pListaProducto[i].tipo);
        j = Nacionalidad_BuscarID(pListaNacionalidad, tNacionalidad, pListaProducto[i].nacionalidad);

		if(pListaProducto[i].tipo == pListaTipo[p].idTipo && pListaProducto[i].nacionalidad == pListaNacionalidad[j].idNacionalidad)
		{
			if(strcmp(pListaTipo[p].descripcionTipo, "Iphone") == 0)
			{
				rtn = 1;
				printf("\n%5d %15s %15s %15s %9.2f\n", pListaProducto[i].idProducto,
																	pListaProducto[i].descripcion,
																	pListaNacionalidad[j].descripcionNacionalidad,
																	pListaTipo[p].descripcionTipo,
																	pListaProducto[i].precio);
			}
		}
    }
    return rtn;
}















//TIPO -----------------------------------------------------------

//16
int Tipo_Eliminar(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo)
{

	int i;
	int index;
	int rtn;
	int idEliminar;
	rtn = 0;

	Tipo_MostrarTodos(pListaTipo, tTipo);
	getInt(&idEliminar, "* Ingrese la ID del Tipo que desea eliminar: \n");
	index = Tipo_BuscarID(pListaTipo, tTipo, idEliminar);

	if(index != -1)
	{
		if(Confirmar_Respuesta("Seguro que desea eliminar este Tipo? 1. Si 0. No: ", "ERROR: Seguro que desea eliminar este Tipo?\nIngrese 1. Si 0. No: ") == 1)
		{
			pListaTipo[index].isEmpty = VACIO;
			for(i = 0; i < tProducto; i++)
			{
				if(idEliminar == pListaProducto[i].tipo)
				{
					pListaProducto[i].isEmpty = VACIO;
				}
			}
				rtn = 1;
		}
	}

	return rtn;

}

//11
void aux_Inicializar(eAuxiliar auxiliar[], eTipoProducto pListaTipo[], int tTipo)
{
	int i;

	for(i = 0; i < tTipo; i++)
	{
		auxiliar[i].id = pListaTipo[i].idTipo;
		auxiliar[i].contador = 0;
	}
}
int Producto_BuscarIdAux(eAuxiliar auxiliar[], int tAuxiliar, int id)
{
	int i;
	int rtn;
	rtn = -1;
	for(i = 0; i < tAuxiliar; i++)
	{
		if(auxiliar[i].id == id)
		{
			rtn = i;
		}
	}

	return rtn;
}
void aux_ContadorTipo(eProducto pListaProductos[], int tProducto, eAuxiliar auxiliar[], eTipoProducto pListaTipo[], int tTipo)
{
	int i;
	int j;

	for(i = 0; i < tProducto; i++)
	{
		j = Producto_BuscarIdAux(auxiliar, tTipo, pListaProductos[i].tipo);
		if(j != -1)
		{
			auxiliar[j].contador++;
		}
	}
}
int aux_calcularMaximo(eAuxiliar auxiliar[], int tAuxiliar)
{
	int maximo;
	int i;

	for(i = 0; i < tAuxiliar; i++)
		{
			if(auxiliar[i].contador > maximo || i == 0)
			{
				maximo = auxiliar[i].contador;
			}
		}

	return maximo;
}
void aux_MostrarTipoMayor(eAuxiliar auxiliar[], eTipoProducto pListaTipo[], int tTipo, int maximo)
{
	int i;

	for(i = 0; i < tTipo; i++)
	{
		if(maximo == auxiliar[i].contador)
		{
			Tipo_MostrarUno(pListaTipo[i]);
		}
	}
}
int Tipo_ConMasProductosElaborados(eProducto pListaProductos[], int tProducto, eTipoProducto pListaTipo[], int tTipo)
{
	eAuxiliar auxiliar[tTipo];
	int maximo;
	maximo = -1;

	aux_Inicializar(auxiliar, pListaTipo, tTipo);
	aux_ContadorTipo(pListaProductos, tProducto, auxiliar, pListaTipo, tTipo);
	maximo = aux_calcularMaximo(auxiliar, tTipo);
	aux_MostrarTipoMayor(auxiliar, pListaTipo, tTipo, maximo);

	return maximo;
}


//10
int Tipo_MostrarProductos(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo)
{
	eAuxiliar auxiliar[tTipo];
	int rtn;
	int i;
	int j;
	rtn = -1;

	aux_Inicializar(auxiliar, pListaTipo, tTipo);

	for(i = 0; i < tProducto; i++)
	{
		j = Producto_BuscarIdAux(auxiliar, tTipo, pListaProducto[i].tipo);
		if(j != -1)
		{
			printf("* %s: ", pListaTipo[j].descripcionTipo);
			Producto_MostrarUno(pListaProducto[i]);
			rtn = 1;
		}
	}

	return rtn;
}


//8

float Tipo_CalcularPromedio(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo)
{
	//SEPARAR EN FUNCIONES
	eAuxiliar auxiliar[tTipo];
	int i;
	int j;


	aux_Inicializar(auxiliar, pListaTipo, tTipo);

	for(i = 0; i < tProducto; i++)//Acumulo
	{
		j = Tipo_BuscarID(pListaTipo, tTipo, pListaProducto[i].tipo);
		if(j != -1)
		{
			auxiliar[j].acumulador += pListaProducto[i].precio;
			auxiliar[j].contador++;
		}
	}

	for(i = 0; i < tTipo; i++)
	{
		if(auxiliar[i].contador != 0)
		{
			Calcular_Promedio(&auxiliar[i].promedio ,auxiliar[i].acumulador, auxiliar[i].contador);
		}
	}

	for(i = 0; i < tTipo; i++)
	{
		if(auxiliar[i].contador != 0)
		{
		printf("El promedio de %s es: %.2f\n", pListaTipo[i].descripcionTipo, auxiliar[i].promedio);
		}
	}


	return 0;
}
void Calcular_Promedio(float* pResultado, float total, int cantidad)
{

	if(cantidad != 0)
	{
		*pResultado = total / cantidad;
	}

}



















//PRODUCTOS ------------------------------------------------------

//9
int Producto_MostrarConDescripcion(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo)
{
	int i;
	int rtn;
	int j;

	rtn = 0;

	for(i = 0; i < tProducto; i++)
	{
		j = Tipo_BuscarID(pListaTipo, tTipo, pListaProducto[i].tipo);
		if(j != -1)
		{
			rtn = 1;
			printf("\n%5d %15s %15d %15s %9.2f\n", pListaProducto[i].idProducto,
													pListaProducto[i].descripcion,
													pListaProducto[i].nacionalidad,
													pListaTipo[j].descripcionTipo,
													pListaProducto[i].precio);
		}
	}

	return rtn;
}

//7 REVISAR
int Producto_CalcularMasCaro(eProducto pListaProducto[], int tProducto)
{
    int i;
    int rtn;
    int auxiliarPrecio;
    rtn = -1;

    for(i = 0; i < tProducto; i++)
    {
		if(pListaProducto[i].precio > auxiliarPrecio || i == 0)
		{
		   auxiliarPrecio = pListaProducto[i].precio;
		   rtn = i;

		}
    }
    if(rtn != -1)
    {
    	Producto_MostrarUno(pListaProducto[rtn]);
    }

    return rtn;
}

//6
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

//5
void Producto_OrdenarPrecio(eProducto pListaProducto[], int tProducto)
{
    int i;
    int j;
    eProducto auxiliar;

    for(i=0; i<tProducto-1; i++)
    {
        for(j=i+1; j < tProducto; j++)
        {
            if(pListaProducto[i].precio < pListaProducto[j].precio)
            {
               auxiliar = pListaProducto[i];
               pListaProducto[i] = pListaProducto[j];
               pListaProducto[j] = auxiliar;
            }
        }
    }
}

//3
int Producto_Modificar(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo)
{
	int index;
	int rtn;
	int idModificar;
	int opcionModificar;
	int nuevoTipo;
	float nuevoPrecio;
	rtn = 0;

	Producto_MostrarTodos(pListaProducto, tProducto);
	if(Confirmar_Respuesta("* Seguro que desea modificar? 1. Si 0. No: ", "* ERROR: Seguro que desea modificar?\nIngrese 1. Si 0. No: ") == 1)
	{
		Producto_GetId(pListaProducto, tProducto, "* Ingrese la ID del producto que desea modificar: \n", &idModificar);
		index = Producto_BuscarID(pListaProducto, tProducto, idModificar);
	}

	if(index != -1)
	{
			utn_getNumero(&opcionModificar, "* Que desea modificar: \n1. Tipo\n2. Precio\n", 1, 2);

			switch(opcionModificar)
			{
			case 1:
				Tipo_MostrarTodos(pListaTipo, tTipo);
				Tipo_GetId(pListaTipo, tTipo, "* Ingrese el tipo de producto: ", &nuevoTipo);
				if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No", "* ERROR: Confirmar cambios: Ingrese 1. Si 0. No: ") == 1)
				{
					pListaProducto[index].tipo = nuevoTipo;
					rtn = 1;
				}
				break;
			case 2:
				getFloat(&nuevoPrecio, "* Ingrese el nuevo precio del producto: ");
				if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No", "* ERROR: Confirmar cambios: Ingrese 1. Si 0. No: ") == 1)
				{
					pListaProducto[index].precio = nuevoPrecio;
					rtn = 1;
				}
				break;
			}
	}
	return rtn;
}

//1
int Producto_Cargar(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
    int i;
    int rtn;
    int auxiliar;
    rtn = -1;

    i = Producto_BuscarLibre(pListaProducto, tProducto);
    if(i != -1)
    {
    	getInt(&auxiliar, "Ingrese el Id del producto: ");

    	while(Producto_BuscarID(pListaProducto, tProducto, auxiliar) != -1)
    	{
    		getInt(&auxiliar, "ERROR: El ID ya existe, Ingrese otro: ");
    	}

		pListaProducto[i] = Producto_PedirDatos(pListaTipo, tTipo, pListaNacionalidad, tNacionalidad);
		pListaProducto[i].idProducto = auxiliar;
		rtn = 1;
    }

    return rtn;
}





eProducto Producto_PedirDatos(eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	eProducto productoIngresado;

	get_Descripcion(productoIngresado.descripcion, 100,"Ingrese la descripcion del producto: ");

	Nacionalidad_GetId(pListaNacionalidad, tNacionalidad, "Ingrese la nacionaldad del producto: ", &productoIngresado.nacionalidad);

	Tipo_GetId(pListaTipo, tTipo, "Ingrese el tipo de producto: ", &productoIngresado.tipo);

    getFloat(&productoIngresado.precio, "Ingrese el precio del producto: ");

    productoIngresado.isEmpty = OCUPADO;

    return productoIngresado;
}
