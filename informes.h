#include "trabajo.h"
#include "servicios.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
void contadorMarcas(nNotebook notebook[], int tam);
void mostrarInformes(nNotebook notebook[], int tam, eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli,eTrabajo trabajo[], int tamt);
void notebooksBaratas(nNotebook notebook[], int tam);
void buscarTipo(nNotebook notebook[], int tam);
void buscarMarca(nNotebook notebook[], int tam);
int notebookListarTipo(nNotebook notebook[], int tam);
void tipoYMarca(nNotebook notebook[], int tam);
void ordenarMarcas(nNotebook notebook[], int tam);
void buscarNotebookTrabajo(nNotebook notebook[], int tam, eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli,eTrabajo trabajo[], int tamt);
