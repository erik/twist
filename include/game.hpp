#pragma once

#ifndef _GAME_DISP_H_
#define _GAME_DISP_H_

#include <SFML/Graphics.hpp>

#include "map.hpp"

class Game {
public:
  Game(int width, int height);
  virtual ~Game();
  
  void Draw(sf::Drawable& r);
  void Run();
  
private:
  void CheckInput(float delta);

  Map m_map;
  sf::Image& m_background;
  sf::RenderWindow m_win;
  sf::RenderImage m_image;
  
  double m_scalex;
  double m_scaley; 
  float m_rotation;
};

#endif /* _GAME_DISP_H_ */
