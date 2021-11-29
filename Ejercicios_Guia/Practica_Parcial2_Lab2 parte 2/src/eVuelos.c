
#include <string.h>
#include "inc/Vuelos.h"
#include "inc/parser.h"
#include "inc/Pilotos.h"
#include "inc/Aviones.h"
#include "inc/eb_INPUT.h"

eVuelos* eVuelos_new()
{
	eVuelos* pVuelo;

	pVuelo = (eVuelos*) malloc(sizeof(eVuelos));

	return pVuelo;
}

eVuelos* eVuelos_newParametros(char* idVueloStr, char* idAvionStr, char* idPilotoStr, char* FechaStr, char* destinoStr, char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr)
{
	 eVuelos* pAuxVuelo;
	 int fDia;
	 int fMes;
	 int fAnio;
	 pAuxVuelo = eVuelos_new();

	 if(pAuxVuelo != NULL)
	 {
		 parser_Fecha(FechaStr, &fDia, &fMes, &fAnio);
		 eVuelos_setIdVuelo(pAuxVuelo, atoi(idVueloStr));
		 eVuelos_setIdAvion(pAuxVuelo, atoi(idAvionStr));
		 eVuelos_setIdPiloto(pAuxVuelo, atoi(idPilotoStr));
		 eVuelos_setDia(pAuxVuelo, fDia);
		 eVuelos_setMes(pAuxVuelo, fMes);
		 eVuelos_setAnio(pAuxVuelo, fAnio);
		 eVuelos_setDestino(pAuxVuelo, destinoStr);
		 eVuelos_setCantPasajeros(pAuxVuelo, atoi(cantPasajerosStr));
		 eVuelos_setHoraDespegue(pAuxVuelo, atoi(horaDespegueStr));
		 eVuelos_setHoraLlegada(pAuxVuelo, atoi(horaLlegadaStr));
	 }

	 return pAuxVuelo;
}

int eVuelos_delete(eVuelos* this)
{
	int rtn;
	rtn = FALSE;
	if(this != NULL)
	{
		free(this);
		rtn = TRUE;
	}

	return rtn;
}

//
int eVuelos_setIdVuelo(eVuelos* this,int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		this->idVuelo = id;
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getIdVuelo(eVuelos* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		*id = this->idVuelo;
		rtn = TRUE;
	}

	return rtn;
}
//
int eVuelos_setIdAvion(eVuelos* this,int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		this->idAvion = id;
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getIdAvion(eVuelos* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		*id = this->idAvion;
		rtn = TRUE;
	}

	return rtn;
}
//
int eVuelos_setIdPiloto(eVuelos* this,int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		this->idPiloto = id;
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getIdPiloto(eVuelos* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		*id = this->idPiloto;
		rtn = TRUE;
	}

	return rtn;
}
//
int eVuelos_setAnio(eVuelos* this,int anio)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL )
	{
		this->fecha.anio = anio;
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getAnio(eVuelos* this, int* anio)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*anio = this->fecha.anio;
		rtn = TRUE;
	}

	return rtn;
}
//
int eVuelos_setMes(eVuelos* this,int mes)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL )
	{
		this->fecha.mes = mes;
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getMes(eVuelos* this, int* mes)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*mes = this->fecha.mes;
		rtn = TRUE;
	}

	return rtn;
}
//
int eVuelos_setDia(eVuelos* this,int dia)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL )
	{
		this->fecha.dia = dia;
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getDia(eVuelos* this, int* dia)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*dia = this->fecha.dia;
		rtn = TRUE;
	}

	return rtn;
}
//
int eVuelos_setDestino(eVuelos* this,char* destino)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(this->destino, destino);
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getDestino(eVuelos* this,char* destino)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		strcpy(destino, this->destino);
		rtn = TRUE;
	}

	return rtn;
}
//
int eVuelos_setCantPasajeros(eVuelos* this,int cantPasajeros)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && cantPasajeros > 0)
	{
		this->cantPasajeros = cantPasajeros;
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getCantPasajeros(eVuelos* this,int* cantPasajeros)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && cantPasajeros > 0)
	{
		*cantPasajeros = this->cantPasajeros;
		rtn = TRUE;
	}

	return rtn;
}
//
int eVuelos_setHoraDespegue(eVuelos* this,int horaDespegue)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && horaDespegue > 0)
	{
		this->horaDespegue = horaDespegue;
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getHoraDespegue(eVuelos* this,int* horaDespegue)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && horaDespegue > 0)
	{
		*horaDespegue = this->horaDespegue;
		rtn = TRUE;
	}

	return rtn;
}
//
int eVuelos_setHoraLlegada(eVuelos* this,int horaLlegada)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && horaLlegada > -1)
	{
		this->horaLlegada = horaLlegada;
		rtn = TRUE;
	}

	return rtn;
}
int eVuelos_getHoraLlegada(eVuelos* this,int* horaLlegada)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && *horaLlegada > -1)
	{
		*horaLlegada = this->horaLlegada;
		rtn = TRUE;
	}

	return rtn;
}

//---------------------------------------\ * /----------------------------------------//

int eVuelos_IDincrease(int* id)
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return *id += 1;
}
