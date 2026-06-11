#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presentacion.h"
#include "tiempo.h"

stPresentacion pedirPresentacion(){

    stPresentacion dato;

printf ("Ingrese ID de la presentacion: ");
scanf("%i", &dato.id);

printf ("Ingrese ID del ARTISTA de la presentacion: ");
scanf ("%i", &dato.idArtista);

printf ("Ingrese ID del ESCENARIO de la presentacion: ");
scanf ("%i", &dato.idEscenario);

    //CARGA DE HORARIOS

    do{

    dato.horaInicio = pedirHorario();

}while(dato.horaInicio.esValido == 0);

do{

    dato.duracion = pedirDuracion();

}while(dato.duracion.esValido == 0);

    return dato;

}
