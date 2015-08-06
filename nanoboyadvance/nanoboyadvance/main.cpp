/*
* Copyright (C) 2015 Frederic Meyer
*
* This file is part of nanoboyadvance.
*
* nanoboyadvance is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* nanoboyadvance is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with nanoboyadvance. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include "core/arm7.h"
#include "common/log.h"
#undef main

using namespace std;
using namespace NanoboyAdvance;

SDL_Surface* screen;
uint32_t* buffer;

int main(int argc, char **argv)
{
    SDL_Event event;
    PagedMemory memory;
    ARM7* arm = new ARM7(&memory);
    bool running = true;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }
    
    screen = SDL_SetVideoMode(240, 160, 32, SDL_SWSURFACE);
    if (screen == NULL)
    {
        printf("SDL_SetVideoMode Error: %s\n", SDL_GetError());
        SDL_Quit();
    }
    buffer = (uint32_t*)screen->pixels;
    
    SDL_WM_SetCaption("NanoBoyAdvance", "NanoBoyAdvance");
    
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
    }

    SDL_FreeSurface(screen);
    return 0;
}