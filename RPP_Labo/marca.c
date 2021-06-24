#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "marca.h"

void hardcodear_Marcas(struct marca* pMarca)
{
    if(pMarca != NULL)
        {
            pMarca[0].id=1;
            strcpy(pMarca[0].marca,"Olmo");

            pMarca[1].id=2;
            strcpy(pMarca[1].marca,"Vairo");

            pMarca[2].id=3;
            strcpy(pMarca[2].marca,"Venzo");

            pMarca[3].id=4;
            strcpy(pMarca[3].marca,"Top Gama");

            pMarca[4].id=5;
            strcpy(pMarca[4].marca,"Trinx");

            pMarca[5].id=6;
            strcpy(pMarca[5].marca,"Otra");
        }
}


void mostrar_Marcas(struct marca* pMarca)
{
    int i;
    if(pMarca != NULL)
        {
            printf("\n    MARCAS");
            printf("\n  ID  | MARCAS");
            for(i=0;i<6;i++)
            {
                printf("\n  %d   | %s",pMarca[i].id, pMarca[i].marca);
            }
        }
}

int mostrar_Marca(struct marca* pMarca, int id)
{
    int i;
    if(pMarca != NULL)
        {
            for(i=0;i<6;i++)
            {
                if(pMarca[i].id==id)
                {
                    printf("Marca: %s",pMarca[i].marca);
                }
            }
        }
    return 0;
}

int buscar_idMarca(struct marca* pMarca, int id)
{
    int i;
    int posicion= -1;
    if(pMarca != NULL)
        {
            for(i=0;i<6;i++)
            {
                if(pMarca[i].id==id)
                {
                    posicion=i;
                    break;
                }
            }
        }
    return posicion;
}

void devolver_Marca(struct marca* pMarca, int id,char marca[])
{
    int i;
    if(pMarca != NULL)
        {
            for(i=0;i<6;i++)
            {
                if(pMarca[i].id==id)
                {
                   strcpy(marca,pMarca[i].marca);
                }
            }
        }
}
