#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.Get.h"

#define T 3

int main(void) {

    setbuf(stdout, NULL);
    int opcion;
    char asd[100];

    myGets(asd, 100, "Ingrese la puta que te pario");
    puts(asd);



    do
	{
    	printf("*************************************************");
		printf("\n  				    				         ");
		printf("\n  	             MENU				         ");
		printf("\n  				 				             ");
    	printf("\n*************************************************\n");

		printf("* 1. \n");
		printf("* 2. \n");
		printf("* 3. \n");
		printf("* 4. \n");
		printf("* 5. \n");
		printf("* 6. \n");
		printf("* 7. \n");
		printf("* 8. \n");

		printf("\n* 10. Salir\n");
		utn_getNumero(&opcion, "*Elija una opcion: ", "*ERROR: Elija una opcion: ", 1, 10);

		switch(opcion)
		{
			case 1:

				system("pause");
				break;
			case 2:

				system("pause");
				break;
			case 3:

				system("pause");
				break;
			case 4:

				system("pause");
				break;
			case 5:

				system("pause");
				break;
			case 6:

				system("pause");
				break;
			case 7:

				system("pause");
				break;
			case 8:

				system("pause");
				break;
			default:
				printf("ERROR: Esta opcion es incorrecta.\n");
				system("pause");
				break;
		}
	}while(opcion!=10);





	return EXIT_SUCCESS;
}
