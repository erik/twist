#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Box2D/Box2D.h"
#include <SFML/Graphics.hpp>

class World;

const float WORLD_SCALE = 30;

/* Physics entities for use in the world */

class Entity {
public:
  enum Type { Tile,
              Player, 
              Other
  };

  static Entity Box(int width, int height);
  static Entity Circle(double radius);
  
  Entity();
  virtual ~Entity();

  /* creation methods */
  Entity& SetDynamic(bool value);
  Entity& SetPosition(int x, int y);
  Entity& SetBullet(bool val);
  Entity& SetDensity(double den);
  Entity& SetFriction(double fric);
  Entity& SetUserData(Type type, void* data);
  
  Entity& Create(World& w);

  /* accessor methods */
  sf::Vector2<float> GetPosition();
  double GetRotation();
  

private:
  b2Shape* m_shape;
  b2FixtureDef m_fixture_def;
  b2BodyDef m_body_def;
  b2Body* m_body;
  Type m_type;
  void* m_data;
};

#endif /* _ENTITY_H_ */
