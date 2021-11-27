#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Biblioteca.h"
#include "ArrayChoferes.h"

#define OCUPADO 1
#define VACIO 0


int InicializarListaDeChoferes( eChofer* choferes, int tam_Choferes) {

	int retorno = -1;
	if(choferes != NULL) {

		for(int i = 0; i< tam_Choferes; i++) {

			choferes[i].isEmpty = VACIO;
			choferes[i].descuento = 0;
			retorno = 0;
		}
	}
	return retorno;

}

int ValidarListaChoferes(eChofer* choferes, int tam_Choferes) {

	int retorno = -1;

	if(choferes != NULL) {

		for(int i = 0; i< tam_Choferes; i++) {

			if(choferes[i].isEmpty != VACIO) {

				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

void SubMenuChoferes(eChofer* choferes, int tam_Choferes,int *idChofer) {

	int opcion;
	int retorno = -1;
	do {
		system("cls");
		printf("\n************************** C H O F E R E S **************************\n\n ");
		printf("1- ALTA DE CHOFER\n 2- BAJA DE CHOFER\n 3- MODIFICACION DE CHOFER\n 4 - LISTA DE CHOFERES\n\n 0 - VOLVER\n\n");
		opcion = LoadInt("OPCION", 0, 4);

		switch(opcion) {

			case 1:
				retorno = AltaDeChofer(choferes, tam_Choferes, idChofer);
				AlertMessageAndEnter(retorno, "Datos de chofer cargados con exito.","No se pueden agregar mas choferes, elimine alguno.");

				break;
			case 2:
				if(ValidarListaChoferes(choferes, tam_Choferes) == 0) {

					retorno = BajaDeChofer(choferes, tam_Choferes);
					AlertMessageAndEnter(retorno, "Chofer eliminado con exito.","No se elimino al chofer.");
				}else {
					AlertMessageAndEnter(retorno, "","Cargue al menos un chofer.");
				}
				break;
			case 3:
				if(ValidarListaChoferes(choferes, tam_Choferes) == 0) {

					retorno = ModificacionDeChofer(choferes, tam_Choferes);
					AlertMessageAndEnter(retorno, "Datos de chofer modificados con exito.","No se modifico el chofer.");
				} else {
					AlertMessageAndEnter(retorno, "","Cargue al menos un chofer.");
				}
				break;
			case 4:
				if(ValidarListaChoferes(choferes, tam_Choferes) == 0) {

					ImprimirListaDeChoferes(choferes, tam_Choferes);
					AlertMessageAndEnter(retorno, "","");
				} else {
					AlertMessageAndEnter(retorno, "","Cargue al menos un chofer.");
				}
				break;
		}
		if(opcion != 0) {
			opcion = -1;
		}
		} while(opcion != 0);
	}

int AltaDeChofer(eChofer* chofer, int tam_Choferes, int* idChofer) {

	 int retorno = -1;

	 int idFuncion = *(idChofer);

	 for(int i = 0; i < tam_Choferes; i++) {

		 if(chofer[i].isEmpty == VACIO) {

			 printf("\n****************************************** A L T A   D E   C H O F E R *****************************************\n\n");
			 chofer[i].id = idFuncion;
			 LoadString("Ingrese nombre completo del chofer: ",chofer[i].nombre);
			 chofer[i].salario = LoadInt("Ingrese salario del chofer: $",1,99999999);
			 chofer[i].horasTrabajadas = 0;
			 chofer[i].isEmpty = ACTIVO;

			 retorno = 0;
			 idFuncion++;

			 break;

		 }
	 }

	 *idChofer = idFuncion;
	 return retorno;
}
int BajaDeChofer(eChofer* choferes, int tam_Choferes) {

    int retorno = -1;
    int idABorrar;
    int opcion;

    if(choferes != NULL && ValidarListaChoferes(choferes, tam_Choferes) == 0) {

    	printf("\n****************************************** B A J A   D E   C H O F E R *****************************************\n\n");

    	    ImprimirListaDeChoferes(choferes, tam_Choferes);
    	    idABorrar = LoadInt("Ingrese el id que desea borrrar: ",1,9999);

    	    for(int i = 0; i < tam_Choferes; i++) {

    	    	if(choferes[i].isEmpty == ACTIVO && idABorrar == choferes[i].id) {
    	    		imprimirCabeceraChoferes();
    	    		imprimirUnChofer(choferes[i]);
    	    		opcion = LoadInt("Es este el chofer que desea borrar?:\n        1-> SI  0-> NO :",0,1);
    	    		 if(opcion == 1) {

    	    			 choferes[i].isEmpty = INACTIVO;
    	    			 retorno = 0;

    	    		 } else {

    	    			 printf("Operacion cancelada. ");
    	    			 retorno = -1;
    	    		 }

    	    		 break;
    	    	}

    	    }
    }


    return retorno;
}
int ModificacionDeChofer(eChofer* choferes, int tam_Choferes) {

	int retorno = -1;
	int idSeleccionado;
	int opcion = -1;
	if(choferes != NULL && ValidarListaChoferes(choferes, tam_Choferes)== 0) {

		system("cls");
		printf("\n****************************************** M O D I F C A C I O N   D E   C H O F E R *****************************************\n\n");

		ImprimirListaDeChoferes(choferes, tam_Choferes);
		idSeleccionado = LoadInt("Ingrese el id que desea modificar: ",1,9999);
		for(int i = 0; i < tam_Choferes; i++) {

			if(choferes[i].isEmpty == ACTIVO && idSeleccionado == choferes[i].id) {

				do {
					system("cls");
					printf("\n\n");
					imprimirCabeceraChoferes();
					imprimirUnChofer(choferes[i]);
					printf("\n 1 - MODIFICAR NOMBRE\n 2 - MODIFICAR SALARIO\n 3 - MODIFICAR HORAS TRABAJADAS\n 0 - VOLVER\n\n");
					opcion = LoadInt("Opcion:" , 0, 3);
					switch(opcion) {

						case 1:
							LoadString("Ingrese nombre completo del chofer: ",choferes[i].nombre);
							break;
						case 2:
							choferes[i].salario = LoadInt("Ingrese salario del chofer: $",1,99999999);
							break;
						case 3:
							choferes[i].horasTrabajadas =  LoadInt("Ingrese horas trabajadas: ",1,99999999);
							break;
					}

					if(opcion != 0) {

						opcion = -1;
						retorno = 0;
					}

				} while( opcion != 0);

				break;
			}
		}
	}

	return retorno;
}
void ImprimirListaDeChoferes(eChofer* chofer, int tam_Choferes) {

	imprimirCabeceraChoferes();
	for(int i = 0; i < tam_Choferes; i++) {

		if(chofer[i].isEmpty == ACTIVO) {

			imprimirUnChofer(chofer[i]);
		}
	}
}
void imprimirUnChofer(eChofer chofer) {

	printf("%4d %30s %20.2f  %10d\n", chofer.id, chofer.nombre, chofer.horasTrabajadas, chofer.salario);
}
void imprimirCabeceraChoferes(void) {
	printf("  ID                         NOMBRE        HS. TRABJADAS      SUELDO\n");
}
