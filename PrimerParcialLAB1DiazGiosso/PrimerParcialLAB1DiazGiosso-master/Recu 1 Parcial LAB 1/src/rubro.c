/*
 * rubro.c
 *
 *  Created on: 1 jul. 2020
 *      Author: lucasgiosso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubro.h"

#define LIBRE 1
#define OCUPADO 0

void hardcodeoRubro(eRubro pRubro[], int idRubro, char descripcion[], int posicion)
{
	pRubro[posicion].idRubro = idRubro;
    strcpy(pRubro[posicion].descripcion, descripcion);
    pRubro[posicion].isEmptyRubro = 0;
}

void inicializarRubro(eRubro pRubro[], int tamRubro)
{
	int i;

	if(pRubro != NULL && tamRubro > 0)
	{
		for(i = 0; i < tamRubro; i++)
		{
			pRubro[i].isEmptyRubro = 1;
		}
	}
}

void mostrarRubro(eRubro pRubro)
{
	printf(" %2d 	%10s\n",pRubro.idRubro,pRubro.descripcion);
}

void mostrarRubros(eRubro pRubro[], int tamRubro)
{
	int i;
	int flag = 0;

	printf("\n  ID       Descripción\n");

	if(pRubro != NULL && tamRubro >= 0)
	{
		for (i = 0; i < tamRubro; i++)
		{
			if(pRubro[i].isEmptyRubro == 0)
			{
				mostrarRubro(pRubro[i]);
				flag = 1;
			}
		}

		if(flag == 0)
		{
			printf("\nNo hay rubros para mostrar\n");
		}
	}
}

int buscarRubroxId(eRubro pRubro[],int tamRubro,int idRubro, char* nombreRubro)
{
	int retorno = -1;
	int i;

	if(pRubro != NULL && tamRubro > 0 )
	{
		for(i = 0; i < tamRubro; i++){
			if(pRubro[i].idRubro == idRubro && pRubro[i].isEmptyRubro == 1)
			{
				strcpy(nombreRubro, pRubro[i].descripcion);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int listarRubros(eRubro pRubro[],int tamRubro)
{
	int respuesta = -1;

	if(pRubro != NULL && tamRubro > 0)
	{
		for(int i = 0; i< tamRubro ; i++)
		{
				if(pRubro[i].isEmptyRubro == OCUPADO)
				{
					printf("\nID Rubro: %2d Nombre Rubro: %8s",
							pRubro[i].idRubro,pRubro[i].descripcion);
					respuesta = 0;

				}
		}
	}
	return respuesta;
}

