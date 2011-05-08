#include "game.hpp"

#include "resourcemanager.hpp"
#include "maploader.hpp"

Game::Game(int width, int height) :
  m_map(MapLoader::LoadMap("resources/maps/test.map")),
  m_win(sf::VideoMode(15*64, 15*64, 32), "twist"),
  m_background(ResourceManager::GetImage("resources/images/background.png")),
  m_rotation(10)
{

  m_image.Create(64 * 15, 64 * 15);
  
  m_background.Resize(15 * 64, 15 * 64);
  
  m_win.EnableVerticalSync(true);
  m_win.SetFramerateLimit(60);
}

Game::~Game() {
}

void Game::Run() {
  while(m_win.IsOpened()) {
    sf::Event Event;
    while (m_win.PollEvent(Event)) {
      if (Event.Type == sf::Event::Closed)
        m_win.Close();
      }

    m_image.Clear();
    m_win.Draw(m_background);
    
    m_map.Draw(*this);
    
    sf::Sprite sprite(m_image.GetImage());
    sprite.SetOrigin(64 * 15 / 2, 64 * 15 / 2);
    sprite.SetPosition(64 * 15 / 2, 64 * 15 / 2);
    sprite.Rotate(m_rotation++ );
    m_win.Draw(sprite);
    
    m_image.Display();
    m_win.Display();
  }
}

void Game::Draw(sf::Drawable& r) {
  m_image.Draw(r);
}
