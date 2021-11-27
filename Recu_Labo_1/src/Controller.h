//Nueva biblioteca de controllers.
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Biblioteca.h"
#include "ArrayEmployees.h"
#include "ArrayPedidos.h"
#include "Localidades.h"
#include "ArrayChoferes.h"
#include "Ordenamientos.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H
//funciones creadas en esta estapa del desarrollo del programa para faciliar la lectura. Tambien facilita la ejecucion de otras funciones
// si bien en el main no se utilia su retorno, estas lo tienen en caso de reutilizar el codigo en otro programa mas grande y que si sean necesarios

/*
 * controlador de la funcion de alta de cliente
 * valida que las listas no sean NULL
 * parametros: ListaDeClientes, array de clientes, tam_Clientes,tamaño de la lista de clientes, ListaDeLocalidades, array de localidades, tam_Localidades,tamaño de la lista de localidades
 * 				Id_Automatico, id que se le asignara al nuevo cliente.
 *retorna -1 si la funcion alta de cliente no pudo dar de alta un cliente o no se cumplieron las condiciones. retorna 0 si pudo
 */
int Controller_AltaCliente(eCliente* ListaDeClientes, int tam_Clientes,eLocalidad* ListaDeLocalidades, int tam_Localidades, int* Id_Automatico);

/*
 * controlador de la funcion de modificacion de cliente
 * valida que las listas no sean NULL y que al menos haya un cliente cargado
 * parametros: ListaDeClientes, array de clientes, tam_Clientes,tamaño de la lista de clientes, ListaDeLocalidades, array de localidades, tam_Localidades,tamaño de la lista de localidades
 *
 *retorna -1 si la funcion modificacion de cliente no pudo modificar un cliente o no se cumplieron las condiciones. retorna 0 si pudo
 */
int Controller_ModificacionCliente(eCliente* ListaDeClientes, int tam_Clientes,eLocalidad* ListaDeLocalidades, int tam_Localidades);

/*
 * controlador de la funcion de bja de cliente
 * valida que las listas no sean NULL y que al menos haya un cliente cargado en la lista
 * parametros: ListaDeClientes, array de clientes, tam_Clientes,tamaño de la lista de clientes, ListaDeLocalidades, array de localidades, tam_Localidades,tamaño de la lista de localidades
 *
 *retorna -1 si la funcion alta de cliente no pudo dar de baja un cliente o no se cuimplieron las condiciones. retorna 0 si pudo
 */
int Controller_BajaDeCliente(eCliente* ListaDeClientes, int tam_Clientes, eLocalidad* ListaDeLocalidades, int tam_localidades);

/*
 * controlador de la funcion crear pedido
 * valida que las listas no sean NULL y que exista al menos un cliente para asignarle un pedido
 * parametros: ListaDePedidos, array de pedidos, tamanio_Pedidos, tamaño del array pedidos, ListaDeClientes, array de clientes, tam_Clientes,tamaño de la lista de clientes,
 * 			    ListaDeLocalidades, array de localidades, tam_Localidades,tamaño de la lista de localidades, ListaDeChoferes array de choferes,tam_Choferes, tamaño del array de choferes
 * 			     idPedido,unico id asignado automaticamente
 * retorna -1 si la funcion no pudo cargar el pedido o no se cumnplieron las condiciones. retorna 0 pudo
 */
int Controller_CrearPedido(ePedido* ListaDePedidos, int tamanio_Pedidos, eCliente* ListaDeClientes, int tam_Clientes,eLocalidad* ListaDeLocalidades,
		int tam_localidades,eChofer* ListaDeChoferes, int tam_Choferes, int* idPedido );

/*
 * controlador de la funcion procesar residuos
 * valida que las listas no sean NULL , que exista al menos un cliente y que exista al menos un pedido
 * parametros: listaDePedidos, array de pedidos, tam_Pedidos,tamaño del array de pedidos, listaDeClientes,array de clinetes, tam_Clientes, tamaño del array de clientes
 *
 * retorna -1 si la funcion no pudo procesar un pedido o no cumplio con las condiciones. retorna 0 si se proceso un pedido
 */
int Controller_ProcesarResiduos(ePedido* listaDePedidos, int tam_Pedidos,eCliente* listaDeClientes, int tam_Clientes);

/*
 * controlador de la la funcion imprimir los clientes con pendientes
 * valida que las listas no sean NULL y que exista al menos un cliente y al menos un pedido pendiente
 * parametros: ListaDeClientes, array de clientes, tam_Clientes, tamaño del array de clintes, ListaDePedidos,array de pedidos ,
 * 				tam_Pedidos,tamaño del array de pedidos, ListaDeLocalidades,array de localidades,tam_Localidades tamaño del array de localidades
 * retorna -1 si la funcion no pudo imprimir los clientes con pendientes o si no cumplio con las condiciones. retorna 0 si pudo
 */

int Controller_ImprimirLosClientesConPendientes(eCliente* ListaDeClientes, int tam_Clientes,ePedido* ListaDePedidos, int tam_Pedidos, eLocalidad* ListaDeLocalidades, int tam_Localidades);

/*
 * controlador de la funcion imprimir pedidos pendientes
 * valida que las listas no sean null y que haya pedidos pendientes
 * parametros: listaDePedidos, array de pedidos, tam_Pedidos,tamaño del array de pedidos, listaDeClientes, array de clientes, tam_Clientes tamaño del array de clientes
 *
 * retorna -1 si la funcion no pudo imprimir los pedidos pendientes o si no cumplio con las condiciones. retorna 0 si imprimio la lista
 */
int Controller_ImprimirPendientes(ePedido* listaDePedidos, int tam_Pedidos, eCliente* listaDeClientes, int tam_Clientes);

/*
 * controlador de la funcion imprimir pedidos procesados
 * valida que las listas no sean null y que haya pedidos procesados
 * parametros: listaDePedidos, array de pedidos, tam_Pedidos,tamaño del array de pedidos, listaDeClientes, array de clientes, tam_Clientes tamaño del array de clientes
 *
 * retorna -1 si la funcion no pudo imprimir los pedidos procesados o si no cumplio con las condiciones. retorna 0 si imprimio la lista
 */
int Controller_ImprimirProcesados(ePedido* listaDePedidos, int tam_Pedidos, eCliente* listaDeClientes, int tam_Clientes);

/*
 * controlador de la funcion imprimir pendientes por localdiad
 * valida que ls listas no sean NULL, que haya pedidos pendientes y que exista al menos un cliente
 * parametros: listaDePedidos, array de pedidos, tam_Pedidos,tamaño del array de pedidos, listaDeClientes, array de clientes, tam_Clientes tamaño del array de clientes
 * 				ListaDeLocalidades,array de localidades, tam_Localidades tamaño del array de localidades
 * retorna -1 si no encontro pedidos para dicha localidad o no cumplio con las condiciones. retorna 0 si si encontro al menos un pedido para dicha localidad
 */
int Controller_ImprimirPedidosPendientesPorLocalidad(ePedido* listaDePedidos, int tam_Pedidos, eCliente* ListaDeClientes, int tam_Clientes, eLocalidad* ListaDeLocalidades, int tam_Localidades);

/*
 * controlador creado para ejecutar mas de un promedio. para el examen se pidio solo uno
 * valida que las listas no sean null. y que las listas esten cargadas
 * parametros:ListaDeClientes,array de clientes, tam_Clientes, tamaño de la lista de clientes, listaDePedidos, array de pedidos,tam_Pedidos tamaño de la lista de pedidos
 * retorna -1 si no encontro kg de polipropileno en los pedidos o si no cumplio con ls condiciones. retorna 0 en caso de encontrar kilos de polipropileno
 */
int Controller_Promedios(eCliente* ListaDeClientes, int tam_Clientes, ePedido* listaDePedidos, int tam_Pedidos);

/*
 *controlador de la funcion mas pedidos pendientes
 * vvalida que la lista este cargada y que existan pedidos pendientes
 *  parametros: listaDePedidos array de pedidos, tam_Pedidos tamaño de la lista de pedidos, ListaDeClientes, array de clientes, tam_Clientes, tamaño de la lista de clientes
 *  			 ListaDeLocalidades, array de localidades, tam_Localidades, tamaño de la lista de localidades
 * retorna -1 si no cumplio con las condiciones. retorna 0 si pudo ejecutar la funcion
 */
int Controller_MasPedidosPendientes(ePedido* listaDePedidos, int tam_Pedidos, eCliente* ListaDeClientes, int tam_Clientes, eLocalidad* ListaDeLocalidades, int tam_Localidades);

/*
 *controlador de la funcion mas pedidos procesados
 * vvalida que la lista este cargada y que existan pedidos procesados
 *  parametros: listaDePedidos array de pedidos, tam_Pedidos tamaño de la lista de pedidos, ListaDeClientes, array de clientes, tam_Clientes, tamaño de la lista de clientes
 *  			 ListaDeLocalidades, array de localidades, tam_Localidades, tamaño de la lista de localidades
 * retorna -1 si no cumplio con las condiciones. retorna 0 si pudo ejecutar la funcion
 */
int Controller_MasPedidosProcesados(ePedido* listaDePedidos, int tam_Pedidos, eCliente* ListaDeClientes, int tam_Clientes, eLocalidad* ListaDeLocalidades, int tam_Localidades);

/*
 * controlador de la funcion manejo de choferes
 * verifica que la lista de choferes no sea NULL
 * parametros: listaDeChoferes, array de choferes, tam_Choferes, tamaño del array de choferes, *idChofer, id unico del chofer
 *
 * retorna -1 si no cumplio con las condiciones, retorna 0 si pudo ejecutar la funcion
 */
int Controller_ManejoDeChoferes(eChofer* listaDeChoferes, int tam_Choferes, int* idChofer);

/*
 *controlador de la funcion listados
 * verifica que las listas no sean null y esten todas cargadas
 * parametros: pedido, array de pedidos, tam_pedido, tamaño del array de pedidos, localidad, array de localidad, tam_localidad, tamaño del array de localidad,
 * 				cliente, array de cliente, tam_cliente tamaño del array de clintes, chofer array de choferes, tam_choferes, tamaño del array de choferes
 *retorna -1 si no cumplio con las condiciones, retorna 0 si pudo ejecutar la funcion
 */
int Controller_Listados(ePedido* pedido,int tam_Pedido, eLocalidad* localidad, int tam_Localidad, eCliente* cliente, int tam_CLiente, eChofer* chofer, int tam_Choferes);
#endif




