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
    printf("\n6- Exportar a TXT");
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
                    ordenarPresentacionXhorario(presentaciones, validosPRESENTACIONES);
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

                    int idA;
                    char opcionA = 's';

                    printf("Ingrese el ID del artista que quiere borrar: ");
                    idA = pedirEntero();

                    int cantA = contarPresentacionesXartista(presentaciones, validosPRESENTACIONES, idA);

                    int posA = buscarXartista(artistas, validosARTISTAS, idA);

                    if(posA == -1){

                        printf("\nArtista inexistente.\n");
                    }
                    else{

                        if (cantA > 0){

                            printf ("\nHay %i presentaciones pendientes del artista. Seguro que desea borrar? ", cantA);
                            printf ("\n ingrese 's' || 'S' para borrar, ingrese otra letra para borrar: ");
                            scanf(" %c", &opcionA);

                             if(opcionA == 's' || opcionA == 'S'){

                                validosPRESENTACIONES = borrarPresentacionXartista(presentaciones, validosPRESENTACIONES, idA);
                                validosARTISTAS = borrarArtista(artistas, validosARTISTAS, idA);

                                }
                                else{

                                    printf("\nOperacion cancelada.\n");
                                }
                            }else {

                                validosARTISTAS = borrarArtista(artistas, validosARTISTAS, idA);

                            }

                        }

                    break;

                case 2:

                    int idE;
                    char opcionE = 's';

                    printf("Ingrese el ID del escenario que quiere borrar: ");
                    idE = pedirEntero();

                    int cantE = contarPresentacionesXescenario(presentaciones, validosPRESENTACIONES, idE);

                    int posE = buscarXescenario(escenarios, validosESCENARIOS, idE);

                    if(posE == -1){

                        printf("\nEscenario inexistente.\n");
                    }
                    else{

                        if (cantE > 0){

                            printf ("\nHay %i presentaciones pendientes del escenario. Seguro que desea borrar? ", cantE);
                            printf ("\n ingrese 's' || 'S' para borrar, ingrese otra letra para borrar: ");
                            scanf(" %c", &opcionE);

                             if(opcionE == 's' || opcionE == 'S'){

                                validosPRESENTACIONES = borrarPresentacionXescenario(presentaciones, validosPRESENTACIONES, idE);
                                validosESCENARIOS = borrarEscenario(escenarios, validosESCENARIOS, idE);

                                }
                                else{

                                    printf("\nOperacion cancelada.\n");
                                }
                            }else {

                                validosESCENARIOS = borrarEscenario(escenarios, validosESCENARIOS, idE);

                            }

                        }

                    break;

                case 3:

                        int idP;

                    printf("\nIngrese ID de la presentacion: ");
                    idP = pedirEntero();

                        validosPRESENTACIONES = borrarPresentacion(presentaciones, validosPRESENTACIONES, idP);

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
                    ordenarPresentacionXhorario(presentaciones, validosPRESENTACIONES);
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

            case 6:

            exportarArtistasTXT(artistas, validosARTISTAS);
            exportarEscenariosTXT(escenarios, validosESCENARIOS);
            exportarPresentacionesTXT(presentaciones, validosPRESENTACIONES);

            printf("\nTodos los archivos fueron exportados.\n");
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
