#define VACIO -1
#define OCUPADO 0
#define VACIO -1
#define OCUPADO 0
#define SIZE_ARRAY 500

#ifndef STRUCT_NACIONALIDAD_H_
#define STRUCT_NACIONALIDAD_H_

typedef struct
{
	int idNacionalidad;
	char descripcionNacionalidad[SIZE_ARRAY];
	int isEmpty;

}eNacionalidad;

/***********************/
void Nacionalidad_GetId(eNacionalidad pListaNacionalidad[], int tNacionalidad, char mensaje[], int* pResultado);

int Nacionalidad_BuscarLibre(eNacionalidad pListaNacionalidad[], int tNacionalidad);

int Nacionalidad_BuscarID(eNacionalidad pListaNacionalidad[], int tNacionalidad, int id);

int Nacionalidad_Modificar(eNacionalidad pListaNacionalidad[], int tNacionalidad);

void Nacionalidad_MostrarUno(eNacionalidad unNacionalidad);

int Nacionalidad_MostrarTodos(eNacionalidad pListaNacionalidad[], int tNacionalidad);

eNacionalidad Nacionalidad_PedirDatos();

int Nacionalidad_Cargar(eNacionalidad pListaNacionalidad[], int tNacionalidad);

void Nacionalidad_Inicializar(eNacionalidad pListaNacionalidad[], int tNacionalidad);

#endif /* STRUCT_NACIONALIDAD_H_ */
