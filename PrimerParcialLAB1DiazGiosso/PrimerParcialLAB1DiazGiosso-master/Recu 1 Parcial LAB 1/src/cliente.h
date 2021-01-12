/*
 * cliente.h
 *
 *  Created on: 1 jul. 2020
 *      Author: lucasgiosso
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
    int idCliente;
    char nombre[25];
    char telefono[25];
    int isEmptyCliente;
    float precioTotal;


}eCliente;

void hardcodeoCliente(eCliente clientes[], int idCliente, char nombre[], char telefono[], int posicion);
int inicializarClientes(eCliente list[], int longitud);
int listarClientes(eCliente cliente[],int tamCliente);
int buscarClientePorId(eCliente cliente[], int tam, int IdCliente);
#endif /* CLIENTE_H_ */
