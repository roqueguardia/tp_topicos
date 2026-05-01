#include "tablero.h"

void crearTablero(tTablero *t)
{
    int i, j;
    for(i = 0; i < FILAS; i++)
        for(j = 0; j < COLUMNAS; j++)
            t->celdas[i][j] = 0;
}

void borrarTablero(tTablero *t)
{
    crearTablero(t);
}

void dibujarTablero(const tTablero *t, uint16_t offsetX, uint16_t offsetY)
{
    int i, j;
    for(i = 0; i < FILAS; i++)
        for(j = 0; j < COLUMNAS; j++)
            if(t->celdas[i][j] != 0)
                gbt_dibujar_pixel(offsetX + j * TAM_CELDA,
                                  offsetY + i * TAM_CELDA,
                                  t->celdas[i][j]);
}

int filaCompleta(const tTablero *t, int fila)
{
    int j;
    for(j = 0; j < COLUMNAS; j++)
        if(t->celdas[fila][j] == 0)
            return 0;
    return 1;
}

void eliminarFila(tTablero *t, int fila)
{
    int i, j;
    for(i = fila; i > 0; i--)
        for(j = 0; j < COLUMNAS; j++)
            t->celdas[i][j] = t->celdas[i-1][j];

    for(j = 0; j < COLUMNAS; j++)
        t->celdas[0][j] = 0;
}
