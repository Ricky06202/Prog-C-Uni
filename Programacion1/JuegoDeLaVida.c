#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Lib/P1/MasUsados.h>

#define TITULO "", 3, "      Juego De La Vida", "2IL112", 2021, "2do", true, "Cecilia Gonzalez"

void ponerElMarco(int tam, char matriz[tam][tam])
{
  for (int i = 0; i < tam; i++)
    for (int j = 0; j < tam; j++)
    {
      if (i == 0)
      {
        if (j == 0)
          matriz[i][j] = 201;

        if (j > 0 && j < tam - 1)
          matriz[i][j] = 205;

        if (j == tam - 1)
          matriz[i][j] = 187;
      }
      if (i > 0 && i < tam - 1)
        if (j == 0 || j == tam - 1)
          matriz[i][j] = 186;

      if (i == tam - 1)
      {
        if (j == 0)
          matriz[i][j] = 200;

        if (j > 0 && j < tam - 1)
          matriz[i][j] = 205;

        if (j == tam - 1)
          matriz[i][j] = 188;
      }
    }

  /*
    ↓ columna 0                         ↓ columna recibida - 1
    ------------------------------------- ← fila 0
    |                                   |
    |                                   |
    |                                   |
    |                                   |
    |                                   |
    |                                   |
    |                                   |
    ------------------------------------- ← fila recibida - 1
  */
}

void ponerLosAsteriscos(int tam, char matriz[tam][tam])
{
  for (int i = 1, j = tam - 2; i < tam - 1; i++, j--)
  {
    matriz[i][i] = '*';
    matriz[i][j] = '*';
  }

  /*

   *      *       para la primera diagonal uno pregunta si la fila y la columna son iguales y si lo son vas
    *    *        poniendo asteriscos
     *  *         para la segunda diagonal uno suele crear una variable que vaya aumentando y otra q vaya
      **          disminuyendo
      **
     *  *
    *    *
   *      *

   */
}

bool registrarAsteriscos(int tam, char matriz[tam][tam], int posicionY, int posicionX)
{
  int contar = 0;

  for (int i = posicionY - 1; i <= posicionY + 1; i++)
    for (int j = posicionX - 1; j <= posicionX + 1; j++)
      if (matriz[i][j] == '*')
        contar++;

  if (contar == 3)
    return true;
  else
    return false;

  /*      aki es la posicion recibida - 1 en Y
          ↓
        0 0 0
        0 * 0 ← posicion recibida + 1 en X
        0 0 *
          ↑posicion recibida + 1 en Y

  si hay exactamente 3 debuelve true
  solo verificar la posicion recibida
  */
}

void nuevoAsterisco(int tam, char matrizActualizada[tam][tam], int posicionY, int posicionX, bool registrarAsterisco)
{
  if (registrarAsterisco)
    matrizActualizada[posicionY][posicionX] = '*';

  /*
  cuando "registrarAsteriscos()" devuelva true vas a colocar un asterisco
  en la posicion recibida en la matrizActualizada(osea la otra matriz)
  */
}

void mostrarMatriz(int tam, char matriz[tam][tam], char matrizActualizada[tam][tam])
{
  for (int f = 0; f < tam; f++)
  {
    for (int c = 0; c < tam; c++)
      printf("%c", matriz[f][c]);
    printf("\t");

    for (int c = 0; c < tam; c++)
      printf("%c", matrizActualizada[f][c]);
    printf("\n");
  }
  printf("\n\n");
}

void limpiarMatriz(int tam, char matriz[tam][tam])
{
  for (int f = 0; f < tam; f++)
    for (int c = 0; c < tam; c++)
      matriz[f][c] = ' ';
}

int main(int argc, char const *argv[])
{
  do
  {
    wePresentacion(TITULO);
    int tam;
    while (true) // este ciclo nos permite estar seguros de que el usuario ingreso un numero valido
    {
      printf("Ingrese el tama%co de la Matriz Cuadrada", 164);
      tam = weIngresarEntero("");
      if (tam >= 5)
        break;
      printf("**Debe-Ser-5-o-Mayor**\n");
    }

    char universo1[tam][tam], universo2[tam][tam];

    // establecemos las condiciones iniciales de la matriz principal
    limpiarMatriz(tam, universo1);
    ponerElMarco(tam, universo1);
    ponerLosAsteriscos(tam, universo1);

    wePresentacion(TITULO);
    int limite;
    while (true) // este ciclo nos permite estar seguros de que el usuario ingreso un numero valido
    {
      limite = weIngresarEntero("Ingrese la Cantidad de Generaciones");
      if (limite >= 1)
        break;
      printf("**Debe-Ser-1-o-Mayor**\n");
    }

    wePresentacion(TITULO);
    int contador = 0;
    while (contador++ < limite)
    {
      // en este primer paso preparamos al universo2 para comenzar a recibir los asteriscos del universo1
      limpiarMatriz(tam, universo2);
      ponerElMarco(tam, universo2);
      for (int i = 1; i < tam - 1; i++)
        for (int j = 1; j < tam - 1; j++)
          nuevoAsterisco(tam, universo2, i, j, registrarAsteriscos(tam, universo1, i, j));
      printf("GENERACION %d\n\n", contador);
      mostrarMatriz(tam, universo1, universo2);
      // luego de mostradas las matrices preparamos al universo1 con una nueva generacion por si acaso se desea
      // volver a repetir el bucle, al fin y al cabo no se va a ver si no se repite otra vez el bucle
      limpiarMatriz(tam, universo1);
      ponerElMarco(tam, universo1);
      for (int i = 1; i < tam - 1; i++)
        for (int j = 1; j < tam - 1; j++)
          nuevoAsterisco(tam, universo1, i, j, registrarAsteriscos(tam, universo2, i, j));
      system("pause");
    }
  } while (wePreguntarSN(false, "Desea volver a Jugar?"));
  return 0;
}
