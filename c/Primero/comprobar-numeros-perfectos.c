#include <stdio.h>
int numero=0, contador=0, resultado=1;

int main(){

    printf("Comprobador de numeros perfectos: \n");
    printf("Dime un numero entero positivo: ");
    scanf("%d", &numero);

    while(contador < numero){
        if(numero%contador == 0){
            resultado = resultado + contador;
        }
        contador = contador + 1;
    }
    if(numero == resultado){
        printf("%d SI es un numero perfecto", numero);
    }
    else{
        printf("%d NO es un numero perfecto", numero);
    } 
    
}
