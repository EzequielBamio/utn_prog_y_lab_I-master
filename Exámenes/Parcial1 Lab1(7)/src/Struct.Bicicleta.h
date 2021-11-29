

#ifndef STRUCT_BICICLETA_H_
#define STRUCT_BICICLETA_H_
#define MAX_CHARS_BICICLETA 25
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct
{
	int id;
	char marca[MAX_CHARS_BICICLETA];
	int rodado;
	char color[MAX_CHARS_BICICLETA];
	int isEmpty;

} eBicicleta;
/**
 * @fn void eBicicleta_ValidarId(eBicicleta[], int, char[], int*)
 * @brief Busca la id menor y mayor, cuando lo encuentra pide el numero con rango
 *
 * @param pListaBicicleta. Array de bicicletas con el tipo de dato eBicicletas
 * @param tBicicleta. Tamanio del array
 * @param mensaje. Mensaje que se usa en la funcion pedir numero
 * @param pResultado. Puntero donde se va a guardar el numero ingresado
 */
void eBicicleta_ValidarId(eBicicleta pListaBicicleta[], int tBicicleta, char mensaje[], int* pResultado);
/**
 * @fn int eBicicleta_BuscarPorID(eBicicleta[], int, int)
 * @brief Busca el id ingresado por parametro con el id del array de bicicletas
 *
 * @param pListaBicicleta. Array de bicicletas con el tipo de dato eBicicletas
 * @param tBicicleta. Tamanio del array
 * @param ID. id que ingresa por parametro para comparar con los id de bicicletas
 * @return devuelve la posicion de donde se cumplio la condicion o -1 si no hay se cumple la condicion
 */
int eBicicleta_BuscarPorID(eBicicleta pListaBicicleta[], int tBicicleta, int ID);
/**
 * @fn void eBicicleta_MostrarUno(eBicicleta)
 * @brief Muestra un servicio que el estado sea ocupado
 *
 * @param pListaBicicleta. Array de bicicletas con el tipo de dato eBicicletas
 */
void eBicicleta_MostrarUno(eBicicleta pListaBicicleta);
/**
 * @fn int eBicicleta_MostrarTodos(eBicicleta[], int)
 * @brief Muestra todos los bicicletas cargados que esten ocupados
 *
 * @param pListaBicicleta. Array de bicicletas con el tipo de dato eBicicletas
 * @param tBicicleta. Tamanio del array
 * @return devuelve 1 si hay servicio para mostrar, 0 si no hay bicicletas para mostrar
 */
int eBicicleta_MostrarTodos(eBicicleta pListaBicicleta[], int tBicicleta);

#endif /* STRUCT_BICICLETA_H_ */
