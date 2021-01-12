/*
 * funcionestp.h
 *
 *  Created on: 12 abr. 2020
 *      Author: lucasgiosso
 */

#ifndef FUNCIONESTP_H_
#define FUNCIONESTP_H_

/* 		\ Brief. Pide un numero
 * 		\ param  char mensaje a mostrar
 *  	\ param char mensaje a mostrar de error
 *  	\ param int limite minimo para la eleccion del menu
 *  	\ param int limite maximo para la eleccion del menu
 *  	\ param int reintentos del usuario al pedir un numero
 * 		\ return Devuelve el numero
  */


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** 		\Brief Pide una cadena de caracteres
 * 			\ param char mensaje a mostrar
 * 			\ param char cadena que se ingresa
 * 			\ return void
 */


void getString(char mensaje[], char cadena[]);


/** 		\ Brief Pide una cadena de caracteres y lo devuelve
 *			\ param char mensaje a mostrar
 *			\ param char cadena que se ingresa
 * 			\ return 1 si el texto contiene solo numeros
 */


int getStringNumeros(char mensaje[],char cadena[]);


/**		\ Brief Pide un entero
 * 			\ param char mensaje a mostrar
 * 			\ param int numero que se ingresa
 * 			\ param int minimo
 *			\ param int maximo
 *			\ return Devuelve el numero ingresado
 */


int getInt(char mensaje[],int numero, int min, int max);


/**		\ Brief Verifica si el valor recibido es numero
 * 			\ param str Array a ser analizado
 * 			\ return 1 si es numero, 0 si no lo es
 */


int esNumerico(char str[]);



// Operaciones

/*		\ Brief.  Int Suma los numeros
 * 		\ param  int primer numero
 * 		\ param int segundo numero
 * 		\ return Suma de los numeros
 */


int sumar(int x, int y);

/*		\ Brief.  Int Resta los numeros
 * 		\ param  int primer numero
 * 		\ param int segundo numero
 * 		\ return Resta de los numeros
 */


int restar ( int x, int y);


/*		\ Brief.  Int Multiplica los numeros
 * 		\ param  int multiplicando
 * 		\ param int multiplicador
 * 		\ return producto
 */

int multiplicar (int x, int y);


/*		\ Brief.  Int Divide los numeros
 * 		\ param  int dividendo
 * 		\ param int divisor
 * 		\ return cociente
 */

float dividir (int x, int y);


/*		\ Brief.  long Pide un número para factorearlo
 * 		\ param  int factorea el numero
 * 		\ return numero factoreado
 */


long factorial (int x);

#endif /* FUNCIONESTP_H_ */
