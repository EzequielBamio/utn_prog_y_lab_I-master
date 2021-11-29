#include "LinkedList.h"

int controller_CantidadPasajeros(void* pElement);
int controller_CantidadPasajerosChina(void* pElement);
int count_pasajeros(LinkedList* pArrayListVuelos);

int controller_loadPilotosFromText(char* path , LinkedList* pArrayListVuelos);
int controller_loadVuelosFromText(char* path , LinkedList* pArrayListVuelos);
int controller_ListVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);

int controller_OneListVuelos(void* pVuelo, void* pPiloto);
int controller_VuelosPortugal(void* pElement);
int controller_FilterDuracionVuelo(void* pElement);
LinkedList* controller_ListVuelosDuracionVuelo(LinkedList* this);
LinkedList* controller_ListVuelosPortugal(LinkedList* this);
LinkedList* controller_ListVuelosPilotos(LinkedList* this);
int controller_saveAsText(char* path , LinkedList* pArrayListVuelos);
