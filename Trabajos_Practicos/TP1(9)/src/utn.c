#include "utn.h"

#ifdef _WIN32
  #include <windows.h>
#endif

void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
int Pedir_Entero(char mensaje[])
{
	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}

int Pedir_Entero_Con_Rango(char mensaje[], char errorMensaje[], int minimo, int maximo)
{
	int numeroIngresado;

	numeroIngresado = Pedir_Entero(mensaje);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR: Ingrese un numero entre %d y %d.\n", minimo, maximo);
    	numeroIngresado = Pedir_Entero(mensaje);
	}

	return numeroIngresado;
}

float Pedir_Decimal(char mensaje[])
{
	float numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}
int Validar_NumeroEntero(float xIngresado)
{
	float auxiliar;
	int rtn;
	auxiliar = xIngresado - (int)xIngresado;
	rtn = -1;

	if(auxiliar == 0)
	{
		rtn = 1;
	}

	return rtn;
}

int MenuOpciones(float primerNumero, float segundoNumero)
{
	int rtn;

	printf("************* CALCULADORA *************\n\n");

	printf("1. Ingresar 1er operando (A: %.2f)\n", primerNumero);
	printf("2. Ingresar 2do operando (B: %.2f)\n", segundoNumero);
	printf("3. Calcular todas las operaciones \n");
	printf("4. Informar resultados \n\n");

	printf("5. Salir \n");
	printf("***************************************\n");

	rtn = Pedir_Entero_Con_Rango("Ingrese la opcion que desea: ", "ERROR. Ingrese una opción valida: ", 1, 5);

	return rtn;
}

void InformarResultados(float suma, float resta, float multiplicacion, int factorialA, int factorialB, float division)
{
	printf("------------------Resultados---------------------------\n");
	printf("* El resultado de A+B es: %.2f\n", suma);
	printf("* El resultado de A-B es: %.2f\n", resta);
	if(division != -1001)
	{
		printf("* El resultado de A/B es: %.2f\n", division);
	}else
	{
		printf("* No es posible dividir por cero\n");
	}
	printf("* El resultado de A*B es: %.2f\n", multiplicacion);

	if(factorialA != -1)
	{
		printf("* El factorial de A es: %d\n", factorialA);
	}else
	{
		printf("* No es posible hacer el factorial de A\n");
	}

	if(factorialB != -1)
		{
			printf("* El factorial de B es: %d\n", factorialB);
		}else
		{
			printf("* No es posible hacer el factorial de B\n");
		}
	printf("-------------------------------------------------------\n");
}
