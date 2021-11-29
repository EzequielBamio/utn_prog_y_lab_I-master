#include "ArrayEmployees.h"
#include "utn.Get.h"

void SubMenu_Informes(eEmployee list[], int len)
{
	int opcion;
	float total;
	float promedioSalario;
	int cantidadEmpleadosSuperanSalario;
	//BUCLE DE MENU
	do {
		//MENU PRINT
		printf("1. LISTADO DE LOS EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR\n");
		printf("2. TOTAL Y PROMEDIO DE LOS SALARIOS, Y EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO\n");
		printf(" \n");

		printf("0. Salir\n");
		utn_getNumero(&opcion, "INGRESE OPCION: ", 0, 2);

		//MENU SWITCH
		switch (opcion)
		{
		case 0:
			opcion = 0;
			break;

		case 1:
			utn_getNumero(&opcion, "INGRESE COMO DESEA VER LA LISTA: \n1. MOSTRAR EMPLEADOS EN ORDEN ASCENDENTE \n0. MOSTRAR EMPLEADOS EN ORDEN DESCENDENTE: ", 0, 1);
			if(sortEmployees(list, len, opcion) == 1)
			{
				if(printEmployees(list, len) == 0)
				{
					puts("* NO HAY EMPLEADOS PARA MOSTRAR");
				}
			}

			system("pause");
			break;
		case 2:
			total = totalSalary(list, len);
			if(total != 0)
			{
				promedioSalario = averageSalary(list, len);
				if(promedioSalario != -1)
				{
					cantidadEmpleadosSuperanSalario = EmployeesExceeded(list, len);
					if(cantidadEmpleadosSuperanSalario != 0)
					{
						puts(" TOTAL          |PROMEDIO SALARIOS     |SUPERAN EL SALARIO PROMEDIO");
						printf("\n %-15.2f %-23.2f %d\n\n", total, promedioSalario, cantidadEmpleadosSuperanSalario);
					}
				}
			}
			system("pause");
			break;
		}

		}while(opcion != 0);
}


int initEmployees(eEmployee* list, int len)
{
	int i;
	int rtn;
	rtn = -1;//Si la longitud no es valida o el array es null

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = LIBRE;
		}

		rtn = 1;//Si esta bien
	}

	return rtn;
}


eEmployee getEmployee(void)
{
	eEmployee auxEmployee;

	get_String(auxEmployee.name, MAX_CHARS_CADENAS, "* INGRESE NOMBRE: ", "REINGRESE NOMBRE");
	get_String(auxEmployee.lastName, MAX_CHARS_CADENAS, "* INGRESE APELLIDO: ", "REINGRESE APELLIDO");
	getFloat(&auxEmployee.salary, "* INGRESE SALARIO: ");
	getInt(&auxEmployee.sector, "* INGRESE SECTOR: ");


	return auxEmployee;
}


int addEmployee(eEmployee* list, int len, int* id)
{
	int rtn;
	int i;
	rtn = -1;//Si la longitud no es valida o el array es null
	eEmployee auxTra;

	if(list != NULL && len > 0)
	{
		i = searchfreeSpace(list, len);
		if(i != -1)
		{
			auxTra = getEmployee();
			auxTra.id = utn_ObtenerID(id);
			auxTra.isEmpty = OCUPADO;
			list[i] = auxTra;

			list[i].isEmpty = OCUPADO;
		}


		rtn = 1;//Si esta bien
	}


	return rtn;
}


int searchfreeSpace(eEmployee* list, int len)
{
	int i;
	int rtn;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == LIBRE)
			{
				rtn = i;
			}
		}
	}

	return rtn;
}


int findEmployeeById(eEmployee* list, int len,int id)
{
	int i;
	int rtn;
	rtn = -1;
	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].id == id)
			{
				rtn = i;
			}
		}
	}

	return rtn;
}


void ValidateId(eEmployee* list, int len, char mensaje[], int* pResultado)
{
	int i;
	int mayor;
	int menor;
	int numeroIngresado;

	for(i = 0; i < len; i++)
	{
		if(list[i].id > mayor || i == 0)
		{
			mayor = list[i].id;
		}
		if(list[i].id < menor || i == 0)
		{
			menor = list[i].id;
		}
	}

	utn_getNumero(&numeroIngresado, mensaje, menor, mayor);

	*pResultado = numeroIngresado;

}


int ModifyEmployee(eEmployee* list, int len)
{
	int index;
	int rtn;
	int idModificar;
	int opcionModificar;
	char actualizarNombre[50];
	char actualizarApellido[50];
	float actualizarSalario;
	int actualizarSector;
	rtn = 0;


	if(printEmployees(list, len) == 1)
	{
		ValidateId(list, len, "* INGRESE EL ID QUE DESEA MODIFICAR: \n", &idModificar);
		index = findEmployeeById(list, len, idModificar);

		while (index == -1)
		{
			printf("EL ID '%d' NO EXISTE.\n", idModificar);
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 0)
			{
				break;
			}

			ValidateId(list, len, "* INGRESE EL ID QUE DESEA MODIFICAR: \n", &idModificar);
		}

		if(index != -1)
		{
				utn_getNumero(&opcionModificar, "* QUE DESEA MODIFICAR: \n1. NOMBRE \n2. APELLIDO \n3. SALARIO \n4. SECTOR\n", 1, 4);

				switch(opcionModificar)
				{
				case 1:
					get_String(actualizarNombre, 20, "* INGRESE EL NUEVO NOMBRE: ", "REINGRESE EL NUEVO NOMBRE");
					if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
					{

						strcpy(list[index].name, actualizarNombre);
						rtn = 1;
					}
					break;

				case 2:
					get_String(actualizarApellido, 20, "* INGRESE EL NUEVO APELLIDO: ", "REINGRESE EL NUEVO APELLIDO");
					if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
					{

						strcpy(list[index].lastName, actualizarApellido);
						rtn = 1;
					}
					break;
				case 3:
					getFloat(&actualizarSalario, "* INGRESE EL NUEVO SALARIO: ");
					if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
					{

						list[index].salary = actualizarSalario;
						rtn = 1;
					}
					break;
				case 4:
					ValidateId(list, len, "* INGRESE EL NUEVO SECTOR: ", &actualizarSector);
					if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
					{

						list[index].sector = actualizarSector;
						rtn = 1;
					}
					break;
				}
		}
	}
	return rtn;
}


int removeEmployee(eEmployee* list, int len)
{
	int rtn;
	int idEmployee;
	int i;
	rtn = -1;

	if(printEmployees(list, len) == 1)
	{
		getInt(&idEmployee, "INGRESE ID A DAR DE BAJA: ");
		i = findEmployeeById(list, len, idEmployee);

		while(i == -1)
		{
			printf("EL ID '%d' NO EXISTE.\n", idEmployee);
			if(Confirmar_Respuesta("* Desea probar ingresando otro ID? 1. Si 0. No: ") == 0)
			{
				break;
			}

			getInt(&idEmployee, "INGRESE ID A DAR DE BAJA: ");

		}
		if(i != -1)
		{
			if(Confirmar_Respuesta("* Confirmar cambios: 1. Si 0. No: ") == 1)
			{
				list[i].isEmpty = BAJA;
				rtn = 1;
			}
		}
	}

	return rtn;
}


int sortEmployeesUp(eEmployee* list, int len)
{
	int i;
	int j;
	int rtn;
	eEmployee aux;
	rtn = 0;

	for (i = 0; i < len-1; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
			{
				if((strcmp(list[i].lastName, list[j].lastName)) > 0)
				{
					aux = list[i];
				   list[i] = list[j];
				   list[j] = aux;
				}else
				{
					if((strcmp(list[i].lastName, list[j].lastName)) == 0)
					{
						if (list[i].sector > list[j].sector)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
				rtn = 1;
			}
		}
	}

	return rtn;
}


int sortEmployeesDown(eEmployee* list, int len)
{
	int i;
	int j;
	int rtn;
	eEmployee aux;
	rtn = 0;

	for (i = 0; i < len-1; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
			{
				if((strcmp(list[i].lastName, list[j].lastName)) < 0)
				{
					aux = list[i];
				   list[i] = list[j];
				   list[j] = aux;
				}else
				{
					if((strcmp(list[i].lastName, list[j].lastName)) == 0)
					{
						if (list[i].sector < list[j].sector)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
				rtn = 1;
			}
		}
	}

	return rtn;
}


int sortEmployees(eEmployee* list, int len, int order)
{
	int rtn;
	rtn = 0;

	if (len > 0)
	{
		switch(order)
		{
		case 0:
			sortEmployeesDown(list, len);
			break;
		case 1:
			sortEmployeesUp(list, len);
			break;
		}
		rtn = 1;
	}
	return rtn;
}


int printEmployees(eEmployee* list, int length)
{
	int i;
	int rtn;
	int cantidad;

	rtn = 0;
	cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO de Trabajo");
	printf("|ID   |NAME        |LASTNAME        |SALARY  	|SECTOR           \n\n");

	if (length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (list[i].isEmpty == OCUPADO)
			{
				printf("%-6d %-12s %-16s %-13.2f %d\n\n", list[i].id,
													 	 list[i].name,
														 list[i].lastName,
														 list[i].salary,
														 list[i].sector);
				cantidad++;
			}
		}
	}

	if (cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}


float totalSalary(eEmployee list[], int len)
{
    int i;
    float totalSalario;
    totalSalario = 0;

    if(list != NULL && len > 0)
    {
        for(i=0; i < len; i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
            	totalSalario += list[i].salary;
            }
        }
    }

    return totalSalario;
}


float averageSalary(eEmployee list[], int len)
{
    int i;
    float promedioSalario;
    int contadorSalario;
    contadorSalario = 0;

    if(list != NULL && len > 0)
    {
        for(i=0; i < len; i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
            	contadorSalario++;
            }
        }
    }
    if(contadorSalario != 0)
    {
    	promedioSalario = totalSalary(list, len) / contadorSalario;
    }else
    {
    	promedioSalario = -1;
    }

    return promedioSalario;
}


int EmployeesExceeded(eEmployee list[], int len)
{
    int i;
    float promedioSalario;
    int contadorEmpleados;
	contadorEmpleados = 0;
    promedioSalario = averageSalary(list, len);

    if(list != NULL && len > 0)
    {
        for(i=0; i < len; i++)
        {
            if(list[i].isEmpty == OCUPADO && list[i].salary >= promedioSalario)
            {
            	contadorEmpleados++;
            }
        }
    }

    return contadorEmpleados;
}
