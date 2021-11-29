/*
 ============================================================================
	Bamio Ezequiel
 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include "utn.Get.h"
#include "Struct.h"
#include "Struct.Product.h"
#include "Struct.Nacionalidad.h"
#include "Struct.Tipo.h"

#define SIZE_PRODUCTO 3
#define SIZE_TIPO 4
#define SIZE_NACIONALIDAD 3

#define ON_FLAG 1
#define OFF_FLAG 0

int main(void) {

    setbuf(stdout, NULL);

	eProducto listaProductos[SIZE_PRODUCTO] = {{2, "Lorem ipsum", 2, 1002, 852, 0},
											  {5, "Lorem ipsum", 1, 1001, 500, 0},
											  {6, "Lorem ipsum", 2, 1002, 525, 0}};

    eTipoProducto listaTipo[SIZE_TIPO] = {{1000, "Iphone", 0},{1001, "Ipad", 0},{1002, "Mac", 0},{1003, "LG", 0}};
    eNacionalidad listaNacionalidad[SIZE_NACIONALIDAD] = {{1, "EEUU", 0},{2, "CHINA", 0},{3, "OTRO", 0}};

    int opcion;
    int flagProducto;
    flagProducto = OFF_FLAG;

    //Nacionalidad_Inicializar(listaNacionalidad, SIZE_NACIONALIDAD);
    //Tipo_Inicializar(listaTipo, SIZE_TIPO);
   // Producto_Inicializar(listaProductos, SIZE_PRODUCTO);

    do
	{

		printf("1. ALTA\n");
		printf("2. BAJA\n");
		printf("3. MODIFICACION\n");
		printf("4. LISTADO DE PRODUCOS\n");
		printf("5. LISTADO ORDENADO POR PRECIO\n");
		printf("6. LISTADO ORDENADO POR DESCRIPCION\n");
		printf("7. EL/LOS PRODUCTOS MAS CAROS\n");//Agregar la cabecera
		printf("8. PRECIO PROMEDIO POR TIPO DE PRODUCTO\n");
		printf("9. LISTADO DE PRODUCTOS CON DESCRIPCION DEL TIPO\n");//Agregar cabecera
		printf("10. POR CADA TIPO LA LISTA DE PRODUCTOS\n"); //R se podria mejorar poniendo el nombre del tipo una sola vez
		printf("11. EL/LOS TIPOS DE PRODUCTOS CON MAS PRODUCTOS ELABORADOS\n");//se podria mostrar el contador
		printf("12. LA NACIONALIDAD QUE SOLO FABRICA IPHONE\n");
		printf("13. LOS PRODUCTOS ORDENADOS POR NACIONALIDAD ALFABETICAMENTE\n");//se muestra de z-a MAL
		printf("14. LA NACIONALIDAD CON MAS TIPOS DE PRODUCTOS FABRICADOS\n"); //CAMBIAR EL RETORNO
		printf("15. EL PRECIO PROMEDIO DE PRODUCTOS POR NACIONALIDAD\n");
		printf("16. TIPOS\n");
		printf("17. NACIONALIDAD\n");
		printf("\n");
		printf("18. Salir\n");
		utn_getNumero(&opcion, "Elija una opcion: ", 1, 18);
		system("cls");


		switch(opcion)
		{
			case 1:
				if(Producto_Cargar(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO, listaNacionalidad, SIZE_NACIONALIDAD) == 1)
				{
					puts("* El producto fue cargado con exito!");
				}else
				{
					puts("* No hay espacio disponible!");
				}
				flagProducto++;
				system("pause");
				break;
			case 2:
				if(flagProducto == 0)
				{
					printf("* No hay productos disponibles para borrar\n");
				}else
				{
					if(Producto_Eliminar(listaProductos, SIZE_PRODUCTO) == 1)
					{
						printf("* El producto fue eliminado!\n");
						flagProducto--;
					}else
					{
						printf("* Se cancelo la eliminacion del producto\n");
					}
				}
				system("pause");
				break;
			case 3:
				if(flagProducto == 0)
				{
					printf("* No hay productos disponibles para modificar\n");
				}else
				{
					if(Producto_Modificar(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO) == 1)
					{
						printf("* El producto se modifico con exito!\n");
						flagProducto--;
					}else
					{
						printf("* Se cancelo la modificacion del producto!\n");
					}
				}
				system("pause");
				break;
			case 4:
				if(Producto_MostrarTodos(listaProductos, SIZE_PRODUCTO) == 0)
				{
					printf("\n* No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 5:
				Producto_OrdenarPrecio(listaProductos, SIZE_PRODUCTO);
				if(Producto_MostrarTodos(listaProductos, SIZE_PRODUCTO) == 0)
				{
					printf("\n* No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 6:
				Producto_OrdenarDescripcion(listaProductos, SIZE_PRODUCTO);
				if(Producto_MostrarTodos(listaProductos, SIZE_PRODUCTO) == 0)
				{
					printf("\n* No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 7:
				if(Producto_CalcularMasCaro(listaProductos, SIZE_PRODUCTO) == -1)
				{
					printf("\n* No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 8:
				if(Tipo_CalcularPromedio(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO) != 1)
				{
					printf("\n* No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 9:
				if(Producto_MostrarConDescripcion(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO) != 1)
				{
					printf("\n* No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 10:
				if(Tipo_MostrarProductos(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO) != 1)
				{
					printf("\n* No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 11:
				if(Tipo_ConMasProductosElaborados(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO) != 1)
				{
					printf("\n* No hay productos para mostrar\n");
				}

				system("pause");
				break;
			case 12:
				if(Nacionalidad_SoloFabricaIphone(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO, listaNacionalidad, SIZE_NACIONALIDAD) == 0)
				{
					printf("\n* No hay productos para mostrar\n");
				}

				system("pause");
				break;
			case 13:
				Nacionalidad_OrdenarAlfabeticamente(listaProductos, SIZE_PRODUCTO, listaNacionalidad, SIZE_NACIONALIDAD);
				if(Nacionalidad_MostrarProductos(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO, listaNacionalidad, SIZE_NACIONALIDAD) != 1)
				{
					printf("\n* No hay productos para mostrar\n");
				}

				system("pause");
				break;
			case 14:
				if(Nacionalidad_ConMasTipoProducto(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO, listaNacionalidad, SIZE_NACIONALIDAD) == -1)
				{
					printf("\n* No hay productos para mostrar\n");
				}

				system("pause");
				break;
			case 15:
				if(Nacionalidad_MostrarPromedio(listaProductos, SIZE_PRODUCTO, listaNacionalidad, SIZE_NACIONALIDAD) == 0)
				{
					printf("\n* No hay productos para mostrar\n");
				}

				system("pause");
				break;
			case 16:
				Tipo_SubMenu(listaProductos, SIZE_PRODUCTO, listaTipo, SIZE_TIPO);
				break;
			case 17:
				Nacionalidad_SubMenu(listaProductos, SIZE_PRODUCTO, listaNacionalidad, SIZE_NACIONALIDAD);
				break;
		}
		system("cls");
	}while(opcion != 18);





	return EXIT_SUCCESS;
}
