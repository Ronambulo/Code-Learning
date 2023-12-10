#include <stdio.h>
#include <stdlib.h>

char* leeLineaDinaicaDeFichero(FILE* f){
    char* linea=NULL;
    int numChar=0;
    char c='\0';
     do{
        c=getc(f);
        numChar++;
        linea=(char*)realloc(linea, sizeof(char)*numChar);
        linea[numChar-1]=c;
    }while(c!='\n' && ! feof(f));

    linea[numChar-1]='\0';

    return linea;

}

int main(int argc, char** argv){

    FILE* fichero1 = NULL;
    int edad = 0;
    fichero1 = fopen("prueba1.txt", "r"); //r significa lectura

    if(fichero1 == NULL){

        printf("Error, el fichero no se ha encontrado \n");
        printf("creando Fichero......\n");
        fichero1 = fopen("prueba1.txt", "w"); //w crea el fichero y si no existe lo reemplaza

        if(fichero1 == NULL){

            printf("Error, no se ha podidio crear el fichero\n");

        }else{

            fclose(fichero1);
            printf("El fichero se ha creado correctamente\n");

            }

    }else{

        printf("El fichero existe\n");
        fclose(fichero1);
    }

    fichero1 = fopen("prueba1.txt", "a"); // abre el fichero y te lleva  al final del texto
    printf("Introduzca su edad: \n");
    scanf("%d", &edad);

    fprintf(fichero1, "Tu edad es: %d\n", edad);
    fclose(fichero1);

    fichero1 = fopen("prueba1.txt", "r");
    while(!feof(fichero1)){
        char* linea = leeLineaDinaicaDeFichero(fichero1);
        printf("linea: %s\n", linea);
        free(linea);
    }
    fclose(fichero1);

    //para volver a crear el fichero y borrarlo
    fichero1 = fopen("prueba1.txt", "w");
    fclose(fichero1);

    return 0;
}
