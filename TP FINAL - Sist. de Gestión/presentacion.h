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

stPresentacion pedirPresentacion();
void cargaPresentaciones (stPresentacion presentacion[], int * validosPRES, stArtista artista[], int validosARTS, stEscenario escenario[], int validosESC);
int existePresentacion (stPresentacion presentacion[], int validos, int id);

#endif // PRESENTACION_H_INCLUDED
