#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "eb_INPUT.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pArchivo, LinkedList* pArrayListEmployee)
{
	Employee* pAuxEmpleado;

	int rtn;
	char id[ARRAY_SIZE];
	char nombre[ARRAY_SIZE];
	char horasTrabajadas[ARRAY_SIZE];
	char sueldo[ARRAY_SIZE];
	int a;

	rtn = FALSE;

	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{

		//falsa lectura
		a = fscanf(pArchivo, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, horasTrabajadas, sueldo);

		//Mientras no sea el final del archivo
		while(!feof(pArchivo))
		{
			if(a == 4)
			{
				pAuxEmpleado = employee_new();

				fscanf(pArchivo, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, horasTrabajadas, sueldo);

				pAuxEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				ll_add(pArrayListEmployee, pAuxEmpleado);
			}
		}
		rtn = TRUE;
	}


    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pArchivo, LinkedList* pArrayListEmployee)
{
	int rtn;
	rtn = FALSE;

	Employee* pAuxEmpleado;

	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{

		//Mientras no sea el final del archivo y pArrayListEmploye sea distinto a NULL
		while(!feof(pArchivo))
		{
			pAuxEmpleado = employee_new();
			//lee los datos
			fread(pAuxEmpleado, sizeof(Employee), 1, pArchivo);

			//Si es el final del archivo sale del programa(Evitamos que se carguen datos basuras)
			if(feof(pArchivo))
			{
				break;
			}

			ll_add(pArrayListEmployee, pAuxEmpleado);
		}

	rtn = TRUE;
	}

    return rtn;
}

