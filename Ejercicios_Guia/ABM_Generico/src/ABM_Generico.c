#include "Struct.gen.h"
#include "utn.Get.h"
#define SIZE_ESTRUCTURA 5

int main(void)
{

	setbuf(stdout, NULL);

	int opcion;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eGen Gen[SIZE_ESTRUCTURA];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eGen_Inicializar(Gen, SIZE_ESTRUCTURA);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		//Menu();
		utn_getNumero(&opcion, "INGRESE OPCION: ", 0, 5);

		//MENU SWITCH
		switch (opcion)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opcion = 0;
			break;
		case 1:
			//ALTA
			if (eGen_Alta(Gen, SIZE_ESTRUCTURA)) {
				puts(" * Gen DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Gen");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (eGen_Baja(Gen, SIZE_ESTRUCTURA)) {
				puts("\n * BAJA DE Gen EXITOSA");
				eGen_MostrarTodos(Gen, SIZE_ESTRUCTURA);
			} else {
				puts("\n * BAJA DE Gen CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//MODIFICACION
			if (eGen_Modificacion(Gen, SIZE_ESTRUCTURA)) {
				puts("\n * MODIFICACION DE Gen EXITOSA\n");
				eGen_MostrarTodos(Gen, SIZE_ESTRUCTURA);
			} else {
				puts("\n * MODIFICACION DE Gen CANCELADA");
			}
			system("pause");
			break;
		case 4:
			//LISTADO Gen
			eGen_MostrarTodos(Gen, SIZE_ESTRUCTURA);
			system("pause");
			break;
		case 5:
			//ORDENAR Gen
			criterioDeOrdenamiento = 1; //PEDIR CRITERIO DE ORDENAMIENTO
			eGen_Ordenamiento(Gen, SIZE_ESTRUCTURA, criterioDeOrdenamiento);
			system("pause");
			break;
		}
	} while (opcion != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
