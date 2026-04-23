#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct  {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct  {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
}Cliente;


int main(){

    srand(time(NULL));

    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantClientes = 0,cantProductos = 0;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);

    Cliente *pClientes = malloc(cantClientes * sizeof(Cliente));

    for (int i = 0; i < cantClientes; i++){

        //(pClientes + i)->ClienteID = i;
        pClientes[i].ClienteID = i;

        //Cragar nombre del cliente
        char nombre[50];
        printf("Ingresar nombre: ");
        scanf("%s",nombre);
        printf("\n\n");
        pClientes[i].NombreCliente = (char*)malloc(strlen(nombre) + 1);
        strcpy(pClientes[i].NombreCliente,nombre);

        pClientes[i].CantidadProductosAPedir = (rand() % 5) + 1;

        //Cargar cantidad de productos pro cliente
        printf("Cuantos productos solicito?: ");
        scanf("%d", &cantProductos);

        Producto *pProducto = malloc(cantProductos * sizeof(Producto));

        pClientes[i].Productos = pProducto;
        
        for (int j = 0; j < cantProductos; j++){
            pProducto[j].ProductoID = j;
            pProducto[j].Cantidad = (rand() % 10) + 1;
            pProducto[j].TipoProducto = TiposProductos[(rand() % 5)];
            pProducto[j].PrecioUnitario = (rand() % 91) + 10;
        }
        

    }
    

    return 0;
}
