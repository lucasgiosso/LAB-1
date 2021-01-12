#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "articulos.h"
#include "utn.h"
#include "linkedList.h"

int parser_ArticulosFromText(FILE* pFile , LinkedList* eArticulos)
{
	eArticulo* aux;
    char auxId[50];
	char auxArticulo[50];
	char auxMedida[50];
	char auxPrecio[50];
	char auxRubroId[50];
    int count = 0;
	int back = 0;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxArticulo,auxMedida, auxPrecio, auxRubroId);

    while(!feof(pFile))
    {
    	count = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxArticulo,auxMedida, auxPrecio, auxRubroId);

        if(count == 5)
        {
        	aux = articulos_newParametros(auxId, auxArticulo,auxMedida, auxPrecio, auxRubroId);
        	ll_add(eArticulos,aux);

            back++;
        }
        else
        {
            if(feof(pFile))
            {
                printf("\nDon`t read last register %d", back);
                break;
            }
        }
    }
    printf("\nLoading...\n");
    fclose(pFile);
    return back;
}
