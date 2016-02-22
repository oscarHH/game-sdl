/**
 * Created by oscar hernandez hernandez on 02/2016.
 */
#include "board.h"
int contador =0;
int contador2 =0;
int contador3 =0;

Board::Board():
    vacio{}
{
}


//0 continua
//1 no continua
int Board::checkColision(Pice *pieza)
{

    int x1,x2;
    int y1,y2;
    int posX1,posX2;
    int posY1,posY2;

    x1 = pieza->piece.posX;
    x2 = pieza->piece2.posX;

    y1 = pieza->piece.posY;
    y2 = pieza->piece2.posY;


    posX1 = (x1/pieceHeight);
    posX2 = (x2/pieceHeight);


    posY1 =( y1/pieceHeight)+1;
    posY2 =( y2/pieceHeight)+1;


    //abajo
    /*if( (y1 >= boarpiece[posY1][posX1].posY-40 &&boarpiece[posY1][posX1].posY >0 )||
            (y2 >= boarpiece[posY2][posX2].posY-40 &&boarpiece[posY2][posX2].posY >0)){
        //boarpiece[posY1-1][posX1] =  pieza->piece;
        //boarpiece[posY2-1][posX2] =  pieza->piece2;

        return 0;
    }*/

    //limite abajo
    /*if ( y1 >= (height -pieceHeight ) ||  y2 >= (height -pieceHeight )) {
        boarpiece[posY1-1][posX1] =  pieza->piece;
        boarpiece[posY2-1][posX2] =  pieza->piece2;
        return 0;
    }*/


    //izquierda
    if(boarpiece[posY1][posX1-1].tipo != -1 || boarpiece[posY2][posX2-1].tipo != -1){
        //printf("detecto arreglos");
        return 3;
    }


    //derecha
    if(boarpiece[posY1][posX1+1].tipo != -1 || boarpiece[posY2][posX2+1].tipo != -1){
        return 2;
    }

    //izquierda
    if( x1 <= 0 ||  x2 <= 0  ||x1 == -40){
        return 3;
    }

    //derecha
    if(x1 >= (with -piecewith ) ||  x2 >= ( with -piecewith )){
        return 2;
    }


    return -1;
}



int Board::nocolision(Pice *pieza)
{

    int x1,x2;
    int y1,y2;
    int posX1,posX2;
    int posY1,posY2;

    x1 = pieza->piece.posX;
    x2 = pieza->piece2.posX;

    y1 = pieza->piece.posY;
    y2 = pieza->piece2.posY;


    posX1 = (x1/pieceHeight);
    posX2 = (x2/pieceHeight);


    posY1 =( y1/pieceHeight)+1;
    posY2 =( y2/pieceHeight)+1;

    if( boarpiece[posY1][posX1].tipo != -1 && boarpiece[posY2][posX2].tipo != -1){
            boarpiece[posY1-1][posX1] =  pieza->piece;
            boarpiece[posY2-1][posX2] =  pieza->piece2;
            //printf("aqui");
            return 3;
        }



    if ( y1 >= (height -pieceHeight ) ||  y2 >= (height -pieceHeight )) {
        boarpiece[posY1-1][posX1] =  pieza->piece;
        boarpiece[posY2-1][posX2] =  pieza->piece2;
        return 3;
    }

    if( boarpiece[posY2][posX2].tipo != -1){
            boarpiece[posY2-1][posX2] =  pieza->piece2;
            return 2;
        }


    if(boarpiece[posY1][posX1].tipo != -1 ){
            boarpiece[posY1-1][posX1] =  pieza->piece;
            return 1;
        }

    return 0;

}


void Board::paintboard(SDL_Renderer *render)
{

    //printf("+++++++++++++++++++++++++++++++++++++++\n");
    for (int var = 0; var < 12; ++var) {
        for (int var2 = 0; var2 < 6; ++var2) {
            SDL_Rect  fillRect;
            if(boarpiece[var][var2].tipo !=-1){
                fillRect = { boarpiece[var][var2].posX,boarpiece[var][var2].posY,30,30 }; //x,y,h,w
                SDL_SetRenderDrawColor( render,boarpiece[var][var2].colorR,boarpiece[var][var2].colorG,boarpiece[var][var2].colorB, 0 );
                SDL_RenderFillRect( render, &fillRect );
            }
            SDL_RenderDrawPoint(render,var2 * 40,var*40);
           // printf("%i,",boarpiece[var][var2].tipo);
        }
        //printf("\n");
    }
}

void Board::clearPiece()
{
    //printf("################soy un separador###############\n");
    for (int varY = 0; varY < 12; ++varY) {
        //int varY = 11;
        int resp=-1;
        int bandera =-1;
        int cuadros = -1;

        for (int varX = 0; varX < 6; ++varX) {

            if(varX == 0  &&  boarpiece[varY][varX].tipo != -1   ){
                resp =  boarpiece[varY][varX].tipo;
                bandera = varX;
                ++cuadros;
            }

            if( varX <= 2 &&
                    boarpiece[varY][varX].tipo != -1
                    && resp != boarpiece[varY][varX].tipo  ){
                resp =  boarpiece[varY][varX].tipo;
                bandera = varX;
                cuadros = 0;
            }

            if(resp  ==  boarpiece[varY][varX].tipo && boarpiece[varY][varX].tipo != -1){
                ++cuadros;
            }else{
                cuadros=0;
            }

            //si existen mas cuadros
            if(cuadros  > 3){
                for (int remplazo = varY; remplazo >= 0; --remplazo) {
                    if(remplazo-1 <= 0){
                        break;
                    }
                    for( int i = bandera; i < bandera+cuadros ; ++i){
                        boarpiece[remplazo-1][i].posY += 40;
                       boarpiece[remplazo][i] = boarpiece[remplazo-1][i];
                    }

                }

            }
        }
    }




}

void Board::clearPieceVertical()
{

    for (int varX = 0; varX < 6; ++varX) {
        int resp=-1;
        int bandera =-1;
        int cuadros = 0;
        for (int varY = 11; varY >= 0; --varY) {
            if(varY == 11  &&  boarpiece[varY][varX].tipo != -1   ){
                resp =  boarpiece[varY][varX].tipo;
                bandera = varY;
            }

            if(resp  ==  boarpiece[varY][varX].tipo && boarpiece[varY][varX].tipo != -1 ){
                ++cuadros;
            }else{
                bandera = varY;
                resp =  boarpiece[varY][varX].tipo;
                cuadros=1;
            }



            //si existen mas cuadros
            if(cuadros  > 3){
                for (int remplazo = bandera; remplazo >= 0; --remplazo) {
                    if(remplazo-1 <= 0){
                        break;
                    }
                    for( int i = bandera; i < bandera+cuadros ; ++i){
                       boarpiece[remplazo][varX] = vacio;
                    }
                }
            }

        }
    }
}
