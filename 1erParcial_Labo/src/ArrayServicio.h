/*
 * ArrayServicio.h
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */

#ifndef ARRAYSERVICIO_H_
#define ARRAYSERVICIO_H_

typedef struct{

	int id;
	char descripcion[26];
	float precio;

}eServicio;

#endif /* ARRAYSERVICIO_H_ */

/**
 *
 * @param lista
 * @param largo
 * @param id
 * @return
 */
int buscarServicio(eServicio* lista,int largo, int id);
/**
 *
 * @param lista
 * @param largo
 * @param posicion
 * @return
 */
int mostrarServicio(eServicio* lista,int largo, int id);
/**
 *
 * @param lista
 * @param largo
 * @return
 */
int mostrarServicios(eServicio* lista,int  largo);
/**
 *
 * @param listadoCarreras
 * @param largoCarrreras
 * @param idCarrera
 * @return
 */
int validarIdServicio(eServicio *listadoServicios, int largoServicios, int idServicio);
/**
 *
 * @param pIdResultado
 * @param listaCarreras
 * @param largoCarreras
 * @param reintentos
 * @return
 */
int pedirServicioPorID(int *pIdResultado, char *mensaje, char *mensajeError ,eServicio *listadoServicios,int largoServicios, int reintentos);
/**
 *
 * @param idCarrera
 * @param listadoCarreras
 * @param largoCarreras
 * @param descCarrera
 * @return
 */
int cargarDescServicio(int idServicio,eServicio* listadoServicios,int largoServicios, char * descServicio);
