#include <SDL2/SDL.h>
#include <stdbool.h>
#include <time.h>


int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect r = { 40,20, 10,10 };
    SDL_Event evt;
    struct square {
        SDL_Rect r;
        int R;
        int G;
        int B;
    };
    struct square squares[10];
    int count = 0;
    bool isQuit = false;

    while (!isQuit) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        for(int i = 0; i <= count; i++){
            SDL_SetRenderDrawColor(ren, squares[i].R,squares[i].G,squares[i].B,0);
            SDL_RenderFillRect(ren, &squares[i].r);
        }
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);
        SDL_WaitEvent(&evt);
        if (evt.type == SDL_KEYDOWN) {
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    if((r.y-5) > -1) {
                        r.y -= 5;
                    }  
                    break;
                case SDLK_DOWN:
                    if((90 - (r.y + 5)) >= 0 ) {
                        r.y += 5;
                    }  
                    break;
                case SDLK_LEFT:
                    if((r.x-5) > -1) {
                        r.x -= 5;
                    }  
                    break;
                case SDLK_RIGHT:
                    if((190 - (r.x+5)) >= 0 ) {
                        r.x += 5;
                    }  
                    break;
            }
        }
        if(evt.type == SDL_WINDOWEVENT) {
            if(evt.window.event == SDL_WINDOWEVENT_CLOSE){
                isQuit = true;
            }
        }
        if(evt.type == SDL_MOUSEBUTTONDOWN) {
            int x = evt.button.x;
            int y = evt.button.y;
            SDL_Rect square = { x,y, 10,10 };
            int randomR = rand()+(int)time(NULL) % 255;
            int randomG = rand()+(int)time(NULL) % 255;
            int randomB = rand()+(int)time(NULL) % 255;
            struct square s;
            s.r = square;
            s.R = randomR;
            s.G = randomG;
            s.B = randomB;
            if(count < 10){
                squares[count] = s;
                count += 1;
            }
        }

        SDL_RenderPresent(ren);
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}