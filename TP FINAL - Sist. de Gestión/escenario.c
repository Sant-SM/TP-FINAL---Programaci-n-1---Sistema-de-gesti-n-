#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escenario.h"
#include "constantes.h"
#include "utilidades.h"
#include "pila.h"

stEscenario pedirEscenario(){

    stEscenario dato;

    do{

    printf ("\nIngrese ID del escenario: ");
    dato.id = pedirEntero();

    if (dato.id < 0){

        printf ("\nError, ingrese ID 'escenario' nuevamente");

        }

    }while (dato.id < 0);


    do{

    printf ("\nIngrese Nombre del escenario: ");
    fgets(dato.nombre, 50, stdin);
    dato.nombre[strcspn(dato.nombre, "\n")] = '\0';

        if (strlen(dato.nombre) == 0){

            printf ("\nError, ingrese NOMBRE nuevamente");

        }


    }while (strlen(dato.nombre) == 0);

    return dato;

}

//====================================================/CARGA ESCENARIO/

void cargarEscenario (stEscenario escenario[], int * validos) {

    stEscenario nuevo;

    char s = 's';

    while ((s == 's' || s == 'S') && *validos < MAX_ESCENARIOS){

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

int existeEscenarioID (stEscenario escenario[], int validos, int id){ ///ESTA FUNCION ES ESPECIFICA PARA CREARPRESENTACION

    for (int i = 0; i < validos; i++){

        if (escenario[i].id == id){

            return 1;
        }
    }

    return 0;

}

//====================================================================================================================/mostrar/

void mostrarEscenarios (stEscenario escenario[], int validos){

    for (int i = 0; i < validos; i++){

        printf ("\n=========================\n");

        mostrarEscenario(escenario[i]);

        printf ("\n=========== ESOS SON LOS ESCENARIOS ==============\n");

    }

}

void mostrarEscenario (stEscenario escenario){

        printf ("\nID del Escenario: %i", escenario.id);
        printf ("\nNombre del Escenario: %s", escenario.nombre);

}

//=======================================================================================================================/ordenar/

void ordenarEscenarios (stEscenario escenario[], int validos){

    stEscenario aux;

    for (int i = 0; i < validos - 1; i++){

        for (int j = i + 1; j < validos; j++){

            if (stricmp(escenario[i].nombre, escenario[j].nombre) > 0){

                aux = escenario[i];
                escenario[i] = escenario[j];
                escenario[j] = aux;

            }

        }
    }

}

//==============================================================================================================/buscar/

int buscarXescenario (stEscenario escenario[], int validos, int id){

    for (int i = 0; i < validos; i++){

        if (escenario[i].id == id){

            return i;

        }

    }

    return -1;

}

//============================================================================================================/modificar/

void modificarEscenario (stEscenario escenario[], int validos){

        int id;

    printf ("\nIngrese ID del escenario que desea modificar: ");
    scanf("%i", &id);

    int pos = buscarXescenario(escenario, validos, id);

    if(pos == -1){

    printf("\nEscenario inexistente");
    return;

    }else{

    printf("\nEscenario encontrado.\n");

    getchar();

    do{

    printf("\nIngrese el nuevo nombre: ");
    fgets(escenario[pos].nombre, 50, stdin);
    escenario[pos].nombre[strcspn(escenario[pos].nombre, "\n")] = '\0';

    }while(strlen(escenario[pos].nombre) == 0);

    printf("\nEscenario modificado correctamente.\n");
    }

}


//===============================================================================================================/borrar/

int borrarEscenario(stEscenario escenarios[], int validos, int id, Pila *historial){

        int pos = buscarXescenario(escenarios, validos, id);

        if (pos == -1){

            printf ("\nEl escenario no existe");
            return validos;

        }

        apilar(historial, id);

        for (int i = pos; i < validos - 1; i++){

            escenarios[i] = escenarios[i + 1];
            }

            validos--;

        printf("\nEscenario eliminado correctamente.\n");

    return validos;
}

//=====================================================================================================/ARCHIVO/

void guardarEscenario(FILE *archi, stEscenario escenario){

    fprintf(archi, "\nID del Escenario: %i", escenario.id);
    fprintf(archi, "\nNombre del Escenario: %s\n", escenario.nombre);
}

void exportarEscenariosTXT(stEscenario escenarios[], int validos){

    FILE *archi = fopen("escenarios.txt", "w");

        if(archi == NULL){

            printf("\nError al crear archivo.");
            return;
        }

    stEscenario *aux = malloc(validos * sizeof(stEscenario));

        if(aux == NULL){

            printf("\nError al reservar memoria.");
            fclose(archi);
            return;
        }

        for(int i = 0; i < validos; i++){

            aux[i] = escenarios[i];
        }

        for(int i = 0; i < validos; i++){

            fprintf(archi, "\n=====================");
            guardarEscenario(archi, aux[i]);
        }

    free(aux);

    fclose(archi);

    printf("\nArchivo exportado correctamente.");
}

