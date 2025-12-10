#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ----------------------------------------------------------
// PARTE 2: GENERACIÓN DEL TABLERO (MINAS + ENTORNO)
// ----------------------------------------------------------

// Coloca 'minas' minas aleatorias en el tablero real
void colocarMinas(char real[][30], int filas, int columnas, int minas)
{
    srand(time(NULL));  // semilla para números aleatorios

    int colocadas = 0;

    while (colocadas < minas)
    {
        int f = rand() % filas;
        int c = rand() % columnas;

        if (real[f][c] != '*')   // si no hay mina ahí, colocamos una
        {
            real[f][c] = '*';
            colocadas++;
        }
    }
}



// Calcula cuántas minas hay alrededor de cada celda SIN mina
void calcularEntorno(char real[][30], int filas, int columnas)
{
    int df[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int f = 0; f < filas; f++)
    {
        for (int c = 0; c < columnas; c++)
        {
            // Si hay una mina, no se calcula número
            if (real[f][c] == '*')
                continue;

            int contador = 0;

            // Revisar las 8 posiciones vecinas
            for (int i = 0; i < 8; i++)
            {
                int nf = f + df[i];
                int nc = c + dc[i];

                // Chequear límites
                if (nf >= 0 && nf < filas && nc >= 0 && nc < columnas)
                {
                    if (real[nf][nc] == '*')
                        contador++;
                }
            }

            // Guardar el número como caracter
            real[f][c] = contador + '0';
        }
    }
}
