#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"
#include "time.h"
#include "Lib/P1/MasUsados.h"
#include "Lib/Otros/MasUsados.h"

#define MENU "", 3, "      Trabajo en Grupo", "2IL112", 2021, "2do", true, "Celicia Gonzales"
#define BINGO "", 3, "      Juego de BINGO", "2IL112", 2021, "2do", true, "Celicia Gonzales"
#define CUADRADO "", 3, "      Cuadrado Magico", "2IL112", 2021, "2do", true, "Celicia Gonzales"
#define MATRICES "", 3, "  Operaciones con Matrices", "2IL112", 2021, "2do", true, "Celicia Gonzales"
#define VENTAS "", 3, "    Prestamos Ventanilla", "2IL112", 2021, "2do", true, "Celicia Gonzales"

void cuadradoMagico()
{
    int medidaCuadrado = 3;
    do
    {
        wePresentacion(CUADRADO);
        if (medidaCuadrado < 3)
            printf("El numero debe ser MAYOR\n");
        if (medidaCuadrado % 2 == 0)
            printf("El numero debe ser IMPAR\n");
        medidaCuadrado = weIngresarEntero("Ingrese la medida del Cuadrado Magico");
    } while (medidaCuadrado < 3 || medidaCuadrado % 2 == 0);

    wePresentacion(CUADRADO);
    int cuadradoMagico[medidaCuadrado][medidaCuadrado];
    for (int i = 0; i < medidaCuadrado; i++)
        for (int j = 0; j < medidaCuadrado; j++)
            cuadradoMagico[i][j] = 0;

    int j = (medidaCuadrado - 1) / 2, i = j + 1, contador = 1, iAnterior = 0, jAnterior = 0;

    while (contador != medidaCuadrado * medidaCuadrado + 1)
    {

        if (cuadradoMagico[i][j] == 0)
        {
            cuadradoMagico[i][j] = contador;
            contador++;
            iAnterior = i++;
            jAnterior = j++;
        }
        else
        {
            i = iAnterior + 2;
            j = jAnterior;
        }

        if (i > medidaCuadrado - 1)
            i -= medidaCuadrado;
        if (j == medidaCuadrado)
            j = 0;
    }

    for (int i = 0; i < medidaCuadrado; i++)
    {
        for (int j = 0; j < medidaCuadrado; j++)
            printf(" %2d", cuadradoMagico[i][j]);
        printf("\n");
    }
}

void Matrices()
{
    srand(time(NULL));
    int opcion, f, c, a[20][20], b[20][20], suma[20][20], resta[20][20], i, j;
    char resp_rand, resp_cont;
principal:
    wePresentacion(MATRICES);
    printf("Vamos a hacer algunas operaciones con las matrices! Que desea hacer?\n 1. Suma\n 2. Resta\n 3. Multiplicacion\n\n");
    scanf("%d", &opcion);
    if (opcion < 1 || opcion > 3)
        goto principal;
    wePresentacion(MATRICES);
    printf("Utilizamos los numeros aleatorios? S/N\n\n");
    scanf(" %c", &resp_rand);
    wePresentacion(MATRICES);
    if (resp_rand == 's' || resp_rand == 'S')
    {
        if (opcion == 1) //la suma de matrices con numeros aleatorios
        {
            printf("Ingrese el numero de las filas de la matriz: ");
            scanf("%d", &f);

            printf("Ingrese el numero de las columnas de la matriz: ");
            scanf("%d", &c);
            printf("\n");

            printf("La primera matriz\n");
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < c; j++)
                {
                    a[i][j] = rand() % 100;
                    printf("%3d  ", a[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            printf("La segunda matriz\n");
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < c; j++)
                {
                    b[i][j] = rand() % 100;
                    printf("%3d  ", b[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            printf("La suma de las matrices\n");
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < c; j++)
                {
                    suma[i][j] = a[i][j] + b[i][j];
                    printf("%3d  ", suma[i][j]);
                }
                printf("\n");
            }
        }

        else if (opcion == 2) //resta de matrices con numeros aleatorios
        {
            printf("Ingrese el numero de las filas de la matriz: ");
            scanf("%d", &f);
            printf("Ingrese el numero de las columnas de la matriz: ");
            scanf("%d", &c);
            printf("\n");
            printf("La primera matriz\n");
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < c; j++)
                {
                    a[i][j] = rand() % 100;
                    printf("%3d  ", a[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            printf("La segunda matriz\n");
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < c; j++)
                {
                    b[i][j] = rand() % 100;
                    printf("%3d  ", b[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            printf("La resta de las matrices\n");
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < c; j++)
                {
                    resta[i][j] = a[i][j] - b[i][j];
                    printf("%3d  ", resta[i][j]);
                }
                printf("\n");
            }
        }
        else if (opcion == 3)
        {
            //aqui va el codigo de Ana de multiplicacion con los numeros aleatorios

            int fa, ca = 1, fb = 1, cb, i = 0, x = 0, j = 0, b = 0;
            do
            {
                wePresentacion(MATRICES);
                if (ca != fb)
                    printf("No se puede realizar la matriz, la columna A debe ser igual a la fila B\n");
                printf("Escribir numero de fila de la matriz A:    ");
                scanf("%d", &fa);
                printf("Escribir numero de columna de la matriz A: ");
                scanf("%d", &ca);
                printf("Escribir numero de fila de la matriz B:    ");
                scanf("%d", &fb);
                printf("Escribir numero de columna de la matriz B: ");
                scanf("%d", &cb);

            } while (ca != fb);

            int mat_A[fa][ca], mat_B[fb][cb], Resp[fa][cb];

            printf("La primera matriz\n");
            for (i = 0; i < fa; i++)
            {
                for (j = 0; j < ca; j++)
                {
                    mat_A[i][j] = 2 * rand() % (25);
                    printf("%3d ", mat_A[i][j]);
                }
                printf("\n");
            }
            printf("\n");

            printf("La segunda matriz\n");
            for (i = 0; i < fb; i++)
            {
                for (j = 0; j < cb; j++)
                {
                    mat_B[i][j] = rand() % (20);
                    printf("%3d ", mat_B[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            //OPERACION DE MULTIPLICACION
            for (i = 0; i < fa; i++)
            {
                for (j = 0; j < cb; j++)
                {
                    Resp[i][j] = 0;
                    for (x = 0; x < ca; x++)
                    {
                        Resp[i][j] = Resp[i][j] + mat_A[i][x] * mat_B[x][j];
                    }
                }
            }

            //RESPUESTA DE MULTIPLICACI�N
            printf("MATRIZ RESULTANTE\n");
            for (i = 0; i < fa; i++)
            {
                for (j = 0; j < cb; j++)
                {
                    if (i != 0 && j == 0)
                    {
                        printf("\n");
                    }
                    printf("%3d ", Resp[i][j]);
                }
            }
            printf("\n");
        }
    }
    else
    {
        if (opcion == 1) //la suma de matrices
        {
            printf("Ingrese el numero de filas de la matriz: ");
            scanf("%d", &f);
            printf("Ingrese el numero de columnas de la matriz: ");
            scanf("%d", &c);
            printf("Ingresando los elementos de la matriz A\n"); //llenando el vector de la matriz A por usuario
            for (i = 0; i < f; i++)
                for (j = 0; j < c; j++)
                {
                    printf("Ingrese el elemento a%d.%d: ", i + 1, j + 1);
                    scanf("%d", &a[i][j]);
                }
            printf("Ingresando los elementos de la matriz B\n"); //llenando el vector de la matriz B usuario
            for (i = 0; i < f; i++)
                for (j = 0; j < c; j++)
                {
                    printf("Ingrese el elemento b%d.%d: ", i + 1, j + 1);
                    scanf("%d", &b[i][j]);
                }
            for (i = 0; i < f; i++) //sumando las matrices
                for (j = 0; j < c; j++)
                {
                    suma[i][j] = a[i][j] + b[i][j];
                }

            printf("La suma de las matrices \n"); //el resultado de la suma
            for (i = 0; i < f; i++)
                for (j = 0; j < c; j++)
                {
                    printf("%3d   ", suma[i][j]);
                    if (j == c - 1)
                    {
                        printf("\n\n");
                    }
                }
        }

        else if (opcion == 2) //resta de matrices
        {
            printf("Ingrese el numero de filas de la matriz: ");
            scanf("%d", &f);
            printf("Ingrese el numero de columnas de la matriz: ");
            scanf("%d", &c);
            printf("Ingresando los elementos de la matriz A\n"); //llenando el vector de la matriz A usuario
            for (i = 0; i < f; i++)
                for (j = 0; j < c; j++)
                {
                    printf("Ingrese el elemento a%d.%d: ", i + 1, j + 1);
                    scanf("%d", &a[i][j]);
                }

            printf("Ingresando los elementos de la matriz B\n"); //llenando el vector de la matriz B usuario
            for (i = 0; i < f; i++)
                for (j = 0; j < c; j++)
                {
                    printf("Ingrese el elemento b%d.%d: ", i + 1, j + 1);
                    scanf("%d", &b[i][j]);
                }

            for (i = 0; i < f; i++) //restando las matrices
                for (j = 0; j < c; j++)
                {
                    resta[i][j] = a[i][j] - b[i][j];
                }

            printf("La resta de las matrices \n"); //el resultado de la resta
            for (i = 0; i < f; i++)
                for (j = 0; j < c; j++)
                {
                    printf("%3d   ", resta[i][j]);
                    if (j == c - 1)
                    {
                        printf("\n\n");
                    }
                }
        }
        else if (opcion == 3)
        {
            //aqui va el codigo de Ana de multiplicacion con los numeros aleatorios

            int fa, ca = 1, fb = 1, cb, i = 0, x = 0, j = 0, b = 0;
            do
            {
                wePresentacion(MATRICES);
                if (ca != fb)
                    printf("No se puede realizar la matriz, la columna A debe ser igual a la fila B\n");
                printf("Escribir numero de fila de la matriz A:    ");
                scanf("%d", &fa);
                printf("Escribir numero de columna de la matriz A: ");
                scanf("%d", &ca);
                printf("Escribir numero de fila de la matriz B:    ");
                scanf("%d", &fb);
                printf("Escribir numero de columna de la matriz B: ");
                scanf("%d", &cb);

            } while (ca != fb);

            int mat_A[fa][ca], mat_B[fb][cb], Resp[fa][cb];

            //INGRESE LAS MATRICES
            printf("\nMatriz A\n");
            for (i = 0; i < fa; i++)
                for (j = 0; j < ca; j++)
                {
                    printf("Ingrese el elemento a%d.%d: ", i + 1, j + 1);
                    scanf("%d", &mat_A[i][j]);
                }

            printf("\nMatriz B\n");
            for (i = 0; i < fb; i++)
                for (j = 0; j < cb; j++)
                {
                    printf("Ingrese el elemento b%d.%d: ", i + 1, j + 1);
                    scanf("%d", &mat_B[i][j]);
                }

            for (int i = 0; i < fa; i++)
            {
                for (j = 0; j < ca; j++)
                {
                    printf("%3d ", mat_A[i][j]);
                }
                printf("\n");
            }
            printf("\n");

            for (int i = 0; i < fb; i++)
            {
                for (j = 0; j < cb; j++)
                {
                    printf("%3d ", mat_B[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            //OPERACION DE MULTIPLICACION
            for (i = 0; i < fa; i++)
            {
                for (j = 0; j < cb; j++)
                {
                    Resp[i][j] = 0;
                    for (x = 0; x < ca; x++)
                    {
                        Resp[i][j] = Resp[i][j] + mat_A[i][x] * mat_B[x][j];
                    }
                }
            }
            //RESPUESTA DE MULTIPLICACI�N
            printf("\nMATRIZ RESULTANTE\n");
            for (i = 0; i < fa; i++)
            {
                for (j = 0; j < cb; j++)
                {
                    if (i != 0 && j == 0)
                    {
                        printf("\n");
                    }
                    printf("%3d ", Resp[i][j]);
                }
            }
            printf("\n");
        }
    }
}

void mensual()
{
    int mes = 0, dec2 = 1;
    float prest, monto, mensual;
    do
    {
        wePresentacion(VENTAS);
        printf("POR FAVOR INGRESE EL MONTO DEL PRESTAMO\n");
        scanf("%f", &prest);
    } while (prest < 1);

    do
    {
        wePresentacion(VENTAS);
        if (dec2 < 1 || dec2 > 5)
            printf("ERROR : NUMERO NO VALIDO\n");
        printf("INDIQUE EL PLAZO DE PAGO(MINIMO 3 A%cOS)\n", 165);
        printf("1. 3 A%cOS\n", 165);
        printf("2. 4 A%cOS\n", 165);
        printf("3. 5 A%cOS\n", 165);
        printf("4. 6 A%cOS\n", 165);
        printf("5. OTRO\n");
        scanf("%d", &dec2);
    } while (dec2 < 1 || dec2 > 5);

    switch (dec2)
    {
    case 1:
        mes = 36;
        break;
    case 2:
        mes = 48;
        break;
    case 3:
        mes = 60;
        break;
    case 4:
        mes = 72;
        break;
    case 5:
        do
        {
            wePresentacion(VENTAS);
            printf("FAVOR INDIQUE EL NUMERO DE MESES DEL PLAZO DE PAGO (MINIMO 36)\n");
            scanf("%d", &mes);
        } while (mes < 36);

        break;
    }
    wePresentacion(VENTAS);
    monto = prest * 0.9144;
    mensual = prest * (0.98 + 0.0075 * mes) / mes;
    printf("CALCULO DE PRESTAMO PERSONAL\n");
    printf("EL PRESTAMO QUE PIDIO FUE DE %.2f\n", prest);
    printf("EL MONTO QUE OBTIENE ES DE %.2f\n", monto);
    printf("USTED ELIGE PAGAR EN %d MESES (%d A%cOS Y %d MESES)\n", mes, mes / 12, 165, mes % 12);
    printf("SU MENSUALIDAD ES DE %.2f\n", mensual);
}
void Ventas()
{
    wePresentacion(VENTAS);
    printf("PROGRAMA DE CALCULO DE PRESTAMOS PERSONALES\n");
    printf("BIENVENIDO\n");
    mensual();
}

void marcarCarton(int numerosSacados[], int ultimo, int carton[5][5])
{
    for (int f = 0; f < 5; f++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (numerosSacados[ultimo] == carton[f][c])
                carton[f][c] = 0;
        }
    }
}

bool hemosGanado(int carton[5][5])
{
    bool ganar = false;
    // comprobamos las filas horizontales para ver si ganamos
    if (carton[0][0] == carton[0][1] && carton[0][0] == carton[0][2] && carton[0][0] == carton[0][3] && carton[0][0] == carton[0][4])
        ganar = true;
    if (carton[1][0] == carton[1][1] && carton[1][0] == carton[1][2] && carton[1][0] == carton[1][3] && carton[1][0] == carton[1][4])
        ganar = true;
    if (carton[2][0] == carton[2][1] && carton[2][0] == carton[2][2] && carton[2][0] == carton[2][3] && carton[2][0] == carton[2][4])
        ganar = true;
    if (carton[3][0] == carton[3][1] && carton[3][0] == carton[3][2] && carton[3][0] == carton[3][3] && carton[3][0] == carton[3][4])
        ganar = true;
    if (carton[4][0] == carton[4][1] && carton[4][0] == carton[4][2] && carton[4][0] == carton[4][3] && carton[4][0] == carton[4][4])
        ganar = true;
    // comprobamos las columnas verticales para ver si ganamos
    if (carton[0][0] == carton[1][0] && carton[0][0] == carton[2][0] && carton[0][0] == carton[3][0] && carton[0][0] == carton[4][0])
        ganar = true;
    if (carton[0][1] == carton[1][1] && carton[0][1] == carton[2][1] && carton[0][1] == carton[3][1] && carton[0][1] == carton[4][1])
        ganar = true;
    if (carton[0][2] == carton[1][2] && carton[0][2] == carton[2][2] && carton[0][2] == carton[3][2] && carton[0][2] == carton[4][2])
        ganar = true;
    if (carton[0][3] == carton[1][3] && carton[0][3] == carton[2][3] && carton[0][3] == carton[3][3] && carton[0][3] == carton[4][3])
        ganar = true;
    if (carton[0][4] == carton[1][4] && carton[0][4] == carton[2][4] && carton[0][4] == carton[3][4] && carton[0][4] == carton[4][4])
        ganar = true;
    // comprobamos las diagonales diagonalisticas para ver si ganamos
    if (carton[0][0] == carton[1][1] && carton[0][0] == carton[2][2] && carton[0][0] == carton[3][3] && carton[0][0] == carton[4][4])
        ganar = true;
    if (carton[4][0] == carton[3][1] && carton[4][0] == carton[2][2] && carton[4][0] == carton[1][3] && carton[4][0] == carton[0][4])
        ganar = true;
    return ganar;
}

int verificarNumeroSacado(int numeroSacado[])
{
    bool listo;
    int num;
    do
    {
        listo = true;
        num = 1 + rand() % (75 + 1 - 1);
        for (int i = 0; i < 75; i++)
            if (num == numeroSacado[i])
                listo = false;
    } while (!listo);
    return num;
}
int verificarNum(int carton[5][5], int min, int max)
{
    bool listo;
    int num;
    do
    {
        listo = true;
        num = min + rand() % (max + 1 - min);
        for (int f = 0; f < 5; f++)
        {
            for (int c = 0; c < 5; c++)
            {
                if (num == carton[f][c])
                    listo = false;
            }
        }
    } while (!listo);
    return num;
}

void vaciarCarton(int carton[][5])
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            carton[i][j] = 0;
}

int generarCarton(int carton[5][5])
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0)

                carton[i][j] = verificarNum(carton, 1, 15);

            else if (j == 1)
                carton[i][j] = verificarNum(carton, 16, 30);

            else if (j == 2)
                carton[i][j] = verificarNum(carton, 31, 45);

            else if (j == 3)
                carton[i][j] = verificarNum(carton, 46, 60);

            else if (j == 4)
                carton[i][j] = verificarNum(carton, 61, 75);
        }
    }
}

void mostrarCarton(int carton[5][5], char nombre[50])
{
    printf("%14s\n", nombre);
    printf("_____________________\n");
    printf("| B | I | N | G | O |\n");
    printf("|___|___|___|___|___|\n");
    for (int x = 0; x < 5; x++)
    {
        printf("|");
        for (int y = 0; y < 5; y++)
        {
            printf(" %2d|", carton[x][y]);
        }
        printf("\n");
        printf("|___|___|___|___|___|\n");
    }
    printf("\n\n");
}
void Bingo()
{
    srand(time(NULL)); // numero sacado : 20

    int numerosSacados[75];
    int ricardo[5][5];
    int thais[5][5];
    int irina[5][5];
    int pedro[5][5];
    int ana[5][5];
    vaciarCarton(ricardo);
    vaciarCarton(thais);
    vaciarCarton(irina);
    vaciarCarton(pedro);
    vaciarCarton(ana);
    bool r, t, i, p, a;
    r = t = i = p = a = false;
    int opcion = 0;
    while (true)
    {
        bool preparado = true;
        do
        {
            do
            {
                wePresentacion(BINGO);
                if (!preparado)
                    printf("/////////TIENE QUE LLENAR POR LO MENOS 1 CARTON//////////\n");
                if (opcion == 0)
                    preparado = false;
                printf("QUE CARTON DESEA LLENAR?\n");
                printf("1) RICARDO\n");
                printf("2) THAIS\n");
                printf("3) IRINA\n");
                printf("4) PEDRO\n");
                printf("5) ANA\n");
                printf("6) LISTO\n");
                opcion = thIngresarNumInt("INGRESE UNA OPCION VALIDA: ");
            } while (opcion < 1 || opcion > 6);
            if (opcion >= 1 && opcion <= 5)
                preparado = true;
        } while (opcion == 6 && !preparado);

        switch (opcion)
        {
        case 1:
            wePresentacion(BINGO);
            mostrarCarton(ricardo, "RICARDO");
            system("pause");
            wePresentacion(BINGO);
            generarCarton(ricardo);
            mostrarCarton(ricardo, "RICARDO");
            system("pause");
            r = true;
            break;
        case 2:
            wePresentacion(BINGO);
            mostrarCarton(thais, "THAIS");
            system("pause");
            wePresentacion(BINGO);
            generarCarton(thais);
            mostrarCarton(thais, "THAIS");
            system("pause");
            t = true;
            break;
        case 3:
            wePresentacion(BINGO);
            mostrarCarton(irina, "IRINA");
            system("pause");
            wePresentacion(BINGO);
            generarCarton(irina);
            mostrarCarton(irina, "IRINA");
            system("pause");
            i = true;
            break;
        case 4:
            wePresentacion(BINGO);
            mostrarCarton(pedro, "PEDRO");
            system("pause");
            wePresentacion(BINGO);
            generarCarton(pedro);
            mostrarCarton(pedro, "PEDRO");
            system("pause");
            p = true;
            break;
        case 5:
            wePresentacion(BINGO);
            mostrarCarton(ana, "ANA");
            system("pause");
            wePresentacion(BINGO);
            generarCarton(ana);
            mostrarCarton(ana, "ANA");
            system("pause");
            a = true;
            break;
        case 6:
            wePresentacion(BINGO);
            printf("\n\n\nCARGANDO EL JUEGO");
            system("timeout /t 1 > nul");
            printf(".");
            system("timeout /t 2 > nul");
            printf("..");
            system("timeout /t 3 > nul");
            printf("...");
            system("timeout /t 1 > nul");
            printf(".");
            system("timeout /t 1 > nul");
            printf(".");
            system("timeout /t 1 > nul");
            printf("LISTO!!!!\n");
            system("timeout /t 1 > nul");
            printf("!!!!!PRESS START TO PLAY!!!!!");
            system("pause > nul");
            goto continuar;
        }
    }
continuar:
    if (!r)
        generarCarton(ricardo);
    if (!t)
        generarCarton(thais);
    if (!i)
        generarCarton(irina);
    if (!p)
        generarCarton(pedro);
    if (!a)
        generarCarton(ana);
    int x = 0;
    while (!hemosGanado(ricardo) && !hemosGanado(thais) && !hemosGanado(irina) && !hemosGanado(pedro) && !hemosGanado(ana))
    {
        numerosSacados[x] = verificarNumeroSacado(numerosSacados);
        wePresentacion(BINGO);
        printf("EL NUMERO SACADO DE LA TOMBOLA");
        system("timeout /t 1 > nul");
        printf(" ES: ");
        system("timeout /t 1 > nul");
        printf("%d\n\n", numerosSacados[x]);
        if (r)
            mostrarCarton(ricardo, "RICARDO");
        if (t)
            mostrarCarton(thais, "THAIS");
        if (i)
            mostrarCarton(irina, "IRINA");
        if (p)
            mostrarCarton(pedro, "PEDRO");
        if (a)
            mostrarCarton(ana, "ANA");
        system("pause");
        wePresentacion(BINGO);
        printf("EL NUMERO SACADO DE LA TOMBOLA");
        //system("timeout /t 1 > nul");
        printf(" ES: ");
        //system("timeout /t 1 > nul");
        printf("%d\n\n", numerosSacados[x]);
        if (r)
        {
            marcarCarton(numerosSacados, x, ricardo);
            mostrarCarton(ricardo, "RICARDO");
        }
        if (t)
        {
            marcarCarton(numerosSacados, x, thais);
            mostrarCarton(thais, "THAIS");
        }
        if (i)
        {
            marcarCarton(numerosSacados, x, irina);
            mostrarCarton(irina, "IRINA");
        }
        if (p)
        {
            marcarCarton(numerosSacados, x, pedro);
            mostrarCarton(pedro, "PEDRO");
        }
        if (a)
        {
            marcarCarton(numerosSacados, x, ana);
            mostrarCarton(ana, "ANA");
        }
        system("pause");
        x++;
    }
    wePresentacion(BINGO);
    printf("FELICIDADES!!! HAZ GANADO!!!\n");
    if (hemosGanado(ricardo))
        mostrarCarton(ricardo, "RICARDO");
    if (hemosGanado(thais))
        mostrarCarton(thais, "THAIS");
    if (hemosGanado(irina))
        mostrarCarton(irina, "IRINA");
    if (hemosGanado(pedro))
        mostrarCarton(pedro, "PEDRO");
    if (hemosGanado(ana))
        mostrarCarton(ana, "ANA");
    system("pause");
    printf("\n");
}

void menu()
{
    printf("O--o--o--o--o--o--o--o--o--o--o--o--o--O\n");
    printf("| /////ELIJA UNA DE LAS OPCIONES/////  |\n");
    printf("O--o--o--o--o--o--o--o--o--o--o--o--o--O\n");
    printf("| 1) PRESTAMOS VENTANILLA              |\n");
    printf("O--o--o--o--o--o--o--o--o--o--o--o--o--O\n");
    printf("| 2) JUEGO DE BINGO                    |\n");
    printf("O--o--o--o--o--o--o--o--o--o--o--o--o--O\n");
    printf("| 3) OPERACIONES CON MATRICES          |\n");
    printf("O--o--o--o--o--o--o--o--o--o--o--o--o--O\n");
    printf("| 4) CUADRADO MAGICO                   |\n");
    printf("O--o--o--o--o--o--o--o--o--o--o--o--o--O\n");
    printf("| 5) *SALIR*                           |\n");
    printf("O--o--o--o--o--o--o--o--o--o--o--o--o--O\n");
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        int opcion = 1;
        do
        {
            wePresentacion(MENU);
            menu();
            if (opcion < 1 || opcion > 5)
                printf("Elija una opccion VALIDA\n");
            opcion = weIngresarEntero("Ingrese una de las opciones");
        } while (opcion < 1 || opcion > 5);

        switch (opcion)
        {
        case 1:
            do
            {
                Ventas();
            } while (wePreguntarSN(false, "Desea Volver a Calcular los Prestamos Personales?"));
            break;
        case 2:
            do
            {
                Bingo();
            } while (wePreguntarSN(false, "Desea Volver a Jugar Bingo?"));
            break;
        case 3:
            do
            {
                Matrices();
            } while (wePreguntarSN(false, "Desea Volver a Hacer Operaciones con Matrices?"));
            break;
        case 4:
            do
            {
                cuadradoMagico();
            } while (wePreguntarSN(false, "Desea Volver a Generar un Cuadrado Magico?"));

            break;
        case 5:
            goto salir;
            break;
        }
    }
salir:
    return 0;
}
