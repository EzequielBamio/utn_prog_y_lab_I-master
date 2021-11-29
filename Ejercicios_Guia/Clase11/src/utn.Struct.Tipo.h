#include "utn.Struct.h"

#define T 100
#define VACIO 0
#define OCUPADO 1

#ifndef UTN_STRUCT_TIPO_H_
#define UTN_STRUCT_TIPO_H_

typedef struct
{
	int idTipo;
	char descripcionTipo[T];

}eTipoProducto;

int Buscar_Productos(eProducto [], int , int );

int Listado_Tipo_Con_Mas_Productos(eProducto [], int , eTipoProducto [], int , char *);

int Listado_Tipo_Producto(eProducto [], int , eNacionalidad pNacionalidad[], int , eTipoProducto [], int );

int Listado_Productos_Con_Descripcion(eProducto [], eNacionalidad [], int , int , eTipoProducto [], int );

int Mostrar_Promedio(eProducto [], int , eTipoProducto [], int );

int Promedio_Tipo_Productos(eProducto [], int, int);

#endif /* UTN_STRUCT_TIPO_H_ */
