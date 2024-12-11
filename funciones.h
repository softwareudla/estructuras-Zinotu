struct Libro
{
    int id;
    char titulo [100];
    char autor [50];
    int anio;
    char estado [20];
};
int menu();
void registrarlibros (struct Libro libros[20],int i);
void mostrarlibros (struct Libro libros[20], int n);
void buscarlibroId(struct Libro libros[20],int id, int n );
void buscarlibroTitulo(struct Libro libros[20], char titulo[100], int n);
void cambiarestado(struct Libro libros[20], char titulo[20], int n);
void eliminarlibro(struct Libro libros[20], int *n);