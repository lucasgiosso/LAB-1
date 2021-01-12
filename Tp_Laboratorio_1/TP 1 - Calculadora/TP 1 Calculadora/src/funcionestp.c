/*
 * funcionestp.c
 *
 *  Created on: 12 abr. 2020
 *      Author: lucasgiosso
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include"funcionestp.h"

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

void getString(char mensaje[], char cadena[])
{
	printf("%s",mensaje);
	fflush(stdin);
    scanf("%s",cadena);
}

int esNumerico(char str[])
{
    int i=0;
    int r = 1;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i]>'9')
        {
            r = 0;
        }
        i++;
    }

    return r;
}

int getStringNumeros(char mensaje[],char cadena[])
{
    char aux[256];
    int r =0;
    getString(mensaje,aux);
    while(esNumerico(aux)==0)
    {
        printf("Error.");
        getString(mensaje,aux);
    }
    strcpy(cadena,aux);
    r=1;

    return r;
}


int sumar(int x, int y)
{
	int r;

	r = x + y;

	return r;
}

int restar ( int x, int y)
{
	int r;

	r = x - y;

	return r;
}

int multiplicar (int x, int y)
{
	int r;

	r = x*y;

	return r;
}

float dividir (int x, int y)
{
	float r;

	if( y == 0)
	{
		r = 0;
		printf("No es posible dividir por cero\n");

	}
	else
	{
		r =(float) x/y;
	}
	return r;
}

long factorial (int x)
{
	int r;

	if(x < 0)
	{
		r = 0;

		printf("Factorear no es posible ya que el número no puede ser menor a cero");
	}

	else
	{
		if(x == 0)
		{
			r = 1;
		}
		else
		{
			r = x * factorial(x -1);
		}
	}
	return r;
}
