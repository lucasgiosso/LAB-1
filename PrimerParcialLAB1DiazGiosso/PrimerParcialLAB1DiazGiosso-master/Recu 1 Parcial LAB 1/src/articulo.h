/*
 * articulo.h
 *
 *  Created on: 1 jul. 2020
 *      Author: lucasgiosso
 */
#include "rubro.h"

#ifndef ARTICULO_H_
#define ARTICULO_H_

typedef struct
{
    int idArticulo;
    char articulo[50];
    int medida;
    float precio;
    int rubroId;
    int isEmptyArticulo;
    float precioTotal;

}eArticulo;

void hardcodeoArticulo(eArticulo pArticulo[], int posicion,int idArticulo, int medida, int precio, int rubroId, char articulo[]);
int inicializarArticulo(eArticulo pArticulo[], int tamArticulo);
int existeArticulo(eArticulo pArticulo[], int tamArticulo);
int buscarArticuloLibre(eArticulo pArticulo[], int tamArticulo, int* posicion);
int buscarIndiceArticulo(eArticulo pArticulo[], int tamArticulo);
int buscarArticuloPorId(eArticulo pArticulo[], int tamArticulo, int IdArticulo, int* posicion);
int altaArticulo(eArticulo pArticulo[], int tamArticulo, eRubro pRubro[],int tamRubro, int* idProximoArticulo);
int modificarArticulo(eArticulo pArticulo[],int tamArticulo);
int bajaArticulo(eArticulo pArticulo[],int tamArticulo);
int listarArticulos(eArticulo pArticulo[],int tamArticulo);
int ordenarArticuloPorRubroYDescripcion(eArticulo pArticulo[],int tamArticulo, int orden);

#endif /* ARTICULO_H_ */
