#include "utn.Get.h"

void myGets(char pResultado[], int tResultado, char mensaje[])
{
	char cadenaString[1000];

		printf("%s",mensaje);
		fflush(stdin);
		fgets(cadenaString, sizeof(cadenaString),stdin);

		while(strlen(cadenaString) > tResultado || strlen(cadenaString) == 0)
		{
			printf("ERROR: Esta fuera del rango -> Minimo = 1 Maximo = %d.\n", tResultado);
			fflush(stdin);
			fgets(cadenaString, sizeof(cadenaString),stdin);
		}

		strncpy(pResultado, cadenaString, tResultado);

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

    while(esNumerica(pResultado) == 0)
	{
    	printf("ERROR: Eso no es un numero.");
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

	if(strlen(pResultado) > 0)
	{
		for(i = 0; strlen(pResultado) > i; i++)
		{
			if(isdigit(pResultado) == 0)
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
    	printf("ERROR: Eso no es un numero.");
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
		printf("ERROR: El numero %d esta fuera del rango -> Minimo = %d Maximo = %d.\n", numeroIngresado ,minimo, maximo);
		getFloat(&numeroIngresado, mensaje);
	}

	*pResultado = numeroIngresado;

}
