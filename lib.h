

typedef struct
{
    char nombre[20];
    int id;
    int stock;
    int vendidos;
    int estado;
    int precio;
    int idUsuario;
}ePublicacion;

typedef struct
{
    int id;
    char nombre[20];
    int estado;
    int calificaciones[20]; //Deben estar entre 1 y 10
    ePublicacion publicaciones[20];
}eUsuario;

void altaUsuario(eUsuario, int);
void altaPublicacion();
int buscarIndexUsuario(eUsuario*, int, int);
int buscarIndexPublicacion(ePublicacion*, int, int);
int buscarLibreUsuario(eUsuario*, int);
void listarUsuarios(eUsuario*, int);
void listarPublicaciones(ePublicacion*, int);
float calcularPromedio(int[20]);

