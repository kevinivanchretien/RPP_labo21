#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"
#include "utn.h"


void iniciar_Fecha(struct fecha* pFecha,int tam)
{
    int i;
    if(pFecha!=NULL && tam>0)
        {
          for(i=0;i<tam;i++)
          {
              pFecha[i].isEmpty=0;
          }
        }
}

int cargar_Fecha(struct fecha* pFecha, int tam,int* id)
{
    int i;
    if(pFecha != NULL)
    {

        for(i=0; i<tam; i++)
        {
            if(pFecha[i].isEmpty==0)
            {
                pFecha[i].id=*id;
                pFecha[i].dia=utn_getNumero("Dia:","Ese dia no existe",31,1);
                pFecha[i].mes=utn_getNumero("Mes:","Ese mes no existe",12,1);
                pFecha[i].anio=utn_getNumero("Anio:","Ese anio no paso",2021,1810);
                pFecha[i].isEmpty=1;
                return 0;
            }
        }
    }

    return 0;
}

void mostrar_Fecha(struct fecha* pFecha,int tam,int id)
{
    int i;
    if(pFecha!=NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(pFecha[i].isEmpty==1)
            {
                if(pFecha[i].id==id)
                {
                    printf("\n Fecha: %d/%d/%d",pFecha[i].dia,
                           pFecha[i].mes,pFecha[i].anio);
                }
            }
        }
    }
}


