#include <stdio.h>

int valor1=0, valor2=0, salir=0;
char que;

int main(){
    printf("[S/s] - Sumar\n[R/r]- Restar\n[M/m] -Multiplicar\n[D/d] - Dividir\n[E/e] - Exit\n");

    while(salir == 0){

        printf("Elige un tipo de operacion: ");
        scanf(" %c", &que);

        switch(que){
            case 'S':
            case 's':
                printf("Introduce el primer valor: ");
                scanf("%d", &valor1);
                printf("Introduce el segundo valor: ");
                scanf("%d", &valor2);

                printf("el resultado de la suma es: %d \n", valor1+valor2);
                break;
            case 'R':
            case 'r':
                printf("Introduce el primer valor: ");
                scanf("%d", &valor1);
                printf("Introduce el segundo valor: ");
                scanf("%d", &valor2);
                
                printf("el resultado de la resta es: %d \n", valor1-valor2);
                break;
            case 'M':
            case 'm':
                printf("Introduce el primer valor: ");
                scanf("%d", &valor1);
                printf("Introduce el segundo valor: ");
                scanf("%d", &valor2);
                
                printf("el resultado de la multiplicación es: %d \n", valor1*valor2);
                break;
            case 'D':
            case 'd':
                printf("Introduce el primer valor: ");
                scanf("%d", &valor1);
                printf("Introduce el segundo valor: ");
                scanf("%d", &valor2);
                
                if (valor2 != 0){
                    printf("el resultado de la división es: %d \n", valor1/valor2);
                }
                else if(valor2 == 0){
                    printf("no se puede dividir entre 0");
                }
                break;
            case 'E':
            case 'e':
                salir = 1;
        }

    };
}