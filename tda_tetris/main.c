/*PruebaTetris/
├── main.c          → solo el loop principal, lo más limpio posible
├── tablero.h       → declaraciones del TDA Tablero
├── tablero.c       → implementación del TDA Tablero
├── pieza.h         → declaraciones del TDA Pieza
├── pieza.c         → implementación del TDA Pieza
├── dibujos.h       → declaraciones de funciones gráficas
├── dibujos.c       → implementación de funciones gráficas*/

#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"
#include "dibujos.h"
#include "tablero.h"

#define ANCHO_VENTANA 128
#define ALTO_VENTANA  128
#define ESCALA_VENTANA 5

#define CANT_COLORES 16
tGBT_ColorRGB paletaCGA[CANT_COLORES] =
{
    {0x00, 0x00, 0x00}, // 0:  Negro
    {0x27, 0x73, 0xF5}, // 1:  Azul
    {0x00, 0xAA, 0x00}, // 2:  Verde
    {0x00, 0xAA, 0xAA}, // 3:  Cian
    {0xAA, 0x00, 0x00}, // 4:  Rojo
    {0xAA, 0x00, 0xAA}, // 5:  Magenta
    {0xAA, 0x55, 0x00}, // 6:  Marron
    {0xAA, 0xAA, 0xAA}, // 7:  Gris claro
    {0x55, 0x55, 0x55}, // 8:  Gris oscuro
    {0x55, 0x55, 0xFF}, // 9:  Azul brillante
    {0x55, 0xFF, 0x55}, // 10: Verde brillante
    {0x55, 0xFF, 0xFF}, // 11: Cian brillante
    {0xFF, 0x55, 0x55}, // 12: Rojo brillante
    {0xFF, 0x55, 0xFF}, // 13: Magenta brillante
    {0xFF, 0xFF, 0x55}, // 14: Amarillo
    {0xFF, 0xFF, 0xFF}  // 15: Blanco
};
int main(int argc, char* argv[])
{
    if(gbt_iniciar() != 0)
    {
        fprintf(stderr, "Error al iniciar GBT\n");
        return -1;
    }

    if(gbt_crear_ventana("Ejercicio 1", ANCHO_VENTANA, ALTO_VENTANA, ESCALA_VENTANA) != 0)
    {
        fprintf(stderr, "Error al crear ventana\n");
        return -1;
    }

    if(gbt_aplicar_paleta(paletaCGA, CANT_COLORES, GBT_FORMATO_888) != 0)
    {
        fprintf(stderr, "Error al aplicar paleta\n");
        return -1;
    }

    tTablero tablero;
    crearTablero(&tablero);
    tablero.celdas[0][0] = 4;
    tablero.celdas[5][3] = 2;

    // Centro de la ventana
    uint16_t x = (ANCHO_VENTANA / 2) - (TAM_CUADRADO / 2);
    uint16_t y = (ALTO_VENTANA  / 2) - (TAM_CUADRADO / 2);

    uint8_t corriendo = 1;

    while(corriendo)
    {
        gbt_procesar_entrada();
        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();

        if(tecla == GBTK_ESCAPE)
            corriendo = 0;
        else if(tecla == GBTK_ARRIBA  )
            y--;
        else if(tecla == GBTK_ABAJO && y < 120)
            y++;
        else if(tecla == GBTK_IZQUIERDA && x > 0)
            x--;
        else if(tecla == GBTK_DERECHA && x < 120)
            x++;
        gbt_borrar_backbuffer(1); // fondo negro
        dibujarTablero(&tablero, 0, 0);
        dibujarCuadrado(x, y, 14); // amarillo
        gbt_volcar_backbuffer();
        gbt_esperar(16);
    }

    gbt_destruir_ventana();
    gbt_cerrar();
    return 0;
}
