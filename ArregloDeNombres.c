#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD 5

void MostrarPersonas(char *arrayNombres[],int cant);
void BuscaNombrePorId(char *arrayNombres[],int cant,int id);
int BuscaNombrePorPalabra(char *arrayNombres[],int cant,char clave[]);

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

    BuscaNombrePorId(nombres,CANTIDAD,3);

    BuscaNombrePorPalabra(nombres,CANTIDAD,"facundo");

    return 0;
}

void MostrarPersonas(char *arrayNombres[],int cant){
    
    printf("======  Lista de Personas  =====\n");
    for (int i = 0; i < cant; i++){
        printf("%s",arrayNombres[i]);
        printf("\n");
    }
    
}

void BuscaNombrePorId(char *arrayNombres[],int cant,int id){
    
    if(id >= cant || id < 0){
        printf("No se encontró el valor buscado");
    }else{
        printf("%s",arrayNombres[id]);
        printf("\n");
    }
    
}


int BuscaNombrePorPalabra(char *arrayNombres[],int cant,char clave[]){
    
    for (int i = 0; i < cant; i++){
        
        if(strstr(arrayNombres[i], clave) != NULL){
            return i;
        }
    }
    
    return -1;
}