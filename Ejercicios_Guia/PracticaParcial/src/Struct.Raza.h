

#ifndef STRUCT_RAZA_H_
#define STRUCT_RAZA_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
//*** ESTRUCTURA
typedef struct
{
	int idRaz;
	char descripcion[MAX_CHARS_CADENAS];
	char tamanio[MAX_CHARS_CADENAS];
	char paisOrigen[MAX_CHARS_CADENAS];
	int isEmpty;

} eRaza;
//***
int eRaza_BuscarPorID(eRaza pListaRaza[], int tRaza, int ID);
#endif /* STRUCT_RAZA_H_ */
