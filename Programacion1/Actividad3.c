#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"

void PrimeraSumatoria();
void SegundaSumatoria();
void TerceraSumatoria(int maximo);
void cuadrado(int ancho);
void flecha(int ancho);
void triangulo(int ancho);
void rombo(int ancho);
void trapecio(int ancho);
bool reiniciar(bool automatico);
void imprimirPresentacion();
int cambiarValor();

int main(int argc, char const *argv[])
{
    int valor = 10;
    bool automatico = true;
    while (reiniciar(automatico))
    {
        if (!automatico)
            valor = cambiarValor();
        automatico = false;
        imprimirPresentacion();
        PrimeraSumatoria();
        system("pause");
        SegundaSumatoria();
        system("pause");
        TerceraSumatoria(valor);
        system("pause");
        imprimirPresentacion();
        cuadrado(valor);
        system("pause");
        imprimirPresentacion();
        flecha(valor);
        system("pause");
        imprimirPresentacion();
        triangulo(valor);
        system("pause");
        imprimirPresentacion();
        rombo(valor);
        system("pause");
        imprimirPresentacion();
        trapecio(valor);
        system("pause");
    }

    return 0;
}

void PrimeraSumatoria()
{
    float suma = 0;
    for (int i = 1; i <= 50; i++)
    {
        suma += 1 / (float)i;
    }
    printf("1) La sumatoria de la primera progresion aritmetica = %.2f\n", suma);
    printf("\n");
}

void SegundaSumatoria()
{
    float suma = 0;
    for (int i = 1; i < 50; i++)
    {
        suma += i / (float)(i + 1);
    }
    printf("2) La sumatoria de la segunda progresion aritmetica = %.2f\n", suma);
    printf("\n");
}

void TerceraSumatoria(int maximo)
{
    float suma = 0;
    float i = maximo;
    for (int i = 1; i <= maximo; i++)
    {
        suma += i / (float)pow(2, i);
    }
    printf("3) La sumatoria de la tercera progresion aritmetica = %.2f\n", suma);
    printf("\n");
}

void cuadrado(int ancho)
{
    if (ancho < 2)
        ancho = 2;
    if (ancho > 100)
        ancho = 100;
    int altura = ancho;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < ancho; j++)
            printf(" X");
        printf("\n");
    }
    printf("\n");
}

void flecha(int ancho)
{
    if (ancho < 5)
        ancho = 5;
    if (ancho > 100)
        ancho = 100;
    if (ancho % 2 == 0)
        ancho++;
    int n = 0, altura = ancho / 2;
    for (int i = 0; i <= altura; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            if (j >= (ancho / 2) - n && j <= (ancho / 2) + n)
                printf(" X");
            else
                printf("  ");
        }
        printf("\n");
        n++;
    }
    n = ancho / 2 - (ancho / 2) / 2 - 1;
    for (int i = 0; i <= altura; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            if (j >= (ancho / 2) - n && j <= (ancho / 2) + n)
                printf(" X");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}

void triangulo(int ancho)
{
    if (ancho < 2)
        ancho = 2;
    if (ancho > 100)
        ancho = 100;
    int altura = ancho - 1, n = 0;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            if (j <= n)
                printf(" X");
            else
                printf("  ");
        }
        printf("\n");
        n++;
    }
    for (int i = 0; i <= altura; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            if (j <= n)
                printf(" X");
            else
                printf("  ");
        }
        printf("\n");
        n--;
    }
    printf("\n");
}

void rombo(int ancho)
{
    if (ancho < 3)
        ancho = 3;
    if (ancho > 100)
        ancho = 100;
    if (ancho % 2 == 0)
        ancho++;
    int n = 0, altura = ancho / 2;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            if (j >= (ancho / 2) - n && j <= (ancho / 2) + n)
                printf(" X");
            else
                printf("  ");
        }
        printf("\n");
        n++;
    }
    for (int i = 0; i <= altura; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            if (j >= (ancho / 2) - n && j <= (ancho / 2) + n)
                printf(" X");
            else
                printf("  ");
        }
        printf("\n");
        n--;
    }
    printf("\n");
}

void trapecio(int ancho)
{
    if (ancho < 4)
        ancho = 4;
    if (ancho > 75)
        ancho = 75;
    int n = 0, altura = ancho / 2;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j <= ancho + n; j++)
        {
            if (j > n)
                printf(" X");
            else
                printf("  ");
        }
        printf("\n");
        n++;
    }
    printf("\n");
}

void imprimirPresentacion()
{
    system("cls");
    printf("\n\n");
    printf("                     Universidad Tecnologica de Panama\n");
    printf("                             Ricardo Sanjur\n");
    printf("                 Lic. en Ingenieria Sistemas Computacionales\n");
    printf("                           2IL112, 2do Semestre\n");
    printf("                        Profesora: Cecilia Gonzales\n\n");
}

bool reiniciar(bool automatico)
{
    char letra;
    bool valido = false;
    if (automatico)
    {
        automatico = false;
        return true; // automatico
    }
    do
    {
        printf("Desea volver a empezar?(S/N): ");
        scanf(" %c", &letra);
        if (letra == 's' || letra == 'S' || letra == 'n' || letra == 'N')
            valido = true;
    } while (!valido);
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

int cambiarValor()
{
    int numero;
    do
    {
        printf("Ingrese un nuevo valor para las medidas: ");
        scanf("%d", &numero);
    } while (numero < 0);

    return numero;
}