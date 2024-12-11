struct Libro
{
    int id;
    char titulo [100];
    char autor [50];
    int anio;
    char estado [20];
};
int menu();
void registrarlibros (struct Libros libros[20],int i);
void mostarlibros (struct libro libros[20], int i);