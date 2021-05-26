#include "fecha.h"
#include "notebook.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Inicializa todo un vector de tipo eTrabajo en la celda isEmpty en 1
 *
 * \param trabajo[] eTrabajo vector a inicializar
 * \param tam int tamaño del vector
 * \return void devuelve 1 si no encontro, sino devuelve el indice
 *
 */
int buscarTrabajoLibre(eTrabajo trabajo[], int tam);

/** \brief Analiza un vector de tipo eTrabajo y busca el primer indice con isEmpty=1
 *
 * \param trabajo[] eTrabajo vector a analizar
 * \param tam int tamaño del vector
 * \return int
 *
 */
 void inicializarTrabajo(eTrabajo trabajo[],int tam);

/** \brief Carga un vector de tipo eTrabajo en un indice
 *
 * \param trabajo[] eTrabajo vector trabajo
 * \param tam int tamaño del vector trabajo
 * \param notebook[] nNotebook vector notebook
 * \param tamn int tamaño vector notebook
 * \param marcas[] eMarca vector marcas
 * \param tamMar int tamaño de vec marcas
 * \param tipo[] eTipo vector tipo
 * \param tamT int tamaño vec tipo
 * \param id int* puntero a id
 * \param clientes[] eCliente vec clientes
 * \param tamCli int tamaño vec clientes
 * \return void devuelve 1 si se pudo dar de alta sino 0
 *
 */
void altaTrabajo(eTrabajo trabajo[],int tam, nNotebook notebook[], int tamn,eMarca marcas[],int tamMar,eTipo tipo[], int tamT, int* id,eCliente clientes[],int tamCli);


/** \brief muestra una lista de todos los trabajos realizados
 *
 * \param trabajo[] eTrabajo vector a analizar
 * \param tam int tamaño del vector
 * \return int
 *
 */

int listarTrabajos(eTrabajo trabajo[], int tam);

