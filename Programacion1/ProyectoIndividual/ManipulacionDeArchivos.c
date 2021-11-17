/**
 * @archivo ProyectoIndividual.c
 * @autor Ricardo Sanjur (ricardosanjurg@gmail.com)
 * @resumen Hay que leer de un archivo llamado "DATOS.txt" la informacion
 *          de ciertos alumnos y procesarla, los resultados de esta
 *          se almacenaran en un archivo nuevo llamado "DatosProcesados.txt"
 * @version 0.4
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

    int creditosTotales[CANTIDAD_DE_SEMESTRES];
    int puntos[CANTIDAD_DE_SEMESTRES];
    float indice[CANTIDAD_DE_SEMESTRES];
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
        for (int i = 0; i < CANTIDAD_DE_SEMESTRES; i++)
        {
            fscanf(datos, "%d %d\n", &estudiante[conteoAlumnos].periodo[i], &estudiante[conteoAlumnos].semestre[i]);
            estudiante[conteoAlumnos].puntos[i] = 0;
            estudiante[conteoAlumnos].creditosTotales[i] = 0;
            for (int j = 0; j < CANTIDAD_DE_MATERIAS; j++)
            {
                int creditos;
                char codigoAsignatura[5], descripcion[50], nota;
                fscanf(datos, "%d %s %c %[^\n]\n", &creditos, &codigoAsignatura, &nota, &descripcion);
                estudiante[conteoAlumnos].creditosTotales[i] += creditos;
                estudiante[conteoAlumnos].puntos[i] += calcularPuntos(creditos, nota);
            }
            estudiante[conteoAlumnos].indice[i] = (float)estudiante[conteoAlumnos].puntos[i] / estudiante[conteoAlumnos].creditosTotales[i];
        }
        conteoAlumnos++;
    }
    fclose(datos);

    FILE *salida = fopen("DatosProcesados.txt", "w");
    for (int i = 0; i < CANTIDAD_DE_ALUMNOS; i++)
    {
        if (i != 0)
            fprintf(salida, "\n");
        fprintf(salida, "%s", estudiante[i].nombre);
        fprintf(salida, "\n      Semestre   Puntos   Total/Cr   Indice   Condicional", estudiante[i].nombre);
        int condicional = 0;
        for (int j = 0; j < CANTIDAD_DE_SEMESTRES; j++)
        {
            if (estudiante[i].indice[j] < 1)
                condicional += 1;
            else
                condicional = 0;
            fprintf(salida, "\n%d  %5d   %7d   %7d   %8.2f   %7d", estudiante[i].periodo[j], estudiante[i].semestre[j], estudiante[i].puntos[j], estudiante[i].creditosTotales[j], estudiante[i].indice[j], condicional);
        }
        if (condicional == 3)
            fprintf(salida, "       CAMBIO DE CARRERA\n");
        if (i != CANTIDAD_DE_ALUMNOS - 1)
            fprintf(salida, "\n");
    }
    fclose(salida);
    return 0;
}
