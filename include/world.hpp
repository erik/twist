#pragma once

#ifndef _WORLD_H_
#define _WORLD_H_

#include "Box2D/Box2D.h"

const float GRAVITY = 10;
const float PHYS_STEP = 1.0 / 100;

/* a class to hold and maintain the physics world */

class World {
public:
  World(b2Vec2 gravity = b2Vec2(0, GRAVITY));
  virtual ~World();
  
  void Update(float dt);

  void SetRotation(float deg);
  void SetGravity(double x, double y);

  b2World& GetWorld();
private:
  b2World m_world;
};

#endif /* _WORLD_H_ */
