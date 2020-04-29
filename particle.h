#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleExplosion {
  struct Particle {
      double m_x;
      double m_y;

      double m_xSpeed;
      double m_ySpeed;
    public:
      Particle();
      void updateParticleState();
      ~Particle();
  };
}

#endif
