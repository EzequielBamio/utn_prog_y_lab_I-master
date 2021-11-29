#include <stdio.h>

void mostrarMenuHeaders (char titulo[], char subtitulo[])
{
	system("clear");
	printf("=======================================\n");
	printf("%s\n",titulo);
	printf("=======================================\n");
	printf("=======================================\n");
	printf("%s\n",subtitulo);
	printf("=======================================\n");
}

void pause (char mensaje[])
{

	printf("%s",mensaje);
	__fpurge(stdin); //Se realiza fpurge para limpiar el buffer y evitar saltar la pausa automaticamente.
	getchar();

}
