#pragma once

#ifndef _GAME_DISP_H_
#define _GAME_DISP_H_

#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "player.hpp"

class Game {
public:
  Game(int width, int height);
  virtual ~Game();
  
  void Draw(sf::Drawable& r);
  void Run();
  
private:
  void Update();
  void CheckInput();
  void DrawMap();
  void DrawBackground();
  void Display();

  Map m_map;
  sf::Image& m_background;
  sf::RenderWindow m_win;
  sf::RenderImage m_image;
  
  double m_scalex;
  double m_scaley; 
  double m_rotation;

  bool m_running;
  float m_frameTime;

  sf::Clock m_clock;
  Player m_player;
};

#endif /* _GAME_DISP_H_ */
