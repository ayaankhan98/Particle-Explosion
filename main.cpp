#include <iostream>
#include <SDL2/SDL.h>
#include "screen.h"

using namespace std;
using namespace screenComponents;

int main() {
  Screen screen;
  
  if (!screen.initScreen()) {
    cout<<"Error : Unable to init SDL"<<endl;
  }

  while(true) {
    // update screen 
    // create particles
    // trigger events
    // update particle states
    if(!screen.processEvent()) {
      break;
    }
  }

  screen.destroyScreen();
  return 0;
}
