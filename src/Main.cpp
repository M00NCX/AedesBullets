#include <SDL.h>
#include "SDL_opengl.h"
#include "SDL_video.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

  SDL_Init(SDL_INIT_EVERYTHING);
  
  //memoria
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 32);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  printf("\n Executando \n");

  SDL_Delay(5000);

  SDL_Quit();
  
  return 0;
}