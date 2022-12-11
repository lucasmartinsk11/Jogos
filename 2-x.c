#include <assert.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

struct square {
        SDL_Rect r;
        bool isDragging;
        SDL_Point origPos;
        bool didDrag;
        
};

SDL_Rect costructReact (int x, int y, int length, int width){
    SDL_Rect rect = {x, y, length, width};
    return rect;
}

void eventListeners (SDL_Event* evt, struct square* sqr){
    SDL_Point mousePosition;
    switch(evt->type){
        case(SDL_MOUSEBUTTONDOWN):
            SDL_PumpEvents();
            SDL_Rect r = sqr->r;  
            SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
            if(SDL_PointInRect (&mousePosition, &r)){
                sqr->origPos.x = sqr->r.x;
                sqr->origPos.y = sqr->r.y;
                sqr->isDragging = true;
                sqr->didDrag = false;
            };
            break;
        case(SDL_MOUSEMOTION):
            SDL_PumpEvents();
            SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
            if(sqr->isDragging){
                sqr->r.x = mousePosition.x;
                sqr->r.y = mousePosition.y;
                sqr->didDrag = true;
                SDL_Log("dragging...!");
            }
            break;
        case(SDL_MOUSEBUTTONUP):
            sqr->isDragging = false;
            if(sqr->didDrag){
                SDL_Log("Dropped!");
            }else {
                SDL_Log("Clicked!");
            }
        case(SDL_KEYDOWN):
            if(evt->key.keysym.sym == SDLK_ESCAPE){
               sqr->isDragging = false;
               sqr->r.x =  sqr->origPos.x;
               sqr->r.y = sqr->origPos.y;
               SDL_Log("Cancelled!");
            }

        default:
            break;
    }
}

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

    /* EXECUÇÃO */
    
    struct square sqr;
    sqr.r = costructReact(400,300,50,50);
    sqr.didDrag = false;
    sqr.isDragging = false;
    
    bool isQuit = false;
    while (!isQuit) {
        
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &sqr.r);
        SDL_RenderPresent(ren);

        SDL_Event evt;
        SDL_WaitEvent(&evt);
        eventListeners(&evt, &sqr);

    
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