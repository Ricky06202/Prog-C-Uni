/**
 * @archivo semestralRicardoSanjur.c
 * @autor Ricardo Sanjur (ricardosanjurg@gmail.com)
 * @resumen En este proyecto intentamos hacer un menu en el que podamos
 * pedir los articulos a vender, hacer un registro de todos los articulos q tenemos
 * y poder procesar las ordenes de los clientes para la venta de los productos
 * 
 * @version 0.1
 * @fecha 10-12-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "Lib/P1/MasUsados.h"

/**
 * @resumen Esta Funcion se encarga de pedir los articulos y registrarlos en
 * el archivo "clientesRicardoSanjur.txt"
 * 
 */
void almacenarArticulos()
{
    char codigo[10], descripcion[50], aux[10], impuesto;
    int cantidad;
    float costo;

    weIngresarTexto(codigo, "Ingrese el Codigo del Articulo");
    weIngresarTexto(descripcion, "Ingrese la Descripcion del Articulo");
    while (true)
    {
        weIngresarTexto(aux, "Ingrese El Impuesto");
        impuesto = aux[0];
        if (impuesto >= '0' && impuesto <= '9')
            break;
        printf("Error!! El impuesto debe ser un numero entre 0 y 9\n");
    }
    while (true)
    {
        weIngresarTexto(aux, "Ingrese La Cantidad Existente");
        cantidad = atoi(aux);
        if (cantidad > 0)
            break;
        printf("Debe ser un numero positivo\n");
    }
    while (true)
    {
        weIngresarTexto(aux, "Ingrese el Costo Unitario");
        costo = atof(aux);
        if (costo > 0)
            break;
        printf("Debe ser un numero positivo\n");
    }

    FILE *clientes = fopen("clientesRicardoSanjur.txt", "a");
    fprintf(clientes, "%s - %s\n", codigo, descripcion);
    fprintf(clientes, "'%c' - %d - %.2f\n", impuesto, cantidad, costo);
    fclose(clientes);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
