#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define T 1000

#ifndef PEDIR_H_
#define PEDIR_H_

int Pedir_Entero(char [], char []);
int Pedir_Entero_Con_Rango(char [], char [], int, int);
float Pedir_Decimal(char [], char []);
float Pedir_Decimal_Con_Rango(char [], char [], float, float);
double Pedir_Double(char [], char []);
double Pedir_Double_Con_Rango(char [], char [], double, double);
char Pedir_Caracter(char [], char []);
void Pedir_Cadena(char [], char [], char [], int);

#endif /* PEDIR_H_ */
