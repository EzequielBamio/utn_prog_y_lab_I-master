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
		int flag_ArchivosAviones;
    	int cantPasajeros;
		char nombreArchivo[ARRAY_SIZE];
		flag_ArchivosAviones = FALSE;
		flag_ArchivosPilotos = FALSE;
		flag_ArchivosVuelos = FALSE;

		    LinkedList* pListaVuelos = ll_newLinkedList();
		    LinkedList* pListaPilotos = ll_newLinkedList();
		    LinkedList* pListaAviones = ll_newLinkedList();


		    do{
		    	//MENU PRINT
				printf("1. CARGAR ARCHIVO PILOTOS.\n");
				printf("2. CARGAR ARCHIVO AVIONES.\n");
				printf("3. CARGAR ARCHIVO VUELOS.\n");
				printf("4. IMPRIMIR VUELOS.\n");
				printf("5. CANTIDAD DE PASAJEROS.\n");
				printf("6. CANTIDAD DE PASAJEROS A CHINA.\n");
				printf("7. ORDERNAR VUELOS.\n");


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
						eb_getArchivo(nombreArchivo, "[*] INGRESE EL NOMBRE DEL ARCHIVO:\n-> ", ARRAY_SIZE);
						if(controller_loadAvionesFromText(nombreArchivo, pListaAviones) != FALSE)
						{
							puts("\n[*] SE CARGARON LOS DATOS CORRECTAMENTE.");
							flag_ArchivosAviones = TRUE;
						}else
						{
							puts("\n[ERROR] NO SE PUDO CARGAR LOS DATOS.");
						}
		            	break;
		            case 3:
		            	if(flag_ArchivosPilotos == TRUE && flag_ArchivosAviones == TRUE)
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
							puts("\n[ERROR] ANTES DE CARGAR LOS DATOS DE LOS VUELOS DEBES CARGAR LOS DATOS DE LOS PILOTOS Y AVIONES.");
						}
						break;
		            case 4:
		            	if(flag_ArchivosVuelos == TRUE)
						{
							if(controller_ListVuelos(pListaVuelos, pListaPilotos, pListaAviones) != TRUE)
							{
								puts("[*] NO HAY VUELOS PARA MOSTRAR");
							}
						}else
						{
							puts("[ERROR] DEBES CARGAR LOS DATOS DE LOS VUELOS.");
						}
						break;
		            case 5:
		            	if(flag_ArchivosVuelos == TRUE)
						{
							cantPasajeros = ll_count(pListaVuelos, controller_CantidadPasajeros);
							if(cantPasajeros != 0)
							{
								printf("[*] EL TOTAL DE PASAJEROS ES: %d \n", cantPasajeros);
							}
						}else
						{
							puts("[ERROR] DEBES CARGAR LOS DATOS DE LOS VUELOS.");
						}
						break;
		            case 6:
						if(flag_ArchivosVuelos == TRUE)
						{
							cantPasajeros = ll_count(pListaVuelos, controller_CantidadPasajerosChina);
							if(cantPasajeros != 0)
							{
								printf("[*] EL TOTAL DE PASAJEROS CON DESTINO 'CHINA' ES: %d \n", cantPasajeros);
							}
						}else
						{
							puts("[ERROR] DEBES CARGAR LOS DATOS DE LOS VUELOS.");
						}
						break;
		            case 7:
		            	if(flag_ArchivosVuelos == TRUE)
						{
							if(controller_sortVuelos(pListaVuelos, pListaPilotos, pListaAviones) != TRUE)
							{
								puts("[*] NO HAY VUELOS PARA MOSTRAR");
							}else
							{
								controller_ListVuelos(pListaVuelos, pListaPilotos, pListaAviones);
							}
						}else
						{
							puts("[ERROR] DEBES CARGAR LOS DATOS DE LOS VUELOS.");
						}
						break;
		            case 8:
						if(flag_ArchivosVuelos == TRUE)
						{
							if(controller_saveAsText("VuelosGuardados.csv", pListaVuelos) == TRUE)
							{
								printf("\n[*] SE GUARDARON LOS DATOS EXITOSAMENTE.\n\n");
							}else
							{
								printf("\n[ERROR] NO SE PUDO GUARDAR LOS DATOS.\n\n");
							}
						}else
						{
							puts("[ERROR] DEBES CARGAR LOS DATOS DE LOS VUELOS.");
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
