#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escenario.h"
#include "constantes.h"
#include "utilidades.h"

stEscenario pedirEscenario(){

    stEscenario dato;

    do{

    printf ("Ingrese ID del escenario: ");
    dato.id = pedirEntero();

    if (dato.id < 0){

        printf ("\nError, ingrese ID 'escenario' nuevamente");

        }

    }while (dato.id < 0);


    do{

    printf ("Ingrese Nombre del escenario: ");
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

        if (escenario[i].id == id == 0){

            return 1;
        }
    }

    return 0;

}
