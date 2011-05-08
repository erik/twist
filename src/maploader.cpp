#include "maploader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

#include "tiles.hpp"

Map MapLoader::LoadMap(std::string name) {
  std::ifstream file(name.c_str());
  
  std::vector<std::string> content;
  
  while (file) {
    std::string s;
    if(!getline(file, s)) {
      break;
    }

    std::istringstream stream(s);

    while(stream) {
      std::string val;
      if(!getline(stream, val, ',' )) {
        break;
      }
      content.push_back(val);
    }
  }
    
  int width = atoi(content[0].c_str());
  int height = atoi(content[1].c_str());
  std::string n = content[2];
  
  content.erase(content.begin(), content.begin() + 3);
  
  Map m(n, width, height);
  
  for(int x = 0; x < width; ++x) {
    for(int y = 0; y < height; ++y) {
      TileType t = static_cast<TileType>(atoi(content[y * width + x].c_str()));
      Tile tile(t, x, y);
      m.SetTile(x, y, tile);
    }
  }

  return m;
}
