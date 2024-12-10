#include <stdio.h>
#include <string.h>
#include "funciones.h"
int menu(){
    int opc;
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por id\n"):
    printf("4. Buscar libro por titulo\n");
    printf("5. Cambiar estado\n");
    printf("6. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opc);
    return opc;
}

void registrarlibros (struct Libros libros[20],int i){
    int len;
    printf("Ingrese el id del libro %d: ",i+1);
    scanf("%d", &libros[i].id);
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

void mostarlibros (struct libro libros[20], int i){
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
/*code*/

//actualizar el estado de un libr de "disponible" a prestado o viceversa"
/*code*/

//eliminar libro
/*code*/

//control deproducto unico y validacion de entradas