
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

int controller_nextId(LinkedList* pArrayListEmployee)
{
	int len = ll_len(pArrayListEmployee);
	int auxId = 0;
	int i;

	Employee* aux;

	for(i = 0; i < len ; i++)
	{
		aux = ll_get(pArrayListEmployee,i);

		if(aux->id > auxId)
		{
			auxId = aux->id;
		}
	}
	return auxId+1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int back = 0;

	FILE* pFile = fopen(path,"r");

	if(pFile == NULL)
	{
		printf("File doesn`t exist");
	}
	else
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);

		back = 1;

		printf("Text Load Succesfully");
	}

	return back;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	int back = 0;

	FILE* pFile = fopen(path,"rb");

	if(pFile == NULL)
	{
		printf("File doesn`t exist");
	}
	else
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		printf("Binary Load Succesfully");

		back = 1;
	}

	return back;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int back = 0;
    int auxId = 0;
    char auxName[128];
    int auxHs;
    int auxSalary;

    Employee* newEmployee;

    if(pArrayListEmployee != NULL)
    {
    	auxId = controller_nextId(pArrayListEmployee);

    	if(utn_getNombre(auxName,128,"\nPlease, insert name:\n","\nERROR\n",2) == 0
    	&& utn_getNumero(&auxHs,"Insert working hs (1-1000):\n", "Error", 1,1000,2) == 0 &&
    	utn_getNumero(&auxSalary,"Insert salary (1000 - 50000):\n","Error", 1000,50000,2) == 0)

    	{

    		newEmployee = employee_new();

    		if(newEmployee != NULL)
    		{
    			employee_setId(newEmployee,auxId);
				employee_setNombre(newEmployee,auxName);
				employee_setHorasTrabajadas(newEmployee, auxHs);
				employee_setSueldo(newEmployee, auxSalary);

    			if(ll_add(pArrayListEmployee, newEmployee) == 0)
    			{

					back = 1;
    			}

    		}

			else
			{
				printf("Add Error");
			}

    	}
    }
	return back;
}

































/*
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int back = 0;
    int auxId = 0;
    char auxIdStr[35];
    char auxName[128];
    char auxHs[35];
    char auxSalary[35];

    Employee* newEmployee = employee_new();

    if(pArrayListEmployee != NULL && newEmployee != NULL)
    {
    	auxId = controller_nextId(pArrayListEmployee);
    	sprintf(auxIdStr,"%d",auxId);

    	utn_getNombre(auxName,128,"\nPlease, insert name:\n","\nERROR\n",2);
    	utn_getTexto("Insert working hs (1-1000):\n","Error", 1,100,2, auxHs);
    	utn_getTexto("Insert salary (1000 - 50000):\n","Error",1,100,2, auxSalary);

    	newEmployee = employee_newParametros(auxIdStr,auxName,auxHs,auxSalary);

    	if(newEmployee != NULL)
    	{
    		ll_add(pArrayListEmployee, newEmployee);
    		printf("Add Succesfully.\n");
    		back = 1;
    	}

    	else
    	{
    		printf("Add Error");
    	}

    }

	return back;
}
*/
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int auxId;
	int i;
	int back = 0;
	Employee* aux;
	int answer;
	int len = ll_len(pArrayListEmployee);
	char auxName[50];
	int auxHs;
	int auxSalary;


	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		utn_getNumero(&auxId,"\nPlease, insert ID to modify:\n","ID Not Found",1,len,2);

		for(i=0; i < len;i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee,i);

			if(auxId == aux ->id)
			{
				do
				{
					employee_print(aux);

					utn_getNumero(&answer,
							"\n	Modify"
							"\n	1. Name "
							"\n	2. Working Hours "
							"\n	3. Salary "
							"\n	4. Exit",
							"\n Error option invalid\n",1,4,2);

					switch(answer)
					{
						fflush(stdin);

						case 1:

							if(utn_getNombre(auxName,50,"\nInsert name: ","\nError",2) == 0)
								{
									employee_setNombre(aux,auxName);
								}
							break;

						case 2:
							if(utn_getNumero(&auxHs,"\nInsert working hours (10 - 500 ): ","\nError",1,500,2)== 0)
							{
									employee_setHorasTrabajadas(aux,auxHs);
							}
							break;

						case 3:
							if(utn_getNumero(&auxSalary,"\nInsert salary(1000 - 50000): ","\nError",1000,50000,2) == 0)
							{
								employee_setSueldo(aux,auxSalary);
							}
							break;

						case 4:
								printf("\nExit\n");
							break;
						default: printf("\nInsert a valid option !\n");
					}
				}while(answer != 4);
			}
		}
	back = 1;
	}
	return back;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

	int auxId = 0;
	int i;
	int change = 0;
	int changeRemove = 0;
	int index = 0;
	int answer = 0;
	int len = ll_len(pArrayListEmployee);

	Employee* aux;

	controller_ListEmployee(pArrayListEmployee);


	utn_getNumero(&auxId, "\nPlease, insert ID to modify:\n", "\nERROR\n", 1, len,2);

	for(i=0; i < len; i++)
	{
		aux = (Employee*) ll_get(pArrayListEmployee,i);

		if(auxId == aux->id)
		{
			change = 1;
			index = i;
		}
	}
	if(change)
	{
		employee_print(aux);
		utn_getNumero(&answer,"\n	1. Confirm Remove\n " "\n	2. Exit\n","\n Error option invalid",1,2,2);

		if(answer == 1)
		{
			if(!ll_remove(pArrayListEmployee, index))
			{
				changeRemove = 1;
			}
		}
		else
		{
			printf("Error");
		}

	}

	return changeRemove;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	Employee* aux;
	int back = 0;

	if(pArrayListEmployee != NULL)
	{
		for(i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee,i);
			employee_print(aux);
			back = 1;
		}
	}
	else
	{
		printf("Error");
	}

	return back;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

	int back = 0;
	int i;
	int j;
	int len = ll_len(pArrayListEmployee);

	Employee* employee1 = employee_new();
	Employee* employee2 = employee_new();

	if(employee1 != NULL && employee2 != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			for(j = i+1; j < len; j++)
			{
				employee1 = ll_get(pArrayListEmployee,i);
				employee2 = ll_get(pArrayListEmployee,j);

				if(strcmp(employee1->nombre,employee2->nombre) > 0)
				{
					ll_set(pArrayListEmployee,j,employee1);
					ll_set(pArrayListEmployee,i,employee2);
				}

			}
		}

		back = 1;

		printf("Sort Employee by name");
	}

	return back;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int back = 0;
	int i;
	int len = ll_len(pArrayListEmployee);
	Employee* employee = employee_new();

	if(len == 0)
	{
		printf("Empty List");
	}

	else
	{
		FILE *pFile = fopen(path,"w");

		if(employee != NULL && pFile != NULL && pArrayListEmployee != NULL)
		{
			fprintf(pFile,"ID, Name, Working Hours, Salary");

			for(i=0;i < len ;i++)
			{
				employee = ll_get(pArrayListEmployee,i);
				fprintf(pFile,"%d,%s,%d,%d\n", employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);
			}
			back = 1;
		}
		fclose(pFile);
	}

	return back;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int back = 0;
	int i;
	int len = ll_len(pArrayListEmployee);
	Employee* employee = employee_new();

	if(len == 0)
	{
		printf("Empty List");
	}

	else
	{
		FILE *pFile = fopen(path,"wb");

		if(employee != NULL && pFile != NULL && pArrayListEmployee != NULL)
		{
			for(i=0;i < len ;i++)
			{
				employee = ll_get(pArrayListEmployee,i);
				fwrite(employee,sizeof(Employee),1,pFile);
			}
			back = 1;
		}
		fclose(pFile);
	}
    return back;
}

