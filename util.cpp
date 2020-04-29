#include "util.h"
#include "particle.h"

namespace particleExplosion {
  Util::Util() {
    m_pParticles = new Particle[N_PARTICLES];
  }

  void Util::update() {
    for(int i=0;i<N_PARTICLES;i++) {
      m_pParticles[i].updateParticleState();
    }
  }
  Util::~Util() {
    // Util Destructor
    delete [] m_pParticles;
  }
}
