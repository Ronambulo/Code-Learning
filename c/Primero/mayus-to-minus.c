#include <stdio.h>

#define CONST1 'A'
#define CONST2 'B'

char VARA = CONST1, VARB = CONST2;
int Mtom = 0;

int main(void){
    printf("las variables antes de la función son: %c %c \n", VARA, VARB);
    Mtom = ('a' - 'A');
    VARA = VARA + Mtom;
    VARB = VARB + Mtom;
    printf("las variables despues de la función son: %c %c", VARA, VARB);
}

