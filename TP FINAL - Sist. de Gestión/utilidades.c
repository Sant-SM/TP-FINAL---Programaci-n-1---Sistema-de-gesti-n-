#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"

int pedirEntero (){

    int dato;
    int control;

    do{

        control = scanf("%i", &dato);

        if (control != 1){              // 1 HACE REFERENCIA A UN ENTERO (conjunto de numeros enteros SIN ESPACIO ENTREMEDIO conforman UN ENTERO)

            printf ("\nError, no es posible ingresar ni LETRAS ni numeros ESPACIADOS");
            printf ("\nIngrese nuevamente el dato: ");

        }

            while(getchar() != '\n');   //LIMPIA EL BUFFER HASTA ENCONTRAR EL SALTO DE LINEA (\n)

    }while (control != 1);


    return dato;

}
