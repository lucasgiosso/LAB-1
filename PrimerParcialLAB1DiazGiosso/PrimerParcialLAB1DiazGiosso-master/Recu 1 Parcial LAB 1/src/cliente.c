/*
 * cliente.c
 *
 *  Created on: 1 jul. 2020
 *      Author: lucasgiosso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"

#define LIBRE 1
#define OCUPADO 0

void hardcodeoCliente(eCliente clientes[], int idCliente, char nombre[], char telefono[], int posicion)
{
	clientes[posicion].idCliente = idCliente;
    strcpy(clientes[posicion].nombre, nombre);
    strcpy(clientes[posicion].telefono, telefono);
    clientes[posicion].isEmptyCliente = OCUPADO;
}

int inicializarClientes(eCliente cliente[], int tamCliente)
{
    int respuesta = -1;
    int i;

	if(cliente != NULL && tamCliente > 0)
	{
		for(i = 0; i < tamCliente; i++)
		{
			cliente[i].isEmptyCliente = LIBRE;
		}
	}
	    return respuesta;
}

int checkearClientes(eCliente cliente[], int tamCliente)
{
	int answer = -1;
	int i;

	for(i = 0; i < tamCliente; i++)
	{
		if(cliente[i].isEmptyCliente == 0)
		{
			answer = 0;
		}
	}
	return answer;
}

int listarClientes(eCliente cliente[],int tamCliente)
{
	int respuesta = -1;

	if(cliente != NULL && tamCliente > 0)
	{
		for(int i = 0; i< tamCliente ; i++)
		{
				if(cliente[i].isEmptyCliente == OCUPADO)
				{
					printf("\nID Cliente: %2d \tNombre Cliente: %8s \tTelefono: %10s",
							cliente[i].idCliente,cliente[i].nombre,cliente[i].telefono);
					respuesta = 0;

				}
		}
	}
	return respuesta;
}

int buscarClientePorId(eCliente cliente[], int tam, int IdCliente)
{
	int respuesta = -1;

	for(int i = 0; i < tam; i++)
	{
		if(cliente[i].idCliente == IdCliente && cliente[i].isEmptyCliente == OCUPADO)
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
