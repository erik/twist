#include "player.hpp"

#include "resourcemanager.hpp"
#include<iostream>
Player::Player(Map& map) :
  m_map(map),
  m_rotation(0),
  m_vel_x(0),
  m_vel_y(0),
  m_image(ResourceManager::GetImage("resources/images/hero.png"))
{
  sf::Vector2f spawn(map.GetSpawn());

  m_x = spawn.x * TILE_WIDTH + TILE_WIDTH / 2;
  m_y = spawn.y * TILE_HEIGHT + TILE_HEIGHT / 2 - 10; 
}

Player::~Player() {
}

void Player::SetPosition(int x, int y) {
  m_x = x;
  m_y = y;
}

void Player::SetRotation(float rot) {
  m_rotation = rot;
}

void Player::Update(float dt) { 
  double acc_y = GRAVITY * sin((m_rotation + 90)*M_PI/180);
  double acc_x = -GRAVITY * cos((m_rotation + 90)*M_PI/180);

  m_vel_x += acc_x * dt;
  m_vel_y += acc_y * dt;
  m_x += m_vel_x;
  m_y += m_vel_y;
}

void Player::Draw(sf::RenderTarget& r) {
  sf::Sprite sprite(m_image);
  sprite.SetOrigin(m_image.GetWidth() / 2, m_image.GetHeight() / 2);
  sprite.SetPosition(m_x, m_y);
  sprite.SetRotation(m_rotation);
  r.Draw(sprite);
}

