#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funciones.h"
#define SIZE 20

/**  TRABAJO PRACTICO Nº2
NICOLAS GIMENEZ  1ºE
*/
int main()
{
    char seguir='s';
    int auxiliarId;
    int menu;
    EPersona persona[SIZE];

    persona_init(persona,SIZE);
    persona_altaForzada(persona,SIZE,"nicolas",21,39711301);
    persona_altaForzada(persona,SIZE,"carlos",57,96311301);
    persona_altaForzada(persona,SIZE,"ignacio",12,12311301);
    persona_altaForzada(persona,SIZE,"julian",25,98741301);
    persona_altaForzada(persona,SIZE,"pepe",30,39716411);
    persona_altaForzada(persona,SIZE,"alberto",57,85101301);
    persona_altaForzada(persona,SIZE,"rodrigo",10,36941301);
    persona_altaForzada(persona,SIZE,"leonel",5,15211301);
    persona_altaForzada(persona,SIZE,"adrian",65,39513301);
    printf("--TRABAJO PRACTICO Nº2--\n");

    while(seguir=='s')
    {
        getValidInt("1.Agregar una persona\n2.Borrar una persona\n3.Imprimir lista ordenada por nombre\n4.Imprimir grafico de edades\n5.Salir\n","\nopcion invalida\n",&menu,1,5,1);
        fflush(stdin);
        switch(menu)
        {
            case 1:
                    if(persona_alta(persona,SIZE)== -2)
                    {
                        printf("!!ALERTA!!\n");
                        printf("no hay mas espacio para agragar personas\n");
                    }
                    break;
            case 2:
                    getValidInt("Ingrese el id de la persona que desea borrar","\n id invalido\n",&auxiliarId,0,999999999,2);
                    if(persona_baja(persona,SIZE,auxiliarId)!= 0)
                    {
                        printf("id no valido\n");
                    }
                    break;
            case 3:
                    persona_ordenar(persona,SIZE,1);
                    persona_mostrar(persona,SIZE);
                    break;
            case 4:
                    persona_imprimir_grafico_edad(persona,SIZE);
                    break;
            case 5:
                    seguir = 'n';
                    break;

        }
    }

    return 0;
}
