#define VACIO -1
#define OCUPADO 0
#define SIZE_ARRAY 500

#ifndef STRUCT_TIPO_H_
#define STRUCT_TIPO_H_

typedef struct
{
	int idTipo;
	char descripcionTipo[SIZE_ARRAY];
	int isEmpty;

}eTipoProducto;

/***********************/
void Tipo_GetId(eTipoProducto pListaTipo[], int tTipo, char mensaje[], int* pResultado);

int Tipo_BuscarLibre(eTipoProducto pListaTipo[], int tTipo);

int Tipo_BuscarID(eTipoProducto pListaTipo[], int tTipo, int id);

int Tipo_Modificar(eTipoProducto pListaTipo[], int tTipo);

void Tipo_MostrarUno(eTipoProducto unTipo);

int Tipo_MostrarTodos(eTipoProducto pListaTipo[], int tTipo);

eTipoProducto Tipo_PedirDatos();

int Tipo_Cargar(eTipoProducto pListaTipo[], int tTipo);

void Tipo_Inicializar(eTipoProducto pListaTipo[], int tTipo);


#endif /* CLASE9_12_04_H_ */
