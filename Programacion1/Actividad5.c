#include "Lib/P1/Actividad4.h"
#include "Lib/P1/MasUsados.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "stdbool.h"

#define MENU "Ricardo Sanjur",3, "     Asignacion-Arreglos", "2IL112", 2021, "2do", true, "Cecilia Gonzalez"
#define ACT1 "Ricardo Sanjur",3, "     Tablas de Promedio", "2IL112", 2021, "2do", true, "Cecilia Gonzalez"
#define ACT2 "Ricardo Sanjur",3, "   Numeros Primos Felices", "2IL112", 2021, "2do", true, "Cecilia Gonzalez"
#define ACT3 "Ricardo Sanjur",3, "Metodo de Ordenacion QuickSort", "2IL112", 2021, "2do", true, "Cecilia Gonzalez"

float notaAleatoria()
{
    return (35 + rand() % (99 + 1 - 35)) + (rand() % (100 + 1)) / 100.0;
}

int numeroAleatorio(int max)
{
    return rand() % max;
}

char *nombres[] = {
    "Roberto Suares",
    "Adriana Hernandez",
    "Patricio Lopez",
    "Patricia Escribano",
    "Humberto Montiel",
    "Asuncion Murillo",
    "Ariana Caceres",
    "Jacinto Costa",
    "Muhammad Rodrigues",
    "Aurelio De-La-Torre",
    "Cipriano Zaragoza",
    "Eduardo Gilabert",
    "Dolores Guirado",
    "Khalid Oliver",
    "Mireia Salgado",
    "Jorge Becerra",
    "Patricia Valle",
    "Gladys Calvo",
    "Juan-Francisco Ochoa",
    "Nadia Quintana",
    "Sheila Pozo",
    "Anibal Borrego",
    "Celestina Jaime",
    "Benat Duque",
    "Yassine Plasencia",
    "Marcela Elvira",
    "Patricio Cuadrado",
    "Jacinto Xu",
    "Lorenza Quintana",
    "Carlos Soto",
    "Guadalupe Guerra",
    "Anibal Escobar",
    "Bernardino Pedrosa",
    "Thomas Barrero",
    "Filomena Arnau",
    "Joaquin de La Cruz",
    "Mariano Figueroa",
    "Beatriz Alfonso",
    "Fabiola Mansilla",
    "Saray Matas",
    "Moussa Amores",
    "Tomas Carrera",
    "Judit Fernandez",
    "Esteban de Diego",
    "Purificacion Parrilla",
    "Jaume Mira",
    "Francesc Simon",
    "Melanie Valcarcel",
    "Marius Teruel",
    "Yoel Duarte",
    "Olaya Fernandez",
    "Arantxa Romera",
    "Roman Montes",
    "Rocio Jorge",
    "Mihai Da-Silva",
    "Montse Redondo",
    "Concepcion Marin",
    "Marisa Zabala",
    "Mirian Castilla",
    "Noemi Casanova",
    "Candido Sanchis",
    "Blas Vela",
    "Esther Serra",
    "Emilio Noguera",
    "Aitziber Cobos",
    "Jose-Luis Zhang",
    "Alfonsa Maya",
    "Anne Catala",
    "Izan Palomares",
    "Purificacion Bravo",
    "Eugenio Parra",
    "Maria-Ines Orellana",
    "Axel Cristobal",
    "Bibiana Sanchis",
    "Vera Quevedo",
    "Adrian Segui",
    "Adelina Pavon",
    "Eusebio Francisco",
    "Catalina Marques",
    "Aina Sanchez",
};

int cantNombres = sizeof(nombres) / sizeof(char *);
int cant = 0;

char *elegirNombre(int usados[])
{
    bool listo;
    do
    {
        usados[cant] = numeroAleatorio(cantNombres);
        listo = true;
        for (int i = 0; i < cant; i++)
        {
            if (usados[cant] == usados[i])
            {
                listo = false;
                break;
            }
        }
    } while (!listo);
    return nombres[usados[cant++]];
}

char notaEnLetras(float nota)
{
    if (nota >= 91)
        return 'A';
    else if (nota >= 81)
        return 'B';
    else if (nota >= 71)
        return 'C';
    else if (nota >= 61)
        return 'D';
    else
        return 'F';
}

void imprimirTablaDeDatos(char *alumno[], float promedio[], int totalAlumnos)
{
    printf("____________________________________________________________\n");
    printf("| NUM |                NOMBRE   | PROMEDIO | NOTA EN LETRA |\n");
    printf("|_____|_________________________|__________|_______________|\n");
    for (int i = 0; i < totalAlumnos; i++)
    {
        printf("| %3d)| %23s | %7.2f  | %7c       |\n", i + 1, alumno[i], promedio[i], notaEnLetras(promedio[i]));
        printf("|_____|_________________________|__________|_______________|\n");
    }
}

int mayorPromedio(float promedio[], int totalAlumnos)
{
    float mayor = promedio[0];
    int pos = 0;
    for (int i = 1; i < totalAlumnos; i++)
    {
        if (mayor < promedio[i])
        {
            mayor = promedio[i];
            pos = i;
        }
    }
    return pos;
}

int menorPromedio(float promedio[], int totalAlumnos)
{
    float menor = promedio[0];
    int pos = 0;
    for (int i = 1; i < totalAlumnos; i++)
    {
        if (menor > promedio[i])
        {
            menor = promedio[i];
            pos = i;
        }
    }
    return pos;
}

void generarTabla(char *alumno[], float promedio[], int usados[], int totalAlumnos)
{
    if (wePreguntarSN(false, "Desea generar los nombres automaticamente?"))
        for (int i = 0; i < totalAlumnos; i++)
            alumno[i] = elegirNombre(usados);
    else
        for (int i = 0; i < totalAlumnos; i++)
        {
            char aux[20][100];
            printf("%d) ", i + 1);
            alumno[i] = weIngresarTexto(aux[i], "Ingrese un nombre");
        }
    for (int i = 0; i < totalAlumnos; i++)
    {
        float suma = 0;

        for (int j = 0; j < 10; j++)
            suma += notaAleatoria();

        promedio[i] = suma / 10;
    }
    wePresentacion(ACT1);
    imprimirTablaDeDatos(alumno, promedio, totalAlumnos);
    printf("\n");
    printf("______________________________________________________________\n");
    printf("|Estudiante de mayor promedio: | %24s    |\n", alumno[mayorPromedio(promedio, totalAlumnos)]);
    printf("|______________________________|_____________________________|\n");
    printf("|Estudiante de menor promedio: | %24s    |\n", alumno[menorPromedio(promedio, totalAlumnos)]);
    printf("|______________________________|_____________________________|\n");
    float promedioGeneral;
    float suma = 0;
    for (int i = 0; i < totalAlumnos; i++)
        suma += promedio[i];
    printf("Promedio General de la clase:  | %24.2f    |\n", suma / totalAlumnos);
    printf("|______________________________|_____________________________|\n");
}

void act1()
{
    do
    {
        int totalAlumnos;
        do
        {
            wePresentacion(ACT1);
            totalAlumnos = weIngresarEntero("Ingrese la cantidad de alumnos");
            if (totalAlumnos < 1 || totalAlumnos > cantNombres)
            {
                printf("Ingrese una cantidad entre 1 y %d\n", cantNombres);
                system("pause");
            }
        } while (totalAlumnos < 1 || totalAlumnos > cantNombres);

        int usados[totalAlumnos];     // 20
        char *alumno[totalAlumnos];   // 20
        float promedio[totalAlumnos]; // 20
        generarTabla(alumno, promedio, usados, totalAlumnos);
    } while (wePreguntarSN(false, "Desea volver a hacer la tabla?"));
}

void menu()
{
    wePresentacion(MENU);
    printf("______________________________________\n");
    printf("|Elija una de las siguientes opciones|\n");
    printf("|____________________________________|\n");
    printf("|1) Tabla de promedios               |\n");
    printf("|____________________________________|\n");
    printf("|2) Lista de numeros Primos Felices  |\n");
    printf("|____________________________________|\n");
    printf("|3) Metodo QuickSort                 |\n");
    printf("|____________________________________|\n");
    printf("|4) Salir                            |\n");
    printf("|____________________________________|\n");
}

void generarPrimosFelices(int num[], int cantNumeros)
{
    int cant = 0;
    int n = 0;
    while (cant < cantNumeros)
    {
        if (fnPrimo(n) && fnFeliz(n))
            num[cant++] = n;
        n++;
    }
}

void act2()
{
    do
    {
        int cantNumeros;
        do
        {
            wePresentacion(ACT2);
            cantNumeros = weIngresarEntero("Ingrese la cantidad de numeros primos felices");
            if (cantNumeros < 1)
                printf("Debe ser un numero Positivo\n");
        } while (cantNumeros < 1);
        wePresentacion(ACT2);
        int numerosEnterosFelices[cantNumeros];
        generarPrimosFelices(numerosEnterosFelices, cantNumeros);
        printf("________________________\n");
        printf("|     |     Numeros    |\n");
        printf("| Num |  Primos Felices|\n");
        printf("|_____|________________|\n");
        for (int i = 0; i < cantNumeros; i++)
        {
            printf("|%3d) |  %7d       |\n", i + 1, numerosEnterosFelices[i]);
            printf("|_____|________________|\n");
        }
    } while (wePreguntarSN(false, "Desea volver a calcular los numeros?"));
}

void ordenarNumeros(int numero[], int inicio, int final)
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
        ordenarNumeros(numero, inicio, izquierda - 1);
        ordenarNumeros(numero, derecha + 1, final);
    }
}

void act3()
{
    do
    {
        int cantNumeros;
        do
        {
            wePresentacion(ACT3);
            cantNumeros = weIngresarEntero("Ingrese la cantidad de numeros a ordenar");
            if (cantNumeros < 1)
                printf("Debe ser un numero Positivo\n");
        } while (cantNumeros < 1);
        int listaDeNumeros[cantNumeros];
        int listaOrdenada[cantNumeros];
        if (wePreguntarSN(false, "Desea generar la lista de numeros automaticamente?"))
        {
            int max;
            do
            {
                wePresentacion(ACT3);
                max = weIngresarEntero("Ingrese el numero maximo de numeros aleatorios a generar");
                if (max == 0)
                    printf("Debe ser un numero mayor que 0\n");
            } while (max <= 0);

            for (int i = 0; i < cantNumeros; i++)
            {
                listaDeNumeros[i] = listaOrdenada[i] = rand() % (max * 2 + 1) - max;
            }
        }
        else
        {
            for (int i = 0; i < cantNumeros; i++)
            {
                printf("%d) ", i + 1);
                listaDeNumeros[i] = listaOrdenada[i] = weIngresarEntero("Ingrese un numero");
            }

            wePresentacion(ACT3);
        }

        wePresentacion(ACT3);

        ordenarNumeros(listaOrdenada, 0, cantNumeros - 1);
        printf("_____________________________________________________\n");
        printf("|       |       NUMEROS         |       NUMEROS     |\n");
        printf("|  NUM  |     SIN ORDENAR       |      ORDENADOS    |\n");
        printf("|_______|_______________________|___________________|\n");
        for (int i = 0; i < cantNumeros; i++)
        {
            printf("|%5d) |     %8d          |      %7d      |\n", i + 1, listaDeNumeros[i], listaOrdenada[i]);
            printf("|_______|_______________________|___________________|\n");
        }

    } while (wePreguntarSN(false, "Desea volver a acomodar otros numeros?"));
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int opcion;
    bool salir = false;
    while (true)
    {
        do
        {
            menu();
            opcion = weIngresarEntero("Ingrese una opcion valida");
        } while (opcion < 1 || opcion > 4);

        switch (opcion)
        {
        case 1:
            act1();
            break;
        case 2:
            act2();
            break;
        case 3:
            act3();
            break;
        default:
            salir = true;
            break;
        }
        if (salir)
            break;
    }

    return 0;
}
