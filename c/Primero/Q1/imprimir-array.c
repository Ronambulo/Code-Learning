#include <stdio.h>

int main(){
    int TAM = 0, strSize = 0;
    char newChar;

    printf("Indica el tamaño del array: ");
    scanf("%d", &TAM);

    char Array1[TAM];
    while(getchar() != '\n');

    printf("introcuzca su array: ");
    while(TAM > strSize || newChar != '\n'){
        newChar = getchar();
        Array1[strSize] = newChar;
        strSize++;
    }

    Array1[strSize] = '\0';
    printf("%s", Array1);

}
