/*
 ============================================================================
 Name        : Segunda.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "utn.h"
#include "controller.h"

void menu();

int main(void) {

	int option = 0;
	char dato[50];

	LinkedList* listaArticulos = ll_newLinkedList();

	if(listaArticulos == NULL)
	{
		printf("Error to create the list");
	}

	do{
		menu();
		utn_getNumero(&option,"\nInsert valid option: ", "Error",1,7,2);

		switch(option)
		{
		case 1:

			utn_getTexto(dato,"Please, insert a name of file .csv\n", "Error\n",1,40,2);

			if(controller_ArticulosloadFromText(dato,listaArticulos) != 0)
			{
				printf("\nLoad Succesfully\n");
			}
			else
			{
				printf("You must load at least one word");
			}

			break;

		case 2:

			if(controller_sortArticulo(listaArticulos)!= 0)
			{
				printf("\nSort Succesfully\n");
			}
			else
			{
				printf("You must load at least one word");
			}

			break;

		case 3:

			if(controller_printArticulos(listaArticulos)!= 0)
			{
				printf("\nEnd List\n");
			}
			else
			{
				printf("You must load at least one word");
			}
			break;

		case 4:

			if(controller_ll_map(listaArticulos)!= 0)
			{
				printf("\nDiscount Applied\n");
			}
			else
			{
				printf("You must load at least one word");
			}

			break;

		case 5:
			if(controller_saveAsTextArticulo("mapeado.csv",listaArticulos)!= 0)
			{
				printf("\nSave Succesfully\n");
			}
			else
			{
				printf("You must load at least one word");
			}
			 break;
		case 6:

			controller_informe(listaArticulos);

				printf("\nEnd Inform\n");


			break;

		case 7:
			printf("\nEnd Program\n");
			break;

		}

	}while(option != 7);

	return EXIT_SUCCESS;
}

void menu()
{
	printf(
			"\n	1.  Read & Load File"
			"\n	2.  Sort"
			"\n	3.  Print"
			"\n	4.  Apply Discount"
			"\n	5.  Save File"
			"\n	6.  Inform"
			"\n	7.  Exit\n"
			);
}

