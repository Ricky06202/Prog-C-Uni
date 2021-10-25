#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

void amortizacionDePrestamo(float *prestamo, float *interes, float *pagoMensual, bool *automatico);
void imprimirPresentacion();
void imprimirCabecera();
void ingreseValores(float *prestamo, float *interes, float *pagoMensual);
bool reiniciar(bool automatico);

int main(int argc, char const *argv[])
{
    float prestamo = 50000, interes = 0.0083, pagoMensual = 4800;
    bool automatico;
    do
    {
        automatico = false;
        system("cls");
        imprimirPresentacion();
        ingreseValores(&prestamo, &interes, &pagoMensual);
        system("cls");
        imprimirPresentacion();
        imprimirCabecera();
        amortizacionDePrestamo(&prestamo, &interes, &pagoMensual, &automatico);
    } while (reiniciar(automatico));

    return 0;
}

void amortizacionDePrestamo(float *prestamo, float *interes, float *pagoMensual, bool *automatico)
{
    int i = 1;
    while (*prestamo > 0)
    {
        float pagoInteres = *prestamo * *interes;
        float pagoCapital = *pagoMensual - pagoInteres;
        float balanceFinal = *prestamo - pagoCapital;
        if (pagoInteres >= *pagoMensual)
        {
            system("cls");
            printf("El pago de interes esta dando mayor o igual que el pago mensual, vuelva a intentar\n");
            printf("Intente disminuir el interes o aumentando el pago mensual\n");
            printf("por que actualmente el pago de interes = %.2f y el pago mensual = %.2f\n", pagoInteres, *pagoMensual);
            printf("y al restarlos hace que el pagoCapital sea de a: %.2f - %.2f = %.2f\n", *pagoMensual, pagoInteres, pagoCapital);
            printf("entonces al restarlos hace que el balance final sea de a: %.2f - (%.2f) = %.2f\n", *prestamo, pagoCapital, balanceFinal);
            printf("lo que nos dara un bucle infinito por que no estamos dismuyendo el valor\n\n");
            *automatico = true;
            system("pause");
            break;
        }

        printf("%3d% 14.2f %14.2f %14.2f %14.2f %14.2f\n\n", i, *prestamo, *pagoMensual, pagoInteres, pagoCapital, balanceFinal);
        *prestamo = balanceFinal;
        i++;
    }
    if (!*automatico)
    {
        printf("TIENE DERECHO A UNA DEVOLUCION DE: %7.2f\n", *prestamo);
    }
}

void imprimirPresentacion()
{
    system("cls");
    printf("\n\n");
    printf("                     Universidad Tecnologica de Panama\n");
    printf("                             Ricardo Sanjur\n");
    printf("                 Lic. en Ingenieria Sistemas Computacionales\n");
    printf("                           2IL112, 2do Semestre\n");
    printf("                         Profesora: Cecilia Gonzales\n\n");
}

void imprimirCabecera()
{
    printf(" Mes      Balance       Pago Fijo        Pago           Pago         Balance\n");
    printf("          Inicial        Mensual        Interes        Capital        Final\n\n");
}

void ingreseValores(float *prestamo, float *interes, float *pagoMensual)
{
    do
    {
        printf("Ingrese el Prestamo: ");
        scanf("%f", &*prestamo);
        if (*prestamo <= 0)
        {
            printf("Debe ser un valor positivo\n");
        }

    } while (*prestamo <= 0);

    do
    {
        printf("Ingrese el Interes: ");
        scanf("%f", &*interes);
        if (*interes <= 0)
        {
            printf("Debe ser un valor positivo\n");
        }

    } while (*interes <= 0);
    do
    {
        printf("Ingrese el Pago Mensual: ");
        scanf("%f", &*pagoMensual);
        if (*pagoMensual <= 0)
        {
            printf("Debe ser un valor positivo\n");
        }

    } while (*pagoMensual <= 0);
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