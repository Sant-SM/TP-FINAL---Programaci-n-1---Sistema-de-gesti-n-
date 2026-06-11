#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artistas.h"
#include "escenario.h"
#include "presentacion.h"
#include "tiempo.h"

const int MAX_ARTISTAS = 200;
const int MAX_ESCENARIOS = 100;
const int MAX_PRESENTACIONES = 100;


//======================================================================/LLAMADO DE FUNCIONES/

void cargarArtista(stArtista artista [], int * validos);
int existeArtista (stArtista artista[], int validos, int id);
int existeEscenario (stEscenario escenario[], int validos, int id, char nombre[]);
int existePresentacion (stPresentacion presentacion[], int validos, int id);

///=========================================================================/MAIN/

int main()
{

    stArtista artistas [MAX_ARTISTAS];
    int validos = 0;

    cargarArtista(artistas, &validos);


    return 0;
}


//=========================================================================/FUNCIONES/

//nombre[strcspn(nombre, "\n")] = '\0';                   BORRA SALTO DE LINEA

//====================================================/CARGA ARTISTA/

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


//====================================================/CARGA ESCENARIO/


void cargarEscenario (stEscenario escenario[], int * validos) {

    stEscenario nuevo;

    char s = 's';

    while ((s == 's' || s == 'S') || *validos < MAX_ESCENARIOS){

        nuevo = pedirEscenario();

        while (existeEscenario(escenario, *validos, nuevo.id, nuevo.nombre) == 1){

            printf ("\nError, ese escenario ya existe, ingrese los datos nuevamente\n");
            nuevo = pedirEscenario();

        }

        escenario[*validos] = nuevo;
        (*validos)++;

        printf("\nEscenario agregado correctamente.\n");

        printf ("\nDesea continuar la carga? Para SI presione 's' || 'S', para NO, presione otra tecla: ");
        scanf (" %c", &s);

    }
}

int existeEscenario (stEscenario escenario[], int validos, int id, char nombre[]){

    for (int i = 0; i < validos; i++){

        if (escenario[i].id == id || strcmp(escenario[i].nombre, nombre) == 0){

            return 1;
        }
    }

    return 0;

}


//====================================================/CARGA PRESENTACIONES/         TENER EN CUENTA *SOLAPAMIENTO* (Sobre todo en HORARIO y ESCENARIO)

void cargaPresentaciones (stPresentacion presentacion[], int * validos){

    stPresentacion nuevo;

    char s = 's';

    while ((s == 's' || s == 'S') || *validos < MAX_ESCENARIOS){

        nuevo = pedirPresentacion();

        while (existePresentacion(presentacion, *validos, nuevo.id) == 1){

            printf ("\nError, esa presentacion ya existe, ingrese los datos nuevamente\n");
            nuevo = pedirPresentacion();

        }

        presentacion[*validos] = nuevo;
        (*validos)++;

        printf("\nPresentacion agregado correctamente.\n");

        printf ("\nDesea continuar la carga? Para SI presione 's' || 'S', para NO, presione otra tecla: ");
        scanf (" %c", &s);

    }


}

int existePresentacion (stPresentacion presentacion[], int validos, int id){

    for (int i = 0; i < validos; i++){

        if (presentacion[i].id == id){

            return 1;
        }
    }

    return 0;

}





