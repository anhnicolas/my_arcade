/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2Wrapper
*/

#ifndef SDL2WRAPPER_HPP_
#define SDL2WRAPPER_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_video.h>
#include "Libs.hpp"

class SDL2Wrapper {
    public:
        SDL2Wrapper() = default;
        ~SDL2Wrapper() = default;

        static int SDL_Init(Uint32 flags);
        static void SDL_Quit();
        static SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);
        static SDL_Renderer *SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags);
        static int SDL_PollEvent(SDL_Event *event);
        static void SDL_SetRenderDrawColor(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        static void SDL_RenderClear(SDL_Renderer *renderer);
        static void SDL_RenderPresent(SDL_Renderer *renderer);
        static void SDL_SetWindowMaximumSize(SDL_Window *window, int max_w, int max_h);
        static void SDL_SetWindowMinimumSize(SDL_Window *window, int min_w, int min_h);
        static void SDL_SetWindowSize(SDL_Window *window, int w, int h);
        static void SDL_SetWindowTitle(SDL_Window *window, std::string title);
        static void SDL_SetWindowPosition(SDL_Window *window, int x, int y);
        static void SDL_GetWindowSize(SDL_Window *window, int *w, int *h);
        static void SDL_GetWindowPosition(SDL_Window *window, int *x, int *y);
        static void SDL_ShowWindow(SDL_Window *window);
        static void SDL_HideWindow(SDL_Window *window);
        static void SDL_DestroyRenderer(SDL_Renderer *renderer);
        static void SDL_DestroyWindow(SDL_Window *window);
        static void SDL_RenderFillRect(SDL_Renderer *renderer, SDL_Rect *rect);
        static void SDL_RenderDrawRect(SDL_Renderer *renderer, SDL_Rect *rect);
        static void SDL_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect);
        static void SDL_FreeSurface(SDL_Surface *surface);
};

#endif /* !SDL2WRAPPER_HPP_ */
