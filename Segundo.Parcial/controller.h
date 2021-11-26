#include "LinkedList.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED


/**
 * \brief Carga los datos de las peliculas desde un archivo (modo texto).
 * \param  LinkedList* lista
 * \return int Return (0) ERROR - Si el puntero a LikedList es NULL o la ruta es invalida, (1) EXITO
 *
 */
int controller_loadPeliculasFromText(LinkedList* lista);

/** \brief Listar peliculas
 *
 * \param LinkedList* lista
 * \return int (0) error - (1) exito
 *
 */
int controller_ListMovies(LinkedList* lista);

/** \brief Genera una nueva Linkedlist con los elementos que corresponden al genero seleccionado
 *
 * \param LinkedList* lista
 * \return int (0) error - (1) exito
 *
 */
int controller_listarPorGenero(LinkedList* lista);

/**
 * \brief Guarda los datos de las peliculas en un archivo (modo texto).
 * \param LinkedList* lista
 * \return int Return (1) EXITO - (0) ERROR
 *
 */
int controller_savePeliculasToTxt(LinkedList* lista);


/** \brief Guarda los datos de las peliculas en un archivo (modo texto)
 *
 * \param path
 * \param LinkedList* lista
 * \return int Return (1) EXITO - (0) ERROR
 *
 */

int controller_saveAsText(char* path , LinkedList* lista);


#endif // CONTROLLER_H_INCLUDED
