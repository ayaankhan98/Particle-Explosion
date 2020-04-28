#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace screenComponents {

  class Screen {
    public:
      const static int SCREEN_WIDTH = 800;
      const static int SCREEN_HEIGHT = 600;
    private:
      SDL_Window *m_window;
      SDL_Renderer *m_renderer;
      SDL_Texture *m_texture;
      Uint32 *m_buffer;
    public:
      Screen();
      bool initScreen();
      void updateScreen();
      void setPixel(int,int,Uint32,Uint32,Uint32);
      bool processEvent();
      void destroyScreen();
  };
};

#endif
