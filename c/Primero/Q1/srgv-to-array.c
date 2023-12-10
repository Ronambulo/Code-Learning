#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    float matriz[3][3];
    int cont = 0;

    printf("\n");
    if(argc >= 10){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cont++;
                matriz[i][j] = strtof(argv[cont], NULL);
                printf("%f  ", matriz[i][j]);
            }
            printf("\n");
        }
    }else{printf("la cantidad de parametros no es valida \n");}
    return 0;
}
