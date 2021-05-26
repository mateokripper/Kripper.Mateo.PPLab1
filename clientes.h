#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{

    int id;
    char sexo;
    char nombre[20];

} eCliente;


#endif // CLIENTES_H_INCLUDED
void mostrarCliente(eCliente cliente);
void mostrarClientes (eCliente clientes[],int tamCli);
int cargarDescripcionCliente(char descripcion[],int id,eCliente clientes[],int tamCli);
