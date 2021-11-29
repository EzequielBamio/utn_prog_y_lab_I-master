#include <stdlib.h>
#include "eb_INPUT.h"

#ifndef eVuelos_H_INCLUDED
#define eVuelos_H_INCLUDED

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    eFecha fecha;
    char destino[ARRAY_SIZE];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

}eVuelos;

eVuelos* eVuelos_new();
eVuelos* eVuelos_newParametros(char* idVueloStr, char* idAvionStr, char* idPilotoStr, char* fechaStr, char* destinoStr, char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr);

int eVuelos_setIdVuelo(eVuelos* this,int id);
int eVuelos_getIdVuelo(eVuelos* this,int* id);

int eVuelos_setIdAvion(eVuelos* this,int id);
int eVuelos_getIdAvion(eVuelos* this,int* id);

int eVuelos_setIdPiloto(eVuelos* this,int id);
int eVuelos_getIdPiloto(eVuelos* this,int* id);


int eVuelos_setAnio(eVuelos* this,int anio);
int eVuelos_getAnio(eVuelos* this, int* anio);

int eVuelos_setMes(eVuelos* this,int mes);
int eVuelos_getMes(eVuelos* this, int* mes);

int eVuelos_setDia(eVuelos* this,int dia);
int eVuelos_getDia(eVuelos* this, int* dia);


int eVuelos_setDestino(eVuelos* this,char* destino);
int eVuelos_getDestino(eVuelos* this,char* destino);

int eVuelos_setCantPasajeros(eVuelos* this,int cantPasajeros);
int eVuelos_getCantPasajeros(eVuelos* this,int* cantPasajeros);

int eVuelos_setHoraDespegue(eVuelos* this,int horaDespegue);
int eVuelos_getHoraDespegue(eVuelos* this,int* horaDespegue);

int eVuelos_setHoraLlegada(eVuelos* this,int horaLlegada);
int eVuelos_getHoraLlegada(eVuelos* this,int* horaLlegada);


int eVuelos_IDincrease(int* id);

#endif // eVuelos_H_INCLUDED
