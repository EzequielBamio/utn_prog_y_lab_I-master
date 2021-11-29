/*
 ============================================================================
Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo:
Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
Gomez, Juan Ignacio
 ============================================================================
 */

#include <stdlib.h>
#include "utnClase6.h"
#include <string.h>
#include <ctype.h>

#define T 20
#define L sizeof(nombreCompleto)

int main(void) {

	setbuf(stdout,NULL);

	char nombre[T];
	char apellido[T];
	char nombreCompleto[100];
	int i;
	int len;

	//Pedimos el nombre y apellido
	printf("Ingrese su Nombre: ");
	gets(nombre);
	printf("Ingrese su Apellido: ");
	gets(apellido);

	//Copiamos el apellido a la candena nombreCompleto
	//Concatenamos una , a nombreCompleto
	//Concatenamos nombre a nombreCompleto
	strncpy(nombreCompleto, apellido, L);
	strncat(nombreCompleto, ", ", 50);
	strncat(nombreCompleto, nombre, L);

	//Convierte todo a minuscula
	strlwr(nombreCompleto);

	nombreCompleto[0] = toupper(nombreCompleto[0]);

	len = strlen(nombreCompleto);
	//Reccoremos la cadena, si i es igual a 0 la primera letra se convierte a Mayuscula
	//Si nombreCompleto en la posicion anterior es igual a espacio en blanco, se convierte en mayuscula la letra siguiente
	for(i=1; nombreCompleto[i] < len ; i++)
	{
		if(isspace(nombreCompleto[i]) != 0)
		{
	    	nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
	    }

	}
	//Mostramos la cadena
	puts(nombreCompleto);

	return EXIT_SUCCESS;
}
