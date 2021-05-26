#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "marcas.h"
#include "servicios.h"
#include "tipos.h"
#include "trabajo.h"
#define TAMT 4
#define TAMMA 4

void hardcodearMarcas(eMarca marca[], int tam)
{
    eMarca auxMarca[] =
    {
        {1000, "Compaq"},
        {1001, "Asus"},
        {1002, "Acer"},
        {1003, "HP"}
    };

    for(int i=0; i<tam; i++)
    {
        marca[i] = auxMarca[i];
    }
}

int listarMarcas(eMarca marca[], int tam)
{
    int retorno=-1;
    int i;
    if(marca!=NULL && tam>=0)
    {
        printf("ID  |Descripcion|\n");
        for(i=0; i<tam; i++)
        {
            printf("\n %2d|  %5s|  \n",marca[i].id, marca[i].descripcion);
        }
        retorno=0;
    }
    return retorno;
}
int cargarDescripcionMarca(char descripcion[], int id,eMarca marca[], int tam)
{
    int retorno=0;

    for(int i=0; i<tam; i++)
    {
        if(marca[i].id==id)
        {
            strcpy(descripcion,marca[i].descripcion);
            retorno=1;
        }
    }

    return retorno;
}
