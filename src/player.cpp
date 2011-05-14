#include "player.hpp"

#include "resourcemanager.hpp"
#include "world.hpp"
#include<iostream>

Player::Player(Map& map, World& w) :
  m_map(map),
  m_rotation(0),
  m_image(ResourceManager::GetImage("resources/images/hero.png")),
  m_world(w),
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
}

Player::~Player() {
}

void Player::Update(float dt) {
}

void Player::Draw(sf::RenderTarget& r) {
  sf::Sprite sprite(m_image);

  sprite.SetOrigin(m_image.GetWidth() / 2, m_image.GetHeight() / 2);  
  sprite.SetPosition(m_entity.GetPosition());
  sprite.SetRotation(m_entity.GetRotation());

  r.Draw(sprite);
}

