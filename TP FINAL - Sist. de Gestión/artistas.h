#ifndef ARTISTAS_H_INCLUDED
#define ARTISTAS_H_INCLUDED

typedef struct{

int id;
char nombre[50];
char genero[30];

} stArtista;

//============================================================================================/cargar/

stArtista pedirArtistas ();
void cargarArtista(stArtista artista [], int * validos);
int existeArtista (stArtista artista[], int validos, int id);

//============================================================================================/mostrar/

void mostrarArtistas (stArtista artista[], int validos);
void mostrarArtista (stArtista artista);

//=============================================================================================/ordenar/

void ordenarArtistas (stArtista artista[], int validos);

//==============================================================================================/buscar/

int buscarXartista (stArtista artista[], int validos, int id);

//============================================================================================================/modificar/

void modificarArtista (stArtista artista[], int validos);

//===============================================================================================================/borrar/

#endif // ARTISTAS_H_INCLUDED
