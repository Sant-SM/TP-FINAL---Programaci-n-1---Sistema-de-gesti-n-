#include <stdio.h>
#include <stdlib.h>

//======================================================================/ESTRUCTURAS/

//====================================/ESTRUCT. HORARIO/

typedef struct{

int horas;
int minutos;
int esValido;

} stHorario;

typedef struct {

int horas;
int minutos;
int esValido;

} stDuracion;

//====================================/ESTRUCT. DATOS/

typedef struct{

int id;
char nombre[50];
char genero[30];

} stArtista;


typedef struct{

int id;
int idArtista;
int idEscenario;
stHorario horaInicio;
stDuracion duracion;

} stPresentacion;


typedef struct{

int id;
char nombre[50];

} stEscenario;


///=========================================================================/MAIN/

int main()
{




    return 0;
}


//=========================================================================/FUNCIONES/

/*CARGAS*/

stArtista cargaARTS (){

    stArtista dato;

printf ("Ingrese el ID del artista: ");
scanf ("%i", &dato.id);

printf ("Ingrese el Nombre del artista: ");
fgets(dato.nombre, 50, stdin);

printf ("Ingrese el Genero del artista: ");
fgets(dato.genero, 30, stdin);

    return dato;

}

//nombre[strcspn(nombre, "\n")] = '\0';                   BORRA SALTO DE LINEA

stEscenario cargaESC(){

    stEscenario dato;

printf ("Ingrese ID del escenario: ");
scanf ("%i", &dato.id);

printf ("Ingrese Nombre del escenario: ");
fgets(dato.nombre, 50, stdin);

    return dato;

}

stPresentacion cargaPRES(){

    stPresentacion dato;

printf ("Ingrese ID de la presentacion: ");
scanf("%i", &dato.id);

printf ("Ingrese ID del ARTISTA de la presentacion: ");
scanf ("%i", &dato.idArtista);

printf ("Ingrese ID del ESCENARIO de la presentacion: ");
scanf ("%i", &dato.idEscenario);

    //CARGA DE HORARIOS

cargaHORARIO();
cargaDUR();

    return dato;

}

stHorario cargaHORARIO (){

    stHorario dato;

printf ("HORAS: ");
scanf("%i", &dato.horas);

printf ("MINUTOS: ");
scanf("%i", &dato.minutos);

    if (dato.horas <= 24 && dato.minutos <= 60){

        dato.esValido == 1;

    }else {

        dato.esValido == 0;

    }

    return dato;

}

stDuracion cargaDUR (){

    stDuracion dato;

printf ("HORAS: ");
scanf("%i", &dato.horas);

printf ("MINUTOS: ");
scanf("%i", &dato.minutos);


    if (dato.minutos <= 60){

        dato.esValido == 1;

    }else {

        dato.esValido == 0;

}


