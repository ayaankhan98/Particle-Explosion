#include <iostream>
#include <SDL2/SDL.h>
#include "screen.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
using namespace screenComponents;

//#define startx 800/4
//#define endx 3*800/4
//#define starty 600/4
//#define endy 3*600/4
//#define colorstart 0
//#define colorend 255

int main() {
  srand(time(0));
  Screen screen;

  if (!screen.initScreen()) {
    cout<<"Error : Unable to init SDL"<<endl;
  }

  while(true) {
    // update screen 
    // create particles
    // trigger events
    // update particle states


    //  int x = (rand() % (startx - endx + 1)) + endx;
    //  int y = (rand() % (starty - endy + 1)) + endy;
    //  Uint32 red = (rand() % (colorstart - colorend + 1)) + colorend;
    //  Uint32 green = (rand() % (colorstart - colorend + 1)) + colorend;
    //  Uint32 blue = (rand() % (colorstart - colorend + 1)) + colorend;

    //  screen.setPixel(x,y,red,green,blue);

    int elapsed = SDL_GetTicks();
    unsigned char red = (unsigned char)(1 + sin(elapsed * 0.0001) * 128); 
    unsigned char green = (unsigned char)(1 + sin(elapsed * 0.0002) * 128);
    unsigned char blue = (unsigned char)(1 + cos(elapsed * 0.0003) * 128);
    for(int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
      for(int x = 0; x < Screen::SCREEN_WIDTH; x++) {
        screen.setPixel(x,y,red,green,blue);
      }
    }

    //screen.setPixel(400,300,255,255,255);

    screen.updateScreen();

    if(!screen.processEvent()) {
      break;
    }
  }

  screen.destroyScreen();
  return 0;
}
