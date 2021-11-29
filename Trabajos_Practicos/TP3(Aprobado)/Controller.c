#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "eb_INPUT.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int rtn;
	rtn = FALSE;
	if(pArrayListEmployee != NULL)
	{
		//abre el archivo en modo lectura
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			rtn = parser_EmployeeFromText(pArchivo, pArrayListEmployee);
			fclose(pArchivo);
		}
	}
    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int rtn;
	rtn = FALSE;
	if(path != NULL)
	{
		//abre el archivo en modo lectura binario
		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL)
		{
			rtn = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
		}
		fclose(pArchivo);
	}

    return rtn;
}
/**
 * @fn int controller_validateID(LinkedList*, int)
 * @brief
 *
 * @param pArrayListEmployee
 * @param id
 * @return Si existe devuelve sale del for y retorna TRUE(1), sino encuentra una id igual retorna FALSE(0)
 */

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pAuxEmpleado;
	int rtn;
	int id;
	int horasTrabajadas;
	int sueldo;
	char nombre[ARRAY_SIZE];

	rtn = FALSE;
	pAuxEmpleado = employee_new();

	if(pAuxEmpleado != NULL)
	{
		if(eb_getNombre(nombre, "[ALTA] INGRESE NOMBRE:\n-> ", ARRAY_SIZE) == TRUE)
		{
			if(eb_getIntPositive(&horasTrabajadas, "[ALTA] INGRESE LA CANTIDAD DE HORAS TRABAJADAS:\n-> ") == TRUE)
			{
				if(eb_getIntPositive(&sueldo, "[ALTA] INGRESE EL SUELDO:\n-> ") == TRUE)
				{
					id = employee_IDlatest(pArrayListEmployee);
					if(id != FALSE)
					{
						id = employee_IDincrease(&id);
						employee_setId(pAuxEmpleado, id);
						employee_setNombre(pAuxEmpleado, nombre);
						employee_setHorasTrabajadas(pAuxEmpleado, horasTrabajadas);
						employee_setSueldo(pAuxEmpleado, sueldo);

						if(eb_getContinuar("[ALTA] SEGURO QUE QUIERE DAR DE ALTA A ESTE EMPLEADO? SI (1) - NO (0):\n-> ") == TRUE)
						{
							ll_add(pArrayListEmployee, pAuxEmpleado);

							printf("\n[ALTA] EMPLEADO DADO DE ALTA!\n");
							controller_showList(pAuxEmpleado);
							rtn = TRUE;
						}
					}
				}
			}
		}
	}

    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pAuxEmpleado;
	int rtn;
	int opcion;
	int id_Modificar;
	int id_Index;
	int flagEmpleado_Buscar;
	int edit_HorasTrabajadas;
	int edit_Sueldo;
	char edit_Nombre[ARRAY_SIZE];

	flagEmpleado_Buscar = FALSE;
	rtn = FALSE;
	opcion = 1;

	if(ll_len(pArrayListEmployee) == 0)
	{
		printf("\n\n[*] NO HAY EMPLEADOS PARA MODIFICAR\n");
	}else
	{
		flagEmpleado_Buscar = controller_searchEmployee(
				pArrayListEmployee,
				&id_Modificar,
				&id_Index,
				"\n\n[*] (0) VER EL LISTADO DE EMPLEADOS - ACA PODRAS ENCONTRAR LA ID DE LOS EMPLEADOS \n[*] (1) MODIFICAR EMPLEADO\n\n[*] (2) SALIR\n-> ",
				"[MODIFICAR] INGRESE LA ID A MODIFICAR:\n-> ",
				"[ERROR] LA ID INGRESADA NO EXISTE. QUIERE VOLVER A INTENTARLO? SI (1) - NO (0):\n-> ");
	}


	while(flagEmpleado_Buscar == TRUE && rtn == FALSE && opcion != 0)
	{
		pAuxEmpleado = employee_new();
		if(pAuxEmpleado != NULL)
		{
			//asigno el empleado del id ingresado a pAuxEmpleado
			pAuxEmpleado = ll_get(pArrayListEmployee, id_Index);

			printf("\n[MODIFICAR] EMPLEADO ENCONTRADO!\n");
			//Muestro el empleado
			controller_showList(pAuxEmpleado);

			eb_getNumero(&opcion, "[*] Que desea modificar?\n[*] 1. NOMBRE \n[*] 2. HORAS TRABAJADAS \n[*] 3. SUELDO\n\n[*] 0. SALIR \n-> ", 0, 4);
			switch (opcion)
			{
				case 0:
					//SALIR
					break;
				case 1:
					//NOMBRE
					if(controller_editNombre(pArrayListEmployee, edit_Nombre) == TRUE)
					{
						employee_setNombre(pAuxEmpleado, edit_Nombre);
						ll_set(pArrayListEmployee, id_Index, pAuxEmpleado);
						rtn = TRUE;
					}else
					{
						opcion = 0;
					}
					break;
				case 2:
					//HORAS TRABAJADAS
					edit_HorasTrabajadas = controller_editHorasTrabajadas(pArrayListEmployee);
					if(edit_HorasTrabajadas != FALSE)
					{
						employee_setHorasTrabajadas(pAuxEmpleado, edit_HorasTrabajadas);
						ll_set(pArrayListEmployee, id_Index, pAuxEmpleado);
						rtn = TRUE;
					}else
					{
						opcion = 0;
					}
					break;
				case 3:
					//SUELDO
					edit_Sueldo = controller_editSueldo(pArrayListEmployee);
					if(edit_Sueldo != FALSE)
					{
						employee_setSueldo(pAuxEmpleado, edit_Sueldo);
						ll_set(pArrayListEmployee, id_Index, pAuxEmpleado);
						rtn = TRUE;
					}else
					{
						opcion = 0;
					}
					break;
			}
		}
	}

	if(rtn == TRUE)
	{
		controller_showList(pAuxEmpleado);
	}

    return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pAuxEmpleado;
	int rtn;
	int id_Remove;
	int id_Index;
	int flagEmpleado_Buscar;

	flagEmpleado_Buscar = FALSE;
	rtn = FALSE;

	if(ll_len(pArrayListEmployee) == 0)
	{
		printf("\n\n[*] NO HAY EMPLEADOS PARA DAR DE BAJA\n");
	}else
	{

		flagEmpleado_Buscar = controller_searchEmployee(
				pArrayListEmployee,
				&id_Remove,
				&id_Index,
				"\n\n[*] (0) Listado de Empleados - ACA PODRAS ENCONTRAR LA ID DE LOS EMPLEADOS \n[*] (1) INGRESAR ID PARA DAR DE BAJA\n\n[*] 2. SALIR \n->  ",
				"[BAJA] INGRESE LA ID A DAR DE BAJA:\n-> ",
				"[ERROR] LA ID INGRESADA NO EXISTE. QUIERE VOLVER A INTENTARLO? SI (1) - NO (0):\n-> ");

	}
	while(flagEmpleado_Buscar == TRUE && rtn == FALSE)
	{
		pAuxEmpleado = employee_new();
		if(pAuxEmpleado != NULL)
		{
			//asigno el empleado del id ingresado a pAuxEmpleado
			pAuxEmpleado = ll_get(pArrayListEmployee, id_Index);

			printf("\n[BAJA] EMPLEADO ENCONTRADO!\n");
			//Muestro el empleado
			controller_showList(pAuxEmpleado);

			if(eb_getContinuar("[BAJA] SEGURO QUE QUIERE DAR DE BAJA A ESTE EMPLEADO? SI (1) - NO (0):\n-> "))
			{
				ll_remove(pArrayListEmployee, id_Index);
				rtn = TRUE;
			}else
			{
				//sale de la funcion y devuelve RTN = FALSE
				flagEmpleado_Buscar = FALSE;
			}
		}
	}

    return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pAuxEmpleado;
	int tEmpleado;
	int rtn;
	int i;
	rtn = FALSE;

	tEmpleado = ll_len(pArrayListEmployee);
	if(tEmpleado > 0)
	{
		puts("\n[LISTA DE EMPLEADOS]\n");
		printf("_____________________________________________________\n");
		printf("|       |       |            |                      |\n");
		printf("| ID    | HORAS | SUELDO     | NOMBRE               |\n");
		printf("|___________________________________________________|\n");
		printf("|       |       |            |                      |\n");

		for(i = 0; i < tEmpleado; i++)
		{
			pAuxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			if(controller_OneListEmployee(pAuxEmpleado) == TRUE)
			{
				rtn = TRUE;
			}
		}
		printf("|___________________________________________________|\n");
	}

    return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn;
	int opcion;
	int criterio;
	rtn = FALSE;

	if(ll_len(pArrayListEmployee) > 0)
	{
		eb_getNumero(&opcion, "[ORDENAR] INGRESE COMO DESEA FILTRAR LA LISTA: \n[*] (1) ID \n[*] (2) NOMBRE \n[*] (3) HORAS TRABAJADAS \n[*] (4) SUELDO\n\n[*] 0. SALIR \n->  ", 0, 4);
		if(opcion != 2)
		{
			eb_getNumero(&criterio, "[*] INGRESE EL ORDEN:\n[*] (0) MAYOR A MENOR \n[*] (1) MENOR A MAYOR \n-> ", 0, 1);
		}else
		{
			eb_getNumero(&criterio, "[*] INGRESE EL ORDEN:\n[*] (0) A-Z \n[*] (1) Z-A \n-> ", 0, 1);
		}
		switch(opcion)
		{
		case 0:

			//SALIR
			break;
		case 1:
			printf("[*] UN MOMENTO, SE ESTA ORDENANDO...");
			ll_sort(pArrayListEmployee, controller_sortID, criterio);
			break;
		case 2:
			printf("[*] UN MOMENTO, SE ESTA ORDENANDO...");
			ll_sort(pArrayListEmployee, controller_sortNombre, criterio);
			break;
		case 3:
			printf("[*] UN MOMENTO, SE ESTA ORDENANDO...");
			ll_sort(pArrayListEmployee, controller_sortHorasTrabajadas, criterio);
			break;
		case 4:
			printf("[*] UN MOMENTO, SE ESTA ORDENANDO...");
			ll_sort(pArrayListEmployee, controller_sortSueldo, criterio);
			break;
		}

		if(opcion != 0)
		{
			//Muestro los empleados ordenados
			controller_ListEmployee(pArrayListEmployee);
			rtn = TRUE;
		}
	}

	return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	Employee* pAuxEmployee;
	int rtn;
	int i;
	int id;
	int horasTrabajadas;
	int sueldo;
	int tEmpleados;
	char nombre[ARRAY_SIZE];


	rtn = FALSE;
	pArchivo = fopen(path, "w");

	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		tEmpleados = ll_len(pArrayListEmployee);

		if(tEmpleados == 0)
		{
			printf("\n[ERROR] NO SE PUEDE GUARDAR SI NO HAY AL MENOS 1 EMPLEADO CARGADO.\n");
		}else
		{
			fprintf(pArchivo, "ID, Nombre, Horas Trabajadas, Sueldo\n");

			for(i = 0; i < tEmpleados; i++)
			{
				pAuxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

				employee_getId(pAuxEmployee, &id);
				employee_getHorasTrabajadas(pAuxEmployee, &horasTrabajadas);
				employee_getSueldo(pAuxEmployee, &sueldo);
				employee_getNombre(pAuxEmployee, nombre);

				fprintf(pArchivo, "%d, %s, %d, %d\n", id, nombre, horasTrabajadas, sueldo);

			}
			rtn = TRUE;
		}
	}

	fclose(pArchivo);

	return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	Employee* pAuxEmployee;
	int rtn;
	int i;
	int tEmpleados;

	rtn = FALSE;
	tEmpleados = ll_len(pArrayListEmployee);
	pArchivo = fopen(path, "wb");

	if(pArchivo != NULL && tEmpleados > 0)
	{
		for(i = 0; i < tEmpleados; i++)
		{
			pAuxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pAuxEmployee, sizeof(Employee), 1, pArchivo);
		}
		rtn = TRUE;
	}

	fclose(pArchivo);

    return rtn;
}

//---------------------------------------\ * /----------------------------------------//

int controller_searchEmployee(LinkedList* pArrayListEmployee, int* id_Get, int* id_Index, char* msgMenu, char* msgGet, char* msgErrorID)
{
	int flagEmpleado_Buscar;
	int rtn;
	flagEmpleado_Buscar = FALSE;

	do
	{
		rtn = eb_subMenu(msgMenu);
		if(rtn == SI)
		{
			if(eb_getIntPositive(id_Get, msgGet) == TRUE)
			{
				*id_Index = controller_validateID(pArrayListEmployee, *id_Get);
				if(*id_Index != FALSE)
				{
					flagEmpleado_Buscar = TRUE;
					break;
				}else
				{
					if(eb_getContinuar(msgErrorID) == TRUE)
					{
						flagEmpleado_Buscar = FALSE;
					}else
					{
						flagEmpleado_Buscar = NO;
					}
				}
			}else
			{
				break;
			}
		}else
		{
			if(rtn == SALIR)
			{
				flagEmpleado_Buscar = SALIR;
			}else
			{
				controller_ListEmployee(pArrayListEmployee);
				eb_pulseToContinue();
			}

		}
	} while(flagEmpleado_Buscar == FALSE);

	return flagEmpleado_Buscar;
}

int employee_IDlatest(LinkedList* pArrayListEmployee)
{
	Employee* pAuxEmpleado;
	int i;
	int id;
	int id_Mayor;
	int tEmpleados;

	id_Mayor = 0;
	pAuxEmpleado = employee_new();
	tEmpleados = ll_len(pArrayListEmployee);

	for(i = 0; i < tEmpleados; i++)
	{
		pAuxEmpleado = ll_get(pArrayListEmployee, i);
		employee_getId(pAuxEmpleado, &id);
		if(id_Mayor < id)
		{
			id_Mayor = id;
		}
	}

	return id_Mayor;

}

int controller_validateID(LinkedList* pArrayListEmployee, int id)
{
	Employee* pAuxEmpleado;
	int rtn;
	int i;

	pAuxEmpleado = employee_new();
	rtn = FALSE;

	for(i = 0; i < ll_len(pArrayListEmployee); i++)
	{
		pAuxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
		if(pAuxEmpleado->id == id)
		{
			rtn = i;
			break;
		}
	}

	return rtn;
}


//Edit INICIO
int controller_editNombre(LinkedList* pArrayListEmployee, char* pEdit_Nombre)
{
	char auxNombre[ARRAY_SIZE];
	int flagEstado_Nombre;

	flagEstado_Nombre = FALSE;

	if(eb_getNombre(auxNombre, "[*] INGRESE EL NUEVO NOMBRE:\n-> ", ARRAY_SIZE) == TRUE)
	{
		if(eb_getContinuar("[MODIFICAR] ESTAS SEGURO QUE QUIERE MODIFICAR ESTE NOMBRE? SI (1) - NO (0):\n-> ") == TRUE)
		{
			strncpy(pEdit_Nombre, auxNombre, ARRAY_SIZE);
			flagEstado_Nombre = TRUE;
		}else
		{
			flagEstado_Nombre = FALSE;
		}
	}

	return flagEstado_Nombre;
}

int controller_editHorasTrabajadas(LinkedList* pArrayListEmployee)
{
	int flagEstado_HorasTrabajadas;
	int auxHorasTrabajadas;

	flagEstado_HorasTrabajadas = FALSE;

	if(eb_getIntPositive(&auxHorasTrabajadas, "[*] INGRESE LA NUEVA CANTIDAD DE HORAS TRABAJADAS:\n-> ") == TRUE)
	{
		if(eb_getContinuar("[MODIFICAR] ESTAS SEGURO QUE QUIERE MODIFICAR LA CANTIDAD DE HORAS TRABAJADAS? SI (1) - NO (0):\n-> ") == TRUE)
		{
			flagEstado_HorasTrabajadas = auxHorasTrabajadas;
		}else
		{
			flagEstado_HorasTrabajadas = FALSE;
		}
	}

	return flagEstado_HorasTrabajadas;
}

int controller_editSueldo(LinkedList* pArrayListEmployee)
{
	int flagEstado_Sueldo;
	int auxSueldo;

	flagEstado_Sueldo = FALSE;

	if(eb_getIntPositive(&auxSueldo, "[*] INGRESE EL NUEVO SUELDO:\n-> ") == TRUE)
	{
		if(eb_getContinuar("[MODIFICAR] ESTAS SEGURO QUE QUIERE MODIFICAR EL SUELDO? SI (1) - NO (0):\n-> ") == TRUE)
		{
			flagEstado_Sueldo = auxSueldo;
		}else
		{
			flagEstado_Sueldo = FALSE;
		}
	}

	return flagEstado_Sueldo;
}

//Edit FIN


//List INICIO
int controller_OneListEmployee(void* pEmployee)
{
	Employee* pAuxEmpleado;
	pAuxEmpleado = (Employee*) pEmployee;
	int rtn;
	int list_id;
	int list_HorasTrabajadas;
	int list_Sueldo;
	char list_Nombre[ARRAY_SIZE];

	rtn = FALSE;

	//asigno los datos del empleado a las variables, si esta todo bien, muestra el empleado
	if(employee_getId(pAuxEmpleado, &list_id) == TRUE)
	{
		if(employee_getHorasTrabajadas(pAuxEmpleado, &list_HorasTrabajadas) == TRUE)
		{
			if(employee_getSueldo(pAuxEmpleado, &list_Sueldo) == TRUE)
			{
				if(employee_getNombre(pAuxEmpleado, list_Nombre) == TRUE)
				{
					printf("| %-5d | %-5d | %-10d | %-20s |\n", list_id, list_HorasTrabajadas, list_Sueldo, list_Nombre);
					rtn = TRUE;
				}
			}
		}
	}

	return rtn;
}
void controller_showList(void* pEmployee)
{
	Employee* pAuxEmpleado;
	pAuxEmpleado = (Employee*) pEmployee;
	printf("_____________________________________________________\n");
	printf("| ID    | HORAS | SUELDO     | NOMBRE               |\n");
	controller_OneListEmployee(pAuxEmpleado);
	printf("|___________________________________________________|\n");
}
//List FIN

//Sort INICIO
int controller_sortID(void* pEmployee1 ,void* pEmployee2)
{
	int rtn;
	int id_Employee1;
	int id_Employee2;
	Employee* pID_Employee1;
	Employee* pID_Employee2;

	pID_Employee1 = (Employee*) pEmployee1;
	pID_Employee2 = (Employee*) pEmployee2;

	employee_getId(pID_Employee1, &id_Employee1);
	employee_getId(pID_Employee2, &id_Employee2);

	if(id_Employee1 > id_Employee2)
	{
		rtn = TRUE;
	}else
	{
		if(id_Employee1 < id_Employee2)
		{
			rtn = FALSE;
		}else
		{
			rtn = NO;
		}
	}

	return rtn;
}

int controller_sortNombre(void* pEmployee1 ,void* pEmployee2)
{
	int rtn;
	char nombre_Employee1[ARRAY_SIZE];
	char nombre_Employee2[ARRAY_SIZE];
	Employee* pNombre_Employee1;
	Employee* pNombre_Employee2;

	pNombre_Employee1 = (Employee*) pEmployee1;
	pNombre_Employee2 = (Employee*) pEmployee2;

	employee_getNombre(pNombre_Employee1, nombre_Employee1);
	employee_getNombre(pNombre_Employee2, nombre_Employee2);

	if(strcmp(nombre_Employee1, nombre_Employee2) < 0)
	{
		rtn = TRUE;
	}else
	{
		if(strcmp(nombre_Employee1, nombre_Employee2) > 0)
		{
			rtn = FALSE;
		}else
		{
			rtn = NO;
		}
	}

	return rtn;
}

int controller_sortHorasTrabajadas(void* pEmployee1 ,void* pEmployee2)
{
	int rtn;
	int horasTrabajadas_Employee1;
	int horasTrabajadas_Employee2;
	Employee* pHorasTrabajadas_Employee1;
	Employee* pHorasTrabajadas_Employee2;

	pHorasTrabajadas_Employee1 = (Employee*) pEmployee1;
	pHorasTrabajadas_Employee2 = (Employee*) pEmployee2;

	employee_getHorasTrabajadas(pHorasTrabajadas_Employee1, &horasTrabajadas_Employee1);
	employee_getHorasTrabajadas(pHorasTrabajadas_Employee2, &horasTrabajadas_Employee2);

	if(horasTrabajadas_Employee1 > horasTrabajadas_Employee2)
	{
		rtn = TRUE;
	}else
	{
		if(horasTrabajadas_Employee1 < horasTrabajadas_Employee2)
		{
			rtn = FALSE;
		}else
		{
			rtn = NO;
		}
	}

	return rtn;
}

int controller_sortSueldo(void* pEmployee1 ,void* pEmployee2)
{
	int rtn;
	int sueldo_Employee1;
	int sueldo_Employee2;
	Employee* pSueldo_Employee1;
	Employee* pSueldo_Employee2;

	pSueldo_Employee1 = (Employee*) pEmployee1;
	pSueldo_Employee2 = (Employee*) pEmployee2;

	employee_getSueldo(pSueldo_Employee1, &sueldo_Employee1);
	employee_getSueldo(pSueldo_Employee2, &sueldo_Employee2);

	if(sueldo_Employee1 > sueldo_Employee2)
	{
		rtn = TRUE;
	}else
	{
		if(sueldo_Employee1 < sueldo_Employee2)
		{
			rtn = FALSE;
		}else
		{
			rtn = NO;
		}
	}

	return rtn;
}
//Sort FIN
