#pragma once

#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <SFML/Graphics.hpp>

#include <string>
#include <map>

#include "tiles.hpp"

namespace ResourceManager {
  sf::Image& GetImage(std::string image);
  
  static std::map<std::string, sf::Image> images;
}

#endif /* _RESOURCE_H_ */
