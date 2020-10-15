/*
 * ArrayReparacion.c
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayReparacion.h"


int inicializarReparacion(eReparacion* listaReparacion, int largoReparacion){
	int vRetorno = 0;
	int i;

	if (listaReparacion != NULL && largoReparacion > 0) {

		for (i = 0; i < largoReparacion; i++) {

			listaReparacion[i].estaVacio = 1;

		}

	} else {

		vRetorno = -1;

	}

	return vRetorno;
}

int agregarReparacion(eReparacion *listaReparacion, int largoReparacion, eReparacion reparacionIngresada){

	int i;
	int vRetorno = -1;
	//Controlo si hay o no espacio libre

	if (listaReparacion != NULL && largoReparacion > 0) {

		for (i = 0; i <= largoReparacion; i++) {

			if (listaReparacion[i].estaVacio == 1) { //Controlo si hay alguno libre

				//cargo los parametros recibidos
				listaReparacion[i]=reparacionIngresada;
				vRetorno = 0;
				break;
			}
		}
	}

	return vRetorno;
}

int buscarReparacionPorId(eReparacion* listaReparacion, int largoReparacion,int id){

	int vRetorno = -1;
	int i;

	if (listaReparacion != NULL && largoReparacion > 0) {

		for (i = 0; i < largoReparacion; i++) {

			if (listaReparacion[i].id == id && listaReparacion[i].estaVacio == 0) {
				vRetorno = i;
				break;
			}
		}
	}

	return vRetorno;

}
int removerReparacion(eReparacion* listaReparacion, int largoReparacion, int id){

	int vRetorno = -1;
	int posicion;

	if (listaReparacion != NULL && largoReparacion > 0) {
		posicion = buscarReparacionPorId(listaReparacion, largoReparacion, id);
		if (posicion >= 0) {
			listaReparacion[posicion].estaVacio = 1;
			vRetorno = 0;
		}
	}

	return vRetorno;
}
/*int ordenarElectrodomesticos(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos, int orden) {

	int vRetorno = -1;
	int i;
	int j;
	eElectrodomesticos aux;

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && (orden == 0 || orden == 1)) {

		switch (orden) {
		case 0:
			for (i = 0; i < largoElectrodomesticos - 1; i++) {

				for (j = 0; j < largoElectrodomesticos; j++) {

					if (strcmp(listaElectrodomesticos[i].apellido, listaElectrodomesticos[j].apellido) > 0) {

						aux = listaElectrodomesticos[i];
						listaElectrodomesticos[i] = listaElectrodomesticos[j];
						listaElectrodomesticos[j] = aux;

					} else if (strcmp(listaElectrodomesticos[i].apellido, listaElectrodomesticos[j].apellido)
							== 0) {

						if (listaElectrodomesticos[i].idMarca > listaElectrodomesticos[j].idMarca) {

							aux = listaElectrodomesticos[i];
							listaElectrodomesticos[i] = listaElectrodomesticos[j];
							listaElectrodomesticos[j] = aux;

						}

					}

				}
			}

			vRetorno = 0;

			break;

		case 1:
			for (i = 0; i < largoElectrodomesticos - 1; i++) {

				for (j = 0; j < largoElectrodomesticos; j++) {

					if (strcmp(listaElectrodomesticos[i].apellido, listaElectrodomesticos[j].apellido) < 0) {

						aux = listaElectrodomesticos[i];
						listaElectrodomesticos[i] = listaElectrodomesticos[j];
						listaElectrodomesticos[j] = aux;

					} else if (strcmp(listaElectrodomesticos[i].apellido, listaElectrodomesticos[j].apellido)
							== 0) {

						if (listaElectrodomesticos[i].idMarca < listaElectrodomesticos[j].idMarca) {

							aux = listaElectrodomesticos[i];
							listaElectrodomesticos[i] = listaElectrodomesticos[j];
							listaElectrodomesticos[j] = aux;

						}

					}

				}
			}

			vRetorno = 0;
			break;
		}

	}

	return vRetorno;
}*/

int imprimirReparaciones(eReparacion * listaReparacion, int largoReparacion,eServicio* listaServicios, int largoServicios)  {

	int vRetorno = -1;
	int i;
	char descServicio[26];

	if (listaReparacion != NULL && largoReparacion > 0 && listaServicios != NULL && largoServicios>0) {


		printf("+------------+--------------------------+--------------------------+----------|\n");
		printf("|   SERIE    |          MODELO          |    DESCRIPCION MARCA     |   FECHA  |\n");
		printf("+------------+--------------------------+--------------------------+----------|\n");
		for (i = 0; i < largoReparacion; i++) {

			if (cargarDescServicio(listaReparacion[i].idServicio, listaServicios, largoServicios, descServicio)==0 && listaReparacion[i].estaVacio == 0) {
				printf("|%12s|%26s|%2d/%2d/%4d|\n",
						listaReparacion[i].serie,descServicio,listaReparacion[i].fecha.dia,
						listaReparacion[i].fecha.mes, listaReparacion[i].fecha.anio);
				printf("+------------+--------------------------+--------------------------+\n");
			}

		}

			vRetorno = 0;
	}
	return vRetorno;
}
int imprimirReparacion(int posicion,eReparacion *listaReparacion, int largoReparacion,eServicio* listaServicios, int largoServicios){

	int vRetorno = -1;
	char descServicio[26];

	if (listaReparacion != NULL && largoReparacion > 0 && listaServicios != NULL && largoServicios>0) {


			printf("+--------------------------+--------------------+--------------------------+----------------+----------------+-------------------+------------+\n");
			printf("|          CARRERA         |      APELLIDO      |          NOMBRE          |     NOTA 1     |     NOTA 2     |    NOTA PROMEDIO  |   LEGAJO   |\n");
			printf("+--------------------------+--------------------+--------------------------+----------------+----------------+-------------------+------------+\n");

			if (cargarDescServicio(listaReparacion[posicion].idServicio, listaServicios, largoServicios, descServicio)==0 && listaReparacion[posicion].estaVacio == 0) {
				printf("|%12s|%26s|%2d/%2d/%4d|\n",
						listaReparacion[posicion].serie,descServicio,listaReparacion[posicion].fecha.dia,
						listaReparacion[posicion].fecha.mes, listaReparacion[posicion].fecha.anio);
				printf("+------------+--------------------------+--------------------------+\n");

			}

		vRetorno = 0;
	}
	return vRetorno;
}


int sueldoPromedioReparaciones(eReparacion *listaReparacion, int largoReparacion, float *promedio) {

	int vRetorno = -1;
	int i;
	float suma = 0;
	int contadorEmpelados = 0;

	if (listaReparacion != NULL && promedio != NULL && largoReparacion > 0) {

		for (i = 0; i < largoReparacion; i++) {

			if (listaReparacion[i].estaVacio == 0)
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
int hayReparacionCargada(eReparacion *listaReparacion, int largoReparacion) {

	int vRetorno = -1;
	int i;
	if (listaReparacion != NULL && largoReparacion > 0) {
		for (i = 0; i < largoReparacion; i++) {

			if (listaReparacion[i].estaVacio == 0) {
				vRetorno = 0;
				break;
			}

		}
	}

	return vRetorno;
}
int hardcodearReparaciones(eReparacion* listaReparacion ,int largoReparacion , int cantidad){

	int vContador = 0;
	int vRetorno = -1;
	int i;

	if(listaReparacion !=  NULL && largoReparacion>0 && cantidad>0 && cantidad<= largoReparacion && cantidad<11){
		eReparacion listaAuxiliar[] =
		{

				{0,"AAAA",{12,5,2018},20001,0},
				{1,"AAAA",{20,5,2013},20000,0},
				{2,"AAAA",{4,8,2014},20003,0},
				{3,"AAAA",{20,3,2015},20002,0},
				{4,"AAAA",{11,5,2016},20000,0},
				{5,"AAAA",{5,1,2019},20001,0},
				{6,"AAAA",{5,10,2017},20003,0},
				{7,"AAAA",{1,1,2020} ,20002,0},
				{8,"AAAA",{20,6,2018},20009,0},
				{9,"AAAA",{12,5,2015},20008,0}
		};

			for(i =0; i<cantidad;i++){
				listaReparacion[i] = listaAuxiliar[i];
				vContador++;
			}
			vRetorno = vContador;
	}

	return vRetorno;
}

int removerReparacionPorSerieElectrod(eReparacion* listaReparacion,int largoReparacion,int vIdElectrodomestico, eElectrodomesticos* listaElectrodomestico, int largoElectrodomestico)
{
	int vRetorno = -1;
	int posicionElectrodomestico;
	char serie[11];
	int i;

	if (listaReparacion != NULL && largoReparacion > 0 && vIdElectrodomestico>0) {


		posicionElectrodomestico = buscarElectrodomesticosPorId(listaElectrodomestico, largoElectrodomestico, vIdElectrodomestico);
		if(posicionElectrodomestico>=0){
			strcpy(serie, listaElectrodomestico[posicionElectrodomestico].serie);

			for(i=0;i<largoReparacion;i++){

				if(listaReparacion[i].estaVacio == 0 && strcmp(listaReparacion[i].serie,serie)==0)
				{
					listaReparacion[i].estaVacio = 1;
					vRetorno=0;
				}

			}
		}
	}

	return vRetorno;
}
