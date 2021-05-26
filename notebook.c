#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "notebook.h"
#include "marcas.h"
#include "tipos.h"
#include "clientes.h"
#define TAMN 1000
#define TAMT 4
#define TAMMA 4

void listarNotebook(nNotebook notebook, int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli)
{
    char marca [20];
    char tipos[20];
    char cliente[20];
    cargarDescripcionMarca (marca, notebook.idMarca,marcas,tamMar);
    cargarDescripcionTipo(tipos, notebook.idTipo,tipo, tamT);
    cargarDescripcionCliente(cliente, notebook.idCliente, clientes,tamCli);

    printf("\n %2d|  %5s| %.2f| %10s |  %10s\n",notebook.id, marca, notebook.precio,  tipos, cliente);


}
int listarNotebooks(nNotebook notebook[], int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli)
{
    int retorno=-1;
    int i;
    if(notebook!=NULL && tam>=0)
    {
        printf("ID |marca  |precio |  Tipo |  Cliente\n");
        for(i=0; i<tam; i++)
        {
            if(notebook[i].isEmpty!=1)
            {
                listarNotebook (notebook[i], tam, marcas, tamMar, tipo, tamT, clientes, tamCli );

            }
        }
        retorno=0;
    }
    return retorno;
}
void inicializarNotebooks (nNotebook lista[], int tam)
{
    for (int i = 0; i<tam; i++)
    {
        lista [i].isEmpty = 1;
    }
}

void altaNotebook(nNotebook notebook[], int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli)
{
    int i;
    i= buscarNotebookLibre(notebook,tam);
    if(i!=-1)
    {
        printf("ingrese un modelo: ");
        fflush(stdin);
        gets(notebook[i].modelo);
        printf("ingrese la ID de la marca:\n\n 1000) Compaq\n 1001) Asus\n 1002) Acer\n 1003) HP\n ");
        fflush(stdin);
        scanf("%d",&notebook[i].idMarca);

        while(notebook[i].idMarca < 1000 || notebook[i].idMarca >1003 )
        {
            printf("ingrese una ID existente\n");
            fflush(stdin);
            scanf("%d",&notebook[i].idMarca);
        }
        printf("ingrese un precio : ");
        fflush(stdin);
        scanf("%f",&notebook[i].precio);

        while(notebook[i].id < 0 )
        {
            printf("ingrese unprecio positivo\n");
            fflush(stdin);
            scanf("%f",&notebook[i].precio);
        }

        printf("ingrese la ID de tipo:\n\n 5000) Gamer,\n 5001) Disenio,\n 5002) Ultrabook,\n 5003) Normalita\n ");
        fflush(stdin);
        scanf("%d",&notebook[i].idTipo);

        while(notebook[i].idTipo < 5000 || notebook[i].idTipo >5003 )
        {
            printf("ingrese una ID existente\n");
            fflush(stdin);
            scanf("%d",&notebook[i].idTipo);
        }
        notebook[i].id=i+1;
        notebook[i].isEmpty=0;

    }
    else
    {
        printf("No hay espacio\n");
    }

}
int buscarNotebookLibre (nNotebook lista[], int tam)
{
    int libre = -1;
    for (int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            libre = i;
            break;
        }
    }
    return libre;
}
int bajaNotebook(nNotebook notebook[], int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli)
{
    int retorno=1;
    int posicion;
    int idNotebook;
    listarNotebooks(notebook,tam, marcas, tamMar, tipo, tamT, clientes, tamCli);

    if(notebook!=NULL && tam>0)
    {
        printf("ingrese la id que se busca\n");
        scanf("%d",&idNotebook);
        if(buscarIdNotebook(notebook,tam,idNotebook,&posicion)==-1)
        {
            printf("\nNo existe este ID\n");
        }
        else
        {
            notebook[posicion].isEmpty=1;
            notebook[posicion].id=0;
            strcpy(notebook[posicion].modelo,"");
            notebook[posicion].precio = 0;
            notebook[posicion].idTipo = 0;
            notebook[posicion].idMarca = 0;
            retorno=0;
            printf("Se elimino correctamente\n");
        }
    }
    return retorno;
}
int modificarNotebook(nNotebook notebook[], int tam,eMarca marcas[],int tamMar,eTipo tipo[], int tamT,eCliente clientes[],int tamCli)
{
    int retorno=1;
    int posicion;
    int idNotebook;
    char opcion;

    if(notebook!=NULL && tam>0)
    {
        int i;
        listarNotebooks(notebook,tam,marcas, tamMar,tipo, tamT, clientes, tamCli);
        printf("ingrese la id de la notebook a modificar");
        scanf("%d",&idNotebook);
        i=buscarIdNotebook(notebook,tam,idNotebook,&posicion);
        if(i==1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                listarNotebooks(notebook,tam,marcas, tamMar,tipo, tamT, clientes, tamCli);
                printf("ingrese una opcion:\n a)- cambiar tipo\n b)- cambiar precio\n s)- salir\n");
                fflush(stdin);
                scanf("%c",&opcion);
                switch(opcion)
                {
                case 'a':
                    printf("ingrese el nuevo ID de tipo: ");
                    scanf("%d",&notebook[posicion].idTipo);

                    while(verificarIdTipo(tipo, TAMT, notebook[i].idTipo )== -1)
                    {
                        printf("ingrese una ID existente\n");
                        fflush(stdin);
                        scanf("%d",&notebook[i].idTipo);
                    }
                    system("pause");
                    break;

                case 'b':
                    printf("ingrese el nuevo precio: ");
                    scanf("%f",&notebook[posicion].precio);

                    while(notebook[posicion].precio < 0 )
                    {
                        printf("ingrese un precio positivo\n");
                        fflush(stdin);
                        scanf("%f",&notebook[posicion].precio);
                    }
                    system("pause");
                    break;

                case 's':
                    break;
                default:
                    printf("\nOpcion no valida");
                }
                system("cls");

            }
            while(opcion!='s');
            retorno=0;
        }
    }
    return retorno;
}
int verificarIdNotebook(nNotebook notebook[], int tam, int id)
{
    int retorno=1;
    for(int i = 0; i < tam; i++ )
    {
        if(notebook[i].id == id && notebook[i].isEmpty!=1)
        {
            retorno = 0;
        }
    }
    return retorno;
}
int buscarIdNotebook(nNotebook notebook[], int tam, int valorBuscado, int* posicion)
{
    int retorno=1;
    int i;
    if(notebook!= NULL && tam>=0)
    {
        for(i=0; i<tam; i++)
        {
            if(notebook[i].isEmpty==1)
                continue;
            else if(notebook[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int verificarArray(nNotebook notebook[], int tam)
{

    int contador = 0;

    for(int i = 0; i < tam; i++ )
    {
        if(notebook[i].isEmpty == 0)
        {
            contador++;
        }
    }
    return contador;

}
