#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fecha.h"
#include "servicios.h"
#include "marca.h"
#include "trabajo.h"
#include "utn.h"




int main()
{
    int opcion=0;
    int flag=-1;
    int id=0;
    int submenu=0;


    struct servicios eServicios [4];//={{20000,"Limpieza",250},{20001,"Parche",300},{20002,"Centrado",400},{20003,"Cadena",350}};
    struct marca eMarca[6];
    struct trabajo eTrabajo[30];
    struct fecha eFecha[30];


    hardcodeo_Servicios(eServicios);//HARCODEO SERVICIOS.
    hardcodear_Marcas(eMarca);      //HARDCODEO MARCAS.
    iniciar_Trabajo(eTrabajo,3);    // HARDCODEO CAMPO isEmpty en 0.
    iniciar_Fecha(eFecha,3);        //campo isEmppty en 0.          cambiar 3 por tam.

    //todo fuera del do-while para que solo sea una vez.
    system("CLEAR");
    do
    {
        //system("CLEAR");//no sirve el CLS en MAC
        //system("CLS");
        printf("\n\n------MENU-----\n\n");
        printf("\n1-ALTA");
        printf("\n2-MODIFICAR.(agregar un submenu)");
        printf("\n3-BAJA");
        printf("\n4-LISTAR TRABAJOS");
        printf("\n5-LISTAR SERVICIOS");
        printf("\n6-TOTAL (en pesos por los servicios prestados)");
        printf("\n7-INFORMES.");
        printf("\n8-SALIR.");

        printf("\n\nSu Opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);



        switch(opcion)
        {
        case 1:
            system("CLEAR");
            printf("\n ingreso al alta\n");
            cargar_Trabajos(eTrabajo,3,&id,eFecha);
            flag=0;//poner en un if si se pudo cargar
            opcion=0;
            break;
        case 2:
            if(flag==0)
            {
                printf("\n \nQue desea MODIFICAR?");
                printf("\n1-Modificar Marca.");
                printf("\n2-Modificar Servis.");
                printf("\n3-Volver al menu principal");
                submenu=utn_getNumero("Opcion: ","Error",3,1);
                switch(submenu)
                {
                case 1:
                    //modificarMarca(eTrabajo,eMarca,30);
                    //AVERIGUAR PORQUE NO ME DEJA PASAR LA ESTRUCTURA MARCA COMO PARAMETRO :'/
                    break;
                case 2://parecido a marca pero cambiando el id de Servicios.
                    break;
                default:
                    printf("\nvolver al menu principal");
                    break;
                }
            }
            else
            {
                printf("\nPrimero debe ingresar un trabajo.");

                if(baja_Trabajo(eTrabajo,30)==0)
                {
                    printf("\nSe dio de baja el usuario");
                }

                system("pause");
            }
            opcion=0;
            break;
        case 3:
            if(flag==0)
            {
                printf("\n ESTA EN BAJA: ");
            }
            else
            {
                printf("\nPrimero debe ingresar un trabajo");
                system("pause");
            }
            opcion=0;
            break;

        case 4:
            if(flag==0)
            {
                printf("\n LISTAR TRABAJOS");

                //mostrar_Trabajos(eTrabajo,3,eFecha,eMarca,eServicios);
            }
            else
            {
                printf("Primero debe ingresar una alta.");
                system("pause");
            }
            opcion=0;
            break;
        case 5:
            if(flag==0)
            {
                printf("\n LISTAR SERVICIOS\n");
            }
            else
            {
                printf("Primero debe ingresar una alta.");
                system("pause");
            }
            mostrar_Servicios(eServicios);
            system("pause");
            opcion=0;
            //opcion=0;
            break;
        case 6:
            if(flag==0)
            {
                printf("\n MOSTRAR TOTAL: ");
            }
            else
            {
                printf("No hay nada ingresado para calcular");
                system("pause");
            }
            opcion=0;
            break;
        case 7:
            if(flag==0)
            {
                printf("\n Informes: ");
                /**MUESVOS INFORMES:
                1- listado de todos los trabajos ordenados por marca de la bicicleta
                2- el o los servicios con mas trabajos realizados.
                **/

            }
            else
            {
                printf("No se puede informar nada si no hay datos ingresados");
                system("pause");
            }
            opcion=0;
        case 8:
            printf("chau");
            opcion=-1;
            break;

        default:
            printf("\n\n OPCION ELEGIDA NO VALIDA");
            opcion=0;

            break;
        }
        //opcion=0;
    }

    while(opcion==0);

    return 0;
}
