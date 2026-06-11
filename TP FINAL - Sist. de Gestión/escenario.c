#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escenario.h"

stEscenario pedirEscenario(){

    stEscenario dato;

    do{

printf ("Ingrese ID del escenario: ");
scanf ("%i", &dato.id);

if (dato.id < 0){

        printf ("\nError, ingrese ID 'escenario' nuevamente");

        }

    }while (dato.id < 0);

getchar();

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
