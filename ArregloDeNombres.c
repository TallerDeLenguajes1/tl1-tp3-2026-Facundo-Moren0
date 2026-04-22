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
    printf("\n\n");


    int opcion;

    do {
        printf("\n");
        printf("================================\n");
        printf("       MENU DE CONSULTA         \n");
        printf("================================\n");
        printf("  1. Buscar por ID              \n");
        printf("  2. Buscar por palabra clave   \n");
        printf("  0. Salir                      \n");
        printf("================================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n");

        if(opcion == 1){

            int id;
            printf("Ingrese el ID a buscar (0 a %d): ", CANTIDAD - 1);
            scanf("%d", &id);
            BuscaNombrePorId(nombres, CANTIDAD, id);
        } else if(opcion == 2){

            char buff[50];
            printf("Ingrese la palabra clave: ");
            scanf("%s", buff);
            int resultado = BuscaNombrePorPalabra(nombres, CANTIDAD, buff);
            if(resultado == -1){
                printf(">>> No se encontro el valor buscado\n");
            } else {
                printf(">>> Nombre encontrado: %s\n", nombres[resultado]);
            }

        } else if(opcion != 0){
            printf(">>> Opcion invalida. Intente nuevamente.\n");
        }

    } while(opcion != 0);

    printf("\n>>> Fin del programa...\n");

    for(int i = 0; i < CANTIDAD; i++){
        free(nombres[i]);
    }

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
        printf("La persona con id(%d) es: %s",id,arrayNombres[id]);
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