#include "Matematica.h"
/*
 * 6. Matematica
    * 6.1: TransformarCelsiusAFahrenhei
    * 6.2: TransformarFahrenheitACelsiu
    * 6.3: Sumar_Pare
    * 6.4: Mayor_Impa
    * 6.5: Sumar_Antecesore
    * 6.6: Menor_Negativ
    * 6.7: Promedio_Positivo
    * 6.8: Suma
    * 6.9: Resta
    * 6.10: Multiplica
    * 6.11: Factoria
    * 6.12: Dividir
	*/
float TransformarCelsiusAFahrenheit(float temperatura)
{
	float temperaturaAFahrenheit;

	temperaturaAFahrenheit = (temperatura * 9/5) + 32;

	return temperaturaAFahrenheit;
}

float TransformarFahrenheitACelsius(float temperatura)
{
	float temperaturaACelsius;

	temperaturaACelsius = (temperatura - 32) * 5/9;

	return temperaturaACelsius;
}

int Sumar_Pares(int numero[], int cantidad)
{
	int i;
	int acumuladorPares;
	int esPar;
	acumuladorPares = 0;
	for(i = 0; i < cantidad; i++)
	{
		esPar = Validar_Paridad(numero[i]);
		if(esPar == 1)
		{
			acumuladorPares += numero[i];
		}
	}

	return acumuladorPares;
}
int Mayor_Impar(int numero[], int cantidad)
{
	int mayorImpar;
	int esImpar;
	int i;

	mayorImpar = -1;

	for(i = 0; i < cantidad; i++)
	{
		esImpar = Validar_Paridad(numero[i]);
		if(numero[i] > mayorImpar || i == 0)
		{
			if(esImpar == 0)
			{
				mayorImpar = numero[i];
			}
		}
	}

	return mayorImpar;
}
int Sumar_Antecesores(int numero)
{
	int i;
	int acumuladorAntecesores;
	acumuladorAntecesores = 0;


	for(i = numero+1; i < 0; i++)
	{
		acumuladorAntecesores += i;
	}

	return acumuladorAntecesores;
}

int Menor_Negativo(int numeros[], int cantidad)
{
	int i;
	int negativo;
	int menorNegativo;

	for(i = 0; i < cantidad; i++)
	{
		negativo = Validar_Positivo(numeros[i]);
		if(menorNegativo > numeros[i] || i == 0)
		{
			if(negativo == -1)
			{
				menorNegativo = numeros[i];
			}
		}
	}

	return menorNegativo;
}

int Promedio_Positivos(int numeros[], int cantidad)
{
	int i;
	int positivo;
	int acumuladorPositivos;
	int promedioPositivos;
	acumuladorPositivos = 0;

	for(i = 0; i < cantidad; i++)
	{
		positivo = Validar_Positivo(numeros[i]);
		if(positivo == 1)
		{
			acumuladorPositivos += numeros[i];
		}
	}

	promedioPositivos = acumuladorPositivos / cantidad;

	return promedioPositivos;
}


float Sumar(float x, float y)
{
	float rtn;

	rtn = x + y;

	return rtn;
}

float Restar(float x, float y)
{
	float rtn;

	rtn = x - y;

	return rtn;
}

float Multiplicar(float x, float y)
{
	float rtn;

	rtn = x * y;

	return rtn;

}
int Factorial(char x[])
{
	int i;
	int factorial;
	int entero;
	factorial = 1;

	if(Validar_NumeroEntero(x) == 1)
	{
		entero = atoi(x);

		if(entero == 1 && x > 0)
		{
			for(i = entero; i > 1; i--)
			{
				factorial = factorial * i;
			}
		}
	}else
	{
		factorial = -1;
	}

	return factorial;

}
float Dividir(float x, float y)
{
	float rtn;
	rtn = -1;

	if(y != 0)
	{
		rtn = x / y;
	}

	return rtn;
}
