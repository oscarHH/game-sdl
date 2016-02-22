/**
 * Created by oscar hernandez hernandez on 02/2016.
 */
#include "pice.h"
#include "definitions.h"
#include <iostream>
#include <ctime>

Pice::Pice():
    piece(),
    piece2(),
    position(0)
{
    srand(time(0));
    piece.tipo = rand()%4;
    piece2.tipo = rand()%4;

    piece.colorR = colors[piece.tipo][0];
    piece.colorG = colors[piece.tipo][1];
    piece.colorB = colors[piece.tipo][2];

    piece2.colorR = colors[piece2.tipo][0];
    piece2.colorG = colors[piece2.tipo][1];
    piece2.colorB = colors[piece2.tipo][2];

    piece.posX = with/2-piecewith;
    piece2.posX = with/2;
}

void Pice::piecedraw(SDL_Renderer *render)
{

    SDL_Rect fillRect;
    SDL_Rect fillRect2;
    fillRect = { piece.posX,piece.posY,pieceHeight-10,piecewith-10 };
    fillRect2 = { piece2.posX,piece2.posY,pieceHeight-10,piecewith-10 };

    SDL_SetRenderDrawColor( render,piece.colorR,piece.colorG,piece.colorB, 0 );
    SDL_RenderFillRect( render, &fillRect );
    SDL_SetRenderDrawColor( render,piece2.colorR,piece2.colorG,piece2.colorB, 0 );
    SDL_RenderFillRect( render, &fillRect2 );
}



void Pice::move(int moveX, int moveY, bool a, bool b)
{
    if(a){
        piece.posX += moveX*pieceHeight;
        piece.posY += moveY*piecewith;

    }

    if(b){
        piece2.posX += moveX*pieceHeight;
        piece2.posY += moveY*piecewith;
    }

}

void Pice::rotate(int pos)
{
    switch (pos) {

    case 0:
        piece.posY = piece2.posY;
        piece2.posX +=piecewith;
        break;


    case 1://listo
        piece2.posX -=piecewith;
        piece2.posY +=pieceHeight;
        break;

    case 2://listo
        piece2.posX = piece.posX;
        piece2.posY -=pieceHeight;
        piece.posX +=piecewith;

        break;

    case 3://listo
        piece.posX -=piecewith;
        piece.posY +=piecewith;
        break;
    }
}


