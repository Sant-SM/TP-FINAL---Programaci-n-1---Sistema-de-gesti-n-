#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artistas.h"
#include "escenario.h"
#include "presentacion.h"
#include "tiempo.h"
#include "constantes.h"
#include "utilidades.h"
#include "pila.h"

stPresentacion pedirPresentacion(stArtista artista[], int validosARTS, stEscenario escenario[], int validosESC){

    stPresentacion dato;

    do{

    printf ("\nIngrese ID de la presentacion: ");
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

    if (existeEscenarioID(escenario, validosESC, dato.idEscenario) == 1){

            printf ("\nEscenario encontrado\n");

        }else if (existeEscenarioID(escenario, validosESC, dato.idEscenario) == 0){

            printf ("\nError, escenario inexistente");

        }

    }while (dato.idEscenario < 0 || existeEscenarioID(escenario, validosESC, dato.idEscenario) == 0);


    //=======================================================================/CARGA DE HORARIOS/

    dato.horaInicio = pedirHorario();

    dato.duracion = pedirDuracion();

    return dato;

}


//====================================================/CARGA PRESENTACIONES/ **nota: TENER EN CUENTA *SOLAPAMIENTO* (Sobre todo en HORARIO y ESCENARIO)

void cargaPresentaciones (stPresentacion presentacion[], int * validosPRES, stArtista artista[], int validosARTS, stEscenario escenario[], int validosESC){

    stPresentacion nuevo;

    char s = 's';

    while ((s == 's' || s == 'S') && *validosPRES < MAX_PRESENTACIONES){

        nuevo = pedirPresentacion(artista, validosARTS, escenario, validosESC);

        while (existePresentacion(presentacion, *validosPRES, nuevo.id) == 1 || existeSolapamientoPRES(presentacion, *validosPRES, nuevo) == 1){

            printf ("\nIngrese de nuevo la presentacion\n");
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


int existeSolapamientoPRES(stPresentacion presentaciones[], int validos, stPresentacion nueva){

    stHorario finNUEVA = calcularFin(nueva.horaInicio, nueva.duracion);

    for (int i = 0; i < validos; i++){

        stHorario finACTUAL = calcularFin(presentaciones[i].horaInicio, presentaciones[i].duracion);

        if (presentaciones[i].idArtista == nueva.idArtista){

            if (haySolapamiento(presentaciones[i].horaInicio, finACTUAL, nueva.horaInicio, finNUEVA) == 1){

                printf ("\nHay solapamiento entre Artistas\n");
                return 1;

            }

        }

        if (presentaciones[i].idEscenario == nueva.idEscenario){

            if (haySolapamiento(presentaciones[i].horaInicio, finACTUAL, nueva.horaInicio, finNUEVA) == 1){

                printf ("\nHay solapamiento entre Escenarios\n");
                return 1;

            }

        }

    }

    return 0;

}

//====================================================================================================================/mostrar/

void mostrarPresentaciones (stPresentacion precentacion[], int validos){

    for (int i = 0; i < validos; i++){

        printf ("\n=========================\n");

        mostrarPresentacion(precentacion[i]);

        printf ("\n============ ESAS SON LAS PRESENTACIONES =============\n");

    }

}

void mostrarPresentacion (stPresentacion precentacion){

        stHorario fin = calcularFin(precentacion.horaInicio, precentacion.duracion);;

        printf ("\nID del Escenario: %i", precentacion.id);
        printf ("\nID del Artista de la presentacion: %i", precentacion.idArtista);
        printf ("\nID del Escenario de la presentacion: %i", precentacion.idEscenario);
        printf ("\nHorario de Inicio de la presentacion: %i:%i", precentacion.horaInicio.horas, precentacion.horaInicio.minutos);
        printf ("\nDuracion de la presentacion: %i:%i", precentacion.duracion.horas, precentacion.duracion.minutos);
        printf ("\nHorario de Finalizacion de la presentacion: %i:%i", fin.horas, fin.minutos);
}

//===============================================================================================================/ordenar/

void ordenarPresentacionXhorario (stPresentacion presentacion[], int validos){

        stPresentacion aux;

    for(int i = 0; i < validos - 1; i++){

        for(int j = i + 1; j < validos; j++){

            if (horarioAMinutos(presentacion[i].horaInicio) > horarioAMinutos(presentacion[j].horaInicio)){

                aux = presentacion[i];
                presentacion[i] = presentacion[j];
                presentacion[j] = aux;

            }
        }
    }
}
//===============================================================================================================/mostrar FILTRADO/

void mostrarPresentacionXartista (stPresentacion presentacion[], int validos, int id){

    int flag = 0;

    for (int i = 0; i < validos; i++){

        if (presentacion[i].idArtista == id){

            mostrarPresentacion(presentacion[i]);
            flag = 1;

        }

    }

    if (flag == 0){

            printf ("\nEl artista no posee presentaciones cargadas en el sistema");

    }
}

void filtrarPresentacionXartista(stPresentacion presentacion[], int validosP, stArtista artista[], int validosA){

        int id;

    printf ("\nIngrese el ID del artista que desea encontrar: ");
    id = pedirEntero();

        if (existeArtista(artista, validosA, id) == 0){

            printf ("\nError, el artista no existe");
            return;

        }

    printf("\n===== PRESENTACIONES DEL ARTISTA =====\n");

    mostrarPresentacionXartista(presentacion, validosP, id);

}

int contarPresentacionesXartista(stPresentacion presentacion[], int validosP, int id){ ///FUNCION ESPECIFICA PARA BORRAR

        int cant = 0;

        for (int i = 0; i < validosP; i++){

            if (presentacion[i].idArtista == id){

                cant++;

            }
    }

    return cant;

}

int contarPresentacionesXescenario(stPresentacion presentacion[], int validosP, int id){ ///FUNCION ESPECIFICA PARA BORRAR

        int cant = 0;

        for (int i = 0; i < validosP; i++){

            if (presentacion[i].idEscenario == id){

                cant++;

            }
    }

    return cant;

}

void mostrarPresentacionXescenario (stPresentacion presentacion[], int validos, int id){

    int flag = 0;

    for (int i = 0; i < validos; i++){

        if (presentacion[i].idEscenario == id){

            printf ("\n=========================\n");

            mostrarPresentacion(presentacion[i]);
            flag = 1;

            printf ("\n=========== ESAS SON LAS PRESENTACIONES ==============\n");

        }

    }

    if (flag == 0){

            printf ("\nEl escenario no posee presentaciones cargadas en el sistema");

    }
}

void filtrarPresentacionXescenario(stPresentacion presentacion[], int validosP, stEscenario escenario[], int validosE){

        int id;

    printf ("\nIngrese el ID del escenario que desea encontrar: ");
    id = pedirEntero();

        if (existeEscenarioID(escenario, validosE, id) == 0){

            printf ("\nError, el escenario no existe");
            return;

        }

    printf("\n===== PRESENTACIONES DEL ESCENARIO =====\n");

    mostrarPresentacionXescenario(presentacion, validosP, id);

}

//==============================================================================================================/buscar/

int buscarXpresentacion (stPresentacion presentacion[], int validos, int id){

    for (int i = 0; i < validos; i++){

        if (presentacion[i].id == id){

            return i;

        }

    }

    return -1;

}

//============================================================================================================/modificar/

void modificarPresentacion (stPresentacion presentacion[], int validosP, stEscenario escenario[], int validosE, stArtista artista[], int validosA){

        int id;
        int auxIDartista;
        int auxIDescenario;

    printf ("\nIngrese ID de la presentacion que desea modificar: ");
    scanf("%i", &id);

    int pos = buscarXpresentacion(presentacion, validosP, id);

    if(pos == -1){

        printf("\nPresentacion inexistente");
        return;

    }

        printf("\nPresentacion encontrado.\n");

        stPresentacion aux = presentacion[pos];

        do{

        printf("\nIngrese el nuevo ID del artista: ");
        scanf ("%i", &auxIDartista);

            if (existeArtista(artista, validosA, auxIDartista) == 1){

                aux.idArtista = auxIDartista;

        }else{

        printf("\nError, artista inexistente");

        }
            }while (existeArtista(artista, validosA, auxIDartista) == 0);


        do{

    printf("\nIngrese el nuevo ID del escenario: ");
    scanf ("%i", &auxIDescenario);

    if (existeEscenarioID(escenario, validosE, auxIDescenario) == 1){

        aux.idEscenario = auxIDescenario;

    }else{

    printf("\nError, escenario inexistente");

    }
        }while (existeEscenarioID(escenario, validosE, auxIDescenario) == 0);

    printf("\nIngrese el nuevo horario de inicio: ");
    aux.horaInicio = pedirHorario();

    printf("\nIngrese la nueva duracion: ");
    aux.duracion = pedirDuracion();

    if (existeSolapamientoPRES_Modificar(presentacion, validosP, aux, pos) == 0){

        presentacion[pos] = aux;
        printf("\nPresentacion modificada correctamente.\n");

        }else{

    printf("\nError, la modificacion genera solapamiento.\n");

    }
}

//=========================================================//

int existeSolapamientoPRES_Modificar (stPresentacion presentaciones[], int validos, stPresentacion nueva, int pos){

    stHorario finNUEVA = calcularFin(nueva.horaInicio, nueva.duracion);

    for (int i = 0; i < validos; i++){

        if (pos != i){

        stHorario finACTUAL = calcularFin(presentaciones[i].horaInicio, presentaciones[i].duracion);

        if (presentaciones[i].idArtista == nueva.idArtista){

            if (haySolapamiento(presentaciones[i].horaInicio, finACTUAL, nueva.horaInicio, finNUEVA) == 1){

                printf ("\nHay solapamiento entre Artistas\n");
                return 1;

            }

        }

        if (presentaciones[i].idEscenario == nueva.idEscenario){

            if (haySolapamiento(presentaciones[i].horaInicio, finACTUAL, nueva.horaInicio, finNUEVA) == 1){

                printf ("\nHay solapamiento entre Escenarios\n");
                return 1;

            }

        }
    }
}

    return 0;

}

//===============================================================================================================/borrar/

int borrarPresentacionXartista (stPresentacion presentaciones[], int validosP, int idArt){

    int i = 0;

    while(i < validosP){

        if(presentaciones[i].idArtista == idArt){

            for(int j = i; j < validosP - 1; j++){

                presentaciones[j] = presentaciones[j + 1];
            }

            validosP--;

        }else{

            i++;
        }
    }

    return validosP;

}

int borrarPresentacionXescenario (stPresentacion presentaciones[], int validosP, int idEsc){

    int i = 0;

    while(i < validosP){

        if(presentaciones[i].idEscenario == idEsc){

            for(int j = i; j < validosP - 1; j++){

                presentaciones[j] = presentaciones[j + 1];
            }

            validosP--;

        }else{

            i++;
        }
    }

    return validosP;

}

int borrarPresentacion (stPresentacion presentacion[], int validosP, int idPres, Pila *historial){

    int pos = buscarXpresentacion(presentacion, validosP, idPres);

        if(pos == -1){

            printf("\nPresentacion inexistente.\n");
            return validosP;
        }

        apilar(historial, idPres);

        for(int i = pos; i < validosP - 1; i++){

            presentacion[i] = presentacion[i + 1];
        }

        validosP--;

        printf("\nPresentacion eliminada correctamente.\n");

        return validosP;

}

//============================================================================================================/ARCHIVO/

void guardarPresentacion(FILE *archi, stPresentacion p)
{
    stHorario fin = calcularFin(p.horaInicio, p.duracion);

    fprintf(archi, "\nID de Presentacion: %d", p.id);

    fprintf(archi, "\nID del Artista: %d", p.idArtista);

    fprintf(archi, "\nID del Escenario: %d", p.idEscenario);

    fprintf(archi,
            "\nHorario Inicio: %02d:%02d",
            p.horaInicio.horas,
            p.horaInicio.minutos);

    fprintf(archi,
            "\nDuracion: %02d:%02d",
            p.duracion.horas,
            p.duracion.minutos);

    fprintf(archi,
            "\nHorario Fin: %02d:%02d\n",
            fin.horas,
            fin.minutos);
}

void exportarPresentacionesTXT(stPresentacion presentaciones[], int validos)
{
     FILE *archi = fopen("presentaciones.txt", "w");

        if(archi == NULL){

            printf("\nError al crear archivo.");
            return;
        }

    stPresentacion *aux = malloc(validos * sizeof(stPresentacion));

        if(aux == NULL){

            printf("\nError al reservar memoria.");
            fclose(archi);
            return;
        }

        for(int i = 0; i < validos; i++){

            aux[i] = presentaciones[i];
        }

        for(int i = 0; i < validos; i++){

            fprintf(archi, "\n=====================");
            guardarPresentacion(archi, aux[i]);
        }

    free(aux);

    fclose(archi);

    printf("\nArchivo exportado correctamente.");
}
