#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct fecha
{
    int id;
    int dia;
    int mes;
    int anio;
    int isEmpty;
};

#endif // FECHA_H_INCLUDED
void iniciar_Fecha(struct fecha* pFecha,int tam);

int cargar_Fecha(struct fecha* pFecha, int tam,int* id);

void mostrar_Fecha(struct fecha* pFecha,int tam,int id);
