#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"
#include "Lib/P1/MasUsados.h"
#include "Lib/P1/Actividad4.h"

#define MENU "Ricardo Sanjur", 3, "     Parcial 2 Practico", "2IL112", 2021, "2do", true, "Cecilia Gonzales"
#define P1 "Ricardo Sanjur", 3, "Problema 1 (Matriz Cuadrada)", "2IL112", 2021, "2do", true, "Cecilia Gonzales"
#define P2 "Ricardo Sanjur", 3, "   Problema 2 (4 Matrices)", "2IL112", 2021, "2do", true, "Cecilia Gonzales"

// ESTAS SON LAS FUNCIONES QUE CREE Y QUE TENGO EN MI LIBRERIA DE MasUsado.h
// MI LIBRERIA Actividad4.h ES LA QUE CONTIENE LAS FUNCIONES QUE REALIZAMOS EN CLASE SOBRE LOS PRIMOS, ULAM, ETC.

// long weIngresarEntero(char texto[])
// {
//     long num;
//     printf("%s: ", texto);
//     scanf("%ld", &num);
//     return num;
// }

// void wePresentacion(char nombre[], int numeroDeTabulaciones, char asignacion[], char salon[], int tiempoAnual, char semestre[], bool femenino, char nombreProfesor[])
// {
//     char genero = '\0';
//     if (femenino)
//         genero = 'a';
//     system("cls");
//     printf("\n\n");
//     printf("                     Universidad Tecnologica de Panama\n");
//     printf("                               %s\n", nombre);
//     for (int i = 0; i < numeroDeTabulaciones; i++)
//         printf("\t");
//     printf("%s\n", asignacion);
//     printf("                 Lic. en Ingenieria Sistemas Computacionales\n");
//     printf("                      %s            %d, %s Semestre\n", salon, tiempoAnual, semestre);
//     printf("                        Profesor%c: %s\n\n", genero, nombreProfesor);
// }

// bool wePreguntarSN(bool automatico, char texto[])
// {
//     char letra;
//     if (automatico)
//         return true; // automatico
//     do
//     {
//         printf("%s(S/N): ", texto);
//         scanf(" %c", &letra);
//     } while (!(letra == 's' || letra == 'S' || letra == 'n' || letra == 'N'));
//     switch (letra)
//     {
//     case 's':
//     case 'S':
//         return true;
//         break;
//     case 'n':
//     case 'N':
//         return false;
//     }
// }

int numeroAleatorio(int min, int max)
{
    return min + rand() % (max + 1 - min);
}

void matrizCuadrada()
{
    srand(time(NULL));
    int cant = 2;
    int num = 0;
    do
    {
        wePresentacion(P1);
        if (cant < 2)
            printf("El numero debe ser Mayor o Igual a 2\n");
        printf("\nIngrese el tama%co de la matriz cuadrada", 164);
        cant = weIngresarEntero("");
    } while (cant < 2);
    printf("\n");
    int primo[cant][cant];
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j < cant; j++)
        {
            while (!fnPrimo(num))
                num = numeroAleatorio(0, 999);
            primo[i][j] = num;
            num = 0;
            printf("%4d ", primo[i][j]);
        }
        printf("\n");
    }
    int sumaPrincipal = 0, sumaSecundaria = 0;
    for (int i = 0, j = cant - 1; i < cant; i++, j--)
    {
        sumaPrincipal += primo[i][i];
        sumaSecundaria += primo[i][j];
    }
    printf("\nLa Suma de la Diagonal Principal es = %d \n", sumaPrincipal);
    printf("La Suma de la Diagonal Secundaria es = %d \n\n", sumaSecundaria);
}

void ecuacionConMatrices()
{
    srand(time(NULL));
    int filaA, filaB, filaC, filaD, columnaA, columnaB, columnaC, columnaD, opcion = 1;
    filaA = filaB = filaC = filaD = columnaA = columnaB = columnaC = columnaD = 1;
    do
    {
        wePresentacion(P2);
        printf("Elija una manera para definir las Matrices\n");
        printf("1- manualmente\n");
        printf("2- automaticamente\n");
        opcion = weIngresarEntero("Ingrese una opcion");
    } while (opcion < 1 || opcion > 2);

    if (opcion == 1)
    {
        do
        {
            wePresentacion(P2);
            printf("Para resolver la siguiente ecuacion \nMATRIZ A = MATRIZ B + MATRIZ C * MATRIZ D\nGenere la MATRIZ B\n");
            if (filaB < 1 || columnaB < 1)
                printf("El numero ingresado debe ser 1 o Mayor\n");
            filaB = weIngresarEntero("Ingrese la cantidad de Filas");
            columnaB = weIngresarEntero("Ingrese la cantidad de Comlumnas");
        } while (filaB < 1 || columnaB < 1);
        wePresentacion(P2);
        printf("Las demas matrices se generaran basandose en los datos anteriores...\n\n");
        system("pause");
        do
        {
            wePresentacion(P2);
            printf("MATRIZ C\nCantidad de Filas = %d\nCantidad de Columnas = (se requiere informacion)\n", filaB);
            if (columnaC < 1)
                printf("Requerimos de que la cantidad de columnas sea mayor o igual a 1\n");
            columnaC = weIngresarEntero("Ingrese la cantidad de columnas");
        } while (columnaC < 1);
    }
    else
    {
        filaB = numeroAleatorio(1, 20);
        columnaB = numeroAleatorio(1, 20);
        wePresentacion(P2);
        printf("MATRIZ B\nCantidad de Filas = %d\nCantidad de Columnas = %d\n\n", filaB, columnaB);
        system("pause");
        columnaC = numeroAleatorio(1, 20);
        wePresentacion(P2);
        printf("MATRIZ C\nCantidad de Filas = %d\nCantidad de Columnas = %d\n\n", filaB, columnaC);
        system("pause");
    }

    wePresentacion(P2);
    printf("MATRIZ D\nCantidad de Filas = %d\nCantidad de Columnas = %d\n\n", columnaC, columnaB);
    system("pause");
    wePresentacion(P2);
    printf("MATRIZ A\nCantidad de Filas = %d\nCantidad de Columnas = %d\n\n", filaB, columnaB);
    system("pause");
    wePresentacion(P2);
    printf("Comenzaremos a generar las matrices...\n\n");
    system("pause");

    int matrizB[filaB][columnaB];
    int matrizC[filaC = filaB][columnaC];
    int matrizD[filaD = columnaC][columnaD = columnaB];
    int matrizA[filaA = filaC][columnaA = columnaD];

    for (int i = 0; i < filaB; i++)
        for (int j = 0; j < columnaB; j++)
            matrizB[i][j] = numeroAleatorio(15, 200);

    for (int i = 0; i < filaC; i++)
        for (int j = 0; j < columnaC; j++)
            matrizC[i][j] = numeroAleatorio(15, 200);

    for (int i = 0; i < filaD; i++)
        for (int j = 0; j < columnaD; j++)
            matrizD[i][j] = numeroAleatorio(15, 200);
    wePresentacion(P2);
    printf("MATRIZ B\n");
    for (int i = 0; i < filaB; i++)
    {
        for (int j = 0; j < columnaB; j++)
            printf("%4d ", matrizB[i][j]);
        printf("\n");
    }
    printf("\nMATRIZ C\n");
    for (int i = 0; i < filaC; i++)
    {
        for (int j = 0; j < columnaC; j++)
            printf("%4d ", matrizC[i][j]);
        printf("\n");
    }
    printf("\nMATRIZ D\n");
    for (int i = 0; i < filaD; i++)
    {
        for (int j = 0; j < columnaD; j++)
            printf("%4d ", matrizD[i][j]);
        printf("\n");
    }
    printf("\n");
    system("pause");
    wePresentacion(P2);
    printf("Realizando los Calculos...\n");
    printf("MATRIZ A = MATRIZ B + MATRIZ C * MATRIZ D\n");
    printf("Calculando primero MATRIZ C * MATRIZ D\n\n");
    system("pause");
    wePresentacion(P2);
    printf("\nMATRIZ (C * D)\n");

    for (int i = 0; i < filaA; i++)
    {
        for (int j = 0; j < columnaA; j++)
        {
            matrizA[i][j] = 0;
            for (int k = 0; k < columnaC; k++)

                matrizA[i][j] += matrizC[i][k] * matrizD[k][j];
            printf("%7d ", matrizA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
    wePresentacion(P2);
    printf("Calculando MATRIZ A = MATRIZ B + MATRIZ (C * D)\n\n");
    system("pause");
    wePresentacion(P2);
    printf("\nMATRIZ A\n");
    for (int i = 0; i < filaA; i++)
    {
        for (int j = 0; j < columnaA; j++)
        {
            matrizA[i][j] += matrizB[i][j];
            printf("%7d ", matrizA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void menu()
{
    printf("##-##-##-##-##-##-##-##-##-##-##-##-##-##\n");
    printf("#//////ELIJA-UNA-DE-LAS-OPCIONES////////#\n");
    printf("| 1) Problema 1 (Matriz Cuadrada)       |\n");
    printf("| 2) Problema 2 (Generar 4 matrices)    |\n");
    printf("# 3) *SALIR*                            #\n");
    printf("##-##-##-##-##-##-##-##-##-##-##-##-##-##\n");
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        int opcion = 2;
        do
        {
            wePresentacion(MENU);
            menu();
            opcion = weIngresarEntero("Ingrese una opcion Valida");
        } while (opcion < 1 || opcion > 3);
        switch (opcion)
        {
        case 1:
            do
            {
                matrizCuadrada();
            } while (wePreguntarSN(false, "Desea volver a Generar una Matriz Cuadrada?"));

            break;
        case 2:
            do
            {
                ecuacionConMatrices();
            } while (wePreguntarSN(false, "Desea volver a Generar las Matrices?"));
            break;
        case 3:
            goto salida;
            break;
        }
    }
salida:
    return 0;
}
