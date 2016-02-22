/**
 * Created by oscar hernandez hernandez on 02/2016.
 */
#ifndef PICE_H
#define PICE_H

#include <SDL.h>
struct propertis{
    int colorR;
    int colorG;
    int colorB ;
    int posY ;
    int posX ;
    int tipo = -1;
};

class Pice
{
public:
    Pice();
    void piecedraw(SDL_Renderer * render);
    propertis piece,piece2;

    //agregar dos parametros bool para ver que piesa puede seguir moviendose
    void move(int moveX, int moveY,bool a,bool b);
    void rotate(int pos);
    int position;

private:

    int colors[4][3]{ {247,49,49},{119,52,243},{74,221,112},{213,71,224} };

};

#endif // PICE_H
