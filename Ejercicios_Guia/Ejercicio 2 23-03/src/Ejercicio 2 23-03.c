/*
 ============================================================================
Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit, X
validando que las temperaturas ingresas estén entre el punto de congelación y ebullición del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca. X
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.

	Bamio Ezequiel

 ============================================================================
 */

#include <stdlib.h>
#include "transformacionTemperatura.h"
#include "validacionTemperaturas.h"


int main(void) {

	setbuf(stdout,NULL);

	int opcionTemperatura;
	int celcius;
	int fahrenheit;
	float celsiusAFahrenheit;
	float fahrenheitACelsius;


	printf("Que temperatura quiere cargar? 1. Celsius 0. Fahrenheit ");
	scanf("%d", &opcionTemperatura);

	if(opcionTemperatura == 1)
	{
		celcius = ValidarTemperatura("Ingrese la temperatura en Celsius", "Error. Ingrese la temperatura en Celsius", 0, 100);
		celsiusAFahrenheit = TransformarCelsiusAFahrenheit(celcius);
		printf("%.1f", celsiusAFahrenheit);
	}else
	{
		if(opcionTemperatura == 0)
		{
			fahrenheit = ValidarTemperatura("Ingrese la temperatura en Fahrenheit", "Error. Ingrese la temperatura en Fahrenheit", 32, 212);
			fahrenheitACelsius = TransformarFahrenheitACelsius(fahrenheit);
			printf("%.4f", fahrenheitACelsius);
		}
	}

	return EXIT_SUCCESS;
}



