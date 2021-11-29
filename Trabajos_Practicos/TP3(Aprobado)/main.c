#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eb_INPUT.h"
#include "Employee.h"

/****************************************************

    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir

*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	int option;
	int st_load;
	int st_high;
	int st_short;
	st_load = 0;
	st_high = 0;
	st_short = 0;

	    LinkedList* pListaEmpleados = ll_newLinkedList();

	    do{
	    	//MENU PRINT
	    	printf("* CARGADOS: %d   |   AGREGADOS: %d   |   BAJA: %d\n\n", st_load, st_high, st_short);
			printf("1. CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO TEXTO)\n");
			printf("2. CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO BINARIO).\n");
			printf("3. ALTA DE EMPLEADO.\n");
			printf("4. MODIFICAR DATOS DE EMPLEADO.\n");
			printf("5. BAJA DE EMPLEADO.\n");
			printf("6. LISTAR EMPLEADOS.\n");
			printf("7. ORDENAR EMPLEADOS.\n");
			printf("8. GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATA.CSV (MODO TEXTO).\n");
			printf("9. GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATA.CSV (MODO BINARIO).\n");

			printf(" \n");

			printf("10. SALIR.\n");
			getInt(&option, "[*] INGRESE OPCION:\n-> ");

            system("cls");
	        switch(option)
	        {
	            case 1:
	            	if(st_load == 0)//Validacion para que no puedan cargar mas de una vez los datos
	            	{
						if(controller_loadFromText("data.csv", pListaEmpleados) == TRUE)
						{
							printf("\n[*] SE CARGARON LOS DATOS EXITOSAMENTE.\n\n");
							st_load = ll_len(pListaEmpleados);
						}else
						{
							printf("\n[ERROR] EL ARCHIVO NO EXISTE.\n\n");
						}
	            	}else
	            	{
	            		printf("\n[*] LOS DATOS YA SE CARGARON\n");
	            	}
	                break;
	            case 2:
	            	if(st_load == 0)
					{
						if(controller_loadFromBinary("data.dat", pListaEmpleados) == TRUE)
						{
							printf("\n[*] SE CARGARON LOS DATOS CORRECTAMENTE.\n\n");
							st_load = ll_len(pListaEmpleados);
						}else
						{
							printf("\n[ERROR] EL ARCHIVO NO EXISTE.\n\n");
						}
					}else
					{
	            		printf("\n[*] LOS DATOS YA SE CARGARON\n");
					}
	            	break;
	            case 3:
	            	if(controller_addEmployee(pListaEmpleados) == TRUE)
					{
						printf("\n[*] EL EMPLEADO FUE DADO DE ALTA EXITOSAMENTE.\n\n");
	            		st_high++;
					}else
					{
						printf("\n[*] EL ALTA DEL EMPLEADO HA SIDO CANCELADA.\n\n");
					}
	            	break;
	            case 4:
	            	if(controller_editEmployee(pListaEmpleados) == TRUE)
	            	{
						printf("\n[*] SE MODIFICO EL EMPLEADO EXITOSAMENTE.\n\n");
	            	}else
	            	{
						printf("\n[*] LA MODIFICACION DEL EMPLEADO HA SIDO CANCELADA.\n\n");
	            	}
	            	break;
	            case 5:
	            	if(controller_removeEmployee(pListaEmpleados) == TRUE)
					{
						puts("\n[*] EL EMPLEADO FUE DADO DE BAJA EXITOSAMENTE.\n\n");
						st_short++;
					}else
					{
						printf("\n[*] LA BAJA DEL EMPLEADO HA SIDO CANCELADA.\n\n");
					}
	            	break;
	            case 6:
	            	if(controller_ListEmployee(pListaEmpleados) != TRUE)
					{
	            		printf("\n[*] NO HAY EMPLEADOS PARA MOSTRAR.\n\n");
					}
	            	break;
	            case 7:
	            	if(controller_sortEmployee(pListaEmpleados) == FALSE)
					{
	            		printf("\n[*] SE CANCELO EL ORDENAMIENTO DE EMPLEADOS.\n\n");
					}
	            	break;
	            case 8:
					if(controller_saveAsText("data.csv", pListaEmpleados) == TRUE)
					{
						printf("\n[*] SE GUARDARON LOS DATOS EXITOSAMENTE.\n\n");
					}else
					{
						printf("\n[ERROR] NO SE PUDO GUARDAR LOS DATOS.\n\n");
					}
	            	break;
	            case 9:
	            	if(controller_saveAsBinary("data.dat", pListaEmpleados) == TRUE)
					{
						printf("\n[*] SE GUARDARON LOS DATOS EXITOSAMENTE.\n\n");
					}else
					{
						printf("\n[ERROR] NO SE PUDO GUARDAR LOS DATOS.\n\n");
					}
	            	break;
	            case 10:
					printf("\n[*] FIN DEL PROGRAMA...\n\n");
					ll_clear(pListaEmpleados);
					ll_deleteLinkedList(pListaEmpleados);
	            	break;
	            default:
	            	puts("\n[ERROR] OPCION INVALIDA.\n");
	            	break;
	        }
            eb_pulseToContinue();
            system("cls");

	    }while(option != 10);

    return EXIT_SUCCESS;
}

