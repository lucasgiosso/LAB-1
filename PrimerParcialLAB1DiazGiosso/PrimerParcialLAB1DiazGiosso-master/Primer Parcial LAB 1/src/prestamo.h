/*
 * prestamo.h
 *
 *  Created on: 16 may. 2020
 *      Author: lucasgiosso
 */

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

int inicializarPrestamo(ePrestamo* prestamo, int tam);
int buscarPrestamoLibre(ePrestamo* prestamo, int tam);
int buscarPrestamoXId(ePrestamo* prestamo, int tam, int IdCliente);
int imprimirPrestamos(ePrestamo* prestamo,int tamPrestamo, eClientes,tamClientes);


int informePrestamos(ePrestamo* prestamo, int tam);

#endif /* PRESTAMO_H_ */
