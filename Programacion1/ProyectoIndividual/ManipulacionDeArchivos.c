/**
 * @archivo ProyectoIndividual.c
 * @autor Ricardo Sanjur (ricardosanjurg@gmail.com)
 * @resumen Hay que leer de un archivo llamado "Datos.txt" la informacion
 *          de ciertos alumnos y procesarla, los resultados de esta
 *          se almacenaran en un archivo nuevo llamado "DatosProcesados.txt"
 * @version 0.2
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
    int creditos[CANTIDAD_DE_SEMESTRES][CANTIDAD_DE_MATERIAS];
    char codigoAsignatura[5];
    char nota[CANTIDAD_DE_SEMESTRES][CANTIDAD_DE_MATERIAS];
    char descripcion[50];
};

#define CANTIDAD_DE_ALUMNOS 6
int main(int argc, char const *argv[])
{
    FILE *datos = fopen("DATOS.txt", "r");
    struct alumno estudiante[CANTIDAD_DE_ALUMNOS];
    int conteoAlumnos = 0;
    while ( !feof(datos) )
    {
        fscanf(datos, "%[^\n]\n", &estudiante[conteoAlumnos].nombre);
        for (int i = 0; i < CANTIDAD_DE_SEMESTRES; i++)
        {
            fscanf(datos, "%d %d\n", &estudiante[conteoAlumnos].periodo[i], &estudiante[conteoAlumnos].semestre[i]);
            for (int j = 0; j < CANTIDAD_DE_MATERIAS; j++)
            {
                fscanf(datos, "%d %s %c %[^\n]\n", &estudiante[conteoAlumnos].creditos[i][j], &estudiante[conteoAlumnos].codigoAsignatura, &estudiante[conteoAlumnos].nota[i][j], &estudiante[conteoAlumnos].descripcion);
            }
            
        }
        conteoAlumnos++;
    }

    for (int i = 0; i < CANTIDAD_DE_ALUMNOS; i++)
    {
        printf("%s\n", estudiante[i].nombre);
    }
    fclose(datos);

    return 0;
}
