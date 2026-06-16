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

//====================================================================================================================/mostrar/

void mostrarArtistas (stArtista artista[], int validos){

    for (int i = 0; i < validos; i++){

        printf ("\n=========================\n");

        mostrarArtista(artista[i]);

        printf ("\n=========== ESOS SON LOS ARTISTAS ==============\n");

    }

}

void mostrarArtista (stArtista artista){

        printf ("\nID del Artista: %i", artista.id);
        printf ("\nNombre del Artista: %s", artista.nombre);
        printf ("\nGenero del Artista: %s", artista.genero);

}

//==============================================================================================================/ordenar/

void ordenarArtistas (stArtista artista[], int validos){

    stArtista aux;

    for (int i = 0; i < validos - 1; i++){

        for (int j = i + 1; j < validos; j++){

            if (stricmp(artista[i].nombre, artista[j].nombre) > 0){

                aux = artista[i];
                artista[i] = artista[j];
                artista[j] = aux;

            }

        }
    }

}

//==============================================================================================================/buscar/

int buscarXartista (stArtista artista[], int validos, int id){

    for (int i = 0; i < validos; i++){

        if (artista[i].id == id){

            return i;

        }

    }

    return -1;

}

//============================================================================================================/modificar/

void modificarArtista (stArtista artista[], int validos){

        int id;

    printf ("\nIngrese ID del artista que desea modificar: ");
    scanf("%i", &id);

    int pos = buscarXartista(artista, validos, id);

    if(pos == -1){

    printf("\nArtista inexistente");
    return;

    }else{

        printf("\nArtista encontrado.\n");

    getchar();

    do{

    printf("\nIngrese el nuevo nombre: ");
    fgets(artista[pos].nombre, 50, stdin);

    }while(strlen(artista[pos].nombre) == 0);

    artista[pos].nombre[strcspn(artista[pos].nombre, "\n")] = '\0';

    do{

    printf("\nIngrese el nuevo genero: ");
    fgets(artista[pos].genero, 30, stdin);

    }while(strlen(artista[pos].genero) == 0);

    artista[pos].genero[strcspn(artista[pos].genero, "\n")] = '\0';

    printf("\nArtista modificado correctamente.\n");
    }

}


//===============================================================================================================/borrar/
