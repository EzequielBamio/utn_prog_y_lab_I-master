#include "utn.Get.h"
#include "Struct.Tipo.h"
#include "Struct.Nacionalidad.h"

// MENUS
void Nacionalidad_SubMenu(eProducto pListaProducto[], int tProducto, eNacionalidad pListaNacionalidad[], int tNacionalidad)
{
	int opcion;

	 do
		{
		 printf("*************************************************");
		printf("\n  				    				         ");
		printf("\n  	            Nacionalidad	             ");
		printf("\n  				 				             ");
		printf("\n*************************************************\n");
		printf("1. ALTA.\n");
		printf("2. BAJA\n");
		printf("3. MODIFICACION\n");
		printf("4. MOSTRAR TODOS\n");
		printf("\n");
		printf("5. Salir\n");

		utn_getNumero(&opcion, "Elija una opcion: ", 1, 5);

		switch(opcion)
		{
			case 1:
				if(Nacionalidad_Cargar(pListaNacionalidad, tNacionalidad) == 1)
				{
					printf("* La nacionalidad fue cargado con exito!\n");
				}else
				{
					printf("* No hay espacio disponible!\n");
				}
				system("pause");
				break;
			case 2:
				if(Nacionalidad_Eliminar(pListaProducto, tProducto, pListaNacionalidad, tNacionalidad) == 1)
				{
					printf("* La Nacionalidad de producto fue eliminado!\n");
				}else
				{
					printf("* Se cancelo la eliminacion de la Nacionalidad del producto\n");
				}
				system("pause");
				break;
			case 3:
//				if(Nacionalidad_Modificar(pListaNacionalidad, tNacionalidad) == 1)
//				{
//					printf("* La nacionalidad se modifico con exito!\n");
//				}else
//				{
//					printf("* Se cancelo la modificacion de la nacionalidad!\n");
//				}
//				system("pause");
				break;
			case 4:
				if(Nacionalidad_MostrarTodos(pListaNacionalidad, tNacionalidad) == 0)
				{
					printf("* No hay nacionalidades para mostrar\n");
				}
				system("pause");
				break;
		}
	}while(opcion != 5);
}

void Tipo_SubMenu(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo)
{
	int opcion;

	 do
		{
		 printf("*************************************************");
		printf("\n  				    				         ");
		printf("\n  	             TIPO				         ");
		printf("\n  				 				             ");
		printf("\n*************************************************\n");
		printf("1. ALTA.\n");
		printf("2. BAJA\n");
		printf("3. MODIFICACION\n");
		printf("4. MOSTRAR TODOS\n");
		printf("\n");
		printf("5. Salir\n");

		utn_getNumero(&opcion, "Elija una opcion: ", 1, 5);

		switch(opcion)
		{
			case 1:
//				if(Tipo_Cargar(pListaTipo, tTipo) == 1)
//				{
//					printf("* El tipo de producto fue cargado con exito!\n");
//				}else
//				{
//					printf("* No hay espacio disponible!\n");
//				}
//				system("pause");
				break;
			case 2:
				if(Tipo_Eliminar(pListaProducto, tProducto, pListaTipo, tTipo) == 1)
				{
					printf("* El tipo de producto fue eliminado!\n");
				}else
				{
					printf("* Se cancelo la eliminacion del tipo de producto\n");
				}
				system("pause");
				break;
			case 3:
//				if(Tipo_Modificar(pListaTipo, tTipo) == 1)
//				{
//					printf("* El tipo de producto se modifico con exito!\n");
//				}else
//				{
//					printf("* Se cancelo la modificacion del tipo de producto!\n");
//				}
//				system("pause");
				break;
			case 4:
				if(Tipo_MostrarTodos(pListaTipo, tTipo) == 0)
				{
					printf("* No hay tipos de producto para mostrar\n");
				}
				system("pause");
				break;
		}
	}while(opcion != 5);
}

/***************************************/
int Confirmar_Respuesta(char mensaje[], char mensajeError[])
{
	int rtn;
	rtn = 0;

	utn_getNumero(&rtn, mensaje, 0, 1);

	if(rtn == 1)
	{
		rtn = 1;
	}

	return rtn;
}


void get_Descripcion(char pResultado[], int tResultado, char mensaje[])
{
	myGets(pResultado, tResultado, mensaje);
	strlwr(pResultado);

	pResultado[0] = toupper(pResultado[0]);
}


void myGets(char pResultado[], int tResultado, char mensaje[])
{

	char cadenaString[1000];

	if(pResultado != NULL && tResultado > 0)
	{
		fflush(stdin);
		printf("%s",mensaje);

		if(fgets(cadenaString,sizeof(cadenaString),stdin) != NULL)
		{
			if(cadenaString[strnlen(cadenaString, sizeof(cadenaString))-1] == '\n')
			{
				cadenaString[strnlen(cadenaString, sizeof(cadenaString))-1] = '\0';
			}
			if(strnlen(cadenaString, sizeof(cadenaString)) < tResultado)
			{
				strncpy(pResultado, cadenaString, tResultado);
			}
		}
	}
}


int esCaracter(char pResultado[])
{
	int i;
	int rtn;
	rtn = 1;

	if(strlen(pResultado) > 0)
	{
		for(i = 0; strlen(pResultado) > 0; i++)
		{
			if(isalpha(pResultado[i]) == 0)
			{
				rtn = 0;
				break;
			}
		}
	}else
	{
		rtn = 0;
	}

	return rtn;
}


int esCaracterConEspacio(char pResultado[])
{
	int i;
	int rtn;
	rtn = 1;

	if(strlen(pResultado) > 0)
	{
		for(i = 0; strlen(pResultado) > 0; i++)
		{
			if(isalpha(pResultado[i]) == 0)
			{
				if(isspace(pResultado[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}else
	{
		rtn = 0;
	}

	return rtn;
}


void getInt(int* pResultado, char mensaje[])
{
    char cadenaString[50];

    myGets(cadenaString, sizeof(cadenaString), mensaje);

    while(esNumerica(cadenaString) == 0)
	{
    	printf("ERROR: Eso no es un numero.\n");
    	fflush(stdin);
        myGets(cadenaString, sizeof(cadenaString), mensaje);
	}

	*pResultado = atoi(cadenaString);
}


int esNumerica(char pResultado[])
{
	int i;
	int rtn;
	rtn = 1;
	if (strlen(pResultado) > 0)
	{
		for(i = 0; i < strlen(pResultado); i++)
		{
			if (isdigit(pResultado[i]) == 0)
			{
				if (i == 0)
				{
					if (pResultado[0] != '-')
					{
						rtn = 0;
						break;
					}
				}else
				{
					rtn = 0;
					break;
				}
			}
		}
	}else
	{
		rtn = 0;
	}
	return rtn;
}


void utn_getNumero(int* pResultado, char mensaje[], int minimo, int maximo)
{
	int numeroIngresado;

	getInt(&numeroIngresado, mensaje);
	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR: El numero %d esta fuera del rango -> Minimo = %d Maximo = %d.\n", numeroIngresado ,minimo, maximo);
		getInt(&numeroIngresado, mensaje);
	}

	*pResultado = numeroIngresado;

}


void getFloat(float* pResultado, char mensaje[])
{
	char cadenaString[50];

    myGets(cadenaString, sizeof(cadenaString), mensaje);

	while(esFlotante(cadenaString) == 0)
	{
    	printf("ERROR: Eso no es un numero.\n");
    	fflush(stdin);
	    myGets(cadenaString, sizeof(cadenaString), mensaje);
	}

	*pResultado = atof(cadenaString);

}


int esFlotante(char pResultado[])
{
	int rtn;
	int i;
	int contadorSigno;

	contadorSigno = 0;
	rtn = 1; // VERDADERO

	if(strlen(pResultado) > 0){
		for(i = 0; i < strlen(pResultado); i++)
		{

			if(pResultado[i] == '.'|| pResultado[i] == ',')
			{
				contadorSigno++;
			}
			else
			{
				if(isdigit(pResultado[i]) == 0)
				{
					if(i == 0)
					{
						if(pResultado[0] != '-')
						{
							rtn = 0;
							break;
						}
					}else
					{
						rtn = 0;
						break;
					}
				}
			}
		}
		if(contadorSigno > 1)
		{
			rtn = 0;
		}
		}else
		{
			rtn = 0;
		}

	return rtn;
}


void utn_getNumeroFlotante(float* pResultado, char mensaje[], float minimo, float maximo)
{
	float numeroIngresado;

	getFloat(&numeroIngresado, mensaje);
	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR: El numero %.2f esta fuera del rango -> Minimo = %.2f Maximo = %.2f.\n", numeroIngresado ,minimo, maximo);
		getFloat(&numeroIngresado, mensaje);
	}

	*pResultado = numeroIngresado;

}
