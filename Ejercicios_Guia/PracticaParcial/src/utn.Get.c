#include "utn.Get.h"


int Confirmar_Respuesta(char mensaje[])
{
	int rtn;
	rtn = 0;

	utn_getNumero(&rtn, mensaje, 0, 1);

	if(rtn == 1)
	{
		rtn = 1;
	}

	return rtn;
}

void get_Tipo(char pTipo[], char mensaje[])
{
	int auxiliar;
	utn_getNumero(&auxiliar, mensaje, 1, 3);

	switch(auxiliar)
	{
	case 1:
		strcpy(pTipo, "Perro");
		break;
	case 2:
		strcpy(pTipo, "Gato");
		break;
	case 3:
		strcpy(pTipo, "Raro");
		break;
	}

}

void get_Sexo(char* pSexo, char mensaje[])
{
	int auxiliar;
	utn_getNumero(&auxiliar, mensaje, 0, 1);

	if(auxiliar == 1)
	{
		*pSexo = 'M';
	}else
	{
		*pSexo = 'F';
	}

}


void get_Descripcion(char pResultado[], int tResultado, char mensaje[])
{
	char cadenaString[1000];
	int maximosCharParaVerificar = tResultado;

	myGets(cadenaString, tResultado, mensaje);

	while(strlen(cadenaString)>maximosCharParaVerificar||strlen(cadenaString)<1)
	{
		printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE DESCRIPCION: ", maximosCharParaVerificar-1);
		fflush(stdin);
		gets(cadenaString);
	}
	strlwr(cadenaString);//PASO TODO A MINUSCULA
	cadenaString[0]=toupper(cadenaString[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
	strcpy (pResultado, cadenaString);//DESCARGO EL BUFFER EN EL NOMBRE

}


void get_Nombre(char* nombre, int tResultado, char mensaje[])
{
    char cadenaString[1000];
    int maximosCharParaVerificar = tResultado;

    myGets(cadenaString, tResultado, mensaje);

    while(strlen(cadenaString) > maximosCharParaVerificar|| strlen(cadenaString) < 1)
    {
        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE NOMBRE: ", maximosCharParaVerificar-1);
        fflush(stdin);
        gets(cadenaString);

    }

    strlwr(cadenaString);//PASO TODO A MINUSCULA
    cadenaString[0]=toupper(cadenaString[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    strcpy (nombre, cadenaString);//DESCARGO EL BUFFER EN EL NOMBRE
}


void get_Apellido(char* apellido, int TAM)
{
    char buffer[1000];
    int maximosCharParaVerificar = TAM;

    printf("INGRESE APELLIDO: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>maximosCharParaVerificar||strlen(buffer)<1)
    {
        system("cls");
        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE APELLIDO: ", maximosCharParaVerificar-1);
        fflush(stdin);
        gets(buffer);

    }
    strlwr(buffer);//PASO TODO A MINUSCULA
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    strcpy (apellido, buffer);//COMO SALI DESCARGO EL BUFFER EN EL NOMBRE

}


void concatenar_NombreApellido(char nombreCompleto[], char cadenaApellido[], char cadenaNombre[])
{
    int i;

    /** FORMATO "Apellido, Nombre" */

    strcpy(nombreCompleto, cadenaApellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, cadenaNombre);

    strlwr(nombreCompleto); //CONVIERTE TODA LA CADENA A MINUSCULA

    nombreCompleto[0]=toupper(nombreCompleto[0]);

    for(i=0; i<strlen(nombreCompleto); i++)
    {
        if (isspace(nombreCompleto[i])) //(nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);//PASA EN MAYUSCULA EL CARACTER DESPUES DEL ESPACIO
        }
    }
}


void getChar(char* letra, char mensaje[])
{
    char cadenaString[1000];

    myGets(cadenaString, 100, mensaje);


    while(strlen(cadenaString)!=1)
    {
        myGets(cadenaString, 100, "[ERROR]SOLO UNA LETRA. REINGRESE: ");
    }
    cadenaString[0] = toupper(cadenaString[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    *letra = cadenaString[0];

}


void myGets(char pResultado[], int tResultado, char mensaje[])
{
	char cadenaString[1000];
	int maximosCharParaVerificar = tResultado;

		printf("%s",mensaje);
	    fflush(stdin);
	    gets(cadenaString);

	    while(strlen(cadenaString) > maximosCharParaVerificar || strlen(cadenaString) < 1)
	    {
	        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE NOMBRE: ", maximosCharParaVerificar);
	        fflush(stdin);
	        gets(cadenaString);
	    }
		strncpy(pResultado, cadenaString, tResultado);

//	char cadenaString[1000];
//
//	if(pResultado != NULL && tResultado > 0)
//	{
//		fflush(stdin);
//		printf("%s",mensaje);
//
//		if(fgets(cadenaString,sizeof(cadenaString),stdin) != NULL)
//		{
//			if(cadenaString[strnlen(cadenaString, sizeof(cadenaString))-1] == '\n')
//			{
//				cadenaString[strnlen(cadenaString, sizeof(cadenaString))-1] = '\0';
//			}
//			if(strnlen(cadenaString, sizeof(cadenaString)) < tResultado)
//			{
//				strncpy(pResultado, cadenaString, tResultado);
//			}
//		}
//	}
}




int esCaracter(char pResultado[])
{
	int i;
	int rtn;
	rtn = 1;

	if(strlen(pResultado) > 0)
	{
		for(i = 0; strlen(pResultado) > 0; i++)
		{
			if(isalpha(pResultado[i]) == 0)
			{
				rtn = 0;
				break;
			}
		}
	}else
	{
		rtn = 0;
	}

	return rtn;
}


int esCaracterConEspacio(char pResultado[])
{
	int i;
	int rtn;
	rtn = 1;

	if(strlen(pResultado) > 0)
	{
		for(i = 0; strlen(pResultado) > 0; i++)
		{
			if(isalpha(pResultado[i]) == 0)
			{
				if(isspace(pResultado[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}else
	{
		rtn = 0;
	}

	return rtn;
}


void getInt(int* pResultado, char mensaje[])
{
    char cadenaString[50];

    myGets(cadenaString, sizeof(cadenaString), mensaje);

    while(esNumerica(cadenaString) == 0)
	{
    	printf("ERROR: Eso no es un numero.\n");
    	fflush(stdin);
        myGets(cadenaString, sizeof(cadenaString), mensaje);
	}

	*pResultado = atoi(cadenaString);
}


int esNumerica(char pResultado[])
{
	int i;
	int rtn;
	rtn = 1;
	if (strlen(pResultado) > 0)
	{
		for(i = 0; i < strlen(pResultado); i++)
		{
			if (isdigit(pResultado[i]) == 0)
			{
				if (i == 0)
				{
					if (pResultado[0] != '-')
					{
						rtn = 0;
						break;
					}
				}else
				{
					rtn = 0;
					break;
				}
			}
		}
	}else
	{
		rtn = 0;
	}
	return rtn;
}


void utn_getNumero(int* pResultado, char mensaje[], int minimo, int maximo)
{
	int numeroIngresado;

	getInt(&numeroIngresado, mensaje);
	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR: El numero %d esta fuera del rango -> Minimo = %d Maximo = %d.\n", numeroIngresado ,minimo, maximo);
		getInt(&numeroIngresado, mensaje);
	}

	*pResultado = numeroIngresado;

}


void getFloat(float* pResultado, char mensaje[])
{
	char cadenaString[50];

    myGets(cadenaString, sizeof(cadenaString), mensaje);

	while(esFlotante(cadenaString) == 0)
	{
    	printf("ERROR: Eso no es un numero.\n");
    	fflush(stdin);
	    myGets(cadenaString, sizeof(cadenaString), mensaje);
	}

	*pResultado = atof(cadenaString);

}


int esFlotante(char pResultado[])
{
	int rtn;
	int i;
	int contadorSigno;

	contadorSigno = 0;
	rtn = 1; // VERDADERO

	if(strlen(pResultado) > 0){
		for(i = 0; i < strlen(pResultado); i++)
		{

			if(pResultado[i] == '.'|| pResultado[i] == ',')
			{
				contadorSigno++;
			}
			else
			{
				if(isdigit(pResultado[i]) == 0)
				{
					if(i == 0)
					{
						if(pResultado[0] != '-')
						{
							rtn = 0;
							break;
						}
					}else
					{
						rtn = 0;
						break;
					}
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


void utn_getNumeroFlotante(float* pResultado, char mensaje[], float minimo, float maximo)
{
	float numeroIngresado;

	getFloat(&numeroIngresado, mensaje);
	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("ERROR: El numero %.2f esta fuera del rango -> Minimo = %.2f Maximo = %.2f.\n", numeroIngresado ,minimo, maximo);
		getFloat(&numeroIngresado, mensaje);
	}

	*pResultado = numeroIngresado;

}
