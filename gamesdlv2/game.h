/**
 * Created by oscar hernandez hernandez on 02/2016.
 */
#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include "definitions.h"
#include "pice.h"
#include "board.h"

class Game
{

public:
    Game();
    void run();
    void handle();
    void readKeys();

private:
    bool gamerun = true;
    SDL_Window* window;
    SDL_Event  evento;
    SDL_Renderer *render;
    bool pause = false;
    int move = 0;
    Pice piece;
    Board board;
    void renderPiece();
    int rotate;
};

#endif // GAME_H
