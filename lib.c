#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


void altaUsuario(eUsuario usuario, int id)
{
    char nombre[20];
    printf("Nombre: ");
    fflush(stdin);
    gets(nombre);
    strcpy(usuario.nombre, nombre);
    usuario.id = id;
    usuario.estado = 1;
}

void altaPublicacion()
{

}

int buscarIndexUsuario(eUsuario lista[], int id, int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[index].id == id && lista[index].estado != 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarIndexPublicacion(ePublicacion lista[], int id, int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[index].id == id && lista[index].estado != 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLibreUsuario(eUsuario lista[], int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}


void listarUsuarios(eUsuario lista[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 1)
            printf("%d -- %s -- %.2f", lista[i].id, lista[i].nombre, calcularPromedio(lista[i].calificaciones));
    }
}
void listarPublicaciones(ePublicacion lista[], int len) //le falta el nombre del usuario
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("%d -- %s -- %d -- %d -- %d", lista[i].id, lista[i].nombre, lista[i].stock, lista[i].vendidos, lista[i].precio);
    }
}

float calcularPromedio(int lista[20])
{
    int i;
    int cantidad = 0;
    int suma = 0;
    float promedio;
    for(i = 0; i < 20; i++)
    {
        if(lista[i] > 0)
        {
            cantidad++;
            suma++;
        }
    }
    promedio = suma / cantidad;
    return promedio;
}
