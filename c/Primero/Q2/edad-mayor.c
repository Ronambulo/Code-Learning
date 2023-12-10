#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int edad;
}alumno_t;

void rellenar(alumno_t *alumno, int i);
int encuentraMax(alumno_t *alumnos, int numAlumnos);
void imprimir(alumno_t *alumno);

int main(int argc, char* argv[]){
    int numAlumnos = 0;
    int edadMax = 0;
    alumno_t* alumnos = NULL;
    printf("introduce el numero de alumnos: \n");
    scanf("%d", &numAlumnos);
    alumnos = (alumno_t*)malloc(sizeof(alumno_t)*numAlumnos);
    for(int i = 0; i < numAlumnos; i++){
       rellenar(&alumnos[i], i); 
    }
    edadMax = encuentraMax(alumnos, numAlumnos);
    printf("\nla edad max es: %d\n", edadMax);
    
    return 0;
}

void rellenar(alumno_t *alumno, int i){
    printf("\nAlumno %d: ", i+1);
    scanf("%d", &(alumno->edad));
    while(getchar() !='\n');
}

int encuentraMax(alumno_t *alumnos, int numAlumnos){
    int valor = 0;
    for(int i = 0; i < numAlumnos; i++){
        
        if(alumnos[i].edad > valor){
            valor = alumnos[i].edad;
        }
    }
    return valor;
}
