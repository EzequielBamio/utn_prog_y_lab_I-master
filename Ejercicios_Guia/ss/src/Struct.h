#include <stdio.h>
#include <string.h>
#include "Struct.Product.h"
#include "Struct.Tipo.h"
#include "Struct.Nacionalidad.h"

#define VACIO -1
#define OCUPADO 0

#ifndef CLASE9_12_04_H_
#define CLASE9_12_04_H_

typedef struct
{
	int id;
	char descripcion[500];
	char descripcionNacionalidad[500];
	int tipo;
	float precio;
	int contador;
	float acumulador;
	float promedio;

}eAuxiliar;

void Calcular_Promedio(float* pResultado, float total, int cantidad);

void Tipo_TotalPrecios(eAuxiliar auxiliar[], eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo);
void Tipo_Promedio(eAuxiliar auxiliar[], eTipoProducto pListaTipo[], int tTipo);
void Tipo_MostrarPromedio(eAuxiliar auxiliar[], eTipoProducto pListaTipo[], int tTipo);

void aux_Inicializar(eAuxiliar auxiliar[], eTipoProducto pListaTipo[], int tTipo);
int Tipo_ConMasProductosElaborados(eProducto pListaProductos[], int tProducto, eTipoProducto pListaTipo[], int tTipo);
void aux_ContadorTipo(eProducto pListaProductos[], int tProducto, eAuxiliar auxiliar[], eTipoProducto pListaTipo[], int tTipo);
int aux_calcularMaximo(eAuxiliar auxiliar[], int tAuxiliar);
int Producto_BuscarIdAux(eAuxiliar auxiliar[], int tAuxiliar, int id);
void aux_MostrarTipoMayor(eAuxiliar auxiliar[], eTipoProducto pListaTipo[], int tTipo, int maximo);

void aux_InicializarNacional(eAuxiliar auxiliar[], eNacionalidad pListaNacionalidad[], int tNacionalidad);
void aux_ContadorNacionalidad(eProducto pListaProducto[], int tProducto, eAuxiliar auxiliar[], eNacionalidad pListaNacionalidad[], int tNacionalidad);
int aux_CalcularMayor(eAuxiliar auxiliar[], eNacionalidad pListaNacionalidad[], int tNacionalidad);
void aux_MostrarNacionalidadMayor(eAuxiliar auxiliar[], eNacionalidad pListaNacionalidad[], int tNacionalidad, int mayor);


//*********************
int Producto_BuscarIdNacionalidad(eProducto pListaProductos[], int tProducto, int id);
int Nacionalidad_ConMasTipoProducto(eProducto pListaProductos[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad);

//*********************
int Nacionalidad_Eliminar(eProducto pListaProducto[], int tProducto, eNacionalidad pListaNacionalidad[], int tNacionalidad);

int Tipo_Eliminar(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo);

int Nacionalidad_MostrarPromedio(eProducto pListaProducto[], int tProducto, eNacionalidad pListaNacionalidad[], int tNacionalidad);

float Nacionalidad_CalcularPromedio(eProducto pListaProducto[], int tProducto, eNacionalidad pListaNacionalidad[], int tNacionalidad, int tipo);

int Nacionalidad_MostrarNacionalidadConMasTipo(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad);

int Nacionalidad_ConMasTipo(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad, int tipo);

int Nacionalidad_MostrarProductos(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad);

void Nacionalidad_OrdenarAlfabeticamente(eProducto pListaProducto[], int tProducto, eNacionalidad pListaNacionalidad[], int tNacionalidad);

int Tipo_MostrarTipoConMasProducto(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo);

int Nacionalidad_SoloFabricaIphone(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad);

int Tipo_MostrarProductos(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo);

int Producto_MostrarConDescripcion(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo);

float Tipo_CalcularPromedio(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo);

int Producto_CalcularMasCaro(eProducto pListaProducto[], int tProducto);

void Producto_OrdenarDescripcion(eProducto pListaProducto[], int tProducto);

void Producto_OrdenarPrecio(eProducto pListaProducto[], int tProducto);

int Producto_Modificar(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo);

eProducto Producto_PedirDatos(eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalida);

int Producto_Cargar(eProducto pListaProducto[], int tProducto, eTipoProducto pListaTipo[], int tTipo, eNacionalidad pListaNacionalidad[], int tNacionalidad);

#endif /* CLASE9_12_04_H_ */
