#include "game.hpp"

#include "resourcemanager.hpp"
#include "maploader.hpp"
#include <sstream>

Game::Game(int width, int height) :
  m_map(MapLoader::LoadMap("resources/maps/test.map")),
  m_background(ResourceManager::GetImage("resources/images/background.png")),
  m_rotation(0.0),
  m_running(false),
  m_frameTime(1),
  m_world(m_map.CreateWorld()),
  m_player(m_map, m_world)
{

  int flags = sf::Style::Close;
  
  m_win.Create(sf::VideoMode(15*64, 15*64, 32), "twist", flags,
               sf::ContextSettings::ContextSettings(24, 8, 8));

  m_image.Create(64 * 15, 64 * 15);
    
  m_win.EnableVerticalSync(true);
  m_win.SetFramerateLimit(120);
}

Game::~Game() {
  m_win.Close();
}

void Game::Run() {
  m_running = true;
  
  while(m_running && m_win.IsOpened()) {

    this->Update();
    this->CheckInput();

    this->DrawBackground();
    this->DrawMap();

    this->Display();
  }
}

void Game::Draw(sf::Drawable& r) {
  m_image.Draw(r);
}

void Game::Update() {
  m_frameTime = m_clock.GetElapsedTime();
  m_clock.Reset();
  
  m_world.SetRotation(m_rotation);
  m_world.Update(m_frameTime);

  m_player.Update(m_frameTime);
}

void Game::CheckInput() {
  const sf::Input& input = m_win.GetInput();
   
  sf::Event Event;
  while (m_win.PollEvent(Event)) {
    if(Event.Type == sf::Event::Closed) {
      m_running = false;
    } 
    if(Event.Type == sf::Event::KeyPressed &&
       Event.Key.Code == sf::Key::Escape) {
      m_running = false;          
    }           
  }

  if(input.IsKeyDown(sf::Key::A)) {
    m_rotation = m_rotation - 60 * m_frameTime;
  } 
  if(input.IsKeyDown(sf::Key::D)) {
    m_rotation = m_rotation + 60 * m_frameTime;
  }  
}

void Game::DrawBackground() {
  m_win.Clear();
  sf::Sprite back(m_background);    
  back.Resize(22 * 64, 22 * 64);
  m_win.Draw(back);
}

void Game::DrawMap() {
  m_image.Clear();
  
  std::stringstream ss;
  ss << "FPS: " << (1 / m_frameTime);
  sf::Text fps(ss.str().c_str(), sf::Font::GetDefaultFont(), 10.f);
  
  m_map.Draw(*this);
  m_player.Draw(m_image);

  m_image.Display();

  sf::Sprite sprite(m_image.GetImage());
  sprite.SetOrigin(64 * 15 / 2, 64 * 15 / 2);
  sprite.SetPosition(64 * 15 / 2, 64 * 15 / 2);
  sprite.Rotate(static_cast<int>(m_rotation));
  
  m_win.Draw(sprite);
  m_win.Draw(fps);
}

void Game::Display() {
  m_win.Display();
}
