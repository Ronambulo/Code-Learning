#include <stdio.h>

int seg = 1;

int main(void){

    while(seg != 0){
    printf("Di una cantidad de segundos: \n");
    scanf("%d", &seg);
    
    printf("Segundos: %d\n", seg);
    printf("minutos: %d\n", seg/60);
    printf("Horas: %d\n", seg/(60*60));
    printf("Dias: %d\n", seg/(60*60*24));
    printf("Semanas: %d\n", seg/(60*60*24*7));
    }
    
}
