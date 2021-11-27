#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArrayPedidos.h"
#include "ArrayEmployees.h"
#include "Localidades.h"
#include "Biblioteca.h"
#include "ArrayChoferes.h"

#define ACTIVO 1
#define INACTIVO 0

#define TAM_CLIENTES 1000
#define TAM_PEDIDOS  100
#define TAM_LOCALIDADES 300

#define PENDIENTE 0
#define PROCESADO 1



//Funciones de pedidos


void InicializarListaPedidos(ePedido* pedidos, int tamanioLista) {

	for(int i = 0; i < tamanioLista; i++) {

        pedidos[i].estaVacante = INACTIVO;
    }
}

int validarPedidosProcesados(eCliente* ListaClientes, int tam_Clientes, ePedido* ListaPedidos, int tam_Pedidos) {

    int retorno = -1;

    if (ListaClientes != NULL && ListaPedidos != NULL && ValidarListaPedidos(ListaClientes, tam_Clientes, ListaPedidos, tam_Pedidos == 0)) {

    	for(int i=0; i < tam_Clientes; i++) {

    		if(ListaClientes[i].estado == ACTIVO) {

    			for(int j=0; j<tam_Pedidos; j++) {

    				if(ListaPedidos[j].estaVacante == ACTIVO && ListaPedidos[j].estadoPedido == PROCESADO) {

    					retorno = 0;
    					break;

    				}
    			}
    		}
    	}
    }
    return retorno;

}

int validarPedidosPendientes(eCliente* ListaClientes, int tam_Clientes, ePedido* ListaPedidos, int tam_Pedidos) {

	int retorno = -1;

	if (ListaClientes != NULL && ListaPedidos != NULL && ValidarListaPedidos(ListaClientes, tam_Clientes, ListaPedidos, tam_Pedidos == 0)) {

		for(int i = 0; i < tam_Clientes; i++) {

			if(ListaClientes[i].estado == ACTIVO) {

				for(int j = 0; j < tam_Pedidos; j++) {

					if(ListaPedidos[j].estaVacante == ACTIVO && ListaPedidos[j].estadoPedido == PENDIENTE) {
						retorno = 0;
						break;

					}
				}
			}
		}
	}
	return retorno;
}

int ValidarListaPedidos(eCliente* ListaClientes, int tam_Clientes,ePedido* ListaPedidos, int tam_Pedidos) {

    int retorno = -1;


    for(int i=0; i < tam_Clientes; i++) {

        if(ListaClientes[i].estado == ACTIVO) {

            for(int j = 0; j < tam_Pedidos; j++) {

                if(ListaPedidos[j].estaVacante == ACTIVO) {

                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int CrearPedidoDeRecoleccion(ePedido* pedido,int tamanio_Pedidos, eCliente* listaDeClientes, int tamanio_Cliente,
		eLocalidad* listaDeLocalidades, int tam_localidades,eChofer* listaDeChoferes, int tam_choferes, int* idPedido) {

	int retorno = -1;
    int idAux;
    idAux = *idPedido;

    printf("******************************************C R E A R   P E D I D O   D E   R E C O L E C C I O N *****************************************\n\n");
    ImprimirListaDeClientes(listaDeClientes,tamanio_Cliente, listaDeLocalidades,tam_localidades, 0);
    retorno = AltaPedido(pedido, tamanio_Pedidos, listaDeClientes, tamanio_Cliente,listaDeLocalidades, tam_localidades,listaDeChoferes, tam_choferes, idAux);

    if(retorno == 0) {

        idAux++;

    } else {

    	printf("Id no encontrado. ");
    }

    *idPedido = idAux;

    return retorno;
}

int AltaPedido(ePedido* pedido, int tam_Pedidos, eCliente* listaDeClientes,int tam_Clientes,eLocalidad* localidad, int tam_localidad,eChofer* choferes, int tam_choferes, int idPedido) {

	int retorno = -1;
	int idDelCliente;
	int estadoBusqueda;
	int validar;
	int idDelChofer;
	float horas;
	int flag = 1;
	do {

	  idDelCliente = LoadInt("Ingrese el id del cliente que realizo el pedido: ",1,9999);
	  estadoBusqueda = BuscarYMostrarClientePorId(listaDeClientes,tam_Clientes,localidad, tam_localidad, idDelCliente);
	  validar =  LoadInt("Confirmar pedido:\n        1-> SI  0-> NO :",0,1);

	} while(validar == 0);

	if(estadoBusqueda == 0) {

      for (int i = 0; i < tam_Pedidos; i++) {

    	  if(pedido[i].estaVacante == INACTIVO) {

    		  do {
    			  system("cls");
    			  ImprimirListaDeChoferes(choferes, tam_choferes);

    			  idDelChofer = LoadInt("Ingrese el id del chofer que realizo el viaje: ", 1, 1000);
    			  for(int j = 0; j < tam_choferes; j++) {
    				  if(choferes[j].id == idDelChofer) {
    					  horas = LoadFloat("Ingrese las horas que se demoro el chofer: ", 0);
    					  choferes[j].horasTrabajadas =  choferes[j].horasTrabajadas + horas;
    					  flag = 0;
    					  break;
    				  }
    			  }
    		  }while(flag);

    		  pedido[i].iDdelChofer = idDelChofer;

    		  pedido[i].idPedido = idPedido;
    		  pedido[i].idCliente = idDelCliente;
              pedido[i].kilosTotales = LoadFloat("Ingrese cantidad de KILOS TOTALES(MINIMO 10kg): ",10);
              pedido[i].estadoPedido = PENDIENTE;
              pedido[i].estaVacante = ACTIVO;
              strcpy(pedido[i].descripcion,"PENDIENTE");

              retorno = 0;
              break;
        }
    }
        if(estadoBusqueda == 0 && retorno != 0) {

        	printf("No hay espacio para realizar un pedido.\n");
        }
    }
    	return retorno;
	}

int ProcesarResiduos(ePedido*listaDePedidos,int tam_Pedidos,eCliente* listaDeClientes, int tam_Clientes){

    int retorno=-1;
    int caso;
    int idPedido;
    int estado;

    printf("****************************************** P R O C E S A R   R E S I D U O S *****************************************\n\n");
    estado= MostrarListaDePedidosPendientes(listaDePedidos,tam_Pedidos,listaDeClientes, tam_Clientes);
    if(estado == 0) {

        idPedido = LoadInt("Ingrese el id del pedido que desea procesar: ",1,9999);
        retorno = BuscarYMostrarPedidoPorId(listaDePedidos,tam_Pedidos,listaDeClientes,tam_Clientes,idPedido);//1 por el tipo de cabezal; 1.para pendientes,0 para procesados

        if(retorno == 0) {

            caso = IngresarKilos(listaDePedidos,tam_Pedidos,idPedido);
            if(caso == -1) {

                retorno = -1;
                printf("Operacion cancelada. ");
            }
        }else {
            printf("No se encontro el id. ");
        }
    }else{
        printf("La lista esta vacia.");
    }
    return retorno;
}

int MostrarListaDePedidosPendientes(ePedido* pedidos,int tam_Pedidos, eCliente* clientes,int tam_Clientes) {

	int retorno = -1;
    MostrarCabezal(1);

    for(int i = 0; i < tam_Pedidos; i++) {

        if(pedidos[i].estaVacante == ACTIVO && pedidos[i].estadoPedido == PENDIENTE ) {

            for(int j = 0; j < tam_Clientes; j++) {

                if(clientes[j].estado == ACTIVO && pedidos[i].idCliente == clientes[j].id) {

                    ImprimirPedido(pedidos[i], clientes[j],1);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

void ImprimirPedido(ePedido pedido, eCliente cliente,int caso) {

    if (caso == 1) {

    	printf("%9d %20s %20s %5d %6d %15.2f KG %20s\n",pedido.idPedido, cliente.empresa,cliente.calle, cliente.altura, cliente.cuit, pedido.kilosTotales, pedido.descripcion);
    }

    if (caso == 0) {

    	printf("%9d %20s %20s %5d %6d %5.2f KG %5.2f KG %5.2f KG %20s\n",
    			pedido.idPedido, cliente.empresa,cliente.calle, cliente.altura, cliente.cuit,pedido.kilosHDPE,pedido.kilosLDPE,pedido.kilosPP, pedido.descripcion);
    }
}

void MostrarCabezal(int cabezal) {

        if(cabezal == 1) {

        	printf("ID PEDIDO              EMPRESA                  DIRECCION   CUIT      KILOS TOTALES    ESTADO DEL PEDIDO\n\n");
        }

        if(cabezal == 0) {

        	printf("ID PEDIDO              EMPRESA                  DIRECCION   CUIT     HDPE     LDPE        PP    ESTADO DEL PEDIDO\n\n");
        }
}

int BuscarYMostrarPedidoPorId(ePedido* pedido, int tam_Pedidos,eCliente* cliente, int tam_Clientes, int id) {

    int retorno = -1;

    for(int i = 0; i < tam_Pedidos; i++) {

    	if(pedido[i].estaVacante == ACTIVO && pedido[i].idPedido == id && pedido[i].estadoPedido == PENDIENTE) {

    		for(int j = 0; j < tam_Clientes; j++) {

    			if(cliente[j].estado == ACTIVO && pedido[i].idCliente == cliente[j].id) {

    				MostrarCabezal(1);
    				ImprimirPedido(pedido[i],cliente[j],1);
    				retorno = 0;
    				break;
    			}
    		}
    	}
    }

    return retorno;
}

int IngresarKilos(ePedido* pedido, int tam_Pedidos,int idIngresado) {

    int opcion;
    int retorno;
    float kilosAux;

    for(int i = 0; i < tam_Pedidos; i++) {

        if(pedido[i].idPedido == idIngresado) {

            pedido[i].kilosHDPE = 0;
            pedido[i].kilosLDPE = 0;
            pedido[i].kilosPP = 0;

            kilosAux = pedido[i].kilosTotales;
            do {
				system("cls");
				printf("************************ T I P O S    D E    P L A S T I C O S ************************\n");
				printf("INGRESE LOS TIPOS DE PLASTICOS (TOTAL = %.2f KG||QUEDAN = %.2f KG):  \n", pedido[i].kilosTotales, kilosAux);
				printf("POLIETILENO DE ALTA DENSIDAD (HDPE) = %6.2f KG\n", pedido[i].kilosHDPE);
				printf("POLIETILENO DE BAJA DENSIDAD (LDPE) = %6.2f KG\n", pedido[i].kilosLDPE);
				printf("POLIPROPILENO (PP) = %6.2f KG\n", pedido[i].kilosPP);
				printf("BASURA= %6.2f KG\n\n", pedido[i].basura);

					if(kilosAux < 0) {

						printf("***********Ingrese datos validos***********\n");
					}

				printf("| 1-HDPE | 2-LDPE | 3-PP | 4-CARGAR DATOS | 0-CANCELAR |");

				opcion = LoadInt("OPCION: ", 0, 4);

				switch(opcion) {

					case 1:
						pedido[i].kilosHDPE = LoadFloat("Ingrese KG de HDPE: ", 0);
						break;

					case 2:
						pedido[i].kilosLDPE = LoadFloat("Ingrese KG de LDPE: ", 0);
						break;

					case 3:
						pedido[i].kilosPP = LoadFloat("Ingrese KG de PP: ",0);
						break;

					case 4:
						if(kilosAux > 0) {

							pedido[i].estadoPedido = PROCESADO;
							strcpy(pedido[i].descripcion, "COMPLETADO");
							retorno = 0;
						}
						break;

					case 0:
						pedido[i].kilosHDPE = 0;
						pedido[i].kilosLDPE = 0;
						pedido[i].kilosPP = 0;
						retorno = -1;
						break;
				}
				kilosAux = pedido[i].kilosTotales-pedido[i].kilosHDPE-pedido[i].kilosLDPE-pedido[i].kilosPP;
				pedido[i].basura = pedido[i].kilosTotales-pedido[i].kilosHDPE-pedido[i].kilosLDPE-pedido[i].kilosPP;

            }while((opcion!=0 && opcion!=4) || kilosAux<0);
        }
    }
  return retorno;
}

int MostrarListaDePedidosProcesados(ePedido* pedido,int tam_Pedidos, eCliente* cliente, int tam_Clientes) {

    printf("****************************************** P E D I D O S   P R O C E S A D O S *****************************************\n\n");
    int retorno = -1;
    MostrarCabezal(0);

    for(int i = 0; i<tam_Pedidos;i++) {

        for(int j = 0; j < tam_Clientes; j++) {

            if(pedido[i].estaVacante == ACTIVO && cliente[j].estado == ACTIVO && pedido[i].idCliente == cliente[j].id && pedido[i].estadoPedido == PROCESADO) {

                ImprimirPedido(pedido[i], cliente[j],0);
                retorno = 0;
            }
        }
    }

    return retorno;

}

//----------------------------------------------F U N C I O N E S   M I X T A S --------------------------------------

int ListaDeClientesConPendinetes(eCliente* cliente, int tam_Clientes, ePedido* pedido,int tam_Pedidos, eLocalidad * localidad, int tam_localidad) {

    printf("****************************************** P E D I D O S   P E N D I E N T E S   P O R   C L I E N T E *****************************************\n\n");
    int retorno = -1;
    int contadorPedidos = 0;
    MostrarCabezalClientes(1);

    for(int i = 0; i < tam_Clientes; i++) {

        if(cliente[i].estado == ACTIVO) {

        	for(int p = 0; p < tam_Pedidos; p++) { //for para calcular la cantidad de pedidos que hay a nombre de los clientes

        		if(pedido[p].estaVacante == ACTIVO && pedido[p].estadoPedido == PENDIENTE &&
        				cliente[i].id == pedido[p].idCliente) {
        			contadorPedidos++;
        		}

        	}

        	for(int j = 0; j < tam_localidad; j++) {

        		if(cliente[i].localidad == localidad[j].idLocalidad) { // for para printear solo si matchea el id con el id de la localidad

        			printf("%4d %20s %15d %20s %6d %30s %5d\n",cliente[i].id, cliente[i].empresa, cliente[i].cuit,cliente[i].calle,
        					cliente[i].altura, localidad[j].descripcion, contadorPedidos);
        			contadorPedidos = 0;
        			break;
        		}
        	}
        }
        retorno = 0;
    }

    return retorno;
}

int MostrarPedidosPorLocalidad(eCliente* cliente, int tam_Clientes, ePedido* pedido, int tam_Pedidos, eLocalidad * localidades, int tam_localidades) {

    int retorno = -1;
    int contadorPedidosPendientesPorLocalidad = 0;
    char LocalidadIngresada[51];

    printf("****************************************** P E D I D O S   P O R   L O C A L I D A D *****************************************\n\n");
    ImprimirListaDeLocalidades(localidades, tam_localidades);
    LoadString("Ingrese una localidad(Sin numeros):", LocalidadIngresada);
    system("cls");

      for(int i = 0; i < tam_localidades; i++) {
    	  if(strcmp(LocalidadIngresada,localidades[i].descripcion) == 0) {

    		  for(int j = 0; j < tam_Clientes; j++) {

    			  if(cliente[j].estado == ACTIVO && cliente[j].localidad == localidades[i].idLocalidad) {
    				  MostrarCabezal(1);
    				  for(int p = 0; p < tam_Pedidos; p ++ ) {

    					  if(pedido[p].estaVacante == ACTIVO && pedido[p].estadoPedido == PENDIENTE &&
    							  pedido[p].idCliente == cliente[j].id) {

    						  ImprimirPedido(pedido[p], cliente[j], 1);
    						  contadorPedidosPendientesPorLocalidad++;
    						  retorno = 0;
    					  }
    				  }
    				  printf("\n");
    				  break;
    			  }
    		  }
    	  }
      }

      if(retorno == 0) {

    	printf("Se encontraron %d pedidos en la localidad de %s.",contadorPedidosPendientesPorLocalidad, LocalidadIngresada);
    }

    return retorno;
}

int CantidadPoliPropilenoPromedioCliente(eCliente* cliente,int tam_Clientes, ePedido* pedido, int tam_Pedidos) {

    printf("****************************************** P O L I P R O P I L E N O *****************************************\n\n");
    int retorno = -1;
    float acumuladorKGPP = 0;
    int contadorClientesTotales = 0;
    float promedio;

    for(int i = 0; i < tam_Clientes; i++) {

        if(cliente[i].estado == ACTIVO) {

        	contadorClientesTotales++;

            for(int j = 0; j < tam_Pedidos; j++) {

                if(cliente[i].id == pedido[j].idCliente && pedido[j].estaVacante == ACTIVO &&
                		pedido[j].estadoPedido == PROCESADO && pedido[j].kilosPP > 0) {

                    acumuladorKGPP = acumuladorKGPP + pedido[j].kilosPP;
                    retorno = 0;
                }
            }
        }
    }

    if(retorno == 0) {

    	promedio = acumuladorKGPP/contadorClientesTotales;
    	printf("El promedio de kg de POLIPROPILENO por cliente es de %.2f KG\n", promedio);
    	printf("Con un total de %.2f KG y un total de %d cliente(s) activos. \n",acumuladorKGPP,contadorClientesTotales);
    }

    return retorno;
}

//funciones parcial, informes

int ClientesConMasPedidosPendientes(eCliente* cliente, int tam_Clientes, ePedido* pedido, int tam_Pedidos, eLocalidad* localidades, int tam_Localidades) {

    int retorno = -1;
    int flag = 1;
    int maximo;
    int contadorPendientes = 0;

    MostrarCabezalClientes(1);

    for(int i = 0; i < tam_Clientes; i++) {

        if(cliente[i].estado == ACTIVO) {

        	for(int j = 0; j < tam_Pedidos; j++) {

        		if(pedido[j].estaVacante == ACTIVO && pedido[j].estadoPedido == PENDIENTE && cliente[i].id == pedido[j].idCliente) {

        			contadorPendientes++;

        		}
        	}

        	if(flag || contadorPendientes > maximo) {

        		maximo = contadorPendientes;
        		flag = 0;
        		retorno = 0;
        	}
        }

        contadorPendientes = 0;

    } //Hasta aca consegui la cantidad de pedidos maxima que un cliente puede tener

    for(int i = 0; i < tam_Clientes; i++)  {

    	if(cliente[i].estado == ACTIVO) {

    		for(int l = 0; l < tam_Localidades; l++) {

    			if(cliente[i].localidad == localidades[l].idLocalidad) {

    				for(int j = 0; j < tam_Pedidos; j++) {

    					if(pedido[j].estaVacante == ACTIVO && pedido[j].estadoPedido == PENDIENTE && cliente[i].id == pedido[j].idCliente) {

    						contadorPendientes++;
    					}
    				}

    				if(contadorPendientes == maximo) {

    					printf("%4d %20s %15d %20s %6d %30s %5d\n",cliente[i].id, cliente[i].empresa, cliente[i].cuit,cliente[i].calle,
    					        					cliente[i].altura, localidades[l].descripcion, contadorPendientes);
    				}
    			}
    		}
    	}
    	contadorPendientes = 0;
    }

    return retorno;
}


int ClientesConMasPedidosProcesados(eCliente* cliente, int tam_Clientes, ePedido* pedido, int tam_Pedidos,eLocalidad* localidades, int tam_Localidades){

    int retorno = -1;
    int flag = 1;
    int maximo;
    int contadorProcesados = 0;

    MostrarCabezalClientes(1);

    for(int i = 0; i < tam_Clientes; i++) {

        if(cliente[i].estado == ACTIVO) {

        	for(int j = 0; j < tam_Pedidos; j++) {

        		if(pedido[j].estaVacante == ACTIVO && pedido[j].estadoPedido == PROCESADO && cliente[i].id == pedido[j].idCliente) {

        			contadorProcesados++;

        		}
        	}

        	if(flag || contadorProcesados > maximo) {

        		maximo = contadorProcesados;
        		flag = 0;
        		retorno = 0;
        	}
        }

        contadorProcesados = 0;

    } //Hasta aca consegui la cantidad de pedidos maxima que un cliente puede tener

    for(int i = 0; i < tam_Clientes; i++)  {

    	if(cliente[i].estado == ACTIVO) {

    		for(int l = 0; l < tam_Localidades; l++) {

    			if(cliente[i].localidad == localidades[l].idLocalidad) {

    				for(int j = 0; j < tam_Pedidos; j++) {

    					if(pedido[j].estaVacante == ACTIVO && pedido[j].estadoPedido == PROCESADO && cliente[i].id == pedido[j].idCliente) {

    						contadorProcesados++;
    					}
    				}

    				if(contadorProcesados == maximo) {

    					printf("%4d %20s %15d %20s %6d %30s %5d\n",cliente[i].id, cliente[i].empresa, cliente[i].cuit,cliente[i].calle,
    					    					        					cliente[i].altura, localidades[l].descripcion, contadorProcesados);
    				}
    			}
    		}
    	}
    	contadorProcesados = 0;
    }

    return retorno;
}





