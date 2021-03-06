#ifndef UTIL_H_
#define UTIL_H_

#include "particle.h"

namespace particleExplosion{

  class Util {
   public:
     const static long int N_PARTICLES = 8000;
    private:
      Particle *m_pParticles;
      int lastTime;
    public:
      Util();
      ~Util();
      void update(int);
      const Particle * const getParticles() { 
        return m_pParticles; 
      }
  };

}

#endif
