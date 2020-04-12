#include "functions.hpp"

#define PI 3.14159265
#define sqrt2 1.41421356

extern int requestExit;
extern int ree;

extern int length;
extern int halflen;

extern SDL_Renderer * rend;
extern SDL_Window * win;

extern SDL_Event event;

extern SDL_Texture * map;
extern SDL_Texture * grid;
extern int world[500][500];
extern SDL_Rect loc;
extern SDL_Color white;

extern SDL_RendererFlip flip;
extern SDL_Rect * cam;

extern SDL_Rect vp;
