#include "player.hpp"

#include "resourcemanager.hpp"
#include<iostream>
Player::Player(Map& map) :
  m_map(map),
  m_rotation(0),
  m_image(ResourceManager::GetImage("resources/images/hero.png")),
  m_world(b2Vec2(0.0, GRAVITY), false),
  m_update(PHYS_STEP)
{
  sf::Vector2f spawn(map.GetSpawn());

  float x = (spawn.x * TILE_WIDTH + m_image.GetWidth() / 2) / WORLD_SCALE;
  float y = (spawn.y * TILE_HEIGHT + m_image.GetHeight() / 2) / WORLD_SCALE;

  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(x, y);
  m_body = m_world.CreateBody(&bodyDef);
  b2CircleShape circ;
  circ.m_radius = (m_image.GetWidth() / 2.0 / WORLD_SCALE);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &circ;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 1;
  m_body->CreateFixture(&fixtureDef);
 
  for(int x = 0; x < map.GetWidth(); ++x) {
    for(int y = 0; y < map.GetHeight(); ++y) {
      Tile& t = map.GetTile(x, y);
      if(t.GetType() != BLOCK) {
        continue;
      }

      float posx = (t.GetX() + TILE_WIDTH / 2.0)  / WORLD_SCALE;
      float posy = (t.GetY() + TILE_HEIGHT / 2.0) / WORLD_SCALE;

      Entity* ent = new Entity;
      ent->type = Entity::TILE;
      ent->data.t = &t;

      b2BodyDef bodyDef;
      bodyDef.userData = ent;
      bodyDef.bullet = true;
      bodyDef.position.Set(posx, posy);
      b2Body* b = m_world.CreateBody(&bodyDef);
      b2PolygonShape bodbox;
      bodbox.SetAsBox(TILE_WIDTH / 2.0 / WORLD_SCALE, TILE_HEIGHT / 2.0 / WORLD_SCALE);
      b2FixtureDef fixDef;
      fixDef.shape = &bodbox;
      fixDef.density = 0;
      fixDef.friction = .3f;
      
      b->CreateFixture(&fixDef);
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

  m_world.SetGravity(b2Vec2(acc_x, acc_y));
  
  m_rotation = rot;
}

void Player::Update(float dt) {
  m_update -= dt;
  if(m_update <= 0) {
    m_update = PHYS_STEP;
    m_world.Step(PHYS_STEP, 6, 6);
    m_world.ClearForces();
  }
}

void Player::Draw(sf::RenderTarget& r) {
  sf::Sprite sprite(m_image);
  sprite.SetOrigin(m_image.GetWidth() / 2, m_image.GetHeight() / 2);
  
  b2Vec2 position = m_body->GetPosition();

  sf::Vector2<float> pos;
  pos.x = position.x * WORLD_SCALE;
  pos.y = position.y * WORLD_SCALE; 

  sprite.SetPosition(pos.x, pos.y);
  sprite.SetRotation(m_body->GetAngle() * (180 / M_PI));
  r.Draw(sprite);
}

