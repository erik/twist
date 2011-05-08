#include "resourcemanager.hpp"

#include <iostream>

sf::Image& ResourceManager::GetImage(std::string name) {
  std::map<std::string, sf::Image>::iterator iter;
  iter = images.find(name);
    
  /* image not found, insert it */
  if(iter == images.end()) {
    sf::Image im;
    if(!im.LoadFromFile(name)) {
      std::cout << "ERROR: requested image not found: " << name << std::endl;
    } else {
      images[name] = im;
    }
  }
  
  return images[name];  
}
