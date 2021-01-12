/*
 * prestamo.c
 *
 *  Created on: 16 may. 2020
 *      Author: lucasgiosso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prestamo.h"
#include "utn.h"
#include "cliente.h"

int inicializarPrestamo(ePrestamo* prestamo, int tam)
{
	int respuesta = -1;

	if(prestamo!= NULL && tam > 0)
	{

		for (int i=0; i < tam; i++)
		{
			prestamo[i].idPrestamo = 0;
			prestamo[i].isEmptyPrestamo = 0;
			respuesta = 0;
		}
	}
	return respuesta;
}

int buscarPrestamoLibre(ePrestamo* prestamo, int tam)
{
	int respuesta = -1;

	for(int i = 0; i < tam; i++)
	{
		if(prestamo[i].isEmptyPrestamo == 0)
		{
			respuesta = i;
			break;
		}
	}
	return respuesta;
}

int buscarPrestamoXId(ePrestamo* prestamo, int tam, int IdCliente)
{
	int respuesta = -1;

	for(int i = 0; i < tam; i++)
	{
		if(prestamo[i].idPrestamo == IdCliente && prestamo[i].isEmptyPrestamo == 1)
		{
			respuesta = i;
			break;
		}
	}
	return respuesta;
}

int proximoIdPrestamo(ePrestamo* prestamo, int tam)
{
	    int respuesta = 0;
	    int i;

	    for(i=0; i<tam; i++)
	    {
	        if(prestamo[i].idPrestamo>respuesta)
	        {
	        	respuesta=prestamo[i].idPrestamo;
	        }
	    }
	    return respuesta+1;
	}

int altaPrestamo(ePrestamo* prestamo, int tamPrestamo,int* buscarId,eClientes* clientes,int tamClientes)
{
	int respuesta = -1;
	int auxIdPrestamo;
	char auxImporte[51];
	char auxCantCuotas[51];
	char auxCuil[51];
	int indice;
	int auxIdCliente;

	if(prestamo!=NULL && tamPrestamo>0 && buscarId != NULL && clientes!=NULL && tamClientes>0)
	    {

					indice = buscarPrestamoLibre(prestamo, tamPrestamo);

					if(indice == -1)
					{
								printf("No hay lugar para almacenar un nuevo prestamo");
					}

					else
					{
					utn_getNumero(&respuesta, "Por favor ingrese ID de Cliente","\nError opción invalida",1,2,2);

					if(buscarClienteXId(clientes,tamClientes,auxIdCliente)== -1)
					{
						printf("\nNo existe ID");
					}

					else
					{

					}

					auxIdPrestamo = proximoIdPrestamo(prestamo, tamPrestamo);
					printf("Su codigo de prestamo es: %d\n", auxIdPrestamo);

					utn_getNombre(auxImporte,51,"\nPor favor, ingrese el importe a solicitar:\n","\nERROR\n",2);
					strcpy(prestamo[indice].importePrestamo,auxImporte);

					utn_getNombre(auxCantCuotas,51,"\nPor favor, ingrese la cantidad de cuotas:\n","\nERROR\n",2);
					strcpy(prestamo[indice].cantCuotasPrestamo,auxCantCuotas);


					prestamo[indice].isEmptyPrestamo = 1;
					prestamo[indice].idPrestamo = *buscarId;
					prestamo[indice].idCliente = auxIdCliente;
					clientes[indice].prestamoActivoCliente = 0;
					clientes[indice].prestamosSaldoCliente = 0;
					auxIdCliente++;

					printf("Alta Correcta");
				}

	    }

	return respuesta;
}

int imprimirPrestamos(ePrestamo* prestamo,int tamPrestamo, eClientes* clientes, int tamClientes)
{
	int respuesta = -1;

	if(prestamo != NULL && tamPrestamo > 0 && clientes != NULL && tamClientes > 0 )
	{
		for(int i = 0; i< tamPrestamo ; i++)
			{
				if(prestamo[i].isEmptyPrestamo == 1)
					{}
				if(strcmp(prestamo[i].situacionPrestamo, "ACTIVO")== 0)
				{
					for(int j = 0; j < tamClientes ; j++)
					{
						if(clientes[j].isEmptyCliente == 1)
						{

						}
						if(prestamo[i].idCliente == clientes[j].idCliente)
						{
							printf("Prestamo: %10d  ID Cliente: %15d  Importe: %.2f  Cant de Cuotas: %20d\n Situacion Prestamo: %10s Cuil Cliente: %s\n", prestamo[i].idPrestamo,prestamo[i].idCliente, prestamo[i].importePrestamo, prestamo[i].cantCuotasPrestamo,prestamo[i].situacionPrestamo,clientes[i].cuilCliente);
							respuesta = 1;
						}
					}
				}
			}
		respuesta = 0;
	}
	return respuesta;
}

int informePrestamos(ePrestamo* prestamo, int tam)
{
	int respuesta = -1;
	int i;
	float importe;

	if(prestamo != NULL && tam > 0)
	{
		utn_getNumeroFlotante(&importe,"Ingrese un Importe mayor a $1000: ", "Error, por favor ingrese un numero correctamente",1,100000,3);

				while(importe > 1000)
				{
					utn_getNumeroFlotante(&importe,"Ingrese un Importe mayor a $1000: ", "Error, por favor ingrese un numero correctamente",1,100000,3);
				}

				for(i=0; i < tam; i++)
				{
						if(prestamo[i].isEmptyPrestamo == 1)
						{}
						if(prestamo[i].importePrestamo == importe && strcmp(prestamo[i].situacionPrestamo, "ACTIVO") == 0 )
						{
							printf("ID Prestamo: %d\n Importe: %.2f,", prestamo[i].idPrestamo, prestamo[i].importePrestamo);
						}
				}
	respuesta = 0;
	}
	return respuesta;
}

