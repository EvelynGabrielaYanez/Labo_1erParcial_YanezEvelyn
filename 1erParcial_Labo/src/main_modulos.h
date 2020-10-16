/*
 * TP2_modulos.h
 *
 *
 *      Author: Yañez Evelyn Gabriela
 */

#ifndef TP2_MODULOS_H_
#define TP2_MODULOS_H_



#endif /* TP2_MODULOS_H_ */
/**@brief  Muestra el menu de opciones y pide al usuario el ingreso de una de ellas y
 * 		   la retorna luego de validarla
 *
 * @return Int. Opcion seleccionada por el usuario
 */
int menu();
/**@brief Pide al usuario el ingreso del nombre, apellido, sector y sueldo calculando
 * 		  el id correspondiente y da de alta en caso de ser posible, caso contrio comunica que
 * 		  no se pudo y explica el motivo(cantidad maxima de cargas alcanzada, reintentos de ingreso
 * 		  de informacion requerida agotados )
 *
 * @param lista  Empleado Array. Puntero al espacio de memoria donde se copia el empleado obtenido.
 * @param largo Int. Cantidad de elementos que tiene el array
 * @param contadorId Int. Id que se autoasginara
 */
void altasElectrodomestico(eElectrodomesticos *listaElectrodomesticos, int largoElectrodomesticos, int *pcontadorIdElect,
		eMarca* listaMarcas, int largoMarcas) ;
void modificarElectrodomestico(eElectrodomesticos *lista, int largoElectrodomesticos,eMarca* listaMarcas, int largoMarca);
void bajaElectrodomesticos(eElectrodomesticos *listaElectrodomesticos,
				int largoElectrodomesticos, eMarca * listaMarcas, int largoMarcas, eReparacion * listaReparacion, int largoReparacion);


void altaReparacion(eReparacion* listaReparaciones,int largoReparaciones,int *vContadorIdReparacion, eServicio* listaServicios,int largoServicios,
					eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos,  eMarca *listaMarca, int largoMarca);

void listarElectrodomesticos(eElectrodomesticos* listaElectrodomesticos,int largoElectrodomesticos,eMarca *listaMarcas,int largoMarcas);
void listarMarcas(eMarca* listaMarcas, int largoMarcas, eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos);
void listarServicios(eServicio* listaServicios, int largoServicios, eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos);
void listarReparaciones(eReparacion* listaReparaciones,int largoReparaciones,eServicio* listaServicios, int largoServicios
		,eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos);
