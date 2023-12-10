#include <stdio.h>
#include <math.h>

int a=0,b=0,c=0;

//calcular las raices de un polinomio de grado 2
int main(){
    printf("Para una funcion ax^2 + bx + c \n");
    printf("Introduce un valor a: ");
    scanf("%d", &a);
    printf("Introduce un valor b: ");
    scanf("%d", &b);
    printf("Introduce un valor c: ");
    scanf("%d", &c);

    if(((b*b)-4*a*c) >= 0){
        double resultado1 = 0;
        double resultado2 = 0;
        resultado1 = ((-b+(sqrt(b*b - 4*a*c)))/(2*a));
        resultado2 = ((-b-(sqrt(b*b - 4*a*c)))/(2*a));  
        printf("Los resultados positivo y negativo son: %lf %lf", resultado1, resultado2);
    }
    else if(((b^2)-4*a*c) < 0){
        printf("El valor del interior de la raiz es menor que cero y no existe.");
    }
}