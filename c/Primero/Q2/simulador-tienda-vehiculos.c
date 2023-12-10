#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idCoche;
    char* marcaCoche;
    char* modeloCoche;
    int añoCoche;
    int kilometrosCoche;
    int precioCoche;

}coche_t;

typedef struct
{
    int numCochelista;
    coche_t* cochesLista;
    
}listaCoches_t;

typedef struct
{
    char** linea;
    int num_Lineas;

}lineas_t;

//funciones

coche_t pedirCoche();
void guardarCocheEnMaster(FILE* fichero1, coche_t coche);
char *Leelineadinamica();
char *leelineaDinamicaFichero (FILE* fd);
lineas_t leelineasFichero (FILE* fichDesc);
void guardarMasterEnStruct(FILE* fichero1, lineas_t linea, listaCoches_t Coches);
void mostrarVehículos(listaCoches_t* Coches);
void comprarVehiculos(FILE* fichero1, listaCoches_t Coches, lineas_t linea);

//variable
int contid = 0;
int numero;

//codigo

int main(int argc, char* argv){

    coche_t coche = {0,NULL,NULL,0,0,0};
    lineas_t linea;
    listaCoches_t Coches;
    Coches.cochesLista = (coche_t*)malloc(sizeof(coche_t));
    Coches.numCochelista = 0;
    FILE* fichero1 = NULL;
    fichero1 = fopen("ficheroMaster.txt", "r");

    int opcion = 0;


    if(fichero1 == NULL){
        printf("Error, el fichero master no se ha encontrado \n");
        printf("creando Fichero......\n");
        fichero1 = fopen("ficheroMaster.txt", "w"); //w crea el fichero y si no existe lo reemplaza
        if(fichero1 == NULL){
            printf("Error, no se ha podidio crear el fichero\n");
        }else{
            fclose(fichero1);
            printf("El fichero master se ha creado correctamente\n");
            }
    }else{
        printf("El fichero master ha sido cargado correctamente\n");
        fclose(fichero1);
    }
   

    printf("\nGestion de coches, para comenzar indique que quiere hacer\n\n");
    while(opcion != 4){
        printf("1.- Introducir vehiculo\n2.- Presentar vehiculos por precio ascendente\n3.- Comprar vehiculo\n4.- Salir\n");
        scanf("%d", &opcion);
        while(getchar() != '\n');
        printf("\n");

        switch (opcion)
        {
        case 1:
            coche = pedirCoche();
            guardarCocheEnMaster(fichero1, coche);
            break;
        case 2:
            fichero1 = fopen("ficheroMaster.txt", "r");
            guardarMasterEnStruct(fichero1, linea, Coches);
            fclose(fichero1);
            printf("\n\n");
            break;
        case 3:
            printf("\n\n");
            comprarVehiculos(fichero1, Coches, linea);
            break;
        case 4:
            printf("Cerrando programa...");
            break;
        
        default:
            printf("Introduce un dato valido");
            break;
        }   
    }
    free(coche.marcaCoche);
    free(coche.modeloCoche);
    
    return 0;
}

coche_t pedirCoche(){
    coche_t nuevoCoche;
    contid++;
    printf("el id del nuevo vehiculo es: %d\n", contid);
    nuevoCoche.idCoche = contid;
    printf("introduce la marca del vehiculo:\n");
    nuevoCoche.marcaCoche = Leelineadinamica();
    printf("\nintruduce el modelo del vehiculo:\n");
    nuevoCoche.modeloCoche = Leelineadinamica();
    printf("\nintroduce el ano del vehiculo\n");
    scanf("%d", &(nuevoCoche.añoCoche));
    while(getchar() != '\n');
    printf("\nintroduce los kilometos del vehiculo\n");
    scanf("%d", &(nuevoCoche.kilometrosCoche));
    while(getchar() != '\n');
    printf("\nintroduce el precio del vehiculo\n");
    scanf("%d", &(nuevoCoche.precioCoche));
    while(getchar() != '\n');

    return nuevoCoche;
}

void guardarCocheEnMaster(FILE* fichero1, coche_t coche){
    fichero1 = fopen("ficheroMaster.txt", "a");
    fprintf(fichero1, "%d;%s;%s;%d;%d;%d\n", coche.idCoche,coche.marcaCoche,coche.modeloCoche,coche.añoCoche,coche.kilometrosCoche,coche.precioCoche);
    fclose(fichero1);
}

char *Leelineadinamica(){
    char* linea = NULL;
    int numChar = 0;
    char c='\0';

    while(c != '\n'){
        c = getchar();
        numChar++;
        linea=(char*)realloc(linea,sizeof(char)*numChar);
        linea[numChar-1] = c;
    }
    linea[numChar-1] = '\0';
    return linea;
}

void mostrarVehículos(listaCoches_t* Coches){
    
        if(Coches->numCochelista == 0){
         printf("no se ha encontrado ningun coche");
    }else{
        for(int i=0;i<Coches->numCochelista;i++){
            printf("%d;%s;%s;%d;%d;%d\n", Coches->cochesLista[i].idCoche, Coches->cochesLista[i].marcaCoche, Coches->cochesLista[i].modeloCoche, Coches->cochesLista[i].añoCoche, Coches->cochesLista[i].kilometrosCoche, Coches->cochesLista[i].precioCoche);
        }
    }
    
 }

char *leelineaDinamicaFichero (FILE* fd){
    char* linea=NULL;
    int size=0;
    char input; 

    linea = (char*)malloc(sizeof(char));
       
    while((input=getc(fd))!='\n' && !feof(fd)){
        linea[size]=input;
        linea = (char*)realloc(linea, sizeof(char)*(size+1));
        size++;
    }
    linea[size]='\0';
    return linea;
}

lineas_t leelineasFichero (FILE* fichDesc){
    lineas_t listaLineas;
    listaLineas.linea = NULL;
    listaLineas.num_Lineas = 0;
    listaLineas.linea = (char**) malloc(sizeof(char));
    
    while(!feof(fichDesc)){
        listaLineas.linea = (char**)realloc(listaLineas.linea, sizeof(char*)*(listaLineas.num_Lineas+1));
        listaLineas.linea[listaLineas.num_Lineas] =leelineaDinamicaFichero(fichDesc);
        listaLineas.num_Lineas++;
    }

    return listaLineas;
}

void guardarMasterEnStruct(FILE* fichero1, lineas_t linea, listaCoches_t Coches){
    linea = leelineasFichero(fichero1);
    for(int i=0;i<linea.num_Lineas-1;i++){
        Coches.cochesLista[i].idCoche = atoi(strtok(linea.linea[i], ";"));
        Coches.cochesLista[i].marcaCoche = (strtok(NULL, ";"));
        Coches.cochesLista[i].modeloCoche = (strtok(NULL, ";"));
        Coches.cochesLista[i].añoCoche = atoi(strtok(NULL, ";"));
        Coches.cochesLista[i].kilometrosCoche = atoi(strtok(NULL, ";"));
        Coches.cochesLista[i].precioCoche = atoi(strtok(NULL, ";"));
        printf("%d", i);

        Coches.numCochelista ++;
        Coches.cochesLista = (coche_t*)realloc(Coches.cochesLista ,sizeof(coche_t)*(Coches.numCochelista+1));

    }
        mostrarVehículos(&Coches);
        printf("%d", linea.num_Lineas);
        numero = linea.num_Lineas;
}

void comprarVehiculos(FILE* fichero1, listaCoches_t Coches, lineas_t linea){
    int elegir;
    printf("indica un identificador para comprar: ");
    scanf("%d", &elegir);
    while(getchar() != '\n');
    printf("%d", numero);
        for(int i = 0; i < numero-1; i++){
            fichero1 = fopen("vehiculos_vendidos.txt", "w");
            if( i = elegir-1){
                fprintf(fichero1, "%d;%s;%s;%d;%d;%d\n", Coches.cochesLista[i].idCoche,Coches.cochesLista[i].marcaCoche,Coches.cochesLista[i].modeloCoche,Coches.cochesLista[i].añoCoche,Coches.cochesLista[i].kilometrosCoche,Coches.cochesLista[i].precioCoche);
            }
            fclose(fichero1);
        }
}
