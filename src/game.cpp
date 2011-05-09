#include "game.hpp"

#include "resourcemanager.hpp"
#include "maploader.hpp"

Game::Game(int width, int height) :
  m_map(MapLoader::LoadMap("resources/maps/test.map")),
  m_background(ResourceManager::GetImage("resources/images/background.png")),
  m_rotation(0.0)
{

  int flags = sf::Style::Resize | sf::Style::Close;
  
  m_win.Create(sf::VideoMode(15*64, 15*64, 32), "twist", flags,
    sf::ContextSettings::ContextSettings(24, 8, 8));

  m_image.Create(64 * 15, 64 * 15);
    
  m_win.EnableVerticalSync(true);
  m_win.SetFramerateLimit(60);
}

Game::~Game() {
}

void Game::Run() {
  bool running(true);
  
  float frameTime = 0;
  sf::Clock clock;

  while(running && m_win.IsOpened()) {
    frameTime = clock.GetElapsedTime();
    clock.Reset();
    
    sf::Event Event;
    while (m_win.PollEvent(Event)) {
      if(Event.Type == sf::Event::Closed) {
        running = false;
      } 
      if(Event.Type == sf::Event::KeyPressed &&
        Event.Key.Code == sf::Key::Escape) {
          running = false;          
      }           
    }
    
    this->CheckInput(frameTime);
    
    m_win.Clear();
    
    sf::Sprite back(m_background);
    
    back.Resize(22 * 64, 22 * 64);
    
    back.SetOrigin(m_background.GetWidth() / 2, m_background.GetHeight() / 2);
    back.SetPosition((15 * 64) / 2, (15 * 64) / 2);
        
    back.Rotate(static_cast<int>(m_rotation));
    m_win.Draw(back);
    
    m_map.Draw(*this);
    
    sf::Sprite sprite(m_image.GetImage());
    sprite.SetOrigin(64 * 15 / 2, 64 * 15 / 2);
    sprite.SetPosition(64 * 15 / 2, 64 * 15 / 2);
    sprite.Rotate(static_cast<int>(m_rotation));
    
    m_win.Draw(sprite);
    
    m_image.Display();
    m_win.Display();
  }
}

void Game::Draw(sf::Drawable& r) {
  m_image.Draw(r);
}

void Game::CheckInput(float dt) {
  const sf::Input& input = m_win.GetInput();
  
  if(input.IsKeyDown(sf::Key::Left)) {
    m_rotation = m_rotation - 40 * dt;
  } 
  if(input.IsKeyDown(sf::Key::Right)) {
    m_rotation = m_rotation + 40 * dt;
  }
  
}
