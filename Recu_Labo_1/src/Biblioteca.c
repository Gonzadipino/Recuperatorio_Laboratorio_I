#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca.h"

#define ACTIVO 1
#define INACTIVO 0

#define PENDIENTE 0
#define PROCESADO 1


int LoadInt(char message[], int min, int max){
    char option[50];
    int state=0;
    int validOption;
    int flag=0;
    do{
    if (flag==1){
        printf("ERROR.");
    }
    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", option);

    state = ValidateIntNumber(option);

    while(state!=0){
        printf("ERROR. '%s' no es una opcion,%s",option, message);
          fflush(stdin);
        scanf("%[^\n]", option);
        state=ValidateIntNumber(option);
    }
    validOption= atoi(option);
    flag=1;
    }while(validOption <min || validOption > max);

    return validOption;

}

float LoadFloat(char message[], int min){
    char option[50];
    int state=0;
    float validOption;
    int flag=0;
    do{
    if (flag){
        printf("ERROR.");
    }
    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", option);

    state = ValidateFloatNumber(option);

    while(state!=0){
        printf("ERROR. '%s' no es un numero decimal,%s",option, message);
          fflush(stdin);
        scanf("%[^\n]", option);
        state=ValidateFloatNumber(option);
    }
    validOption= atof(option);
    flag=1;
    }while(validOption <min);

    return validOption;

}

void LoadString(char message[], char loadedString[]){
    int state=0;
    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", loadedString);
   state=ValidateString(loadedString);
    while(state!=0){
        printf("ERROR. '%s' no es válido,%s",loadedString, message);
        fflush(stdin);
        scanf("%[^\n]", loadedString);
        state=ValidateString(loadedString);
    }
    StandardChar(loadedString,51);
}

void AlertMessageAndEnter(int num, char messageA[], char messageB[]) {

    char enter;
    if(num == 0) {

        printf("%s\n",messageA);
    } else {

        printf("%s\n",messageB);
    }

    printf("presione cualquier tecla para continuar.");
    fflush(stdin);
    scanf("%c", &enter);
    printf("\n\n");

}
void AlertMessageNoKey(int num, char messageA[], char messageB[]) {

    if(num == 0) {
        printf("%s\n",messageA);
    } else {
        printf("%s\n",messageB);
    }
}

int ValidateIntNumber(char number[]){
    int i=0;
    int j;
    int ret=0;

    j=strlen(number);
    while(i<j && ret==0){
        if(isdigit(number[i])!=0){
            i++;
        }
        else{
            ret=-1;
        }
    }
    return ret;
}

int ValidateString(char string[]){
    int i=0;
    int ret=0;
    int j;
    j=strlen(string);
    while(i<j && ret==0){
        if(isalpha(string[i])!=0 || string[i]== ' '){
            i++;
        }
        else{
            ret=-1;
        }
    }
    return ret;
}

int ValidateFloatNumber(char number[]) {
    int i=0;
    int ret=0;
    int j;
    int flag=1;
    j=strlen(number);
    while(i<j && ret==0){
        if(isdigit(number[i])!=0){
            i++;
        }else if(flag && ispunct(number[i])!=0){
            i++;
            flag=0;
            }else{
                 ret=-1;
            }

        }
        return ret;
    }

void StandardChar(char string[], int len) {
    int flag=1;

    for(int i=0; i<len; i++){
        if(string[i]==' '){
        flag=1;
        }else if(flag && string[i]!=' '){
            string[i]= toupper(string[i]);
            flag=0;
        }else if(flag==0){
            string[i]= tolower(string[i]);
            }
        }

}

