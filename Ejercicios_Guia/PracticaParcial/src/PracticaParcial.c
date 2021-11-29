/*
 ============================================================================
 Name        : PracticaParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Struct.General.h"
#include "Struct.Raza.h"
#include "Struct.Mascotas.h"
#include "utn.Get.h"

#define SIZE_MASCOTAS 10
#define SIZE_RAZA 4

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eMascotas listaMascotas[SIZE_MASCOTAS] = {
			{1, "Pedro", 2, 'M', "Gato", 1, 1},
			{2, "Luna", 5, 'F', "Perro", 2, 1},
			{3, "Roco", 1, 'M', "Perro", 3, 1},
			{4, "Persi", 6, 'F', "Gato", 1, 1}};

	eRaza listaRaza[SIZE_RAZA] = {
			{1, "Siames", "Chico", "Tailandia", 1},
			{2, "Doberman", "Grande", "Alemania", 1},
			{3, "Persa", "Mediano", "Persia", 1},
			{4, "Pastor Belga", "Grande", "Belgica", 1}};

	//INICIALIAZO ARRAY DE ESTRUCTURA
	//eMascotas_Inicializar(listaMascotas, SIZE_MASCOTAS);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		printf("1. ALTA\n");
		printf("2. BAJA\n");
		printf("3. MODIFICACION\n");
		printf("4. LISTADO DE listaMascotas\n");
		printf("5. \n");

		printf("0. Salir\n");
		utn_getNumero(&opcion, "INGRESE OPCION: ", 0, 5);

		//MENU SWITCH
		switch (opcion)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opcion = 0;
			break;
		case 1:
			//ALTA
			if (eMascotas_Alta(listaMascotas, SIZE_MASCOTAS))
			{
				puts(" * MASCOTAS DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS MASCOTAS");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (eMascotas_Baja(listaMascotas, SIZE_MASCOTAS))
			{
				puts("\n * BAJA DE MASCOTAS EXITOSA");
				eMascotas_MostrarTodos(listaMascotas, SIZE_MASCOTAS);
			} else {
				puts("\n * BAJA DE MASCOTAS CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//MODIFICACION
			if (eMascotas_Modificacion(listaMascotas, SIZE_MASCOTAS)) {
				puts("\n * MODIFICACION DE MASCOTAS EXITOSA\n");
				eMascotas_MostrarTodos(listaMascotas, SIZE_MASCOTAS);
			} else {
				puts("\n * MODIFICACION DE MASCOTAS CANCELADA");
			}
			system("pause");
			break;
		case 4:
			//LISTADO listaMascotas
			Mascotas_MostrarTodos(listaMascotas, SIZE_MASCOTAS, listaRaza, SIZE_RAZA);
			system("pause");
			break;
		case 5:
			//ORDENAR listaMascotas
			criterioDeOrdenamiento = 1; //PEDIR CRITERIO DE ORDENAMIENTO
			eMascotas_Ordenamiento(listaMascotas, SIZE_MASCOTAS, criterioDeOrdenamiento);
			system("pause");
			break;
		}

	} while (opcion != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
