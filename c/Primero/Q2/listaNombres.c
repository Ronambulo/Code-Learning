#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char** nombres;
    int numNombres;
}listaNombres_t;

char* leelineadinamica();
listaNombres_t leenombres(listaNombres_t lNombres);
listaNombres_t imprimenombres(listaNombres_t lNombres);

int main(int argc, char* argv){
    listaNombres_t lNombres;

    printf("Escriba los nombres de uno en uno (0 para terminar): \n");
    printf("introduzca nombre: ");
    leenombres(lNombres);
    imprimenombres(lNombres);

    return 0;
}

listaNombres_t leenombres(listaNombres_t lNombres){
    lNombres.nombres = NULL;
    lNombres.numNombres = 0;
    while(getchar() != '0'){
        printf("introduzca nombre: ");
        lNombres.numNombres++;
        lNombres.nombres=(char**)realloc(lNombres.nombres,sizeof(char*)*lNombres.numNombres);
        lNombres.nombres[lNombres.numNombres-1] = leelineadinamica();
    }
    return lNombres;
}

listaNombres_t imprimenombres(listaNombres_t lNombres){
    for(int i = 0; i < lNombres.numNombres; i++){
        printf("\n %s", lNombres.nombres[i]);
    }
}

char* leelineadinamica(){
    char* linea = NULL;
    int numChar = 0;
    char c='\0';

    while(c != '\n'){
        c = getchar();
        numChar++;
        linea=(char*)realloc(linea,sizeof(char)*numChar);
        linea[numChar-1] = c;
    }
    linea[numChar-1] = '\0';
    return linea;
}