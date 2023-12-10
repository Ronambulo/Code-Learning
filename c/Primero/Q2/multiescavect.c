#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    float v1[3] = {1,2,3};
    float v2[3] = {3,2,1};
    float res = 0;
    float vRes[3] = {0,0,0};

    res = multescalar(v1,v2);
    multVector(v1,v2,vRes);
    printf("El producto escalar es: %f\n", res);
    printf("El producto vectorial es:");
}