#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];
} eTipo;



#endif // TIPOS_H_INCLUDED
void hardcodearTipo(eTipo tipo[], int tam);
int verificarIdTipo(eTipo tipo[], int tam, int id);
int listarTipo(eTipo tipo[], int tam);
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipo[], int tam);
