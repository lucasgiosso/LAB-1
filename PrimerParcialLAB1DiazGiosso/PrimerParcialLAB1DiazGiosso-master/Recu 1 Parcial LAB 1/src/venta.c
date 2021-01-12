/*
 * venta.c
 *
 *  Created on: 1 jul. 2020
 *      Author: lucasgiosso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "venta.h"
#include "articulo.h"

#define LIBRE 1
#define OCUPADO 0
#define TAM_ARTICULO 50
#define TAM_VENTA 50
#define TAM_CLIENTES 50

void hardcodeoVenta(eVenta pVenta[], int articuloId, int dia, int mes, int anio, int cantidad, int clienteId, int idVenta, float precioTotal,int posicion)
{	eFecha fecha;
	pVenta[posicion].articuloId = articuloId;
	pVenta[posicion].cantidad = cantidad;
	pVenta[posicion].clienteId = clienteId;
	fecha.dia=dia;
	fecha.mes=mes;
	fecha.anio=anio;
	pVenta[posicion].fecha = fecha;
	pVenta[posicion].idVenta = idVenta;
	pVenta[posicion].isEmptyVenta = 1;
	pVenta[posicion].precioTotal = precioTotal;

}

int inicializarVenta(eVenta pVenta[],int tamVenta)
{
	int respuesta = -1;
	int i;

	if(pVenta != NULL && tamVenta > 0)
	{
		for(i = 0; i < tamVenta; i++)
		{
			pVenta[i].isEmptyVenta = LIBRE;
		}
		respuesta = 0;
	}
	return respuesta;
}

int buscarVentaLibre(eVenta pVenta[], int tamVenta, int* posicion)
{
	int respuesta = -1;
	int i;

	if(pVenta != NULL && tamVenta > 0 && posicion != NULL )
	{
		for(i = 0; i < tamVenta; i++)
		{
			if(pVenta[i].isEmptyVenta == LIBRE)
			{
				respuesta = 0;
				*posicion = i;
				break;
			}
		}
	}
	return respuesta;
}

int buscarIndiceVenta(eVenta pVenta[], int tamVenta)
{
	int respuesta = -1;
	int i;

	if(pVenta != NULL && tamVenta > 0)
	{
		respuesta = 0;
		for(i = 0; i < tamVenta; i++)
		{
			if(pVenta[i].isEmptyVenta == LIBRE)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int buscarVentaPorId(eVenta pVenta[], int tamVenta, int IdVenta, int* posicion)
{
	int respuesta = -1;
	int i;

		if(pVenta != NULL && tamVenta > 0 && IdVenta >= 0)
		{
			for(i = 0; i < tamVenta; i++)
			{
				if(pVenta[i].idVenta == IdVenta)
				{
					*posicion = i;
					respuesta = 0;
					break;
				}
			}
		}
		return respuesta;
}

int altaVenta(eVenta pVenta[],int tamVenta, eArticulo pArticulo[], int tamArticulo, eCliente clientes[],int tamClientes, int* idProximaVenta)
{
	int retorno = -1;
	int idCliente = 0;
	int idArticulo = 0;
	int auxIdVenta = 0;
	//char fecha[50];
	int posicionVenta;
	int posicionArticulo;
	eFecha fecha;

	printf("\n\n<<<< Alta Venta >>>>\n");

	listarClientes(clientes,TAM_CLIENTES);

	if(pArticulo != NULL && tamArticulo > 0 && clientes != NULL && tamClientes > 0 && pVenta != NULL && tamVenta > 0)
	{
		if(buscarVentaLibre(pVenta,tamVenta,&posicionVenta) != -1)
		{
			utn_getNumero(&idCliente,"\n\nIngrese el id del cliente: ","Error\n",1,TAM_VENTA,2);

			if(buscarClientePorId(clientes,tamClientes,idCliente) != -1)
			{
				listarArticulos(pArticulo,TAM_ARTICULO);
				utn_getNumero(&idArticulo,"\n\nIngrese el id del articulo: ","Error\n",1,TAM_CLIENTES,2);

				if(buscarArticuloPorId(pArticulo,tamArticulo,idArticulo,&posicionArticulo) != -1)
				{
					pVenta[posicionVenta].articuloId = idArticulo;
					pVenta[posicionVenta].clienteId = idCliente;

					utn_getNumero(&pVenta[posicionVenta].cantidad,"\n\nIngrese la cantidad a ordenar: ","Error\n",1,1000,3);

					utn_getNumero(&fecha.dia,"\n\nIngrese el dia(numero): ","Error\n",1,31,3);

					utn_getNumero(&fecha.mes,"\n\nIngrese el mes: ","Error\n",1,12,3);

					utn_getNumero(&fecha.anio,"\n\nIngrese el año: ","Error\n",1,2025,3);

					pVenta[posicionVenta].fecha = fecha;

					/*utn_getTexto(fecha,"\n\nIngrese la fecha (XX-XX-XXXX): ","Error\n",0,20,3);
					strcpy(pVenta[posicionVenta].fecha,fecha);*/

					pVenta[posicionVenta].isEmptyVenta = 0;
					pVenta[posicionVenta].precioTotal = pArticulo[posicionArticulo].precio * pVenta[posicionVenta].cantidad;

					(*idProximaVenta)++;

					auxIdVenta = *idProximaVenta;
					pVenta[posicionVenta].idVenta = auxIdVenta;

					printf("\nSu codigo de venta es: %d\n",auxIdVenta);

					printf("\nAlta de Venta Correcta");

				}
				else
				{
					printf("No hay lugar para almacenar un nueva venta");
				}
			}
	    }
	}
	return retorno;
}

int listarVentas(eVenta pVenta[],int tamVenta)
{
	int respuesta = -1;
	int i;

	if(pVenta != NULL && tamVenta > 0)
	{
		for(i = 0; i < tamVenta ; i++)
		{
			if(pVenta[i].isEmptyVenta == 0)
			{
				printf("ID Articulo: %d Cantidad : %d ID Cliente: %d Fecha: %d/%d/%d ID Venta: %d Precio Total: %.2f \n",
						pVenta[i].articuloId,pVenta[i].cantidad,pVenta[i].clienteId,pVenta[i].fecha.dia,pVenta[i].fecha.mes,pVenta[i].fecha.anio,pVenta[i].idVenta,pVenta[i].precioTotal
						);
				respuesta = 0;

			}
		}
	}
	return respuesta;
}

