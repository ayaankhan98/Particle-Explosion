#include "util.h"
#include "particle.h"

namespace particleExplosion {
  Util::Util(): lastTime(0) {
    m_pParticles = new Particle[N_PARTICLES];
  }

  void Util::update(int elapsed) {
    
    int interval = elapsed - lastTime;
    
    for(int i=0;i<N_PARTICLES;i++) {
      m_pParticles[i].updateParticleState(interval);
    }
    
    lastTime = elapsed;
  }
  Util::~Util() {
    // Util Destructor
    delete [] m_pParticles;
  }
}
