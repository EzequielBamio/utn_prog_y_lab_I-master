/*
 * \fn long long int suma (long long int numeroUno, long long int numeroDos)
 * \brief Recibe dos números enteros, devuelve la suma de los mismos.
 * \param long long int numeroUno: Primer numero a sumarse.
 * \param long long int numeroDos: Segundo numero a sumarse.
 * \return long long int
 * */
long long int suma (long long int numeroUno, long long int numeroDos);

/*
 * \fn long long int resta (long long int numeroUno, long long int numeroDos)
 * \brief Recibe dos números enteros, devuelve la resta de los mismos.
 * \param long long int numeroUno: Primer numero a restarse.
 * \param long long int numeroDos: Segundo numero a restarse.
 * \return long long int
 * */
long long int resta (long long int numeroUno, long long int numeroDos);

/*
 * \fn long long int multiplicacion (long long int numeroUno, long long int numeroDos)
 * \brief Recibe dos números enteros, devuelve el producto de los mismos.
 * \param long long int numeroUno: Primer numero a multiplicarse.
 * \param long long int numeroDos: Segundo numero a multiplicarse.
 * \return long long int
 * */
long long int multiplicacion (long long int numeroUno, long long int numeroDos);

/*
 * \fn double division (long long int numeroUno, long long int numeroDos)
 * \brief Recibe dos números enteros, devuelve la division de los mismos. Si el dividendo es 0, devuelve inf.
 * \param long long int numeroUno: Dividendo.
 * \param long long int numeroDos: Divisor.
 * \return double
 * */
double division (double numeroUno, double numeroDos);

/*
 * \fn long long int factorial (long long int numero)
 * \brief Recibe un número entero. Si esta entre 0 y 20, devuelve su factorial. Sino, devuelve 0.
 * \param long long int numero: Numero a obtener factorial.
  * \return long long int
 * */
unsigned long long factorial(long long int numero);
