#include <stdio.h>
#include <stdlib.h>
#include "Struct.General.h"


#define SIZE_SERVICIO 4
#define SIZE_TRABAJO 5
#define SIZE_BICICLETA 5

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int trabajoId;
	float TotalPrecio;
	int cantidadBicicletasRojas;
	trabajoId = 0; //Empieza el ID en 1

	//CREO ARRAY DE ESTRUCTURA
	eServicio listaServicio[SIZE_SERVICIO] = {
			{20000, "Liempieza", 250, 1},
			{20001, "Parche", 300, 1},
			{20002, "Centrado", 400, 1},
			{20003, "Cadena", 350, 1}};

	eBicicleta listaBicicleta[SIZE_BICICLETA] = {
				{29, "Scott", 24, "Verde", 1},
				{30, "Specialized", 28, "Azul", 1},
				{31, "Trek", 15, "Rojo", 1},
				{32, "BMC", 15, "Rojo", 1},
				{33, "Orbea", 24, "Amarillo", 1},
		};
	eTrabajo listaTrabajo[SIZE_TRABAJO] = {
			{1, 29, 20000, {14, 2, 2001}, 1},
			{2, 33, 20002, {2, 4, 2001}, 1},
			{3, 33, 20002, {16, 8, 2000}, 1},
			{4, 32, 20002, {16, 8, 2000}, 1},
			{5, 30, 20003, {5, 11, 2004}, 1},
	};

	//eTrabajo_Inicializar(listaTrabajo, SIZE_TRABAJO);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		printf("1. ALTA\n");
		printf("2. BAJA\n");
		printf("3. MODIFICACION\n");
		printf("4. LISTADO DE TRABAJOS\n");
		printf("5. LISTADO DE SERVICIOS\n");
		printf("6. LISTADO ORDENADO POR ANIO\n");
		printf("7. PRECIO TOTAL EN PESOS\n");
		printf("8. LISTADO ORDENADO POR MARCA BICICLETA\n");
		printf("9. EL O LOS SERVICIOS CON MAS TRABAJOS REALIZADOS.\n");
		printf("10. LISTADO DE SERVICIOS CON LOS DATOS DE LAS BICICLETAS QUE SE LO REALIZARON.\n");
		printf("11. LA CANTIDAD DE BICICLETAS DE COLOR ROJO QUE REALIZARON UN SERVICIO ELEGIDO POR EL USUARIO.\n");

		printf(" \n");

		printf("0. Salir\n");
		utn_getNumero(&opcion, "INGRESE OPCION: ", 0, 11);

		//MENU SWITCH
		switch (opcion)
		{
		case 0:
			opcion = 0;
			break;
		case 1:
			//ALTA
			if (eTrabajo_Alta(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA, &trabajoId) == 1)
			{
				puts("* SE HA DADO DE ALTA EXITOSAMENTE");

			}else
			{
				puts("* ERROR. SIN ESPACIO PARA ALMACENAR");
			}

			system("pause");
			break;
		case 2:
			if (eTrabajo_Baja(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA) == 1)
			{
				puts("\n* BAJA EXITOSA");
				eTrabajo_MostrarTodos(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA);
			}else
			{
				puts("\n* BAJA CANCELADA");
			}

			system("pause");
			break;
		case 3:
			if (eTrabajo_Modificar(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA) == 1)
			{
				puts("\n* MODIFICACION EXITOSA\n");
				eTrabajo_MostrarTodos(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA);
			}else
			{
				puts("\n* MODIFICACION CANCELADA");
			}

			system("pause");
			break;
		case 4:
			if(eTrabajo_MostrarTodos(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA) == 0)
			{
				puts("* NO HAY TRABAJOS PARA MOSTRAR.");
			}

			system("pause");
			break;
		case 5:
			if(eServicio_MostrarTodos(listaServicio, SIZE_SERVICIO) == 0)
			{
				puts("* NO HAY SERVICIOS PARA MOSTRAR.");
			}

			system("pause");
			break;
		case 6:
			eTrabajo_Ordenamiento(listaTrabajo, SIZE_TRABAJO, listaBicicleta, SIZE_BICICLETA);
			if(eTrabajo_MostrarTodos(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA) == 0)
			{
				puts("* NO HAY TRABAJOS PARA MOSTRAR.");
			}

			system("pause");
			break;
		case 7:
			TotalPrecio = Total_ServiciosPrestados(listaServicio, SIZE_SERVICIO ,listaTrabajo, SIZE_TRABAJO);
			printf("* El total en pesos por los servicios prestados es: %.2f \n", TotalPrecio);

			system("pause");
			break;
		case 8:
			eTrabajo_OrdenamientoMarcaBicicleta(listaTrabajo, SIZE_TRABAJO, listaBicicleta, SIZE_BICICLETA);
			if(eTrabajo_MostrarTodos(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA) == 0)
			{
				puts("* NO HAY TRABAJOS PARA MOSTRAR.");
			}
			system("pause");
			break;
		case 9:
			if(eTrabajo_ConMasServiciosPrestados(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO) == 0)
			{
				puts("* NO SE PRESTARON SERVICIOS.");
			}
			system("pause");
			break;
		case 10:
			eServicios_MostrarTodosListadoServicioConBicicleta(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA);
			system("pause");
			break;
		case 11:
			cantidadBicicletasRojas = eTrabajos_CantidadBicicletasRojo(listaTrabajo, SIZE_TRABAJO, listaServicio, SIZE_SERVICIO, listaBicicleta, SIZE_BICICLETA);
			if(cantidadBicicletasRojas == -1)
			{
				puts("* No hay bicicletas de color Rojo");
			}else
			{
				printf("* La cantidad de bicicletas Rojas es: %d\n", cantidadBicicletasRojas);
			}
			system("pause");
			break;
		}
		system("cls");


	} while (opcion != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}

