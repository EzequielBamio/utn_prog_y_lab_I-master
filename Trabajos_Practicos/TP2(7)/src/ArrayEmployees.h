#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.Get.h"

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
//*** DEFINES
#define MAX_CHARS_CADENAS 51
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
//***

//*** ESTRUCTURA
typedef struct
{
 int id;
 char name[MAX_CHARS_CADENAS];
 char lastName[MAX_CHARS_CADENAS];
 float salary;
 int sector;
 int isEmpty;

} eEmployee;

//***
/**
 * @fn void SubMenu_Informes(eEmployee[], int)
 * @brief submenu listings
 *
 * @param list
 * @param len
 */
void SubMenu_Informes(eEmployee list[], int len);
/**
 * @fn float totalSalary(eEmployee[], int)
 * @brief calculate total salary
 *
 * @param list
 * @param len
 * @return float returns the total salary
 */
float totalSalary(eEmployee list[], int len);
/**
 * @fn float averageSalary(eEmployee[], int)
 * @brief calculate the average salary of employees
 *
 * @param list
 * @param len
 * @return float returns the average salary
 */
float averageSalary(eEmployee list[], int len);
/**
 * @fn int EmployeesExceeded(eEmployee[], int)
 * @brief counts employees who exceed average salary
 *
 * @param list
 * @param len
 * @return int returns the number of employees who exceeded the average salary
 */
int EmployeesExceeded(eEmployee list[], int len);
/**
 * @fn int sortEmployeesUp(eEmployee*, int)
 * @brief sort the list in ascending order
 *
 * @param list
 * @param len
 * @return int Return (-1) if Error - (0) if Ok
 */
int sortEmployeesUp(eEmployee* list, int len);
/**
 * @fn int sortEmployeesDown(eEmployee*, int)
 * @brief sort the list in descending order
 *
 * @param list
 * @param len
 * @return int Return (-1) if Error - (0) if Ok
 */
int sortEmployeesDown(eEmployee* list, int len);
/**
 * @fn int ModifyEmployee(eEmployee*, int)
 * @brief Modify all the fields that the user chooses from the structure
 *
 * @param list eEmployee
 * @param len int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 * */
int ModifyEmployee(eEmployee* list, int len);
/**
 * @fn void ValidateId(eEmployee*, int, char[], int*)
 * @brief It goes through the list finding the largest and smallest id and asks for an id an integer with range
 *
 * @param list eEmployee
 * @param len int
 * @param mensaje char[]
 * @param pResultado int*
 */
void ValidateId(eEmployee* list, int len, char mensaje[], int* pResultado);
/**
 * @fn int searchfreeSpace(eEmployee*, int)
 * @brief search if there is space in the list
 *
 * @param list eEmployee*
 * @param len int
 * @return int return (-1) if you can't find a free space, if there is free space it returns the position
 */
int searchfreeSpace(eEmployee* list, int len);
/**
 * @fn int findEmployeeById(eEmployee*, int, int)
 * @brief Search employee by id
 *
 * @param list eEmployee*
 * @param len int
 * @param id int
 * @return int return (-1) if I can't find an employee with that id or if it finds it returns the position
 */
int findEmployeeById(eEmployee* list, int len,int id);
/**
 * @fn eEmployee getEmployee()
 * @brief request the necessary data for the Employees
 *
 * @return eEmployee return a list of data type eEmployee
 */
eEmployee getEmployee();

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee* list, int len);

/** \brief add in an existing list of employees by loading the data with the getEmployee function
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(eEmployee* list, int len, int* id);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee* list, int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee* list, int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee* list, int len, int order);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee* list, int length);

#endif /* ARRAYEMPLOYEES_H_ */
