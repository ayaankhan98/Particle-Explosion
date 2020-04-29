#include "particle.h"
#include <stdlib.h>
#include <math.h>

namespace particleExplosion {

  Particle::Particle():m_x(0),m_y(0) {
    //   m_x = ((2.0 * rand())/RAND_MAX) - 1;
    //   m_y = ((2.0 * rand())/RAND_MAX) - 1;  
    //  m_xSpeed = 0.01 * (((2.0 * rand())/RAND_MAX) - 1) ;
    //  m_ySpeed = 0.01 * (((2.0 * rand())/RAND_MAX) - 1) ;
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
    /*  m_x += m_xSpeed;
        m_y += m_ySpeed;

        if (m_x <= -1.0 || m_x >= 1.0)
        {
        m_xSpeed = -m_xSpeed;
        }

        if (m_y <= -1.0 || m_y >= 1.0)
        {
        m_ySpeed = -m_ySpeed;
        }
        */
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
    // Particle Destructor
  }

}
