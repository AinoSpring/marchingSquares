//
// Created by ainols on 13.04.23.
//

#include "Application.h"
#include <SDL2/SDL.h>
#include <iostream>

Application::Application(std::string Title, unsigned int Width, unsigned int Height, std::vector<std::vector<float>> Points)
: Title(Title), Width(Width), Height(Height), Window(NULL), Running(true),
Squares(MarchingSquares(Points)) {

    WidthRatio = Width / (2 * Squares.Width);
    HeightRatio = Height / (2 * Squares.Height);

    Squares.Compute();

}

int Application::OnExecute() {

    if(OnInit() == false) {

        return -1;

    }

    SDL_Event Event;

    while(Running) {

        while(SDL_PollEvent(&Event)) {

            OnEvent(&Event);

        }

        OnLoop();
        OnRender();

    }

    OnCleanup();

    return 0;

}

bool Application::OnInit() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    SDL_CreateWindowAndRenderer(Width, Height, 0, &Window, &Renderer);

    if(Window == NULL) {
        return false;
    }

    return true;

}

void Application::OnEvent(SDL_Event *Event) {

    if (Event->type == SDL_QUIT) {

        Running = false;

    }

}

void Application::OnLoop() {



}

void Application::OnRender() {

    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);

    SDL_RenderClear(Renderer);

    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);

    /*for (unsigned int x = 0; x < Squares.Width; x++) {

        for (unsigned int y = 0; y < Squares.Height; y++) {

            if (Squares.Points[x][y] <= 0) {

                continue;

            }

            SDL_RenderDrawPoint(Renderer, 2 * x * WidthRatio, 2 * y * HeightRatio);

        }

    }*/

    for (int connection = 0; connection < Squares.Connections.size(); connection += 2) {

        unsigned int x1 = Squares.Connections[connection][0] * WidthRatio;
        unsigned int y1 = Squares.Connections[connection][1] * HeightRatio;
        unsigned int x2 = Squares.Connections[connection + 1][0] * WidthRatio;
        unsigned int y2 = Squares.Connections[connection + 1][1] * HeightRatio;

        SDL_RenderDrawLine(Renderer, x1, y1, x2, y2);

    }

    SDL_RenderPresent(Renderer);

}

void Application::OnCleanup() {

    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();

}