#include "menu.h"
#include "utn.Get.h"
#include "utn.Struct.h"
#include "utn.Struct.Tipo.h"

void SubMenu_Listado(eProducto pListaProducto[], int tProducto, eTipo pListaTipo[], int tTipo)
{
	int opcion;
	do
		{
	    	printf("*************************************************");
			printf("\n  				    				         ");
			printf("\n  	             Listados			         ");
			printf("\n  				 				             ");
	    	printf("\n*************************************************\n");

			printf("* 1. Productos\n");
			printf("* 2. Ordenado por precio\n");
			printf("* 3. Ordenado por descripcion\n");
			printf("* 4. Ordenado por nacionalidad alfabeticamente\n");
			printf("* 5. Tipos con mas productos\n");
			printf("* 6. Productos con descripcion del tipo\n");
			printf("* 7. Tipos\n");

			printf("\n* 8. Salir\n");
			utn_getNumero(&opcion, "*Elija una opcion: ", 1, 8);

			switch(opcion)
			{
				case 1:
					if(Productos_MostrarTodos(pListaProducto, tProducto) != 1)
					{
						printf("No hay productos disponibles!\n");
					}

					system("pause");
					break;
				case 2:
					Ordenar_Productos_Por_Precio(pListaProducto, tProducto);
					if(Productos_MostrarTodos(pListaProducto, tProducto) == 0)
					{
						printf("No hay productos disponibles!\n");
					}

					system("pause");
					break;
				case 3:
					Ordenar_Productos_Por_Descripcion(pListaProducto, tProducto);
					if(Productos_MostrarTodos(pListaProducto, tProducto) == 0)
					{
						printf("No hay productos disponibles!\n");
					}

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
			}
		}while(opcion != 8);

}
void SubMenu_Informes(eTipo pListaTipo[], int tTipo, eProducto pListaProducto[], int tProducto)
{
	int opcion;
	do
		{
	    	printf("*************************************************");
			printf("\n  				    				         ");
			printf("\n  	             Informes			         ");
			printf("\n  				 				             ");
	    	printf("\n*************************************************\n");

			printf("* 1. El/Los productos mas caros\n");
			printf("* 2. Precio promedio por tipo\n");
			printf("* 3. Precio promedio por nacionalidad\n");

			printf("\n* 4. Salir\n");
			utn_getNumero(&opcion, "*Elija una opcion: ", 1, 4);

			switch(opcion)
			{
				case 1:

					system("pause");
					break;
				case 2:
					if(Tipo_Mostrar_Promedio(pListaTipo, tTipo, pListaProducto, tProducto) == 0)
					{
						printf("No hay productos disponibles!\n");
					}
					system("pause");
					break;
				case 3:

					system("pause");
					break;

			}
		}while(opcion != 4);

}
void SubMenu_Consultas(eProducto pListaProducto[], int tProducto)
{
	int opcion;
	do
		{
	    	printf("*************************************************");
			printf("\n  				    				         ");
			printf("\n  	             Consultas			         ");
			printf("\n  				 				             ");
	    	printf("\n*************************************************\n");

			printf("* 1. Nacionalidad que solo fabrica Iphone\n");
			printf("* 2. Nacionalidad con mas tipos de productos fabricados\n");

			printf("\n* 3. Salir\n");
			utn_getNumero(&opcion, "*Elija una opcion: ", 1, 3);

			switch(opcion)
			{
				case 1:

					system("pause");
					break;
				case 2:
					system("pause");
					break;

			}
		}while(opcion != 3);

}
void SubMenu_Tareas(eTipo pListaTipo[], int tTipo)
{
	int opcion;
	do
		{
	    	printf("*************************************************");
			printf("\n  				    				         ");
			printf("\n  	             TAREAS 			         ");
			printf("\n  				 				             ");
	    	printf("\n*************************************************\n");

			printf("* Tipo\n");
			printf(" * 1. Alta:\n");
			printf(" * 2. Baja:\n");
			printf(" * 3. Modificacion:\n");
			printf("* Nacionalidad\n");
			printf(" * 4. Alta:\n");
			printf(" * 5. Baja:\n");
			printf(" * 6. Modificacion:\n");

			printf("\n* 7. Salir\n");
			utn_getNumero(&opcion, "*Elija una opcion: ", 1, 7);

			//Tipo_Inicializar(pListaTipo, tTipo);

			switch(opcion)
			{
				case 1:
					if(Tipo_Cargar(pListaTipo, tTipo) != 0)
					{
						printf("* El Tipo se cargo correctamente! \n");
					}else
					{
						printf("* No hay espacio suficiente! \n");
					}
					system("pause");
					break;
				case 2:
					if(Tipo_Eliminar(pListaTipo, tTipo) != 0)
					{
						printf("* Se elimino el producto correctamente! \n");
					}else
					{
						printf("* Se cancelo la eliminacion del producto! \n");
					}
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

			}
		}while(opcion != 7);

}

