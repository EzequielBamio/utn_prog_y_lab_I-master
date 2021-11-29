/*
 ============================================================================
 EJERCICIOS DEL SEGUNDO PARCIAL PROGRAMACIÓN.

Diseñar la estructura (según el tema otorgado). Realizar un constructor por defecto y uno parametrizado para dicha estructura.
 Respetar las reglas de estilo vistas en la cátedra. Crear un dato de este tipo en el main y mostrarlo a través de una función

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "hParcial.h"
#include "eb_INPUT.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
    eImpresora* pListaImpresora;// = eImpresora_newParametros("5", "HP", "50");

//    printf("%d - %s - %d\n", pListaImpresora->id, pListaImpresora->marca, pListaImpresora->cantidadTinta);

    getInt(&opcion, "INGRESE OPCION: \n");
    switch(opcion)
    {
    case 1:
        if(eImpresora_saveAsBinary("hp.dat", pListaImpresora) != FALSE)
        {
        	puts("SE GUARDO CORRECTAMENTE");
        }else
        {
        	puts("NO SE GUARDO CORRECTAMENTE");
        }
    	break;
    case 2:
    	if(controller_loadFromBinary("hp.dat", pListaImpresora) == TRUE)
		{
            printf("%d - %s - %d\n", pListaImpresora->id, pListaImpresora->marca, pListaImpresora->cantidadTinta);
		}
    	break;
    case 3:
    	break;
    }
	return EXIT_SUCCESS;
}
