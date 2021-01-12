/*
 * cliente.h
 *
 *  Created on: 16 may. 2020
 *      Author: lucasgiosso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int idCliente;
	char nombreCliente[51];
	char apellidoCliente[51];
	char cuilCliente[51];
	int prestamoActivoCliente;
	int prestamosSaldoCliente;
	int isEmptyCliente;

}eClientes;

int menu();
int inicializarCliente(eClientes* clientes, int tam);
int imprimirClientes(eClientes* clientes, int tam);
int buscarClienteLibre(eClientes* clientes, int tam);
int buscarClienteXId(eClientes* clientes, int tam, int IdCliente);
int proximoIdCliente(eClientes* clientes, int tam);
int altaCliente(eClientes* clientes, int tam);
int menuModificarCliente();
int modificarCliente(eClientes* clientes, int tam);
int bajaCliente(eClientes* clientes, int tam);
int informeClientes(eClientes* clientes, int tam);


#endif /* CLIENTE_H_ */
