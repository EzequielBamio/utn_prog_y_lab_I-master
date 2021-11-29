#include "LinkedList.h"

#ifndef PARSER_H_
#define PARSER_H_

int parser_PilotosFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_VuelosFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_AvionesFromText(FILE* pArchivo, LinkedList* pArrayListAviones);
int parser_Fecha(char* fecha, int* fDia, int* fMes, int* fAnio);
#endif /* PARSER_H_ */
