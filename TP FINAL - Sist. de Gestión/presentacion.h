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

#endif // PRESENTACION_H_INCLUDED
