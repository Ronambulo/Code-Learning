#include <stdio.h>
#include <math.h>

int main(){
    int decimal = 0, binario[32], cont = 0, resto = 0;

    printf("Conversor de decimal a binario: \n Pon un numero para transformarlo a binario:");
    scanf("%d", &decimal);

    do{
        resto = decimal % 2;
        decimal = decimal / 2;
        binario[cont] = resto;
        cont++;

    }while(decimal > 0);
    
    printf("\n binario: %d", &binario);
}
