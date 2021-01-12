/*
 * cliente.c
 *
 *  Created on: 16 may. 2020
 *      Author: lucasgiosso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "utn.h"

int menu()
{
	int respuesta = -1;

	utn_getNumero(&respuesta,
									"\n      · ········································································ ·"
									"\n      ·                    1)  	Alta Cliente                              ·"
									"\n      ·                    2)  	Modificar Cliente                     ·"
									"\n      ·                    3)  	Baja Cliente                              ·"
									"\n      ·                    4)  	Creación Préstamo                  ·"
						            "\n      ·                    5)  	Saldar Préstamo                      ·"
						            "\n      ·                    6)  	Reanudar Préstamo                 ·"
									"\n      ·                    7)  	Imprimir Clientes                      ·"
									"\n      ·                    8)  	Imprimir Préstamos                 ·"
									"\n      ·                    9)  	Informar Clientes                     ·"
									"\n      ·                    10)  Informar Préstamos                ·"
									"\n      ·                    11)  Salir                                          ·"
									"\n      · ········································································ ·",
									"\n                            Error opción invalida",1,11,2);

	return respuesta;
}

int inicializarCliente(eClientes* clientes, int tam)
{
	int respuesta = -1;

	if(clientes!= NULL && tam > 0)
	{

		for (int i=0; i < tam; i++)
		{
			clientes[i].idCliente = 0;
			clientes[i].isEmptyCliente = 0;
			respuesta = 0;
		}
	}
	return respuesta;
}

int imprimirClientes(eClientes* clientes, int tam)
{
	int respuesta = 0;

	for(int i = 0; i< tam ; i++)
	{
		if(clientes[i].isEmptyCliente == 1)
			{
			printf("%10d  %15s  %15s  %20s\n", clientes[i].idCliente,clientes[i].nombreCliente, clientes[i].apellidoCliente, clientes[i].cuilCliente);
						respuesta = 1;
			}
	}
	if(respuesta == 0)
	{
		printf(" No hay clientes");
	}
	return respuesta;
}

int buscarClienteLibre(eClientes* clientes, int tam)
{
	int respuesta = -1;

	for(int i = 0; i < tam; i++)
	{
		if(clientes[i].isEmptyCliente == 0)
		{
			respuesta = i;
			break;
		}
	}
	return respuesta;
}

int buscarClienteXId(eClientes* clientes, int tam, int IdCliente)
{
	int respuesta = -1;

	for(int i = 0; i < tam; i++)
	{
		if(clientes[i].idCliente == IdCliente && clientes[i].isEmptyCliente == 1)
		{
			respuesta = i;
			break;
		}
	}
	return respuesta;
}

int proximoIdCliente(eClientes* clientes, int tam)
{
	    int respuesta = 0;
	    int i;

	    for(i=0; i<tam; i++)
	    {
	        if(clientes[i].idCliente>respuesta)
	        {
	        	respuesta=clientes[i].idCliente;
	        }
	    }
	    return respuesta+1;
	}

int altaCliente(eClientes* clientes, int tam)
{
	int respuesta = -1;
	int auxIdCliente;
	char auxNombre[51];
	char auxApellido[51];
	char auxCuil[51];
	int indice;

	if(clientes!=NULL && tam>0)
	    {

					indice = buscarClienteLibre(clientes, tam);

					if(indice == -1)
					{
								printf("No hay lugar para almacenar un nuevo cliente");
					}

					else
					{
					auxIdCliente = proximoIdCliente(clientes, tam);
					printf("Su codigo de cliente es: %d\n", auxIdCliente);

					utn_getNombre(auxNombre,51,"\nPor favor, ingrese nombre:\n","\nERROR\n",2);
					strcpy(clientes[indice].nombreCliente,auxNombre);

					utn_getNombre(auxApellido,51,"\nPor favor, ingrese apellido:\n","\nERROR\n",2);
					strcpy(clientes[indice].apellidoCliente,auxApellido);

					utn_getCuil(auxCuil,14,"\nPor favor, ingrese cuil (ej xx-xxxxxxxx-x):\n","Error option invalid",2);
					strcpy(clientes[indice].cuilCliente,auxCuil);

					clientes[indice].isEmptyCliente = 1;
					clientes[indice].idCliente = auxIdCliente;
					clientes[indice].prestamoActivoCliente = 0;
					clientes[indice].prestamosSaldoCliente = 0;
					auxIdCliente++;

					printf("Alta Correcta");
				}

	    }

	return respuesta;
}

int menuModificarCliente()
{
		int respuesta = -1;

		utn_getNumero(&respuesta,
										"\n      · Elegir campo a modificar   "
										"\n      · ·········································· ·"
										"\n      ·            1)  	Nombre            		  ·"
										"\n      ·            2)  	Apellido            	  ·"
										"\n      ·            3)  	Cuil                      ·"
										"\n      ·            4)  	Salir                     ·"
										"\n      · ········································· ·",
										"\n         Error opción invalida",1,4,2);

		return respuesta;
	}

int modificarCliente(eClientes* clientes, int tam)
{
	int respuesta = -1;
	int auxIdCliente;
	char auxNombre[51];
	char auxApellido[51];
	char auxCuil[51];
	int indice;
	int mostrar = imprimirClientes(clientes, tam);
	char estaSeguro = 'N';

	if(mostrar == 0)
	{
		printf("Modificar");
	}
	else
	{
		printf("Ingrese el ID a modificar:");
		scanf("%d",&auxIdCliente);
		indice = buscarClienteXId(clientes,tam,auxIdCliente);

		if(indice == -1)
		{
			printf("No se encontre el cliente");
		}
		else
		{
				do
				{
					switch(menuModificarCliente())
					{
							case 1:

								printf("El nombre actual es: %s\n", clientes[indice].nombreCliente);
								utn_getNombre(auxNombre,51,"\nPor favor, ingrese nuevo nombre:\n","\nERROR\n",2);
								printf("El nombre actual es: %s\n", auxNombre);

								printf("Esta seguro que desea modificarlo? (S/N): ");
								fflush(stdin);
								scanf("%c", &estaSeguro);

								while (estaSeguro != 'S' && estaSeguro != 'N' && estaSeguro != 's' && estaSeguro != 'n'  )
								{
									printf("Esta seguro que desea modificarlo? (S/N): ");
									fflush(stdin);
									scanf("%c", &estaSeguro);

									if(estaSeguro == 'S' )
											{
												strcpy(clientes[indice].nombreCliente,auxNombre);
											}
								}
								break;

							case 2:

									printf("El apellido actual es: %s\n", clientes[indice].apellidoCliente);
									utn_getNombre(auxApellido,51,"\nPor favor, ingrese nuevo apellido:\n","\nERROR\n",2);
									printf("El nombre actual es: %s\n", auxApellido);

									printf("Esta seguro que desea modificarlo? (S/N): ");
									fflush(stdin);
									scanf("%c", &estaSeguro);

									while (estaSeguro != 'S' && estaSeguro != 'N' && estaSeguro != 's' && estaSeguro != 'n'  )
									{
										printf("Esta seguro que desea modificarlo? (S/N): ");
										fflush(stdin);
										scanf("%c", &estaSeguro);

										if(estaSeguro == 'S' )
												{
													strcpy(clientes[indice].apellidoCliente,auxNombre);
												}
									}
								break;

							case 3:

									printf("El cuil actual es: %s\n", clientes[indice].cuilCliente);
									utn_getNombre(auxCuil,51,"\nPor favor, ingrese nuevo apellido:\n","\nERROR\n",2);
									printf("El nombre actual es: %s\n", auxCuil);

									printf("Esta seguro que desea modificarlo? (S/N): ");
									fflush(stdin);
									scanf("%c", &estaSeguro);

									while (estaSeguro != 'S' && estaSeguro != 'N' && estaSeguro != 's' && estaSeguro != 'n'  )
									{
										printf("Esta seguro que desea modificarlo? (S/N): ");
										fflush(stdin);
										scanf("%c", &estaSeguro);

										if(estaSeguro == 'S' )
												{
													strcpy(clientes[indice].cuilCliente,auxNombre);
												}
									}
								break;

							default:
								printf("Ingrese una opcion correcta\n");
					}
				}while(respuesta == 4);
		}
	}
	return respuesta;
}

int bajaCliente(eClientes* clientes, int tam)
{
	int indice;
	int auxIdCliente;
	int respuesta = imprimirClientes(clientes, tam);
	char estaSeguro = 'N';

	if(respuesta == 0)
	{
		printf("Baja");
	}
	else
	{
		printf("Ingrese el codigo a dar de baja:");
		scanf("%d", &auxIdCliente);
		indice = buscarClienteXId(clientes,tam,auxIdCliente);

		if(indice == -1)
		{
			printf("No se encontro el cliente solicitado");
		}
		else
		{
			printf("Esta seguro que desea eliminar? (S/N): ");
			fflush(stdin);
			scanf("%c", &estaSeguro);

			while (estaSeguro != 'S' && estaSeguro != 'N' && estaSeguro != 's' && estaSeguro != 'n'  )
			{
				printf("Esta seguro que desea eliminar? (S/N): ");
				fflush(stdin);
				scanf("%c", &estaSeguro);
			}
				if(estaSeguro == 'S' || estaSeguro == 's' )
				{
							clientes[indice].isEmptyCliente = 0;
							printf("Baja Correcta");
				}
				else
				{
					printf("No se dio de baja al cliente");
				}

		}
	}
	return 0;
}

int informeClientes(eClientes* clientes, int tam)
{
	int respuesta = -1;
	int i;
	int opcion = 0;
	int mayorCliente = 0;
	char auxNombre[51];
	char auxApellido[51];
	char auxCuil[51];
	int idCliente;

	if(clientes != NULL && tam > 0)
	{
		utn_getNumero(&opcion,"El estado es: \n 1) Clientes con mas prestamos activos. \n2) Clientes con mas prestamos saldados. \n 3) Salir\n Ingrese Opcion:"
											,"\n Error opción invalida",1,3,2);

		switch(opcion)
		{

		case 1:
			for(i = 0; i < tam; i++)
			{
				if(clientes[i].isEmptyCliente == 1)
				{

				}

				if(clientes[i].prestamoActivoCliente > mayorCliente )
				{
					mayorCliente = clientes[i].prestamoActivoCliente;
					idCliente = clientes[i].idCliente;
					strcpy(auxNombre,clientes[i].nombreCliente);
					strcpy(auxApellido,clientes[i].apellidoCliente);
					strcpy(auxCuil,clientes[i].cuilCliente);
				}
			}

			printf("ID Cliente: %d  Nombre: %s\n   Cuil: %s\n Clientes con mas prestamos activos: %d", idCliente,auxNombre,auxApellido,auxCuil,mayorCliente);
			break;

		case 2:
					for(i = 0; i < tam; i++)
					{
						if(clientes[i].isEmptyCliente == 1)
						{

						}

						if(clientes[i].prestamosSaldoCliente > mayorCliente )
						{
							mayorCliente = clientes[i].prestamosSaldoCliente;
							idCliente = clientes[i].idCliente;
							strcpy(auxNombre,clientes[i].nombreCliente);
							strcpy(auxApellido,clientes[i].apellidoCliente);
							strcpy(auxCuil,clientes[i].cuilCliente);
						}
					}

					printf("ID Cliente: %d  Nombre: %s\n   Cuil: %s\n Clientes con mas prestamos pagos: %d", idCliente,auxNombre,auxApellido,auxCuil,mayorCliente);
					break;
		case 3:
			break;
		default:
			printf("Ingrese una opcion correcta");
		}
		respuesta = 0;
	}

	return respuesta;
}

int informeClientesC(eClientes* clientes, int tam)
{
	int respuesta = -1;
	int i;
	int opcion = 0;
	int mayorCliente = 0;
	char auxNombre[51];
	char auxApellido[51];
	char auxCuil[51];
	int idCliente;

	if(clientes != NULL && tam > 0)
	{
		utn_getNumero(&opcion,"El estado es: \n 1) Clientes con mas prestamos activos. \n2) Clientes con mas prestamos saldados. \n 3) Salir\n Ingrese Opcion:"
											,"\n Error opción invalida",1,3,2);


			for(i = 0; i < tam; i++)
			{
				if(clientes[i].isEmptyCliente == 1)
				{

				}

				if(clientes[i].prestamoActivoCliente > mayorCliente )
				{
					mayorCliente = clientes[i].prestamoActivoCliente;
					idCliente = clientes[i].idCliente;
					strcpy(auxNombre,clientes[i].nombreCliente);
					strcpy(auxApellido,clientes[i].apellidoCliente);
					strcpy(auxCuil,clientes[i].cuilCliente);
				}
			}

			printf("ID Cliente: %d  Nombre: %s\n   Cuil: %s\n Clientes con mas prestamos activos: %d", idCliente,auxNombre,auxApellido,auxCuil,mayorCliente);
			break;

		}
		respuesta = 0;

	return respuesta;
}
