/*
 * ArrayElectrodomesticos.c
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayElectrodomesticos.h"
#include "utn_validaciones.h"

int inicializarElectrodomesticos(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos){
	int vRetorno = 0;
	int i;

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0) {

		for (i = 0; i < largoElectrodomesticos; i++) {

			listaElectrodomesticos[i].estaVacio = 1;

		}

	} else {

		vRetorno = -1;

	}

	return vRetorno;
}

int agregarElectrodomesticos(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos, eElectrodomesticos electrodomesticoIngresado) {

	int i;
	int vRetorno = -1;
	//Controlo si hay o no espacio libre

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0) {

		for (i = 0; i <= largoElectrodomesticos; i++) {

			if (listaElectrodomesticos[i].estaVacio == 1) { //Controlo si hay alguno libre

				//cargo los parametros recibidos
				listaElectrodomesticos[i]=electrodomesticoIngresado;
				vRetorno = 0;
				break;
			}
		}
	}

	return vRetorno;
}

int buscarElectrodomesticosPorId(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos,int id){

	int vRetorno = -1;
	int i;

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0) {

		for (i = 0; i < largoElectrodomesticos; i++) {

			if (listaElectrodomesticos[i].id == id && listaElectrodomesticos[i].estaVacio == 0) {
				vRetorno = i;
				break;
			}
		}
	}

	return vRetorno;

}
int removerElectrodomesticos(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos, int id) {

	int vRetorno = -1;
	int posicion;

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0) {
		posicion = buscarElectrodomesticosPorId(listaElectrodomesticos, largoElectrodomesticos, id);
		if (posicion >= 0) {
			listaElectrodomesticos[posicion].estaVacio = 1;
			vRetorno = 0;
		}
	}

	return vRetorno;
}
int ordenarElectrodomesticos(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eMarca* listadoMarcas,int largoMarcas, int orden) {

	int vRetorno = -1;
	int i;
	int j;
	eElectrodomesticos aux;

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && (orden == 0 || orden == 1)) {

		switch (orden) {
		case 0:
			for (i = 0; i < largoElectrodomesticos - 1; i++) {

				for (j = 0; j < largoElectrodomesticos; j++) {

					if (listaElectrodomesticos[i].estaVacio == 0
							&& listaElectrodomesticos[j].estaVacio == 0) {

						if (listaElectrodomesticos[i].modelo>listaElectrodomesticos[j].modelo) {

							aux = listaElectrodomesticos[i];
							listaElectrodomesticos[i] =
									listaElectrodomesticos[j];
							listaElectrodomesticos[j] = aux;

						} else if (listaElectrodomesticos[i].modelo==listaElectrodomesticos[j].modelo) {


							if (strcmp(listaElectrodomesticos[i].serie, listaElectrodomesticos[j].serie) > 0) {

								aux = listaElectrodomesticos[i];
									listaElectrodomesticos[i] =listaElectrodomesticos[j];
								listaElectrodomesticos[j] = aux;

							}
						}

					}
				}
			}

			vRetorno = 0;

			break;

		case 1:
			for (i = 0; i < largoElectrodomesticos - 1; i++) {

				for (j = 0; j < largoElectrodomesticos; j++) {

					if (listaElectrodomesticos[i].estaVacio == 0
							&& listaElectrodomesticos[j].estaVacio == 0) {

						if (listaElectrodomesticos[i].modelo<listaElectrodomesticos[j].modelo) {

							aux = listaElectrodomesticos[i];
							listaElectrodomesticos[i] = listaElectrodomesticos[j];
							listaElectrodomesticos[j] = aux;

						} else if (listaElectrodomesticos[i].modelo==listaElectrodomesticos[j].modelo) {

							if (strcmp(listaElectrodomesticos[i].serie, listaElectrodomesticos[j].serie) < 0) {

								aux = listaElectrodomesticos[i];
								listaElectrodomesticos[i] = listaElectrodomesticos[j];
								listaElectrodomesticos[j] = aux;

							}
						}
					}

				}
			}

			vRetorno = 0;
			break;
		}

	}

	return vRetorno;
}

int imprimirElectrodomesticos(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos,eMarca* listaMarcas, int largoMarcas)  {

	int vRetorno = -1;
	int i;
	char descMarca[21];

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && listaMarcas != NULL && largoMarcas>0) {


		printf("+------------+--------------------------+--------------------------+\n");
		printf("|   SERIE    |          MODELO          |    DESCRIPCION MARCA     |\n");
		printf("+------------+--------------------------+--------------------------+\n");
		for (i = 0; i < largoElectrodomesticos; i++) {

			if (cargarDescMarca(listaElectrodomesticos[i].idMarca, listaMarcas, largoMarcas, descMarca)==0 && listaElectrodomesticos[i].estaVacio == 0) {
				printf("|%12s|%26d|%26s|\n",
						listaElectrodomesticos[i].serie,listaElectrodomesticos[i].modelo,descMarca);
				printf("+------------+--------------------------+--------------------------+\n");
				 vRetorno = 0;
			}

		}

			vRetorno = 0;
	}
	return vRetorno;
}


int imprimirElectrodomestico(int posicion,eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos,eMarca* listaMarcas, int largoMarcas){

	int vRetorno = -1;
	char descMarca[51];

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && listaMarcas != NULL && largoMarcas>0) {


		printf("+------------+--------------------------+--------------------------+\n");
		printf("|   SERIE    |          MODELO          |    DESCRIPCION MARCA     |\n");
		printf("+------------+--------------------------+--------------------------+\n");

			if (cargarDescMarca(listaElectrodomesticos[posicion].idMarca, listaMarcas, largoMarcas, descMarca)==0 && listaElectrodomesticos[posicion].estaVacio == 0) {
				printf("|%12s|%26d|%26s|\n",
						listaElectrodomesticos[posicion].serie,listaElectrodomesticos[posicion].modelo,descMarca);
				printf("+------------+--------------------------+--------------------------+\n");
				 vRetorno = 0;
			}

		vRetorno = 0;
	}
	return vRetorno;
}

int sueldoPromedioElectrodomesticos(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos, float *promedio) {

	int vRetorno = -1;
	int i;
	float suma = 0;
	int contadorEmpelados = 0;

	if (listaElectrodomesticos != NULL && promedio != NULL && largoElectrodomesticos > 0) {

		for (i = 0; i < largoElectrodomesticos; i++) {

			if (listaElectrodomesticos[i].estaVacio == 0)
			{
				//suma += listaElectrodomesticos[i].notaPromedio;
				contadorEmpelados++;
			}

		}

		if (contadorEmpelados == 0) {
			printf("\n No hay empleados cargados, no se puede calcular el promedio");
		} else {

			*promedio = suma / contadorEmpelados;
			vRetorno = 0;
		}

	}

	return vRetorno;

}
int hayElectrodomesticoCargado(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos) {

	int vRetorno = -1;
	int i;
	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0) {
		for (i = 0; i < largoElectrodomesticos; i++) {

			if (listaElectrodomesticos[i].estaVacio == 0) {
				vRetorno = 0;
				break;
			}

		}
	}

	return vRetorno;
}
int hardcodearElectrodomesticos(eElectrodomesticos* listaElectrodomesticos ,int largoElectrodomesticos , int cantidad){

	int vContador = 0;
	int vRetorno = -1;
	int i;

	if(listaElectrodomesticos !=  NULL && largoElectrodomesticos>0 && cantidad>0 && cantidad<= largoElectrodomesticos && cantidad<11){
		eElectrodomesticos listaAuxiliar[] =
		{
				{0,"20000", 1000, 1999,0},
				{1,"2000", 1000, 1992,0},
				{2,"20002", 1001, 2019,0},
				{3,"20003", 1002, 1987,0},
				{4,"20004", 1003, 2019,0},
				{5,"20005", 1003, 1887,0},
				{6,"20006", 1004, 1887,0},
				{7,"20007", 1001, 2019,0},
				{8,"20008", 1002, 1999,0},
				{9,"20009", 1001, 2019,0}
		};

			for(i =0; i<cantidad;i++){
				listaElectrodomesticos[i] = listaAuxiliar[i];
				vContador++;
			}
			vRetorno = vContador;
	}

	return vRetorno;
}

int validarSerieElectrodomestico(eElectrodomesticos *listadoElectrodomestico, int largoElectrodomestico,
		char* serie) {

	int vRetorno = -1;
	int i;

	if (listadoElectrodomestico != NULL && largoElectrodomestico > 0 && serie!= NULL) {
		for (i = 0; i < largoElectrodomestico; i++) {

			if (strcmp(listadoElectrodomestico[i].serie,serie)==0) {
				vRetorno = 0;
				break;
			}
		}
	}

	return vRetorno;
}

int pedirElectrodomesticoPorSerie(char *pSerieResultado, char *mensaje, char *mensajeError ,eElectrodomesticos *listadoElectrodomestico,
		int largoElectrodomestico, int reintentos,eMarca * listadoMarcas,int largoMarcas)
{

	int vRetorno = -1;
	char vBufferSerie[11];

	if (pSerieResultado != NULL && listadoElectrodomestico != NULL && largoElectrodomestico > 0
			&& reintentos >= 0 && pSerieResultado!= NULL) {
		do {
			system("cls");
			if (imprimirElectrodomesticos(listadoElectrodomestico, largoElectrodomestico, listadoMarcas, largoMarcas) == 0
					&& utn_getTexto(vBufferSerie, largoElectrodomestico, mensaje, mensajeError, 0) == 0
					&& validarSerieElectrodomestico(listadoElectrodomestico, largoElectrodomestico, vBufferSerie) == 0) {
				strcpy(pSerieResultado, vBufferSerie);
				vRetorno = 0;
				system("cls");
				break;
			}
			reintentos--;
		} while (reintentos >= 0);

	}

	return vRetorno;
}

int pedirSeriePorPantalla(eElectrodomesticos* listadoElectrodomesticos, int largoElectrodomesticos, int largoSerie,char * mensaje, char * mensajeError, int reintentos, char * pRetornoSerie){

	int vRetorno = -1;
	char vBuffer[largoSerie];
	int i;

	if(listadoElectrodomesticos != NULL && largoElectrodomesticos>0 && mensaje!= NULL && mensajeError != NULL && largoSerie>0 && reintentos>=0){

		do{
			system("cls");
			if(utn_getTexto(vBuffer, largoSerie,mensaje,mensajeError, 0)==0){
				for(i=0;i<largoElectrodomesticos;i++){
					if(strcmp(listadoElectrodomesticos[i].serie,vBuffer)!=0)
					{
						strncpy(pRetornoSerie, vBuffer,largoSerie);
						vRetorno=0;
						break;
					}else{
						printf(" El id Ingresado ya esta cagado\n");
						system("pause");
						break;
					}
				}
			}
			reintentos--;


		}while(reintentos>=0  && vRetorno == -1);
	}
	return vRetorno;
}
