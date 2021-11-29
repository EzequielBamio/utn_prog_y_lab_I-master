#include <stdio.h>
#include "utn.Get.h"

#define T 100
#define VACIO 0
#define OCUPADO 1

#ifndef UTN_STRUCT_H_
#define UTN_STRUCT_H_

typedef struct
{
	int idTipo;
	char descripcionTipo[T];
	int isEmpty;

}eTipo;

typedef struct
{
	int idNacionalidad;
	char descripcionNacionalidad[T];

}eNacionalidad;

typedef struct
{
	int idProducto;
	char descripcion [T];
	int idNacionalidad;
	float precio;
	int idTipo;
    int isEmpty;


}eProducto;

void Listado_Tipo_Producto(eProducto pListaProducto[], int tProducto, eTipo pTipo[], int tTipo);

void Listado_Productos_Con_Descripcion(eProducto pListaProducto[], int tProducto, eTipo pTipo[], int tTipo);

void Mostrar_Promedio(eProducto pProducto[], int tProducto, eTipo pTipo[], int tTipo);

int Promedio_Tipo_Productos(eProducto [], int, int);

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
