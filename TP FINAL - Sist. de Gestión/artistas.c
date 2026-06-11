#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artistas.h"

stArtista pedirArtistas (){

    stArtista dato;

    do{

printf ("Ingrese el ID del artista: ");
scanf ("%i", &dato.id);

    if (dato.id < 0){

        printf ("\nError, ingrese ID 'artista' nuevamente");

        }

    }while (dato.id < 0);

getchar();

    do{

printf ("Ingrese el Nombre del artista: ");
fgets(dato.nombre, 50, stdin);
dato.nombre[strcspn(dato.nombre, "\n")] = '\0';

        if (strlen(dato.nombre) == 0){

            printf ("\nError, ingrese NOMBRE nuevamente");

        }


    }while (strlen(dato.nombre) == 0);

    do {

printf ("Ingrese el Genero del artista: ");
fgets(dato.genero, 30, stdin);
dato.genero[strcspn(dato.genero, "\n")] = '\0';

        if (strlen(dato.genero) == 0){

            printf ("\nError, ingrese GENERO nuevamente");

        }


    }while (strlen(dato.genero) == 0);

    return dato;

}

