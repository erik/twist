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

Tile& Map::GetTile(int x, int y) {
  return m_map[x * m_height + y];
}

sf::Vector2f Map::GetType(TileType t) {
  for(int x = 0; x < m_width; ++x) {
    for(int y = 0; y < m_height; ++y) {
      Tile& tile = m_map[x * m_height + y];
      if(tile.GetType() == t) {
        return sf::Vector2f(x, y);
      }
    }
  }
  return sf::Vector2f(-1, -1);
}

World Map::CreateWorld() {
  World world;
  
  for(int x = 0; x < this->GetWidth(); ++x) {
    for(int y = 0; y < this->GetHeight(); ++y) {
      Tile& t = this->GetTile(x, y);
      if(t.GetType() != BLOCK) {
        continue;
      }
      
      float posx = (t.GetX() + TILE_WIDTH / 2.0);
      float posy = (t.GetY() + TILE_HEIGHT / 2.0);
      
      Entity::Box(TILE_WIDTH, TILE_HEIGHT)
        .SetDynamic(false)
        .SetPosition(posx, posy)
        .SetDensity(0)
        .SetFriction(.3)
        .Create(world);
    }
  }

  return world;

}

sf::Vector2f Map::GetSpawn() {
  return this->GetType(SPAWN);
}

sf::Vector2f Map::GetGoal() {
  return this->GetType(GOAL);
}

void Map::Draw(Game& game) {
  for(int i = 0; i < m_width * m_height; ++i) {
    m_map[i].Draw(game);
  }
}
