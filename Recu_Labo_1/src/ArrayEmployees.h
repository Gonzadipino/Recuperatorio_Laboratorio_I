#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Biblioteca.h"
#include "Localidades.h"
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct {
    int id;
    char empresa[51];
    int cuit;
    char calle[51];
    int altura;
    int localidad; // localidad es solo un numero que matchea con el numero del id de eLocalidad
    int estado;

}eCliente;
/*
 * inicializa la lista de pedidos poniendo el campo estado en 0 para dar lugar a la carga de clientes
 * parametros: cliente, array de clientes, tamaniLista tamaño del array de clientes
 *
 *
 */
void InicializarLista(eCliente* cliente, int tamanioLista);

/*
 * Verifica que exista al menos un campo de estado que este en 1 o ACTIVO
 * parametros: parametros: cliente, array de clientes, tamaniLista tamaño del array de clientes
 *
 * retorna -1 si todos los campos estan en 0 o 0 si encontro al menos un cliente ACTIVO
 */
int ValidarListaCargada(eCliente* lista, int tamanioLista);

/*
 * Da de alta un cliente y le asigna una localidad especificada por el usuario y un id automatico
 * parametros: Listacliente,array de clientes,tamanioLista,tamaño del array de clientes, localidad, array de localidades, tamLocalidad, tamaño del array de localidades,*idAutomatico, id unico que se le asigna al cliente
 *
 * retorna: -1 si no encontro un espacio en la lista para dar de alta al cliente o 0 si pudo hacerlo
 */
int AltaDeCliente(eCliente* cliente, int tamanioLista, eLocalidad* localidad, int tamLocalidad, int *idAutomatico);

/*
 * parametros: Listacliente,array de clientes,tamanioLista,tamaño del array de clientes, localidad, array de localidades, tamLocalidad, tamaño del array de localidades,
 *		parametro, para mostrar un tipo de cabecera
 *
 */
void ImprimirListaDeClientes(eCliente* ListaCliente, int tamanioLista, eLocalidad* ListaLocalidades, int tam_localidades, int parametro);

/*
 * imrpime un cliente en la posicion especificada del array
 * parametros: cliente, cliente en posicion especificada, localidad, localidad en posicion especificada
 *
 */
void ImprimirCliente(eCliente cliente, eLocalidad localidad);

/*
 * busca un cliente por el id que ingrese el usuario
 * parametros: cliente, array de clientes, tamanioLista tamaño de la lista de clientes, localidad, array de localidad, tam_localidad, tamaño del array de localidades, id, id que se busca
 *
 * esta funcion retorna -1 si no encontro el id que se especifica o 0 si lo eoncontro
 */
int BuscarYMostrarClientePorId(eCliente* cliente, int tamanioLista, eLocalidad* localidad, int tam_localidad, int id);

/*
 * Da de baja un cliente permanentemente
 * utiliza la funcion buscar y mostrar cliente por id, de encontrarlo ejecuta la funcion borrar cliente
 * parametros: cliente, array de clientes, tamanioLista tamaño de la lista de clientes, localidad, array de localidad, tam_localidad, tamaño del array de localidades
 * retorna -1 si no pudo encontrar el usuario que se especifico borrar o si se cancelo la operacion. retorna 0 si pudo dar de baja al usuario
 *
 */
int BajaDeCliente(eCliente* cliente, int tamanioLista, eLocalidad* localidad, int tam_localidad);

/*
 * Elimina el usuario poniendo en 0 el campo de estado
 * parametros cliente array de clientes, tamanioLista tamaño del array de clientes, id, id a borrar
 *
 */
void BorrarCliente(eCliente* cliente,int tamanioLista, int id);

/*
 * modifica un cliente permanentemente
 * utiliza la funcion buscar y mostrar cliente por id, de encontrarlo ejecuta la funcion modificar cliente
 * parametros: cliente, array de clientes, tamanioLista tamaño de la lista de clientes, localidad, array de localidad, tamLocalidad, tamaño del array de localidades
 * retorna -1 si no se encontro el usuario o si no se realizaron modificaciones, retorna 0 en caso de realizar la operacion
 *
 */
int ModificarCliente(eCliente* cliente,int tamanioLista,eLocalidad* localidad, int tamLocalidad);

/*
 * permite modificar los campos al usuario permitidos por el desarrollador, mostrando un submenu
 * parametros: cliente, array de clientes, tamanioLista tamaño del array de clientes, localidad array de localidades, tamanioLocalidad, tamaño del array de localidades, idaModificar, id del cliente que se le realizaraon modificaciones
 * retorna -1 si no se realizan modificaciones en el cliente o 0 si se realizao alguna modificacion
 *
 */
int CambiarDatosDeCliente(eCliente* cliente,int tamanioLista,eLocalidad* localidad, int tamLocalidad,int idAModificar);

/*
 * muestra dos tipos de cabeceras parecidas, salvo que en una imprime tambien los pedidos pendientes
 * parametro: caso, elije el tipo de cabecera que se quiere mostrar
 *
 */
void MostrarCabezalClientes(int caso);

#endif
