#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artistas.h"

stArtista pedirArtistas (){

    stArtista dato;

printf ("Ingrese el ID del artista: ");
scanf ("%i", &dato.id);

getchar();

printf ("Ingrese el Nombre del artista: ");
fgets(dato.nombre, 50, stdin);
dato.nombre[strcspn(dato.nombre, "\n")] = '\0';

printf ("Ingrese el Genero del artista: ");
fgets(dato.genero, 30, stdin);
dato.genero[strcspn(dato.genero, "\n")] = '\0';

    return dato;

}
