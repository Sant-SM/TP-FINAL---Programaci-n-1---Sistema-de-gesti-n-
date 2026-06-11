#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presentacion.h"
#include "tiempo.h"

stPresentacion pedirPresentacion(){

    stPresentacion dato;

    do{

printf ("Ingrese ID de la presentacion: ");
scanf("%i", &dato.id);

    if (dato.id < 0){

        printf ("\nError, ingrese ID 'presentacion' nuevamente");

    }

    }while (dato.id < 0);

    do{

printf ("Ingrese ID del ARTISTA de la presentacion: ");
scanf ("%i", &dato.idArtista);

    if (dato.idArtista < 0){

        printf ("\nError, ingrese ID 'artista' nuevamente");

    }

    }while (dato.idArtista < 0);

    do{

printf ("Ingrese ID del ESCENARIO de la presentacion: ");
scanf ("%i", &dato.idEscenario);

    if (dato.idEscenario < 0){

        printf ("\nError, ingrese ID 'escenario' nuevamente");

    }

    }while (dato.idEscenario < 0);


    //CARGA DE HORARIOS

    do{

    dato.horaInicio = pedirHorario();

}while(dato.horaInicio.esValido == 0);

do{

    dato.duracion = pedirDuracion();

}while(dato.duracion.esValido == 0);

    return dato;

}
