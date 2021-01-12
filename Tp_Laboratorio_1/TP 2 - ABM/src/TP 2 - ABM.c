/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define TAM 1000

int main(){

		int answer = 0;
		int option;
		int idEmployee = 0;

		eEmployee employee[TAM];

		initEmployees(employee,TAM);

		printf("< < < Welcome to the Employee program > > >");

		do
		{
		utn_getNumero(&option,	"\n1) Add employee""\n2) Modify employee""\n3) Remove employee""\n4) Inform employee"
								"\n5) Print Employee""\n6) Exit \n\nYour option is: ","\nError option invalid",1,6,2);

		switch(option)
		{
		case 1:

			insertEmployee(employee,TAM,&idEmployee);

			break;

		case 2:

			if(checkEmployees(employee, TAM) == 0)
			{
				printEmployees(employee,TAM);
				modifyEmployee(employee,TAM);
			}
			else
			{
				printf("You must load at least one employee");
			}

			break;

		case 3:

			if(checkEmployees(employee, TAM) == 0)
			{
				removeEmployee(employee,TAM);
			}
			else
			{
				printf("You must load at least one employee");
			}
			break;

		case 4:

			if(checkEmployees(employee, TAM) == 0)
			{
				reportEmployee(employee,TAM);
			}
			else
			{
				printf("You must load at least one employee");
			}
			break;

		case 5:

			printEmployees(employee,TAM);
			break;

		case 6:

			printf("\nEnd Program");
			break;
		}
	}while(option != 6);

	return answer;
}
