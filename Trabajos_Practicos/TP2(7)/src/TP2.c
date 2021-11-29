/*
 ============================================================================

	Administrar empleados: maximo 1000 empleados
	Datos: Id, nombre, apellido, salario, sector, estado

	Menu: Alta(id automatico), baja, modificar, Informar:
														(Listado de empleados ordenado alfabeticamente por apellido y sector)
														(Total y promedio de los salarios, cuantos empleados superan el salario promedio)
	Tener en cuenta: Menu y validacion en funciones, no se podra ingresar a los casos 2, 3, 4; sin antes haber realizado la carga de algun empleado

	Nombre biblioteca: "ArrayEmployees"





 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define SIZE_EMPLOYEES 1000
#define OFF 0
#define ON 1

int main(void) {
	setbuf(stdout, NULL);

		int opcion;
		int employeesID;
		int flagEmployee;
		flagEmployee = OFF;
		employeesID = 0; //Empieza el ID en 1

		//CREO ARRAY DE ESTRUCTURA
		eEmployee listaEmployees[SIZE_EMPLOYEES];

		initEmployees(listaEmployees, SIZE_EMPLOYEES);

		//BUCLE DE MENU
		do {
			//MENU PRINT
			printf("1. ALTA\n");
			printf("2. BAJA\n");
			printf("3. MODIFICACION\n");
			printf("4. INFORMES\n");

			printf(" \n");

			printf("0. Salir\n");
			utn_getNumero(&opcion, "INGRESE OPCION: ", 0, 4);

			//MENU SWITCH
			switch (opcion)
			{
			case 0:
				opcion = 0;
				break;

			case 1:
				//ALTA
				if(addEmployee(listaEmployees, SIZE_EMPLOYEES, &employeesID) == 1)
				{
					puts("* SE HA DADO DE ALTA EXITOSAMENTE");
					flagEmployee = ON;

				}else
				{
					puts("* ERROR. SIN ESPACIO PARA ALMACENAR");
				}
				system("pause");
				break;
			case 2:
				//BAJA
				if(flagEmployee == ON)
				{
					if(removeEmployee(listaEmployees, SIZE_EMPLOYEES) == 1)
					{
						puts("\n* BAJA EXITOSA");
						if(printEmployees(listaEmployees, SIZE_EMPLOYEES) == 0)
						{
							flagEmployee = OFF;
						}
					}else
					{
						puts("\n* BAJA CANCELADA");
					}
				}else
				{
					puts("* DEBES CARGAR EMPLEADOS PARA ACCEDER AQUI.");
				}
				system("pause");
				break;
			case 3:
				//MODIFICACION
				if(flagEmployee == ON)
				{
					if(ModifyEmployee(listaEmployees, SIZE_EMPLOYEES) == 1)
					{
						puts("\n* MODIFICACION EXITOSA\n");
						if(printEmployees(listaEmployees, SIZE_EMPLOYEES) == 0)
						{
							flagEmployee = OFF;
						}
					}else
					{
						puts("\n* MODIFICACION CANCELADA");
					}
				}else
				{
					puts("* DEBES CARGAR EMPLEADOS PARA ACCEDER AQUI.");
				}
				system("pause");
				break;
			case 4:
				//INFORMES
				if(flagEmployee == ON)
				{
					SubMenu_Informes(listaEmployees, SIZE_EMPLOYEES);
				}else
				{
					puts("* DEBES CARGAR EMPLEADOS PARA ACCEDER AQUI.");
				}
				system("pause");
				break;
			}

		} while (opcion != 0);

		puts("\n... FIN PROGRAMA");

		return 0;
	}

