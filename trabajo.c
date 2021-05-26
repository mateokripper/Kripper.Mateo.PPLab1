#include <stdio.h>
#include <stdlib.h>
#include "marcas.h"
#include "trabajo.h"
#include "servicios.h"
#include "tipos.h"
#include "trabajo.h"
#include <string.h>
#define TAMN 4
#define TAMTR 1000
#define TAMT 4
#define TAMMA 4
#define TAMS 4

void inicializarTrabajo(eTrabajo trabajo[],int tam)
{

    for(int i=0; i < tam; i++)
    {
        trabajo[i].isEmpty = 1;
    }
}

int buscarTrabajoLibre(eTrabajo trabajo[], int tam)
{
    int index=1;

    for(int i=0; i<tam; i++)
    {
        if(trabajo[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }

    return index;
}
void altaTrabajo(eTrabajo trabajo[],int tam, nNotebook notebook[], int tamn,eMarca marcas[],int tamMar,eTipo tipo[], int tamT, int* id,eCliente clientes[],int tamCli)
{
    int i;
    i = buscarTrabajoLibre(trabajo, tam);
    if(i!=1)
    {

        listarNotebooks(notebook,tam, marcas, tamMar,tipo, tamT, clientes, tamCli);
        printf("\nIngrese id de la notebook: ");
        scanf("%d", &trabajo[i].idNotebook);

        while(verificarIdNotebook(notebook, TAMN, trabajo[i].idNotebook )==1 )
        {
            printf("ingrese una ID existente\n");
            scanf("%d",&trabajo[i].idNotebook);
        }

        printf("ingrese la ID del servicio:\n\n 20000) Bateria\n 20001) Antivirus:\n 20002) Actualizacion:\n 20003) Fuente:\n ");
        fflush(stdin);
        scanf("%d",&trabajo[i].idServicio);

        while(trabajo[i].idServicio < 20000 || trabajo[i].idServicio >20003 )
        {
            printf("ingrese una ID existente\n");
            fflush(stdin);
            scanf("%d",&trabajo[i].idServicio);
        }

        printf("\nIngrese fecha del trabajo: ");
        scanf("%d/%d/%d", &trabajo[i].fecha.dia, &trabajo[i].fecha.mes, &trabajo[i].fecha.anio);

        trabajo[i].isEmpty=0;

    }
    else
    {
        printf("No hay una notebook existente\n");
    }

}


int listarTrabajos(eTrabajo trabajo[], int tam)
{
    int retorno=-1;
    int i;
    if(trabajo!=NULL && tam>=0)
    {
        printf("ID |ID notebook  |ID servicio |fecha\n");
        for(i=0; i<tam; i++)
        {
            if(trabajo[i].isEmpty!=1)
            {
                printf("\n  %d| %d| %d| %d/%d/%d  \n",trabajo[i].id, trabajo[i].idNotebook, trabajo[i].idServicio, trabajo[i].fecha.dia, trabajo[i].fecha.mes, trabajo[i].fecha.anio);

            }
        }
        retorno=0;
    }
    return retorno;
}
