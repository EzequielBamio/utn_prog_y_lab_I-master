/*
 ============================================================================
1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
	a) Calcular la suma (A+B)
	b) Calcular la resta (A-B)
	c) Calcular la division (A/B)
	d) Calcular la multiplicacion (A*B)
	e) Calcular el factorial (A!)
4. Informar resultados
	a) “El resultado de A+B es: r”
	b) “El resultado de A-B es: r”
	c) “El resultado de A/B es: r” o “No es posible dividir por cero”
	d) “El resultado de A*B es: r”
	e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir

	Bamio Ezequiel

 ============================================================================
 */

#include <stdlib.h>
#include "utn.h"
#include "utnMath.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcionUsuario;
	float suma;
	float resta;
	float multiplicacion;
	int factorialA;
	int factorialB;
	float division;
	float primerNumero;
	float segundoNumero;

	primerNumero = 0;
	segundoNumero = 0;

	int banderaPrimerOperando;
	int banderaSegundoOperando;
	int banderaOperaciones;
	banderaOperaciones = 0;
	banderaPrimerOperando = 0;
	banderaSegundoOperando = 0;


	/*******
	 * Menu *
	 *******/

	do
	{
		opcionUsuario = MenuOpciones(primerNumero, segundoNumero);
		limpiar_pantalla();

		switch(opcionUsuario)
		{
		case 1:
				banderaPrimerOperando = 1;
				primerNumero = Pedir_Decimal("Ingrese el 1er operando: ");
			break;
		case 2:
				banderaSegundoOperando = 1;
				segundoNumero = Pedir_Decimal("Ingrese el 2do operando: ");
			break;
		case 3:
			if(banderaPrimerOperando == 1 && banderaSegundoOperando == 1)
			{
				banderaOperaciones = 1;
				suma = Sumar(primerNumero, segundoNumero);
				resta = Restar(primerNumero, segundoNumero);
				division = Dividir(primerNumero, segundoNumero);
				multiplicacion = Multiplicar(primerNumero, segundoNumero);
				factorialA = Factorial(primerNumero);
				factorialB = Factorial(segundoNumero);
				printf("Operaciones realizadas!\n");
				system("pause");

			}else
			{
				printf("ERROR: Debe ingresar los operandos antes de calcular las operaciones\n");
			}
			break;
		case 4:
			if(banderaOperaciones == 1)
			{
				InformarResultados(suma, resta, multiplicacion, factorialA, factorialB, division);
				system("pause");
				limpiar_pantalla();
				primerNumero = 0;
				segundoNumero = 0;
				banderaOperaciones = 0;
				banderaPrimerOperando = 0;
				banderaSegundoOperando = 0;
			}else
			{
				printf("ERROR: Debe calcular las operaciones antes de informar los resultados\n");
			}

			break;
		}

	}
	while(opcionUsuario != 5);




	return EXIT_SUCCESS;
}

