
#include "Localidades.h"
#include "Biblioteca.h"
#include "ArrayEmployees.h"
#include "ArrayPedidos.h"
#include "Controller.h"
#include "ArrayChoferes.h"
#include "Ordenamientos.h"

void Listados(ePedido* pedido,int tam_Pedido, eLocalidad* localidad, int tam_Localidad, eCliente* cliente, int tam_CLiente, eChofer* chofer, int tam_Choferes) {

	int retorno = 0;
	int opcion;

	do {
		system("cls");
		printf("\n****************************************** L I S T A S D O S   Y   B O N O S  *****************************************\n\n");

		printf(" 1 - ORDENAMIENTO POR ID DE CHOFERES \n 2 - VIAJES REALIZADOS POR CADA CHOFER\n");
		printf(" 3 - LOCALIDADES RECORRIDAS POR CADA CHOFER\n 4 - CHOFERES CON MAS VIAJES \n 5 - DAR BONO POR 3 VIAJES REALIZADOS\n 0 - VOLVER\n ");
		opcion = LoadInt("OPCION = ",0,5);

		switch (opcion) {
			case 1:
				retorno = OrdenamientoPorId(chofer, tam_Choferes);
				AlertMessageAndEnter(retorno, "", "");
				break;
			case 2:
				retorno = ViajesRealizadosPorCadaChofer(pedido, tam_Pedido, cliente, tam_CLiente, chofer, tam_Choferes);
				AlertMessageAndEnter(retorno, "", "Los choferes no tienen horas trabajadas.");
				break;
			case 3:
				retorno = LocalidadesRecorridasPorCadaChofer(pedido, tam_Pedido, localidad, tam_Localidad, cliente, tam_CLiente, chofer, tam_Choferes);
				AlertMessageAndEnter(retorno, "", "");
				break;
			case 4:
				retorno = ChoferConMasViajes(pedido, tam_Pedido, cliente, tam_CLiente, chofer, tam_Choferes);
				AlertMessageAndEnter(retorno, "", "");
				break;
			case 5:
				retorno = BonoPorViajes(pedido, tam_Pedido, cliente, tam_CLiente, chofer, tam_Choferes);
				AlertMessageAndEnter(retorno, "Se realizaron modificaciones en los salarios", "No hay choferes a los que bonificar.");
				break;


		}

		if(opcion != 0) {
			opcion = -1;
			retorno = 0;

		}
	} while(opcion != 0);

}

int OrdenamientoPorId(eChofer* choferes, int tam_Choferes) {

	eChofer choferAux;
	int retorno = -1;

	for(int i = 0; i<tam_Choferes - 1; i++) {


		if(choferes[i].isEmpty == ACTIVO) {

			for(int j = i+1; j<tam_Choferes; j ++) {

				if(choferes[j].isEmpty == ACTIVO) {

					if(choferes[i].id > choferes[j].id) {

						choferAux = choferes[i];
						choferes[i] = choferes[j];
						choferes[j] = choferAux;
						retorno = 0;
					}
				}
			}
		}
	}
	ImprimirListaDeChoferes(choferes, tam_Choferes);

	return retorno;
}

int ViajesRealizadosPorCadaChofer(ePedido* pedido, int tam_Pedido, eCliente*cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes) {

	int retorno = -1;
		for(int c = 0; c < tam_Choferes; c++) {

			if(choferes[c].isEmpty  == ACTIVO && choferes[c].horasTrabajadas > 0) {

				printf("\nCHOFER: %s\n", choferes[c].nombre);
				MostrarCabezal(1);

				for(int i= 0; i < tam_CLiente; i++) {

					if(cliente[i].estado == ACTIVO) {

						for(int j = 0; j < tam_Pedido; j ++) {

							if( cliente[i].id == pedido[j].idCliente && pedido[j].estaVacante == ACTIVO && pedido[j].iDdelChofer == choferes[c].id) {

								ImprimirPedido(pedido[j], cliente[i],1);
								retorno = 0;
							}
						}
					}
				}
			}
		}

	return retorno;
}

int BonoPorViajes(ePedido* pedido, int tam_Pedido, eCliente*cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes) {

	int retorno = -1;
	int contadorViajes = 0;

	for(int c = 0; c < tam_Choferes; c++) {

		if(choferes[c].isEmpty == ACTIVO && choferes[c].horasTrabajadas > 0) {


			for(int i = 0; i < tam_CLiente; i++) {

				if(cliente[i].estado == ACTIVO) {

					for(int j = 0; j < tam_Pedido; j ++) {

						if( cliente[i].id == pedido[j].idCliente && pedido[j].estaVacante == ACTIVO && pedido[j].iDdelChofer == choferes[c].id) {

							contadorViajes ++;


						}
					}
				}
			}
			if(contadorViajes >= 5 && choferes[c].descuento == 0) {

				retorno = 0;
				choferes[c].salario = choferes[c].salario * 1.15;
				choferes[c].descuento = 1;
			}
		}
		contadorViajes = 0;

	}
		return retorno;
	}

int LocalidadesRecorridasPorCadaChofer(ePedido* pedido, int tam_Pedido, eLocalidad* localidad, int tam_Localidad, eCliente*cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes) {

	int retorno = -1;
	int localidadAuxiliar = 0;

	for(int c = 0; c < tam_Choferes; c++) {

		if(choferes[c].isEmpty == ACTIVO && choferes[c].horasTrabajadas > 0) {

			printf("\n\n  CHOFER: %s\n  -", choferes[c].nombre);

			for(int i = 0; i < tam_CLiente; i++) {

				if(cliente[i].estado == ACTIVO) {

					for(int j = 0; j < tam_Pedido; j ++) {

						if(pedido[j].estaVacante == ACTIVO) {

							for(int l = 0; l<tam_Localidad; l++) {

								if( cliente[i].id == pedido[j].idCliente && pedido[j].iDdelChofer == choferes[c].id &&
										cliente[i].localidad == localidad[l].idLocalidad && localidadAuxiliar != localidad[l].idLocalidad) {

									localidadAuxiliar = localidad[l].idLocalidad;
									printf("%s - ", localidad[l].descripcion);
									retorno = 0;
								}
							}
						}
					}
				}
			}
		}
	}

	printf("\n");
	return retorno;
}

int ChoferConMasViajes(ePedido* pedido, int tam_Pedido, eCliente* cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes) {

	int retorno = -1;
	int acumulador = 0;
	int maximo;
	int flag = 1;

	for(int c = 0; c < tam_Choferes; c++) {

		if(choferes[c].isEmpty == ACTIVO && choferes[c].horasTrabajadas > 0) {

			for(int i = 0; i < tam_CLiente; i++) {

				if(cliente[i].estado == ACTIVO) {

					for(int j = 0; j < tam_Pedido; j++) {

						if(pedido[j].estaVacante == ACTIVO && cliente[i].id == pedido[j].idCliente && pedido[j].iDdelChofer == choferes[c].id) {

							acumulador ++;
						}
					}
				}
			}

			if(flag || acumulador > maximo) {

				maximo = acumulador;
				flag = 0;
				retorno = 0;
			}

			acumulador = 0;
		}
	}

	if(retorno == 0) {

		MostrarChoferesConMasViajes(pedido, tam_Pedido, cliente, tam_CLiente, choferes, tam_Choferes, maximo);
	}


	return retorno;

}

void MostrarChoferesConMasViajes(ePedido* pedido, int tam_Pedido, eCliente* cliente, int tam_CLiente, eChofer* choferes, int tam_Choferes, int maximo) {

	int acumulador;

	printf("ID                           CHOFER        VIAJES TOTALES       HORAS TRABAJADAS        SALARIO \n");

	for(int c = 0; c < tam_Choferes; c++) {

		if(choferes[c].isEmpty == ACTIVO && choferes[c].horasTrabajadas > 0) {

			for(int i = 0; i < tam_CLiente; i++) {

				if(cliente[i].estado == ACTIVO) {

					for(int j = 0; j < tam_Pedido; j++) {

						if(pedido[j].estaVacante == ACTIVO && cliente[i].id == pedido[j].idCliente && pedido[j].iDdelChofer == choferes[c].id) {

							acumulador ++;
						}
					}

				}
			}
		}

		if (acumulador == maximo) {

			printf("%4d %30s %21d %22.2f %14d\n",choferes[c].id,choferes[c].nombre,acumulador,choferes[c].horasTrabajadas,choferes[c].salario);
		}

		acumulador = 0;
	}
}

