#include <stdio.h>
#include <math.h>

int var1=0, cont=0, n=0;

int main(){
    printf("Introduce el vaor de n: ");
    scanf("%d", &n);
    cont = n;
    for(;cont>0; cont--){
        var1 = var1 + cont;
    }
    printf("la suma aritmetica de 1+n = %d \n", var1);
    printf("el resultado de la operación n*(n+1)/2 = %d \n",  n*(n+1)/2);
}