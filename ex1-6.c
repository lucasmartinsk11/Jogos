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

    int AUX_WaitEventTimeoutCount (SDL_Event* evt, Uint32* ms){
        Uint32 antes = SDL_GetTicks();
        int isevt = SDL_WaitEventTimeout(evt, *ms);
        int passedTime = (SDL_GetTicks() - antes);

        *ms -= passedTime;
        if (*ms < 0) {
            *ms = 0;
        }
        
        return isevt;
     }

    /* EXECUÇÃO */
    struct square {
        SDL_Rect r;
        int ordem;
        bool colidiu;
    };
    SDL_Rect r = { 0,30, 30,30 };
    struct square azul;
    azul.r = r;
    azul.colidiu = false;
    azul.ordem = -1;
    SDL_Rect finishLine = { 780,0, 50,600 };
    int espera = 500;
    int contadoDeOrdem = 0;
    bool isQuit = false;
    int x, y, xTime, yTime;
    int ms = 0;
    SDL_Rect rMouse;
    struct square preto;
    preto.r = rMouse;
    preto.colidiu = false;
    preto.ordem = -1;
    SDL_Rect rTime = {0, 0, 30, 30};
    struct square vermelho;
    vermelho.r = rTime;
    vermelho.colidiu = false;
    vermelho.ordem = -1;
    clock_t start, end;
    double cpu_time_used;
    while (!isQuit) {
        
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0x00);
        SDL_RenderFillRect(ren, &vermelho.r);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0x00,0x00);
        SDL_RenderFillRect(ren, &preto.r);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &azul.r);
        SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
        SDL_RenderFillRect(ren, &finishLine);
        SDL_RenderPresent(ren);

        SDL_Event evt;
        int isevt = AUX_WaitEventTimeoutCount(&evt, &espera);
        if (isevt) {
            if (evt.type == SDL_KEYDOWN) {
                switch (evt.key.keysym.sym) {
                    // case SDLK_UP:
                    //     r.y -= 5;
                    //     break;
                    // case SDLK_DOWN:
                    //     r.y += 5;
                    //     break;
                    // case SDLK_LEFT:
                    //     r.x -= 5;
                    //     break;
                    case SDLK_RIGHT:
                        azul.r.x += 5;
                        break;
                }
            }
        } else if((799 - (xTime+5)) >= 0 && (595 - (yTime + 5)) >= 0) {
            espera = 500;
            vermelho.r.x += 50;
            // rTime.y += 2;
        }
        if(evt.type == SDL_MOUSEMOTION)
        {
            SDL_PumpEvents();
            SDL_GetMouseState(&x, &y);
            int x1, y1;
            if(((x-5) > -1) && (799 - (x+5)) >= 0) {
                x1 = x;
            }
            // if(((y-5) > -1) && (595 - (y + 5)) >= 0) {
            //     y1 = y;
            // }
            SDL_Rect square = { x1,60, 30,30 };  
            preto.r = square;
        }
        if(SDL_HasIntersection (&azul.r, &finishLine) && !azul.colidiu){
            contadoDeOrdem = contadoDeOrdem + 1;
            azul.colidiu = true;
            azul.ordem = contadoDeOrdem;

        }else if (SDL_HasIntersection (&vermelho.r, &finishLine) && !vermelho.colidiu){
            contadoDeOrdem = contadoDeOrdem + 1;
            vermelho.colidiu = true;
            vermelho.ordem = contadoDeOrdem;
        }else if (SDL_HasIntersection (&preto.r, &finishLine) && !preto.colidiu){
            contadoDeOrdem = contadoDeOrdem + 1;
            preto.colidiu = true;
            preto.ordem = contadoDeOrdem;
        }

        if(azul.ordem > 0 && preto.ordem > 0 && vermelho.ordem > 0){
            SDL_Log("Preto %d", preto.ordem);
            SDL_Log("Azul %d", azul.ordem);
            SDL_Log("Vermelho %d", vermelho.ordem);
            if(azul.ordem == 1){
                SDL_Log("Azul Ganhou");
            }else if(preto.ordem == 1){
                SDL_Log("Preto ganhou");
            }else {
                SDL_Log("Vermelho ganhou");
            }
            azul.r = r;
            azul.ordem = -1;
            azul.colidiu = false;
            vermelho.r = rTime;
            vermelho.ordem = -1;
            vermelho.colidiu =  false;
            preto.r = rMouse;
            preto.ordem = -1;
            preto.colidiu = false;
            contadoDeOrdem = 0;


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