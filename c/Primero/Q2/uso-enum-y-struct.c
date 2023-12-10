#include <stdio.h>
#include <stdlib.h>

typedef enum{
    pino, haya, roble, euclipto
}tipoArbol_e;

char* arbolName[] = {"pino", "haya", "roble", "eucalipto"};

typedef struct {
    int numeroHojas;
    int numeroRamas;
    short int numeroRaices;
    tipoArbol_e nombreArbol;
}arbol_t;

arbol_t pedirArbol(arbol_t nuevoArbol);

int main(){
    arbol_t nuevoArbol;

    pedirArbol(nuevoArbol);
    printf("\n\n %d, %d, %d", nuevoArbol.numeroHojas, nuevoArbol.numeroRamas, nuevoArbol.numeroRaices);
}   

arbol_t pedirArbol(arbol_t nuevoArbol){

    printf("introduce el numero de hojas: ");
    scanf("%d", &nuevoArbol.numeroHojas);
    printf("\nIntroduzca el numero de ramas: ");
    scanf("%d", &nuevoArbol.numeroRamas);
    printf("\nIntroduzca el numero de raices: ");
    scanf("%d", &nuevoArbol.numeroRaices);

}
