#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

/** \brief inicializa el estado en vacio
 *
 * \param array EPersona* el array de la estructura persona
 * \param limite int el limite del array
 * \return int 0 si lo hizo -1 si no
 *
 */
int persona_init(EPersona* array, int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].estado = 1;
        }
    }
    return retorno;
}
/** \brief da el alta a una persona
 *
 * \param array EPersona*el array de la estructura persona
 * \param limite int el limite del array
 * \return int 0 si lo hizo -1 si no
 *
 */
int persona_alta( EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    char nombreAux[50];
    int edadAux;
    int dniAux;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nIngrese nombre ","\nEso no es un nombre\n","El maximo son 50 caracteres\n",nombreAux,50,3))
            {
                if(getValidInt("\nIngrese edad ","\nEdad no valida\n",&edadAux,1,120,3) == 0)
                {
                    if(getValidInt("\nIngrese DNI ","\nDNI no valida\n",&dniAux,1,99999999,3) == 0)
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombreAux);
                        array[i].edad = edadAux;
                        array[i].dni = dniAux;
                        array[i].idPersona = proximoId();
                        array[i].estado = 0;
                    }
                    else
                    {
                    retorno = -3;
                }

                }
                else
                {
                    retorno = -3;
                }
            }
            else
            {
                retorno = -4;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}
/** \brief busca un lugar libre
 *
 * \param array EPersona*el array de la estructura persona
 * \param limite int el limite del array
 * \return int 0 si lo hizo -1 si no
 *
 */
int buscarLugarLibre(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].estado==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief genera un unico y irrepetible id
 *
 * \return int el id
 *
 */
int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
/** \brief imprime datos de los usuarios
 *
 * \param array EPersona*el array de la estructura persona
 * \param limite int el limite del array
 * \return int 0 si lo hizo -1 si no
 *
 */
int persona_mostrar(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    printf("| NOMBRE  |EDAD|DNI     |NUMERO ID|\n");
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado)
            {
                printf("| %s | %d |%d| %d |\n", array[i].nombre,array[i].edad,array[i].dni,array[i].idPersona);
            }
        }
    }
    return retorno;
}
/** \brief imprime un grafico de asteriscos
 *
 * \param array EPersona*el array de la estructura persona
 * \param limite int el limite del array
 * \return int int 0 si lo hizo -1 si no
 *
 */
int persona_imprimir_grafico_edad(EPersona* array,int limite)
{
    int i;
    int j;
    int limiteMenores = 0;
    int limiteIntermedio = 0;
    int limiteMayores = 0;
    int limiteAux = 0;
    int contador[3];
    int retorno = -1;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(array[i].edad <= 18 && array[i].edad >0 && array[i].estado == 0)
            {
                limiteMenores=limiteMenores+1;
            }
            if(array[i].edad > 18 && array[i].edad <=35 && array[i].estado == 0)
            {
                limiteIntermedio=limiteIntermedio+1;
            }
            if(array[i].edad > 35 && array[i].estado == 0)
            {
                limiteMayores=limiteMayores+1;
            }
        }
            printf("----GRAFICO DE EDADES----\n");
            contador[0]=limiteMenores;
            contador[1]=limiteIntermedio;
            contador[2]=limiteMayores;
            if(contador[0]>contador[1] && contador[0]>contador[2])
            {
                limiteAux = contador[0];
            }
            else
            {
                if(contador[1]>contador[0] && contador[1]>contador[2])
                {
                    limiteAux = contador[1];
                }
                else
                {
                    limiteAux = contador[2];
                }
            }
            for(i=limiteAux;i>0;i--)
            {
                for(j=0;j<3;j++)
                {
                    if(i<=contador[j])
                    {
                        printf("  *   ");
                    }
                    else
                    {
                        printf("      ");
                    }
                }
                printf("\n");
            }
            printf("  <15__19-35__>35\n");
            printf("   %d    %d      %d ",limiteMenores,limiteIntermedio,limiteMayores);
            printf("CANTIDAD DE PERSONAS\n");
    }
    return retorno;
}
/** \brief da de baja una persona
 *
 * \param array EPersona*el array de la estructura persona
 * \param limite int el limite del array
 * \return int int 0 si lo hizo -1 si no
 *
 */
int persona_baja(EPersona* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado && array[i].idPersona==id)
            {
                array[i].estado = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/** \brief ordena por nombre las personas
 *
 * \param limite del array
 * \param orden del ordenamiento decendente acendente
 * \return int int 0 si lo hizo -1 si no
 *
 */

int persona_ordenar(EPersona* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    EPersona auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].estado && !array[i+1].estado)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
/** \brief genera un alta de personas
 *
 * \param array EPersona* array de la estructura
 * \param limite int limite del array
 * \param nombre char*
 * \param edad int
 * \param dni int
 * \return int int int 0 si lo hizo -1 si no
 *
 */
int persona_altaForzada(EPersona* array,int limite,char* nombre,int edad,int dni)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            array[i].edad = edad;
            array[i].dni = dni;
            //------------------------------
            //------------------------------
            array[i].idPersona = proximoId();
            array[i].estado = 0;
        }
        retorno = 0;
    }
    return retorno;
}
