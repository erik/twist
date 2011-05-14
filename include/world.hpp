#pragma once

#ifndef _WORLD_H_
#define _WORLD_H_

#include "Box2D/Box2D.h"

const float GRAVITY = 10;
const float PHYS_STEP = 1.0 / 100;

/* a class to hold and maintain the physics world */

class World {
public:
  World(b2Vec2 gravity = b2Vec2(0, GRAVITY)) : m_world(gravity, false) {}

  void Update(float dt) { m_world.Step(PHYS_STEP, 6, 6); m_world.ClearForces();};
  void SetRotation(float deg) {   
    double acc_y = GRAVITY * sin((deg + 90)*M_PI/180);
    double acc_x = -GRAVITY * cos((deg + 90)*M_PI/180);
    
    m_world.SetGravity(b2Vec2(acc_x, acc_y));
  }
  void SetGravity(double x, double y) { m_world.SetGravity(b2Vec2(x, y)); }

  b2World& GetWorld() { return m_world; }
private:
  b2World m_world;
};

#endif /* _WORLD_H_ */
