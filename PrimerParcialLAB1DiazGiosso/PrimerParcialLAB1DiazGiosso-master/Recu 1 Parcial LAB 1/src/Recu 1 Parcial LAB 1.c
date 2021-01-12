/*
 ============================================================================
 Name        : Recu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "articulo.h"
#include "rubro.h"
#include "cliente.h"
#include "fecha.h"
#include "venta.h"
#include "utn.h"
#include "informes.h"


#define TAM_CLIENTES 50
#define TAM_RUBRO 50
#define TAM_ARTICULO 50
#define TAM_VENTA 50


int main(){

int respuesta = 0;
int opcion;
int idArticulo = 1;
int idVenta=1;

		eCliente cliente[TAM_CLIENTES];
		eArticulo pArticulo[TAM_ARTICULO];
		eRubro pRubro[TAM_RUBRO];
		eVenta venta[TAM_VENTA];

		inicializarRubro(pRubro,TAM_RUBRO);
		inicializarClientes(cliente,TAM_CLIENTES);
		inicializarArticulo(pArticulo,TAM_ARTICULO);
		inicializarVenta(venta,TAM_VENTA);


		hardcodeoRubro(pRubro,1001,"CUIDADO DE ROPA",1);
		hardcodeoRubro(pRubro,1002,"LIMPIEZA Y DESINFECCION",2);
		hardcodeoRubro(pRubro,1003,"CUIDADO PERSONAL E HIGIENE",3);
		hardcodeoRubro(pRubro,1004,"CUIDADO DEL AUTOMOTOR",4);

		hardcodeoCliente(cliente,1,"Juana Sosa","3456-5689",1);
		hardcodeoCliente(cliente,2,"Ana Rubio","500-9924",2);
		hardcodeoCliente(cliente,3,"Pedro Duarte","180-1897",3);
		hardcodeoCliente(cliente,4,"Sonia Rios","145-2587",4);
		/*
		hardcodeoVenta(venta,1,"Mayo",30,2,1,1567,1);
		hardcodeoVenta(venta,2,"Junio",22,3,4,12347,2);
		hardcodeoVenta(venta,3,"Marzo",26,1,2,18537,3);
		hardcodeoVenta(venta,1,"Domingo",14,4,3,1469,4);

		hardcodeoArticulo(pArticulo,1,1,20,30,1001,"Lavanda");
		hardcodeoArticulo(pArticulo,2,2,40,20,1001,"asd");
		hardcodeoArticulo(pArticulo,3,3,40,10,1001,"fsa");
		 */

		printf("< < < Bienvenido al sistema > > >\n");

		do
		{
			utn_getNumero(&opcion,	"\n1) Alta Articulo""\n2) Modificar Articulo""\n3) Baja Articulo""\n4) Listar Articulos"
									"\n5) Listar Rubros""\n6) Listar Clientes""\n7) Alta Venta""\n8) Listar Ventas""\n9) Informes"
									"\n10) Salir" "\n\nOpción elegida: ","\nError opcion invalida",1,10,2);

			switch(opcion)
			{
				case 1:

					altaArticulo(pArticulo,TAM_ARTICULO,pRubro,TAM_RUBRO,&idArticulo);

					break;

				case 2:

					modificarArticulo(pArticulo,TAM_ARTICULO);

			break;

				case 3:

					bajaArticulo(pArticulo,TAM_ARTICULO);

					break;

				case 4:

					ordenarArticuloPorRubroYDescripcion(pArticulo,TAM_ARTICULO);
					listarArticulos(pArticulo,TAM_ARTICULO);

					break;

				case 5:

					listarRubros(pRubro,TAM_RUBRO);
					break;

				case 6:

					listarClientes(cliente,TAM_CLIENTES);
					break;

				case 7:
					altaVenta(venta,50,pArticulo,TAM_ARTICULO,cliente,TAM_CLIENTES,&idVenta);
				break;

				case 8:
					listarVentas(venta,50);
					break;

				case 9:
					informes(pArticulo,TAM_ARTICULO,cliente,TAM_CLIENTES,venta,TAM_VENTA,pRubro,TAM_RUBRO);
					break;


			}
		}while(opcion != 10);

	return respuesta;
}
