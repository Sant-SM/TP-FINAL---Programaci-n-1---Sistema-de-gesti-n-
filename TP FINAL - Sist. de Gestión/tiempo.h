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
stHorario calcularFin (stHorario horarioINICIO, stDuracion horarioDURACION);
int horarioAMinutos(stHorario h);        ///PARA SIMPLIFICAR FUNCION haySolapamiento
int haySolapamiento(stHorario inicio1, stHorario fin1, stHorario inicio2, stHorario fin2);

#endif // TIEMPO_H_INCLUDED
