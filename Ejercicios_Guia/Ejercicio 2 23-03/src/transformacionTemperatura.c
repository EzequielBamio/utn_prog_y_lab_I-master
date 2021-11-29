/*
 * transformacionTemperatura.c
 *
 *  Created on: 23 mar. 2021
 *      Author: ezequiel
 */

#include "transformacionTemperatura.h"















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

