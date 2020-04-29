#include <iostream>
#include <SDL2/SDL.h>
#include <time.h>
#include <math.h>

#include "screen.h"
#include "util.h"
#include "particle.h"

using namespace std;
using namespace particleExplosion;
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

  Util util;

  while(true) {
    // update screen 
    // create particles
    // trigger events
    // update particle state

    int elapsed = SDL_GetTicks();
    util.update(elapsed);
    // cout<<elapsed<<"\n";
    //     screen.clearScreen();
    unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
    unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
    unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

    const Particle * const pParticles = util.getParticles();


    for(int i = 0 ;i<Util::N_PARTICLES;i++) {
      Particle particle = pParticles[i];

      int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
      int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

      screen.setPixel(x,y,red,green,blue);
    }

    screen.boxBlur();

    screen.updateScreen();

    if(!screen.processEvent()) {
      break;
    }
  }

  screen.destroyScreen();
  return 0;
}
