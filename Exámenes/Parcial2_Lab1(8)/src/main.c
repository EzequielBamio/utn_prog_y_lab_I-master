/*
 ============================================================================
 Name        : Parcial2_Lab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inc/eb_INPUT.h"
#include "inc/Vuelos.h"
#include "inc/LinkedList.h"
#include "inc/Controller.h"

int main(void)
{

	setbuf(stdout, NULL);

		int option;
		int flag_ArchivosPilotos;
		int flag_ArchivosVuelos;
    	int cantPasajeros;
		char nombreArchivo[ARRAY_SIZE];
		flag_ArchivosPilotos = FALSE;
		flag_ArchivosVuelos = FALSE;

		    LinkedList* pListaVuelos = ll_newLinkedList();
		    LinkedList* pAuxListaVuelos = ll_newLinkedList();
		    LinkedList* pListaPilotos = ll_newLinkedList();

		    do{
		    	//MENU PRINT
				printf("1. CARGAR ARCHIVO PILOTOS.\n");
				printf("2. CARGAR ARCHIVO VUELOS.\n");
				printf("3. IMPRIMIR VUELOS.\n");
				printf("4. CANTIDAD DE PASAJEROS.\n");
				printf("5. CANTIDAD DE PASAJEROS A CHINA.\n");
				printf("6. FILTRAR VUELOS LARGOS.\n");
				printf("7. LISTAR VUELOS PORTUGAL.\n");
				printf("8. FILTRAR A ALEX LIFESON Y RICHARD BACH.\n");


				printf(" \n");
				printf("0. SALIR.\n");
				getInt(&option, "[*] INGRESE OPCION:\n-> ");

	            system("cls");
		        switch(option)
		        {
		        case 0:
					printf("\n[*] FIN DEL PROGRAMA...\n\n");
					ll_deleteLinkedList(pListaPilotos);
					ll_deleteLinkedList(pListaVuelos);
					break;
		            case 1:
		            	eb_getArchivo(nombreArchivo, "[*] INGRESE EL NOMBRE DEL ARCHIVO:\n-> ", ARRAY_SIZE);
		            	if(controller_loadPilotosFromText(nombreArchivo, pListaPilotos) != FALSE)
		            	{
		            		puts("\n[*] SE CARGARON LOS DATOS CORRECTAMENTE.");
		            		flag_ArchivosPilotos = TRUE;
		            	}else
		            	{
		            		puts("\n[ERROR] NO SE PUDO CARGAR LOS DATOS.");
		            	}
		                break;
		            case 2:
		            	if(flag_ArchivosPilotos == TRUE)
		            	{
							eb_getArchivo(nombreArchivo, "[*] INGRESE EL NOMBRE DEL ARCHIVO:\n-> ", ARRAY_SIZE);
							if(controller_loadVuelosFromText(nombreArchivo, pListaVuelos) != FALSE)
							{
								puts("\n[*] SE CARGARON LOS DATOS CORRECTAMENTE.");
								flag_ArchivosVuelos = TRUE;
							}else
							{
								puts("\n[ERROR] NO SE PUDO CARGAR LOS DATOS.");
							}
		            	}else
		            	{
							puts("\n[ERROR] ANTES DE CARGAR LOS DATOS DE LOS VUELOS DEBES CARGAR LOS DATOS DE LOS PILOTOS.");
		            	}
		            	break;
		            case 3:
		            	if(flag_ArchivosVuelos == TRUE)
		            	{
							if(controller_ListVuelos(pListaVuelos, pListaPilotos) != TRUE)
							{
								puts("[*] NO HAY VUELOS PARA MOSTRAR");
							}
		            	}else
		            	{
							puts("[ERROR] DEBES CARGAR LOS DATOS DE LOS PILOTOS Y LOS VUELOS.");
		            	}
		            	break;
		            case 4:
		            	if(flag_ArchivosVuelos == TRUE)
						{
							cantPasajeros = ll_count(pListaVuelos, controller_CantidadPasajeros);
							if(cantPasajeros != 0)
							{
								printf("[*] EL TOTAL DE PASAJEROS ES: %d \n", cantPasajeros);
							}
						}else
						{
							puts("[ERROR] DEBES CARGAR LOS DATOS DE LOS PILOTOS Y LOS VUELOS.");
						}
						break;
		            case 5:
		            	if(flag_ArchivosVuelos == TRUE)
		            	{
							cantPasajeros = ll_count(pListaVuelos, controller_CantidadPasajerosChina);
							if(cantPasajeros != 0)
							{
								printf("[*] EL TOTAL DE PASAJEROS CON DESTINO 'CHINA' ES: %d \n", cantPasajeros);
							}
		            	}else
		            	{
							puts("[ERROR] DEBES CARGAR LOS DATOS DE LOS PILOTOS Y LOS VUELOS.");
		            	}
						break;
		            case 6:
		            	pAuxListaVuelos = controller_ListVuelosPortugal(pListaVuelos);
		            	 if(pAuxListaVuelos != NULL)
		            	 {
		            		if(controller_ListVuelos(pAuxListaVuelos, pListaPilotos) != TRUE)
							{
								puts("[*] NO HAY VUELOS PARA MOSTRAR");
							}
		            	 }
		            	break;
		            case 7:
						pAuxListaVuelos = controller_ListVuelosPilotos(pListaVuelos);
						 if(pAuxListaVuelos != NULL)
						 {
							if(controller_ListVuelos(pAuxListaVuelos, pListaPilotos) != TRUE)
							{
								puts("[*] NO HAY VUELOS PARA MOSTRAR");
							}
						 }
						break;
		            case 8:
						pAuxListaVuelos = controller_ListVuelosDuracionVuelo(pListaVuelos);
						 if(pAuxListaVuelos != NULL)
						 {
							if(controller_ListVuelos(pAuxListaVuelos, pListaPilotos) != TRUE)
							{
								puts("[*] NO HAY VUELOS PARA MOSTRAR");
							}
						    controller_saveAsText("VuelosFiltrados.csv", pAuxListaVuelos);
						 }
						break;
		            default:
		            	puts("\n[ERROR] OPCION INVALIDA.\n");
		            	break;
		        }
	            eb_pulseToContinue();
	            system("cls");

		    }while(option != 0);

	return EXIT_SUCCESS;
}
