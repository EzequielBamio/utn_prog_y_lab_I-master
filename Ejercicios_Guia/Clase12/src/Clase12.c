#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.Get.h"
#include "utn.Struct.h"
#include "utn.Struct.Tipo.h"
#include "menu.h"

#define SIZE_LIST_PRODUCTO 3
#define SIZE_LIST_NACIONALIDAD 3
#define SIZE_LIST_TIPO 4

int main(void) {

	setbuf(stdout, NULL);

	   // eNacionalidad listaNacionalidadProducto[SIZE_LIST_NACIONALIDAD] = {{1, "EEUU"},{2, "CHINA"},{3, "OTRO"}};

	    eTipo listaTipoProducto[SIZE_LIST_TIPO] = {{1000, "Iphone"},{1001, "Ipad"},{1002, "Mac"},{1003, "LG"}};

	   eProducto listaProductos[SIZE_LIST_PRODUCTO]; //= {{2, "Lorem ipsum", 1, 500, 1003, 1},{5, "Lorem ipsum", 3, 650, 1002, 1},{6, "Lorem ipsum", 2, 250, 1002, 1}};

	    int opcion;



    do
	{
    	printf("*************************************************");
		printf("\n  				    				         ");
		printf("\n  	             MENU				         ");
		printf("\n  				 				             ");
    	printf("\n*************************************************\n");

		printf("* 1. Alta\n");
		printf("* 2. Baja\n");
		printf("* 3. Modificacion\n");
		printf("* 4. Listados\n");
		printf("* 5. Informes\n");
		printf("* 6. Consultas\n");
		printf("* 7. Tareas\n");

		printf("\n* 8. Salir\n");
		utn_getNumero(&opcion, "*Elija una opcion: ", 1, 8);

		//Inicializar Productos (-1)
		Productos_Inicializar(listaProductos, SIZE_LIST_PRODUCTO);

		switch(opcion)
		{
			case 1:
				if(Productos_Cargar(listaProductos, SIZE_LIST_PRODUCTO) != 0)
				{
					printf("* El producto se cargo correctamente! \n");
				}else
				{
					printf("* No hay espacio suficiente! \n");
				}
				system("pause");
				break;
			case 2:
				if(Productos_Eliminar(listaProductos, SIZE_LIST_PRODUCTO) != 0)
				{
					printf("* Se elimino el producto correctamente! \n");
				}else
				{
					printf("* Se cancelo la eliminacion del producto! \n");
				}
				system("pause");
				break;
			case 3:
				if(Productos_Modificar(listaProductos, SIZE_LIST_PRODUCTO) != -1)
				{
					printf("* Se modifico el producto correctamente! \n");
				}else
				{
					printf("* Se cancelo la modificacion del producto! \n");
				}
				system("pause");
				break;
			case 4:
				SubMenu_Listado(listaProductos, SIZE_LIST_PRODUCTO, listaTipoProducto, SIZE_LIST_TIPO);
				system("pause");
				break;
			case 5:
				SubMenu_Informes(listaTipoProducto, SIZE_LIST_TIPO, listaProductos, SIZE_LIST_PRODUCTO);
				system("pause");
				break;
			case 6:
				SubMenu_Consultas(listaProductos, SIZE_LIST_PRODUCTO);
				system("pause");
				break;
			case 7:
				SubMenu_Tareas(listaTipoProducto, SIZE_LIST_TIPO);
				system("pause");
				break;

		}
	}while(opcion != 8);





	return EXIT_SUCCESS;
}
