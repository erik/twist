#pragma once

#ifndef _GAME_DISP_H_
#define _GAME_DISP_H_

#include <SFML/Graphics.hpp>

class GameDisplay {
public:
  GameDisplay(int width, int height);
  virtual ~GameDisplay();
  
  
  
  void Run();
  
private:
  sf::RenderWindow win;
};

#endif /* _GAME_DISP_H_ */
