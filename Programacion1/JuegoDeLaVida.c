#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ponerElMarco(int filas, int columnas, char matriz[filas][columnas]){
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

void ponerLosAsteriscos(int filas, int columnas, char matriz[filas][columnas]){
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

bool registrarAsteriscos(int filas, int columnas, char matriz[filas][columnas], int posicionX, int posicionY){
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

void nuevoAsterisco(int filas, int columnas, char matrizActualizada[filas][columnas],int posicionX, int posicionY, bool registrarAsterisco){
/*
cuando "registrarAsteriscos()" devuelva true vas a colocar un asterisco
en la posicion recibida en la matrizActualizada(osea la otra matriz)
*/
}
