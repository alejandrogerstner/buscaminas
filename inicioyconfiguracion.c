#include <stdio.h>

#define MIN 2
#define MAX 30

void inicioDelJuego(int *filas, int *columnas, int *minas)
{
    printf("=====================================\n");
    printf("        BIENVENIDO AL BUSCAMINAS       \n");
    printf("=====================================\n");
    printf("Descubre todas las casillas sin minas.\n");
    printf("Ingrese el tamaño del tablero y la\n");
    printf("cantidad de minas para comenzar.\n\n");

    do {
        printf("Filas (%d a %d): ", MIN, MAX);
        scanf("%d", filas);

        printf("Columnas (%d a %d): ", MIN, MAX);
        scanf("%d", columnas);

        printf("Cantidad de minas: ");
        scanf("%d", minas);

        if (*filas < MIN || *filas > MAX ||
            *columnas < MIN || *columnas > MAX ||
            *minas <= 0 || *minas >= (*filas * *columnas))
        {
            printf("\nValores invalidos. Intente nuevamente.\n\n");
        }

    } while (*filas < MIN || *filas > MAX ||
             *columnas < MIN || *columnas > MAX ||
             *minas <= 0 || *minas >= (*filas * *columnas));
}
