#include "LinkedList.h"

int controller_CantidadPasajeros(void* pElement);
int controller_CantidadPasajerosChina(void* pElement);
int count_pasajeros(LinkedList* pArrayListVuelos);

int controller_loadPilotosFromText(char* path , LinkedList* pArrayListVuelos);
int controller_loadVuelosFromText(char* path , LinkedList* pArrayListVuelos);
int controller_loadAvionesFromText(char* path , LinkedList* pArrayListAviones);
int controller_ListVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos, LinkedList* pArrayListAviones);
int controller_sortVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos, LinkedList* pArrayListAviones);
int controller_saveAsText(char* path , LinkedList* pArrayListVuelos);
int controller_OneListVuelos(void* pVuelo, void* pPiloto, void* pAviones);
int controller_sortID(void* pElement1 ,void* pElement2);
int controller_sortDestino(void* pElement1 ,void* pElement2);
int controller_sortFecha(void* pElement1 ,void* pElement2);
