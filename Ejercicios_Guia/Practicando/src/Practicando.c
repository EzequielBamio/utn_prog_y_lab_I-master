/*
 ============================================================================
 Name        : Practicando.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    setbuf(stdout, NULL);

	FILE *pArchivo;
	int numeros;
	//numeros = 64;

	/*pArchivo = fopen("numero.dat", "wb");

	fwrite(&numeros, sizeof(int), 1, pArchivo);*/

	/*pArchivo = fopen("numero.dat", "rb");

	int x = fread(&numeros, sizeof(int), 1, pArchivo);

	fclose(pArchivo);

	printf("%d -- %d", x, numeros);*/





	//char cadena[100] = "Estudiante de programación: Ezequiel Bamio ";
	//char cadenaActualizacion[100] = "actualizado // 07-06";

	//char cadenaLectura[100];

	//EJEMPLO DE ESCRIBIR

	//abrir
	/*
	pArchivo = fopen("archivo_prueba.txt", "w");//escribir y leer, (w, r, wb, rb), (a - Escribe en la ultima linea del archivo)
	//usar
	if(pArchivo != NULL)
	{
		fprintf(pArchivo, "%s\n%s", cadena, cadenaActualizacion);
		//cerrar
		fclose(pArchivo);
	}else
	{
		printf("No se encontro el directorio");
	}
	*/

	//EJEMPLO DE LEER

	/*
	 * pArchivo = fopen("archivo_prueba.txt", "r");
	if(pArchivo != NULL)
	{
		fgets(cadenaLectura, 100, pArchivo);
		puts(cadenaLectura);
		fgets(cadenaLectura, 100, pArchivo);
		puts(cadenaLectura);
		fclose(pArchivo);
	}else
	{
		printf("No se encontro el directorio");
	}
	*/









	return EXIT_SUCCESS;
}
