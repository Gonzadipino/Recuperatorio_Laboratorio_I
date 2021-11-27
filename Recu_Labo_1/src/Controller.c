//Nueva biblioteca de controllers.
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Controller.h"
#include "Biblioteca.h"
#include "ArrayEmployees.h"
#include "ArrayPedidos.h"
#include "Localidades.h"
#include "ArrayChoferes.h"

#define ACTIVO 1
#define INACTIVO 0

#define TAM_CLIENTES 1000
#define TAM_PEDIDOS  100
#define TAM_LOCALIDADES 300
#define TAM_CHOFERES 20
#define PENDIENTE 0
#define PROCESADO 1


//CASE 1:
int Controller_AltaCliente(eCliente* ListaDeClientes, int tam_Clientes,eLocalidad* ListaDeLocalidades, int tam_Localidades, int* Id_Automatico) {

	int retorno = -1;

	if(ListaDeClientes != NULL && ListaDeLocalidades != NULL) {

		retorno = AltaDeCliente(ListaDeClientes,tam_Clientes,ListaDeLocalidades,tam_Localidades, Id_Automatico);
		AlertMessageAndEnter(retorno,"Cliente cargado correctamente.","No hay espacio en memoria, borre un cliente para cargar otro.");
	}else {
		AlertMessageAndEnter(retorno,"","ERROR.");
	}

	return retorno;
}
//CASE 2:
int Controller_ModificacionCliente(eCliente* ListaDeClientes, int tam_Clientes,eLocalidad* ListaDeLocalidades, int tam_Localidades) {

	int retorno = -1;

	if(ListaDeClientes != NULL && ListaDeLocalidades != NULL && ValidarListaCargada(ListaDeClientes, tam_Clientes) == 0) {

		retorno = ModificarCliente(ListaDeClientes, tam_Clientes, ListaDeLocalidades, tam_Localidades);
		AlertMessageAndEnter(retorno, "Cliente modificado con exito. ", "No se realizaron modificaciones.");
	}else {

		AlertMessageAndEnter(retorno,"", "No hay clientes en la lista.");
	}


	return retorno;
}
//CASE 3:
int Controller_BajaDeCliente(eCliente* ListaDeClientes, int tam_Clientes, eLocalidad* ListaDeLocalidades, int tam_localidades) {

	int retorno = -1;

	if(ListaDeClientes != NULL && ValidarListaCargada(ListaDeClientes, tam_Clientes) == 0) {

		retorno = BajaDeCliente(ListaDeClientes, tam_Clientes, ListaDeLocalidades, tam_localidades);
		AlertMessageAndEnter(retorno, "Baja realizada con exito.", "No se realizo la baja.");
	}else {
		AlertMessageAndEnter(retorno,"", "No hay clientes en la lista.");
	}

	return retorno;
}
//CASE 4:
int Controller_CrearPedido(ePedido* ListaDePedidos, int tamanio_Pedidos, eCliente* ListaDeClientes, int tam_Clientes,eLocalidad* ListaDeLocalidades,
		int tam_localidades,eChofer* ListaDeChoferes, int tam_Choferes, int* idPedido ) {

	int retorno = -1;

	if(ListaDeClientes != NULL && ListaDePedidos != NULL && ValidarListaCargada(ListaDeClientes, tam_Clientes) == 0) {

		retorno = CrearPedidoDeRecoleccion(ListaDePedidos, tamanio_Pedidos, ListaDeClientes, tam_Clientes,ListaDeLocalidades, tam_localidades,ListaDeChoferes,tam_Choferes, idPedido);
		AlertMessageAndEnter(retorno, "Pedido creado con exito.", "No se creo el pedido.");
	} else {
		AlertMessageAndEnter(retorno,"", "No hay clientes para asignar un pedido.");
	}


	return retorno;
}
//CASE 5:
int Controller_ProcesarResiduos(ePedido* ListaDePedidos,int tam_Pedidos,eCliente* ListaDeClientes, int tam_Clientes) {

	int retorno = -1;

	if(ListaDePedidos != NULL && ListaDeClientes != NULL && ValidarListaCargada(ListaDeClientes, tam_Clientes) == 0 &&
	ValidarListaPedidos(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos) == 0) {

		retorno = ProcesarResiduos(ListaDePedidos, tam_Pedidos, ListaDeClientes, tam_Clientes);
		AlertMessageAndEnter(retorno, "Residuos procesados con exito.", "No se procesaron los residuos seleccionados.");
	}else {
		AlertMessageAndEnter(retorno,"", "No hay pedidos en la lista.");
	}

	return retorno;

}
//CASE 6:
int Controller_ImprimirLosClientesConPendientes(eCliente* ListaDeClientes, int tam_Clientes,ePedido* ListaDePedidos, int tam_Pedidos, eLocalidad* ListaDeLocalidades, int tam_Localidades) {

	int retorno = -1;

	if(ValidarListaCargada(ListaDeClientes, tam_Clientes) == 0 && ListaDeClientes != NULL && ListaDeLocalidades != NULL) {

		retorno = 0;

		ListaDeClientesConPendinetes(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos, ListaDeLocalidades, tam_Localidades);

	}
	AlertMessageAndEnter(retorno,"", "No hay clientes para mostrar.");

	return retorno;
}
//CASE 7:
int Controller_ImprimirPendientes(ePedido* ListaDePedidos, int tam_Pedidos, eCliente* ListaDeClientes, int tam_Clientes) {

	int retorno = -1;

	if(validarPedidosPendientes(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos) == 0) {

		retorno = MostrarListaDePedidosPendientes(ListaDePedidos, tam_Pedidos, ListaDeClientes, tam_Clientes);
	}
	AlertMessageAndEnter(retorno, "", "No hay pedidos PENDIENTES para mostrar.");

	return retorno;
}
//CASE 8:
int Controller_ImprimirProcesados(ePedido* ListaDePedidos,int tam_Pedidos, eCliente* ListaDeClientes, int tam_Clientes) {

	int retorno = -1;

	if(validarPedidosProcesados(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos) == 0 &&
		ListaDePedidos != NULL && ListaDeClientes != NULL) {

			retorno = MostrarListaDePedidosProcesados(ListaDePedidos, tam_Pedidos, ListaDeClientes, tam_Clientes);
	}

	AlertMessageAndEnter(retorno,"","No hay pedidos PROCESADOS para mostrar.");

	return retorno;

	}
//CASE 9:
int Controller_ImprimirPedidosPendientesPorLocalidad(ePedido* listaDePedidos, int tam_Pedidos, eCliente* ListaDeClientes, int tam_Clientes, eLocalidad* ListaDeLocalidades, int tam_Localidades) {

	int retorno = -1;

	if(validarPedidosPendientes(ListaDeClientes, tam_Clientes, listaDePedidos, tam_Pedidos) == 0) {

		retorno = MostrarPedidosPorLocalidad(ListaDeClientes, tam_Clientes, listaDePedidos, tam_Pedidos, ListaDeLocalidades,tam_Localidades);
		AlertMessageAndEnter(retorno,"","No se encontraron pedidos para la localidad ingresada.");
	}else {
		AlertMessageAndEnter(retorno,"","No hay pedidos para mostrar.");
	}

	return retorno;
}
//CASE 10:
int Controller_Promedios(eCliente* ListaDeClientes, int tam_Clientes, ePedido* ListaDePedidos, int tam_Pedidos) {

	int retorno = -1;

	if(ListaDePedidos != NULL && ListaDeClientes != NULL && ValidarListaCargada(ListaDeClientes, tam_Clientes) == 0 &&
		ValidarListaPedidos(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos) == 0) {

		retorno = CantidadPoliPropilenoPromedioCliente(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos);
	}

	AlertMessageAndEnter(retorno,"","No se encontraron registros de KG de PoliPropileno.");

	return retorno;
}
//CASE 11:
int Controller_MasPedidosPendientes(ePedido* ListaDePedidos, int tam_Pedidos, eCliente* ListaDeClientes, int tam_Clientes, eLocalidad* ListaDeLocalidades, int tam_Localidades) {

	int retorno = -1;

	if( ValidarListaCargada(ListaDeClientes, tam_Clientes) == 0 && validarPedidosPendientes(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos) == 0) {

		retorno = ClientesConMasPedidosPendientes(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos,ListaDeLocalidades, tam_Localidades);
	}
	AlertMessageAndEnter(retorno,"", "No hay pedidos pendientes en la lista.");

		return retorno;
}
//CASE 12:
int Controller_MasPedidosProcesados(ePedido* ListaDePedidos, int tam_Pedidos, eCliente* ListaDeClientes, int tam_Clientes, eLocalidad* ListaDeLocalidades, int tam_Localidades) {

	int retorno = -1;

	if( ValidarListaCargada(ListaDeClientes, tam_Clientes) == 0 && validarPedidosProcesados(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos) == 0) {

		retorno = ClientesConMasPedidosProcesados(ListaDeClientes, tam_Clientes, ListaDePedidos, tam_Pedidos, ListaDeLocalidades,tam_Localidades);
		AlertMessageNoKey(retorno, "", "");
	}

	AlertMessageAndEnter(retorno,"", "No hay pedidos procesados en la lista.");

	return retorno;
}
//CASE 13:
int Controller_ManejoDeChoferes(eChofer* listaDeChoferes, int tam_Choferes, int* idChofer) {


	int retorno = -1;

	if( listaDeChoferes != NULL) {

	SubMenuChoferes(listaDeChoferes, tam_Choferes, idChofer);
	retorno  = 0;
	}


	return retorno;
}
//CASE 14
int Controller_Listados(ePedido* listaPedidos,int tam_Pedidos, eLocalidad* listaLocalidades, int tam_Localidades, eCliente* listaClientes, int tam_Clientes, eChofer* listaChofer, int tam_Choferes) {

	int retorno = -1;

	if(listaPedidos != NULL && listaLocalidades != NULL && listaChofer != NULL && listaClientes != NULL) {

		if(ValidarListaCargada(listaClientes, tam_Clientes) == 0 && ValidarListaPedidos(listaClientes, tam_Clientes, listaPedidos, tam_Pedidos)== 0 &&
				ValidarListaChoferes(listaChofer, tam_Choferes) == 0) {

				Listados(listaPedidos, tam_Pedidos, listaLocalidades, tam_Localidades, listaClientes, tam_Clientes, listaChofer, tam_Choferes);
		}else {
			AlertMessageAndEnter(retorno, "", "Faltan datos para ver las listas. Verifique que exista al menos un cliente, un pedido y un chofer");
		}

	}
	return retorno;

}





