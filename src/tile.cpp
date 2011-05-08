#include "tiles.hpp"

#include "resourcemanager.hpp"
#include "game.hpp"

Tile::Tile() :
  m_x(0),
  m_y(0)
{
}

Tile::Tile(TileType t, int x, int y) :
  m_x(x),
  m_y(y),
  m_type(t),
  m_sprite(ResourceManager::GetImage("resources/images/tiles.png"))
{

  
  m_sprite.SetSubRect(sf::IntRect(t * TILE_WIDTH, 0 * TILE_HEIGHT, TILE_WIDTH, 
    TILE_HEIGHT));
  m_sprite.SetPosition(x * TILE_WIDTH, y * TILE_HEIGHT);
}

Tile::~Tile(){
}

void Tile::Draw(Game& g) {
  g.Draw(m_sprite);
}

