#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"

int utn_getNumero(char* msje,char* msjeError,int max,int min)
{
    int numero=0;
    int intento=3;

    if(msje!=NULL && msjeError != NULL)
    {
        do
        {
            printf("\n%s",msje);
            fflush(stdin);
            scanf("%d",&numero);

            if(validar_getNumero(numero,max,min)!=0)
            {
                printf("\n%s",msjeError);
                intento++;
            }
            else
                {
                    break;
                }
        }
        while(intento>0);
        }
    return numero;
}

int validar_getNumero(int num, int max, int min)
{
    int retorna =-1;

    if(num <= max && num >= min)
    {
        retorna=0;
    }
    return retorna;
}
