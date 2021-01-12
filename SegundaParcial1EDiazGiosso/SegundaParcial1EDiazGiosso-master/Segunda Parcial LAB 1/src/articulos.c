#include "articulos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "linkedList.h"


eArticulo* articulos_new()
{
	eArticulo* eArticulos = (eArticulo*) malloc(sizeof(eArticulo));

	if(eArticulos != NULL)
	{
		eArticulos->id = 0;
		strcpy(eArticulos->articulo, " ");
		strcpy(eArticulos->medida, " ");
		eArticulos->precio = 0;
		eArticulos->rubroId = 0;
	}
		return eArticulos;
}

eArticulo* articulos_newParametros(char* id,char* articulo,char* medida,char* precio, char* rubroId)
{
	eArticulo* newArticulos = articulos_new();

	int change = 0;

	if(newArticulos != NULL && id != NULL && articulo
			!= NULL && medida != NULL && precio != NULL && rubroId
			!= NULL)
		{
			articulos_setId(newArticulos, atoi(id));
			articulos_setArticulo(newArticulos,articulo);
			articulos_setMedida(newArticulos,medida);
			articulos_setPrecio(newArticulos, atoi(precio));
			articulos_setRubroId(newArticulos, atoi(rubroId));
			change = 1;

		}

		if(change == 0)
		{
			free(newArticulos);
			newArticulos = NULL;
		}

	return newArticulos;
}

int articulos_setId(eArticulo* this, int id)
{
	int change = 0;

	if(this != NULL && id > 0)
	{
		 this->id = id;
		 change = 1;
	}
	return change;
}

int articulos_getId(eArticulo* this, int* id)
{
	int change = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		change = 1;
	}
	return change;
}

int articulos_setArticulo(eArticulo* this, char* articulo)
{
	int change = 0;

	if(this != NULL && articulo != NULL)
	{
		strcpy(this->articulo,articulo);
		change = 1;
	}
	return change;
}

int articulos_getArticulo(eArticulo* this, char* articulo)
{
	int change = 0;

	if(this != NULL && articulo != NULL)
	{
		strcpy(articulo,this->articulo);
		change = 1;
	}
	return change;
}

int articulos_setMedida(eArticulo* this, char* medida)
{
	int change = 0;

	if(this != NULL && medida >= 0)
	{
		strcpy(this->medida,medida);
		change = 1;
	}
	return change;
}

int articulos_getMedida(eArticulo* this, char* medida)
{
	int change = 0;

	if(this != NULL && medida != NULL)
	{
		strcpy(medida,this->medida);
		change = 1;
	}
	return change;
}

int articulos_setPrecio(eArticulo* this, float precio)
{
	int change = 0;

	if(this != NULL && precio > 0)
		{
			 this->precio = precio;
			change = 1;
		}
		return change;
}

int articulos_getPrecio(eArticulo* this, float* precio)
{
	int change = 0;

	if(this != NULL && precio != NULL)
		{
			*precio = this->precio;
			change = 1;
		}
	return change;
}

int articulos_setRubroId(eArticulo* this, int rubroId)
{
	int change = 0;

	if(this != NULL && rubroId >= 0)
	{
		this->rubroId = rubroId;
		change = 1;
	}
	return change;
}

int articulos_getRubroId(eArticulo* this, int* rubroId)
{
	int change = 0;

	if(this != NULL && rubroId != NULL)
	{
		*rubroId = this->rubroId;
		change = 1;
	}
	return change;
}

int controller_mapArticulos(void* Articulos)
{
	int back = -1;
	float auxPrecio;
	int auxRubroId;
	float descuento;
	int total;

	if(Articulos != NULL)
		{
			Articulos = (eArticulo*)Articulos;
			articulos_getPrecio(Articulos,&auxPrecio);
			articulos_getRubroId(Articulos,&auxRubroId);

			if(auxRubroId == 1 && auxPrecio >= 120)
			{
				descuento = 0.80;
				total = auxPrecio * descuento; // 120 * 0,80 = 96
				articulos_setPrecio(Articulos,total);
				back = 0;
			}
			if(auxRubroId == 2 && auxPrecio <= 200)
			{
				descuento = 0.90;
				total = auxPrecio * descuento; // 200 * 0,90 = 180
				articulos_setPrecio(Articulos,total);
				back = 0;
			}
		}
	return back;
}

int mayorACien(void* ventas)
{
	int back = 0;
	float auxPrecio;
	eArticulo* auxArticulo;

	if(ventas != NULL)
	{
		auxArticulo = (eArticulo*)ventas;
		articulos_getPrecio(auxArticulo,&auxPrecio);

		if((auxPrecio) > 100)
		{
			back = 1;
		}
	}
	return back;
}

int cantCuidado(void* ventas)
{
	int back = 0;
	eArticulo* auxArticulo;
	int rubroId;

	if(ventas != NULL)
	{
		auxArticulo = (eArticulo*)ventas;
		articulos_getRubroId(auxArticulo,&rubroId);

		if(rubroId == 1)
		{
			back = 1;
		}
	}

	return back;
}
