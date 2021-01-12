/*
 * ArrayEmployees.c
 *
 *  Created on: 2 may. 2020
 *      Author: lucasgiosso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"

int initEmployees(eEmployee* list, int len)
{
    int answer = -1;

	    if(list!= NULL && len > 0)
	    {
	    	for(; len > 0 ; len--)
	    		{
	            	list[len-1].isEmpty = 1;
	    		}
	    		answer = 0;
	    }
	    return answer;
}

int checkEmployees(eEmployee* list, int len)
{
	int answer = -1;
	int i;

	for(i = 0; i < len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			answer = 0;
		}
	}
	return answer;
}

int findEmpty(eEmployee* list, int len, int* position)
{
	int answer = -1;
	int i;

	if(list != NULL && len >= 0 && position != NULL)

	for(i=0; i < len; i++)
	{
		if(list[i].isEmpty == 1)
		{
			answer = 0;
			*position = i;
			break;
		}
	}

	return answer;
}

int printEmployees(eEmployee* list, int len)
{
    int i;
    int answer = -1;

    if(list!= NULL && len >=0)
    {
    		for(i=0;i<len;i++)
    		{
    			if(list[i].isEmpty != 1)
    			{
    				printf("\nID: %2d \tName: %2s \tLast Name: %2s \tSalary: %.2f \tSector: %4d\n",
    						list[i].id, list[i].name, list[i].lastName,list[i].salary,list[i].sector);
    			}
    			else
    			{
    				continue;
    			}

    		}
    		answer = 0;
    }
    return answer;
}

int addEmployee(eEmployee* list, int len, int id, char* name,char* lastName,float salary,int sector, int position)
{
	int answer = -1;

	if(list!= NULL && len>0 && id>0 && name!= NULL && lastName!= NULL && salary>0 && sector>0)
		{
			list[position].id = id;
			strcpy(list[position].name,name);
			strcpy(list[position].lastName,lastName);
			list[position].salary = salary;
			list[position].sector = sector;
			list[position].isEmpty =0;

			answer = 0;
		}
	return answer;
}

int insertEmployee(eEmployee* list, int len, int* idCount)
{
	int answer = -1;
	int auxId;
	char auxName[51];
	char auxLastName[51];
	float auxSalary = 0;
	int auxSector;
	int position;

	printf("\n\n<<<< Add an Employee >>>>\n");

	if(list!= NULL && len > 0)
		{
			if (findEmpty(list,len,&position) != -1)
			{
					fflush(stdin);
					utn_getNombre(auxName,51,"\nPlease, insert name.\n","\nERROR\n",2);

					fflush(stdin);
					utn_getNombre(auxLastName,51,"\nPlease, insert last name.\n","\nERROR\n",2);

					fflush(stdin);
					utn_getNumeroFlotante(&auxSalary,"\nPlease, insert salary:(Range: $30000 to $150000)\n","\nERROR\n",30000,150000,2);

					fflush(stdin);
					utn_getNumero(&auxSector,"\nPlease insert sector:(Range: 1 to 8)\n", "\nERROR",1,8, 2);

					(*idCount)++;

					auxId = *idCount;

					printf("Your id is: %d",auxId);

					addEmployee(list,len,auxId,auxName,auxLastName,auxSalary,auxSector,position);
			}
			else
			{
				printf("\nFull Storage.");
			}
		}
return answer;
}

int modifyEmployee(eEmployee* list,int len)
{
	int answer = -1;
	int id;
	int option = 0;
	int position;

	if(list!= NULL && len>0)
	{
		utn_getNumero(&id,"\nEmployee Id to modify:\n", "\nERROR",1,len, 2);

		if(findEmployeeById(list,len,id,&position)== -1)
		{
			printf("\nNo Id");
		}
		else
		{
			do{
				utn_getNumero(&option,"\nPlease insert field to modify:\n(1) Name\n(2) Last Name\n(3) Salary\n(4) Sector\n(5) Exit\n", "\nERROR",1,5,2);

				switch(option)
			{

					case 1:
						utn_getNombre(list[position].name,51,"\nPlease, insert name.\n","\nERROR\n",2);
						break;
					case 2:
						utn_getNombre(list[position].lastName,51,"\nPlease, insert last name.\n","\nERROR\n",2);
						break;
					case 3:
						utn_getNumeroFlotante(&list[position].salary,"\nPlease, insert salary. (Range: $30000 to $150000).\n","\nERROR\n",30000,150000,2);
						break;
					case 4:
						utn_getNumero(&list[position].sector,"\nPlease insert sector. (Range: 1 to 8).\n", "\nERROR",1,8, 2);
						break;
					case 5:

						break;
					default:
						printf("Please, select an option valid");
			}

			}while(option != 5);
			answer = 0;
		}
	}

	return answer;
}

int removeEmployee(eEmployee* list, int len)
{
	int answer = -1;
	int id;
	int position;

	if(list != NULL && len > 0)
	{
		printEmployees(list,len);

		utn_getNumero(&id,"Insert valid ID\n","\nError ID invalid",1,len,2);

		if(findEmployeeById(list,len,id,&position) != -1)
	    {
	        list[position].isEmpty = 1;
	        strcpy(list[position].name,"");
	        strcpy(list[position].lastName,"");
	        list[position].sector=0;
	        list[position].id=0;
	        list[position].salary = 0;
	    }
		answer = 0;
	}
	return answer;
}

int getEmptyIndexEmployee(eEmployee* list,int len)
{
	int answer = -1;
	int i;

	if(list != NULL && len > 0)
	{
		answer = 0;
		for(i=0; i < len ;i++)
		{
			if(list[i].isEmpty == 1)
			{
				answer = i;
				break;
			}
		}
	}
	return answer;
}

int findEmployeeById(eEmployee* list, int len, int id, int* position)
{
	int answer = -1;
	int i;

	if(list != NULL && len > 0 && id >= 0)
	{
		for(i=0; i<len ;i++)
		{
			if(list[i].id == id)
			{
				*position = i;
				answer = 0;
				break;
			}
		}
	}
	return answer;
}

int sortEmployeesByLastNameSector(eEmployee* list,int len, int order)
{
	int answer = -1;
	int i;

	eEmployee buffer;

	if(list != NULL && len > 0 && order > 0)
	{
		switch(order)
		{
		case 1:
				for(i = 0; i < len - 1; i++)
				{
					for(int j=i+1;j < len;j++)
					{

							if(strcmp(list[j].lastName,list[i].lastName) < 0 )
							{
								buffer = list[i];
								list[i] = list[j];
								list[j] = buffer;
							}
							else if(strcmp(list[j].lastName,list[i].lastName) == 0 && list[j].sector < list[i].sector)
							{
								buffer = list[i];
								list[i] = list[j];
								list[j] = buffer;
							}
					}
				}
			answer = 0;
			break;

		case 2:

			for(i = 0; i < len - 1; i++)
			{
				for(int j=i+1;j < len;j++)
				{

						if(strcmp(list[j].lastName,list[i].lastName) > 0 )
						{
							buffer = list[i];
							list[i] = list[j];
							list[j] = buffer;
						}
						else if(strcmp(list[j].lastName,list[i].lastName) == 0 && list[j].sector > list[i].sector)
						{
							buffer = list[i];
							list[i] = list[j];
							list[j] = buffer;
						}
				}
			}
			answer = 0;
			break;
		}
	}
	return answer;
}

int averageSalary(eEmployee* list,int len)
{
	int answer = -1;
	int i;
	int salaryCount = 0;
	float salaryAcum = 0;
	float salaryTotal = 0;
	int salaryAverage = 0;

	if(list!= NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				salaryAcum += list[i].salary;
				salaryCount++;
			}
		}
		salaryTotal = salaryAcum/salaryCount;

		for (i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > salaryTotal)
			{
				salaryAverage++;
			}
		}
		    printf("\nTotal salary: %.2f ", salaryAcum);
		    printf("\nAverage Salary: %.2f ", salaryTotal);
		    printf("\nEmployees with Upper Average Salary : %d \n", salaryAverage);
		    answer = 0;
	}
	return answer;
}

int reportEmployee(eEmployee* list, int len)
{
	int answer = -1;
	int order= 0;

	if (list != NULL && len >0)
	{
		if(!utn_getNumero(&answer,
				"\n1)  Order Employee By Last Name & Sector Up/Down"
				"\n2)  Total & Average Salary, Employee Upper Average Salary"
				"\n3)  Return to the menu",
				"\nError option invalid",1,3,2))
			{
				switch(answer)
				{
					case 1:

						if(!utn_getNumero(&order,
						"\n1)  Order Employee By Last Name & Sector Up"
						"\n2)  Order Employee By Last Name & Sector Down",
						"\nError option invalid",1,2,2))
						{
							sortEmployeesByLastNameSector(list, len, order);
							printEmployees(list, len);
						}
						break;

					case 2:

						averageSalary(list, len);
						break;

					case 3:

						printf("\n Return to the menu");
						break;
					}
			}
	answer = 0;
	}
	return answer;
}

