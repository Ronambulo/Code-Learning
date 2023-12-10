#include <stdio.h> 
#include <math.h>

int n1=0, n2=0;


int main(){
    do{
    printf("Esta es una calculadora de MCD de dos numeros enteros positivos \n");
    printf("para comenzar, elige el pimer número: ");
    scanf("%d", &n1);
    printf("Elige el segundo número: ");
    scanf("%d", &n2);
    }while (n1<0 && n2<0);

    if(n1 > n2){
        while(n1%n2 != 0){
            n2 = n2/(n1%n2);
        }            
        printf("El máximo comun divisor es: %d", n2);
    }

    else if(n2 > n1){
        while(n2%n1 != 0){
            n2 = n1/(n2%n1);
        }
        printf("El máximo comun divisor es: %d", n1);
    }
}
