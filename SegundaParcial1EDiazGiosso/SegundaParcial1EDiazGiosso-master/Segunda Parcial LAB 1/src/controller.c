#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "articulos.h"
#include "utn.h"
#include "linkedList.h"
#include "parser.h"

int controller_ArticulosloadFromText(char* path, LinkedList* listaArticulos)
{
	int back = -1;

	FILE* pFile = fopen(path, "r");

	if(pFile == NULL)
	{
		printf("File doesn`t exist");
	}
	else
	{
		if(parser_ArticulosFromText(pFile,listaArticulos)== 1)
		{

			printf("\nText Load Succesfully\n");
			fclose(pFile);
			back = 1;
		}

	}

return back;
}

int orderByArticulo(void* art1, void* art2)
{
	int back = 0;

	char articulo1[51];
	char articulo2[51];

	articulos_getArticulo(art1,articulo1);
	articulos_getArticulo(art2,articulo2);

	if(strcmp(articulo1,articulo2) > 0)
	{
		back = 1;
	}

	return back;
}

int controller_sortArticulo(LinkedList* listaArticulos)
{
	int back = 0;

	if(listaArticulos != NULL)
	{
		if(ll_sort(listaArticulos,orderByArticulo,1) == 0)
		{
			back = 1;
		}
	}
	return back;
}

int controller_printArticulos(LinkedList* listaArticulos)
{
	int back = 0;
	int i;
	int len = ll_len(listaArticulos);
	eArticulo* auxArt = NULL;
	int auxId;
	char auxArticulo[50];
	char auxMedida[50];
	float auxPrecio;
	int auxRubroId;
	char auxRubroStr[50];

	if(len > 0 && listaArticulos != NULL)
	{
		for(i=0; i < len; i++)
		{

			auxArt = (eArticulo*)ll_get(listaArticulos,i);

			if(auxArt != NULL)
			{
				articulos_getId(auxArt,&auxId);
				articulos_getArticulo(auxArt,auxArticulo);
				articulos_getMedida(auxArt,auxMedida);
				articulos_getPrecio(auxArt,&auxPrecio);
				articulos_getRubroId(auxArt,&auxRubroId);

				switch(auxRubroId)
				{
				case 1:

					strcpy(auxRubroStr,"CUIDADO DE ROPA");

					break;

				case 2:

					strcpy(auxRubroStr,"LIMPIEZA Y DESINFECCION");
					break;

				case 3:

					strcpy(auxRubroStr,"CUIDADO PERSONAL E HIGIENE");
					break;

				case 4:

					strcpy(auxRubroStr,"CUIDADO DEL AUTOMOTOR");
					break;
				}


				printf("|ID:%d\t|Articulo: %-30.30s\t|Medida: %-6.5s\t|Precio: $ %3.2f\t\t|Rubro ID:%-10.30s\n",auxId,auxArticulo,
						auxMedida,auxPrecio,auxRubroStr);
			}

		}
		back = 1;
	}
	else
	{
		printf("It`s Empty");
	}

	return back;
}

int controller_ll_map(LinkedList* listaArticulos)
{
	int back = 0;

	if(listaArticulos != NULL)
	{
		ll_map(listaArticulos,controller_mapArticulos);
		back = 1;
	}

	return back;
}


int controller_saveAsTextArticulo(char* path,LinkedList* listaArticulos)
{
	int back = 0;
	int i;
	int auxId;
	char auxArticulo[128];
	char auxMedida[50];
	float auxPrecio;
	int auxRubroId;
	//char auxRubroStr[50];

	eArticulo* auxArt;
	int len = ll_len(listaArticulos);

	if(len == 0)
	{
		printf("Empty List");
	}

	else
	{
		FILE *pFile = fopen(path,"w");

		if(pFile != NULL && listaArticulos != NULL)
		{
			fprintf(pFile,"ID,Articulo,Medida,Precio,Rubro ID\n");

			for(i=0;i < len ;i++)
			{
				auxArt = ll_get(listaArticulos,i);

				articulos_getId(auxArt,&auxId);
				articulos_getArticulo(auxArt,auxArticulo);
				articulos_getMedida(auxArt,auxMedida);
				articulos_getPrecio(auxArt,&auxPrecio);
				articulos_getRubroId(auxArt,&auxRubroId);

				/*
				switch(auxRubroId)
				{
				case 1:

					strcpy(auxRubroStr,"CUIDADO DE ROPA");

					break;

				case 2:

					strcpy(auxRubroStr,"LIMPIEZA Y DESINFECCION");
					break;

				case 3:

					strcpy(auxRubroStr,"CUIDADO PERSONAL E HIGIENE");
					break;

				case 4:

					strcpy(auxRubroStr,"CUIDADO DEL AUTOMOTOR");
					break;
				}
				 */
				fprintf(pFile,"%d,%s,%s,%f,%d\n",auxId,auxArticulo,auxMedida,auxPrecio,auxRubroId);

			}
			back = 1;
		}
		fclose(pFile);
	}
	return back;
}

int controller_informe(LinkedList* listaArticulos)
{
	int back = 0;
	int auxMayorACien;
	int auxCantCuidado;

			auxMayorACien = ll_count(listaArticulos,mayorACien);
			auxCantCuidado = ll_count(listaArticulos,cantCuidado);

			printf("Cantidad de Artículos cuyo precio sea mayor a $100: %d\n",auxMayorACien);

			printf("Cantidad de Artículos rubro 1: %d\n",auxCantCuidado);


	return back;
}

