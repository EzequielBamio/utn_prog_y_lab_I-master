
#ifndef UTNMATH_H_
#define UTNMATH_H_
/**
 * @fn float Sumar(float, float)
 * @brief Suma ambos numeros
 *
 * @param x primer numero ingresado
 * @param y segundo numero ingresado
 * @return retorna el resultado de la suma
 */
float Sumar(float x, float y);
/**
 * @fn float Restar(float, float)
 * @brief Resta ambos numeros
 *
 * @param x primer numero ingresado
 * @param y segundo numero ingresado
 * @return retorna el resultado de la resta
 */
float Restar(float x, float y);
/**
 * @fn float Multiplicar(float, float)
 * @brief Multiplica ambos numeros
 *
 * @param x primer numero ingresado
 * @param y segundo numero ingresado
 * @return retorna el resultado de la multiplicacion
 */
float Multiplicar(float x, float y);
/**
 * @fn int Factorial(float)
 * @brief Recibe un numero, si es decimal, la operacion no se puede hacer.
 *
 * @param x numero para realizar el factorial
 * @return retorna el factorial del numero o -1 si el numero no es entero
 */
int Factorial(float x);
/**
 * @fn float Dividir(float, float)
 * @brief Divide 2 numeros, si es que el segundo numero ingresado es distinto a 0
 *
 * @param x primer numero ingresado por el usuario
 * @param y segundo numero ingresado por el usuario
 * @return retorna el resultado de la division o si "y" es 0 devuelve -1001, la division no se puede hacer.
 */
float Dividir(float x, float y);

#endif /* UTNMATH_H_ */
