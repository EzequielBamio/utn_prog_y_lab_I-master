/*
 ============================================================================
Creada 13/04/2021
Actualizaciones:

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.Get.h"

int main(void) {
	int edad;
	edad = utn_getNumero("\nEdad? ","\nError", 0,200,2);

	if(edad != -1)
	{
		printf("\nLa edad es %d",edad);
	}

		return EXIT_SUCCESS;
}
