#include "utnMath.h"
#include "utn.h"

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
int Factorial(float x)
{
	int i;
	int factorial;
	factorial = 1;

	if(Validar_NumeroEntero(x) == 1 && x > 0)
	{
		for(i = x; i > 1; i--)
		{
			factorial = factorial * i;
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
	rtn = -1001;

	if(y != 0)
	{
		rtn = x / y;
	}

	return rtn;
}
