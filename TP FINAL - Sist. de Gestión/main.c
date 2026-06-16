#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artistas.h"
#include "escenario.h"
#include "presentacion.h"
#include "tiempo.h"
#include "constantes.h"
#include "utilidades.h"

//nombre[strcspn(nombre, "\n")] = '\0';                   BORRA SALTO DE LINEA

///=========================================================================/MAIN/

int main()
{

    stArtista artistas [MAX_ARTISTAS];                  ///PREGUNTAR EN CLASE: Debo verificar el si el nombre estaba ingresado? O basta con los datos?
    int validosARTISTAS = 0;

    stEscenario escenarios [MAX_ESCENARIOS];
    int validosESCENARIOS = 0;

    stPresentacion presentaciones [MAX_PRESENTACIONES];
    int validosPRESENTACIONES = 0;

    int opcion;
    int subOpcion;

do{

    printf("\n==============================");
    printf("\n   SISTEMA DE FESTIVALES");
    printf("\n==============================");

    printf("\n1- Dar de Alta");
    printf("\n2- Modificar");
    printf("\n3- Borrar");
    printf("\n4- Listar");
    printf("\n5- Listados Filtrados");
    printf("\n0- Salir");

    printf("\n\nIngrese una opcion: ");
    opcion = pedirEntero();

    switch(opcion){

        //========================================================/ALTAS/

        case 1:

            printf("\n--- DAR DE ALTA ---");

            printf("\n1- Artista");
            printf("\n2- Escenario");
            printf("\n3- Presentacion");

            printf("\nIngrese una opcion: ");
            subOpcion = pedirEntero();

            switch(subOpcion){

                case 1:
                    cargarArtista(artistas, &validosARTISTAS);
                    break;

                case 2:
                    cargarEscenario(escenarios, &validosESCENARIOS);
                    break;

                case 3:
                    cargaPresentaciones(presentaciones, &validosPRESENTACIONES, artistas, validosARTISTAS, escenarios, validosESCENARIOS);
                    break;

                default:
                    printf("\nOpcion invalida");
            }

            break;

        //========================================================/MODIFICAR/

        case 2:

            printf("\n--- MODIFICAR ---");

            printf("\n1- Artista");
            printf("\n2- Escenario");
            printf("\n3- Presentacion");

            printf("\nIngrese una opcion: ");
            subOpcion = pedirEntero();

            switch(subOpcion){

                case 1:
                    modificarArtista (artistas, validosARTISTAS);
                    ordenarArtistas(artistas, validosARTISTAS);
                    break;

                case 2:
                    modificarEscenario (escenarios, validosESCENARIOS);
                    ordenarEscenarios(escenarios, validosESCENARIOS);
                    break;

                case 3:
                    modificarPresentacion (presentaciones, validosPRESENTACIONES, escenarios, validosESCENARIOS, artistas, validosARTISTAS);
                    //ordenarPresentacion(...)
                    break;

                default:
                    printf("\nOpcion invalida");
            }

            break;

        //========================================================/BORRAR/

        case 3:

            printf("\n--- BORRAR ---");

            printf("\n1- Artista");
            printf("\n2- Escenario");
            printf("\n3- Presentacion");

            printf("\nIngrese una opcion: ");
            subOpcion = pedirEntero();

            switch(subOpcion){

                case 1:
                    // borrarArtista(...)
                    break;

                case 2:
                    // borrarEscenario(...)
                    break;

                case 3:
                    // borrarPresentacion(...)
                    break;

                default:
                    printf("\nOpcion invalida");
            }

            break;

        //========================================================/LISTADOS COMPLETOS/

        case 4:

            printf("\n--- LISTADOS COMPLETOS ---");

            printf("\n1- Artistas");
            printf("\n2- Escenarios");
            printf("\n3- Presentaciones");

            printf("\nIngrese una opcion: ");
            subOpcion = pedirEntero();

            switch(subOpcion){

                case 1:
                    ordenarArtistas(artistas, validosARTISTAS);
                    mostrarArtistas(artistas, validosARTISTAS);
                    break;

                case 2:
                    ordenarEscenarios(escenarios, validosESCENARIOS);
                    mostrarEscenarios(escenarios, validosESCENARIOS);
                    break;

                case 3:
                    //ordenarPresentaciones(...);   ///LAS PRESENTACIONES SE ORDENAN POR ID? O COMO???
                    mostrarPresentaciones(presentaciones, validosPRESENTACIONES);
                    break;

                default:
                    printf("\nOpcion invalida");
            }

            break;

        //========================================================/FILTRADOS/

        case 5:

            printf("\n--- LISTADOS FILTRADOS ---");

            printf("\n1- Presentaciones por Artista");
            printf("\n2- Presentaciones por Escenario");

            printf("\nIngrese una opcion: ");
            subOpcion = pedirEntero();

            switch(subOpcion){

                case 1:
                    filtrarPresentacionXartista(presentaciones, validosPRESENTACIONES, artistas, validosARTISTAS);
                    break;

                case 2:
                    filtrarPresentacionXescenario(presentaciones, validosPRESENTACIONES, escenarios, validosESCENARIOS);
                    break;

                default:
                    printf("\nOpcion invalida");
            }

            break;

        //========================================================/SALIR/

        case 0:

            printf("\nSaliendo del sistema...");
            break;

        default:

            printf("\nOpcion invalida");
    }

}while(opcion != 0);


    return 0;
}
