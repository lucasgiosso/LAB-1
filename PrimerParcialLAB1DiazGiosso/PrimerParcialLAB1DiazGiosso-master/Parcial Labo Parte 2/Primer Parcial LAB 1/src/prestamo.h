/*
 * prestamo.h
 *
 *  Created on: 16 may. 2020
 *      Author: lucasgiosso
 */

#include "cliente.h"

#ifndef PRESTAMO_H_
#define PRESTAMO_H_

typedef struct
{
	int idCliente;
	int idPrestamo;
	float importePrestamo;
	int cantCuotasPrestamo;
	char situacionPrestamo[51];
	int isEmptyPrestamo;

}ePrestamo;

int inicializarPrestamo(ePrestamo* prestamo, int tamPrestamo);
int buscarPrestamoLibre(ePrestamo* prestamo, int tamPrestamo);
int buscarPrestamoXId(ePrestamo* prestamo, int tamPrestamo, int IdCliente);
int altaPrestamo(ePrestamo* prestamo, int tamPrestamo,int* buscarId, eClientes* clientes,int tamClientes);
int imprimirPrestamos(ePrestamo* prestamo,int tamPrestamo, eClientes* clientes, int tamClientes);
int informePrestamos(ePrestamo* prestamo, int tamPrestamo);

#endif /* PRESTAMO_H_ */
