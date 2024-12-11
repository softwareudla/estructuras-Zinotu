#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    struct Libro libros[20];
    int len;
    int opc;
    int i=0;
do{
    opc = menu();
    switch (opc)
    {
        case 1:
            registrarlibros(libros, i);
            i++;
            break;
        case 2:
            mostrarlibros(libros, i);
            break;
        case 3:
            int id;
            printf("Ingrese el id del libro a buscar: ");
            scanf("%d", &id);
            buscarlibroId(libros, id, i);

            break;
        case 4:
            char titulo[100];
            printf("Ingrese el título del libro a buscar: ");
            fflush(stdin); 
            fgets(titulo, 100, stdin); 
            titulo[strcspn(titulo, "\n")] = '\0'; 
            buscarlibroTitulo(libros, titulo, i); 
            break;
        case 5:
            printf("Ingrese el titulo del libro para cambiar su estado: ");
            fflush(stdin);
            fgets(titulo,100,stdin);
            titulo[strcspn(titulo, "\n")] = '\0'; 
            cambiarestado(libros, titulo, i);
            break;
        case 6:
            eliminarlibro(libros, &i);
            break;
        case 7:
            break;
        
        default:
            printf("opción no válida");
    }
    }while(opc != 7);

    return 0;
}
