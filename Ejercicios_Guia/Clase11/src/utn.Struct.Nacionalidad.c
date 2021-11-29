#include "utn.Struct.Nacionalidad.h"
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


int Nacionalidad_Buscar_ID(eNacionalidad pListaNacionalidad[], int tNacionalidad, int valorBuscado)
{
	int i;
	int rtn;
	rtn = -1;

		for(i = 0; i < tNacionalidad; i++)
		{
			if(valorBuscado == pListaNacionalidad[i].idNacionalidad)
			{
				rtn = i;
			}
		}

	return rtn;
}


int Nacionalidad_Buscar_Libre(eNacionalidad pListaNacionalidad[], int pListaNacionalidad)
{
	int i;
	int index;
	index = -1;
	for(i=0; i < pListaNacionalidad; i++)
	{
		if(pListaNacionalidad[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}


void Nacionalidad_Mostrar_Uno(eNacionalidad pListaNacionalidad)
{
    printf("\nID Producto: %d Descripcion: %s Nacionalidad: %d Tipo: %d Precio: %.2f\n", pListaNacionalidad.idNacionalidad,
																						pListaNacionalidad.descripcionNacionalidad);
}


int Nacionalidad_Mostrar_Todos(eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
    int rtn;
    int i;
    rtn = 0;

    for(i=0; i < tNacionalidad; i++)
    {
    	if(pListaNacionalidad[i].isEmpty != VACIO)
    	{
    		Nacionalidad_Mostrar_Uno(pListaNacionalidad[i]);
     		rtn = 1;
    	}
    }
    return rtn;
}

int Nacionalidad_Modificar(eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int rtn;
	char modificarNacionalidad[50];
	int nuevoTipo;
	float nuevoPrecio;
	int index;

	rtn = 0;
	if(Mostrar_Todos_Los_Nacionalidad(pListaNacionalidad, tNacionalidad) != 0)
	{
		getInt(&index, "Ingrese la nacionalidad que desea modificar: ");
		if(buscar_Id(pListaNacionalidad, tNacionalidad, index))
		{
			myGets(&modificarNacionalidad, 50,"Ingrese la nueva nacionalidad")();
			if(Confirmar_Respuesta("Seguro que desea modificar este Producto? 1. Si 0. No", "ERROR: Seguro que desea modificar este Alumno?\nIngrese 1. Si 0. No") == 1)
			{
				strcpy(pListaNacionalidad[index].descripcionNacionalidad, modificarNacionalidad);
				rtn = 1;
				break;
			}
		}
	return rtn;
}


int Nacionalidad_Eliminar(eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int rtn;
	int index;
	rtn = 0; //Si se cancelo la baja

	if(Mostrar_Todos_Los_Nacionalidad(pListaNacionalidad, tNacionalidad) != 0)
	{
		getInt(&index, "Ingrese la nacionalidad que desea eliminar: ");

		if(Nacionalidad_Buscar_ID(pListaNacionalidad, tNacionalidad, index))
		{
			Mostrar_Un_Producto(pListaNacionalidad[index]);
			if(Confirmar_Respuesta("Seguro que desea eliminar esta nacionalidad? 1. Si 0. No: ", "ERROR: Seguro que desea eliminar esta nacionalidad?\nIngrese 1. Si 0. No: ") == 1)
			{
				pListaNacionalidad[index].isEmpty = VACIO;
				rtn = 1; //Si el confirmo la baja
			}
		}
	}
	return rtn;
}


int Nacionalidad_Cargar(eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
    int i;
    int rtn;
    rtn = -1;
    i = Buscar_Libre(pListaNacionalidad, tNacionalidad);
    if(i != -1)
      {
      	 pListaNacionalidad[i] = Pedir_Datos();
      	 if(!Buscar_Libre(pListaNacionalidad, tNacionalidad))
      	 {
  			 pListaNacionalidad[i].isEmpty = i;
      	 }

      	 rtn = 1;
      }

    return rtn;
}


eNacionalidad Nacionalidad_Pedir_Datos()
{
	eNacionalidad productoIngresado;

	getInt(&productoIngresado.idNacionalidad, "* Ingrese el Id de la Nacionalidad: ");
	myGets(productoIngresado.descripcionNacionalidad, T, "* Ingrese la nacionalidad: ");

    productoIngresado.isEmpty = OCUPADO;

    return productoIngresado;
}


void Nacionalidad_Inicializar(eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int i;

	for(i = 0; i < tNacionalidad; i++)
	{
		pListaNacionalidad[i].isEmpty = VACIO;
	}
}
