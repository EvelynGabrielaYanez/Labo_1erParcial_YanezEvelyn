/*
 * TP2_modulos.c
 *
 *
 *      Author: Ya�ez Evelyn Gabriela
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayElectrodomesticos.h"
#include "ArrayReparacion.h"
#include "ArrayServicio.h"
#include "ArrayMarca.h"
#include "utn_validaciones.h"


#include "utn_validaciones.h"
#define REINTENTOS 5
#define CANTIDAD_CARACTERES_SERVICIO 26
#define CANTIDAD_CARACTERES_MARCA 21
#define CANTIDAD_CARACTERES_SERIE 11

int menu() {

	int vOpcionMenu;	  //va a contener la opcion del menu seleccionada
	int vResultadoIngreso;// va a ser 0 si el usuario ingreso la opcion de menu deseada correctamente y -1 si no

	do {
		//Imprimo el menu
		system("cls");
		printf("----------------EMPLEADOS---------------\n");
		printf(" 1.ALTA ELECTRODOMESTICO\n");
		printf(" 2.MODIFICAR ELECTRODOMESTICO\n");
		printf(" 3.BAJA ELECTRODOMESTICOS\n");
		printf(" 4.ALTA REPARACION\n");
		printf(" 5.LISTAR\n");
		printf(" 6.SALIR\n");
		printf("----------------------------------------\n");

		//Pido el ingreso de un numero entero entre 1 y 5 para seleccionar la opcion de menu
		vResultadoIngreso = utn_getNumero(&vOpcionMenu,
				" Ingrese la opcion deseada: ",
				" No ingreso una opcion valida.\n Vuelva a intentarlo.\n"
				, 1, 6,0);

	} while (vResultadoIngreso == -1);//Mientras que el el ingreso sea erroneo continuo pidiendolo

	system("cls");

	return vOpcionMenu;
}
void altasElectrodomestico(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos, int *pcontadorIdElect,
		eMarca* listaMarcas, int largoMarcas) {

	int vBanderaReintentos = 1;	// (1) se quedo sin reintentos (0) cargo correctamente
	eElectrodomesticos electrodomesticoIngresado;// contendra la informacion del alumno que ingresa el usuario


	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && *pcontadorIdElect >= 0 &&
			listaMarcas!= NULL && largoMarcas>0) {

		if (utn_getTextoSoloLetras(electrodomesticoIngresado.serie, CANTIDAD_CARACTERES_SERIE,
				" Ingrese el numero de serie: ",
				" Numero de serie invalido ", REINTENTOS)
				== 0) {
			system("cls");

			if (pedirMarcaPorID(&electrodomesticoIngresado.idMarca, " Ingrese el id de la marca: ",
					" Id ingresado invalido. ", listaMarcas , largoMarcas, REINTENTOS)
					== 0) {
				system("cls");
				if (utn_getNumero(&electrodomesticoIngresado.modelo,
						" Ingrese el ano del modelo: ",
						" Ingreso un ano invalido", 1000,2020 ,REINTENTOS)
						== 0) {
					system("cls");

					electrodomesticoIngresado.id = *pcontadorIdElect + 1;
					electrodomesticoIngresado.estaVacio = 0;
					vBanderaReintentos = 0;
					system("cls");

					if (agregarElectrodomesticos(listaElectrodomesticos, largoElectrodomesticos, electrodomesticoIngresado) == 0) {
					(*pcontadorIdElect)++;
						printf("\n Se le ha asignado el legajo: %d \n Alta exitosa.\n ",*pcontadorIdElect);

					} else {
						printf("\n Hay %d electrodomesticos cargados, no es posible cargar mas.\n No se ha dado el alta.\n ",
							largoElectrodomesticos);
					}

				}
			}
		}

		if (vBanderaReintentos == 1)
		{
			printf("\n No tiene mas reintentos.\n No se ha dado el alta.\n ");
		}
	}
	return;
}

void modificarElectrodomestico(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos,eMarca* listaMarcas, int largoMarca) {

	int vIdElectrodomestico;			//Contendra el Id que ingresa el electrodomestico para modificar
	int vOpcionSubMenu;			//Contendra la opcion seleccionada en el submenu
	int vPosicionElectrodomestico;//Contendra el estado de la opcion ingresada en el submenu 0 EXITO, -1 ERROR
	int vRespuestaVolver = 0;//Contendra la respuesta del usuario 0 (NO) o 1 (SI) a la pregunta 'desea volver?'

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && listaMarcas != NULL && largoMarca>0) {

		if (hayElectrodomesticoCargado(listaElectrodomesticos, largoMarca) == 0) {
			//Si se ingreso el ID de manera correcta, es decir, si es igual a 0.
			if (utn_getNumeroMin(&vIdElectrodomestico," Ingrese el ID del electrodomestico que desea modificar: ",
					" Tiene que ingresar un n�mero mayor a cero.", 0,
					REINTENTOS) == 0) {	//Buso el Id en el listado de alumnos
				vPosicionElectrodomestico = buscarElectrodomesticosPorId(listaElectrodomesticos, largoElectrodomesticos, vIdElectrodomestico);

				//Si no se encontro el ID del alunbi en el listado comunico y vuelvo al menu inicial
				if (vPosicionElectrodomestico == -1) {
					printf("\n No se ha ingresado ningun electrodomestico de Id %d ",vIdElectrodomestico);
				}
				else // Si se encontro el ID del alumnos en el listado
				{
					do {

						do { //Menu de modificacion. Sigo iterando mientras la opcion ingresada sea incorrecta
							system("cls");
							printf(
									"--------INFORMACION DEL ALUMNO---------\n\n");

							imprimirElectrodomestico(vPosicionElectrodomestico, listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarca);

							printf("\n\n----------------MODIFICAR---------------\n");
							printf(" 1.SERIE\n");
							printf(" 2.MARCA\n");
							printf(" 3.MODELO\n");
							printf(" 4.VOLVER\n");
							printf("----------------------------------------\n");

						} while (utn_getNumero(&vOpcionSubMenu,
								" Ingrese la opcion deseada modificar: ",
								" No ingreso una opcion valida.\n Vuelva a intentarlo.\n",
								1, 4, 0) == -1);

						system("cls");

						switch (vOpcionSubMenu) { //Analizo caso por caso de la opcion seleccionada del menu
						case 1:
							//Pido el ingreso del nombre modificado (solo dejo ingresar letras), si es correcto lo modifico
							if (utn_getTextoSoloLetras(
									listaElectrodomesticos[vPosicionElectrodomestico].serie,
									CANTIDAD_CARACTERES_SERIE,
									" Ingrese la serie del electrodomestico: ",
									" El numero de serie ingresado es invalido. ",
									REINTENTOS) == 0) {
								system("cls");
								printf("\n Modificacion realizada.\n ");
							} else {
								system("cls");
								printf("\n No se realizo la modificacion.\n ");
							}
							system("pause");
							break;
						case 2:

							if (pedirMarcaPorID(&listaElectrodomesticos[vPosicionElectrodomestico].idMarca
									, " Ingrese el ID de la marca: "," Ingreso un Id invalido ",
									listaMarcas, largoMarca, REINTENTOS) == 0) {
								system("cls");
								printf("\n Modificacion realizada.\n ");
							} else {
								system("cls");
								printf("\n No se realizo la modificacion.\n ");
							}
							system("pause");
							break;
						case 3:
							if (utn_getNumero(&listaElectrodomesticos[vPosicionElectrodomestico].modelo,
									" Ingrese el modelo modificado: ",
									" No ingreso un ano valida (1000-2020) ",
									1000, 2020, REINTENTOS) == 0) {
								system("cls");
								printf("\n Modificacion realizada.\n ");
							} else {
								system("cls");
								printf("\n No se realizo la modificacion.\n ");
							}
							system("pause");
							break;
						case 4:
							//Pregunto si desea volver al menu
							do {
								vRespuestaVolver = unt_preguntaRespuestaBinaria(
										" Desea volver?(s/n) ", 's', 'n');
								system("cls");
							} while (vRespuestaVolver == -1);
							break;
						}

					}while (vRespuestaVolver == 0); //Siempre que la respuesta de salida sea 0 vuelvo a iterar

					system("cls");
				}
			} else {
				system("cls");
				printf("\n Ya no tiene reintentos.\n ");
			}
		} else {
			system("cls");
			printf("\n No puede modificar, no hay empleados cagados.\n ");
		}
	}

	return;
}

void bajaElectrodomesticos(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos, eMarca * listaMarcas, int largoMarcas,
		eReparacion * listaReparacion, int largoReparacion) {

	int vIdElectrodomestico;	//Contendra el ID que el usuario ingresa para eliminar
	int vRetornoRespuestaEliminar=0; /* (1) si desea eliminar (0) si no desea eliminar
	 (-1) si no ingreso una opcion correcta*/
	int vPosicionElectrodomestico; //posicion del empleado que desea eliminar

	if (listaElectrodomesticos != NULL && largoElectrodomesticos > 0 && listaMarcas != NULL && largoMarcas>0) {
		if (hayElectrodomesticoCargado(listaElectrodomesticos, largoElectrodomesticos) == 0) {
			//Pido al usuario que ingrese el ID y veo si ingreso el usuario correctamente (EXITO)
			if (utn_getNumeroMin(&vIdElectrodomestico,
					" Ingrese el ID del usuario que desea eliminar: ",
					" No ingreso un Id valido.", 0, REINTENTOS) == 0) {
				system("cls");
				vPosicionElectrodomestico = buscarElectrodomesticosPorId(listaElectrodomesticos, largoElectrodomesticos, vIdElectrodomestico);

				if (vPosicionElectrodomestico >= 0)
				{
					//Pido el usuario confirmacion 's' o 'n' para eliminar y veo is confirma la eliminacion
					do {
						printf("----------------ELIMINAR---------------\n \n");

						if(imprimirElectrodomestico(vPosicionElectrodomestico, listaElectrodomesticos, largoElectrodomesticos, listaMarcas, largoMarcas)==0){
						vRetornoRespuestaEliminar = unt_preguntaRespuestaBinaria("\n Esta seguro que desea eliminarlo?(s/n) ",'s', 'n');
						system("cls");
						}
					} while (vRetornoRespuestaEliminar == -1);

					if (vRetornoRespuestaEliminar == 1) {
						//Si se elimino exitosamente pongo la variable de retorno en 0 (EXITO)
						if (removerElectrodomesticos(listaElectrodomesticos, largoElectrodomesticos, vIdElectrodomestico) == 0
								&& removerReparacionPorSerieElectrod(listaReparacion, largoReparacion, vIdElectrodomestico, listaElectrodomesticos, largoElectrodomesticos)== 0)
						{
							printf("\n Empleado eliminado.\n ");
						}
					} else
					{
						printf("\n No se elimino el electrodomestico.\n ");
					}

				} else
				{
					printf("\n No se ha ingresado ningun empleado de Id %d ",vIdElectrodomestico);
				}

			} else
			{
				printf("\n Ya no tiene reintentos.\n ");
			}

		} else {
			printf("\n No puede eliminar, no hay empleados cagados.\n ");
		}
	}

	return;
}

void altaReparacion(eReparacion* listaReparaciones,int largoReparaciones,int *vContadorIdReparacion, eServicio* listaServicios,int largoServicios,
					eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, eMarca *listaMarca, int largoMarca){

	int vBanderaReintentos = 1;	// (1) se quedo sin reintentos (0) cargo correctamente
	eReparacion reparacionIngresado;// contendra la informacion del alumno que ingresa el usuario


	if (listaReparaciones != NULL && largoReparaciones > 0 && *vContadorIdReparacion >= 0 &&
			listaServicios!= NULL && largoServicios>0 && listaElectrodomesticos!=NULL && largoElectrodomesticos>0 && largoMarca>0 && listaMarca !=NULL)  {

			if (pedirElectrodomesticoPorSerie(reparacionIngresado.serie, " Ingrese la serie del electrodomestico: ",
					" La serie ingresada es invalida ", listaElectrodomesticos , largoElectrodomesticos, REINTENTOS, listaMarca, largoMarca)
					== 0)
			{
				system("cls");
				if (pedirServicioPorID(&reparacionIngresado.id, " Ingrese el ano del modelo: ", " Ingreso un ano invalido",
						listaServicios, largoServicios, REINTENTOS)== 0) {
					system("cls");

					reparacionIngresado.id = *vContadorIdReparacion + 1;
					reparacionIngresado.estaVacio = 0;
					vBanderaReintentos = 0;
					system("cls");
					if(utn_getFecha(&reparacionIngresado.fecha.dia, &reparacionIngresado.fecha.mes, &reparacionIngresado.fecha.anio,
										" Ingrese la fecha de reparacion ", " Ingreso una fecha invalida.", REINTENTOS)){

					if (agregarReparacion(listaReparaciones, largoReparaciones, reparacionIngresado) == 0)
					{
					(*vContadorIdReparacion)++;
						printf("\n Se le ha asignado el legajo: %d \n Alta exitosa.\n ",*vContadorIdReparacion);

					} else {
						printf("\n Hay %d electrodomesticos cargados, no es posible cargar mas.\n No se ha dado el alta.\n ",
							largoReparaciones);
					}
					}
			}
		}

		if (vBanderaReintentos == 1)
		{
			printf("\n No tiene mas reintentos.\n No se ha dado el alta.\n ");
		}
	}



	return;
}
