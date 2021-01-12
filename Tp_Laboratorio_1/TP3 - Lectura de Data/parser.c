#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int count;
	int back = 0;
	char auxId[30];
	char auxName[150];
	char auxHs[35];
	char auxSalary[35];
	//Employee* aux;

	if((pFile = fopen("data.csv","r")) != NULL && pArrayListEmployee != NULL)
		{
			ll_clear(pArrayListEmployee);
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]",auxId,auxName,auxHs,auxSalary);

			while(!feof(pFile))
			{
				count = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]",auxId,auxName,auxHs,auxSalary);

				if(count == 4)
				{
					Employee* aux = employee_newParametros(auxId,auxName,auxHs,auxSalary);
					ll_add(pArrayListEmployee,aux);
					back = 1;
				}

				else if(count != 4)
				{

					if(feof(pFile))
					{
						break;
					}

					else
					{
						printf("Don`t read last register\n");
						back = 0;
						break;
					}


				}
			}
		}
			fclose(pFile);
    return back;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int count;
	int back = 0;
	Employee* aux;

	ll_clear(pArrayListEmployee);
	while(!feof(pFile))
	{
		aux = employee_new();
		count = fread(aux,sizeof(Employee),1,pFile);

			if(aux != NULL && count == 1)
			{
				ll_add(pArrayListEmployee, aux);
				back = 1;
			}
			else if(count != 1)
			{
				if(feof(pFile))
				{
					break;
				}
				else
				{
					printf("Don`t read last register\n");
					back = 0;
					break;
				}
			}
	}
	fclose(pFile);
    return back;
}
