#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"


eMovie* movie_new()
{
    eMovie* movie_new;
    movie_new = (eMovie*) malloc(sizeof(eMovie));

    if (movie_new != NULL)
        {
            movie_new->id_peli = 0;
            strcpy(movie_new->titulo, "nn");
            strcpy(movie_new->genero, "nn");
            movie_new->rating = 0;
        }

    return movie_new;
}


eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr)
{
	eMovie* pMovie_new;

	int auxID;
	float auxRating;


	if (idStr != NULL && tituloStr != NULL && generoStr != NULL && ratingStr != NULL)
	{
		pMovie_new = movie_new();
        auxID = atoi(idStr);
        auxRating = atof(ratingStr);

		if ((pMovie_new != NULL) &&
           (!(movie_setId(pMovie_new,auxID) &&
            movie_setTitulo(pMovie_new,tituloStr) &&
			movie_setGenero(pMovie_new,generoStr) &&
			movie_setRating(pMovie_new,auxRating))))
		{
            movie_delete(pMovie_new);
            pMovie_new = NULL;
		}
	}
	return pMovie_new;
}


void movie_delete(eMovie* this)
{
    if(this != NULL)
        {
            free(this);
        }
}



int movie_setId(eMovie* this,int id)
{
    int retorno = 0;

    if( this != NULL && id >0)
        {
            this->id_peli= id;
            retorno = 1;
        }

    return retorno;
}

int movie_getId(eMovie* this,int* id)
{
    int retorno = 0;

    if( this != NULL && id !=NULL)
        {
            *id = this->id_peli;
            retorno = 1;
        }

    return retorno;
}

int movie_setTitulo(eMovie* this,char* titulo)
{
    int retorno = 0;

	if (this != NULL && titulo != NULL)
        {
            strupr(titulo);
            strcpy(this->titulo, titulo);
            retorno = 1;
        }

	return retorno;
}

int movie_getTitulo(eMovie* this,char* titulo)
{
    int retorno = 0;

	if (this != NULL && titulo != NULL)
        {
            strcpy(titulo, this->titulo);
            retorno = 1;
        }

	return retorno;
}

int movie_setGenero(eMovie* this,char* genero)
{
    int retorno = 0;

	if (this != NULL && genero != NULL)
        {
            strlwr(genero);
            genero[0] = toupper(genero[0]);
            strcpy(this->genero, genero);
            retorno = 1;
        }

	return retorno;
}

int movie_getGenero(eMovie* this,char* genero)
{
    int retorno = 0;

	if (this != NULL && genero != NULL)
        {
            strcpy(genero, this->genero);
            retorno = 1;
        }

	return retorno;
}


int movie_setRating(eMovie* this,float rating)
{
    int retorno = 0;

    if( this != NULL && rating >= 0)
        {
            this->rating = rating;
            retorno = 1;
        }

    return retorno;
}


int movie_getRating(eMovie* this,float* rating)
{
    int retorno = 0;

    if( this != NULL && rating != NULL)
        {
            *rating = this->rating;
            retorno = 1;
        }

    return retorno;
}


void* generarGenero(void* element)
{
    eMovie* aux = NULL;
    int numero;
    char genero[10];
    int max = 40;
    int min = 10;
    //srand(time(NULL));

    if(element != NULL)
    {
            numero = (rand() % (max - min + 1) + min)/10;
            aux = (eMovie*) element;
            switch(numero)
            {
                case 1:
                  strcpy(genero, "drama");
                  break;

                case 2:
                  strcpy(genero, "comedia");
                  break;

                case 3:
                  strcpy(genero, "accion");
                  break;

                case 4:
                  strcpy(genero, "terror");
                  break;
            }

            movie_setGenero(aux, genero);

    }

    return aux;
}



void* generarRating(void* element)
{
    eMovie* aux = NULL;
    float numero;
    int max = 100;
    int min = 10;
    //srand(time(NULL));

    if(element != NULL)
    {
            numero = (float)(rand() % (max - min + 1) + min)/10;
            aux = (eMovie*) element;
            movie_setRating(aux, numero);

    }

    return aux;
}


int filterGeneroDrama(void* pElement)
{
    int retorno = 0;

    if(pElement != NULL)
    {
        if(strcmp(((eMovie*) pElement)->genero,"Drama")==0)
            {
                retorno = 1;
            }
    }

    return retorno;
}


int filterGeneroComedia(void* pElement)
{
    int retorno = 0;

    if(pElement != NULL)
    {
        if(strcmp(((eMovie*) pElement)->genero,"Comedia")==0)
            {
                retorno = 1;
            }
    }

    return retorno;
}

int filterGeneroAccion(void* pElement)
{
    int retorno = 0;

    if(pElement != NULL)
    {
        if(strcmp(((eMovie*) pElement)->genero,"Accion")==0)
            {
                retorno = 1;
            }
    }

    return retorno;
}

int filterGeneroTerror(void* pElement)
{
    int retorno = 0;

    if(pElement != NULL)
    {
        if(strcmp(((eMovie*) pElement)->genero,"Terror")==0)
            {
                retorno = 1;
            }
    }

    return retorno;
}


int movie_OrdenarPorGenero(void *generoUno, void *generoDos)
{

    char genero1[20];
    char genero2[20];
    int retorno = 0;

    movie_getGenero(generoUno, genero1);
    movie_getGenero(generoDos, genero2);

    if (strcmp(genero1, genero2) > 0)
        {
            retorno = 1;
        }
    else if (strcmp(genero1, genero2) < 0)
        {
            retorno = -1;
        }

    return retorno;
}


int movie_OrdenarPorRatig(void *rating_Uno, void *rating_Dos)
{
    float rating1;
    float rating2;
    int retorno = 0;

    movie_getRating(rating_Uno, &rating1);
    movie_getRating(rating_Dos, &rating2);

    if (rating1 < rating2)
        {
            retorno = 1;
        }
    else if(rating1 > rating2)
        {
            retorno = -1;
        }

    return retorno;
}
