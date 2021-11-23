/**
 * @archivo ProyectoIndividual.c
 * @autor Ricardo Sanjur (ricardosanjurg@gmail.com)
 * @resumen Hay que leer de un archivo llamado "DATOS.txt" la informacion
 *          de ciertos alumnos y procesarla, los resultados de esta
 *          se almacenaran en un archivo nuevo llamado "DatosProcesados.txt"
 * @version 0.5
 * @fecha 22-11-2021
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Lib/P1/MasUsados.h"

/**
 * @resumen nos permite calcular la cantidad de puntos que se obtubo gracias a la
 *          nota obtenida
 *
 * @parametro creditos
 * @parametro nota
 * @return int
 */
int calcularPuntos(int creditos, char nota)
{
    if (nota == 'A')
        return creditos * 3;
    else if (nota == 'B')
        return creditos * 2;
    else if (nota == 'C')
        return creditos * 1;
    else
        return 0;
}

void almacenarParametros(int cantidadAlumnos, int cantidadSemestres, int cantidadMaterias)
{
    FILE *parametros = fopen("PARAMETROS.txt", "w");
    fprintf(parametros, "%d %d %d", cantidadAlumnos, cantidadSemestres, cantidadMaterias);
    fclose(parametros);
}

void *leerParametros(int *cantidadAlumnos, int *cantidadSemestres, int *cantidadMaterias)
{
    FILE *parametros = fopen("PARAMETROS.txt", "r");
    if (parametros == NULL)
        return 1;
    fscanf(parametros, "%d %d %d", cantidadAlumnos, cantidadSemestres, cantidadMaterias);
    fclose(parametros);
}

void determinarValores()
{
    int cantidadAlumnos, cantidadSemestres, cantidadMaterias;
    FILE *nombres = fopen("NOMBRES.txt", "r");
    int limiteNombres = 0;
    if (nombres != NULL)
    {
        while (!feof(nombres))
        {
            char aux[30];
            fscanf(nombres, "%[^\n]\n", &aux);
            limiteNombres++;
        }
    }
    else
    {
        limiteNombres = 100;
    }
    FILE *materias = fopen("MATERIAS.txt", "r");
    int limiteMaterias = 0;
    if (materias != NULL)
    {
        while (!feof(materias))
        {
            char aux[30];
            fscanf(materias, "%[^\n]\n", &aux);
            limiteMaterias++;
        }
    }
    else
    {
        limiteMaterias = 100;
    }

    fclose(nombres);
    fclose(materias);

    printf("\n**ADVERTENCIA** Si Usted solo quiere procesar los datos de un Archivo \"DATOS.txt\" ya creado");
    printf("\nAsegurese de Poner La Cantidad de Alumnos, Semestres(contando los de solo 1 alumno), \ny Materias(Contando las solo 1 semestre)\n\n");
    while (true)
    {
        cantidadAlumnos = weIngresarEntero("Ingrese la Cantidad de Alumnos");
        if (cantidadAlumnos >= 1 && cantidadAlumnos <= limiteNombres)
            break;
        printf("La cantidad de Alumnos debe estar entre 1 y %d\n", limiteNombres);
    }
    while (true)
    {
        cantidadSemestres = weIngresarEntero("Ingrese la Cantidad de Semestres");
        if (cantidadSemestres >= 1 && cantidadSemestres <= 100)
            break;
        printf("La cantidad de Semestres debe estar entre 1 y 100\n");
    }
    while (true)
    {
        cantidadMaterias = weIngresarEntero("Ingrese la Cantidad de Materias");
        if (cantidadMaterias >= 1 && cantidadMaterias <= limiteMaterias)
            break;
        printf("La cantidad de Materias debe estar entre 1 y %d\n", limiteMaterias);
    }
    almacenarParametros(cantidadAlumnos, cantidadSemestres, cantidadMaterias);
    printf("\nArchivo \"PARAMETROS\" Creado Con Exito!\n\n");
}

void procesarLosDatosYGuardarlos()
{
    int CANTIDAD_DE_ALUMNOS, CANTIDAD_DE_SEMESTRES, CANTIDAD_DE_MATERIAS;
    FILE *datos = fopen("DATOS.txt", "r");
    if (datos == NULL)
    {
        printf("\nNo se pudo encontrar el archivo \"DATOS.txt\"\n\n");
        return;
    }

volverALeer:
    if ((int)leerParametros(&CANTIDAD_DE_ALUMNOS, &CANTIDAD_DE_SEMESTRES, &CANTIDAD_DE_MATERIAS) == 1)
    {
        determinarValores();
        goto volverALeer;
    }
    struct alumno
    {
        char nombre[25];
        int periodo[CANTIDAD_DE_SEMESTRES];
        int semestre[CANTIDAD_DE_SEMESTRES];

        int creditosTotales[CANTIDAD_DE_SEMESTRES];
        int puntos[CANTIDAD_DE_SEMESTRES];
        float indice[CANTIDAD_DE_SEMESTRES];
    };

    struct alumno estudiante[CANTIDAD_DE_ALUMNOS];
    for (int conteoAlumnos = 0; conteoAlumnos < CANTIDAD_DE_ALUMNOS; conteoAlumnos++)
    {
        fscanf(datos, "%[^\n]\n", &estudiante[conteoAlumnos].nombre);
        for (int conteoSemestres = 0; conteoSemestres < CANTIDAD_DE_SEMESTRES; conteoSemestres++)
        {
            fscanf(datos, "%d %d\n", &estudiante[conteoAlumnos].periodo[conteoSemestres], &estudiante[conteoAlumnos].semestre[conteoSemestres]);
            estudiante[conteoAlumnos].puntos[conteoSemestres] = 0;
            estudiante[conteoAlumnos].creditosTotales[conteoSemestres] = 0;
            for (int conteoMaterias = 0; conteoMaterias < CANTIDAD_DE_MATERIAS; conteoMaterias++)
            {
                int creditos;
                char codigoAsignatura[5], descripcion[50], nota;
                fscanf(datos, "%d %s %c %[^\n]\n", &creditos, &codigoAsignatura, &nota, &descripcion);
                estudiante[conteoAlumnos].creditosTotales[conteoSemestres] += creditos;
                estudiante[conteoAlumnos].puntos[conteoSemestres] += calcularPuntos(creditos, nota);
            }
            estudiante[conteoAlumnos].indice[conteoSemestres] = (float)estudiante[conteoAlumnos].puntos[conteoSemestres] / estudiante[conteoAlumnos].creditosTotales[conteoSemestres];
        }
    }
    fclose(datos);

    FILE *salida = fopen("DatosProcesados.txt", "w");
    for (int conteoAlumnos = 0; conteoAlumnos < CANTIDAD_DE_ALUMNOS; conteoAlumnos++)
    {
        if (conteoAlumnos != 0)
            fprintf(salida, "\n");
        fprintf(salida, "%s", estudiante[conteoAlumnos].nombre);
        fprintf(salida, "\n      Semestre   Puntos   Total/Cr   Indice   Condicional", estudiante[conteoAlumnos].nombre);
        int condicional = 0;
        for (int conteoSemestres = 0; conteoSemestres < CANTIDAD_DE_SEMESTRES; conteoSemestres++)
        {
            if (estudiante[conteoAlumnos].indice[conteoSemestres] < 1)
                condicional += 1;
            else
                condicional = 0;
            fprintf(salida, "\n%d  %5d   %7d   %7d   %8.2f   %7d", estudiante[conteoAlumnos].periodo[conteoSemestres], estudiante[conteoAlumnos].semestre[conteoSemestres], estudiante[conteoAlumnos].puntos[conteoSemestres], estudiante[conteoAlumnos].creditosTotales[conteoSemestres], estudiante[conteoAlumnos].indice[conteoSemestres], condicional);
            if (condicional == 3)
            {
                fprintf(salida, "       CAMBIO DE CARRERA\n");
                break;
            }
        }
        fprintf(salida, "\n");
    }
    fclose(salida);
    printf("\nDatos Procesados Correctamente\nPuede Ver los Resultados en el Archivo \"DatosProcesados.txt\" que hemos generado\n\n");
}

char *generarCodigoMateria()
{
    static char codigo[5];
    strcpy(codigo, "");
    for (int i = 0; i < 4; i++)
        sprintf(codigo, "%s%d", codigo, weNumeroAleatorio(0, 9));
    return codigo;
}
int sacaNumeroSinRepetir(int pos, int arreglo[], int min, int max)
{
    bool listo;
    int num;
    while (true)
    {
        listo = true;
        num = weNumeroAleatorio(min, max);
        for (int i = 0; i < pos; i++)
            if (arreglo[i] == num)
            {
                listo = false;
                break;
            }
        if (listo)
            break;
    }
    arreglo[pos] = num;
    return num;
}

void crearArchivo()
{
    int cantidadAlumnos, cantidadSemestres, cantidadMaterias;
    FILE *nombres = fopen("NOMBRES.txt", "r");
    FILE *materias = fopen("MATERIAS.txt", "r");
    if (nombres == NULL)
    {
        printf("\nNo se pudo encontrar el archivo \"NOMBRES.txt\"");
        printf("\nUsted Puede Crear el suyo, solo debe escribir un nombre por linea\n\n");
        return;
    }
    if (materias == NULL)
    {
        printf("\nNo se pudo encontrar el archivo \"MATERIAS.txt\"");
        printf("\nUsted Puede Crear el suyo, solo debe seguir el siguiente formato");
        printf("\n00 XXXXXXXXXX  \nDonde los 00 significan la cantidad de creditos y las XXXXX el nombre de la Materia\n\n");
        return;
    }
    FILE *nuevo = fopen("DATOS.txt", "w");
    int periodo, semestre = 1;
    determinarValores();
volverALeer:
    if ((int)leerParametros(&cantidadAlumnos, &cantidadSemestres, &cantidadMaterias) == 1)
    {
        printf("\nError al Leer los Valores Vuelva a Ingresar las Cantidades\n\n");
        determinarValores();
        goto volverALeer;
    }
    while (true)
    {
        printf("Ingrese el a%co inicial", 164);
        periodo = weIngresarEntero("");
        if (periodo > 0)
            break;
        printf("La cantidad deber ser Positiva\n");
    }

    int lineasNombre = 0;
    while (!feof(nombres))
    {
        char aux[30];
        fscanf(nombres, "%[^\n]\n", &aux);
        lineasNombre++;
    }

    rewind(nombres);
    char listaNombres[lineasNombre][25];
    for (int i = 0; i < lineasNombre; i++)
        fscanf(nombres, "%[^\n]\n", &listaNombres[i]);

    int lineasMaterias = 0;
    while (!feof(materias))
    {
        char aux[50];
        fscanf(materias, "%[^\n]\n", &aux);
        lineasMaterias++;
    }

    rewind(materias);
    struct creditosYMaterias
    {
        int creditos;
        char descripcion[45];
    } listaMaterias[lineasMaterias];
    for (int i = 0; i < lineasMaterias; i++)
        fscanf(materias, "%d %[^\n]\n", &listaMaterias[i].creditos, &listaMaterias[i].descripcion);

    int nombresUsados[lineasNombre];

    for (int i = 0; i < cantidadAlumnos; i++)
    {
        fprintf(nuevo, "%s\n", listaNombres[sacaNumeroSinRepetir(i, nombresUsados, 0, lineasNombre - 1)]);

        for (int j = 0; j < cantidadSemestres; j++)
        {
            fprintf(nuevo, "%d %d\n", periodo + j / 2, semestre + j % 2);
            int materiasIngresadas = weNumeroAleatorio(1, cantidadMaterias);
            int materiasUsadas[cantidadMaterias];
            for (int k = 0; k < cantidadMaterias; k++)
            {
                if (k < materiasIngresadas)
                {
                    int indiceSinRepetir = sacaNumeroSinRepetir(k, materiasUsadas, 0, lineasMaterias - 1);
                    char letra = weNumeroAleatorio(65, 69);
                    letra = letra == 69 ? 'F' : letra;
                    fprintf(nuevo, "%d %s %c %s\n", listaMaterias[indiceSinRepetir].creditos, generarCodigoMateria(), letra, listaMaterias[indiceSinRepetir].descripcion);
                }
                else
                    fprintf(nuevo, "0 0000 X XXXXXXXXX\n");
            }
        }
    }
    fclose(nuevo);
    fclose(materias);
    fclose(nombres);
    printf("\nHemos Generado Su Archivo \"DATOS.txt\" Exitosamente!\n\n");
    procesarLosDatosYGuardarlos();
}

void menu()
{
    printf("SELECCIONE UNA DE LAS OPCIONES\n");
    printf("1) PROCESAR MI ARCHIVO \"DATOS.txt\"\n");
    printf("2) CREAR NUEVO ARCHIVO \"DATOS.txt\"\n");
    printf("3) ESTABLECER LA CANTIDAD DE ALUMNOS, SEMESTRE Y MATERIAS\n");
    printf("4) SALIR\n");
}
#define MENU "Ricardo Sanjur", 3, "      ProyectoArchivos", "2IL112", 2021, "2do", true, "Cecilia Gonzales"
int main(int argc, char const *argv[])
{
    wePresentacion(MENU);
    while (true)
    {
        weSemilla;
        menu();
        int elegido;
        void (*opcion[])() = {procesarLosDatosYGuardarlos,
                              crearArchivo,
                              determinarValores};
        while (true)
        {
            elegido = weIngresarEntero("Ingrese Una opcion");
            if (elegido >= 1 && elegido <= 4)
                break;
            printf("****INGRESE UNA OPCION VALIDA****\n");
        }
        if (elegido != 4)
            opcion[elegido - 1]();
        else
            break;
    }
    return 0;
}