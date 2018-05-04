

typedef struct
{
    char nombre[20];
    int id;
    int stock;
    int vendidos;
    int estado;
    float precio;
    int idUsuario;
}ePublicacion;

typedef struct
{
    int id;
    char nombre[20];
    char pass[20];
    int estado;
    int calificaciones[20]; //Deben estar entre 1 y 10
    int publicaciones[20];
}eUsuario;

eUsuario altaUsuario(int);
ePublicacion altaPublicacion(int, int);
int buscarIndexUsuario(eUsuario*, int, int);
int buscarIndexPublicacion(ePublicacion*, int, int);
int buscarLibreUsuario(eUsuario*, int);
int buscarLibrePublicacion(ePublicacion*, int);
void listarUsuarios(eUsuario*, int);
void listarPublicaciones(ePublicacion*, int, eUsuario*, int);
float calcularPromedio(int[20]);
void inicializar(int*);
int obtenerLibrePublicacion(eUsuario);
void listarPublicacionesUsuario(eUsuario, ePublicacion*, int);
int obtenerLibreCalificacion(eUsuario);
void borrarPublicaciones(ePublicacion*, int, int);
int chequearPass(eUsuario*, int);

