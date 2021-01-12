/*
 ============================================================================
 Name        : TP Calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionestp.h"


int main(void) {

	int opcion;
	int respuesta;
	int x= 0;
	int y = 0;
	int flag = 0;
	int suma;
	int resta;
	int multiplicacion;
	long factoreoA;
	long factoreoB;
	float division;
	char numeroAuxStrA[256];
	char numeroAuxStrB[256];


	/* El usuario debe elegir una opcion para realizar el calculo correspondiente*/

	do
	{

	respuesta = utn_getNumero(&opcion,"\n\n>>> CALCULADORA TP 1 <<<\n\nSeleccione una opción.\n\n1. Ingresar 1er operando \n2. Ingresar 2do operando\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n","\n\nNo es una opcion valida. Por favor elija una opcion entre 1 y 5.",1,5,2);

	printf("\n\nA=%d",x);
	printf("  B=%d\n",y);

	if(!respuesta)
	{
		switch(opcion)
		{
		case 1:

			 if (!getStringNumeros("Ingrese un numero: ",numeroAuxStrA))
			{
				printf("Error, debe ingresar un numero\n");
			break;
			}
			x = atoi(numeroAuxStrA);

			break;

		case 2:

			 if (!getStringNumeros("Ingrese un numero: ",numeroAuxStrB))
					{
						printf("Error, debe ingresar un numero\n");
					break;
					}
					y = atoi(numeroAuxStrB);

					break;
		case 3:

			flag = 1;
			suma = sumar(x,y);
			resta = restar(x,y);
			multiplicacion = multiplicar (x,y);
			division = dividir (x,y);
			factoreoA = factorial(x);
			factoreoB = factorial(y);

			break;

		case 4:

			if (flag)
			{
				printf("\na) El resultado de A+B es: %d\n", suma);
				printf("\nb) El resultado de A-B es: %d\n", resta);

				if(division == 0)
				{
					printf("\nc) La division no es posible\n");
				}
				else
				{
					printf("\nc) El resultado de A/B es: %.2f\n",division);
				}

				printf("\nd) El resultado de A*B es: %d\n", multiplicacion);

				if(factoreoA <= 0)
				{
					printf("\ne) Factorial de A: error\n");
				}
				else
				{
					printf("\ne) Factorial de A es: %li\n",factoreoA);
				}

				if(factoreoB <= 0)
				{
					printf("\ne) Factorial de B: error\n");
				}
				else
				{
					printf("\ne) Factorial de B es: %li\n",factoreoB);
				}
			}
			else
			{
				printf("No se han calculado las operaciones.\n");
			}
			break;

		}
	}

	}while(opcion != 5);

	return 0;
}
