#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


int controller_validateID(LinkedList* pArrayListEmployee, int id);
int controller_editNombre(LinkedList* pArrayListEmployee, char* pEdit_Nombre);
int controller_editHorasTrabajadas(LinkedList* pArrayListEmployee);
int controller_editSueldo(LinkedList* pArrayListEmployee);
int controller_sortID(void* pEmployee1 ,void* pEmployee2);
int controller_sortNombre(void* pEmployee1 ,void* pEmployee2);
int controller_sortHorasTrabajadas(void* pEmployee1 ,void* pEmployee2);
int controller_sortSueldo(void* pEmployee1 ,void* pEmployee2);
int controller_OneListEmployee(void* pEmployee);
int controller_searchEmployee(LinkedList* pArrayListEmployee, int* id_Get, int* id_Index, char* msgMenu, char* msgGet, char* msgErrorID);
int employee_IDlatest(LinkedList* pArrayListEmployee);
void controller_showList(void* pEmployee);
