/*
 ============================================================================
 Name        : Primer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <curses.h>
#include "cliente.h"
#include "utn.h"
#include "prestamo.h"

#define TAM_CLIENTES 1000

int main() {

	eClientes clientes [TAM_CLIENTES];

	inicializarCliente(clientes,TAM_CLIENTES);

	do
	{
		switch(menu())
		{
		case 1:

			altaCliente(clientes,TAM_CLIENTES);

			break;

		case 2:

			modificarCliente(clientes,TAM_CLIENTES);

			break;

		case 3:

			bajaCliente(clientes,TAM_CLIENTES);
			break;

		case 4:

			altaPrestamo(clientes,TAM_CLIENTES);

			break;

		case 5:

			saldarPrestamo(clientes,TAM_CLIENTES);

			break;

		case 6:

			reanudarPrestamo(clientes,TAM_CLIENTES);

			break;

		case 7:

			imprimirClientes(clientes,TAM_CLIENTES);

			break;

		case 8:

			imprimirPrestamos(clientes,TAM_CLIENTES);

			break;

		case 9:

			informeClientes(clientes,TAM_CLIENTES);

			break;

		case 10:

			informePrestamos(clientes,TAM_CLIENTES);

			break;

		}
	}while(menu() != 11);

	return 0;
}
