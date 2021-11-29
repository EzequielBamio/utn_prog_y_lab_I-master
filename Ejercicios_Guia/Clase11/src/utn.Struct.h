#include <stdio.h>
#include "utn.Get.h"

#define T 100
#define VACIO 0
#define OCUPADO 1

#ifndef UTN_STRUCT_H_
#define UTN_STRUCT_H_

typedef struct
{
	int idProducto;
	char descripcion [T];
	int idNacionalidad;
	float precio;
	int idTipo;
    int isEmpty;


}eProducto;

int buscar_Id(eProducto pListaProducto[], int tProducto, int valorBuscado);

int Buscar_Tipo(eTipoProducto [], int , int );

int Calcular_Mas_Caro(eProducto [], int);

int Modificar_Un_Producto(eProducto [], int);

void Ordenar_Productos_Por_Descripcion(eProducto [], int);

void Ordenar_Productos_Por_Precio(eProducto [], int);

int MostrarID(eProducto [], int);

int Eliminar_Un_Producto(eProducto [], int);

void Mostrar_Un_Producto(eProducto );

int Mostrar_Todos_Los_Productos(eProducto [], int);

eProducto Pedir_Datos();

int Cargar_Productos(eProducto [], int);

void Inicializar_Productos(eProducto [], int);

int Buscar_Libre(eProducto [], int);

int Confirmar_Respuesta(char [], char []);

#endif /* UTN_STRUCT_H_ */
