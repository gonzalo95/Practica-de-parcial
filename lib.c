#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


eUsuario altaUsuario(int id)
{
    eUsuario nuevoUsuario;

    char nombre[20];
    printf("Nombre: ");
    fflush(stdin);
    gets(nombre);
    strcpy(nuevoUsuario.nombre, nombre);

    char pass[20];
    printf("Pass: ");
    fflush(stdin);
    gets(pass);
    strcpy(nuevoUsuario.pass, pass);

    nuevoUsuario.id = id;
    nuevoUsuario.estado = 1;

    inicializar(nuevoUsuario.calificaciones);
    inicializar(nuevoUsuario.publicaciones);

    return nuevoUsuario;
}

ePublicacion altaPublicacion(int idPublicacion, int idUsuario)
{
    ePublicacion nuevaPublicacion;

    nuevaPublicacion.id = idPublicacion;
    nuevaPublicacion.idUsuario = idUsuario;
    nuevaPublicacion.estado = 1;
    nuevaPublicacion.vendidos = 0;

    char nombre[20];
    printf("Nombre: ");
    fflush(stdin);
    gets(nombre);
    strcpy(nuevaPublicacion.nombre, nombre);

    float precio;
    printf("Precio: ");
    scanf("%f", &precio);
    nuevaPublicacion.precio = precio;

    int stock;
    printf("Stock: ");
    scanf("%d", &stock);
    nuevaPublicacion.stock = stock;

    return nuevaPublicacion;
}

int buscarIndexUsuario(eUsuario lista[], int id, int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].id == id && lista[i].estado != 0)
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

int buscarLibrePublicacion(ePublicacion lista[], int len)
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
    float promedio;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 1)
        {
            promedio = calcularPromedio(lista[i].calificaciones);
            printf("%d -- %s -- %.2f\n", lista[i].id, lista[i].nombre, promedio);
        }

    }
}
void listarPublicaciones(ePublicacion lista[], int len) //le falta el nombre del usuario
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 1)
            printf("%d -- %s -- %d -- %d -- %.2f\n", lista[i].id, lista[i].nombre, lista[i].stock, lista[i].vendidos, lista[i].precio);
    }
}

float calcularPromedio(int lista[20])
{
    int i;
    int cantidad = 0;
    int suma = 0;
    float promedio = 0;
    for(i = 0; i < 20; i++)
    {
        if(lista[i] > 0)
        {
            cantidad++;
            suma = suma + lista[i];
        }
    }
    if(cantidad != 0)
        promedio = (float)suma / cantidad;

    return promedio;
}

void inicializar(int lista[])
{
    int i;
    for(i = 0; i < 20; i++)
    {
        lista[i] = 0;
    }
}
int obtenerUltimaPublicacion(eUsuario lista[], int index)
{
    int i;
    for(i = 0; i < 20; i++)
}
