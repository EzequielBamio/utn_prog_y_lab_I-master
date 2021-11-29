#include "utn.Get.h"

static int esNumerica(char* cadena, int limite);
static int esFlotante(char* cadena);


/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un maximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 1 (EXITO) si se obtiene una cadena y 0 (ERROR) si no
 *
 */
void myGets(char* cadena, int longitud, char* mensaje)
{
	char cadenaString[1000];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		printf("%s",mensaje);
		if(fgets(cadenaString,sizeof(cadenaString),stdin) != NULL)
		{
			if(cadenaString[strnlen(cadenaString, sizeof(cadenaString))-1] == '\n')
			{
				cadenaString[strnlen(cadenaString, sizeof(cadenaString))-1] = '\0';
			}
			if(strnlen(cadenaString, sizeof(cadenaString)) <= longitud)
			{
				strncpy(cadena, cadenaString, longitud);
			}
		}
	}
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 1 (EXITO) si se obtiene un numero entero y 0 (ERROR) si no
 *
 */
void getInt(int* pResultado, char* mensaje)
{
    char cadenaString[50];

    myGets(cadenaString, sizeof(cadenaString), mensaje);
    if(	pResultado != NULL && esNumerica(cadenaString, sizeof(cadenaString)))
	{
		*pResultado = atoi(cadenaString);
	}

}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int rtn = 1;
	int i;
	for(i=0;i < limite && cadena[i] != '\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(isdigit(cadena[i]) == 0)
		{
			rtn = 0;
			break;
		}
	}
	return rtn;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 1 si se obtuvo el numero y 0 si no
 *
 */
void utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int rtn;
	int numeroIngresado;
	rtn = 0;
	do
	{
		getInt(&numeroIngresado, mensaje);
		if(numeroIngresado >= minimo && numeroIngresado <= maximo)
		{
			rtn = 1;
			*pResultado = numeroIngresado;
			break;
		}
		printf("%s",mensajeError);
	}while(rtn != 1);

}


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 1 (EXITO) si se obtiene un numero flotante y 0 (ERROR) si no
 *
 */
void getFloat(float* pResultado, char* mensaje)
{
	char cadenaString[50];

    myGets(cadenaString, sizeof(cadenaString), mensaje);
	if(	pResultado != NULL && esFlotante(cadenaString))
	{
		*pResultado = atof(cadenaString);
	}

}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int rtn;
	int i;
	int contadorSigno;

	contadorSigno = 0;
	rtn = 1; // VERDADERO
	if(strlen(cadena) > 0){
		for(i = 0; i < strlen(cadena); i++)
		{

			if(cadena[i] == '.'|| cadena[i] == ',')
			{
				contadorSigno++;
			}
			else
			{
				if(isdigit(cadena[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
		if(contadorSigno > 1)
		{
			rtn = 0;
		}
		}else
		{
			rtn = 0;
		}
	return rtn;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 1 si se obtuvo el numero flotante y 0 si no
 *
 */
void utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo)
{
	float rtn;
	rtn = 0;
	float numeroIngresado;
	do
	{
	getFloat(&numeroIngresado, mensaje);
	if(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		*pResultado = numeroIngresado;
		rtn = 1;
	}
	printf("%s", mensajeError);

	}while(rtn != 1);
}





