#include <stdio.h>

int cont = 0, nnum = 0, x = 0, valorm = 32768, valorM= 0;
float resul = 0.0;

int main(){
    printf("Selecciona el número de números que va a utilizar: ");
    scanf("%d", &nnum);
    if(nnum > 0){
        while (cont < nnum){
            cont = cont + 1;
            printf("Indica el valor número %d: ", cont);
            scanf("%d", &x);
            resul = resul + x;
            if(x < valorm){
                valorm = x;
            }
            if(x >= valorM){
                valorM = x;
            }
        }
        printf("El resultado de la media es: %f \n", (resul/nnum));
        printf("el menor valor es: %d \n", valorm);
        printf("el mayor valor es: %d", valorM);
    }
    else if(nnum < 0)
    {
        printf("el numero de numeros no puede ser negativo");
    }
    
}
