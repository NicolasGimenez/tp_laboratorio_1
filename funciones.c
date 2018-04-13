#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funciones.h"

/** \brief Suma dos numeros y devuelve el resultado.
 *
 * \param los numeros A y B que seran sumados.
 * \param devuelve el resultado por puntero
 * \return retorna un -1 o 0 dependiendo si esta bien la operacion
 *
 */
int sumaOperandos (float primerOperando, float segundoOperando,float *suma)
{
    double sumaAuxiliar;
    int retorno = -1;
    sumaAuxiliar= primerOperando + segundoOperando;
    if(sumaAuxiliar < INT_MAX)
    {
        *suma = sumaAuxiliar;
        retorno=0;
    }
    return retorno;
}
/** \brief Resta dos numeros y devuelve el resultado.
 *
 * \param Los numeros A y B que seran restados.
 * \param Devuelve el resultado por puntero.
 * \return Retorna un -1 o 0 dependiendo si esta bien la operacion
 *
 */
int restaOperandos (float primerOperando, float segundoOperando,float * resta)
{
    double restaAuxiliar;
    int retorno = -1;
    restaAuxiliar= primerOperando - segundoOperando;
    if(restaAuxiliar > INT_MIN && restaAuxiliar < INT_MAX)
    {
        *resta = restaAuxiliar;
        retorno = 0;
    }
    return retorno;
}
/** \brief Divide dos numeros y devuelve el resultado.
 *
 * \param Los numeros A y B que seran divididos.
 * \param Devuelve el resultado por puntero.
 * \return Retorna un -1 o 0 dependiendo si esta bien la operacion.
 *
 */
int divisionOperandos (float primerOperando, float segundoOperando,float * division)
{
    int retorno = -1;

    if(segundoOperando != 0)
    {
        *division = primerOperando / segundoOperando;

        retorno = 0;
    }
    return retorno;
}
/** \brief Multiplica dos numeros y devuelve el resultado.
 *
 * \param Los numeros A y B que seran multiplicados.
 * \param Devuelve el resultado por puntero.
 * \return Retorna un -1 o 0 dependiendo si esta bien la operacion.
 *
 */
int multiplicacionOperandos (float primerOperando, float segundoOperando, float *multiplicacion)
{
    double multiplicacionAuxiliar;
    int retorno = -1;

    multiplicacionAuxiliar = primerOperando * segundoOperando;

    if(multiplicacionAuxiliar < INT_MAX)
    {
        *multiplicacion = multiplicacionAuxiliar;
        retorno = 0;
    }
    return retorno;
}
/** \brief Realiza el factorial de un numero y devuelve el resultado
 *
 * \param Al numero A se le realiza el factoreo.
 * \param Devuelve el resultado por puntero.
 * \return Retorna un -1 o 0 dependiendo si esta bien la operacion.
 *
 */

int factorialOperando (float primerOperando,float *factorial)
{
    float factorialAuxiliar = 1;
    int retorno = -1;
    int i;
    if(primerOperando > 0 && primerOperando < 13)
     {
        for(i=1; i <= primerOperando; i++)
        {
            factorialAuxiliar= factorialAuxiliar * i;
            *factorial= (float)factorialAuxiliar;
            retorno = 0;
        }
     }
    return retorno;
}
/** \brief Realiza todas las funciones sumar restar multiplicar dividir y factorizar un numero y imprime los resultados.
 *
 * \param Se aplican todas las operaciones a los numeros A y B.
 * \param imprime los resultados.
 * \return Retorna un -1 o 0 dependiendo si esta bien la operacion.
 *
 */
int todasLasOperaciones(float primerOperando,float segundoOperando)
{
        float suma;
        float resta;
        float division;
        float multiplicacion;
        float factorial;
        int retorno = -1;

        if(primerOperando !=0 && segundoOperando !=0)
        {

            sumaOperandos (primerOperando,segundoOperando,&suma);
            restaOperandos (primerOperando,segundoOperando,&resta);
            divisionOperandos (primerOperando,segundoOperando,&division);
            multiplicacionOperandos (primerOperando,segundoOperando,&multiplicacion);
            factorialOperando (primerOperando,&factorial);
            if(factorialOperando (primerOperando,&factorial)==0)
            {
               printf("El factorial de %.2f es %.2f \n\n",primerOperando,factorial);
            }
            else
            {
                 printf("Error ingresaste numero negativo o superaste el limite del factorial--\n\n");
            }

            if(sumaOperandos (primerOperando,segundoOperando,&suma)==0 && restaOperandos (primerOperando,segundoOperando,&resta)==0 && divisionOperandos (primerOperando,segundoOperando,&division)==0 && multiplicacionOperandos (primerOperando,segundoOperando,&multiplicacion)==0 )
            {
                    printf("El resultado de la suma es : %.2f \n\n",suma);
                    printf("El resultado de la resta es : %.2f \n\n",resta);
                    printf("El resultado de la division es : %.2f \n\n",division);
                    printf("El resultado de la multiplicacion es : %.2f \n\n",multiplicacion);
                    retorno = 0;

            }
        }else
        {
            printf("Error uno de los operandos no esta cargado \n\n");
        }
        return retorno;

}
