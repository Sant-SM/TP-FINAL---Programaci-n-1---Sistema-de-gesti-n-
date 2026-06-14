#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artistas.h"
#include "constantes.h"
#include "utilidades.h"

stArtista pedirArtistas (){

    stArtista dato;

    do{

    printf ("\nIngrese el ID del artista: ");
    dato.id = pedirEntero();

    if (dato.id < 0){

        printf ("\nError, ingrese ID 'artista' nuevamente");

        }

    }while (dato.id < 0);


    do{

    printf ("\nIngrese el Nombre del artista: ");
    fgets(dato.nombre, 50, stdin);
    dato.nombre[strcspn(dato.nombre, "\n")] = '\0';

        if (strlen(dato.nombre) == 0){

            printf ("\nError, ingrese NOMBRE nuevamente");

        }


    }while (strlen(dato.nombre) == 0);

    do {

    printf ("\Ingrese el Genero del artista: ");
    fgets(dato.genero, 30, stdin);
    dato.genero[strcspn(dato.genero, "\n")] = '\0';

        if (strlen(dato.genero) == 0){

            printf ("\nError, ingrese GENERO nuevamente");

        }


    }while (strlen(dato.genero) == 0);

    return dato;

}

void cargarArtista (stArtista artista[], int * validos) {

    stArtista nuevo;

    char s = 's';

    while((s == 's' || s == 'S') && *validos < MAX_ARTISTAS){

        nuevo = pedirArtistas();

        while(existeArtista(artista, *validos, nuevo.id) == 1){

            printf ("\nError, ese artista ya existe, ingrese los datos nuevamente\n");
            nuevo = pedirArtistas();

        }

        artista[*validos] = nuevo;
        (*validos)++;

        printf("\nArtista agregado correctamente.\n");

        printf ("\nDesea continuar la carga? Para SI presione 's' || 'S', para NO, presione otra tecla: ");
        scanf (" %c", &s);

    }
}

int existeArtista (stArtista artista[], int validos, int id){

    for (int i = 0; i < validos; i++){

        if (artista[i].id == id){

            return 1;
        }
    }

    return 0;

}

