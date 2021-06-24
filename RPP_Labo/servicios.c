#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicios.h"



void hardcodeo_Servicios(struct servicios* this)
{
    if(this!= NULL)
    {

        this[0].id=20000;
        strcpy(this[0].descripcion,"Limpieza");
        this[0].precio=250;

        this[1].id=20001;
        strcpy(this[1].descripcion,"Parche");
        this[1].precio=300;

        this[2].id=20002;
        strcpy(this[2].descripcion,"Centrado");
        this[2].precio=400;

        this[3].id=20003;
        strcpy(this[3].descripcion,"Cadena");
        this[3].precio=350;

    }

}

void mostrar_Servicios(struct servicios* this)
{
    int i;
    if(this != NULL)
        printf("\n      SERVICIOS\n");
    printf("|  ID   | Servicio: Precio   \n");

    for (i=0; i<4; i++)
    {

        printf("| %d | %s: $%d  \n", this[i].id, this[i].descripcion, this[i].precio);
    }
}


void mostrar_unServicio(struct servicios* pServicio, int id)
{

    int posicion=-1;
    if(pServicio!=NULL)
    {
        posicion=buscar_idServicio(pServicio,id);
        printf("Servicio: %s",pServicio[posicion].descripcion);
    }
}


int buscar_idServicio(struct servicios* pServicio,int id)
{
    int i;
    int posicion=-1;
    if(pServicio!=NULL && id<=20003 && id>=2000)
    {
        for(i=0; i<4; i++)
        {
            if(pServicio[i].id==id)
            {
                posicion=i;
                break;
            }
        }
    }
    return posicion;
}


void devolver_Servicio(struct servicios* pServicio, int id,char servicio[])
{
    int i;
    if(pServicio!=NULL)
    {
        for(i=0; i<4; i++)
        {
            if(pServicio[i].id==id)
            {
                strcpy(servicio,pServicio[i].descripcion);
            }
        }
    }

}
