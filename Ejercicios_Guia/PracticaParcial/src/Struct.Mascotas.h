

#ifndef STRUCT_MASCOTAS_H_
#define STRUCT_MASCOTAS_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct
{
	int idMas;
	char nombre[MAX_CHARS_CADENAS];
	int edad;
	char sexo;
	char tipo[MAX_CHARS_CADENAS];
	int raza;
	int isEmpty;

} eMascotas;
//***

/** INICIO CABECERAS DE FUNCION*/
void eMascotas_Inicializar(eMascotas pListaMascotas[], int tMascotas);
int eMascotas_ObtenerID(void);
int eMascotas_ObtenerIndexLibre(eMascotas pListaMascotas[], int tMascotas);
int eMascotas_BuscarPorID(eMascotas pListaMascotas[], int tMascotas, int ID);
void eMascotas_MostrarUno(eMascotas pListaMascotas);
int eMascotas_MostrarTodos(eMascotas pListaMascotas[], int tMascotas);
int eMascotas_MostrarDadosDeBaja(eMascotas pListaMascotas[], int tMascotas);
void eMascotas_ValidarId(eMascotas pppListaMascotas[], int tMascotas, char mensaje[], int* pResultado);


/** ORDENAMIENTO */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eMascotas_Ordenamiento(eMascotas pListaMascotas[], int tMascotas, int criterio);

//ABM
eMascotas eMascotas_CargarDatos(void);
eMascotas eMascotas_ModificarUno(eMascotas Gen);
int eMascotas_Alta(eMascotas pListaMascotas[], int tMascotas);
int eMascotas_Baja(eMascotas pListaMascotas[], int tMascotas);
int eMascotas_Modificacion(eMascotas pListaMascotas[], int tMascotas);
/** FIN CABECERAS DE FUNCION*/
#endif /* STRUCT_MASCOTAS_H_ */
