#include "player.hpp"

#include "resourcemanager.hpp"
#include "world.hpp"
#include<iostream>

Player::Player(Map& map) :
  m_map(map),
  m_rotation(0),
  m_image(ResourceManager::GetImage("resources/images/hero.png")),
  m_update(PHYS_STEP)
{
  sf::Vector2f spawn(map.GetSpawn());

  float x = (spawn.x * TILE_WIDTH + m_image.GetWidth() / 2);
  float y = (spawn.y * TILE_HEIGHT + m_image.GetHeight() / 2);

  m_entity = Entity::Circle(m_image.GetWidth() / 2.0)
    .SetDynamic(true)
    .SetPosition(x, y)
    .SetDensity(1.0)
    .SetFriction(1)
    .SetUserData(Entity::Player, static_cast<void*>(this)).
    Create(m_world);
 
  for(int x = 0; x < map.GetWidth(); ++x) {
    for(int y = 0; y < map.GetHeight(); ++y) {
      Tile& t = map.GetTile(x, y);
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
        .Create(m_world);
    }
  }

}

Player::~Player() {
}

void Player::SetPosition(int x, int y) {
  /* nothing to see here */
}

void Player::SetRotation(float rot) {
  double acc_y = GRAVITY * sin((m_rotation + 90)*M_PI/180);
  double acc_x = -GRAVITY * cos((m_rotation + 90)*M_PI/180);

  m_world.SetGravity(acc_x, acc_y);
  
  m_rotation = rot;
}

void Player::Update(float dt) {
  m_update -= dt;
  if(m_update <= 0) {
    m_update = PHYS_STEP;
    m_world.Update(PHYS_STEP);
  }
}

void Player::Draw(sf::RenderTarget& r) {
  sf::Sprite sprite(m_image);

  sprite.SetOrigin(m_image.GetWidth() / 2, m_image.GetHeight() / 2);  
  sprite.SetPosition(m_entity.GetPosition());
  sprite.SetRotation(m_entity.GetRotation());

  r.Draw(sprite);
}

