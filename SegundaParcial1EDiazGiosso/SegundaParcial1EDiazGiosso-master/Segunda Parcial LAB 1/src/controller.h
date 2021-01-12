/*
 * controller.h
 *
 *  Created on: 21 jun. 2020
 *      Author: lucasgiosso
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_ArticulosloadFromText(char* path, LinkedList* listaArticulos);
int orderByArticulo(void* art1, void* art2);
int controller_sortArticulo(LinkedList* listaArticulos);
int controller_printArticulos(LinkedList* listaArticulos);
int controller_ll_map(LinkedList* listaArticulos);
int controller_saveAsTextArticulo(char* path,LinkedList* listaArticulos);
int controller_informe(LinkedList* listaArticulos);

#endif /* CONTROLLER_H_ */


