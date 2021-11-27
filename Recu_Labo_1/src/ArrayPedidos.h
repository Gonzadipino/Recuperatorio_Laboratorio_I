#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "Localidades.h"
#include "Biblioteca.h"
#include "ArrayChoferes.h"
#ifndef ARRAYPEDIDOS_H_
#define ARRAYPEDIDOS_H_

typedef struct {
    int idPedido;
    int idCliente;
    float kilosTotales;
    float kilosHDPE;
    float kilosLDPE;
    float kilosPP;
    float basura;
    int estadoPedido;
    char descripcion[51];//PENDIENTE O PROCESADO, puedo determinarlo si no se especificaron(=0) la cantidad de kilos de los tres tipos de plasticos
    int estaVacante;//isEmpty
    int iDdelChofer;
}ePedido;

//funciones de PEDIDOS
/*
 * Inicializa la lista de pedidos como si todos estuvieran vacios poniendo el estado de estaVacante en 0
 * parametros: pedidos, estructrua de pedidos, tam_pedidos tamaño del array de pedidos
 *
 *
 */
void InicializarListaPedidos(ePedido* pedidos, int tamanio_Pedidos);

/*
 * Se fija si almenos un pedido esta procesado
 * parametros: pedidos, estructrua de pedidos, tam_pedidos tamaño del array de pedidos
 * retorna: -1 si todos los pedidos estan pendinetes o 0 si algun pedido esta procesado

 */
int validarPedidosProcesados(eCliente* cliente, int tam_Clientes,ePedido* pedido, int tam_Pedidos);

/*
 * Se fija si almenos un pedido esta pendiente
 * parametros: pedidos, estructrua de pedidos, tam_pedidos tamaño del array de pedidos
 * retorna: -1 si todos los pedidos estan procesados o 0 si algun pedido esta pendiente

 */
int validarPedidosPendientes(eCliente* cliente, int tam_Clientes,ePedido* pedido, int tam_Pedidos);

/*
 * Se fija si almenos un pedido fue dado de alta
 * parametros: pedidos, estructrua de pedidos, tam_pedidos tamaño del array de pedidos
 * retorna: -1 si todos los pedidos estan vacantes o 0 si algun pedido fue dado de alta
 *
 */
int ValidarListaPedidos(eCliente* cliente, int tamanio_Cliente,ePedido* pedido, int tam_Pedido);

/*
 * Crea un pedido de recoleccion el cual se encontrara como pendiente en la lista de pedidos y lo enlaza con un cliente y un chofer
 * parametros: pedido, estructrua de pedidos, tamanio_pedidos tamaño del array de pedidos,cliente, estructura de cliente  y tamanio_clientes con el tamaño del array de clientes
 * 				lista de localidades, array de localidades, tam_localidades tamañodel array de localidades, choferes array de choferes,
 * 				 tam_choferes tamaño del array de choferes, idPedido, id del pedido
 *
 * retorna -1 si alta de pedido no pudo crear un pedido o 0 si pudo cargarlo correctamente
 */
int CrearPedidoDeRecoleccion(ePedido* pedido,int tamanio_Pedidos, eCliente* listaDeClientes, int tamanio_Cliente,
		eLocalidad* listaDeLocalidades, int tam_localidades,eChofer* listaDeChoferes, int tam_choferes, int* idPedido);

/*
 *	da de alta un pedido y carga los datos a los arrays
 *	 parametros: pedido, estructrua de pedidos, tamanio_pedidos tamaño del array de pedidos,cliente, estructura de cliente  y tamanio_clientes con el tamaño del array de clientes
 * 				lista de localidades, array de localidades, tam_localidades tamañodel array de localidades, choferes array de choferes, tam_choferes tamaño del array de choferes
 *
 *retorna -1 si no encontro un espacio en el array para cargar un pedido o 0 si cargo el pedido correctamente
 */
int AltaPedido(ePedido* pedido, int tam_Pedidos, eCliente* listaDeClientes,int tam_Clientes,eLocalidad* localidad, int tam_localidad,eChofer* choferes, int tam_choferes, int idPedido);

/*
 * procesa los residuos, convierte el total de pedidos en la cantidad especificada por el usuario de los tipos de plasticos dados por el parcial
 * parametros: listaDepedidos, estructrua de pedidos, tam_pedidos tamaño del array de pedidos, listaDeClientes, array de clientes, tam_clientes tamaño del array de clientes
 *
 * retorna -1 si no pudo procesar el pedido dado que no se encontro el id del pedido especificado o 0 si se proceso correctamente
 */
int ProcesarResiduos(ePedido*listaDePedidos,int tam_Pedidos,eCliente* listaDeClientes, int tam_Clientes);

/*
 * muestra una lista con todos los pedios pendientes
 * parametros: listaDepedidos, estructrua de pedidos, tam_pedidos tamaño del array de pedidos, listaDeClientes, array de clientes, tam_clientes tamaño del array de clientes
 *
 * retorna -1 si no pudo imprimr ningun pedido pendiente o 0 si imprimio al menos un pedido
 */
int MostrarListaDePedidosPendientes(ePedido* pedidos,int tam_Pedidos, eCliente* clientes,int tam_Clientes);


/*
 * imprime un pedido especifiado en una posicion del array
 *  paramentros: pedido,  array del pedido en esa posicion, cliente, array de cliente en esa posicion, caso, en caso de ser pedido pendiente o procesado (0 y 1)
 *
 */
void ImprimirPedido(ePedido pedido, eCliente cliente, int caso);

/*
 * muestra la cabecera del pedido que se le especifique, procesado o pendiente (0 y 1)
 * paramentro: cabezal, elije el tipo de cabecera que se le especifique
 *
 *
 */
void MostrarCabezal(int cabezal);

/*
 * busca y muestra un pedido especificado por el usuario
 * parametros: pedido array de pedidos, tam_pedidos tamaño del array de pedidos,cliente array de clientes, tam_clientes tamaño del array de clientes, id id especificado por el usuario
 * retorna -1 si no encontro el pedido ingresado o 0 si logro mostrarlo
 *
 */
int BuscarYMostrarPedidoPorId(ePedido* pedido, int tam_Pedidos,eCliente* cliente, int tam_Clientes, int id);

/*
 * sub funcion que permite ingresar los kilos de cada tipo de plastico
 * parametros: pedido array de pedidos, tam_pedidos tamaño del array de pedidos, idIngresado, id ingresado previamente por el usuario
 *
 * retorna -1 si no pudo cargar los datos o 0 si concluyo l carga de datos de pedidos procesados
 */
int IngresarKilos(ePedido* pedido, int tam_Pedidos,int idIngresado);

/*
 * muestra una lista con todos los pedios procesados
 * parametros: pedido, estructrua de pedidos, tam_pedidos tamaño del array de pedidos, listaDeClientes, array de clientes, tam_clientes tamaño del array de clientes
 *
 * retorna -1 si no pudo imprimr ningun pedido procesado o 0 si imprimio al menos un pedido
 *
 */
int MostrarListaDePedidosProcesados(ePedido* pedido,int tam_Pedidos, eCliente* cliente, int tam_Clientes);

//funciones mixtas

/*
 * muestra una lista con los pedidos pendientes que tiene cada cliente
 * parametros: pedido array de pedidos, tam_pedidos tamaño del array de pedidos,cliente array de clientes, tam_clientes tamaño del array de clientes,
 * 				localidad, array de localidad, tam_localidad tamaño del array de localidad.
 *
 * retorna -1 si no hay nada para mostrar en la lista o 0 si imprimio la lista
 * nota: si los clientes no tienen pedidos pendientes en el campo de pendientes se marca un 0. pero si lo imrpime
 */
int ListaDeClientesConPendinetes(eCliente* cliente, int tam_Clientes, ePedido* pedido,int tam_Pedidos, eLocalidad * localidad, int tam_localidad);

/*
 * compara la cadena de localidad ingresada por el usuario con la cadena guardada en la descripcion de las localidades
 * de encontrar una localidad, muestra los pedidos que hay en dicha localdiad con la cnatidad que encontro
 * parametros: cliente array de clientes, tam_clientes tamaño del array de clientes, pedido array de pedidos, tam_pedidos tamaño del array de pedidos,
 * 				localidad, array de localidad, tam_localidad tamaño del array de localidad.
 * retorna -1 si no encontro la cadena que compara con las localidades, o 0 si la encontro
 */
int MostrarPedidosPorLocalidad(eCliente* cliente, int tam_Clientes, ePedido* pedido, int tam_Pedidos, eLocalidad * localidades, int tam_localidades);

/*
 * realiza un promedio de la cantidad de pp que se encontro en el array de pedidos con la cantidad total de clientes
 * parametros: cliente array de clientes, tam_clientes tamaño del array de clientes, pedido array de pedidos, tam_pedidos tamaño del array de pedidos
 * retorna -1 si no encontro registros de pp o 0 si pudo realizar el promedio
 */
int CantidadPoliPropilenoPromedioCliente(eCliente* cliente,int tam_Clientes, ePedido* pedido, int tam_Pedidos);

//funciones segunda parte parcial

/*
 *imprime los clientes que tengan la mayor cantidad de pedidos pendientes
 *parametros: cliente array de clientes, tam_clientes tamaño del array de clientes, pedido array de pedidos, tam_pedidos tamaño del array de pedidos,
 * 				localidad, array de localidad, tam_localidad tamaño del array de localidad.
 *retorna -1 si no encontro ningun cliente con pedidos pendientes o 0 si encontro al menos uno
 */
int ClientesConMasPedidosPendientes(eCliente* cliente, int tam_Clientes, ePedido* pedido, int tam_Pedidos,eLocalidad* localidades, int tam_Localidades);

/*
 *imprime los clientes que tengan la mayor cantidad de pedidos procesados
 *parametros: cliente array de clientes, tam_clientes tamaño del array de clientes, pedido array de pedidos, tam_pedidos tamaño del array de pedidos,
 * 				localidad, array de localidad, tam_localidad tamaño del array de localidad.
 *retorna -1 si no encontro ningun cliente con pedidos procesados o 0 si encontro al menos uno
 */
int ClientesConMasPedidosProcesados(eCliente* cliente, int tam_Clientes, ePedido* pedido, int tam_Pedidos,eLocalidad* localidades, int tam_Localidades);


#endif
