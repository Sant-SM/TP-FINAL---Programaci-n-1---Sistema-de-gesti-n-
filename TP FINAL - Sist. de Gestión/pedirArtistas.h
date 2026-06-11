#ifndef ARTISTAS_H_INCLUDED
#define ARTISTAS_H_INCLUDED

typedef struct{

int id;
char nombre[50];
char genero[30];

} stArtista;

stArtista pedirArtistas ();

#endif // ARTISTAS_H_INCLUDED
