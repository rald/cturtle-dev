#include "turtle.h"



static double deg2rad(double deg) {
    return deg*M_PI/180.0;
}

static double normalizeAngle(double angle) {
    double n=fmod(angle,360.0);
    if(n<0.0) n+=360.0;
    return n;
}



Turtle *Turtle_New(SDL_Renderer *renderer) {
    Turtle *turtle=malloc(sizeof(*turtle));
    if(turtle) {
        turtle->x=SCREEN_WIDTH/2;
        turtle->y=SCREEN_HEIGHT/2;
        turtle->heading=0;
        turtle->isPenDown=true;
        turtle->renderer=renderer;
    }
    return turtle;
}

void Turtle_Free(Turtle *turtle) {
    free(turtle);
}

void Turtle_Move(Turtle *turtle,double distance) {
    double nx=distance*cos(deg2rad(turtle->heading))+turtle->x;
    double ny=distance*sin(deg2rad(turtle->heading))+turtle->y;

    if(turtle->isPenDown) {
        SDL_RenderDrawLine(turtle->renderer,turtle->x,turtle->y,nx,ny);
    }

    turtle->x=nx;
    turtle->y=ny;
}

void Turtle_Turn(Turtle *turtle,double angle) {
    turtle->heading=normalizeAngle(turtle->heading+angle);
}

void Turtle_PenDown(Turtle *turtle) {
    turtle->isPenDown=true;
}

void Turtle_PenUp(Turtle *turtle) {
    turtle->isPenDown=false;
}

void Turtle_SetPenColor(Turtle *turtle,SDL_Color color) {
    SDL_SetRenderDrawColor(turtle->renderer,color.r,color.g,color.b,color.a);
}

void Turtle_Clean(Turtle *turtle) {
    SDL_RenderClear(turtle->renderer);
}

void Turtle_SetX(Turtle *turtle,double x) {
    turtle->x=x;
}

void Turtle_SetY(Turtle *turtle,double y) {
    turtle->y=y;
}

void Turtle_SetHeading(Turtle *turtle,double heading) {
    turtle->heading=heading;
}

void Turtle_Jump(Turtle *turtle,double x,double y) {
    turtle->x=x;
    turtle->y=y;
}


