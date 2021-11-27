#ifndef ORDENAMIENTOS_H_
#define ORDENAMIENTOS_H_

#include "Localidades.h"
#include "Biblioteca.h"
#include "ArrayEmployees.h"
#include "ArrayPedidos.h"
#include "Controller.h"
#include "ArrayChoferes.h"


/*Imprime un submenu con opciones para armar listados
 *
 * parametros : tamaños de todas las estructuras(clientes, pedidos, localidades y choferes)
 *  			estructuras de pedido, localidad, cliente y choferes.
 *
 */
void Listados(ePedido* pedido, int tam_Pedido, eLocalidad* localidad, int tam_Localidad, eCliente*cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes);

/*
 * Ordena la lista de choferes por id
 * parametros: choferes_ estructura de choferes,  tam_Choferes tamaño de la estructura de choferes
 * retorna -1 si no pudo ordenar la lista o si ningun usuario de la lista estaba dado de alta
 * retorna 0 si pudo ordenar la lista
 */
int OrdenamientoPorId(eChofer* choferes, int tam_Choferes);

/*imprime una lista donde se muestran cada chofer con sus respectivos viajes
 *
 * parametros : tamaños de todas las estructuras(clientes, pedidos, localidades y choferes)
 *  			estructuras de pedido, localidad, cliente y choferes.
 *  retorna -1  si no encuentra ningun viaje realizado por ningun chofer
 *  retorna 0 si encuentra al menos un viaje
 */
int ViajesRealizadosPorCadaChofer(ePedido* pedido, int tam_Pedido, eCliente*cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes);

/*
 * Aumenta en un 15% el salario los choferes que hayan hecho al menos 3 viajes
 *
 * parametros : tamaños de todas las estructuras(clientes, pedidos, localidades y choferes)
 *  			estructuras de pedido, localidad, cliente y choferes.
 * retorna -1 si no consigue encontrar 3 viajes de algun chofer
 * retorna 0 si encuentra un chofer al que hacerle descuento.
 *
 */
int BonoPorViajes(ePedido* pedido, int tam_Pedido, eCliente*cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes);

/*
 * Muestra un chofer y a continuacion una seguidiila de localidades que este recorrio. si realizo dos pedidos seguidos en la misma localidad se evita imprimrila dos veces
 *
 * parametros : tamaños de todas las estructuras(clientes, pedidos, localidades y choferes)
 *  			estructuras de pedido, localidad, cliente y choferes.
 * retorna -1 si no encontro informacion para imprimr al menos un recorrido
 * retorna 0 si encuentra al menos un recorrido para imprimir
 *
 */
int LocalidadesRecorridasPorCadaChofer(ePedido* pedido, int tam_Pedido, eLocalidad* localidad, int tam_Localidad, eCliente*cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes);

/*
 * Muestra cual o cuales de todos los choferes tinee mas viajes realizados
 * parametros : tamaños de todas las estructuras(clientes, pedidos, y choferes)
 *  			estructuras de pedido, cliente y choferes.
 * retorna -1 si no encontro datos en las listas
 * retorna 0 si consiguio imprimir aunque sea un chofer
 */
int ChoferConMasViajes(ePedido* pedido, int tam_Pedido, eCliente*cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes);

/*
 * funcion dechofer con mas viajes para imprimr
 * utiliza los mismos parametros que la funcion ChoferConMasViajes
 *
 */
void MostrarChoferesConMasViajes(ePedido* pedido, int tam_Pedido, eCliente* cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes, int maximo);
#endif /* ORDENAMIENTOS_H_ */
