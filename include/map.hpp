#pragma once

#ifndef _MAP_H_
#define _MAP_H_

#include <string>

#include "tiles.hpp"

class Game;

class Map {
public:
  Map(std::string name, int width, int height);
  virtual ~Map();

  void Draw(Game& game);
  void SetTile(int x, int y, Tile& t);
  std::string Name();
  
private:
  int m_width;
  int m_height;
  std::string m_name;
  Tile *m_map;
};

#endif /* _MAP_H_ */
