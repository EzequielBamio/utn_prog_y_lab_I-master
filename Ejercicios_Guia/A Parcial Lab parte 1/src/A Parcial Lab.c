#include <stdio.h>
#include <stdlib.h>
#include "Struct.General.h"

#define SIZE_SERVICIO 4
#define SIZE_TRABAJO 6
#define SIZE_MARCA 5
int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	float TotalPrecio;


	//CREO ARRAY DE ESTRUCTURA
	eMarca listaMarca[SIZE_MARCA] = {
			{1, "Scott", 1},
			{2, "Specialized", 1},
			{3, "Trek", 1},
			{4, "BMC", 1}

	};

	eServicio listaServicio[SIZE_SERVICIO] = {
			{20000, "Liempieza", 250, 1},
			{20001, "Parche", 300, 1},
			{20002, "Centrado", 400, 1},
			{20003, "Cadena", 350, 1}
	};

	eTrabajo listaTrabajo[SIZE_TRABAJO];/* = {
			{1, 2, 24, 20000, {14, 2, 2001}, 1},
			{2, 1, 28, 20000, {2, 4, 2001}, 1},
			{3, 1, 15, 20002, {16, 8, 2000}, 1},
			{4, 4, 15, 20002, {16, 8, 2000}, 1},
			{5, 3, 24, 20003, {5, 11, 2004}, 1},
	};*/

	//eMarca_Inicializar(listaMarca, SIZE_MARCA);
	//eServicio_Inicializar(listaServicio, SIZE_SERVICIO);
	eTrabajo_Inicializar(listaTrabajo, SIZE_TRABAJO);

	//BUCLE DE MENU
	do {
	    printf("\n********************* MENU *********************\n");
		//MENU PRINT
		printf("1. TRABAJOS\n");
		printf("2. SERVICIOS\n");
		printf("3. MARCA\n");
		printf("4. LISTADO ORDENADO POR ANIO\n");
		printf("5. PRECIO TOTAL EN PESOS\n");
		printf("6. El/los Servicios con mas servicios prestados\n");
		printf("7. \n");

		printf(" \n");

		printf("0. Salir\n");
		utn_getNumero(&opcion, "INGRESE OPCION: ", 0, 7);
		system("cls");

		//MENU SWITCH
		switch (opcion)
		{
		case 0:
			opcion = 0;
			break;
		case 1:
			//ALTAS
			Sub_MenuTrabajos(listaServicio, SIZE_SERVICIO, listaTrabajo, SIZE_TRABAJO, listaMarca, SIZE_MARCA);

			system("pause");
			break;
		case 2:
			Sub_MenuServicios(listaServicio, SIZE_SERVICIO);

			system("pause");
			break;
		case 3:
			Sub_MenuMarca(listaMarca, SIZE_MARCA);

			system("pause");
			break;
		case 4:
			eTrabajo_Ordenamiento(listaTrabajo, SIZE_TRABAJO, listaMarca, SIZE_MARCA);
			if(eTrabajo_MostrarTodos(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaMarca, SIZE_MARCA) == 0)
			{
				puts("* NO HAY TRABAJOS PARA MOSTRAR.");
			}

			system("pause");
			break;
		case 5:
			if(Total_ServiciosPrestados(&TotalPrecio, listaServicio, SIZE_SERVICIO ,listaTrabajo, SIZE_TRABAJO) == 1)
			{
				printf("* EL TOTAL EN PESOS POR LOS SERVICIOS PRESTADOS ES: %.2f \n", TotalPrecio);
			}else
			{
				puts("* NO SE PRESTARON SERVICIOS.");
			}

			system("pause");
			break;

			system("pause");
			break;
		case 6:
			if(eTrabajo_ConMasServiciosPrestados(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO) == 0)
			{
				puts("* NO SE PRESTARON SERVICIOS.");
			}

			system("pause");
			break;
		case 7:

			system("pause");
			break;
		}
		system("cls");


	} while (opcion != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}

