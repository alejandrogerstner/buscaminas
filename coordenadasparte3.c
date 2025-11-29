#include <stdio.h>

// --------------------------------------------------------------
// PARTE 3: Entrada del jugador + análisis de jugada + expansión
// --------------------------------------------------------------

// Pedimos coordenadas al usuario
void pedirCoordenadas(int *fila, int *columna)
{
    printf("\nIngrese fila: ");
    scanf("%d", fila);

    printf("Ingrese columna: ");
    scanf("%d", columna);
}


// Validamos que la coordenada esté dentro del tablero
int coordenadaValida(int fila, int col, int filas, int columnas)
{
    return (fila >= 0 && fila < filas && col >= 0 && col < columnas);
}


// Expansión recursiva de ceros (destapa vecinos)
void expandirCeros(char real[][30], char visible[][30],
                   int fila, int col, int filas, int columnas)
{
    if (!coordenadaValida(fila, col, filas, columnas))
        return;

    if (visible[fila][col] != '#')
        return;   // ya fue destapada

    visible[fila][col] = real[fila][col];

    // Si no es cero, no sigue expandiendo
    if (real[fila][col] != '0')
        return;

    // Expansión a los 8 vecinos
    for (int df = -1; df <= 1; df++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (df == 0 && dc == 0) continue;
            expandirCeros(real, visible, fila + df, col + dc, filas, columnas);
        }
    }
}


// Analiza la jugada del jugador
// return 0 = sigue jugando
// return 1 = pisó mina
int analizarJugada(char real[][30], char visible[][30],
                   int fila, int col)
{
    // Si pisa una mina => perder
    if (real[fila][col] == '*') {
        visible[fila][col] = '*';
        return 1;
    }

    // Si pisa un número normal, lo destapamos
    if (real[fila][col] != '0') {
        visible[fila][col] = real[fila][col];
        return 0;
    }

    // Si pisa un 0 => expansión de ceros
    expandirCeros(real, visible, fila, col, 30, 30);

    return 0;
}
