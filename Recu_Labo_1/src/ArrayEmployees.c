#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "Biblioteca.h"
#include "Localidades.h"

#define ACTIVO 1
#define INACTIVO 0

#define TAM_CLIENTES 1000
#define TAM_PEDIDOS  100
#define TAM_LOCALIDADES 300

#define PENDIENTE 0
#define PROCESADO 1

void InicializarLista(eCliente* cliente, int tamanioLista) {

    for(int i = 0; i < tamanioLista; i++) {

    	cliente[i].estado = INACTIVO;
    }
}

int ValidarListaCargada(eCliente* lista, int tamanioLista) {

	int retorno = -1;

    if(lista != NULL) {

    	for(int i = 0; i < tamanioLista; i++) {

    	    if(lista[i].estado != INACTIVO) {

    	    	retorno = 0;
    	    	break;

    	        }
    	    }
    }
    return retorno;
}

int AltaDeCliente(eCliente* cliente,int tamanioLista,eLocalidad* localidad, int tamLocalidad, int* idAutomatico) {

    int retorno = -1;
    int idFuncion = *(idAutomatico);

    for(int i = 0; i < tamanioLista; i++) {

        if(cliente[i].estado == INACTIVO) {

            printf("****************************************** A L T A   D E   C L I E N T E *****************************************\n\n");
            cliente[i].id = idFuncion;
            LoadString("Ingrese empresa: ",cliente[i].empresa);
            cliente[i].cuit = LoadInt("Ingrese cuit(sin puntos ni guiones): ",1,99999999);
            LoadString("Ingrese nombre de la calle de la empresa (sin numeros): ", cliente[i].calle);
            cliente[i].altura = LoadInt("Ingrese numero de la calle de la empresa: ",0,999999);
            cliente[i].localidad = TomarLocalidad(localidad, tamLocalidad);
            cliente[i].estado = ACTIVO;
            retorno = 0;
            idFuncion++;
            break;

        }
    }
    *idAutomatico = idFuncion;
    return retorno;
}

void ImprimirListaDeClientes(eCliente* ListaCliente, int tamanioLista, eLocalidad* ListaLocalidades, int tam_localidades, int parametro) {

	MostrarCabezalClientes(parametro);

	for(int i = 0; i<tamanioLista; i++) {

		if(ListaCliente[i].estado == ACTIVO) {

			for(int j = 0; j < tam_localidades; j++) {

				if(ListaLocalidades[j].idLocalidad == ListaCliente[i].localidad) {

					ImprimirCliente(ListaCliente[i],ListaLocalidades[j]);
				}
			}
		}
    }

    printf("\n");
}

void ImprimirCliente(eCliente cliente, eLocalidad localidad) {

        printf("%4d %20s %15d %20s %6d %30s\n",cliente.id, cliente.empresa, cliente.cuit, cliente.calle, cliente.altura, localidad.descripcion);

    }//modificada para el examen

int BuscarYMostrarClientePorId(eCliente* cliente, int tamanioLista, eLocalidad* localidad, int tam_localidad, int id) {

    int retorno = -1;

    for(int i = 0; i < tamanioLista; i++) {

    	if(cliente[i].estado == ACTIVO) {

    		for(int j = 0; j<tam_localidad; j++) {

    			if(cliente[i].id == id && cliente[i].localidad == localidad[j].idLocalidad) {

    				ImprimirCliente(cliente[i],localidad[j]);
    				retorno = 0;
    				break;
    			}

    		}

        }
    }

    return retorno;
}

int BajaDeCliente(eCliente* cliente, int tamanioLista, eLocalidad* localidad, int tam_localidad) {

    int retorno = -1;
    int idABorrar;
    int opcion;
    printf("****************************************** B A J A   D E   C L I E N T E *****************************************\n\n");
    ImprimirListaDeClientes(cliente, tamanioLista,localidad,tam_localidad, 0);
    idABorrar = LoadInt("Ingrese el id que desea borrrar: ",1,9999);
    retorno   = BuscarYMostrarClientePorId(cliente, tamanioLista,localidad,tam_localidad, idABorrar);
    if(retorno!=-1){
        opcion = LoadInt("Es este el usuario que desea borrar?:\n        1-> SI  0-> NO :",0,1);
        if(opcion == 1){
        BorrarCliente(cliente, tamanioLista, idABorrar);
        }else{
            printf("Operacion cancelada. ");
            retorno = -1;
        }
    }else{
        printf("Id no encontrado. ");
    }
   return retorno;
}

void BorrarCliente(eCliente* cliente,int tamanioLista, int id){
        for(int i=0;i<tamanioLista; i++){
            if(cliente[i].estado==ACTIVO && cliente[i].id==id){
                cliente[i].estado=INACTIVO;
                break;
            }
       }
   }

int ModificarCliente(eCliente* cliente,int tamanioLista,eLocalidad* localidad, int tamLocalidad) {

    int idAModificar;
    int cambios;
    int estadoBusqueda;


    printf("****************************************** M O D I F I C A C I O N  D E   C L I E N T E *****************************************\n");

    ImprimirListaDeClientes(cliente,tamanioLista,localidad, tamLocalidad, 0);
    idAModificar  = LoadInt("Ingrese el id del usuario que desea modificar: ",1,9999);
    estadoBusqueda = BuscarYMostrarClientePorId(cliente, tamanioLista,localidad, tamLocalidad, idAModificar);

    if(estadoBusqueda != -1) {

        cambios = CambiarDatosDeCliente(cliente,tamanioLista,localidad, tamLocalidad,idAModificar);

        if(cambios == -1) {

        	printf("No se modifico ningun campo. ");
        }
    } else {

    	printf("no se encontro el id.");

    }

    return cambios;
}

int CambiarDatosDeCliente(eCliente* cliente,int tamanioLista,eLocalidad* localidad, int tamLocalidad,int idAModificar) {

    int retorno = -1;
    int opcionFuncion;
    for(int i = 0; i < tamanioLista ; i++) {

        if(cliente[i].id == idAModificar) {

			do {
				printf("\n\n1.MODIFICAR DIRECCION\n2.MODIFICAR LOCALIDAD\n\n0.VOLVER\n\n");
				opcionFuncion=LoadInt(" OPCION: ",0,2);

				switch(opcionFuncion) {

					case 1:
						LoadString("Ingrese nombre de la calle de la empresa (sin numeros): ", cliente[i].calle);
						cliente[i].altura = LoadInt("Ingrese numero de la calle de la empresa: ", 0 , 999999);
						printf("Se modifico la calle.\n");
						retorno = 0;
						break;

					case 2:
						cliente[i].localidad = TomarLocalidad(localidad, tamLocalidad);

						printf("Se modifico la localidad.\n");
						retorno = 0;
						break;

					case 0:
						break;
				}

			} while(opcionFuncion != 0);

			break;
        }
    }

    return retorno;
}

void MostrarCabezalClientes(int caso) {
    if(caso==0){
    printf("\n  ID              EMPRESA            CUIT                   DIRECCION                      LOCALIDAD\n");
    }
    if (caso==1){
    printf("\n  ID              EMPRESA            CUIT                   DIRECCION                      LOCALIDAD    PEDIDOS PENDIENTES\n");
    }

}

