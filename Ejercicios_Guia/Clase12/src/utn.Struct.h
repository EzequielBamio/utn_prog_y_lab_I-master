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


/******************************************************************/

int Productos_Buscar_ID(eProducto [], int , int );

int Productos_Buscar_Libre(eProducto [], int);

int Productos_Eliminar(eProducto [], int);

int Productos_Modificar(eProducto [], int );

void Productos_MostrarUno(eProducto pListaProducto);

int Productos_MostrarTodos(eProducto pListaProducto[], int );

eProducto Productos_Pedir_Datos();

int Productos_Cargar(eProducto [], int);

void Productos_Inicializar(eProducto [], int);



#endif /* UTN_STRUCT_H_ */
