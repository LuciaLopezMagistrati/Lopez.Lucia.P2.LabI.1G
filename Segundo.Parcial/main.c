#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "inputs.h"
#include "controller.h"


#define QTY_RETRIES 3

int main()
{
    srand(time(NULL));
    int opcion;

    LinkedList* listPeliculas = ll_newLinkedList();
    LinkedList* newList = ll_newLinkedList();

    do
    {

        if(!utn_getNumeroEntero(&opcion,"\nMenu de acciones\n\n"
                                " 1. Cargar archivo\n"
                                " 2. Imprimir lista\n"
                                " 3. Asignar rating\n"
                                " 4. Asignar genero\n"
                                " 5. Filtrar por genero\n"
                                " 6. Ordenar peliculas\n"
                                " 7. Guardar peliculas\n"
                                " 8. Salir\n\n"
                                "Seleccione una opcion: ",
                                "\nError opcion invalida. Seleccione una opcion del ",1,8,QTY_RETRIES))

        switch(opcion)
            {
                case 1: // Cargar archivo
                    if(controller_loadPeliculasFromText(listPeliculas))
                        {
                            printf("\nCarga de datos desde archivo .csv exitosa\n");
                        }
                    else
                        {
                            printf("\nError en la carga de datos desde archivo .csv\n");
                        }
                    break;

                case 2: // Imprimir lista
                    if(ll_isEmpty(listPeliculas)==0)
                        {
                            controller_ListMovies(listPeliculas);
                        }
					else
                        {
                            printf("\nPara listar se requiere que exista al menos una pelicula cargada.\n");
                        }
                    break;

                case 3: // asignar rating
                    if(ll_isEmpty(listPeliculas)==0)
                        {
                            listPeliculas = ll_map(listPeliculas, generarRating);
                            controller_ListMovies(listPeliculas);
                        }
                    else
                        {
                            printf("\nPara asignar rating se requiere que exista al menos una pelicula cargada.\n");
                        }
                    break;

                case 4: //Asignar genero
                     if(ll_isEmpty(listPeliculas)==0)
                        {
                            listPeliculas = ll_map(listPeliculas, generarGenero);
                            controller_ListMovies(listPeliculas);
                        }
                    else
                        {
                            printf("\nPara asignar rating se requiere que exista al menos una pelicula cargada.\n");
                        }
                    break;


                case 5:  //Filtrar por genero
                    if(!ll_isEmpty(listPeliculas))
                    {
                        if(controller_listarPorGenero(listPeliculas))
                        {
                           printf("\nLista filtrada con exito.\n");
                        }else
                        {
                           printf("\n Error en el filtrado.\n");
                        }
                    }
                    else
                    {
                        printf("\nPara filtrar se requiere que exista al menos una pelicula.\n");
                    }
                    break;

                case 6: //Ordenar peliculas
                    if(!ll_isEmpty(listPeliculas))
                    {
                        if(!ll_dobleSort(listPeliculas, movie_OrdenarPorGenero, movie_OrdenarPorRatig, 0))
                            {
                                 controller_ListMovies(listPeliculas);
                            }
                    }
                    else
                    {
                        printf("\nPara ordenar se requiere que existan peliculas.\n");
                    }

                    break;

                case 7: // Guardar peliculas
                    if(!ll_isEmpty(listPeliculas))
                    {
                        if (controller_savePeliculasToTxt(listPeliculas))
                        {
                            printf("Archivo guardado con exito.\n");
                        } else
                        {
                             printf("Error al guardar peliculas.\n");
                        }
                    }
                    else
                    {
                        printf("\nPara guardar peliculas se requiere que exista al menos una peliculas.\n");
                    }
                    break;

                case 8: // Salir
					 ll_deleteLinkedList(listPeliculas);
					 ll_deleteLinkedList(newList);
					 //ll_clear(newList1);
					 //ll_deleteLinkedList(newList1);

                     break;
            }
    }
    while(opcion != 8);




    return 0;
}
