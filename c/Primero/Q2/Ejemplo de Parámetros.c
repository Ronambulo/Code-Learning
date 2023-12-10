#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    long int suma = 0;
    float total = 0;
    for (int i = 0; i < argc; i++){
        if(i > 0){
            printf("Parametro: %d: %d \n", i, atoi(argv[i]));
        }
    }
    printf("\n");
    for(int j = 0; j<argc; j++){
        if(j > 0){
            long int acumulaint=strtol(argv[j], NULL, 10);
            suma = suma + acumulaint;
        }
        
    }
    total = (float) suma / (argc - 1);
    printf("La media de los valores es: %f", total);
    printf("\n%d suma",suma);

    return 0;
}