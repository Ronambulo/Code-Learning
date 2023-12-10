#include <stdio.h>
#include <stdlib.h>

typedef enum{
    int_t, float_t, char_t
}tipoListaDinamica;

typedef struct{
    int size;
    int maxSize;
    union{ 
        void* rawData;
        int* intData;
        float* floatData;
        char* charData;
    };
    tipoListaDinamica tipo;
}listaDinamica_t;


// DECLARACION DE FUNCIONES
listaDinamica_t crealista(tipoListaDinamica tipo, int size);
listaDinamica_t redimensionalista(tipoListaDinamica tipo, int size);
void mostrarlista(listaDinamica_t lista);
void liberalista(tipoListaDinamica tipo);




// FUNCIONES
int main(int argc, char* argv[]){

    listaDinamica_t lista;
    lista = crealista(int_t, 5);

    for(int i = 0; i < lista.maxSize; i++){
        lista.intData[i] = i;
        lista.size++;
    }

    lista = redimensionalista(lista, int_t, 10);

    for(int i = lista.size; i < lista.maxSize; i++){
        lista.intData[i] = -i;
        lista.size++;
    }

    liberalista(lista);
    return 0;
}



listaDinamica_t crealista(tipoListaDinamica tipo, int size){
    listaDinamica_t lista;

    int sizeBytes = 0;
    switch (tipo)
    {
        case int_t:
            sizeBytes = sizeof(int)*size;
        break;
        case float_t:
            sizeBytes = sizeof(float)*size;
        break;
        case char_t:
            sizeBytes = sizeof(char)*size;
        break;
    }
    lista.size = 0;
    lista.maxSize = size;
    lista.tipo = tipo;
    lista.rawData = (void*)malloc(sizeBytes);

    return lista;
}


listaDinamica_t redimensionalista(listaDinamica_t listaAntigua, tipoListaDinamica tipo, int size){
    
    int sizeBytes = 0;
    switch (tipo)
    {
        case int_t:
            sizeBytes = sizeof(int)*size;
        break;
        case float_t:
            sizeBytes = sizeof(float)*size;
        break;
        case char_t:
            sizeBytes = sizeof(char)*size;
        break;
    }
    lista.size = 0;
    lista.maxSize = size;
    lista.tipo = tipo;
    listaAntigua.rawData = (void*)realloc(lista.rawData.sizeBytes);

    return lista;
}

void mostrarlista(listaDinamica_t lista){
    for(int i = 0; i < lista.size; i++){

        switch (lista.tipo)
        {
            case int_t:
                printf("POS: [%d] VALOR: %d\n", i, lista.intData);
            break;
            case float_t:
                printf("POS: [%d] VALOR: %d\n", i, lista.floatData);
            break;
            case char_t:
                printf("POS: [%d] VALOR: %d\n", i, lista.charData);
            break;
      
        }
    }
}

void liberalista(tipoListaDinamica_t tipo){
    free(lista.rawData);
}