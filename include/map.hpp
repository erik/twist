#pragma once

#ifndef _MAP_H_
#define _MAP_H_

#include <string>

#include "tiles.hpp"

class World;
class Game;

class Map {
public:
  Map(std::string name, int width, int height);
  virtual ~Map();

  void Draw(Game& game);
  void SetTile(int x, int y, Tile& t);

  Tile& GetTile(int x, int y);

  /* create a physics world for the map */
  World CreateWorld();

  int GetWidth() { return m_width; }
  int GetHeight() { return m_height; }

  sf::Vector2f GetSpawn();
  sf::Vector2f GetGoal();

  std::string Name();
  
private:
  sf::Vector2f GetType(TileType t);

  int m_width;
  int m_height;
  std::string m_name;
  Tile *m_map;
};

#endif /* _MAP_H_ */
