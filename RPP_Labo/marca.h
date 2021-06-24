#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED



struct marca
{
    int id;
    char marca[25];
};


#endif // MARCA_H_INCLUDED

/** \brief Hardcodea la estructura
 *
 * \param recibe el puntero a la estructura marca,
 * \param y carga los datos
 * \return
 *
 */

void hardcodear_Marcas(struct marca* pMarca);


/** \brief Muestra todas las Marcas de la estructura
 *
 * \param pMarca struct marca*
 * \param tam int
 * \return void
 *
 */
void mostrar_Marcas(struct marca* pMarca);


/** \brief Muestra la Marca pedida por id
 *
 * \param pMarca struct marca*
 * \param id int
 * \return int
 *
 */
int mostrar_Marca(struct marca* pMarca, int id);


/** \brief Guarda la posicion de un id.
 *
 * \param pMarca struct marca*
 * \param id int
 * \return int
 *
 */
int buscar_idMarca(struct marca* pMarca, int id);

void devolver_Marca(struct marca* pMarca, int id,char marca[]);
