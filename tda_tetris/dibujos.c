#include"dibujos.h"
void dibujarCuadrado(uint16_t x, uint16_t y, uint8_t color)
{
    uint16_t i, j;

    for(i = 0; i < TAM_CUADRADO; i++)
    {
        for(j = 0; j < TAM_CUADRADO; j++)
        {
            gbt_dibujar_pixel(x + j, y + i, color);
        }
    }
}
