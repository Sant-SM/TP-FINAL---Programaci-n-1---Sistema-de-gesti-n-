#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED

#include "tiempo.h"

typedef struct{

int id;
int idArtista;
int idEscenario;
stHorario horaInicio;
stDuracion duracion;

} stPresentacion;

//============================================================================================/cargar/

stPresentacion pedirPresentacion();
void cargaPresentaciones (stPresentacion presentacion[], int * validosPRES, stArtista artista[], int validosARTS, stEscenario escenario[], int validosESC);
int existePresentacion (stPresentacion presentacion[], int validos, int id);
int existeSolapamientoPRES(stPresentacion presentaciones[], int validos, stPresentacion nueva);

//============================================================================================/mostrar/

void mostrarPresentacion (stPresentacion precentacion);
void mostrarPresentaciones (stPresentacion precentacion[], int validos);
void ordenarPresentacionXhorario (stPresentacion presentacion[], int validos);

//===================================================================================/mostrar filtrado/

void mostrarPresentacionXartista (stPresentacion presentacion[], int validos, int id);
void filtrarPresentacionXartista (stPresentacion presentacion[], int validosP, stArtista artista[], int validosA);
void mostrarPresentacionXescenario (stPresentacion presentacion[], int validos, int id);
void filtrarPresentacionXescenario (stPresentacion presentacion[], int validosP, stEscenario escenario[], int validosE);

//==============================================================================================/buscar/

int buscarXpresentacion (stPresentacion presentacion[], int validos, int id);

//============================================================================================================/modificar/

void modificarPresentacion (stPresentacion presentacion[], int validosP, stEscenario escenario[], int validosE, stArtista artista[], int validosA);
int existeSolapamientoPRES_Modificar (stPresentacion presentaciones[], int validos, stPresentacion nueva, int pos);

//===============================================================================================================/borrar/

#endif // PRESENTACION_H_INCLUDED
