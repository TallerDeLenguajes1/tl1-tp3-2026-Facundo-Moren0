#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD 5

void MostrarPersonas(char *arrayNombres[],int cant);

int main(){
    char nombre[50];
    char *nombres[CANTIDAD];

    for (int i = 0; i < CANTIDAD; i++){
        printf("Ingresar nombre: ");
        scanf("%s",nombre);
        printf("\n\n");

        nombres[i] = (char*)malloc(strlen(nombre) + 1);
        strcpy(nombres[i],nombre);
    }
    
    MostrarPersonas(nombres,CANTIDAD);

    return 0;
}

void MostrarPersonas(char *arrayNombres[],int cant){
    
    printf("======  Lista de Personas  =====\n");
    for (int i = 0; i < cant; i++){
        printf("%s",arrayNombres[i]);
        printf("\n");
    }
    
}
