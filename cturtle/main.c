#include <SDL2/SDL.h>

#include "common.h"
#include "turtle.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>



SDL_Color palette[]={
    { 26, 28, 44},
    { 93, 39, 93},
    {177, 62, 83},
    {239,125, 87},
    {255,205,117},
    {167,240,112},
    { 56,183,100},
    { 37,113,121},
    { 41, 54,111},
    { 59, 93,201},
    { 65,166,246},
    {115,239,247},
    {244,244,244},
    {148,176,194},
    { 86,108,134},
    { 51, 60, 87},
};



void Turtle_DrawStar(Turtle *turtle,double size) {
    Turtle_PenUp(turtle);
    Turtle_Turn(turtle,-90);
    Turtle_Move(turtle,size/8);
    Turtle_Turn(turtle,90);
    Turtle_PenDown(turtle);
    Turtle_Move(turtle,-size/2);
    for(int i=0;i<5;i++) {
        Turtle_Move(turtle,size);
        Turtle_Turn(turtle,144);
    }
}



int main() {

	bool quit=false;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window =    SDL_CreateWindow(GAME_TITLE,
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer =    SDL_CreateRenderer(window, -1,
                                SDL_RENDERER_ACCELERATED |
                                SDL_RENDERER_TARGETTEXTURE);

   	SDL_Event event;

    Turtle *turtle=Turtle_New(renderer);

    srand(time(NULL));

    Turtle_SetPenColor(turtle,palette[0]);
    Turtle_Clean(turtle);


    for(int i=0;i<10;i++) {
        Turtle_SetPenColor(turtle,palette[rand()%15+1]);
        Turtle_Jump(turtle,rand()%SCREEN_WIDTH,rand()%SCREEN_HEIGHT);
        Turtle_Turn(turtle,rand()%360);
        Turtle_DrawStar(turtle,rand()%50+50);
    }


    SDL_RenderPresent(renderer);

    while(!quit) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_QUIT:
                quit=true;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    quit=true;
                default: break;
                }
            default: break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}


