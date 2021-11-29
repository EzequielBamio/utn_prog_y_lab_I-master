/*
 * \fn int getIntValidacion(char mensajeIngreso[], char errorIngreso[], int maximo, int minimo)
 * \brief Muestra un mensaje y permite al usuario ingresar un número. Se valida que el numero este dentro de un rango determinado.
 * \param char mensajeIngreso[]: Mensaje de ingreso.
 * \param char errorIngreso[]: Mensaje en caso de error (número fuera de rango).
 * \param int maximo: Numero máximo permitido.
 * \param int minimo: Numero mínimo permitido.
 * \return int
 * */
int getIntValidacion(char mensajeIngreso[], char errorIngreso[], int maximo, int minimo);

/*
 * \fn long long int getInt(char mensajeIngreso[])
 * \brief Muestra un mensaje y permite al usuario ingresar un número.
 * \param char mensajeIngreso[]: Mensaje de ingreso.
 * \return long long int
 * */
long long int getInt(char mensajeIngreso[]);
