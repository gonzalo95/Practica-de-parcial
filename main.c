#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define MAXU 100
#define MAXP 1000


int main()
{
    eUsuario usuarios[MAXU] = {};
    ePublicacion publicaciones[MAXP] = {};
    int flag = 1;
    int opcion;
    int index;
    int idUsuario = 1;
    int idPublicacion = 1;
    int id;
    char nuevoPass[20];
    char nuevoNombre[20];
    int auxIndex;
    int calificacion;
    int auxPass;

    do
    {
        printf("1.-Alta usuario\n");
        printf("2.-Modificar usuario\n");
        printf("3.-Baja usuario\n");
        printf("4.-Publicar\n");
        printf("5.-Modificar publicacion\n");
        printf("6.-Cancelar publicacion\n");
        printf("7.-Comprar\n");
        printf("8.-Listar publicaciones de usuario\n");
        printf("9.-Listar publicaciones\n");
        printf("10.-Listar usuarios\n");
        printf("11.-Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                index = buscarLibreUsuario(usuarios, MAXU);
                if(index != -1)
                {
                    usuarios[index] = altaUsuario(idUsuario);
                    idUsuario++;
                }
                else
                    printf("Error: no hay mas espacio");

                break;

            case 2:
                printf("Id usuario: ");
                scanf("%d", &id);
                index = buscarIndexUsuario(usuarios, id, MAXU);

                if(index == -1)
                    printf("Usuario inexistente\n");
                else
                {
                    auxPass = chequearPass(usuarios, index);
                    if(auxPass == -1)
                    {
                        printf("Pass incorrecto\n");
                        break;
                    }
                    printf("Nombre: ");
                    fflush(stdin);
                    gets(nuevoNombre);
                    strcpy(usuarios[index].nombre, nuevoNombre);

                    printf("Nuevo pass: ");
                    fflush(stdin);
                    gets(nuevoPass);
                    strcpy(usuarios[index].pass, nuevoPass);
                }

                break;

            case 3:
                printf("Id usuario: ");
                scanf("%d", &id);
                index = buscarIndexUsuario(usuarios, id, MAXU);
                if(index != -1)
                {
                    auxPass = chequearPass(usuarios, index);
                    if(auxPass == -1)
                    {
                        printf("Pass incorrecto\n");
                        break;
                    }
                    borrarPublicaciones(publicaciones, usuarios[index].id, MAXP);
                    usuarios[index].estado = 0;
                    printf("Usuario eliminado\n");
                }
                else
                    printf("Usuario inexistente\n");
            break;

            case 4:
                printf("Id usuario: ");
                scanf("%d", &id);
                index = buscarIndexUsuario(usuarios, id, MAXU);

                if(index == -1)
                {
                    printf("Usuario inexistente\n");
                    break;
                }

                auxPass = chequearPass(usuarios, index);
                if(auxPass == -1)
                {
                    printf("Pass incorrecto\n");
                    break;
                }

                auxIndex = obtenerLibrePublicacion(usuarios[index]);

                if(auxIndex != -1)
                    usuarios[index].publicaciones[auxIndex] = idPublicacion;
                else
                {
                    printf("Usted llego al limite de publicaciones");
                    break;
                }


                index = buscarLibrePublicacion(publicaciones, MAXP);
                if(index != -1)
                {
                    publicaciones[index] = altaPublicacion(idPublicacion, id);
                    publicaciones[index].idUsuario = id;
                    idPublicacion++;
                }
                else
                    printf("Error: no hay mas espacio");
            break;

            case 5:
                printf("Id usuario: ");
                scanf("%d", &id);
                index = buscarIndexUsuario(usuarios, id, MAXU);

                if(index == -1)
                {
                    printf("Usuario inexistente\n");
                    break;
                }

                auxPass = chequearPass(usuarios, index);
                if(auxPass == -1)
                {
                    printf("Pass incorrecto\n");
                    break;
                }

                listarPublicacionesUsuario(usuarios[index], publicaciones, MAXP);

                printf("Id del producto a modificar: ");
                scanf("%d", &id);

                index = buscarIndexPublicacion(publicaciones, id, MAXP);

                if(index == -1)
                {
                    printf("Producto inexistente\n");
                    break;
                }

                float precio;
                printf("Precio: ");
                scanf("%f", &precio);
                publicaciones[index].precio = precio;

                int stock;
                printf("Stock: ");
                scanf("%d", &stock);
                publicaciones[index].stock = stock;

            break;

            case 6:
                printf("Id usuario: ");
                scanf("%d", &id);
                index = buscarIndexUsuario(usuarios, id, MAXU);

                if(index == -1)
                {
                    printf("Usuario inexistente\n");
                    break;
                }

                auxPass = chequearPass(usuarios, index);
                if(auxPass == -1)
                {
                    printf("Pass incorrecto\n");
                    break;
                }

                listarPublicacionesUsuario(usuarios[index], publicaciones, MAXP);

                printf("Id del producto a borrar: ");
                scanf("%d", &id);

                index = buscarIndexPublicacion(publicaciones, id, MAXP);

                if(index == -1)
                {
                    printf("Producto inexistente\n");
                    break;
                }

                publicaciones[index].estado = 0;

            break;

            case 7:
                printf("Id del producto a comprar: ");
                scanf("%d", &id);
                index = buscarIndexPublicacion(publicaciones, id, MAXP);
                if(index == -1)
                {
                    printf("Producto inexistente\n");
                    break;
                }

                if(publicaciones[index].stock == 0)
                {
                    printf("Falta stock\n");
                    break;
                }
                else
                {
                    publicaciones[index].stock--;
                    publicaciones[index].vendidos++;
                }


                printf("Califique al vendedor(1 - 10): ");//validar
                scanf("%d", &calificacion);

                auxIndex = obtenerLibreCalificacion(usuarios[index]);

                if(auxIndex != -1)
                    usuarios[index].calificaciones[auxIndex] = calificacion;
                else
                {
                    printf("El usuario llego al limite de calificaciones");
                    break;
                }



            break;

            case 8:
                printf("Id usuario: ");
                scanf("%d", &id);
                index = buscarIndexUsuario(usuarios, id, MAXU);

                if(index == -1)
                {
                    printf("Usuario inexistente\n");
                    break;
                }

                listarPublicacionesUsuario(usuarios[index], publicaciones, MAXP);

            break;

            case 9:
                listarPublicaciones(publicaciones, MAXP, usuarios, MAXU);
            break;

            case 10:
                listarUsuarios(usuarios, MAXU);
            break;

            case 11:
                flag = 0;
                printf("Programa finalizado");
                break;

            default:
                printf("Comando invalido\n");
        }
    }
    while(flag != 0);

    return 0;
}
