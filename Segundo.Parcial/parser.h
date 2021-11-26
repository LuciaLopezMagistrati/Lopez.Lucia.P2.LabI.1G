#include "LinkedList.h"

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED


/** \brief Parsea los datos los datos desde el archivo .csv (modo texto).
 *
 * \param FILE* pFile puntero al archivo a cargar
 * \param LinkedList* lista puntero a la LinkedList
 * \return retorna (0) si hubo error [puntero nulo] - (1) exito.
 *
 */
int parser_PeliculasFromText(FILE* pFile , LinkedList* lista);


/**
 * \brief Parsea los datos  al archivo .csv(modo texto).
 * \param pFile FILE* puntero al archivo a cargar
 * \param LinkedList* lista puntero a la LinkedList
 * \return int Return (1) EXITO (0) ERROR - Si el puntero a LikedList es NULL o la ruta es invalida.
 *
 *
 */
int parser_peliculasToText(FILE* pFile , LinkedList* lista);

#endif // PARSER_H_INCLUDED
