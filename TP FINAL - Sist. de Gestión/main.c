#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artistas.h"
#include "escenario.h"
#include "presentacion.h"
#include "tiempo.h"
#include "constantes.h"
#include "utilidades.h"

//======================================================================/LLAMADO DE FUNCIONES/



///=========================================================================/MAIN/

int main()
{

    stArtista artistas [MAX_ARTISTAS];                  ///PREGUNTAR EN CLASE: Debo verificar el si el nombre estaba ingresado? O basta con los datos?
    int validosARTISTAS = 0;

    cargarArtista(artistas, &validosARTISTAS);

    stEscenario escenarios [MAX_ESCENARIOS];
    int validosESCENARIOS = 0;

    cargarEscenario(escenarios, &validosESCENARIOS);

    stPresentacion presentaciones [MAX_PRESENTACIONES];
    int validosPRESENTACIONES = 0;

    cargaPresentaciones(presentaciones, &validosPRESENTACIONES, artistas, validosARTISTAS, escenarios, validosESCENARIOS);


    return 0;
}


//=========================================================================/FUNCIONES/

//nombre[strcspn(nombre, "\n")] = '\0';                   BORRA SALTO DE LINEA










