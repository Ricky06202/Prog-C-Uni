#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "math.h"
#include "stdbool.h"

bool fnPrimo(int numero)
{
    if (numero <= 1)
        return false;
    for (int i = 2; i < numero; i++)
        if (numero % i == 0)
            return false;
    return true;
}

bool fnPerfecto(int numero)
{
    int suma = 0;
    if (numero <= 0)
        return false;
    for (int i = 1; i < numero; i++)
        if (numero % i == 0)
            suma += i;
    if (suma == numero)
        return true;
    else
        return false;
}

long fnInvertir(long numero)
{
    long invertido = 0;
    while (numero != 0)
    {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }
    return invertido;
}

long fnCifras(long numero)
{
    int contador = 0;
    while (numero != 0)
    {
        numero /= 10;
        contador++;
    }
    return contador;
}

void fnUlam(int numero)
{
    if (numero >= 1)
    {
        printf("%d ", numero);
        while (numero != 1)
        {
            if (numero % 2 == 0)
                numero /= 2;
            else
                numero = 3 * numero + 1;
            printf("%d ", numero);
        }
    }
}

bool fnAbundante(int numero)
{
    int abundancia = 0;
    for (int i = 1; i <= numero; i++)
        if (numero % i == 0)
            abundancia += i;
    if (abundancia > numero * 2)
        return true;
    else
        return false;
}

bool fnArmstrong(int numero)
{
    int suma = 0;
    int cifras = fnCifras(numero);
    int inicio = numero;
    while (numero != 0)
    {
        suma += (int)pow(numero % 10, cifras);
        numero /= 10;
    }
    if (suma == inicio)
        return true;
    else
        return false;
}

char fnParImpar(int numero)
{
    if (numero % 2 == 0)
        return 'P';
    else
        return 'I';
}

long fnFactorial(int numero)
{
    long factorial = 1;
    for (int i = 2; i <= numero; i++)
        factorial *= i;
    return factorial;
}

bool fnAmigos(int numero1, int numero2)
{
    int suma1 = 0, suma2 = 0;
    for (int i = 1; i < numero1; i++)
        if (numero1 % i == 0)
            suma1 += i;
    for (int i = 1; i < numero2; i++)
        if (numero2 % i == 0)
            suma2 += i;
    if (numero1 == suma2 && numero2 == suma1)
        return true;
    else
        return false;
}

bool fnCapicua(int numero)
{
    if (numero == fnInvertir(numero))
        return true;
    else
        return false;
}

bool fnPalindromo(char cadena[])
{
    /*for (int i = 0, j = strlen(cadena)-1; i < j; i++, j--)
        if (tolower(cadena[i]) != tolower(cadena[j]))
            return false;
    return true;*/
    char inv[strlen(cadena)]; 
    strcpy(inv, cadena);
    if (strcmpi(cadena, strrev(inv)) == 0)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    printf(fnPalindromo("olo") ? "si" : "no");
    return 0;
}


bool fnFeliz(int numero)
{
    int suma = 0;
    int periodos = 0;
    while (suma != 1)
    {
        suma = 0;
        while (numero != 0)
        {
            suma += powf((numero % 10), 2); // (numero % 10)
            numero /= 10;
        }
        numero = suma;
        if (++periodos == 8)
            break;
    }
    if (suma == 1)
        return true;
    else
        return false;
}
