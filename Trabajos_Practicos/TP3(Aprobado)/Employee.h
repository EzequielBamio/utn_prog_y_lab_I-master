#include <stdlib.h>

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

//#define ARRAY_SIZE 100
//#define TRUE 1
//#define FALSE -1
//#define SI 1
//#define NO 0
//#define SALIR 2

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_delete(Employee*);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


int employee_IDincrease(int* id);



#endif // employee_H_INCLUDED
