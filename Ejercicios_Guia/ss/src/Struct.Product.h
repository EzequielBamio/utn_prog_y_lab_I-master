#define VACIO -1
#define OCUPADO 0
#define SIZE_ARRAY 500

#ifndef STRUCT_PRODUCT_H_
#define STRUCT_PRODUCT_H_

typedef struct
{
	int idProducto;
	char descripcion [SIZE_ARRAY];
	int nacionalidad;
	int tipo;
	float precio;
    int isEmpty;

}eProducto;

void Producto_GetId(eProducto pListaProducto[], int tProducto, char mensaje[], int* pResultado);
int Producto_BuscarID(eProducto pListaProducto[], int tProducto, int id);
int Producto_BuscarIdNacionalidad(eProducto pListaProducto[], int tProducto, int id);
int Producto_BuscarIdTipo(eProducto pListaProducto[], int tProducto, int id);
int Producto_BuscarLibre(eProducto pListaProducto[], int tProducto);

//int Producto_Modificar(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo);

int Producto_Eliminar(eProducto pListaProducto[], int tProducto);

void Producto_MostrarUno(eProducto unProducto);

int Producto_MostrarTodos(eProducto pListaProducto[], int tProducto);

/*eProducto Producto_PedirDatos();

int Producto_Cargar(eProducto pListaProducto[], int tProducto);*/

void Producto_Inicializar(eProducto pListaProducto[], int tProducto);

#endif /* STRUCT_PRODUCT_H_ */
