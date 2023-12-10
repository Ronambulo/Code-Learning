#include <stdio.h>
#include <stdlib.h>

char* leelineadinamica();

int main(int argc, char* argv){

    printf("Introduzca datos: ");
    linea = leelineadinamica();
    printf("\nHe leido: '%s'\n", linea);
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