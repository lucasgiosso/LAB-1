/*
 * ventas.h
 *
 *  Created on: 21 jun. 2020
 *      Author: lucasgiosso
 */

#ifndef ARTICULOS_H_
#define ARTICULOS_H_

typedef struct
{
	int id;
	char articulo[128];
	char medida[128];
	float precio;
	int rubroId;

}eArticulo;

eArticulo* articulos_new();
eArticulo* articulos_newParametros(char* id,char* articulo,char* precio,char* medida, char* rubroId);
int articulos_setId(eArticulo* this, int id);
int articulos_getId(eArticulo* this, int* id);
int articulos_setArticulo(eArticulo* this, char* articulo);
int articulos_getArticulo(eArticulo* this, char* articulo);
int articulos_setMedida(eArticulo* this, char* medida);
int articulos_getMedida(eArticulo* this, char* medida);
int articulos_setPrecio(eArticulo* this, float precio);
int articulos_getPrecio(eArticulo* this, float* precio);
int articulos_setRubroId(eArticulo* this, int rubroId);
int articulos_getRubroId(eArticulo* this, int* rubroId);
int controller_mapArticulos(void* Articulos);

int mayorACien(void* ventas);
int cantCuidado(void* ventas);
#endif /* ARTICULOS_H_ */


