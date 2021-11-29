#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int Validar_NumeroEntero(char[]);
int Validar_NumeroDecimal(char[]);
int Validar_Cadena(char[]);
int Validar_Cadena_Con_Espacio(char[]);
int Validar_Caracter(char []);
int Validar_Caracter_Con_Espacio(char []);
float ValidarTemperatura(char [],char [], float, float);
int Validar_Paridad(int);
int Validar_Positivo(int);

#endif /* VALIDACIONES_H_ */
