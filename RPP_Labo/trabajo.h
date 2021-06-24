#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"

struct trabajo
{
    int id;                 //autoincremental
    int marcaBici;          //traer desde su estructura
    int rodado;             //Mostrar los 8 tipos de rodado.
    int servicio;        //traer desde su estructura.
    int idfecha;
    int isEmpty;

};

#endif // TRABAJO_H_INCLUDED


/** \brief Inicializa el campo isEmpty en 0
 *
 * \param pTrabajo struct trabajo* || puntero a estructura
 * \param tam int || tama–o de la estructura
 * \return void
 *
 */
void iniciar_Trabajo(struct trabajo* pTrabajo, int tam);

int buscar_isEmpty(struct trabajo* pTrabajo, int tam);

int cargar_Trabajos(struct trabajo* pTrabajo,int tam,int* id, struct fecha* pFecha);

void mostrar_Trabajos(struct trabajo* pTrabajo,int tam,struct fecha* pFecha,char marca[],char servis[]);

//void modificarMarca(struct trabajo* pTrabajo,struct marca* pMarca,int num);


int baja_Trabajo(struct trabajo* pTrabajo,int tam);

