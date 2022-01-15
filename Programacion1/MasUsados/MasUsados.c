#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"

#define weNumeroAleatorio(min, max) min + rand() % (max - min + 1)


bool wePreguntarSN(bool automatico, char texto[])
{
    char letra;
    if (automatico)
        return true; // automatico
    do
    {
        printf("%s(S/N): ", texto);
        scanf(" %c", &letra);
    } while (!(letra == 's' || letra == 'S' || letra == 'n' || letra == 'N'));
    switch (letra)
    {
    case 's':
    case 'S':
        return true;
        break;
    case 'n':
    case 'N':
        return false;
    }
}

void wePresentacion(char nombre[], int numeroDeTabulaciones, char asignacion[], char salon[], int tiempoAnual, char semestre[], bool femenino, char nombreProfesor[])
{
    char genero = '\0';
    if (femenino)
        genero = 'a';
    system("cls");
    printf("\n\n");
    printf("                     Universidad Tecnologica de Panama\n");
    printf("                               %s\n", nombre);
    for (int i = 0; i < numeroDeTabulaciones; i++)
        printf("\t");
    printf("%s\n", asignacion);
    printf("                 Lic. en Ingenieria Sistemas Computacionales\n");
    printf("                      %s            %d, %s Semestre\n", salon, tiempoAnual, semestre);
    printf("                        Profesor%c: %s\n\n", genero, nombreProfesor);
}

long weIngresarEntero(char texto[])
{
    long num;
    printf("%s: ", texto);
    scanf("%ld", &num);
    return num;
}

double weIngresarReal(char texto[])
{
    double num;
    printf("%s: ", texto);
    scanf("%Lf", &num);
    return num;
}

char *weIngresarTexto(char variable[], char texto[])
{
    printf("%s: ", texto);
    scanf(" %[^\n]", variable);
    return variable;
}

void weOrdenarAscendente(int numero[], int inicio, int final)
{
    int pivote, izquierda, derecha;

    if (inicio < final)
    {
        pivote = numero[inicio];
        izquierda = inicio;
        derecha = final;

        while (izquierda < derecha)
        {
            while (derecha > izquierda && numero[derecha] > pivote)
                derecha--;
            if (derecha > izquierda)
            {
                numero[izquierda] = numero[derecha];
                izquierda++;
            }

            while (izquierda < derecha && numero[izquierda] < pivote)
                izquierda++;
            if (izquierda < derecha)
            {
                numero[derecha] = numero[izquierda];
                derecha--;
            }
        }
        numero[derecha] = pivote;
        weOrdenarAscendente(numero, inicio, izquierda - 1);
        weOrdenarAscendente(numero, derecha + 1, final);
    }
}

void weOrdenarDescendente(int numero[], int inicio, int final)
{
    int pivote, izquierda, derecha;

    if (inicio < final)
    {
        pivote = numero[inicio];
        izquierda = inicio;
        derecha = final;

        while (izquierda < derecha)
        {
            while (derecha > izquierda && numero[derecha] < pivote)
                derecha--;
            if (derecha > izquierda)
            {
                numero[izquierda] = numero[derecha];
                izquierda++;
            }

            while (izquierda < derecha && numero[izquierda] > pivote)
                izquierda++;
            if (izquierda < derecha)
            {
                numero[derecha] = numero[izquierda];
                derecha--;
            }
        }
        numero[derecha] = pivote;
        weOrdenarDescendente(numero, inicio, izquierda - 1);
        weOrdenarDescendente(numero, derecha + 1, final);
    }
}

