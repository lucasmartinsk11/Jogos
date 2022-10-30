#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Hello World!",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
    SDL_Rect r = { 40,20, 10,50 };
    SDL_RenderFillRect(ren, &r);
    SDL_SetRenderDrawColor(ren, 0xff,0x00,0xFF,0x00);
    SDL_Rect p = { 40,40, 50,5 };
    SDL_RenderFillRect(ren, &p);
    SDL_SetRenderDrawColor(ren, 0xff,0xaa,0xFF,0x00);
    SDL_Rect i = { 60,70, 5,5 };
    SDL_RenderFillRect(ren, &i);
    SDL_RenderPresent(ren);
    SDL_Delay(5000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}



