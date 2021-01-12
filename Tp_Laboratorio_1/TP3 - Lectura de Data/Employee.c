#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "utn.h"



Employee* employee_new()
{
	Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

	if(newEmployee != NULL)
	{
		newEmployee->id = 0;
		strcpy(newEmployee->nombre, " ");
		newEmployee->horasTrabajadas = 0;
		newEmployee->sueldo  = 0;
	}
	return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee = employee_new();

	int change = 0;

	if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
		{

			employee_setId(newEmployee, atoi(idStr));
			employee_setNombre(newEmployee,nombreStr);
			employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
			employee_setSueldo(newEmployee, atoi(sueldoStr));

			change = 1;

		}

		if(change == 0)
		{
			free(newEmployee);
			newEmployee = NULL;
		}

	return newEmployee;
}

int employee_setId(Employee* this,int id)
{
	int change = 0;

	if(this != NULL && id > 0)
	{
		this ->id = id ;
		change = 1;
	}
	return change;
}

int employee_getId(Employee* this,int* id)
{
	int change = 0;

		if(this != NULL && id != NULL)
		{
			*id = this ->id;
			change = 1;
		}
		return change;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int change = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		change = 1;
	}
	return change;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int change = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		change = 1;
	}
	return change;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int change = 0;

		if(this != NULL && horasTrabajadas > 0)
		{
			this->horasTrabajadas = horasTrabajadas;
			change = 1;
		}
		return change;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int change = 0;

		if(this != NULL && horasTrabajadas != NULL)
		{
			*horasTrabajadas = this ->horasTrabajadas;
			change = 1;
		}
		return change;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int change = 0;

		if(this != NULL && sueldo > 0 && sueldo < 100000)
		{
			this ->sueldo = sueldo;
			change = 1;
		}
		return change;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int change = 0;

		if(this != NULL && sueldo != NULL)
		{
			*sueldo = this ->sueldo;
			change = 1;
		}
		return change;
}

void employee_delete(Employee* this)
{

}

void employee_print(Employee* this)
{
	int auxId;
	char auxName[35];
	int auxHsTrabajadas;
	int auxSueldo;

	employee_getId(this, &auxId);
	employee_getNombre(this,auxName);
	employee_getHorasTrabajadas(this,&auxHsTrabajadas);
	employee_getSueldo(this,&auxSueldo);

	printf("ID: %5d \tName: %10s \tHoras Trabajadas: %5d \tSueldo: %5d\n",auxId,auxName,auxHsTrabajadas,auxSueldo);
}




