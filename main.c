#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define MAXU 100
#define MAXP 1000


int main()
{
    eUsuario usuarios[MAXU] = {};
    //ePublicacion publicaciones[MAXP] = {};
    int flag = 1;
    int opcion;
    int index;
    eUsuario nuevoUsuario;
    int idUsuario = 1;
    //int idPublicacion = 1;
    int id;

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
                altaUsuario(nuevoUsuario, idUsuario);
                idUsuario++;
                usuarios[index] = nuevoUsuario;
            }
            else
                printf("Error: no hay mas espacio");
            break;

            case 2:
            printf("Id usuario: ");
            scanf("%d", &id);
            index = buscarIndexUsuario(usuarios, id, MAXU);
            if(index != -1)
            {

            }
            else
                printf("Usuario inexistente");

            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

            case 8:
            break;

            case 9:
            break;

            case 10:
                listarUsuarios(usuarios, MAXU);
            break;

            case 11:
            flag = 0;
            printf("Programa finalizado");
            break;
        }
    }
    while(flag != 0);

    return 0;
}