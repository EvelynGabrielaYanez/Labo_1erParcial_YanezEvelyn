/*
 ============================================================================
 Name        : 1erParcial_Labo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include "ArrayElectrodomesticos.h"
#include "ArrayReparacion.h"
#include "ArrayServicio.h"
#include "ArrayMarca.h"
#include "utn_validaciones.h"
#include "main_modulos.h"

#define ELECTRODOMESTICOS 1000
#define REPARACIONES 1000
#define MARCAS 5
#define SERVICIOS 4
int main(void) {

	setbuf(stdout, NULL);

	eElectrodomesticos listaElectrodomesticos[ELECTRODOMESTICOS];
	eReparacion listaReparaciones[REPARACIONES];
	eServicio listaServicios[] = {{20000, "Garantia", 250}, {20001, "Mantenimiento", 500}, {20002, "Repuestos", 400}, {20003, "Refaccion", 600}};
	eMarca listaMarcas[] = {{1000, "Wirpool"}, {1001, "Sony"}, {1002, "Liliana"}, {1003, "Gafa"}, {1004, "Philips"}};

	int vRespSalir = 0; //0 = no, 1 = si
	int vContadorIdElectrodomestico = 0;
	int vContadorIdReparacion = 0;

	if (inicializarElectrodomesticos(listaElectrodomesticos, ELECTRODOMESTICOS) == 0 &&
			inicializarReparacion(listaReparaciones, REPARACIONES) == 0) {

		vContadorIdElectrodomestico+= hardcodearElectrodomesticos(listaElectrodomesticos, ELECTRODOMESTICOS, 10);
		vContadorIdReparacion+= hardcodearElectrodomesticos(listaElectrodomesticos, ELECTRODOMESTICOS, 10);

		do {
			switch (menu()) {
			case 1:
				altasElectrodomestico(listaElectrodomesticos, ELECTRODOMESTICOS, &vContadorIdElectrodomestico, listaMarcas, MARCAS);
				system("pause");
				break;
			case 2:
				modificarElectrodomestico(listaElectrodomesticos, ELECTRODOMESTICOS, listaMarcas, MARCAS);
				break;
			case 3:
				bajaElectrodomesticos(listaElectrodomesticos, ELECTRODOMESTICOS, listaMarcas, MARCAS, listaReparaciones, REPARACIONES);
				system("pause");
				break;
			case 4:
				//informar(lista, ALUMNOS , listaCarreras, CARRERAS);
				altaReparacion(listaReparaciones, REPARACIONES, &vContadorIdReparacion, listaServicios, SERVICIOS, listaElectrodomesticos, ELECTRODOMESTICOS, listaMarcas , MARCAS);
				system("pause");
				break;
			case 5:
				//listarElectrodomesticos(listaElectrodomesticos, ELECTRODOMESTICOS, listaMarcas, MARCAS);
				break;
			case 6:
				//informar(lista, ALUMNOS , listaCarreras, CARRERAS);
				//listaReparaciones(listaReparaciones, REPARACIONES, &vContadorIdReparacion, listaServicios, SERVICIOS, listaElectrodomesticos, ELECTRODOMESTICOS);
				system("pause");
				break;
			case 7:
				do{
				//Pregunto si desea salir hasta que ingrese s o n.
				vRespSalir = unt_preguntaRespuestaBinaria("\n Desea Salir?(s/n) ", 's', 'n');
				system("cls");
				}while(vRespSalir==-1);

				break;
			}

		} while (vRespSalir == 0); // Mientras vRespSalir = n continuo en el menu
	}
	return 0;
}
