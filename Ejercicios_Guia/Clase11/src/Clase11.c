/*

 ============================================================================
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
idProducto (numerico)
descripcion (alfanumérico)
nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
tipo (numérico)
precio (numérico decimal)
Agregar la estructura etipoProducto, que definirá los siguientes campos:
idTipo (numérico)
descripcionTipo(alfanumérico)
Para esta estructura en principio trabajaremos con datos hardcodeados:
Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array. Al momento de dar de alta el producto, el usuario podrá elegir el tipo de producto, de una lista que se le desplegará en pantalla.
BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo. Si modifica el tipo de producto, se utilizara el mismo criterio que para dar de alta.
LISTADO Productos.
LISTADO ordenado por precio.
LISTADO ordenado por descripción.
Agregar los siguientes informes:
El/los  productos más caros.
Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.
Se agregan los siguientes listados:
El listado de todos los productos con la descripción del tipo.
Por cada tipo la lista de productos.

	Bamio Ezequiel

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.Get.h"
#include "utn.Struct.h"
#include "utn.Struct.Tipo.h"

#define SIZE_LIST_PRODUCTO 3
#define SIZE_LIST_NACIONALIDAD 3
#define SIZE_LIST_TIPO 4

int main(void) {

    setbuf(stdout, NULL);

    eNacionalidad listaNacionalidadProducto[SIZE_LIST_NACIONALIDAD] = {{1, "EEUU"},{2, "CHINA"},{3, "OTRO"}};

    eTipoProducto listaTipoProducto[SIZE_LIST_TIPO] = {{1000, "Iphone"},{1001, "Ipad"},{1002, "Mac"},{1003, "Accesorios"}};

   eProducto listaProductos[SIZE_LIST_PRODUCTO] = {{2, "Asdq", 1, 500, 1003, 1},{5, "Zasd", 3, 650, 1002, 1},{6, "hola", 2, 250, 1001, 1}};

    int opcion;
    char tipoConMasProducto[50];


   // Inicializar_Productos(listaProductos, SIZE_LIST_PRODUCTO);

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
		printf("* 11. Lista de tipo con mas productos\n");

		printf("\n* 12. Salir\n");
		utn_getNumero(&opcion, "*Elija una opcion: ", "*ERROR: Elija una opcion: ", 1, 12);

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
				if(Eliminar_Un_Producto(listaProductos, SIZE_LIST_PRODUCTO) == 1)
				{
					printf("* Se dio de baja el producto!\n ");
				}else
				{
					printf("* Se cancelo la baja del producto!\n");
				}
				break;
			case 3:
				if(Modificar_Un_Producto(listaProductos, SIZE_LIST_PRODUCTO) == 1)
				{
					printf("* Se modifico el producto!\n ");
				}else
				{
					printf("* Se cancelo la modificacion del producto!\n ");
				}
				break;
			case 4:
				if(Mostrar_Todos_Los_Productos(listaProductos, SIZE_LIST_PRODUCTO) == 0)
				{
					printf("No hay productos disponibles!\n");
				}
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
				 if(Mostrar_Promedio(listaProductos, SIZE_LIST_PRODUCTO, listaTipoProducto, SIZE_LIST_TIPO) == -1)
				 {
					printf("\nNo hay productos para mostrar\n");
				 }
				break;
			case 9:
				if(Listado_Productos_Con_Descripcion(listaProductos, listaNacionalidadProducto, SIZE_LIST_NACIONALIDAD, SIZE_LIST_PRODUCTO, listaTipoProducto, SIZE_LIST_TIPO) == 0)
				{
					printf("\nNo hay productos para mostrar\n");
				}
				break;
			case 10:
				if(Listado_Tipo_Producto(listaProductos, SIZE_LIST_PRODUCTO, listaNacionalidadProducto, SIZE_LIST_NACIONALIDAD, listaTipoProducto, SIZE_LIST_TIPO) == 0)
				{
					printf("\nNo hay productos para mostrar\n");
				}
				break;
			case 11:
				if(Listado_Tipo_Con_Mas_Productos(listaProductos, SIZE_LIST_PRODUCTO, listaTipoProducto, SIZE_LIST_TIPO, tipoConMasProducto) != 0)
				{
					printf("El tipo con mayor productos es: %s\n", tipoConMasProducto);
				}else
				{
					printf("\nNo hay productos para mostrar\n");
				}
				break;
		}
		system("pause");
	}while(opcion != 12);





	return EXIT_SUCCESS;
}
