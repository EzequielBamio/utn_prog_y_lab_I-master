/*
 ============================================================================
	Bamio Ezequiel
 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include "Struct.h"
#include "utn.Get.h"

#define SIZE_PRODUCTO 3

int main(void) {

    setbuf(stdout, NULL);

    eProducto listaProductos[SIZE_PRODUCTO];
    int opcion;
    int promedioTipo;

    Producto_Inicializar(listaProductos, SIZE_PRODUCTO);

    do
	{

		printf("1. ALTA\n");
		printf("2. BAJA\n");
		printf("3. MODIFICACION\n");
		printf("4. LISTADO DE PRODUCOS\n");
		printf("5. LISTADO ORDENADO POR PRECIO\n");
		printf("6. LISTADO ORDENADO POR DESCRIPCION\n");
		printf("7. EL/LOS PRODUCTOS MAS CAROS\n");
		printf("8. PRECIO PROMEDIO POR TIPO DE PRODUCTO\n");
		printf("10. Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				if(Producto_Cargar(listaProductos, SIZE_PRODUCTO) == 1)
				{
					printf("El producto fue cargado con exito!\n");
				}else
				{
					printf("No hay espacio disponible!\n");
				}
				system("pause");
				break;
			case 2:
				if(Producto_Eliminar(listaProductos, SIZE_PRODUCTO) == 1)
				{
					printf("El producto fue eliminado!\n");
				}else
				{
					printf("Se cancelo la eliminacion del producto\n");
				}
				system("pause");
				break;
			case 3:
				if(Producto_Modificar(listaProductos, SIZE_PRODUCTO) == 1)
				{
					printf("El producto se modifico con exito!\n");
				}else
				{
					printf("Se cancelo la modificacion del producto!\n");
				}
				system("pause");
				break;
			case 4:
				if(Producto_MostrarTodos(listaProductos, SIZE_PRODUCTO) == 0)
				{
					printf("No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 5:
				Producto_OrdenarPrecio(listaProductos, SIZE_PRODUCTO);
				if(Producto_MostrarTodos(listaProductos, SIZE_PRODUCTO) == 0)
				{
					printf("No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 6:
				Producto_OrdenarDescripcion(listaProductos, SIZE_PRODUCTO);
				if(Producto_MostrarTodos(listaProductos, SIZE_PRODUCTO) == 0)
				{
					printf("No hay productos para mostrar\n");
				}
				system("pause");
				break;
			case 7:
				if(Producto_CalcularMasCaro(listaProductos, SIZE_PRODUCTO) == 0)
				{
					printf("\nNo hay productos para mostrar\n");
				}
				break;
			case 8:
				promedioTipo = Tipo_CalcularPromedio(listaProductos, 1, SIZE_PRODUCTO);
				if(promedioTipo != -1)
				{
					printf("El promedio de IPHONE: %d\n", promedioTipo);
				}
				promedioTipo = Tipo_CalcularPromedio(listaProductos, 2, SIZE_PRODUCTO);
				if(promedioTipo != -1)
				{
					printf("El promedio de MAC: %d\n", promedioTipo);
				}
				promedioTipo = Tipo_CalcularPromedio(listaProductos, 3, SIZE_PRODUCTO);
				if(promedioTipo != -1)
				{
					printf("El promedio de IPAD: %d\n", promedioTipo);
				}
				promedioTipo = Tipo_CalcularPromedio(listaProductos, 4, SIZE_PRODUCTO);
				if(promedioTipo != -1)
				{
					printf("El promedio de ACCESORIOS: %d\n", promedioTipo);
				}

				break;
		}
	}while(opcion!=10);





	return EXIT_SUCCESS;
}
