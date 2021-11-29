/*
 ============================================================================
Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void  Sumar3(int, int);
void Sumar4(void);

 ============================================================================
 */


int Sumar1(int, int);//prototipo
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int resultadoSumar1;

	resultadoSumar1 = Sumar1(6,5);
	printf("La suma es: %d\n", resultadoSumar1);

	int resultadoSumar2;

	resultadoSumar2 = Sumar2();

	printf("La suma2 es: %d\n", resultadoSumar2);

	Sumar3(5,5);

	Sumar4();



	return EXIT_SUCCESS;
}

int Sumar1(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}


int Sumar2(void)
{
	int numeroUno;
	int numeroDos;
	int resultado;

	printf("Ingrese un numero \n");
	scanf("%d", &numeroUno);

	printf("Ingrese otro numero \n");
	scanf("%d", &numeroDos);

	resultado = numeroUno + numeroDos;

	return resultado;
}

void Sumar3(int numeroUno, int numeroDos)
{
	int resultado;
	resultado = numeroUno + numeroDos;

	printf("El resultado de Sumar3 es: %d\n", resultado);
}

void Sumar4(void)
{
		int numeroUno;
		int numeroDos;
		int resultado;

		printf("Ingrese un numero\n");
		scanf("%d", &numeroUno);

		printf("Ingrese otro numero\n");
		scanf("%d", &numeroDos);

		resultado = numeroUno + numeroDos;

		printf("El resultado de Sumar4 es: %d", resultado);
}
