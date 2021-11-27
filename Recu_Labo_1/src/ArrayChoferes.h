#ifndef ARRAYCHOFERES_H_
#define ARRAYCHOFERES_H_

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



#include "Biblioteca.h"

typedef struct {
	int id; // i del chofer registrado en la empresa
	char nombre[50]; // nombre del chofer
	int salario;
	float horasTrabajadas;
	int isEmpty;
	int descuento;
}eChofer;

/* Inicializa la lista de choferes poniendo su campo is empty en 0.
 *
 *  parametros: eChoferes estructura de choferes, tam_ choferes tamaño del array.
 *
 * retorna -1 si la lista es NULL o 0 si la lista se inicializo como corresponde.
 *
*/
int InicializarListaDeChoferes( eChofer* choferes, int tam_Choferes);


/* Valida que la lista tenga al menos un dato cargado.
 *
 * parametros: eChoferes estructura de choferes, tam_ choferes tamaño del array.
 *
 * retorna -1 si la lista es NULL o si no tiene ningun elemento cargado.
 * retorna  0 si encontro algun campo de is empty en 1.
 */
int ValidarListaChoferes(eChofer* choferes, int tam_Choferes);

/* Muestra un sub menu en pantalla
 *
 * parametros: eChoferes estructura de choferes, tam_ choferes tamaño del array, *idChofer para aumentar el id del chofer en otra funcion
 *
 */
void SubMenuChoferes(eChofer* choferes, int tam_Choferes,int *idChofer);

/* Da de alta un chofer
 * parametros: eChoferes estructura de choferes, tam_ choferes tamaño del array, *idChofer
 *  puntero al id del menu para aumentar el id del chofer
 *
 * retorna -1  si no pudo cargar un chofer a la lista ya que no hay campos disponibles.
 * retorna  0 si encontro un espacio y cargo un chofer.
 */
int AltaDeChofer(eChofer* choferes, int tam_Choferes, int* idChofer);


/* Da de baja un chofer
 * parametros: eChoferes estructura de choferes, tam_ choferes tamaño del array
 *  retorna -1 si no encuentra el id ingresado o si se da de baja la operacion
 *  retorna 0 si borra al chofer
 *
 */
int BajaDeChofer(eChofer* choferes, int tam_Choferes);
/*
 * Modifica datos de un chofer
 * parametros: eChoferes estructura de choferes, tam_ choferes tamaño del array
 * retorna -1 si no encontro el id ingreasdo  o si no se modifico el chofer
 * retorna 0 si modifico al chofer
 *
 */
int ModificacionDeChofer(eChofer* choferes, int tam_Choferes);

/* Imprime la lista de choferes
 * parametros: eChoferes estructura de choferes, tam_ choferes tamaño del array
 *
 */
void ImprimirListaDeChoferes(eChofer* choferes, int tam_Choferes);
/*Imprime un solo chofer
 * se utiliza dentro del nucle de la funcion anterior
 * parametro: eChofer en posicion del array indicado
 *
 */
void imprimirUnChofer(eChofer chofer);
/*
 * Iprime cabecera de choferes con los datos que componen a la estructura
 * para facilitar la lectura
 *
 */
void imprimirCabeceraChoferes(void);

#endif
