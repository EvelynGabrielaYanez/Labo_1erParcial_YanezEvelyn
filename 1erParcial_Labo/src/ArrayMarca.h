/*
 * ArrayMarca.h
 *
 *  Created on: 15 oct. 2020
 *      Author: CLEM
 */

#ifndef ARRAYMARCA_H_
#define ARRAYMARCA_H_

typedef struct{

	int id;
	char descripcion[21];

}eMarca;


#endif /* ARRAYMARCA_H_ */

/**
 *
 * @param lista
 * @param largo
 * @param id
 * @return
 */
int buscarMarca(eMarca* lista,int largo, int id);
/**
 *
 * @param lista
 * @param largo
 * @param posicion
 * @return
 */
int mostrarMarca(eMarca* lista,int largo, int id);
/**
 *
 * @param lista
 * @param largo
 * @return
 */
int mostrarMarcas(eMarca* lista,int  largo);
/**
 *
 * @param listadoCarreras
 * @param largoCarrreras
 * @param idCarrera
 * @return
 */
int validarIdMarca(eMarca *listadoMarcas, int largoMarcas, int idMarca);
/**
 *
 * @param pIdResultado
 * @param listaCarreras
 * @param largoCarreras
 * @param reintentos
 * @return
 */
int pedirMarcaPorID(int *pIdResultado, char *mensaje, char *mensajeError ,eMarca *listaMarcas,int largoMarcas, int reintentos);
/**
 *
 * @param idCarrera
 * @param listadoCarreras
 * @param largoCarreras
 * @param descCarrera
 * @return
 */
int cargarDescMarca(int idMarca,eMarca* listadoMarcas,int largoMarcas, char * descMarca);
