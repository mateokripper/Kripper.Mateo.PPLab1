#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    float precio;
} eServicios;
#endif // SERVICIOS_H_INCLUDED
void hardcodearServicios(eServicios servicios[], int tam);
/** \brief  Muestra todos los servicios con sus descripciones
 *
 * \param servicios[] eServicios vector a recorrer
 * \param tam int tamaño del vector
 * \return int
 *
 */
int listarServicios(eServicios servicios[], int tam);
