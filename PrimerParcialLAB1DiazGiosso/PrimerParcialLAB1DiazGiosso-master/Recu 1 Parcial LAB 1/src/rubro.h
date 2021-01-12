/*
 * rubro.h
 *
 *  Created on: 1 jul. 2020
 *      Author: lucasgiosso
 */

#ifndef RUBRO_H_
#define RUBRO_H_

typedef struct
{
    int idRubro;
    char descripcion[30];
    int isEmptyRubro;

}eRubro;

void hardcodeoRubro(eRubro pRubro[], int idRubro, char descripcion[], int posicion);
void inicializarRubro(eRubro pRubro[], int tamRubro);
int buscarRubroxId(eRubro pRubro[], int idBuscado, int tamBuscado, char* nombreRubro);
void mostrarRubro(eRubro pRubro);
void mostrarRubros(eRubro pRubro[], int tamRubro);
int listarRubros(eRubro pRubro[],int tamRubro);

#endif /* RUBRO_H_ */
