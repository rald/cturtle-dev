#ifndef TURTLE_H
#define TURTLE_H

#include <SDL2/SDL.h>

#include "common.h"



typedef struct {
    double x,y,heading;
    bool isPenDown;
    SDL_Renderer *renderer;
} Turtle;



Turtle *Turtle_New(SDL_Renderer *renderer);
void Turtle_Free(Turtle *turtle);
void Turtle_Move(Turtle *turtle,double distance);
void Turtle_Turn(Turtle *turtle,double angle);
void Turtle_PenDown(Turtle *turtle);
void Turtle_PenUp(Turtle *turtle);
void Turtle_SetPenColor(Turtle *turtle,SDL_Color color);
void Turtle_Clean(Turtle *turtle);
void Turtle_SetX(Turtle *turtle,double x);
void Turtle_SetY(Turtle *turtle,double y);
void Turtle_SetHeading(Turtle *turtle,double heading);
void Turtle_Jump(Turtle *turtle,double x,double y);



#endif /* TURTLE_H */


