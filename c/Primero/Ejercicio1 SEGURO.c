#include <stdio.h>
#define TAM 200

//funciones: 
int esCaracterValido(char newChar);
int  muestraFraseInvertida(char *frase, int strSize2);
void main(){
    //variables:
    char frase [TAM];
    char newChar;
    int strSize=0, strSize2 = 0;
    int i;
    int palabras = 1;
    int nletras = 0, nespacios = 0;
    int caractervalido = 1, error = 0;
    
    //codigo:
    printf("Escriba una frase: ");
    while((newChar = getchar()) != '\n') {
        frase[strSize] = newChar;
        if(frase[strSize]==' '){
            palabras++;
            nespacios++; 
        }

        caractervalido = esCaracterValido(newChar);
        if(caractervalido == 0){
            error = 1;
        }
        strSize++;
    }
    if(error == 1){

        printf("has puesto un caracter invalido");

    }else{
        frase[strSize] = '\0';
        printf ("Tu frase es: %s y tiene %d caracteres\n",frase, strSize);
        printf ("tu frase tiene %d palabras\n", palabras);
        printf ("tu frase pero invertida: ");
        strSize2 = strSize;
        muestraFraseInvertida(frase, strSize2);
    }
}

int esCaracterValido(char newChar){
    int caractervalido = 1;
    if(('A' <= newChar && newChar <= 'Z') || ('a' <= newChar && newChar <= 'z') || newChar == ' '){
        caractervalido = 1;
    }else{
        caractervalido = 0;
    }
    return caractervalido;
}

int  muestraFraseInvertida(char *frase, int strSize2){
    while(strSize2 >= 0) {
        printf ("%c", frase[strSize2]);
        strSize2--;
    }
}