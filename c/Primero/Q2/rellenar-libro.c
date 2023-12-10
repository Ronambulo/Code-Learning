#include <stdio.h>
#include <stdlib.h>

struct autor_t{
    int identificador_autor;
    char nombre[10];
    char apellido[10];
    char nacionalidad[10];
    int lista_libros[10];
};

struct libro_t{
    int identificador;
    char titulo[50];
    char ISBN[10];
    int numero_paginas;
    char editorial[10];
    char autor[10];
    int lista_autores[10];
};

void rellenarLibro(struct libro_t *libro){
    printf("Nombre del libro: ");
    scanf("%s", libro->titulo);  
    while(getchar() != '\n');  
    printf("\nISBN: ");
    scanf("%s", libro->ISBN);
    while(getchar() != '\n');  
    printf("\nNumero de paginas: ");
    scanf("%d", &libro->numero_paginas);
    while(getchar() != '\n');  
    printf("\nEditorial: ");
    scanf("%s", libro->editorial);
    while(getchar() != '\n');  
    printf("\nAutor: ");
    scanf("%s", libro->autor);
    while(getchar() != '\n');  
    printf("\n");

}

/*void imprimirLibro(struct libro_t *libro)
{
    printf();
}*/


int main(int argc, char* argv[]){

    struct libro_t libro;

    rellenarLibro(&libro);
    //imprimirLibro(&libro);
    return 0;

}
