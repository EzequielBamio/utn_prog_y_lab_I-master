#include "Validaciones.h"
/*
 * 5. Validaciones
    * 5.1: Validar_NumeroEntero
    * 5.2: Validar_NumeroDecimal
    * 5.3: Validar_Cadena
    * 5.4: Validar_Cadena_Con_Espacio
    * 5.5: Validar_Caracter
    * 5.6: Validar_Caracter_Con_Espacio
    * 5.7: Validar_Temperatura
    * 5.8: Validar_Paridad
    * 5.9: Validar_Positivo
 */

int Validar_NumeroEntero(char xIngresado[])
{

	int rtn = 1;

	if(strlen(xIngresado) > 0)
	{
		for(int i = 0; i < strlen(xIngresado); i++)
		{
			if(isdigit(xIngresado[i]) == 0)
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
int Validar_NumeroDecimal(char xIngresado[])
{
	int contadorSigno;
	int rtn;
	contadorSigno = 0;
	rtn = 1;

	if(strlen(xIngresado) > 0){
		for(int i = 0; i < strlen(xIngresado); i++)
		{

			if(xIngresado[i] == '.'|| xIngresado[i] == ',')
			{
				contadorSigno++;
			}
			else{
				if(isdigit(xIngresado[i]) == 0){
					rtn = 0;
					break;
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
int Validar_Cadena(char xIngresado[])
{
	int rtn = 1;

	if(strlen(xIngresado) > 0)
	{
		for(int i = 0; i < strlen(xIngresado); i++)
		{
			if(isalpha(xIngresado[i]) == 0)
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

int Validar_Cadena_Con_Espacio(char xIngresado[])
{
	int rtn = 1;

	if(strlen(xIngresado) > 0)
	{
		for(int i = 0; i < strlen(xIngresado); i++)
		{
			if(isalpha(xIngresado[i]) == 0){
				if(isspace(xIngresado[i]) == 0)
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
int Validar_Caracter(char xIngresado[])
{
	int rtn = 1;

	if(strlen(xIngresado) > 0)
	{
		for(int i = 0; i < strlen(xIngresado); i++)
		{
			if(isalpha(xIngresado[i]) == 0)
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

int Validar_Caracter_Con_Espacio(char xIngresado[])
{
	int rtn = 1;

	if(strlen(xIngresado) > 0)
	{
		for(int i = 0; i < strlen(xIngresado); i++)
		{
			if(isalpha(xIngresado[i]) == 0){
				if(isspace(xIngresado[i]) == 0)
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
float Validar_Temperatura(char mensaje [], char mensajeError[], float minimo, float maximo)
{
	float numeroIngresado;
	printf("%s\n", mensaje);
	scanf("%f", &numeroIngresado);

	while (numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("%s\n", mensajeError);
		scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}

int Validar_Paridad(int numero)
{
	int rtn;
	rtn = 0;

	if(numero % 2 == 0)
	{
		rtn = 1;
	}

	return rtn;
}
//1 es positivo 0 es cero -1 es negativo.
int Validar_Positivo(int numero)
{
	int rtn;
	rtn = 0;

	if(numero > 0)
	{
		rtn = 1;
	}else
	{
		if(numero < 0)
		{
			rtn = -1;
		}
	}

	return rtn;
}
