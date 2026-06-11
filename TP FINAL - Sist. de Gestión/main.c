#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artistas.h"
#include "escenario.h"
#include "presentacion.h"
#include "tiempo.h"

//======================================================================/LLAMADO DE FUNCIONES/

void cargarArtista(stArtista artista [], int validos);




///=========================================================================/MAIN/

int main()
{




    return 0;
}


//=========================================================================/FUNCIONES/

//nombre[strcspn(nombre, "\n")] = '\0';                   BORRA SALTO DE LINEA

//====================================================/CARGAS/

void cargarArtista (stArtista artista[], int validos) {

    int i = 0;
    char s = 's';

    while (i < validos && (s == 's' || s == 'S')){

        pedirArtistas();

        printf ("Desea continuar la carga? Para SI presione 's' || 'S', para NO, presione otra tecla: ");
        scanf (" %c", &s);

    }
}

stArtista existeArtista (stArtista artista[], int validos, int j, int flag){

    for (int i = 0; i < validos; i++){

    if (artista[j].id == artista[i].id || artista[j].nombre == artista[i].nombre){

        printf ("\nEse artista ya existe! Ingrese de nuevo los datos del artista");
        flag = 1;


    }else {

        flag = 0;

    }

    }

}









