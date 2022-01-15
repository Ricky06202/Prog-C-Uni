#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define ANCHO "el Ancho"
#define ALTO "la Altura"

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
    printf("\n\n");
}

void rectangulo(int ancho, int alto)
{
    if (ancho < 2)
        ancho = 2;
    if (ancho > 100)
        ancho = 100;
    if (alto < 2)
        alto = 2;
    if (alto > 100)
        alto = 100;
    for (int i = 0; i < alto; i++)
    {
        for (int j = 0; j < ancho; j++)
            printf(" X");
        printf("\n");
    }
    printf("\n\n");
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
    printf("\n\n");
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
    printf("\n\n");
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
    printf("\n\n");
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
    printf("\n\n");
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

bool preguntarSalida(char texto[200])
{
    char letra;
    bool valido = false;
    do
    {
        printf("%s(S/N): ", texto);
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

int cambiarValor(char texto[25])
{
    int numero;
    do
    {
        printf("Ingrese un valor para %s: ", texto);
        scanf("%d", &numero);
    } while (numero < 0);

    return numero;
}

int menu()
{
    int opcion = 1;
    do
    {
        imprimirPresentacion();
        printf("\n\nElije una de opciones para continuar\n");
        printf("1) Cuadrado\n");
        printf("2) Rectangulo\n");
        printf("3) Flecha\n");
        printf("4) Triangulo\n");
        printf("5) Rombo\n");
        printf("6) Trapecio\n");
        printf("7) SALIR\n\n");
        if (opcion < 1 || opcion > 7)
        {
            printf("Elija correctamente\n\n");
        }
        printf("Ingrese el numero correspondiente a la opcion deseada: ");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 7);
    return opcion;
}

int main(int argc, char const *argv[])
{
    bool salir = false;
    while (true)
    {
        switch (menu())
        {
        case 1:
            cuadrado(cambiarValor(ANCHO));
            break;
        case 2:
            rectangulo(cambiarValor(ANCHO), cambiarValor(ALTO));
            break;
        case 3:
            flecha(cambiarValor(ANCHO));
            break;
        case 4:
            triangulo(cambiarValor(ANCHO));
            break;
        case 5:
            rombo(cambiarValor(ANCHO));
            break;
        case 6:
            trapecio(cambiarValor(ANCHO));
            break;
        default:
            salir = preguntarSalida("Seguro de que quiere salir?");
            if (salir)
                salir = preguntarSalida("Pero... nos estabamos divirtiendo... estas... seguro...de que quieres salir :c?");
            if (salir)
                salir = preguntarSalida("Nanana no aceptare un SI por respuesta");
            if (salir)
                salir = preguntarSalida("NO me niego a terminar este programa escribe N y sigamos dibujando :c");
            if (salir)
                salir = preguntarSalida("Esta bien... :c si insiste tanto en salir :C no te detendre... :c escribe la S y sal no te preocupes :c");
            if (!salir)
            {
                printf("\n\nGenial!!! Sigamos Dibujando!!! :D\n\n");
            }
        }
        if (salir)
            break;
        else
            system("pause");
    }
    return 0;
}
