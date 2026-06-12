#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artistas.h"
#include "escenario.h"
#include "presentacion.h"
#include "tiempo.h"
#include "constantes.h"
#include "utilidades.h"

stPresentacion pedirPresentacion(stArtista artista[], int validosARTS, stEscenario escenario[], int validosESC){

    stPresentacion dato;

    do{

    printf ("Ingrese ID de la presentacion: ");
    dato.id = pedirEntero();

    if (dato.id < 0){

        printf ("\nError, ingrese ID 'presentacion' nuevamente");

    }

    }while (dato.id < 0);

    //=======================================================================/ARTISTAS/

    do{

        printf ("\nIngrese ID del ARTISTA de la presentacion: ");
        dato.idArtista = pedirEntero();

    if (dato.idArtista < 0){

        printf ("\nError, ingrese ID 'artista' nuevamente");

    }

    if (existeArtista(artista, validosARTS, dato.idArtista) == 1){

            printf ("\nArtista encontrado");

        }else if (existeArtista(artista, validosARTS, dato.idArtista) == 0){

            printf ("\nError, artista inexistente");

        }

    }while (dato.idArtista < 0 || existeArtista(artista, validosARTS, dato.idArtista) == 0);

    //=======================================================================/ESCENARIOS/

    do{

    printf ("\nIngrese ID del ESCENARIO de la presentacion: ");
    dato.idEscenario = pedirEntero();

    if (dato.idEscenario < 0){

        printf ("\nError, ingrese ID 'escenario' nuevamente");

    }

    if (existeEscenarioID(escenario, validosESC, dato.idEscenario) == 1){                   ///EL MENSAJE ESTA AL REVEZ, WTF???

            printf ("\nEscenario encontrado");

        }else if (existeEscenarioID(escenario, validosESC, dato.idEscenario) == 0){

            printf ("\nError, escenario inexistente");

        }

    }while (dato.idEscenario < 0 || existeEscenarioID(escenario, validosESC, dato.idEscenario));


    //=======================================================================/CARGA DE HORARIOS/

    do{

    dato.horaInicio = pedirHorario();

    }while(dato.horaInicio.esValido == 0);

    do{

    dato.duracion = pedirDuracion();

    }while(dato.duracion.esValido == 0);

    return dato;

}


//====================================================/CARGA PRESENTACIONES/         TENER EN CUENTA *SOLAPAMIENTO* (Sobre todo en HORARIO y ESCENARIO)

void cargaPresentaciones (stPresentacion presentacion[], int * validosPRES, stArtista artista[], int validosARTS, stEscenario escenario[], int validosESC){

    stPresentacion nuevo;

    char s = 's';

    while ((s == 's' || s == 'S') && *validosPRES < MAX_PRESENTACIONES){

        nuevo = pedirPresentacion(artista, validosARTS, escenario, validosESC);

        while (existePresentacion(presentacion, *validosPRES, nuevo.id) == 1){

            printf ("\nError, esa presentacion ya existe, ingrese los datos nuevamente\n");
            nuevo = pedirPresentacion(artista, validosARTS, escenario, validosESC);

        }

        presentacion[*validosPRES] = nuevo;
        (*validosPRES)++;

            printf("\nPresentacion agregada correctamente.\n");

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


