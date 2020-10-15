/*
 * ArrayReparacion.h
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */
#include "ArrayServicio.h"
#include "ArrayElectrodomesticos.h"

#ifndef ARRAYREPARACION_H_
#define ARRAYREPARACION_H_

 typedef struct{

	int dia;
	int mes;
	int anio;

} eFecha;


 typedef struct{

	int id;
	char serie[11];
	eFecha fecha;
	int idServicio;
	int estaVacio;

} eReparacion;

#endif /* ARRAYREPARACION_H_ */
/** @brief Para indicar que todas las posiciones en el array estan vacias,
 * 		   esta funcion pone la bandera (isEmty) en verdadero (1) en todas
 *         las posiciones del array.
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Array Largo del array de empleados
 * \return int Retorna (-1) en caso de ERROR [largo invalido o puntero nulo] - (0) en caso de EXITO
 *
 */
int inicializarReparacion(eReparacion* listaReparacion, int largoReparacion);
/** @brief Añade a una lista existente de empleados los valores recividos como parametros
 *		   en la primer posicion vacia.
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @param id int ID del usuario a agregar
 * @param marca[] char marca del usuario a agregar
 * @param apellido[] char apellido del usuario a agregar
 * @param salario float Salario del usuario a agregar
 * @param sector int Sector del usuario a agregar
 * @return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo o sin espacio libre]
 *
 **/
int agregarReparacion(eReparacion *listaReparacion, int largoReparacion, eReparacion reparacionIngresada);
/** @brief Busca un Empleado por Id y devuelve la posicion del indice del Array,
 *
 * @param lista Empleado*  Puntero al array de empleados
 * @param largo Int Largo del array de empleados
 * @param id Int ID del usuario a agregar
 * @return Int Retorna la posicion del indice del Empleado o (-1) si [Largo invalido o puntero
 *  nulo o empleado no encontrado]
 *
 **/
int buscarReparacionPorId(eReparacion* listaReparacion, int largoReparacion,int id);
/** @brief Remueve a un Empleado por Id (pone la bandera isEmpty en 1).
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @param id int ID del usuario a eliminar
 * @return int Retorna (-1) si ERROR [Largo invalido o puntero nulo o
 * si no puede encontrar el empleado]  - (0) en caso de EXITO
 *
 */
int removerReparacion(eReparacion* listaReparacion, int largoReparacion, int id);
/** @brief   Ordena los elementos en el Array de Empleados, el argumento
 * de orden indica orden ascendente u orden descendente
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @param orden int [1] indica ASCENDENTE - [0] indica DESCENDENTE
 * @return int Retorna (-1) en caso de ERROR [Largo invalido o puntero
 * nulo] - (0) en caso de EXITO
 *
 */
//int ordenarElectrodomesticos(eElectrodomesticos* listaElectrodomesticos, int largoElectrodomesticos, int orden);
/** \brief Imprime el contenido del Array de Empleados
 *
 * \param lista Empleado* Puntero al array de empleados
 * \param largo int Largo del array de empleados
 * \return int Retorna (-1) en caso de ERROR [Largo invalido, puntero nulo
 * u orden invalido]
 *
 */
int imprimirReparaciones(eReparacion * listaReparacion, int largoReparacion,eServicio* listaServicios, int largoServicios);
/**
 *
 * @param posicion
 * @param lista
 * @param largo
 * @param listaCarreras
 * @param largoCarreras
 * @return
 */
int imprimirReparacion(int posicion,eReparacion *listaReparacion, int largoReparacion,eServicio* listaServicios, int largoServicios);

/**\brief Retorna el sueldo promedio del Array de Empleados
 *
 * \param lista Empleado* Puntero al array de empleados
 * \param largo int Largo del array de empleados
 * \param promedio * Puntero al espacio de memoria donde se guardara el promedio
 * \return Int Retorna (-1) en caso de Error [Largo invalido o puntero nulo]
 * 		   -(0) en caso de EXITO
 */
int sueldoPromedioReparaciones(eReparacion* listaReparacion, int largoReparacion, float *promedio);
/**@brief Busca si hay algun empelado cargado en el array y devuelve true (1)
 * si lo encuentra y (0)false si no
 *
 * @param lista Empleado* Puntero al array de empleados
 * @param largo int Largo del array de empleados
 * @return Retorna (-1) en caso de Error [Largo invalido o puntero nulo o si no
 * 		   hay empleado cargado] - (0) en caso de encontrar al menos un empeleado
 * 		   cargado.
 *
 */
int hayReparacionCargada(eReparacion *listaReparacion, int largoReparacion);
/**
 *
 * @param lista
 * @param largo
 * @param cantidad
 * @return
 */
int hardcodearReparaciones(eReparacion* listaReparacion ,int largoReparacion , int cantidad);

int removerReparacionPorSerieElectrod(eReparacion* listaReparacion,int largoReparacion,int vIdElectrodomestico, eElectrodomesticos* listaElectrodomestico, int largoElectrodomestico);
