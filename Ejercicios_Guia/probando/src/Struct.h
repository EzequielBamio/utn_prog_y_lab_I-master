#include <stdio.h>
#include <string.h>

#define VACIO -1
#define OCUPADO 0
#define D 500
#define EEUU 1
#define CHINA 2
#define OTRO 3
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4

#ifndef CLASE9_12_04_H_
#define CLASE9_12_04_H_

typedef struct
{
	int idProducto;
	char descripcion [D];
	int nacionalidad;
	int tipo;
	float precio;
    int isEmpty;


}eProducto;

int Tipo_CalcularPromedio(eProducto pListaProducto[], int tipo, int tProducto);

int Producto_CalcularMasCaro(eProducto pListaProducto[], int tProducto);


void Producto_OrdenarDescripcion(eProducto pListaProducto[], int tProducto);

void Producto_OrdenarPrecio(eProducto pListaProducto[], int tProducto);

int Producto_MostrarID(eProducto pListaProducto[], int tProducto);

int Producto_Modificar(eProducto pListaProducto[], int tProducto);

int Producto_Eliminar(eProducto pListaProducto[], int tProducto);

void Producto_MostrarUno(eProducto unProducto);

int Producto_MostrarTodos(eProducto pListaProducto[], int tProducto);

eProducto Producto_PedirDatos();

int Producto_Cargar(eProducto pListaProducto[], int tProducto);

void Producto_Inicializar(eProducto pListaProducto[], int tProducto);

int Producto_BuscarLibre(eProducto pListaProducto[], int tProducto);

#endif /* CLASE9_12_04_H_ */
