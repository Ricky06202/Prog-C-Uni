#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
//vamo
void UnNumeroEsParOImpar();
void DosNumerosImprimirAmbosPositivos();
void RaizCuadradaDeUnNumero();
void LeerRealMostrarEntero();
void NombreYCarrera();
void TresNumerosIndicarOrden();
void HabitacionCamas();

int main(int argc, char const *argv[])
{
    system("cls");
    UnNumeroEsParOImpar();
    printf("\n");
    system("pause");
    system("cls");
    DosNumerosImprimirAmbosPositivos();
    printf("\n");
    system("pause");
    system("cls");
    RaizCuadradaDeUnNumero();
    printf("\n");
    system("pause");
    system("cls");
    LeerRealMostrarEntero();
    printf("\n");
    system("pause");
    system("cls");
    NombreYCarrera();
    printf("\n");
    system("pause");
    system("cls");
    TresNumerosIndicarOrden();
    printf("\n");
    system("pause");
    system("cls");
    HabitacionCamas();
    printf("\n");
    system("pause");
    return 0;
}

void UnNumeroEsParOImpar()
{
    int nombre;
    printf("El numero es Par o es Impar?\n");
    printf("Ingrese un numero: ");
    scanf("%d", &nombre);
    if (nombre % 2 == 0)
        printf("Es un numero Par");

    else
        printf("Es un numero impar");
}

void DosNumerosImprimirAmbosPositivos()
{
    int a, b;
    printf("Imprimir ambos numeros si son positivos los dos\n");
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    if (a > 0 && b > 0)
        printf("Los numeros %d y %d son positivos", a, b);
}

void RaizCuadradaDeUnNumero()
{
    int num;
    printf("Calcular la Raiz Cuadrada de un Numero\n");
    do
    {
        printf("Ingrese un numero positivo: ");
        scanf("%d", &num);
    } while (num <= 0);
    printf("La raiz cuadrada de: %d = %.2f", num, sqrt(num));
}

void LeerRealMostrarEntero()
{
    float num;
    printf("Lee un numero Real y muestra un Entero\n");
    printf("Ingrese un numero: ");
    scanf("%f", &num);
    printf("La parte entera del numero %.2f es: %d", num, (int)num);
}

void NombreYCarrera()
{
    char nombre[40], carrera[100];
    printf("Muestra el Nombre y la Carrera\n");
    printf("Ingrese su nombre: ");
    scanf(" %[^\n]%*c", &nombre);
    printf("Ingrese su carrera: ");
    scanf(" %[^\n]%*c", &carrera);
    printf("Estudiante: %s en la carrera: %s", nombre, carrera);
}

void TresNumerosIndicarOrden()
{
    int a, b, c;
    printf("Ingresando 3 numeros, te indica el orden en que estan\n");
    printf("Ingrese el Primer Numero: ");
    scanf("%d", &a);
    printf("Ingrese el Segundo Numero: ");
    scanf("%d", &b);
    printf("Ingrese el Tercer Numero: ");
    scanf("%d", &c);

    if (a > b && b > c)
        printf("Estan en orden Decreciente");
    else if (c > b && b > a)
        printf("Estan en orden Creciente");
    else
        printf("Estan Desordenados");
}

void HabitacionCamas()
{
    int habitacion, camas;
    char planta[10];
    printf("   Habitacion   Camas   Planta\n");
    printf("1) Individual     1     primera\n");
    printf("2) Individual     2     segunda\n");
    printf("3) Individual     2     tercera\n");
    printf("4) Individual     3     primera\n");
    printf("5) Individual     3     segunda\n");
    printf("6) Individual     3     segunda\n");
    printf("7) Individual     2     tercera\n");
    do
    {
        printf("Ingrese el numero correspondiente con la habitacion: ");
        scanf("%d", &habitacion);

        if (habitacion < 1 || habitacion > 7)
            printf("ERROR: numero de habitacion no existe\n");

    } while (habitacion < 1 || habitacion > 7);

    switch (habitacion)
    {
    case 1:
        camas = 1;
        strcpy(planta, "primera");
        break;
    case 2:
        camas = 2;
        strcpy(planta, "segunda");
        break;
    case 3:
        camas = 2;
        strcpy(planta, "tercera");
        break;
    case 4:
        camas = 3;
        strcpy(planta, "primera");
        break;
    case 5:
        camas = 3;
        strcpy(planta, "segunda");
        break;
    case 6:
        camas = 3;
        strcpy(planta, "segunda");
        break;
    case 7:
        camas = 2;
        strcpy(planta, "tercera");
        break;
    }
    printf("\nLa Habitacion numero %d se encuentra en la %s planta y posee %d camas\n\n", habitacion, planta, camas);
}
