#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

#include "map.hpp"

const float WORLD_SCALE = 30;
const float GRAVITY = 10;
const float PHYS_STEP = 1.0 / 100;

class Player;

struct Entity {
  enum Type { TILE, PLAYER };

  Type type;

  union data {
    Tile *t;
    Player* p;
  } data;
};


struct ContactListener : public b2ContactListener {
  ContactListener();
  virtual ~ContactListener();

  void BeginContact(b2Contact* contact) {
    Entity *t1 = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
    Entity *t2 = (Entity*)contact->GetFixtureB()->GetBody()->GetUserData();

    if(t1->type == t2->type) {
      return;
    } else {
      /*
        Player* p = ((t1->type == Entity::PLAYER) ? t1 : t2)->data.p;
        Tile* t   = ((t2->type == Entity::TILE  ) ? t1 : t2)->data.t;
      */
    }
  }
};

class Player {
public:
  Player(Map& map);
  virtual ~Player();

  void SetRotation(float rot);
  void SetPosition(int m_x, int m_y);

  void Update(float dt);

  void Draw(sf::RenderTarget& d);

private:
  Map& m_map;
  float m_rotation;

  sf::Image& m_image;

  b2World m_world;
  b2Body* m_body;
  float m_update;

  b2Body** m_bodies;
};

#endif /* _PLAYER_H_ */
