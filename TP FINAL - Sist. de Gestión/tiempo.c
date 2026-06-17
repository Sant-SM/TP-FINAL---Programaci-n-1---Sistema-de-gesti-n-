#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include "constantes.h"
#include "utilidades.h"

stHorario crearHorario (int h, int m){

    stHorario dato;

    dato.horas = h;
    dato.minutos = m;

    if (h >= 0 && m >= 0 && h <= 23 && m <= 59){

        dato.esValido = 1;

    }else {

        printf ("\nError, las horas tienen que ser menor a 24 y los minutos menor a 60");

        dato.esValido = 0;

    }

    return dato;

}


stHorario pedirHorario (){

    stHorario dato;

    printf ("\n---HS DE INICIO DE LA PRESENTACION---\n");

    do{

printf ("\nHORAS: ");
scanf("%i", &dato.horas);

printf ("\nMINUTOS: ");
scanf("%i", &dato.minutos);

    dato = crearHorario(dato.horas, dato.minutos);

    }while (dato.esValido == 0);

    return dato;

}


stDuracion crearDuracion (int h, int m){

    stDuracion dato;

    dato.horas = h;
    dato.minutos = m;

    if (h >= 0 && m >= 0 && m <= 59){

        dato.esValido = 1;

    }else {

        printf ("\nError, los minutos tienen que ser menor a 60");

        dato.esValido = 0;

    }

    return dato;
}

stDuracion pedirDuracion(){

    stDuracion dato;

    printf ("\n---DURACION DE LA PRESENTACION---\n");

    do{

printf ("\nHORAS: ");
scanf("%i", &dato.horas);

printf ("\nMINUTOS: ");
scanf("%i", &dato.minutos);

    dato = crearDuracion(dato.horas, dato.minutos);

    }while (dato.esValido == 0);

    return dato;

}

stHorario calcularFin (stHorario horarioINICIO, stDuracion horarioDURACION){

    stHorario fin;

    fin.horas = horarioINICIO.horas + horarioDURACION.horas;
    fin.minutos = horarioINICIO.minutos + horarioDURACION.minutos;

    while (fin.minutos >= 60){

        fin.minutos -= 60;
        fin.horas++;

    }

    fin.horas %= 24;

    fin.esValido = 1;
    return fin;

}

int haySolapamiento(stHorario inicio1, stHorario fin1, stHorario inicio2, stHorario fin2){

    int ini1 = horarioAMinutos(inicio1);
    int finN1 = horarioAMinutos(fin1);

    int ini2 = horarioAMinutos(inicio2);
    int finN2 = horarioAMinutos(fin2);


    if (finN1 <= ini2 || finN2 <= ini1){

        return 0; //INDICA QUE NO HAY SOLAPAMIENTO

    }

    return 1;

}

int horarioAMinutos(stHorario h){           ///PARA SIMPLIFICAR FUNCION haySolapamiento

    return h.horas * 60 + h.minutos;

}
