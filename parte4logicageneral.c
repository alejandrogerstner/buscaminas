#include <stdio.h>

// ------ FUNCIONES QUE HACEN TUS COMPAÑEROS ------
// Vos solo las llamás. NO las implementes acá.
void inicializarTableros(char real[][30], char visible[][30], int f, int c);
void colocarMinas(char real[][30], int f, int c, int minas);
void calcularEntorno(char real[][30], int f, int c);
void imprimirVisible(char visible[][30], int f, int c);
void pedirCoordenadas(int *fila, int *columna);
int analizarJugada(char real[][30], char visible[][30], int fila, int columna);
int chequearVictoria(char visible[][30], char real[][30], int f, int c);
// --------------------------------------------------


// ==================================================
//        PARTE 4 — LÓGICA GENERAL DEL JUEGO
// ==================================================

void logicaGeneral(int filas, int columnas, int minas)
{
    char real[30][30];
    char visible[30][30];

    int fila, columna;
    int estado = 0;   // 0: sigue | 1: perdió | 2: ganó

    // ------ INICIALIZACIÓN DEL JUEGO ------
    inicializarTableros(real, visible, filas, columnas);
    colocarMinas(real, filas, columnas, minas);
    calcularEntorno(real, filas, columnas);

    // ------ BUCLE PRINCIPAL DE JUEGO ------
    while (1)
    {
        imprimirVisible(visible, filas, columnas);

        pedirCoordenadas(&fila, &columna);

        estado = analizarJugada(real, visible, fila, columna);

        if (estado == 1) {
            printf("\n>>> PISASTE UNA MINA — PERDISTE <<<\n");
            break;
        }

        if (chequearVictoria(visible, real, filas, columnas)) {
            printf("\n>>> ¡FELICITACIONES, GANASTE! <<<\n");
            break;
        }
    }
}



