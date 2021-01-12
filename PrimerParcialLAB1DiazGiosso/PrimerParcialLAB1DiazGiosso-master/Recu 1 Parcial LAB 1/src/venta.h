/*
 * venta.h
 *
 *  Created on: 1 jul. 2020
 *      Author: lucasgiosso
 */

#ifndef VENTA_H_
#define VENTA_H_

#include "cliente.h"
#include "articulo.h"

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int idVenta;
    int clienteId;
    int articuloId;
    int cantidad;
    float precioTotal;
    eFecha fecha;
    int isEmptyVenta;

}eVenta;

void hardcodeoVenta(eVenta pVenta[], int articuloId, int dia, int mes, int anio, int cantidad, int clienteId, int idVenta, float precioTotal,int posicion);
int inicializarVenta(eVenta pVenta[],int tamVenta);
int buscarVentaLibre(eVenta pVenta[], int tamVenta, int* posicion);
int buscarIndiceVenta(eVenta pVenta[], int tamVenta);
int buscarVentaPorId(eVenta pVenta[], int tamVenta, int IdVenta, int* posicion);
int altaVenta(eVenta venta[],int tamVenta,eArticulo articulo[], int tamArticulo,eCliente clientes[],int tamClientes, int* idProximaVenta);
int listarVentas(eVenta pVenta[],int tamVenta);

#endif /* VENTA_H_ */
