#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct  {
 int ProductoID;
 int Cantidad;
 char *TipoProducto;
 float PrecioUnitario;
}Producto;

typedef struct  {
int ClienteID;
char *NombreCliente;
int CantidadProductosAPedir;
Producto *Productos;
}Cliente;

float CostoTotalProducto(Producto *producto);

void MostrarClientes(Cliente *pClientes, int cantClientes);

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

        //Cargar nombre del cliente
        char nombre[50];
        printf("Ingresar nombre: ");
        scanf("%s",nombre);
        getchar();
        printf("\n\n");
        pClientes[i].NombreCliente = (char*)malloc(strlen(nombre) + 1);
        strcpy(pClientes[i].NombreCliente,nombre);

        pClientes[i].CantidadProductosAPedir = (rand() % 5) + 1;

        //Cargar cantidad de productos por cliente
        
        /*
        printf("Cuantos productos solicito?: ");
        scanf("%d", &cantProductos);*/

        cantProductos = pClientes[i].CantidadProductosAPedir;

        Producto *pProducto = malloc(cantProductos * sizeof(Producto));

        pClientes[i].Productos = pProducto;
        
        for (int j = 0; j < cantProductos; j++){
            pProducto[j].ProductoID = j;
            pProducto[j].Cantidad = (rand() % 10) + 1;
            pProducto[j].TipoProducto = TiposProductos[(rand() % 5)];
            pProducto[j].PrecioUnitario = (rand() % 91) + 10;
        }
        

    }

    //Costo total del segundo producto solicitado del cliente 4
    //CostoTotalProducto((pClientes + 3) -> Productos + 1);

    //Costo total del primer producto solicitado del cliente 1
    CostoTotalProducto(pClientes -> Productos);


    MostrarClientes(pClientes, cantClientes);

    for (int i = 0; i < cantClientes; i++){
        free(pClientes[i].NombreCliente);
        free(pClientes[i].Productos);
    }
    free(pClientes);

    return 0;
}

float CostoTotalProducto(Producto *producto){
    float costoTotal = 0;
    costoTotal = (producto->Cantidad * producto->PrecioUnitario);
    return costoTotal;
}

void MostrarClientes(Cliente *pClientes, int cantClientes){

    for (int i = 0; i < cantClientes; i++){

        float totalCliente = 0;

        printf("================================\n");
        printf(" Cliente ID : %d\n", pClientes[i].ClienteID);
        printf(" Nombre     : %s\n", pClientes[i].NombreCliente);
        printf(" Productos  : %d\n", pClientes[i].CantidadProductosAPedir);
        printf("--------------------------------\n");
        printf(" %-5s %-15s %-10s %-10s %-10s\n", "ID", "Tipo", "Cantidad", "P.Unit", "Subtotal");
        printf("--------------------------------\n");

        for (int j = 0; j < pClientes[i].CantidadProductosAPedir; j++){
            Producto *p = &pClientes[i].Productos[j];
            float subtotal = CostoTotalProducto(p);
            totalCliente += subtotal;
            printf(" %-5d %-15s %-10d %-10.2f %-10.2f\n",
                p->ProductoID,
                p->TipoProducto,
                p->Cantidad,
                p->PrecioUnitario,
                subtotal
            );
        }

        printf("--------------------------------\n");
        printf(" TOTAL A PAGAR: $%.2f\n", totalCliente);
        printf("================================\n\n");
    }
}
