#include <stdio.h>

// ----------------------------------------------------------
// PARTE 5: IMPRIMIR MATRIZ VISIBLE + PERSISTENCIA (opcional)
// ----------------------------------------------------------

// Imprime el tablero que ve el jugador
void imprimirVisible(char visible[][30], int filas, int columnas)
{
    printf("\n    ");
    for (int c = 0; c < columnas; c++)
        printf("%2d ", c);
    printf("\n");

    printf("   -------------------------------\n");

    for (int f = 0; f < filas; f++)
    {
        printf("%2d | ", f);
        for (int c = 0; c < columnas; c++)
        {
            printf("%c  ", visible[f][c]);
        }
        printf("\n");
    }

    printf("\n");
}



// ----------------------------------
