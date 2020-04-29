#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleExplosion {
  struct Particle {
      double m_x;
      double m_y;

      double m_speed;
      double m_direction;
//      double m_xSpeed;
//      double m_ySpeed;
    public:
      Particle();
      void reInitParticle();
      void updateParticleState(int);
      ~Particle();
  };
}

#endif
