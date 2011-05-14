#include "entity.hpp"
#include "world.hpp"



Entity Entity::Box(int width, int height) {
  Entity ent;
  b2PolygonShape* body_box = new b2PolygonShape;
  body_box->SetAsBox(width / 2.0 / WORLD_SCALE, height / 2.0 / WORLD_SCALE);

  ent.m_shape = body_box;
  return ent;
}

Entity Entity::Circle(double radius) {
  Entity ent;
  b2CircleShape* circ = new b2CircleShape;
  
  circ->m_radius = radius / WORLD_SCALE;
  
  ent.m_shape = circ;

  return ent;
}

Entity::Entity()
  :
  m_body(NULL),
  m_type(Entity::Other),
  m_data(NULL)
{
  m_fixture_def.density = 1.0;
  m_fixture_def.friction = 1.0;
}

Entity::~Entity() {
}

Entity& Entity::SetDynamic(bool val) {
  m_body_def.type = val ? b2_dynamicBody : b2_staticBody;
  return *this;
}

Entity& Entity::SetPosition(int x, int y) {
  m_body_def.position.Set(x / WORLD_SCALE, y / WORLD_SCALE);
  return *this;
}

Entity& Entity::SetBullet(bool val) {
  m_body_def.bullet = true;
  return *this;
}

Entity& Entity::SetDensity(double density) {
  m_fixture_def.density = density;
  return *this;
}

Entity& Entity::SetFriction(double fric) {
  m_fixture_def.friction = fric;
  return *this;
}

Entity& Entity::SetUserData(Type type, void* data) {
  m_type = type;
  m_data = data;
  m_body_def.userData = data;
  return *this;
}

Entity& Entity::Create(World& w) {
  m_fixture_def.shape = m_shape;

  b2World& world = w.GetWorld();
  m_body = world.CreateBody(&m_body_def);
  m_body->CreateFixture(&m_fixture_def);
  return *this;
}

sf::Vector2<float> Entity::GetPosition() {
  b2Vec2 tmp(m_body->GetPosition());

  sf::Vector2<float> pos;
  pos.x = tmp.x * WORLD_SCALE;
  pos.y = tmp.y * WORLD_SCALE;

  return pos;
}

double Entity::GetRotation() {
  double rads = m_body->GetAngle();

  return rads * (180 / M_PI);
}
