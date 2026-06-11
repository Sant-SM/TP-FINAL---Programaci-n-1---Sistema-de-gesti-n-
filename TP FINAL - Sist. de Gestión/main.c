#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


//======================================================================/LLAMADO DE FUNCIONES/

stArtista pedirArtistas ();
stEscenario pedirEscenario();
stPresentacion pedirPresentacion();
stHorario crearHorario (int h, int m);
stHorario pedirHorario ();
stDuracion crearDuracion (int h, int m);
stDuracion pedirDuracion();

///=========================================================================/MAIN/

int main()
{




    return 0;
}


//=========================================================================/FUNCIONES/

//====================================================/CARGAS INDIVIDUALES/

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

//nombre[strcspn(nombre, "\n")] = '\0';                   BORRA SALTO DE LINEA

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

//====================================================/CARGAS GLOBALES/

void cargarArtista (stArtista artista[], int validos) {







}










