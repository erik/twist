#include "world.hpp"

World::World(b2Vec2 grav)
  : m_world(grav, false)
{
}

World::~World()
{
}

void World::Update(float dt) {
  m_world.Step(PHYS_STEP, 6, 6);
  m_world.ClearForces();
}

void World::SetRotation(float deg) {
  double acc_y = GRAVITY * sin((deg + 90)*M_PI/180);
  double acc_x = -GRAVITY * cos((deg + 90)*M_PI/180);
  
  this->SetGravity(acc_x, acc_y);
}

void World::SetGravity(double x, double y) {
  m_world.SetGravity(b2Vec2(x, y));
}

b2World& World::GetWorld() {
  return m_world;
}
