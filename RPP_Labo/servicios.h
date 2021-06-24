#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct servicios //HARDCODEAR
{
    int id; //autoincremental.
    char descripcion[25];
    int precio;
};

#endif // SERVICIOS_H_INCLUDED


/** \brief Carga la estructura de servicios
 *
 * \param this struct servicios* Recibe un puntero a la estructura Servicios
 *
 */
void hardcodeo_Servicios(struct servicios* this);




/** \brief Muestra por pantalla los datos ingresados en la estructura Servicios
 *
 * \param this struct servicios* Recibe un punter a estructura de servicios.
 * \param tam int reciebe el tama–o de la estructura.
 * \return void
 *
 */
void mostrar_unServicio(struct servicios* this,int id);

void informar_Rodado();



int buscar_idServicio(struct servicios* pServicio,int id);

void mostrar_Servicios(struct servicios* this);

void devolver_Servicio(struct servicios* pServicio, int id,char servicio[]);

