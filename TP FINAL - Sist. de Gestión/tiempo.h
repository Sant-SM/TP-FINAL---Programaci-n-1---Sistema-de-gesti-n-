#ifndef TIEMPO_H_INCLUDED
#define TIEMPO_H_INCLUDED

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

stHorario pedirHorario();
stDuracion pedirDuracion();
stHorario crearHoriario (int h, int m);
stDuracion crearDuracion (int h, int m);

#endif // TIEMPO_H_INCLUDED
