#include <stdio.h>

int numero=0, contador=0, divisores=0;

int main(){

    printf("comprobador de números primos: \nDime un número: ");
    scanf("%d", &numero);
    if(numero > 0){

        while (contador<numero){
            contador ++ ;
            if(numero % contador == 0){
                divisores ++ ;
            }
        }
        if(divisores == 2){
            printf("%d es un número primo", numero);
        }
        else{
            printf("%d no es un número primo", numero);
        }

    }
    else{
        printf("\nel numero tiene que ser positivo");
    }
}