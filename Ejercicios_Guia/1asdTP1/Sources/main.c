#include <stdio.h>
#include "../Headers/funcionesMath.h"
#include "../Headers/funcionesGet.h"
#include "../Headers/funcionesVarias.h"

int main()
{
	//Declaración de variables
	//Variables de entrada
	int opcion;
	long long int primerNumero;
	long long int segundoNumero;

	//Variables de salida
	long long int resultadoSuma;
	long long int resultadoResta;
	long long int resultadoMultiplicacion;
	double resultadoDivision;
	unsigned long long factorialUno;
	unsigned long long factorialDos;

	//Variables flag, inicializadas en 0
	int ingresadoPrimerNumero = 0;
	int ingresadoSegundoNumero = 0;
	int calculosRealizados = 0;

	//Bucle do while con switch para interactuar con menú de opciones
	do
	{
		//Se muestra header de calculadora, y las 5 opciones.
		mostrarMenuHeaders("               Calculadora","             Menú de opciones");
		printf("1. Ingresar 1er operando");
		if (ingresadoPrimerNumero == 1)
		{
			printf(" (A=%lld)",primerNumero);
		}
		printf("\n2. Ingresar 2do operando");
		if (ingresadoSegundoNumero == 1)
		{
			printf(" (B=%lld)",segundoNumero);
		}
		printf("\n3. Calcular todas las operaciones");
		printf("\n4. Informar resultados");
		printf("\n5. Salir");
		printf("\n=======================================\n");

		//Hacemos el pedido de dato y asignamos el valor en variables opcion
		opcion = getIntValidacion("Ingrese una opción: ","Opción inválida, vuelva a intentarlo: ",5,1);

		switch (opcion)
		{
			case 1:
				// Caso opción 1. Mostramos header.
				mostrarMenuHeaders("               Calculadora","             Ingreso 1er operando");

				// Solicitamos ingreso de primer operando
				primerNumero = getInt("Ingrese un número: ");

				// Seteamos flag de primer número ingresado en 1 y cálculos realizados en 0.
				// Esto será para saber si podemos realizar y mostrar los resultados o no.
				ingresadoPrimerNumero = 1;
				calculosRealizados = 0;
			break;
			case 2:
				// Caso opción 2. Mostramos header.
				mostrarMenuHeaders("               Calculadora","             Ingreso 2do operando");

				// Solicitamos ingreso de segundo operando
				segundoNumero = getInt("Ingrese un número: ");

				// Seteamos flag de segundo número ingresado en 1 y cálculos realizados en 0.
				// Esto será para saber si podemos realizar y mostrar los resultados o no.
				ingresadoSegundoNumero = 1;
				calculosRealizados = 0;
			break;
			case 3:
				// Caso opcion 3. Verificamos que estén ingresados ambos operandos.
				if (ingresadoPrimerNumero == 1  && ingresadoSegundoNumero == 1)
				{
					//Si ambos están ingresados, realizamos cálculos con funciones de la biblioteca funcionesMath
					resultadoSuma = suma(primerNumero,segundoNumero);
					resultadoResta = resta(primerNumero,segundoNumero);
					resultadoMultiplicacion = multiplicacion(primerNumero,segundoNumero);
					resultadoDivision = division(primerNumero,segundoNumero);
					factorialUno = factorial(primerNumero);
					factorialDos = factorial(segundoNumero);

					// Asignamos valor 1 a flag de calculos realizados
					calculosRealizados = 1;
				}
				else {
					// Si no se ingresaron los dos operandos, mostramos header y error.
					mostrarMenuHeaders("               Calculadora","  No se pudieron realizar los cálculos");
					pause("Debe ingresar ambos operandos para realizar los cálculos.\nPulse <Enter> para volver...");
				}
			break;
			case 4:
				// Caso opcion 4. Mostramos header correspondiente.
				mostrarMenuHeaders("               Calculadora","                Resultados");

				if (calculosRealizados == 1){

					// Si se realizaron los cálculos mostramos resultado de las distintas operaciones.
					printf("a. El resultado de (%lld)+(%lld) es: %lld\n",primerNumero,segundoNumero,resultadoSuma);
					printf("b. El resultado de (%lld)-(%lld) es: %lld\n",primerNumero,segundoNumero,resultadoResta);
					printf("c. El resultado de (%lld)*(%lld) es: %lld\n",primerNumero,segundoNumero,resultadoMultiplicacion);

					if (segundoNumero != 0)
					{
						// En el caso que el segundo operando sea distinto de cero, mostramos el resultado de la división.
						printf("d. El resultado de (%lld)/(%lld) es: %.4f\n",primerNumero,segundoNumero,resultadoDivision);
					}

					else
					{
						// Si es cero, indicamos error.
						printf("d. No es posible dividir por cero.\n");
					}

					if (factorialUno == 0)
					{
						//En caso de que factorialUno sea 0, significa que no se pudo calcular el mismo, damos mensaje correspondiente.
						printf("e. No se puede calcular el factorial de %lld por ser negativo o mayor a 20. ",primerNumero);
					}
					else
					{
						//Sino, mostramos resultado.
						printf("e. El factorial de %lld es: %llu. ",primerNumero,factorialUno);
					}

					if (factorialDos == 0)
					{
						//En caso de que factorialDos sea 0, significa que no se pudo calcular el mismo, damos mensaje correspondiente.
						printf("No se puede calcular el factorial de %lld por ser negativo o mayor a 20.\n",segundoNumero);
					}
					else
					{
						//Sino, mostramos resultado.
						printf("El factorial de %lld es: %llu\n",segundoNumero,factorialDos);
					}

				}
				else
				{
					//En caso de que no se hayan calculado los resultados, no podemos mostrarlos. Mostramos mensaje de error.
					printf("Debe calcular los resultados antes de mostrarlos.\n");
				}
				pause("\nPulse <Enter> para continuar...");
			break;

			case 5:
				// Caso opcion 5. Mensaje de despedida.
				mostrarMenuHeaders("               Calculadora","                 Adios!");
			break;
		}

	} while (opcion != 5);
	return 0;
}
