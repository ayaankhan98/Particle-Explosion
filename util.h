#ifndef UTIL_H_
#define UTIL_H_

#include "particle.h"

namespace particleExplosion{

  class Util {
   public:
     const static int N_PARTICLES = 10000;
    private:
      Particle *m_pParticles;
    public:
      Util();
      ~Util();
      void update();
      const Particle * const getParticles() { 
        return m_pParticles; 
      }
  };

}

#endif
