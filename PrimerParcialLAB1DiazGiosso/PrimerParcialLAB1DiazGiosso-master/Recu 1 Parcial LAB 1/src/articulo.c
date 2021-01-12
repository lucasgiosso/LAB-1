#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articulo.h"
#include "rubro.h"
#include "utn.h"

#define LIBRE 1
#define OCUPADO 0

void hardcodeoArticulo(eArticulo pArticulo[], int posicion,int idArticulo, int medida, int precio, int rubroId, char articulo[])
{
	strcpy(pArticulo[posicion].articulo,articulo);
	pArticulo[posicion].idArticulo = idArticulo;
	pArticulo[posicion].isEmptyArticulo = 0;
	pArticulo[posicion].medida = medida;
	pArticulo[posicion].precio = precio;
	pArticulo[posicion].rubroId = rubroId;
}

int inicializarArticulo(eArticulo pArticulo[], int tamArticulo)
{
	int respuesta = -1;
	int i;

	if(pArticulo != NULL && tamArticulo > 0)
	{
		for(i = 0; i < tamArticulo; i++)
		{
			pArticulo[i].isEmptyArticulo = LIBRE;
		}
		respuesta = 0;
	}
	return respuesta;
}

int existeArticulo(eArticulo pArticulo[], int tamArticulo)
{
	int respuesta = -1;
	int i;

	for(i = 0; i < tamArticulo; i++)
	{
		if(pArticulo[i].isEmptyArticulo == OCUPADO)
		{
			respuesta = 0;
		}
	}
	return respuesta;
}

int buscarArticuloLibre(eArticulo pArticulo[], int tamArticulo, int* posicion)
{
	int respuesta = -1;
	int i;

	if(pArticulo != NULL && tamArticulo > 0 && posicion != NULL )
	{
		for(i = 0; i < tamArticulo; i++)
		{
			if(pArticulo[i].isEmptyArticulo == LIBRE)
			{
				respuesta = 0;
				*posicion = i;
				break;
			}
		}
	}
	return respuesta;
}

int buscarIndiceArticulo(eArticulo pArticulo[], int tamArticulo)
{
	int respuesta = -1;
	int i;

	if(pArticulo != NULL && tamArticulo > 0)
	{
		respuesta = 0;

		for(i = 0; i < tamArticulo; i++)
		{
			if(pArticulo[i].isEmptyArticulo == LIBRE)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int buscarArticuloPorId(eArticulo pArticulo[], int tamArticulo, int IdArticulo, int* posicion)
{
	int respuesta = -1;
	int i;

	if(pArticulo != NULL && tamArticulo > 0 && IdArticulo >= 0)
	{
		for(i = 0; i < tamArticulo; i++)
		{
			if(pArticulo[i].idArticulo == IdArticulo)
			{
				*posicion = i;
				respuesta = 0;
				break;
			}
		}
	}
	return respuesta;
}

int altaArticulo(eArticulo pArticulo[], int tamArticulo, eRubro pRubro[],int tamRubro, int* idProximoArticulo)
{
	int retorno = -1;
	int posicion;
	int auxIdArticulo = 0;
	char auxArticulo[50];
	int auxMedida = 0;
	float auxPrecio;
	int auxRubroId = 1000;


	printf("\n\n<<<< Alta articulo >>>>\n");

	if(pArticulo != NULL && tamArticulo > 0 &&  pRubro != NULL && tamRubro > 0)
	{
		if(buscarArticuloLibre(pArticulo,tamArticulo,&posicion) != -1)
		{
			fflush(stdin);
			utn_getNombre(auxArticulo,50,"\nPor favor, ingrese nombre de articulo:\n","\nERROR\n",2);

			fflush(stdin);
			utn_getNumero(&auxMedida,"\nPor favor, ingrese la medida ( 1 - Unidades  2 - Litros  3 - Kg ) del articulo: \n","\nERROR\n",1,3,2);

			fflush(stdin);
			utn_getNumeroFlotante(&auxPrecio,"\nPor favor, ingrese importe (Rango: $100 to $2500) del articulo: \n","\nERROR\n",100,2500,2);

			mostrarRubros(pRubro, tamRubro);

			fflush(stdin);
			utn_getNumero(&auxRubroId,"\nPor favor, ingrese el rubro del articulo: \n", "\nERROR",1001,1004,2);

			(*idProximoArticulo)++;

			auxIdArticulo = *idProximoArticulo;

			printf("\nSu codigo de articulo es: %d\n",auxIdArticulo);

			printf("\nAlta Correcta\n");

			pArticulo[posicion].idArticulo = auxIdArticulo;
			strcpy(pArticulo[posicion].articulo,auxArticulo);
			pArticulo[posicion].medida = auxMedida;
			pArticulo[posicion].precio = auxPrecio;
			pArticulo[posicion].rubroId = auxRubroId;
			pArticulo[posicion].isEmptyArticulo = OCUPADO;
		}

		else
		{
			printf("No hay lugar para almacenar un nuevo articulo");
		}
	}
	return retorno;
}

int modificarArticulo(eArticulo pArticulo[],int tamArticulo)
{
	int respuesta = -1;
	int idArticulo;
	int posicion;
	int opcion = 0;

	if(pArticulo!= NULL && tamArticulo > 0)
	{
		utn_getNumero(&idArticulo,"\nIngrese ID a modificar: ", "\nERROR",1,tamArticulo, 2);

		if(buscarArticuloPorId(pArticulo,tamArticulo,idArticulo,&posicion) == -1)
		{
			printf("\nNo hay existe articulo\n");
		}
		else
		{
			do{
				utn_getNumero(&opcion,"\n(1) Medida\n(2) Precio\n(3) Salir\nPor favor, ingrese opción a modificar: ", "\nERROR",1,3,2);

				switch(opcion)
				{
					case 1:

						utn_getNumero(&pArticulo[posicion].medida,"\n( 1 - Unidades  2 - Litros  3 - Kg )\nPor favor, ingrese medida a modificar: \n","\nERROR\n",1,3,2);

						printf("\nMedida modificada satisfactoriamente.\n");

						break;

					case 2:

						utn_getNumeroFlotante(&pArticulo[posicion].precio,"\nPor favor, ingrese el precio a modificar:\n","\nERROR\n",100,2500,2);

						printf("\nPrecio modificado satisfactoriamente.\n");

						break;

					case 3:

						printf("\nSaliendo...\n");

						break;

					default:

						printf("\nPor favor, seleccione una opción valida\n");
			}

			}while(opcion != 3);
			respuesta = 0;
		}
	}

	return respuesta;
}

int bajaArticulo(eArticulo pArticulo[],int tamArticulo)
{
	int respuesta = -1;
	int idArticulo;
	int posicion;
	int opcion = 0;

	if(pArticulo != NULL && tamArticulo > 0)
	{
		listarArticulos(pArticulo,tamArticulo);

		utn_getNumero(&idArticulo,"Ingrese ID Articulo para dar de baja\n","\nError ID invalido",1,tamArticulo,2);

		if(buscarArticuloPorId(pArticulo,tamArticulo,idArticulo,&posicion) != -1)
		{
			utn_getNumero(&opcion,"1) Confirma 2) Cancela\n","Error\n",1,2,2);

			if(opcion == 1)
			{
				pArticulo[posicion].idArticulo = 0;
				strcpy(pArticulo[posicion].articulo,"");
				pArticulo[posicion].medida = 0;
				pArticulo[posicion].precio = 0;
				pArticulo[posicion].rubroId = 0;
				pArticulo[posicion].isEmptyArticulo = LIBRE;

				printf("\nEliminado\n");
			}
			else
			{
				printf("\nCancelado\n");
			}
		}
		respuesta = 0;
	}
	return respuesta;
}

int listarArticulos(eArticulo pArticulo[],int tamArticulo)
{
	int respuesta = -1;

	if(pArticulo != NULL && tamArticulo > 0)
	{
		for(int i = 0; i < tamArticulo ; i++)
		{
				if(pArticulo[i].isEmptyArticulo == 0)
				{

					printf("\nID Articulo: %2d    Nombre Articulo: %3s \tMedida: %2d  Precio: $%.2f  Rubro ID: %2d\n",
							pArticulo[i].idArticulo,pArticulo[i].articulo,pArticulo[i].medida,pArticulo[i].precio
							,pArticulo[i].rubroId);
					respuesta = 0;
				}
		}
	}
	return respuesta;
}

int ordenarArticuloPorRubroYDescripcion(eArticulo pArticulo[],int tamArticulo, int orden)
{
	int respuesta = -1;
	int i;
	int j;
	eArticulo aux;

	if(pArticulo != NULL && tamArticulo > 0 && orden > 0)
	{

		utn_getNumero(&orden,"\n¿En que orden desea ordenar los articulos por rubro y descripción 1) Descendente 2) Ascendente?\n","Error\n",1,2,2);

		switch(orden)
		{
			case 1:

				for(i = 0; i < tamArticulo - 1; i++)
				{
					for(j=i+1;j < tamArticulo;j++)
					{
						if(strcmp(pArticulo[j].articulo,pArticulo[i].articulo) < 0 )
						{
							aux = pArticulo[i];
							pArticulo[i] = pArticulo[j];
							pArticulo[j] = aux;
						}
						else if(strcmp(pArticulo[j].articulo,pArticulo[i].articulo) == 0 && pArticulo[j].rubroId < pArticulo[i].rubroId)
						{
							aux = pArticulo[i];
							pArticulo[i] = pArticulo[j];
							pArticulo[j] = aux;
						}
					}
				}
				respuesta = 0;
				break;

			case 2:

				for(i = 0; i < tamArticulo - 1; i++)
				{
					for(j=i+1;j < tamArticulo;j++)
					{
						if(strcmp(pArticulo[j].articulo,pArticulo[i].articulo) > 0 )
						{
							aux = pArticulo[i];
							pArticulo[i] = pArticulo[j];
							pArticulo[j] = aux;
						}
						else if(strcmp(pArticulo[j].articulo,pArticulo[i].articulo) == 0 && pArticulo[j].rubroId > pArticulo[i].rubroId)
						{
							aux = pArticulo[i];
							pArticulo[i] = pArticulo[j];
							pArticulo[j] = aux;
						}
					}
				}
				respuesta = 0;
				break;
		}
	}
	return respuesta;
}
