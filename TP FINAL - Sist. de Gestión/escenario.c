#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escenario.h"

stEscenario pedirEscenario(){

    stEscenario dato;

printf ("Ingrese ID del escenario: ");
scanf ("%i", &dato.id);

getchar();

printf ("Ingrese Nombre del escenario: ");
fgets(dato.nombre, 50, stdin);
dato.nombre[strcspn(dato.nombre, "\n")] = '\0';

    return dato;

}
