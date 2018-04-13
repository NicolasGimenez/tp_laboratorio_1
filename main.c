#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funciones.h"
/** Nicolas Gimenez.**/

int main()
{
    char seguir='s';
    int opcion=0;
    float primerOperando;
    float segundoOperando;
    int contador=0;
    int banderaUno;
    int banderaDos;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factorial;

    while(seguir=='s')
    {   if(contador==0)
        {
            primerOperando=0;
            segundoOperando=0;
            contador= contador + 1;
        }
        printf("---CALCULADORA---\n\n");
        printf("1- Ingresar 1er operando (A=%.2f )\n",primerOperando);
        printf("2- Ingresar 2do operando (B=%.2f )\n",segundoOperando);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    printf("ingrese el primer operando \n ");
                    scanf("%f",&primerOperando);
                    printf("\n");
                    banderaUno=1;
                    break;
            case 2:
                    printf("ingrese el segundo operando \n ");
                    scanf("%f",&segundoOperando);
                    printf("\n");
                    banderaDos=1;
                    break;
            case 3:
                    if(banderaUno == 1 && banderaDos == 1)
                    {
                        if(sumaOperandos (primerOperando,segundoOperando,&suma)==0)
                        {
                            printf("El resultado de la suma es : %.2f \n\n",suma);
                        }else
                        {
                            printf("\n Error la suma supera el limite \n\n");

                        }
                    }else
                    {
                        printf("error uno de los operandos no esta cargado!!\n\n ");
                    }

                    break;
            case 4:
                    if(banderaUno == 1 && banderaDos == 1)
                    {
                        if(restaOperandos (primerOperando,segundoOperando,&resta)==0)
                        {
                            printf("El resultado de la resta es : %.2f \n\n",resta);
                        }else
                        {
                            printf("Error la resta supera el limite \n\n");
                        }
                    }else
                    {
                        printf("Error uno de los operandos no esta cargado \n\n");
                    }

                break;
            case 5:
                    if(divisionOperandos (primerOperando,segundoOperando,&division)==0)
                    {
                        printf("El resultado de la division es : %.2f \n\n",division);
                    }else
                    {
                       printf("Error no se puede dividir por cero!! \n\n");
                    }
                    break;
            case 6:
                    if(banderaUno == 1 && banderaDos == 1)
                    {
                        if(multiplicacionOperandos (primerOperando,segundoOperando,&multiplicacion)==0)
                        {
                            printf("El resultado de la multiplicacion es : %.2f \n\n",multiplicacion);
                        }else
                        {
                            printf("Error la multiplicacion supera el limite \n\n");
                        }
                    }else
                    {
                        printf("Error uno de los operandos no esta cargado \n\n");
                    }

                    break;
            case 7:
                    if(banderaUno == 1)
                    {
                        if(factorialOperando(primerOperando,&factorial)==0)
                        {
                            printf("El factorial de %.2f es %.2f \n\n",primerOperando,factorial);
                        }else
                        {
                            printf("Error ingresaste numero negativo o superaste el limite del factorial--\n\n");
                        }
                    }
                    else
                    {
                        printf("Error comando no ingresado\n");
                    }
                        break;
            case 8:
                    if(banderaUno == 1 && banderaDos == 1)
                    {
                        todasLasOperaciones(primerOperando,segundoOperando);
                    }
                    else
                    {
                        printf("Error uno de los operandos no esta cargado \n\n");
                    }

                    break;
            case 9:
                    seguir = 'n';
                    break;
            default:
                    printf(" Error Ingrese la opcion de 1 a 9 \n");
                    break;

         }


     }


    return 0;
}
