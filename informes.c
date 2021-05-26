#include <stdio.h>
#include <stdlib.h>
#include "marcas.h"
#include "notebook.h"
#include "servicios.h"
#include "tipos.h"
#include "informes.h"
#include "fecha.h"
#include "trabajo.h"
#include <string.h>
#define TAMN 1000
#define TAMTR 1000
#define TAMT 4
#define TAMMA 4
#define TAMS 4


void buscarTipo(nNotebook notebook[], int tam)
{
    int id;
    printf("Mostrar las notebooks del tipo seleccionado por el usuario\n\n");
    printf("Ingrese ID de tipo:\n\n 5000) Gamer,\n 5001) Disenio,\n 5002) Ultrabook,\n 5003) Normalita\n\n");
    scanf("%d",&id);



    for(int i=0; i<tam; i++)
    {
        if(notebook[i].isEmpty == 0)
        {
            if(notebook[i].idTipo == id)
            {

                printf("\n %2d|  %5s| %.2f| %d | \n",notebook[i].id, notebook[i].modelo, notebook[i].precio, notebook[i].idTipo);
            }

        }
    }


}

void buscarMarca(nNotebook notebook[], int tam)
{
    int idMarca;
    printf("Mostrar notebooks de una marca seleccionada\n\n");
    printf("ingrese la ID de la marca:\n\n 1000) Compaq\n 1001) Asus\n 1002) Acer\n 1003) HP\n ");
    scanf("%d",&idMarca);

    for(int i=0; i<tam; i++)
    {
        if(notebook[i].isEmpty == 0)
        {
            if(notebook[i].idMarca == idMarca)
            {

                printf("\n %2d|  %5s| %.2f| %d | %d | \n",notebook[i].id, notebook[i].modelo, notebook[i].precio, notebook[i].idTipo, notebook[i].idMarca);
            }

        }
    }


}


void contadorMarcas(nNotebook notebook[], int tam)
{

    int contadorCompaq = 0;
    int contadorAsus = 0;
    int contadorAcer = 0;
    int contadorHP = 0;

    for(int i=0; i<tam; i++)
    {
        if(notebook[i].isEmpty == 0)
        {
            switch(notebook[i].idMarca)
            {

            case 1000:
                contadorCompaq++;
                break;

            case 1001:
                contadorAsus++;
                break;

            case 1002:
                contadorAcer++;
                break;

            case 1003:
                contadorHP++;
                break;

            default:
                printf("\n\n");
            }
        }
    }
    printf("Mostrar la o las marcas mas elegidas por los clientes\n\n");
    printf("Compaqs: %d\n Asus: %d\n Acer: %d\n HP: %d\n  ",contadorCompaq, contadorAsus, contadorAcer, contadorHP);
}

void notebooksBaratas(nNotebook notebook[], int tam)
{
    int idNot;
    float maxId;


    for(int i=0; i<tam; i++)
    {
        if(notebook[i].isEmpty ==0)
        {
            if(notebook[i].precio < maxId)
            {
                maxId = notebook[i].precio;
                idNot=notebook[i].id;
            }
        }

    }
    printf("Informar la o las notebooks mas baratas\n\n");
    printf("La id mas barata es : %d y es %.2f\n\n ",idNot,maxId);

}

void ordenarMarcas(nNotebook notebook[], int tam)
{
    int flagSwap;
    nNotebook buffer;

    if(notebook!=NULL && tam>=0)
    {

        do
        {
            flagSwap=0;
            for(int i=0; i<tam-1; i++)
            {

                if(notebook[i].idMarca > notebook[i+1].idMarca)
                {
                    flagSwap=1;
                    buffer=notebook[i];
                    notebook[i]=notebook[i+1];
                    notebook[i+1]=buffer;
                }
            }
            tam--;
        }
        while(flagSwap);
    }
    else
    {
        printf("No hay nada que ordenar\n");
    }
    printf("Mostrar un listado de las notebooks separadas por marca\n\n");
    for(int i=0; i < tam; i++)
    {
        if(notebook[i].isEmpty == 0)
        {

            printf("\n %2d|  %5s| %.2f| %d | %d | \n",notebook[i].id, notebook[i].modelo, notebook[i].precio, notebook[i].idTipo, notebook[i].idMarca);
        }
    }

}


void tipoYMarca(nNotebook notebook[], int tam)
{

    int marca;
    int tipo;
    int contador = 0;

    printf("Ingrese la ID de la marca:\n\n 1000) Compaq\n 1001) Asus\n 1002) Acer\n 1003) HP\n ");
    scanf("%d",&marca);
    printf("Ingrese la ID de tipo:\n\n 5000) Gamer,\n 5001) Disenio,\n 5002) Ultrabook,\n 5003) Normalita\n");
    scanf("%d",&tipo);



    for(int i=0; i<tam; i++)
    {
        if(notebook[i].isEmpty == 0)
        {
            if(notebook[i].idMarca == marca && notebook[i].idTipo == tipo )
            {

                contador++;
            }

        }
    }

    printf("Contar notebooks con la misma marca y tipo\n");
    printf("Hay %d notebooks con esa marca y tipo\n",contador);

}

void buscarNotebookTrabajo(nNotebook notebook[], int tam, eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli,eTrabajo trabajo[], int tamt)
{
    int idNot;

    if ( verificarArray(notebook,tam)!=0)
    {
        listarNotebooks(notebook,tam, marcas, tamMar, tipo, tamT, clientes, tamCli);
        printf("Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma\n");
        printf("Ingrese la ID de la notebook: \n");
        scanf("%d",&idNot);
        printf("ID |ID notebook  |ID servicio |fecha\n");
        for(int i=0; i<tamt; i++)
        {
            if(trabajo[i].idNotebook == idNot)
            {
                printf("\n  %d| %d| %d| %d/%d/%d  \n",trabajo[i].id, trabajo[i].idNotebook, trabajo[i].idServicio, trabajo[i].fecha.dia, trabajo[i].fecha.mes, trabajo[i].fecha.anio);
            }
        }

    }
    else
    {
        printf("no hay una notebook existente\n");
    }

}
/*
void sumaImportes(enotebook notebook[], int tam, etrabajo trabajo[], int tamt, eservicios servicio[], int tams)
{
   int idNot;
   int contador=0;
   int acumulador=0;
    if ( verificarArray(notebook,tam)!=0){
         notebookListarTodos(notebook,tam);
         printf("Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma\n")
         printf("ingrese la ID de la notebook: \n");
         scanf("%d",&idNot);
         for(int i=0; i<tamt; i++){
            if(trabajo[i].idNotebook == idNot){
                acumulador+=tra
            }
         }
    }else{
        printf("no hay una notebook existente\n");
    }
}*/

void mostrarInformes(nNotebook notebook[], int tam, eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli,eTrabajo trabajo[], int tamt)
{

    contadorMarcas(notebook,tam);
    notebooksBaratas(notebook,tam);
    buscarTipo(notebook,tam);
    buscarMarca(notebook,tam);
    ordenarMarcas(notebook,tam);
    tipoYMarca(notebook,tam);
    buscarNotebookTrabajo(notebook,tam, marcas,tamMar, tipo, tamT, clientes, tamCli,trabajo,tamt);

    system("pause");
}
