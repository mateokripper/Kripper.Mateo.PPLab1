#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"
#include "notebook.h"
#include "marcas.h"
#include "tipos.h"
#include "trabajo.h"
#include "clientes.h"
#include "informes.h"
#define TAMN 4
#define TAMTR 2
#define TAMT 4
#define TAMMA 4
#define TAMS 4
#define TAMCLIENTES 10

int menu();

int main()
{

    char salir = 'n';
    int idTrabajador=0;
    nNotebook notebook[TAMN];
    eTipo tipo[TAMT];
    eMarca marca[TAMMA];
    eServicios servicio[TAMS];
    eTrabajo trabajo[TAMTR];
    eCliente clientes [TAMCLIENTES];

    int flag=0;

    inicializarNotebooks(notebook,TAMN);
    inicializarTrabajo(trabajo,TAMTR);
    hardcodearTipo(tipo,TAMT);
    hardcodearMarcas(marca,TAMMA);
    hardcodearServicios(servicio,TAMS);

    do
    {

        system ("cls");

        switch(menu())
        {
        case 1:
            system ("cls");
            altaNotebook(notebook, TAMN,marca, TAMMA, tipo, TAMT,clientes,TAMCLIENTES);
            flag = 1;
            break;
        case 2:
            system ("cls");
            if (flag==1)
            {
                modificarNotebook(notebook,TAMN,marca, TAMMA,tipo,TAMT, clientes,TAMCLIENTES);
            }
            else
            {
                printf("No se puede modificar sin dar alta una notebook\n");
            }
            break;
        case 3:
            system ("cls");
            if (flag==1)
            {
                bajaNotebook(notebook,TAMN,marca, TAMMA,tipo,TAMT, clientes, TAMCLIENTES);
            }
            else
            {
                printf("No se puede dar de baja sin antes dar de alta una notebook\n");
            }

            break;
        case 4:
            system ("cls");
            if(flag==1)
            {
                listarNotebooks(notebook,TAMN,marca, TAMMA,tipo,TAMT,clientes,TAMCLIENTES);

            }
            else
            {
                printf("No se puede listar sin antes dar de alta una notebook\n");
            }
            break;

        case 5:
            listarMarcas(marca,TAMMA);

            break;
        case 6:
            system ("cls");
            listarTipo(tipo,TAMT);
            break;
        case 7:
            system ("cls");
            listarServicios(servicio,TAMS);
            break;
        case 8:
            system ("cls");
            if (flag==1)
            {
                altaTrabajo(trabajo,TAMTR,notebook,TAMN,marca, TAMMA,tipo,TAMT,&idTrabajador, clientes,TAMCLIENTES);
            }
            else
            {
                printf("No se puede dar de alta empleado sin antes haber ingresado notebook\n");
            }
            break;
        case 9:
            system ("cls");
            listarTrabajos(trabajo,TAMTR);
            break;
        case 10:
            system ("cls");
            if (flag==1)
            {
                mostrarInformes(notebook,TAMN,marca, TAMMA,tipo,TAMT,clientes,TAMCLIENTES,trabajo,TAMTR);
            }
            else
            {
                printf("No se ingresaron notebooks, no hay informes\n");
            }
            break;
        case 11:
            printf("Confirma salida?\n");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("Opcion invalida \n");
            system ("pause");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}
int menu()
{
    int opcion;
    printf(" *** ABM NOTEBOOK ***\n");
    printf("1. ALTA NOTEBOOK\n");
    printf("2. MODIFICAR NOTEBOOK \n");
    printf("3. BAJA NOTEBOOK\n");
    printf("4. LISTAR NOTEBOOK \n");
    printf("5. LISTAR MARCAS\n");
    printf("6. LISTAR TIPOS\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. INFORMES\n");
    printf("11. SALIR \n");
    printf(" \n Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

