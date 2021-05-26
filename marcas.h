#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eMarca;

#endif // MARCAS_H_INCLUDED
void hardcodearMarcas(eMarca marca[], int tam);
int listarMarcas(eMarca marca[], int tam);
int cargarDescripcionMarca(char descripcion[], int id,eMarca marca[], int tam);
