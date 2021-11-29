#include "Struct.General.h"
#include "Struct.Mascotas.h"
#include "Struct.Raza.h"
void Mascotas_MostrarUno(eMascotas pListaMascotas, eRaza pListaRaza)
{
	//PRINTF DE UN SOLO pListaMascotas
	printf("%-6d %-15s %-6d %-5c %-14s %-20s %-10s\n\n", pListaMascotas.idMas, pListaMascotas.nombre, pListaMascotas.edad, pListaMascotas.sexo, pListaMascotas.tipo, pListaRaza.descripcion, pListaRaza.paisOrigen);
}


int Mascotas_MostrarTodos(eMascotas pListaMascotas[], int tMascotas, eRaza pListaRaza[], int tRaza)
{
	int i;
	int j;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO pListaMascotas");
	printf("|ID   |NOMBRE        |EDAD  |SEXO  |TIPO           |RAZA            |PAIS DE ORIGEN\n\n");
	//printf("%6s %13s %15s %15s %13s\n\n", "ID ", "NOMBRE ", "EDAD ", "SEXO ", "TIPO "); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	// EL LIMITE ES VALIDO
	if (tMascotas > 0)
	{
		//RECORRO TODO EL pListaMascotas
		for (i = 0; i < tMascotas; i++)
		{
			j = eRaza_BuscarPorID(pListaRaza, tRaza, pListaMascotas[i].raza);
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (pListaMascotas[i].isEmpty == OCUPADO)
			{
				//MUESTRO UN SOLO pListaMascotas
				Mascotas_MostrarUno(pListaMascotas[i], pListaRaza[j]);
				//CONTADOR DE pListaMascotas
				cantidad++;
			}
		 }
	}

	//SI CANTIDAD == 0 - NO HUBO pListaMascotas PARA MOSTRAR (pListaMascotas SIN ALTAS)
	if (cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}
