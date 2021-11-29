#include "utn.Get.h"

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
