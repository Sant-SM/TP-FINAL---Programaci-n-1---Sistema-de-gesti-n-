#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED

typedef struct{

int id;
char nombre[50];

} stEscenario;

stEscenario pedirEscenario();
void cargarEscenario (stEscenario escenario[], int * validos);
int existeEscenario (stEscenario escenario[], int validos, int id, char nombre[]);
int existeEscenarioID (stEscenario escenario[], int validos, int id); ///ESTA FUNCION ES ESPECIFICA PARA CREARPRESENTACION

#endif // ESCENARIO_H_INCLUDED
