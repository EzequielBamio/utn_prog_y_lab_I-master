/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: ezequ
 */

#include <stdio.h>
#include <string.h>
#include "utnMath.h"

#ifndef UTN_H_
#define UTN_H_
/**
 * @fn void limpiar_pantalla()
 * @brief Limpia la pantalla de la consola, si es windows usa system cls, sino usa system clear.
 *
 */
void limpiar_pantalla();
/**
 * @fn int Pedir_Entero(char[], char[])
 * @brief pide un numero entero.
 *
 * @param mensaje para cuando se pide ingresar un numero.
 * @return retorna el numero ingresado.
 */
int Pedir_Entero(char mensaje[]);
/**
 * @fn int Pedir_Entero_Con_Rango(char[], char[], int, int)
 * @brief Pedi un numero Entero entre un minimo y un maximo.
 *
 * @param mensaje que se muestra cuando se pide el numero.
 * @param mensaje de error cuando el usuario ingresa un numero fuera del rango.
 * @param el minimo de los numeros que puede ingresar.
 * @param el maximo de los numeros que puede ingresar.
 * @return retorna el numero entero que este en el rango establecido.
 */
int Pedir_Entero_Con_Rango(char mensaje[], char errorMensaje[], int minimo, int maximo);
/**
 * @fn float Pedir_Decimal(char[])
 * @brief Pedir un numero decimal.
 *
 * @param mensaje para pedir el numero.
 * @return retorna el numero ingresado.
 */
float Pedir_Decimal(char mensaje[]);
/**
 * @fn int Validar_NumeroEntero(float)
 * @brief Valida que el numero ingresado sea Entero.
 *
 * @param Numero ingresado por el usuario.
 * @return retorna 1 si es entero, sino retorna -1 (si es un numero decimal).
 */
int Validar_NumeroEntero(float xIngresado);
/**
 * @fn int MenuOpciones(float, float)
 * @brief Muestra el menu de opciones, cada vez que el usuario ingresa un numero se muestra el numero en el menu.
 *
 * @param primer numero ingresado por el usuario, se muestra en el 1er operando "A = primerNumero".
 * @param segundo numero ingresado por el usuario, se muestra en el 2do operando "A = segundoNumero".
 * @return retorna la opcion elegida.
 */
int MenuOpciones(float primerNumero, float segundoNumero);
/**
 * @fn void InformarResultados(float, float, float, int, int, float)
 * @brief Muestra los resultados de las operaciones
 *
 * @param recibe el resultado de la suma
 * @param recibe el resultado de la resta
 * @param recibe el resultado de la multiplicacion
 * @param recibe el resultado del factorial A
 * @param recibe el resultado del factorial B
 * @param recibe el resultado de la division
 */
void InformarResultados(float s, float r, float m, int fA, int fB, float d);

#endif /* UTN_H_ */
