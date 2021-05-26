#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "fecha.h"
#include "notebook.h"
#include "servicios.h"
#include "tipos.h"
#include "trabajo.h"
#define TAMT 4
#define TAMMA 4
void hardcodearTipo(eTipo tipo[], int tam)
{
    eTipo auxTipo[] =
    {
        {5000, "Gamer",},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
    };

    for(int i=0; i<tam; i++)
    {
        tipo[i] = auxTipo[i];
    }
}

int verificarIdTipo(eTipo tipo[], int tam, int id)
{
    int retorno=-1;
    for(int i = 0; i < tam; i++ )
    {
        if(tipo[i].id == id)
        {
            retorno = 0;
        }
    }
    return retorno;
}

int listarTipo(eTipo tipo[], int tam)
{
    int retorno=-1;
    if(tipo!=NULL && tam>=0)
    {
        printf("ID  |Descripcion|\n");
        for(int i=0; i<tam; i++)
        {
            printf("\n %2d|  %5s|  \n",tipo[i].id, tipo[i].descripcion);
        }
        retorno=0;
    }
    return retorno;
}
int cargarDescripcionTipo(char descripcion[], int id,eTipo tipo[], int tam)
{
    int retorno=0;

    for(int i=0; i<tam; i++)
    {
        if(tipo[i].id==id)
        {
            strcpy(descripcion,tipo[i].descripcion);
            retorno=1;
        }
    }

    return retorno;
}
