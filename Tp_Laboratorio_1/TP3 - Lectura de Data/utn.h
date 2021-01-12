/*
 * utn.h
 *
 *  Created on: 6 jun. 2020
 *      Author: lucasgiosso
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int isValidTexto(char* stringRecibido);
int getString_text(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);

#endif /* UTN_H_ */
