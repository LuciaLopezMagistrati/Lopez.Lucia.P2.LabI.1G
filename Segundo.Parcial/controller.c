#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "controller.h"
#include "LinkedList.h"
#include "inputs.h"
#include "parser.h"
#include "peliculas.h"



int controller_loadPeliculasFromText(LinkedList* lista)
{
    int retorno = 0;
    char confirmacionString[2];
    char confirmacionChar;
    char path[20];
    char extension []= ".csv";
    FILE* f = NULL;
    int len;

    utn_getDescripcion(path,20, "\nIngrese el path (la extension .csv se agrega automaticamente): \n","Error. Path invalido.\n",3);
    strcat(path,extension);

    f = fopen(path, "r");

    if( f == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }
    else
    {
        len = ll_len(lista) > 0;

        if(len >0)
        {
            utn_getChar(confirmacionString,2,
                        "\nYa hay datos cargados en el listado, si procede los datos seran eliminados. Confirma [S-N]: ",
                        "\nError, ingrese S para confirmar, N para cancelar.", 3);

            confirmacionChar = confirmacionString[0];
            confirmacionChar = toupper(confirmacionChar);
        }
    }

    if(f != NULL && (confirmacionChar == 'S' ||  ll_len(lista) == 0))
    {
        ll_clear(lista);
        parser_PeliculasFromText(f, lista);
        fclose(f);
        retorno = 1;

    }

    return retorno;
}


int controller_ListMovies(LinkedList* lista)
{

    int retorno = 0;
    int len;
    eMovie* pMovie;
    int id;
    char nombre[30];
    char genero[20];
    float rating;


    if(lista == NULL || ll_isEmpty(lista))
    {
        printf("\nNo hay peliculas para listar.\n");
    }
    else
    {
        len = ll_len(lista);
        printf("\n\n           ***Listado de peliculas***       \n\n");
        printf(" ID    Titulo                           Genero                  Rating\n");


        for(int i=0; i<len; i++)
        {
            pMovie = ll_get(lista, i);
            movie_getId(pMovie, &id);
            movie_getTitulo(pMovie, nombre);
            movie_getGenero(pMovie, genero);
            movie_getRating(pMovie, &rating);
            printf(" %-5d %-30s %-20s      %.1f\n", id, nombre, genero,rating);
        }

        printf("\n\n");
        retorno = 1;
    }

    return retorno;
}


int controller_listarPorGenero(LinkedList* lista)
{
    int retorno = 0;
    int opcion;

    utn_getNumeroEntero(&opcion, "Menu de generos de peliculas:\n"
                         " 1. Drama\n"
                         " 2. Comedia\n"
                         " 3. Accion\n"
                         " 4. Terror\n\n"
                         "Seleccione el genero de pelicula por el que filtrar: ",
                         "\nError opcion invalida. Seleccione una opcion del ",1,4,3);

    switch(opcion)
    {

        LinkedList* listaFiltrada = ll_newLinkedList();
        listaFiltrada = NULL;

        case 1:
            listaFiltrada = ll_filter(lista, filterGeneroDrama);
            if(listaFiltrada != NULL)
                {
                    //controller_ListMovies(listaFiltrada);
                    controller_saveAsText("DRAMA.csv" , listaFiltrada);
                    ll_deleteLinkedList(listaFiltrada);
                    retorno = 1;
                }
            break;
        case 2:
            listaFiltrada = ll_filter(lista, filterGeneroComedia);
            if(listaFiltrada != NULL)
                {
                    //controller_ListMovies(listaFiltrada);
                    controller_saveAsText("COMEDIA.csv" , listaFiltrada);
                    ll_deleteLinkedList(listaFiltrada);
                    retorno = 1;
                }
            break;
        case 3:
            listaFiltrada = ll_filter(lista, filterGeneroAccion);
            if(listaFiltrada != NULL)
                {
                    //controller_ListMovies(listaFiltrada);
                    controller_saveAsText("ACCION.csv" , listaFiltrada);
                    ll_deleteLinkedList(listaFiltrada);
                    retorno = 1;
                }
            break;
        case 4:
            listaFiltrada = ll_filter(lista, filterGeneroTerror);
            if(listaFiltrada != NULL)
                {
                    //controller_ListMovies(listaFiltrada);
                    controller_saveAsText("TERROR.csv" , listaFiltrada);
                    ll_deleteLinkedList(listaFiltrada);
                    retorno = 1;
                }
            break;
    }




    return retorno;
}

int controller_savePeliculasToTxt(LinkedList* lista)
{
    int retorno = 0;
    char confirmacionString[2];
    char confirmacionChar;
    char path[20];
    char extension []= ".csv";
    FILE* f = NULL;

    utn_getDescripcion(path,20, "\nIngrese el path (la extension .csv se agrega automaticamente): \n","Error. Path invalido.\n",3);
    strcat(path,extension);

    f = fopen(path, "r");

    if( f != NULL)
        {
            utn_getChar(confirmacionString,2,
                        "\nYa exite ese path, si procede los datos seran eliminados. Confirma [S-N]: ",
                        "\nError, ingrese S para confirmar, N para cancelar.", 3);

            confirmacionChar = confirmacionString[0];
            confirmacionChar = toupper(confirmacionChar);
        }

    if( confirmacionChar == 'S' || f == NULL)
        {
            f = fopen(path, "w");

            if (f != NULL)
            {
                parser_peliculasToText(f, lista);
                fclose(f);
                retorno = 1;
            }
        }

    return retorno;


}



int controller_saveAsText(char* path , LinkedList* lista)
{
	int retorno = 0;
	FILE *pFile;

	if (path != NULL && lista != NULL)
	{
		pFile = fopen(path, "w");

		if (pFile != NULL)
		{
			parser_peliculasToText(pFile, lista);
			fclose(pFile);
			retorno = 1;
		}
	}
	return retorno;
}

