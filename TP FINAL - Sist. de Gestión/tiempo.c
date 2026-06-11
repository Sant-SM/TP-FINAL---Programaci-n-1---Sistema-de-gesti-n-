#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

stHorario crearHoriario (int h, int m){

    stHorario dato;

    dato.horas = h;
    dato.minutos = m;

    if (h >= 0 && m >= 0 && h <= 23 && m <= 59){

        dato.esValido = 1;

    }else {

        dato.esValido = 0;

    }

    return dato;

}


stHorario pedirHorario (){

    stHorario dato;

printf ("HORAS: ");
scanf("%i", &dato.horas);

printf ("MINUTOS: ");
scanf("%i", &dato.minutos);

    return crearHoriario(dato.horas, dato.minutos);

}


stDuracion crearDuracion (int h, int m){

    stDuracion dato;

    dato.horas = h;
    dato.minutos = m;

    if (h >= 0 && m >= 0 && m <= 59){

        dato.esValido = 1;

    }else {

        dato.esValido = 0;

    }

    return dato;
}

stDuracion pedirDuracion(){

    stDuracion dato;

printf ("HORAS: ");
scanf("%i", &dato.horas);

printf ("MINUTOS: ");
scanf("%i", &dato.minutos);

    return crearDuracion(dato.horas, dato.minutos);

}
