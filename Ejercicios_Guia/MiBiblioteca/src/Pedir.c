#include "Pedir.h"
/*
 * 4. Pedir
    * 4.1 Pedir_Entero
    * 4.2 Pedir_Entero_Con_Rango
    * 4.3 Pedir_Decimal
    * 4.4 Pedir_Decimal_Con_Rango
    * 4.5 Pedir_Double
    * 4.6 Pedir_Double_Con_Rango
    * 4.7 Pedir_Caracter
    * 4.8 Pedir_Cadena


int Pedir_Entero(char mensaje[])
{
	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", numeroIngresado);

	return numeroIngresado;
}

int Pedir_Entero_Con_Rango(char mensaje[], char errorMensaje[], int minimo, int maximo)
{
	int numeroIngresado;

	numeroIngresado = Pedir_Entero(mensaje, errorMensaje);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR: Ingrese un numero entre %d y %d.\n", minimo, maximo);
    	numeroIngresado = Pedir_Entero(mensaje, errorMensaje);
	}

	return numeroIngresado;
}

float Pedir_Decimal(char mensaje[], char errorMensaje[])
{

	char numeroIngresado[T];
	float rtn;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", numeroIngresado);

	while(Validar_NumeroDecimal(numeroIngresado) == 0)
	{
		printf("%s", errorMensaje);
		fflush(stdin);
	    scanf("%[^\n]", numeroIngresado);
	}

	rtn = atoi(numeroIngresado);

	return rtn;
}

float Pedir_Decimal_Con_Rango(char mensaje[], char errorMensaje[], float minimo, float maximo)
{
	float numeroIngresado;
	numeroIngresado = Pedir_Decimal(mensaje, errorMensaje);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR: Ingrese un numero entre %.2f y %.2f.\n", minimo, maximo);
    	numeroIngresado = Pedir_Decimal(mensaje, errorMensaje);
	}

	return numeroIngresado;
}

double Pedir_Double(char mensaje[], char errorMensaje[])
{
	char numeroIngresado[T];
	double rtn;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", numeroIngresado);

	while(Validar_NumeroDecimal(numeroIngresado) == 0)
	{
		printf("%s", errorMensaje);
		fflush(stdin);
	    scanf("%[^\n]", numeroIngresado);
	}

	rtn = atoi(numeroIngresado);

	return rtn;
}

double Pedir_Double_Con_Rango(char mensaje[], char errorMensaje[], double minimo, double maximo)
{
	double numeroIngresado;
	numeroIngresado = Pedir_Double(mensaje, errorMensaje);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR: Ingrese un numero entre %.2f y %.2f.\n", minimo, maximo);
		numeroIngresado = Pedir_Double(mensaje, errorMensaje);
	}

	return numeroIngresado;
}
char Pedir_Caracter(char mensaje[], char errorMensaje[])
{
	char caracterIngresada[T];
	char rtn;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", caracterIngresada);

	while(strlen(caracterIngresada) > 1 || Validar_Caracter(caracterIngresada) == 0)
	{
		printf("%s", errorMensaje);
		fflush(stdin);
	    scanf("%[^\n]", caracterIngresada);
	}

	rtn = caracterIngresada[0];

	return rtn;
}

void Pedir_Cadena(char mensaje[], char errorMensaje[], char cadena[], int tam)
{
	char cadenaIngresada[T];

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", cadenaIngresada);

	strcpy(cadena, cadenaIngresada);
}
*/

