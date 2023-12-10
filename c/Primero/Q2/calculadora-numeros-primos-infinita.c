#include <stdio.h>

int main( int argc, char* argv){

//  1003000         15534721 


    int nprimo = 15514589;
    int cont = 0;
    int divisores = 0;
    int contador = 0;
    float j = 1001777;
    float por = 0;

    while (nprimo > 0){
            divisores = 0;
            cont = 0;
            contador = 0;
            
            while (contador < nprimo){
                contador ++ ;
                if(nprimo % contador == 0){
                    divisores ++ ;
                }
            }

            if(divisores == 2){
                j++;
                por = (nprimo / j);
                printf("          %.0f         %d          %.5f \% \n", j, nprimo, por);
            }
            nprimo ++ ;
            
    }
}
