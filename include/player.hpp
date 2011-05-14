#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

#include "map.hpp"
#include "entity.hpp"
#include "world.hpp"

class Player {
public:
  Player(Map& map, World& w);
  virtual ~Player();

  void Update(float dt);

  void Draw(sf::RenderTarget& d);

private:
  Map& m_map;
  float m_rotation;

  sf::Image& m_image;

  World& m_world;
  Entity m_entity;

  float m_update;
};

#endif /* _PLAYER_H_ */
