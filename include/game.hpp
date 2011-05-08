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
  double m_scalex;
  double m_scaley; 
  Map m_map;
  sf::RenderWindow m_win;
  sf::Sprite m_background;
  sf::RenderImage m_image;
  int m_rotation; 
};

#endif /* _GAME_DISP_H_ */
