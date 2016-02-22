/**
 * Created by oscar hernandez hernandez on 02/2016.
 */
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "pice.h"
#include "definitions.h"

class Board
{
public:
    Board();
    int checkColision(Pice * pieza);
    void paintboard(SDL_Renderer  * render);
    int nocolision(Pice * pieza);
    void clearPiece();
    void clearPieceVertical();

private:
    propertis boarpiece [filas][columnas];
    propertis vacio;

};

#endif // BOARD_H
