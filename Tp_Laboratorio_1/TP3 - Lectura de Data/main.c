#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

void menu();


int main()
{

	int option = 0;
	int change = 1;

    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados == NULL)
    {
    	printf("Error to create the list");
    }

    do{
    	change = ll_isEmpty(listaEmpleados);

    	menu();
    	utn_getNumero(&option,"Insert valid option:\n", "Error",1,10,2);

    	switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);

                break;

            case 2:
            	controller_loadFromBinary("data.csv",listaEmpleados);

            	break;

            case 3:

            	if(change == 0)
            	{
            		if(controller_addEmployee(listaEmpleados))
            		{
            			printf("\nAdd Succesfully\n");
            		}
            		else
            		{
            			printf("Error to add new employee");
            		}
            	}else
            	{
            		printf("Empty Employee");
            	}

            	break;

            case 4:

            	if(change == 0)
				{
					if(controller_editEmployee(listaEmpleados))
					{
						printf("\nModify Succesfully\n");
					}
					else
					{
						printf("Error to modify employee");
					}
				}else
					{
						printf("Empty Employee");
					}

            	break;

            case 5:

            	if(change == 0)
				{
					if(controller_removeEmployee(listaEmpleados))
					{
						printf("\nRemove Succesfully\n");
					}
					else
					{
						printf("Error to remove employee");
					}
				}else
					{
						printf("Empty Employee");
					}

            	break;

            case 6:

            	if(change == 0)
				{
					if(controller_ListEmployee(listaEmpleados))
					{
						printf("\nList Succesfully\n");
					}
					else
					{
						printf("Error to list employees");
					}
				}else
					{
						printf("Empty Employee");
					}

            	break;

            case 7:

            	if(change == 0)
				{
					if(controller_sortEmployee(listaEmpleados))
					{
						printf("\nSort Succesfully\n");
					}
					else
					{
						printf("Error to sort employees");
					}
				}else
					{
						printf("Empty Employee");
					}

				break;

            case 8:

            	if(change == 0)
				{
					if(controller_saveAsText("data.csv",listaEmpleados))
					{
						printf("\nSave Succesfully as a text\n");
					}
					else
					{
						printf("Error to save as a text");
					}
				}else
					{
						printf("Empty text");
					}

				break;

            case 9:

            	if(change == 0)
				{
					if(controller_saveAsBinary("data.bin",listaEmpleados))
					{
						printf("\nSave succesfully as a binary\n");
					}
					else
					{
						printf("Error to save as a binary");
					}
				}else
					{
						printf("Empty binary");
					}

				break;

        }
    }while(option != 10);

    return change;
}

void menu()
{

	printf(
			"\n	1.  Cargar los datos de los empleados desde el archivo data.csv (modo texto)"
			"\n	2.  Cargar los datos de los empleados desde el archivo data.csv (modo binario)"
			"\n	3.  Alta de empleado"
			"\n	4.  Modificar datos de empleado"
			"\n	5.  Baja de empleado"
			"\n	6.  Listar empleados"
			"\n	7.  Ordenar empleados"
			"\n	8.  Guardar los datos de los empleados en el archivo data.csv (modo texto)"
			"\n	9.  Guardar los datos de los empleados en el archivo data.csv (modo binario)"
			"\n	10. Salir\n"
			);
}
