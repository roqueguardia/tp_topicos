#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

#include <GBT/gbt.h>

#define FILAS      20
#define COLUMNAS   10
#define TAM_CELDA  8

typedef struct
{
    uint8_t celdas[FILAS][COLUMNAS];
} tTablero;

void crearTablero(tTablero *t);
void dibujarTablero(const tTablero *t, uint16_t offsetX, uint16_t offsetY);
void borrarTablero(tTablero *t);
int  filaCompleta(const tTablero *t, int fila);
void eliminarFila(tTablero *t, int fila);

#endif // TABLERO_H_INCLUDED
