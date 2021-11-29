/*
 * utnClase6.c
 *
 *  Created on: 2 abr. 2021
 *      Author: ezequ
 */

#include "utnClase6.h"

void MostrarNombreApellido(char nombrecompleto[], char nombre[], char apellido[])
{
	strcpy(nombrecompleto, nombre);
	strcpy(nombrecompleto, ",");
	strcpy(nombrecompleto, apellido);
}

//Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
void PedirCadena(char mensaje[], char cadena[])
{

	printf("%s", mensaje);
	gets(cadena);

}
