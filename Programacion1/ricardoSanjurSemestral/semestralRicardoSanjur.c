/**
 * @archivo semestralRicardoSanjur.c
 * @autor Ricardo Sanjur (ricardosanjurg@gmail.com)
 * @resumen En este proyecto intentamos hacer un menu en el que podamos
 * pedir los articulos a vender, hacer un registro de todos los articulos q tenemos
 * y poder procesar las ordenes de los clientes para la venta de los productos
 *
 * @version 0.2
 * @fecha 12-12-2021
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
typedef struct datosArticulos
{
    char codigo[10], descripcion[30], aux[10], impuesto;
    int cantidad;
    float costo;
} datosArticulos;

/**
 * @resumen Esta Funcion se encarga de pedir los articulos y registrarlos en
 * el archivo "clientesRicardoSanjur.txt"
 * 
 */
void almacenarArticulos()
{
    datosArticulos articulo;

    weIngresarTexto(articulo.codigo, "Ingrese el Codigo del Articulo");
    weIngresarTexto(articulo.descripcion, "Ingrese la Descripcion del Articulo");
    while (true)
    {
        weIngresarTexto(articulo.aux, "Ingrese El Impuesto");
        articulo.impuesto = articulo.aux[0];
        if (articulo.impuesto >= '0' && articulo.impuesto <= '9')
            break;
        printf("Error!! El impuesto debe ser un numero entre 0 y 9\n");
    }
    while (true)
    {
        weIngresarTexto(articulo.aux, "Ingrese La Cantidad Existente");
        articulo.cantidad = atoi(articulo.aux);
        if (articulo.cantidad > 0)
            break;
        printf("Debe ser un numero positivo\n");
    }
    while (true)
    {
        weIngresarTexto(articulo.aux, "Ingrese el Costo Unitario");
        articulo.costo = atof(articulo.aux);
        if (articulo.costo > 0)
            break;
        printf("Debe ser un numero positivo\n");
    }

    FILE *clientes = fopen("clientesRicardoSanjur.txt", "a");
    fprintf(clientes, "%s - %s\n", articulo.codigo, articulo.descripcion);
    fprintf(clientes, "'%c' - %d - %.2f\n", articulo.impuesto, articulo.cantidad, articulo.costo);
    fclose(clientes);
}

/**
 * @resumen esta funcion se encarga de contar la cantidad de lineas que posee
 * el archivo con los articulos y regresa la cantidad de articulos
 * 
 * @return int 
 */
int obtenerCantidadDeArticulos()
{
    FILE *clientes = fopen("clientesRicardoSanjur.txt", "r");
    if (clientes == NULL)
    {
        printf("No se encontro el Archivo \"clientesRicardoSanjur.txt\"");
        wePausa;
        exit(-1);
    }
    int cantidadArticulos = 0;
    while (!feof(clientes))
    {
        char aux[50];
        fgets(aux, 50, clientes);
        cantidadArticulos++;
    }
    fclose(clientes);
    return cantidadArticulos /= 2;
}

/**
 * @resumen esta funcion se encarga de leer los datos de los articulos existentes y
 * almacenarlos en un arreglo y lo regresa como un puntero para poder usarlo mas adelante
 * 
 * @return datosArticulos* 
 */
datosArticulos *leerValores()
{
    FILE *clientes = fopen("clientesRicardoSanjur.txt", "r");
    if (clientes == NULL)
    {
        printf("No se encontro el Archivo \"clientesRicardoSanjur.txt\"");
        wePausa;
        exit(-1);
    }

    const int CANTIDAD_ARTICULOS = obtenerCantidadDeArticulos();

    // malloc es una funcion que me permite asignar un espacio de memoria
    // y lo que hago es q el puntero apunte a ese espacio en memoria
    datosArticulos *articulo = malloc(CANTIDAD_ARTICULOS * sizeof(datosArticulos));
    for (int i = 0; i < CANTIDAD_ARTICULOS; i++)
    {
        // Tambien pude haber usado        articulo[i].codigo    pero queria probarlo de esta manera
        fscanf(clientes, "%s - %[^\n]\n", &(articulo + i)->codigo, &(articulo + i)->descripcion);
        fscanf(clientes, "'%c' - %d - %f", &(articulo + i)->impuesto, &(articulo + i)->cantidad, &(articulo + i)->costo);
    }
    fclose(clientes);
    return articulo;
}

#define multiplicar(a, b) a * b
/**
 * @resumen esta es la funcion que se encarga de registrar todos los articulos
 * y mostrarlos haciendo un resumen del inventario y lo almacena en el
 * archivo "salidaRicardoSanjur.txt"
 * 
 */
void mostrarInventario()
{
    datosArticulos *articulo = leerValores();
    float valorTotal = 0;
    FILE *salida = fopen("salidaRicardoSanjur.txt", "a");

    int CANTIDAD_ARTICULOS = obtenerCantidadDeArticulos();

    fprintf(salida, "Codigo     Descripcion                       Costo    Cantidad        Valor\n");
    for (int i = 0; i < CANTIDAD_ARTICULOS; i++)
    {
        // Tambien pude haber usado         articulo[i].costo    pero queria probarlo de esta manera
        float valorcalculado = multiplicar((articulo + i)->costo, (articulo + i)->cantidad);

        fprintf(salida, "%-8s   %-30s   %7.2f    %-4d     %12.2f\n", (articulo + i)->codigo, (articulo + i)->descripcion, (articulo + i)->costo, (articulo + i)->cantidad, valorcalculado);
        valorTotal += valorcalculado;
    }
    fprintf(salida, "\n                                                  Valor Total   %12.2f\n", valorTotal);

    fclose(salida);
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
