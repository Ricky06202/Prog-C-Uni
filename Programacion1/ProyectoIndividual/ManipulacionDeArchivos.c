/**
 * @archivo ProyectoIndividual.c
 * @autor Ricardo Sanjur (ricardosanjurg@gmail.com)
 * @resumen Hay que leer de un archivo llamado "DATOS.txt" la informacion
 *          de ciertos alumnos y procesarla, los resultados de esta
 *          se almacenaran en un archivo nuevo llamado "DatosProcesados.txt"
 * @version 0.3
 * @fecha 17-11-2021
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "stdio.h"
#include "stdlib.h"
#define CANTIDAD_DE_SEMESTRES 3
#define CANTIDAD_DE_MATERIAS 6
struct alumno
{
    char nombre[25];
    int periodo[CANTIDAD_DE_SEMESTRES];
    int semestre[CANTIDAD_DE_SEMESTRES];
    int creditos;
    char codigoAsignatura[5];
    char nota;
    char descripcion[50];

    int creditosTotales[CANTIDAD_DE_SEMESTRES];
    int puntos[CANTIDAD_DE_SEMESTRES];
    float indice[CANTIDAD_DE_SEMESTRES];
    int condicional;
};
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

#define CANTIDAD_DE_ALUMNOS 6
int main(int argc, char const *argv[])
{
    FILE *datos = fopen("DATOS.txt", "r");
    struct alumno estudiante[CANTIDAD_DE_ALUMNOS];
    int conteoAlumnos = 0;
    while (!feof(datos))
    {
        fscanf(datos, "%[^\n]\n", &estudiante[conteoAlumnos].nombre);
        estudiante[conteoAlumnos].condicional = 0;
        for (int i = 0; i < CANTIDAD_DE_SEMESTRES; i++)
        {
            fscanf(datos, "%d %d\n", &estudiante[conteoAlumnos].periodo[i], &estudiante[conteoAlumnos].semestre[i]);
            estudiante[conteoAlumnos].creditosTotales[i] = 0;
            estudiante[conteoAlumnos].puntos[i] = 0;
            for (int j = 0; j < CANTIDAD_DE_MATERIAS; j++)
            {
                fscanf(datos, "%d %s %c %[^\n]\n", &estudiante[conteoAlumnos].creditos, &estudiante[conteoAlumnos].codigoAsignatura, &estudiante[conteoAlumnos].nota, &estudiante[conteoAlumnos].descripcion);
                estudiante[conteoAlumnos].creditosTotales[i] += estudiante[conteoAlumnos].creditos;
                estudiante[conteoAlumnos].puntos[i] += calcularPuntos(estudiante[conteoAlumnos].creditos, estudiante[conteoAlumnos].nota);
            }
            estudiante[conteoAlumnos].indice[i] = (float)estudiante[conteoAlumnos].puntos[i] / (float)estudiante[conteoAlumnos].creditosTotales[i];
        }
        conteoAlumnos++;
    }
    fclose(datos);

    FILE *salida = fopen("DatosProcesados.txt", "w");
    for (int i = 0; i < CANTIDAD_DE_ALUMNOS; i++)
    {
        fprintf(salida, "%30s   Semestre   Puntos   Total/Cr   Indice   Condicional\n", estudiante[i].nombre);
        estudiante[i].condicional = 0;
        for (int j = 0; j < CANTIDAD_DE_SEMESTRES; j++)
        {
            if (estudiante[i].indice[j] < 1)
                estudiante[i].condicional += 1;
            else
                estudiante[i].condicional = 0;
            fprintf(salida, "%25d  %11d   %7d   %7d   %8.2f   %7d", estudiante[i].periodo[j], estudiante[i].semestre[j], estudiante[i].puntos[j], estudiante[i].creditosTotales[j], estudiante[i].indice[j], estudiante[i].condicional);
            fprintf(salida, "\n");
        }
        if(estudiante[i].condicional == 3)
            fprintf(salida, "                    CAMBIO DE CARRERA\n");
        fprintf(salida, "\n");
    }
    fclose(salida);
    return 0;
}
