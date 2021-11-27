#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Localidades.h"
#include "Biblioteca.h"
#define OCUPADO 1
#define VACIO 0


int ImprimirListaDeLocalidades(eLocalidad* localidad, int tamLocaldiad) {

	int contadorLocalidades = 0;

    printf("\n******************************************** L O C A L I D A D E S ********************************************\n\n");
    printf("ID LOCALIDAD                       NOMBRE LOCALIDAD\n");

    for(int i = 0; i < tamLocaldiad; i++) {

    	if(localidad[i].isEmpty != VACIO) {
    		contadorLocalidades++;
    		printf("%10d  %40s\n", localidad[i].idLocalidad, localidad[i].descripcion);
    	}
    }
    return contadorLocalidades;
}

int TomarLocalidad(eLocalidad* localidadingresada, int tamLocaldiad) {

    int retorno =-1;
    int cantidadLocalidades;
    cantidadLocalidades = ImprimirListaDeLocalidades(localidadingresada,tamLocaldiad);

    retorno = LoadInt("Ingrese una id de localidad: ", 0, cantidadLocalidades);
    return retorno;
}


int cargaDeCiudades(char* path, eLocalidad* Localidades, int tam_localidades) {

	int retorno = -1;
	int i = 0;
	char descripcion[60];
	FILE* pFile = NULL;

	pFile = fopen(path,"r");

	if(pFile != NULL) {

		while(!feof(pFile)) {
			i++;
			fscanf(pFile,"%[^\n]\n",descripcion);
			Localidades[i].idLocalidad = i;
			strcpy(Localidades[i].descripcion, descripcion);
			Localidades[i].isEmpty = OCUPADO;
			retorno = 0;
		}
	}

	fclose(pFile);

	return retorno;
}



