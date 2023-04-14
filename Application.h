//
// Created by ainols on 13.04.23.
//

#ifndef MARCHING_SQUARES_APPLICATION_H
#define MARCHING_SQUARES_APPLICATION_H

#include <SDL2/SDL.h>
#include <string>
#include "MarchingSquares.h"

class Application {
private:
    bool Running;
    std::string Title;
    unsigned int Width;
    unsigned int Height;
    SDL_Window *Window;
    SDL_Renderer *Renderer;
    float WidthRatio;   // screenWidth / 2fieldWidth
    float HeightRatio;  // screenHeight / 2fieldHeight

public:
    Application(std::string Title, unsigned int Width, unsigned int Height, std::vector<std::vector<float>> Points);
    int OnExecute();

public:
    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void OnCleanup();

public:
    MarchingSquares Squares;
};


#endif //MARCHING_SQUARES_APPLICATION_H
