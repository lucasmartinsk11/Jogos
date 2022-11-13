#include <assert.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Contando o Tempo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         800, 600, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    int AUX_WaitEventTimeoutCount (SDL_Event* evt, Uint32* ms, Uint32* esp){
        *esp -= *ms;
        *ms = 0;
        if (*esp < 0) {
            *esp = 0;
        }
        int isevt = SDL_WaitEventTimeout(evt, *esp);
        return isevt;
     }

    /* EXECUÇÃO */
    SDL_Rect r = { 40,20, 10,10 };
    int espera = 500;
    bool isQuit = false;
    int x, y, xTime, yTime;
    int ms = 0;
    SDL_Rect rMouse;
    SDL_Rect rTime = {0, 0, 50, 50};
    clock_t start, end;
    double cpu_time_used;
    while (!isQuit) {
        
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0x00);
        SDL_RenderFillRect(ren, &rTime);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0x00,0x00);
        SDL_RenderFillRect(ren, &rMouse);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);

        SDL_Event evt;
        Uint32 antes = SDL_GetTicks();
        int isevt = AUX_WaitEventTimeoutCount(&evt, &ms, &espera);
        if (isevt) {
            ms = (SDL_GetTicks() - antes);
            if (evt.type == SDL_KEYDOWN) {
                switch (evt.key.keysym.sym) {
                    case SDLK_UP:
                        r.y -= 5;
                        break;
                    case SDLK_DOWN:
                        r.y += 5;
                        break;
                    case SDLK_LEFT:
                        r.x -= 5;
                        break;
                    case SDLK_RIGHT:
                        r.x += 5;
                        break;
                }
            }
        } else if((799 - (xTime+5)) >= 0 && (595 - (yTime + 5)) >= 0) {
            espera = 500;
            rTime.x += 2;
            rTime.y += 2;
        }
        if(evt.type == SDL_MOUSEMOTION)
        {
            SDL_PumpEvents();
            SDL_GetMouseState(&x, &y);
            int x1, y1;
            if(((x-5) > -1) && (799 - (x+5)) >= 0) {
                x1 = x;
            }
            if(((y-5) > -1) && (595 - (y + 5)) >= 0) {
                y1 = y;
            }
            SDL_Rect square = { x1,y1, 10,10 };  
            rMouse = square;
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