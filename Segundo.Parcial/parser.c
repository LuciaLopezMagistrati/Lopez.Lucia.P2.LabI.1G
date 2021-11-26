#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "peliculas.h"


int parser_PeliculasFromText(FILE* pFile , LinkedList* lista)
{
	eMovie* pMovie;

	char auxID[2];
	char auxTitulo[30];
	char auxGenero[20];
	char auxRating[4];

	int retorno = 0;


	if (pFile != NULL && lista != NULL)
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxTitulo, auxGenero,auxRating); // lectura cabecera

            do
            {
                fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxID, auxTitulo, auxGenero,auxRating);
                pMovie = movie_newParametros(auxID, auxTitulo, auxGenero,auxRating);

                if (pMovie != NULL)
                    {
                        ll_add(lista, pMovie);
                        retorno = 1;
                    }
            }while(!feof(pFile));
        }

    return retorno;
}



int parser_peliculasToText(FILE* pFile , LinkedList* lista)
{
    int retorno = 0;
	eMovie* pMovie;
    char titulo[30];
    char genero[20];
    int ID;
    float rating;
	int len;

	if (pFile != NULL && lista != NULL)
	{
		len = ll_len(lista);
		fprintf(pFile, "ID,TITULO,GENERO,RATING\n");

		for (int i = 0; i < len; i++)
		{
			pMovie = ll_get(lista, i);
			if (pMovie != NULL &&
                movie_getId(pMovie, &ID) &&
				movie_getTitulo(pMovie, titulo) &&
				movie_getGenero(pMovie, genero) &&
				movie_getRating(pMovie, &rating))
                {
                    fprintf(pFile, "%d,%s,%s,%.1f\n", ID, titulo, genero, rating);
                }
		}
		retorno = 1;
	}
 return retorno;

}

