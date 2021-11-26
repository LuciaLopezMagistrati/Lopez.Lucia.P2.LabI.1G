#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct{
    int id_peli;
    char titulo[30];
    char genero[20];
    float rating;
}eMovie;




/** \brief Solicita espacio en memoria para una nueva pelicula e incializa los valores
 *
 * \param No aplica
 * \return Retorna puntero de tipo eMovie* si obtuvo lugar o NULL en caso contrario
 *
 */
eMovie* movie_new();


/** \brief Solicita espacio en memoria para una nueva pelicula y le asigna los valores que recibe por parametro
 *
 * \param Id a asignar
 * \param Titulo a asignar
 * \param Genero a asignar
 * \param Rating a asignar
 * \return Retorna puntero de tipo Employee* si obtuvo lugar o NULL en caso contrario
 *
 */
eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr);



/**
 * \brief Libera espacio de memoria de una pelicula (free)
 * \param this eMovie* puntero a pelicula
 * \return void
 */
void movie_delete(eMovie* this);


/**
 * \brief Carga el id en el campo
 * \param  puntero a pelicula
 * \param id a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero eMovie* es NULL o si el id no es valido
 *
 */
int movie_setId(eMovie* this,int id);



/**
 * \brief Obtiene el id
 * \param  puntero a pelicula
 * \param  puntero al espacio donde guarda el titulo obtenido
 * \return (1) EXITO - (0) ERROR - Si el puntero a eMovie* es NULL o si e puntero al id es NULL
 *
 */
int movie_getId(eMovie* this,int* id);


/**
 * \brief Carga el titulo de la pelicula
 * \param  puntero a pelicula
 * \param puntero al nombre a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a eMovie* es NULL o si e puntero al nombre es NULL
 *
 */
int movie_setTitulo(eMovie* this,char* titulo);



/**
 * \brief Obtiene el titulo de la pelicula
 * \param  puntero a pelicula
 * \param puntero al titulo a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a eMovie* es NULL o si e puntero al nombre es NULL
 *
 */
int movie_getTitulo(eMovie* this,char* titulo);


/**
 * \brief Carga el genero de la pelicula
 * \param  puntero a pelicula
 * \param puntero al genero a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a eMovie* es NULL o si e puntero al nombre es NULL
 *
 */
int movie_setGenero(eMovie* this,char* genero);


/**
 * \brief Obtiene el genero de la pelicula
 * \param  puntero a pelicula
 * \param puntero al genero a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a eMovie* es NULL o si e puntero al nombre es NULL
 *
 */
int movie_getGenero(eMovie* this,char* genero);

/**
 * \brief Carga el rating de la pelicula
 * \param  puntero a pelicula
 * \param puntero al rating a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a eMovie* es NULL o si e puntero al nombre es NULL
 *
 */
int movie_setRating(eMovie* this,float rating);

/**
 * \brief Obtiene el rating de la pelicula
 * \param  puntero a pelicula
 * \param puntero al rating a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a eMovie* es NULL o si e puntero al nombre es NULL
 *
 */
int movie_getRating(eMovie* this,float* rating);


/** \brief Genera un genero random y lo setea en el elemento
 *
 * \param void* element puntero al elemento
 * \return Retorna puntero al elemento seteado en caso de exito o NULL en caso contrario.
 *
 */
void* generarGenero(void* element);


/** \brief Genera un rating random y lo setea en el elemento
 *
 * \param void* element puntero al elemento
 * \return Retorna puntero al elemento seteado en caso de exito o NULL en caso contrario.
 *
 */
void* generarRating(void* element);

/** \brief Evalua si el elemento es del genero Drama
 *
 * \param void* element puntero al elemento a evaluar
 * \return Retorna 1 si es parte del genero o 0 en caso contrario
 *
 */
int filterGeneroDrama(void* pElement);

/** \brief Evalua si el elemento es del genero Comedia
 *
 * \param void* element puntero al elemento a evaluar
 * \return Retorna 1 si es parte del genero o 0 en caso contrario
 *
 */
int filterGeneroComedia(void* pElement);

/** \brief Evalua si el elemento es del genero Accion
 *
 * \param void* element puntero al elemento a evaluar
 * \return Retorna 1 si es parte del genero o 0 en caso contrario
 *
 */
int filterGeneroAccion(void* pElement);

/** \brief Evalua si el elemento es del genero Terror
 *
 * \param void* element puntero al elemento a evaluar
 * \return Retorna 1 si es parte del genero o 0 en caso contrario
 *
 */
int filterGeneroTerror(void* pElement);


/**
 * \brief Compara dos generos
 * \param void* puntero al primer genero a comparar
 * \param void* puntero al segundo genero a comparar
 * \return int Return
 * 					  (-1) Si el nombre del primer genero es mayor al segundo
 * 					   (1) Si el nombre del primer genero es menor al segundo
 * 					   (0) Si los nombres son iguales
 */
int movie_OrdenarPorGenero(void *generoUno, void *generoDos);



/**
 * \brief Compara los ratings de dos peliculas
 * \param void* puntero al primer rating a comparar
 * \param void* puntero al segundo rating a comparar
 * \return int Return
 * 					  (-1) Si el primer rating es menor al del segundo
 * 					   (1) Si el primer rating es mayor al del segundo
 * 					   (0) Si los nombres son iguales
 */

int movie_OrdenarPorRatig(void *rating_Uno, void *rating_Dos);




#endif // PELICULAS_H_INCLUDED
