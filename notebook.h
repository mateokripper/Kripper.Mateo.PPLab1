#include "marcas.h"
#include "tipos.h"
#include "clientes.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[21];
    int idMarca;
    int idTipo;
    float precio;
    int idCliente;
    int isEmpty;
} nNotebook;


#endif // NOTEBOOK_H_INCLUDED
void listarNotebook(nNotebook notebook, int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli);
int listarNotebooks(nNotebook notebook[], int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli);
int buscarNotebookLibre (nNotebook notebook[], int tam);
int bajaNotebook(nNotebook notebook[], int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli);
void altaNotebook(nNotebook notebook[], int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli);
int modificarNotebook(nNotebook notebook[], int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli);
int buscarIdNotebook(nNotebook notebook[], int tam, int valorBuscado, int* posicion);
int verificarIdNotebook(nNotebook notebook[], int tam, int id);
void inicializarNotebooks (nNotebook lista[], int tam);
int verificarArray(nNotebook notebook[], int tam);
