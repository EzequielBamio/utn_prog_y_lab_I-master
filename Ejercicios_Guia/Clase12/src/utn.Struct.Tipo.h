#define T 100
#define VACIO 0
#define OCUPADO 1
#include "utn.Struct.h"

#ifndef UTN_STRUCT_TIPO_H_
#define UTN_STRUCT_TIPO_H_


float Tipo_Calcular_Promedio(eTipo [], int , eProducto [], int , int );

int Tipo_Mostrar_Promedio(eTipo [], int , eProducto [], int );

int Tipo_Buscar_ID(eTipo [], int , int );

int Tipo_Buscar_Libre(eTipo [], int);

int Tipo_Eliminar(eTipo [], int);

int Tipo_Modificar(eTipo [], int );

void Tipo_Mostrar_Uno(eTipo );

int Tipo_Mostrar_Todos(eTipo [], int);

eTipo Tipo_Pedir_Datos();

int Tipo_Cargar(eTipo [], int);

void Tipo_Inicializar(eTipo [], int);

#endif /* UTN_STRUCT_TIPO_H_ */
