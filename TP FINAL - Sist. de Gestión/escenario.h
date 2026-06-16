#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED

typedef struct{

int id;
char nombre[50];

} stEscenario;

//============================================================================================/cargar/

stEscenario pedirEscenario();
void cargarEscenario (stEscenario escenario[], int * validos);
int existeEscenario (stEscenario escenario[], int validos, int id, char nombre[]);
int existeEscenarioID (stEscenario escenario[], int validos, int id); ///ESTA FUNCION ES ESPECIFICA PARA CREARPRESENTACION

//============================================================================================/mostrar/

void mostrarEscenario (stEscenario escenario);
void mostrarEscenarios (stEscenario escenario[], int validos);

//============================================================================================/ordenar/

void ordenarEscenarios (stEscenario escenario[], int validos);

//=============================================================================================/buscar/

int buscarXescenario (stEscenario escenario[], int validos, int id);

//============================================================================================================/modificar/

void modificarEscenario (stEscenario escenario[], int validos);

//===============================================================================================================/borrar/

#endif // ESCENARIO_H_INCLUDED
