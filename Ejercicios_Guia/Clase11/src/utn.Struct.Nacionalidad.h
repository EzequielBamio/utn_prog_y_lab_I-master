#include "utn.Struct.Tipo.h"

#define T 100
#define VACIO 0
#define OCUPADO 1

#ifndef UTN_STRUCT_NACIONALIDAD_H_
#define UTN_STRUCT_NACIONALIDAD_H_

typedef struct
{
	int idNacionalidad;
	char descripcionNacionalidad[T];
	int isEmpty;

}eNacionalidad;

int Confirmar_Respuesta(char [], char []);

int Nacionalidad_Buscar_ID(eNacionalidad pListaProducto[], int tProducto, int valorBuscado);

int Nacionalidad_Buscar_Libre(eNacionalidad [], int);

int Nacionalidad_Eliminar(eNacionalidad [], int);

void Nacionalidad_Mostrar_Uno(eNacionalidad );

int Nacionalidad_Mostrar_Todos(eNacionalidad [], int);

int Nacionalidad_Modificar(eNacionalidad pListaNacionalidad[], int tNacionalidad);

eNacionalidad Nacionalidad_Pedir_Datos();

int Nacionalidad_Cargar(eNacionalidad [], int);

void Nacionalidad_Inicializar(eNacionalidad [], int);

#endif /* UTN_STRUCT_NACIONALIDAD_H_ */
