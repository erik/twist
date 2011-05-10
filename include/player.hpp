#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics.hpp>
#include "map.hpp"

const float GRAVITY = 1;

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
  float m_x;
  float m_y;
  float m_vel_x;
  float m_vel_y;
  
  sf::Image& m_image;
};

#endif /* _PLAYER_H_ */
