/**
 * Created by oscar hernandez hernandez on 02/2016.
 */
#include "game.h"

Game::Game():
    piece{},
    rotate (0)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("puyo puyo",50,50,with,height,SDL_WINDOW_OPENGL  | SDL_WINDOW_SHOWN);
    SDL_SetWindowPosition(window,200,126);
    if(window == NULL){
        SDL_Quit();
    }

}

void Game::run()
{

    render = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    SDL_SetRenderDrawColor( render, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderPresent( render );
    //game loop star
    while(gamerun){
        SDL_WaitEventTimeout(&evento,200); ///time for events

        if(pause == false){
            handle();
        }
        readKeys();
    }


}

bool a =true;
bool b =true;
void Game::handle()
{
    if ( SDL_GetTicks()  > move  ){
        move += 1800;

        if(board.nocolision(&piece) == 2){
                b = false;
        }

        if(board.nocolision(&piece) == 1){
                a = false;
        }



        if( /*board.checkColision(&piece) == 0 &&*/ board.nocolision(&piece)==3){
            board.clearPieceVertical();
            board.clearPiece();
            piece = Pice();
            rotate = 0;
            a = true;
            b=true;
            //printf("valor y = %i",piece.piece.posY);
        }

        piece.move(0,1,a,b);
        renderPiece();

    }
}

void Game::readKeys()
{
    switch (evento.type) {
    case SDL_QUIT:
        gamerun = false;
        break;

    case SDL_KEYDOWN:
        switch (evento.key.keysym.sym) {

        case SDLK_p:
            pause = true;
            break;
        case SDLK_c:
            pause = false;
            break;

        case SDLK_DOWN:


            if(board.nocolision(&piece) == 2){
                    b = false;
            }

            if(board.nocolision(&piece) == 1){
                    a = false;
            }



            if(/*board.checkColision(&piece) == 0 &&*/ board.nocolision(&piece)==3 ){
                //printf("3\n");
                board.clearPieceVertical();
                board.clearPiece();
                piece = Pice();
                rotate = 0;
                a = true;
                b=true;
            }

            piece.move(0,1,a,b);
            renderPiece();


            break;

        case SDLK_LEFT:
            if(board.checkColision(&piece) != 3 && /*board.checkColision(&piece) != 0*/  board.nocolision(&piece)==0  && (a&&b)){

                if(rotate == 0){
                    if(piece.piece.posX >  0){
                        piece.move(-1,0,a,b);
                        renderPiece();
                    }
                }else if(rotate == 2){
                    if(piece.piece2.posX >  0){
                        piece.move(-1,0,a,b);
                        renderPiece();
                    }
                }else{
                    piece.move(-1,0,a,b);
                    renderPiece();
                }



            }
            break;

        case SDLK_RIGHT:

            if(board.checkColision(&piece) != 2 && /*board.checkColision(&piece) != 0*/ board.nocolision(&piece) == 0  && (a&&b)){

                //printf("pos : %i \n",rotate);
                if(rotate == 0){
                    if(piece.piece.posX+40 <  with -piecewith ){
                        piece.move(1,0,a,b);
                        renderPiece();
                    }
                }else if(rotate == 2){
                    if(piece.piece2.posX+40 <  with -piecewith ){
                        piece.move(1,0,a,b);
                        renderPiece();
                    }
                }else{
                    piece.move(1,0,a,b);
                    renderPiece();
                }

            }
            break;

        case SDLK_UP:

            if(/*board.checkColision(&piece) != 0*/board.nocolision(&piece) == 0 && (a&&b)){
                rotate++;
                //printf("rotate : %i ",rotate);
                if(  (rotate ==2 || rotate == 0) &&   piece.piece2.posX == (with-piecewith)  ){
                    piece.rotate(rotate);
                    piece.piece.posX -= piecewith;
                    piece.piece2.posX -= piecewith;
                    renderPiece();
                }else{
                    piece.rotate(rotate);
                    renderPiece();
                }

                if(rotate == 3){
                    rotate =-1;
                }
            }
            break;
        }
        break;

    default:
        break;
    }
}

void Game::renderPiece()
{
    SDL_SetRenderDrawColor(render, 0, 0, 0, 0xff);
    SDL_RenderClear(render);


    piece.piecedraw(render);
    board.paintboard(render);
    SDL_RenderPresent( render );
}

