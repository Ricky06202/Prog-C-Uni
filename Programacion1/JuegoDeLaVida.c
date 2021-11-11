/**
 * @archivo JuegoDeLaVida.c
 * @autor Ricardo Sanjur, Thais Samudio, Irina Matveeva,Pedro de la torre, Ana Guerra
 * @resumen
 * @version 0.3
 * @fecha 09-11-2021
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Lib/P1/MasUsados.h>

#define TITULO "", 3, "      Juego De La Vida", "2IL112", 2021, "2do", true, "Cecilia Gonzalez"

/**
 * @resumen Encargada de poner el borde en la matriz
 *
 * @parametro tam
 * @parametro matriz
 */
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
/**
 * @resumen Encargada de poner los asteriscos en forma de cruz en la matriz
 *
 * @parametro tam
 * @parametro matriz
 */
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
/**
 * @resumen Encargada de verificar los arrededores de una casilla de la matriz
 * devolviendo true si encuentra 3 asteriscos contando la casilla objetivo
 *
 * @parametro tam
 * @parametro matriz
 * @parametro posicionY
 * @parametro posicionX
 * @return true
 * @return false
 */
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
/**
 * @resumen Si registrarAsterisco devuelve true va a poner un asterisco en la posicion
 * donde dio true en la nueva dimension
 *
 * @parametro tam
 * @parametro matrizActualizada
 * @parametro posicionY
 * @parametro posicionX
 * @parametro registrarAsterisco
 */
void nuevoAsterisco(int tam, char matrizActualizada[tam][tam], int posicionY, int posicionX, bool registrarAsterisco)
{
  if (registrarAsterisco)
    matrizActualizada[posicionY][posicionX] = '*';

  /*
  cuando "registrarAsteriscos()" devuelva true vas a colocar un asterisco
  en la posicion recibida en la matrizActualizada(osea la otra matriz)
  */
}
/**
 * @resumen imprime las dos matrices una alado de la otra
 *
 * @parametro tam
 * @parametro matriz
 * @parametro matrizActualizada
 */
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
/**
 * @resumen asigna a todas las casillas de la matriz a espacio en blanco ' '
 *
 * @parametro tam
 * @parametro matriz
 */
void limpiarMatriz(int tam, char matriz[tam][tam])
{
  for (int f = 0; f < tam; f++)
    for (int c = 0; c < tam; c++)
      matriz[f][c] = ' ';
}
/**
 * @resumen verifica si aun hay asteriscos en la matriz
 *
 * @parametro tam
 * @parametro matriz
 * @return true
 * @return false
 */
bool sigueAlguienVivo(int tam, char matriz[tam][tam])
{
  for (int i = 1; i < tam - 1; i++)
    for (int j = 1; j < tam - 1; j++)
      if (matriz[i][j] == '*')
        return true;
  return false;
}
/**
 * @resumen verifica si las matrices son exactamente iguales y si aun tienen asteriscos
 * si es asi devuelve true
 *
 * @parametro tam
 * @parametro matriz
 * @parametro matrizActualizada
 * @return true
 * @return false
 */
bool hayInmortalidad(int tam, char matriz[tam][tam], char matrizActualizada[tam][tam])
{
  bool respuesta = false;
  for (int i = 1; i < tam - 1; i++)
    for (int j = 1; j < tam - 1; j++)
      if (matriz[i][j] == matrizActualizada[i][j] && sigueAlguienVivo(tam, matriz))
        respuesta = true;
      else
        return false;
  return respuesta;
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
      if (tam >= 5 && tam <= 50)
        break;
      printf("**Debe-Ser-Entre-5-y-50**\n");
    }

    char universo1[tam][tam], universo2[tam][tam], universoAux[tam][tam];

    // establecemos las condiciones iniciales de la matriz principal
    limpiarMatriz(tam, universo1);
    ponerElMarco(tam, universo1);
    ponerLosAsteriscos(tam, universo1);

    limpiarMatriz(tam, universoAux);

    wePresentacion(TITULO);
    int limite;
    while (true) // este ciclo nos permite estar seguros de que el usuario ingreso un numero valido
    {
      limite = weIngresarEntero("Ingrese la Cantidad de Generaciones");
      if (limite >= 1 && limite <= 1000)
        break;
      printf("**Debe-Ser-Entre-1-y-1000**\n");
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
      system("pause");

      if (hayInmortalidad(tam, universo1, universo2) || hayInmortalidad(tam, universo2, universoAux))
      {
        printf("\nSe Ha Alcanzado La Felicidad Absoluta");
        printf("\nEl Pueblo Goza de Inmortalidad");
        printf("\nSe Detendra El Juego Para No Perturbar A Esta Civilizacion\n\n");
        break;
      }

      for (int i = 1; i < tam - 1; i++)
        for (int j = 1; j < tam - 1; j++)
          universoAux[i][j] = universo2[i][j];

      // luego de mostradas las matrices preparamos al universo1 con una nueva generacion por si acaso se desea
      // volver a repetir el bucle, al fin y al cabo no se va a ver si no se repite otra vez el bucle
      limpiarMatriz(tam, universo1);
      ponerElMarco(tam, universo1);
      for (int i = 1; i < tam - 1; i++)
        for (int j = 1; j < tam - 1; j++)
          nuevoAsterisco(tam, universo1, i, j, registrarAsteriscos(tam, universo2, i, j));

      if (!sigueAlguienVivo(tam, universo1))
      {
        printf("\nTodos Murieron Por Soledad");
        printf("\nNo Hay Nadie Vivo Para Continuar\n\n");
        break;
      }
    }
  } while (wePreguntarSN(false, "Desea volver a Jugar?"));
  return 0;
}
