#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;
    int idPersona;

}EPersona;

int persona_init(EPersona* array,int limite);
int persona_alta(EPersona* array,int limite);
int persona_mostrar(EPersona* array,int limite);
int persona_baja(EPersona* array,int limite, int id);
int persona_ordenar(EPersona* array,int limite, int orden);
int persona_imprimir_grafico_edad(EPersona* array,int limite);
int buscarLugarLibre(EPersona* array,int limite);
int proximoId();
int limite_interno(EPersona* array,int limite);
int persona_altaForzada(EPersona* array,int limite,char* nombre,int edad,int dni);



#endif // FUNCIONES_H_INCLUDED
