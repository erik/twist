#include "map.hpp"

#include "game.hpp"

#include <iostream>

Map::Map(std::string name, int width, int height) :
  m_width(width),
  m_height(height),
  m_name(name)
{
  m_map = new Tile[width * height];
}

Map::~Map() {
  delete[] m_map;
}

void Map::SetTile(int x, int y, Tile& t) {
  int pos = x * m_height + y;
  if(pos >= m_width * m_height) {
    std::cout << "WARNING: position is greater than size, ignoring" << std::endl;
  } else {
    m_map[pos] = t;
  }
}

void Map::Draw(Game& game) {
  for(int i = 0; i < m_width * m_height; ++i) {
    m_map[i].Draw(game);
  }
}
