#include <SDL2/SDL.h>
#include <stdbool.h>
#include <assert.h>

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
    SDL_Event evt;
    bool isQuit = false;
    int count = 0;

    while (!isQuit) {
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
        SDL_WaitEvent(&evt);
        if (evt.type == SDL_KEYDOWN) {
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    r1.y -= 5;
                    r2.y -= 5;
                    r3.y += 5;
                    r4.y += 5;
                    break;
                case SDLK_DOWN:
                    r1.y += 5;
                    r2.y += 5;
                    r3.y -= 5;
                    r4.y -= 5; 
                    break;
                case SDLK_LEFT:
                    r1.x += 5;
                    r2.x -= 5;
                    r3.x += 5;
                    r4.x -= 5;
                    break;
                case SDLK_RIGHT:
                    r1.x -= 5;
                    r2.x += 5;
                    r3.x -= 5;
                    r4.x += 5;
                    break;
            }
        }
        if(evt.type == SDL_WINDOWEVENT) {
            if(evt.window.event == SDL_WINDOWEVENT_CLOSE){
                isQuit = true;
            }
        }
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}