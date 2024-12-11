#include <stdio.h>
#include <string.h>
#include "funciones.h"
int menu(){
    int opc;
    printf("1. Registrar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por id\n");
    printf("4. Buscar libro por titulo\n");
    printf("5. Cambiar estado\n");
    printf("6. Eliminar un libro\n");
    printf("7. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opc);
    return opc;
}

void registrarlibros (struct Libro libros[20],int i){
    int len;
    int esigual;

    if (i >= 20) {
        printf("No puedes ingresar más de 20 libros.\n");
        return;  // Sale de la función si se alcanzó el límite
    }
    
    do
    {
        printf("Ingrese el id del libro %d: ",i+1);
        do
        {
            scanf("%d", &libros[i].id);
        } while (libros[i].id<1);
         
        esigual = 1; 
        for (int j = 0; j < i ; j++)  
        {
            if(libros[j].id == libros[i].id){
                printf("el id ya existe\n");
                esigual = 0;
                break;
            }
            
        }
        
    } while (esigual == 0);
    printf("Ingrese el titulo del libro %d: ",i+1);
    fflush(stdin);
    fgets(libros[i].titulo,100,stdin);
    len=strlen(libros[i].titulo)-1;
    libros[i].titulo[len]='\0';
    printf("Ingrese el autor del libro %d: ",i+1);
    fflush(stdin);
    fgets(libros[i].autor,100,stdin);
    len=strlen(libros[i].autor)-1;
    libros[i].autor[len]='\0';
    printf("Ingrese el anio del libro %d: ",i+1);
    scanf("%d",& libros[i].anio);
    strcpy(libros[i].estado, "Disponible");
}

void mostrarlibros (struct Libro libros[20], int n){
    printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
    for (int i = 0; i < n; i++)
    {
        if (libros[i].id!=0)
        {
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n",libros[i].id,
                                                libros[i].titulo,
                                                libros[i].autor,
                                                libros[i].anio,
                                                libros[i].estado);
        } 
    }
}

//funcion buscar un lbro or titulo o id y mostrar su informacion
void buscarlibroId(struct Libro libros[20],int id, int n ){
    for (int i = 0; i < n; i++)
    {
        if (libros[i].id == id)
        {
            printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n",libros[i].id,
                                                libros[i].titulo,
                                                libros[i].autor,
                                                libros[i].anio,
                                                libros[i].estado);
            break;
        }
    }
}
void buscarlibroTitulo(struct Libro libros[20], char titulo[100], int n){
    for (int i = 0; i < n; i++)
    {
        if (strcmp(libros[i].titulo, titulo) == 0)
        {
            printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n",libros[i].id,
                                                libros[i].titulo,
                                                libros[i].autor,
                                                libros[i].anio,
                                                libros[i].estado);
            break;
        }
        
    }
    
}

//actualizar el estado de un libr de "disponible" a "prestado" o viceversa
void cambiarestado(struct Libro libros[20], char titulo[100], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            // Cambiar entre "Disponible" y "Prestado"
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("El estado del libro '%s' ha sido actualizado a '%s'.\n", 
                    libros[i].titulo, libros[i].estado);
            return;
        }
    }
    printf("El libro con el título '%s' no se encontró.\n", titulo);
}

//eliminar libro
void eliminarlibro(struct Libro libros[20], int *n) {
    char titulo[100];
    int encontrado = 0;

    printf("Ingrese el titulo del libro a eliminar: ");
    fflush(stdin);
    fgets(titulo, 100, stdin);
    titulo[strcspn(titulo, "\n")] = '\0'; // Eliminar salto de línea

    for (int i = 0; i < *n; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            // Mover todos los elementos hacia atrás para llenar el espacio vacío
            for (int j = i; j < *n - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*n)--; // Reducir el número total de libros
            encontrado = 1;
            printf("El libro con titulo '%s' ha sido eliminado.\n", titulo);
            break;
        }
    }

    if (!encontrado) {
        printf("El libro con titulo '%s' no se encontró.\n", titulo);
    }
    
}


//control deproducto unico y validacion de entradas
