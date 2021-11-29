#include <string.h>
#include "Employee.h"
#include "eb_INPUT.h"

Employee* employee_new()
{
	Employee* pEmpleado;

	pEmpleado = (Employee*) malloc(sizeof(Employee));

	return pEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	 Employee* pAuxEmpleado;
	 pAuxEmpleado = employee_new();

	 if(pAuxEmpleado != NULL)
	 {

		 employee_setId(pAuxEmpleado, atoi(idStr));
		 employee_setNombre(pAuxEmpleado, nombreStr);
		 employee_setHorasTrabajadas(pAuxEmpleado, atoi(horasTrabajadasStr));
		 employee_setSueldo(pAuxEmpleado, atoi(sueldoStr));
	 }

	 return pAuxEmpleado;
}

int employee_delete(Employee* this)
{
	int rtn;
	rtn = FALSE;
	if(this != NULL)
	{
		free(this);
		rtn = TRUE;
	}

	return rtn;
}

//
int employee_setId(Employee* this,int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = TRUE;
	}

	return rtn;
}
int employee_getId(Employee* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		*id = this->id;
		rtn = TRUE;
	}

	return rtn;
}
//
int employee_setNombre(Employee* this,char* nombre)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(this->nombre, nombre);
		rtn = TRUE;
	}

	return rtn;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		rtn = TRUE;
	}

	return rtn;
}
//
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		rtn = TRUE;
	}

	return rtn;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && horasTrabajadas > 0)
	{
		*horasTrabajadas = this->horasTrabajadas;
		rtn = TRUE;
	}

	return rtn;
}
//
int employee_setSueldo(Employee* this,int sueldo)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		rtn = TRUE;
	}

	return rtn;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && sueldo > 0)
	{
		*sueldo = this->sueldo;
		rtn = TRUE;
	}

	return rtn;
}

//---------------------------------------\ * /----------------------------------------//

int employee_IDincrease(int* id)
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return *id += 1;
}

