/**
 * @archivo semestralRicardoSanjur.c
 * @autor Ricardo Sanjur (ricardosanjurg@gmail.com)
 * @resumen En este proyecto intentamos hacer un menu en el que podamos
 * pedir los articulos a vender, hacer un registro de todos los articulos q tenemos
 * y poder procesar las ordenes de los clientes para la venta de los productos
 *
 * @version 0.4
 * @fecha 13-12-2021
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "Lib/P1/MasUsados.h"
#include "string.h"
#include "stdbool.h"
#include "time.h"

/**
 * @resumen Esta Funcion se encarga de pedir los articulos y registrarlos en
 * el archivo "clientesRicardoSanjur.txt"
 *
 */
typedef struct datosArticulos
{
    char codigo[10], descripcion[30], impuesto;
    int cantidad;
    float costo;
} datosArticulos;

/**
 * @resumen Esta Funcion se encarga de pedir los articulos y registrarlos en
 * el archivo "clientesRicardoSanjur.txt"
 *
 */
bool elArticuloExiste(int cantidad, char codigo[], datosArticulos *verificar);
datosArticulos *leerValoresDeLosArticulos();
int obtenerCantidadDeArticulos();
void almacenarArticulos()
{
    datosArticulos articulo, *verificar;
    char aux[10];
    int cantidad = obtenerCantidadDeArticulos();
    bool listo;
    if (cantidad != 0)
        verificar = leerValoresDeLosArticulos();

    while (true)
    {
        listo = true;
        weIngresarTexto(articulo.codigo, "Ingrese el Codigo del Articulo");
        strupr(articulo.codigo);
        if (cantidad == 0 || !elArticuloExiste(cantidad, articulo.codigo, verificar))
            break;
        printf("El Codigo introducido ya existe\n");
        wePausa;
    }
    free(verificar); // para liberar el espacio reservado por malloc
    weIngresarTexto(articulo.descripcion, "Ingrese la Descripcion del Articulo");

    while (true)
    {
        weIngresarTexto(aux, "Ingrese El Impuesto");
        articulo.impuesto = aux[0];
        if (articulo.impuesto >= '0' && articulo.impuesto <= '9')
            break;
        printf("Error!! El impuesto debe ser un numero entre 0 y 9\n");
        wePausa;
    }
    while (true)
    {
        weIngresarTexto(aux, "Ingrese La Cantidad Existente");
        articulo.cantidad = atoi(aux);
        if (articulo.cantidad > 0)
            break;
        printf("Debe ser un numero positivo\n");
        wePausa;
    }
    while (true)
    {
        weIngresarTexto(aux, "Ingrese el Costo Unitario");
        articulo.costo = atof(aux);
        if (articulo.costo > 0)
            break;
        printf("Debe ser un numero positivo\n");
        wePausa;
    }

    FILE *clientes = fopen("clientesRicardoSanjur.txt", "a");
    fprintf(clientes, "%s %s\n", articulo.codigo, articulo.descripcion);
    fprintf(clientes, "'%c' %d %.2f\n", articulo.impuesto, articulo.cantidad, articulo.costo);
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
        return 0;
    int cantidadArticulos = 0;
    while (!feof(clientes))
    {
        char aux[100];
        fgets(aux, 100, clientes);
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
datosArticulos *leerValoresDeLosArticulos()
{
    FILE *clientes = fopen("clientesRicardoSanjur.txt", "r");
    if (clientes == NULL)
    {
        printf("No se encontro el Archivo \"clientesRicardoSanjur.txt\"\n");
        printf("Este archivo se generara automaticamente si almacena algun articulo\n");
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
        fscanf(clientes, "%s %[^\n]\n", &(articulo + i)->codigo, &(articulo + i)->descripcion);
        fscanf(clientes, "'%c' %d %f", &(articulo + i)->impuesto, &(articulo + i)->cantidad, &(articulo + i)->costo);
    }
    fclose(clientes);
    return articulo;
}

#define multiplicar(a, b) a *b
/**
 * @resumen esta es la funcion que se encarga de registrar todos los articulos
 * y mostrarlos haciendo un resumen del inventario y lo almacena en el
 * archivo "salidaRicardoSanjur.txt"
 *
 */
void imprimirFormato(char texto[], FILE *archivo);
void mostrarInventario()
{
    datosArticulos *articulo = leerValoresDeLosArticulos();
    float valorTotal = 0;
    FILE *salida = fopen("salidaRicardoSanjur.txt", "a");
    imprimirFormato("REPORTE DE VALORIZACION DE INVENTARIO", salida);
    const int CANTIDAD_ARTICULOS = obtenerCantidadDeArticulos();
    if (CANTIDAD_ARTICULOS == 0)
    {
        printf("No hay Articulos Disponibles\n\n");
        wePausa;
        return;
    }

    fprintf(salida, "Codigo     Descripcion                       Costo    Cantidad        Valor\n");
    for (int i = 0; i < CANTIDAD_ARTICULOS; i++)
    {
        // Tambien pude haber usado         articulo[i].costo    pero queria probarlo de esta manera
        float valorcalculado = multiplicar((articulo + i)->costo, (articulo + i)->cantidad);

        fprintf(salida, "%-8s   %-30s   %7.2f    %-4d     %12.2f\n", (articulo + i)->codigo, (articulo + i)->descripcion, (articulo + i)->costo, (articulo + i)->cantidad, valorcalculado);
        valorTotal += valorcalculado;
    }
    fprintf(salida, "\n                                                  Valor Total   %12.2f\n", valorTotal);
    free(articulo); // para liberar el espacio reservado por malloc
    fclose(salida);
    printf("\nPuede ver el Inventario en el archivo de salida\n\n");
    wePausa;
}
/**
 * @resumen esta funcion nos ayudara a poder actualizar nuestro almacen o inventario
 * poniendonos al dia sobre las cosas q se compraron
 *
 * @parametro cantidad
 * @parametro articulo
 */
void actualizarAlmacen(int cantidad, datosArticulos *articulo)
{
    FILE *clientes = fopen("clientesRicardoSanjur.txt", "w");
    for (int i = 0; i < cantidad; i++)
    {
        fprintf(clientes, "%s %s\n", articulo[i].codigo, articulo[i].descripcion);
        fprintf(clientes, "'%c' %d %.2f\n", articulo[i].impuesto, articulo[i].cantidad, articulo[i].costo);
    }
    fclose(clientes);
}
/**
 * @resumen esta funcion comprueba si el codigo q insertamos existe en el arreglo de datos
 *
 * @parametro cantidad
 * @parametro codigo
 * @parametro verificar
 * @return true
 * @return false
 */
bool elArticuloExiste(int cantidad, char codigo[], datosArticulos *verificar)
{
    bool listo = false;
    for (int i = 0; i < cantidad; i++)
        if (strcmp(verificar[i].codigo, strupr(codigo)) == 0)
            listo = true;
    return listo;
}
/**
 * @resumen esta es la funcion que llamamos cuando elegimos mal el codigo del producto a comprar
 * y nos sirve para visualizar los productos existentes
 *
 * @parametro cantidad
 * @parametro articulo
 */
void mostrarArticulosDisponibles(int cantidad, datosArticulos *articulo)
{
    if (cantidad == 0)
    {
        printf("No hay Articulos Disponibles\n\n");
        wePausa;
        return;
    }
    printf("\nCodigo     Descripcion                       Costo    Cantidad\n");
    for (int i = 0; i < cantidad; i++)
        printf("%-8s   %-30s   %7.2f    %-4d\n", (articulo + i)->codigo, (articulo + i)->descripcion, (articulo + i)->costo, (articulo + i)->cantidad);
    printf("\n");
}
/**
 * @resumen esta funcion es la que nos permite comparar el codigo que le ingresamos con los codigos
 * que existen en nuestro inventario, de encontrarlo devuelve su posicion en el arreglo
 *
 * @parametro cantidad
 * @parametro articulo
 * @parametro codigo
 * @return int
 */
int encontrarArticulo(int cantidad, datosArticulos *articulo, char codigo[])
{
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(articulo[i].codigo, strupr(codigo)) == 0)
            return i;
    }
}
/**
 * @resumen esta funcion es la que va imprimiendo parte de la factura, para evitar tener
 * que almacenar cada dato de la factura, mejor vamos imprimiendolo en el camino
 *
 * @parametro salida
 * @parametro articulo
 * @parametro indiceArticulo
 * @parametro cantidad
 * @parametro precioDeVenta
 * @return float
 */
float imprimirArticuloComprado(FILE *salida, datosArticulos *articulo, int indiceArticulo, int cantidad, float precioDeVenta)
{
    float valor = multiplicar(precioDeVenta, cantidad);
    fprintf(salida, "%-8s   %-30s   %7.2f    %-4d     %12.2f\n", articulo[indiceArticulo].codigo, articulo[indiceArticulo].descripcion, precioDeVenta, cantidad, valor);

    return valor;
}
/**
 * @resumen esta es la funcion en la que pedimos y verificamos el codigo y la cantidad
 * si insertamos un codigo incorrecto se nos mostrara una lista con las opciones
 *
 * @parametro salida
 * @parametro CANTIDAD_ARTICULOS
 * @parametro articulo
 * @parametro codigo
 * @parametro cantidad
 * @return true
 * @return false
 */
bool ingresarCodigoYCantidad(FILE *salida, int CANTIDAD_ARTICULOS, datosArticulos *articulo, char codigo[], int *cantidad)
{
    char aux[10];
    int indiceArticulo;
    while (true)
    {
        printf("Los Articulos Disponibles son los siguientes\n\n");
        mostrarArticulosDisponibles(CANTIDAD_ARTICULOS, articulo);
        weIngresarTexto(codigo, "Ingrese el Codigo del Articulo, Ingrese \"0\" para Finalizar");
        if (strcmp(codigo, "0") == 0)
            return false;
        if (elArticuloExiste(CANTIDAD_ARTICULOS, codigo, articulo))
        {
            indiceArticulo = encontrarArticulo(CANTIDAD_ARTICULOS, articulo, codigo);
            if (articulo[indiceArticulo].cantidad == 0)
            {
                printf("Articulo Agotado!!\n");
                wePausa;
                continue;
            }
            break;
        }

        printf("El Codigo Ingresado no Existe\n");
        wePausa;
    }

    int cantidadMaxima = articulo[indiceArticulo].cantidad;
    while (true)
    {
        weIngresarTexto(aux, "Ingrese la Cantidad que va a Comprar");
        *cantidad = atoi(aux);
        if (*cantidad > 0 && *cantidad <= cantidadMaxima)
            break;
        printf("La Cantidad Ingresada Debe ser menor o igual a %d y ser positiva\n", cantidadMaxima);
        wePausa;
    }
    articulo[indiceArticulo].cantidad -= *cantidad;
    actualizarAlmacen(CANTIDAD_ARTICULOS, articulo);
    return true;
}
/**
 * @resumen esta funcion es la que nos permite seleccionar el precio a que venderemos
 * nuestro producto
 *
 * @parametro indiceArticulo
 * @parametro articulo
 * @return float
 */
float elegirPrecioDeVenta(int indiceArticulo, datosArticulos *articulo)
{
    float costo = articulo[indiceArticulo].costo;
    const float costoMasPorcentaje[3] = {
        costo * 1.15,
        costo * 1.27,
        costo * 1.35};
    while (true)
    {
        printf("Elija un Precio De venta Para El producto solicitado\n");
        printf("1) %.2f\n", costoMasPorcentaje[0]);
        printf("2) %.2f\n", costoMasPorcentaje[1]);
        printf("3) %.2f\n", costoMasPorcentaje[2]);
        char aux[10];
        weIngresarTexto(aux, "Ingrese una de las Opciones");
        int opcion = atoi(aux);
        if (opcion >= 1 && opcion <= 3)
            return costoMasPorcentaje[opcion - 1];
        printf("Ingrese una Opcion Valida\n");
        wePausa;
    }
}
/**
 * @resumen esta funcion es la encargada de registrar las ventas de cada uno de los clientes como si
 * fuesen facturas en las que se mostraran todos los datos relevantes
 *
 */
void registrarVentas()
{
    char nombre[20], codigo[10];
    int cantidad;
    datosArticulos *articulo = leerValoresDeLosArticulos();
    const int CANTIDAD_ARTICULOS = obtenerCantidadDeArticulos();

    if (CANTIDAD_ARTICULOS == 0)
    {
        printf("No hay Articulos Disponibles\n\n");
        wePausa;
        return;
    }
    weIngresarTexto(nombre, "Nombre del Cliente");
    FILE *salida = fopen("salidaRicardoSanjur.txt", "a");
    imprimirFormato("         REPORTE DE VENTAS", salida);
    fprintf(salida, "NOMBRE DEL CLIENTE: %s\n\n", nombre);

    // esta parte es para que se imprima la fecha y la hora, como lo verias en una factura
    time_t tiempo = time(0);
    struct tm *tiempoLocal = localtime(&tiempo);
    char FechaYHora[20];
    strftime(FechaYHora, 20, "%d/%m/%y %H:%M:%S", tiempoLocal);
    fprintf(salida, "%s\n\n", FechaYHora);

    bool ingresarOtroArticulo;
    float subtotal = 0;
    char listaPorcentajes[50] = "";
    int listaIndices[20];
    int i = 0;
    fprintf(salida, "Codigo     Descripcion                       Precio   Cantidad        Valor\n");
    while (true)
    {
        if (!ingresarCodigoYCantidad(salida, CANTIDAD_ARTICULOS, articulo, codigo, &cantidad))
            break;
        listaIndices[i] = encontrarArticulo(CANTIDAD_ARTICULOS, articulo, codigo);
        int precioDeVenta = elegirPrecioDeVenta(listaIndices[i], articulo);
        float porcentaje = imprimirArticuloComprado(salida, articulo, listaIndices[i], cantidad, precioDeVenta);
        sprintf(listaPorcentajes, "%s%.2f,", listaPorcentajes, porcentaje);
        subtotal += porcentaje;
        i++;
    }

    fprintf(salida, "\n                                                                ------------\n");
    fprintf(salida, "\n                                                    Sub Total   %12.2f\n", subtotal);
    fprintf(salida, "\n                                                                ------------\n");
    char *porcentaje = strtok(listaPorcentajes, ","); // con esto voy a poder ir obteniendo uno a uno los diferentes porcentajes o impuestos
    i = 0;
    float totalPorcentajes = 0;
    while (porcentaje != NULL)
    {
        char impuestoActual = articulo[listaIndices[i++]].impuesto;
        int impuesto = impuestoActual == '1' ? 10 : impuestoActual - 48;
        float porcentajePorImpuesto = atof(porcentaje) * impuesto / 100.0;
        fprintf(salida, "\n                                                          %d%%   %12.2f\n", impuesto, porcentajePorImpuesto);
        totalPorcentajes += porcentajePorImpuesto;
        porcentaje = strtok(NULL, ","); // esto es para seguir con el siguiente valor
    }
    fprintf(salida, "\n                                                                ------------\n");
    fprintf(salida, "\n                                               Total Impuesto   %12.2f\n", totalPorcentajes);
    fprintf(salida, "\n                                                                ============\n");
    fprintf(salida, "\n                                                Total a Pagar   %12.2f\n", totalPorcentajes + subtotal);
    free(articulo);
    fclose(salida);
}
/**
 * @resumen En esta funcion añadimos un valor a la cantidad actual del producto seleccionado
 *
 */
void reabastecerAlmacen()
{
    datosArticulos *articulo = leerValoresDeLosArticulos();
    const int CANTIDAD_ARTICULOS = obtenerCantidadDeArticulos();
    char codigo[10], aux[10];
    int cantidad;
    if (CANTIDAD_ARTICULOS == 0)
    {
        printf("No hay Articulos Disponibles\n\n");
        wePausa;
        return;
    }

    while (true)
    {
        printf("Estos Son los Articulos Actuales:\n");
        mostrarArticulosDisponibles(CANTIDAD_ARTICULOS, articulo);
        printf("Ingrese el codigo del producto al que quiere reavastecer\n");
        printf("(Esta cantidad se a%cadira a la existente)\n", 164);
        weIngresarTexto(codigo, "Codigo");
        if (elArticuloExiste(CANTIDAD_ARTICULOS, codigo, articulo))
            break;
        printf("El Codigo Ingresado no Existe\n");
        wePausa;
    }
    while (true)
    {
        weIngresarTexto(aux, "Ingrese la Cantidad que va a Reabastecer");
        cantidad = atoi(aux);
        if (cantidad >= 0)
            break;
        printf("La Cantidad Ingrada debe ser positiva\n");
        wePausa;
    }
    int indiceArticulo = encontrarArticulo(CANTIDAD_ARTICULOS, articulo, codigo);
    articulo[indiceArticulo].cantidad += cantidad;
    actualizarAlmacen(CANTIDAD_ARTICULOS, articulo);
    free(articulo);
}
/**
 * @resumen aki imprimimos nuestro menu principal
 *
 */
void menu()
{
    printf("################################\n");
    printf("#-----OPCIONES-DISPONIBLES-----#\n");
    printf("#--1)*Almacenar-Los-Articulos--#\n");
    printf("#--2)*Imprimir-El-Inventario---#\n");
    printf("#--3)*Realizar-Ventas----------#\n");
    printf("#--4)*Reabastecer-El-Almacen---#\n");
    printf("#--5)*(((SALIR)))--------------#\n");
    printf("################################\n");
}
/**
 * @resumen esta funcion nos mostrara una brebe presentacion para el trabajo
 *
 * @parametro texto
 */
void mostrarPresentacion(char texto[])
{
    system("cls");
    printf("\n\n");
    printf("             UNIVERSIDAD TECNOLOGICA DE PANAMA\n");
    printf("                CENTRO REGIONAL DE CHIRIQUI\n");
    printf("     LICENCIATURA EN INGENIERIA DE SISTEMAS Y COMPUTACION\n");
    printf("ESTUDIANTE: Ricardo Sanjur PROFESORA: Cecilia Gonzalez de Beitia\n");
    printf("            %s\n", texto);
    printf("                     EXAMEN SEMESTRAL\n");
    printf("\n\n");
}
/**
 * @resumen Esta funcion es exlusiva para imprimir el formato en los archivos
 *
 * @parametro texto
 * @parametro archivo
 */
void imprimirFormato(char texto[], FILE *archivo)
{
    fprintf(archivo, "\n\n");
    fprintf(archivo, "             UNIVERSIDAD TECNOLOGICA DE PANAMA\n");
    fprintf(archivo, "                CENTRO REGIONAL DE CHIRIQUI\n");
    fprintf(archivo, "     LICENCIATURA EN INGENIERIA DE SISTEMAS Y COMPUTACION\n");
    fprintf(archivo, "ESTUDIANTE: Ricardo Sanjur PROFESORA: Cecilia Gonzalez de Beitia\n");
    fprintf(archivo, "           %s\n", texto);
    fprintf(archivo, "                     EXAMEN SEMESTRAL\n");
    fprintf(archivo, "\n\n");
}

int main(int argc, char const *argv[])
{

    char aux[10];
    int elegida;
    void (*opcion[])() = {
        almacenarArticulos,
        mostrarInventario,
        registrarVentas,
        reabastecerAlmacen};
    char pregunta[4][50] = {
        "Desea Almacenar Otro Articulo?",
        "el inventario solo se ve una vez no se repite",
        "Desea Registrar Otra Venta?",
        "Desea Reabastecer Otro Articulo del Almacen?"};
    char textoPresentacion[4][40] = {
        "        ALMACENAR ARTICULO",
        "REPORTE DE VALORIZACION DE INVENTARIO",
        "         VENDER ARTICULOS",
        "       REABASTECER ARTICULOS"};

    while (true)
    {
        while (true)
        {
            mostrarPresentacion("       PROGRAMA EMPRESARIAL");
            menu();
            weIngresarTexto(aux, "Ingrese una de las Opciones");
            elegida = atoi(aux);
            if (elegida >= 1 && elegida <= 5)
                break;
            printf("Opcion Incorrecta, Vuelva a Intentarlo...\n");
            wePausa;
        }
        switch (elegida)
        {
        case 5:
            exit(EXIT_SUCCESS);
            break;

        default:
            do
            {
                mostrarPresentacion(textoPresentacion[elegida - 1]);
                opcion[elegida - 1]();
                if (elegida == 2)
                    break;
            } while (wePreguntarSN(false, pregunta[elegida - 1]));
            break;
        }
    }

    return 0;
}
