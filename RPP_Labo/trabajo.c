#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "trabajo.h"
#include "fecha.h"
#include "marca.h"
#include "servicios.h"
#include "utn.h"



void iniciar_Trabajo(struct trabajo* pTrabajo, int tam)
{
    int i;
    if(pTrabajo != NULL)
    {
        for(i=0; i<tam; i++)
        {
            pTrabajo[i].isEmpty=0;
        }
    }
}

int buscar_isEmpty(struct trabajo* pTrabajo, int tam)//[
{
    int i;
    int vacio=-1;
    if(pTrabajo != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(pTrabajo[i].isEmpty==0)
            {
                vacio=i;
                break;
            }
        }
    }
    return vacio;
}

void informar_Rodado()
{
    printf("\n\nRodados de Bicicletas: \n");
    printf("\nRodado | anios | altura");
    printf("\n  12   | 2-4   | 70-85cm");
    printf("\n  14   | 3-5   | 85-100cm");
    printf("\n  16   | 4-6   | 100-110cm");
    printf("\n  20   | 6-10  | 110-140cm");
    printf("\n  24   | 9-12  | 140-160cm");
    printf("\n  26   | +12   | mas de 160cm");
    printf("\n  27   | +15   | mas de 160cm");
    printf("\n  29   |       | mas de 160cm");

}

int cargar_Trabajos(struct trabajo* pTrabajo,int tam,int* id,struct fecha* pFecha)//[
{
    int retorno=-1;
    int indice=-1;

    struct marca pMarca[6];
    struct servicios pServicio[4];

    int idMarca=0;
    char marca[25];

    int idServicio=0;
    char servicio[25];

    int rodado=0;

    if(pTrabajo!= NULL)
    {
        indice=buscar_isEmpty(pTrabajo,tam);
        if(indice>=0)
        {
            printf("\nSe encontro un lugar libre");

            hardcodear_Marcas(pMarca);
            hardcodeo_Servicios(pServicio);

            //cargar id
            *id=*id+1;//idAutoincremental
            printf("\nid= %d",*id);

            //cargar marca
            mostrar_Marcas(pMarca);//muestro Marcas
            idMarca=utn_getNumero("Ingrese id de la Marca: ","Ese id no existe",6,1);
            devolver_Marca(pMarca,idMarca,marca);

            //cargar rodado
            informar_Rodado();
            pTrabajo[indice].rodado=rodado=utn_getNumero("Especifique el rodado: ","Ese rodado no existe",29,12);

            //cargar SERVICIO
            mostrar_Servicios(pServicio);
            idServicio=utn_getNumero("Ingrese codigo del servicio: ","Error",20003,20000);
            devolver_Servicio(pServicio,idServicio,servicio);

            cargar_Fecha(pFecha,tam,id);
            mostrar_Fecha(pFecha,tam,*id);


            mostrar_Trabajos(pTrabajo,3,pFecha,marca,servicio);

            pTrabajo[indice].id=*id;
            pTrabajo[indice].marcaBici=idMarca;
            pTrabajo[indice].rodado=rodado;
            pTrabajo[indice].servicio=idServicio;
            pTrabajo[indice].idfecha=*id;
            pTrabajo[indice].isEmpty=1;
        }
        else
        {
            printf("No hay mas lugares libres");
        }
    }
    return retorno;
}



void mostrar_Trabajos(struct trabajo* pTrabajo,int tam,struct fecha* pFecha,char marca[],char servis[])
{
    int i;

    if(pTrabajo!=NULL && pFecha != NULL)
    {


        for(i=0; i<tam; i++)
        {
            if(pTrabajo[i].isEmpty==1)
            {
                //devolver_Marca(pMarca,(pTrabajo[i].marcaBici),marca);
                //devolver_Servicio(pServicio,(pTrabajo[i].servicio),servis);

                printf("\nID: %d",pTrabajo[i].id);
                printf("\nMarca: %s",marca);
                printf("\nRodado: %d",pTrabajo[i].rodado);
                printf("\nServis: %s",servis);
                //mostrar_Fecha(pFecha,tam,(pTrabajo[i].id));variable pservicio is uninitialized when use here


            }
        }
    }
}

/*
void modificarMarca(struct trabajo* pTrabajo,struct marca* pMarca,int num)
{
    int i;
    int auxId=0;
    int nuevoId=0;
    char nuevaMarca[25];
    char marca[25];
    if(pTrabajo!=NULL && pMarca != NULL)
    {
        printf("ingrese id a modificar: ");
        fflush(stdin);
        scanf("%d",&auxId);
        for(i=0; i<num; i++)
        {
            if(pTrabajo[i].isEmpty==1 && pTrabajo[i].id==auxId)
            {
                devolver_Marca(pMarca,auxId,marca);
                printf("\n Id | Marca");
                printf("\n %d | %s",auxId,marca);

                mostrar_Marcas(pMarca);
                nuevoId=utn_getNumero("Ingrese id de la Marca: ","Ese id no existe",6,1);

                pTrabajo[i].marcaBici=nuevoId;
            }
        }

    }

}
*/

int baja_Trabajo(struct trabajo* pTrabajo,int tam)
{
    int i,id;
    int retorno=-1;
    if(pTrabajo!= NULL && tam >0)
       {
           printf("Ingrese id a dar debaja:");
            fflush(stdin);
            scanf("%d",&id);
          for(i=0;i>tam;i++)
          {
              if(pTrabajo[i].id==id)
              {
                  pTrabajo[i].isEmpty==0;
                  retorno=0;
              }
          }
       }
    return retorno;
}
