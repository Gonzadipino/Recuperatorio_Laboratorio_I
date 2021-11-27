#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define ACTIVO 1
#define INACTIVO 0

#define TAM_CLIENTES 1000
#define TAM_PEDIDOS  100
#define TAM_LOCALIDADES 300

#define PENDIENTE 0
#define PROCESADO 1

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int LoadInt(char message[],int min, int max);
float LoadFloat(char message[], int min);
void LoadString(char message[], char loadedString[]);
void AlertMessageAndEnter(int num, char messageA[],char messageB[]);
void AlertMessageNoKey(int num, char messageA[], char messageB[]);
int ValidateIntNumber(char number[]);
int ValidateString(char string[]);
int ValidateFloatNumber(char number[]);
void StandardChar(char string[],int len);

#endif
