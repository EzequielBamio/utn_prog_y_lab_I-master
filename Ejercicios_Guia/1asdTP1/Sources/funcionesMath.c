#include <stdio.h>

long long int suma (long long int numeroUno, long long int numeroDos)
{
	long long int resultado;
	resultado = numeroUno+numeroDos;
	return resultado;
}

long long int resta (long long int numeroUno, long long int numeroDos)
{
	long long int resultado;
	resultado = numeroUno-numeroDos;
	return resultado;
}

long long int multiplicacion (long long int numeroUno, long long int numeroDos)
{
	long long int resultado;
	resultado = numeroUno*numeroDos;
	return resultado;
}

double division (double numeroUno, double numeroDos)
{
	double resultado;
	resultado = numeroUno/numeroDos;
	return resultado;

}

unsigned long long factorial(long long int numero)
{
	unsigned long long resultado;
	int i;
    // Números negativos no tienen factorial. Los mayores a 20 no pueden obtenerse porque llegan al límite del tipo de dato.
	if (numero >= 0 && numero <= 20)
    {
    	resultado = 1;
    	for (i=numero; i > 0; i--)
    	{
    		resultado*=i;
    	}
    }
    else
    {
    	resultado = 0;
    }

    return resultado;
}
