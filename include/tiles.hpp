#pragma once

#ifndef _TILE_H_
#define _TILE_H_

#include <SFML/Graphics.hpp>

class Game;

const int TILE_WIDTH  = 64;
const int TILE_HEIGHT = 64;

typedef enum TileType {
  BLOCK,
  SPIKES,
  COIN,
  SPAWN,
  GOAL,
  EMPTY
} TileType;

class Tile {
public:
  Tile();
  Tile(TileType t, int x=0, int y=0);
  virtual ~Tile();
  
  void Draw(Game& game);
  void Draw(sf::RenderTarget& g);

  TileType GetType() { return m_type; }
  int GetX() { return m_sprite.GetPosition().x; }
  int GetY() { return m_sprite.GetPosition().y; }
  
private:
  int m_x, m_y;
  TileType m_type;
  sf::Sprite m_sprite;
};

#endif /* _TILE_H_ */
