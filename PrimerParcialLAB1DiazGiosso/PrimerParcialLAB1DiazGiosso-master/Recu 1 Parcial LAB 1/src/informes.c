#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "articulo.h"
#include "rubro.h"
#include "cliente.h"
#include "venta.h"
#include "utn.h"
#include "rubro.h"

int informes(eArticulo pArticulo[],int tamArticulo,eCliente clientes[], int tamCliente,eVenta pVenta[],int tamVenta,eRubro pRubro[], int tamRubro)
{
	int retorno=-1;
	int aux;
	char auxArray[50];
	int i;
	int opcion;
	//int idArticulo;
	//int posicionArticulo;
	float acumulador = 0;
	int j;
	char nombreCliente[50];

	if(pArticulo != NULL && tamArticulo > 0 && clientes != NULL && tamCliente > 0 && pVenta != NULL && tamVenta > 0 && pRubro != NULL && tamRubro > 0)
	{

		utn_getNumero(&opcion,"\n1- Mostrar artículos de un rubro seleccionado\n"
								"2- Mostrar todas las ventas efectuadas al cliente seleccionado\n"
								"3- Informar importe total de las ventas realizadas de un artículo seleccionado.\n"
								"4- Informar importe total de las ventas realizadas a un cliente seleccionado.\n"
								"5- Salir\nIngrese opcion: ","\nError.",1,5,3);

	switch(opcion)
	// Mostrar artículos de un rubro seleccionado
	{
	case 1:

		utn_getNumero(&aux,"\nIngrese el rubro \n","\nerror\n",1000,1004,3);

		for(i=0;i < tamArticulo;i++)
		{
			if(aux == pArticulo[i].rubroId)
			{

				printf("ID Articulo: %2d Nombre Articulo: %8s Medida: %2d Precio: %.2f Rubro ID: %2d\n",
						pArticulo[i].idArticulo,pArticulo[i].articulo,pArticulo[i].medida,pArticulo[i].precio,
						pArticulo[i].rubroId);
				retorno = 0;
			}
		}
		break;
		// Mostrar todas las ventas efectuadas al cliente seleccionado
	case 2:

		utn_getNumero(&aux,"\nIngrese el ID del cliente para ver las ventas: ","\nError\n",1,50,3);

		for(i = 0;i < tamCliente;i++)
		{
			if(clientes[i].idCliente == aux && clientes[i].isEmptyCliente == 0)
			{
				for(j = 0;j < tamVenta;j++)
				{
					if(pVenta[j].clienteId == aux && pVenta[j].isEmptyVenta == 0)
					{

						printf("ID Articulo: %d Cantidad : %d ID Cliente: %d Fecha: %d/%d/%d ID Venta: %d Precio Total: %.2f \n",
								pVenta[j].articuloId,pVenta[j].cantidad,pVenta[j].clienteId,pVenta[j].fecha.dia,pVenta[j].fecha.mes,pVenta[j].fecha.anio,
								pVenta[j].idVenta,pVenta[j].precioTotal);

					}
				}
			}

		}
				retorno = 0;
		break;
		//Informar importe total de las ventas realizadas de un artículo seleccionado
	case 3:

		listarArticulos(pArticulo,tamArticulo);

		utn_getDescripcion(auxArray,50,"\nIngresar nombre de articulo: ","\nError\n",2);

		for(i = 0;i < tamArticulo;i++)
		{
			if(strcmp(pArticulo[i].articulo,auxArray) == 0)
			{
				for(j = 0;j < tamVenta;j++)
				{
					if(pVenta[j].articuloId == pArticulo[i].idArticulo)
					{
						acumulador += pVenta[j].precioTotal;
					}
				}
			}
		}
		printf("\nImporte total de ventas %.2f",acumulador);
		retorno = 0;
		break;

		//- Informar importe total de las ventas realizadas a un cliente seleccionado
	case 4:

		listarClientes(clientes,tamCliente);

		utn_getNumero(&aux,"\nIngrese ID de Cliente: ","\nError\n",1,50,3);

		for(i = 0;i < tamCliente;i++)
		{
			if(clientes[i].idCliente == aux && clientes[i].isEmptyCliente == 0 )
			{
				strcpy(nombreCliente,clientes[i].nombre);

				for(j = 0;j < tamVenta;j++)
				{
					if(pVenta[j].clienteId == aux && pVenta[j].isEmptyVenta == 0)
					{
						acumulador += pVenta[j].precioTotal;
					}
				}
			}
		}
		printf("\nImporte total de ventas de %s es %.2f",nombreCliente,acumulador);
		retorno = 0;
		break;
	}

	}

return retorno;
}


