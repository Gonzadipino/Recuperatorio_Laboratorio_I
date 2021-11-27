#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_

typedef struct {

    int idLocalidad;
    char descripcion[60];
    int isEmpty;

} eLocalidad;

/* Imprime la lista de localidades
 * parametros: localidad, estructura de localidades, tam localidad, tamaño de la estructura de localidades
 *  retorna 0 en caso de no contar ninguna localidad  o retorna la cantidad de localidades que encontro activas
 *
 */
int ImprimirListaDeLocalidades(eLocalidad* localidad, int tamLocaldiad);

/*
 * toma una localidad ingresada por el usuario como un entero
 * parametros: localidad, estructura de localidades, tam localidad, tamaño de la estructura de localidades
 * retorna -1 por error o el numero ingresado como localidad
 */
int TomarLocalidad(eLocalidad* localidad, int tamLocaldiad);

/*
 * Carga un archivo .csv desde la carpeta del programa
 * parametros: localidad, estructura de localidades, tam localidad, tamaño de la estructura de localidades
 * retorna: -1 si no pudo abrir el archivo y 0 si imprimio aunque sea una localidad
 */
int cargaDeCiudades(char* path, eLocalidad* Localidades, int tam_localidades);

#endif

