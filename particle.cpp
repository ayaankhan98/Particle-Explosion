#include "particle.h"
#include <stdlib.h>
#include <math.h>

namespace particleExplosion {

  Particle::Particle():m_x(0),m_y(0) {
    reInitParticle();
  }

  void Particle::reInitParticle() {
    m_x = 0;
    m_y = 0;
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.4 * rand())/RAND_MAX;

    m_speed *= m_speed;
  }

  void Particle::updateParticleState(int interval) {
    m_direction += interval*0.0004;
    double xSpeed = m_speed * cos(m_direction);
    double ySpeed = m_speed * sin(m_direction);

    m_x += xSpeed * interval;
    m_y += ySpeed * interval;

    if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1 ) {
      reInitParticle();
    }
  }

  Particle::~Particle() {
  }

}
