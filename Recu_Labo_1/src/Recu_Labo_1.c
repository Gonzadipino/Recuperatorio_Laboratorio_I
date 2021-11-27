/*
 ============================================================================
 Name        : Recu_Labo_1.c
 Author      : DI PINO GONZALO
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Localidades.h"
#include "Biblioteca.h"
#include "ArrayEmployees.h"
#include "ArrayPedidos.h"
#include "Controller.h"
#include "ArrayChoferes.h"

#define ACTIVO 1
#define INACTIVO 0

#define TAM_CLIENTES 1000
#define TAM_PEDIDOS  100
#define TAM_LOCALIDADES 300
#define TAM_CHOFERES 20

#define PENDIENTE 0
#define PROCESADO 1


int main() {

    setbuf(stdout,NULL);


    eCliente      listaDeClientes[TAM_CLIENTES] = {{0001,"Pirelli",12345,"udaondo", 100,23,ACTIVO}, // altura, localidad, estado
                                                  {0002,"Bridgestone",23456,"Casares", 1221,4,ACTIVO},
                                                  {0003,"Michellin",34567,"Pilcomayo", 2345,5,ACTIVO},
                                                  {0004,"Dunlop",34555,"Hipolito Yrigoyen", 6575,94,ACTIVO},
                                                  {0005,"Continental",32455,"Ferre", 788,6,ACTIVO},
                                                  {0006,"Firestone",45678,"Oncativo", 1221,43,ACTIVO},
                                                  {0007,"GoodYear",56789,"Belgrano", 2345,78,ACTIVO},
                                                  {8,"Uniroyal",67890,"Rosas", 6575,9,ACTIVO}};

    ePedido       listaDePedidos[TAM_PEDIDOS] = {{1,1,230,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,2},
                                                   {2,2,250,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,3},
                                                   {3,2,159,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,4},
                                                   {4,2,1200,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,1},
                                                   {5,5,500,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,1},
                                                   {6,6,245,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,2},
                                                   {7,7,220,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,3},
                                                   {8,8,990,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,4},
												   {9,1,230,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,1},
												   {10,2,250,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,3},
												   {11,3,159,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,2},
												   {12,4,1200,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,4},
												   {13,5,500,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,1},
												   {14,6,245,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,1},
												   {15,7,220,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,2},
												   {16,8,990,0,0,0,0,PENDIENTE,"PENDIENTE",ACTIVO,2}};

    eLocalidad    listaDeLocalidades[TAM_LOCALIDADES];

    eChofer 		listaDeChoferes[TAM_CHOFERES] = {{1,"Juan Carlos", 23000,14,ACTIVO},/////////////
    												{2,"Julio Sosa", 40000,16,ACTIVO},
													{3,"Pedro Gopar", 12000,30,ACTIVO},
													{4,"Ricardo Fort", 55000,17,ACTIVO}};

    int idAutomatico = 1;
    int opcion;
    int idPedido = 1;
    int idChofer = 1;
    cargaDeCiudades("CiudadesConurbano.csv", listaDeLocalidades,TAM_LOCALIDADES);///////////////
    //InicializarLista(listaDeClientes, TAM_CLIENTES);
    //InicializarListaPedidos(listaDePedidos,TAM_PEDIDOS);
    //InicializarListaDeChoferes(listaDeChoferes, TAM_CHOFERES);

    do {

       system("cls");
        printf("\n******************************PRIMER PARCIAL*****ALUMNO DI PINO GONZALO*****DIVISION F*****TURNO NOCHE******************************\n");
        printf(" 1 - ALTA DE CLIENTE\n 2 - MODIFICACION DE CLIENTE\n 3 - BAJA DE CLIENTE\n 4 - CREAR PEDIDOS DE RECOLECCION\n 5 - PROCESAR RESIDUOS\n 6 - IMPRIMIR CLIENTES\n");
        printf(" 7 - IMPRIMIR PEDIDOS PENDIENTES\n 8 - IMPRIMIR PEDIDOS PROCESADOS\n 9 - PEDIDOS PENDIENTES POR LOCALIDAD\n10 - PROMEDIOS\n11 - MAS PEDIDOS PENDIENTES\n");
        printf("12 - MAS PEDIDOS PROCESADOS\n13 - CHOFERES\n14 - LISTADOS\n\n 0 - SALIR\n\n");

        opcion = LoadInt(" OPCION:",0,14); //cantidad de opciones del menu.

            system("cls");
            printf("\n");
            switch(opcion) {
                case 1:
                	Controller_AltaCliente(listaDeClientes, TAM_CLIENTES, listaDeLocalidades, TAM_LOCALIDADES, &idAutomatico);
                	break;

                case 2:
                	Controller_ModificacionCliente(listaDeClientes, TAM_CLIENTES, listaDeLocalidades, TAM_LOCALIDADES);
                	break;

                case 3:
                	Controller_BajaDeCliente(listaDeClientes, TAM_CLIENTES, listaDeLocalidades, TAM_LOCALIDADES);
                	break;

                case 4:
                	Controller_CrearPedido(listaDePedidos, TAM_PEDIDOS, listaDeClientes, TAM_CLIENTES, listaDeLocalidades,TAM_LOCALIDADES,listaDeChoferes,TAM_CHOFERES, &idPedido);
                	break;

                case 5:
                	Controller_ProcesarResiduos(listaDePedidos, TAM_PEDIDOS, listaDeClientes, TAM_CLIENTES);
                	break;

                case 6:
                	Controller_ImprimirLosClientesConPendientes(listaDeClientes, TAM_CLIENTES,listaDePedidos,TAM_PEDIDOS, listaDeLocalidades, TAM_LOCALIDADES);
					break;

                case 7:
                	Controller_ImprimirPendientes(listaDePedidos, TAM_PEDIDOS, listaDeClientes, TAM_CLIENTES);
                	break;

                case 8:
                	Controller_ImprimirProcesados(listaDePedidos, TAM_PEDIDOS, listaDeClientes, TAM_CLIENTES);
                	break;

                case 9:
                	Controller_ImprimirPedidosPendientesPorLocalidad(listaDePedidos, TAM_PEDIDOS,listaDeClientes, TAM_CLIENTES, listaDeLocalidades, TAM_LOCALIDADES);
                	break;

                case 10:
                	Controller_Promedios(listaDeClientes, TAM_CLIENTES, listaDePedidos, TAM_PEDIDOS);
                	break;

                case 11:
                	Controller_MasPedidosPendientes(listaDePedidos, TAM_PEDIDOS, listaDeClientes, TAM_CLIENTES, listaDeLocalidades, TAM_LOCALIDADES);
                	break;

                case 12:
                	Controller_MasPedidosProcesados(listaDePedidos, TAM_PEDIDOS, listaDeClientes, TAM_CLIENTES, listaDeLocalidades, TAM_LOCALIDADES);
                	break;
                case 13:
                	Controller_ManejoDeChoferes(listaDeChoferes, TAM_CHOFERES, &idChofer);
                	break;
                case 14:
                	Controller_Listados(listaDePedidos, TAM_PEDIDOS, listaDeLocalidades, TAM_LOCALIDADES, listaDeClientes, TAM_CLIENTES, listaDeChoferes, TAM_CHOFERES);
                	break;
        }

    } while(opcion != 0);

    return 0;
}
