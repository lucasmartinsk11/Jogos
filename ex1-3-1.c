#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Animacao Simples",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         1000, 1000, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect r1 = { 450,450, 50,50 };
    SDL_Rect r2 = { 500,450, 50,50 };
    SDL_Rect r3 = { 450,500, 50,50 };
    SDL_Rect r4 = { 500,500, 50,50 };
    int count = 0;
    while (count < 50) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 255,0,0,0);
        SDL_RenderFillRect(ren, &r1);
        SDL_SetRenderDrawColor(ren, 0,0,255,0);
        SDL_RenderFillRect(ren, &r2);
        SDL_SetRenderDrawColor(ren, 0,255,0,0);
        SDL_RenderFillRect(ren, &r3);
        SDL_SetRenderDrawColor(ren, 0,0,0,0);
        SDL_RenderFillRect(ren, &r4);
        SDL_RenderPresent(ren);
        SDL_Delay(500);
        count += 5;
        r1.x = r1.x-count;
        r1.y = r1.y-count;
        r2.x = r2.x+count;
        r2.y = r2.y-count;
        r3.x = r3.x-count;
        r3.y = r3.y+count;
        r4.x = r4.x+count;
        r4.y = r4.y+count;
    }
    count = 0;
    while (count < 75) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 255,0,0,0);
        SDL_RenderFillRect(ren, &r1);
        SDL_SetRenderDrawColor(ren, 0,0,255,0);
        SDL_RenderFillRect(ren, &r2);
        SDL_SetRenderDrawColor(ren, 0,255,0,0);
        SDL_RenderFillRect(ren, &r3);
        SDL_SetRenderDrawColor(ren, 0,0,0,0);
        SDL_RenderFillRect(ren, &r4);
        SDL_RenderPresent(ren);
        SDL_Delay(500);
        count += 5;
        r1.x = r1.x+count;
        // r1.y = r1.y-count;
        // r2.x = r2.x+count;
        r2.y = r2.y+count;
        // r3.x = r3.x-count;
        r3.y = r3.y-count;
        r4.x = r4.x-count;
        // r4.y = r4.y+count;
    }

    count = 0;
    while (count < 55) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 255,0,0,0);
        SDL_RenderFillRect(ren, &r1);
        SDL_SetRenderDrawColor(ren, 0,0,255,0);
        SDL_RenderFillRect(ren, &r2);
        SDL_SetRenderDrawColor(ren, 0,255,0,0);
        SDL_RenderFillRect(ren, &r3);
        SDL_SetRenderDrawColor(ren, 0,0,0,0);
        SDL_RenderFillRect(ren, &r4);
        SDL_RenderPresent(ren);
        SDL_Delay(500);
        count += 5;
        r1.x = r1.x-count;
        r1.y = r1.y+count;
        r2.x = r2.x-count;
        r2.y = r2.y-count;
        r3.x = r3.x+count;
        r3.y = r3.y+count;
        r4.x = r4.x+count;
        r4.y = r4.y-count;
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}