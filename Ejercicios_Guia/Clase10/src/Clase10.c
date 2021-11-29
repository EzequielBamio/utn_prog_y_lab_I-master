/*
 ============================================================================

	Bamio Ezequiel

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.Get.h"
#include "utn.Struct.h"

#define SIZE_LIST_PRODUCTO 3
#define SIZE_LIST_TIPO 4

int main(void) {

    setbuf(stdout, NULL);

    eTipo listaTipoProducto[SIZE_LIST_TIPO] = {{1000, "Iphone"},{1001, "Ipad"},{1002, "Mac"},{1003, "Accesorios"}};

    eProducto listaProductos[SIZE_LIST_PRODUCTO];// = {{2, "Asdq", 1, 500, 1002, 1},{5, "Zasd", 2, 650, 1003, 1},{6, "hola", 1, 250, 1001, 1}};

    int opcion;
    int bajaProducto;
    int modifcarProducto;

    Inicializar_Productos(listaProductos, SIZE_LIST_PRODUCTO);

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
		printf("* 4. Listado productos.\n");
		printf("* 5. Listado ordenado por precio.\n");
		printf("* 6. Listado ordenado por descripcion\n");
		printf("* 7. El/los producto mas caro\n");
		printf("* 8. Precio promedio por tipo de producto\n");
		printf("* 9. Listado productos con descripcion del tipo\n");
		printf("* 10. Lista de productos de cada tipo\n");
		printf("\n* 11. Salir\n");
		utn_getNumero(&opcion, "*Elija una opcion: ", "*ERROR: Elija una opcion: ", 1, 11);

		switch(opcion)
		{
			case 1:
				if(Cargar_Productos(listaProductos, SIZE_LIST_PRODUCTO) == 1)
				{
					printf("* Se cargo correctamente el producto!\n ");
				}else
				{
					printf("* No hay espacio disponible!\n");
				}
				break;
			case 2:
				bajaProducto = Eliminar_Un_Producto(listaProductos, SIZE_LIST_PRODUCTO);
				if(bajaProducto == 1)
				{
					printf("* Se dio de baja el producto!\n ");
				}else
				{
					if(bajaProducto == -1)
					{
						printf("* No se encontro el ID!\n");
					}else
					{
						printf("* Se cancelo la baja el producto!\n ");
					}
				}
				break;
			case 3:
				modifcarProducto = Modificar_Un_Producto(listaProductos, SIZE_LIST_PRODUCTO);
				if(modifcarProducto == 1)
				{
					printf("* Se modifico el producto!\n ");
				}else
				{
					if(modifcarProducto == -1)
					{
						printf("* No se encontro el ID!\n");
					}else
					{
						printf("* Se cancelo la modificacion del producto!\n ");
					}
				}
				break;
			case 4:
				Mostrar_Todos_Los_Productos(listaProductos, SIZE_LIST_PRODUCTO);

				break;
			case 5:
				Ordenar_Productos_Por_Precio(listaProductos, SIZE_LIST_PRODUCTO);
				if(Mostrar_Todos_Los_Productos(listaProductos, SIZE_LIST_PRODUCTO) != 1)
				{
					printf("No hay productos disponibles!\n");
				}

				break;
			case 6:
				Ordenar_Productos_Por_Descripcion(listaProductos, SIZE_LIST_PRODUCTO);
				if(Mostrar_Todos_Los_Productos(listaProductos, SIZE_LIST_PRODUCTO) != 1)
				{
					printf("No hay productos disponibles!\n");
				}

				break;
			case 7:
				if(Calcular_Mas_Caro(listaProductos, SIZE_LIST_PRODUCTO) == 0)
				{
					printf("\nNo hay productos para mostrar\n");
				}

				break;
			case 8:
				 Mostrar_Promedio(listaProductos, SIZE_LIST_PRODUCTO, listaTipoProducto, SIZE_LIST_TIPO);

				break;
			case 9:
				Listado_Productos_Con_Descripcion(listaProductos, SIZE_LIST_PRODUCTO, listaTipoProducto, SIZE_LIST_TIPO);
				break;
			case 10:
				Listado_Tipo_Producto(listaProductos, SIZE_LIST_PRODUCTO, listaTipoProducto, SIZE_LIST_TIPO);
				break;
		}
		system("pause");
	}while(opcion != 11);





	return EXIT_SUCCESS;
}
