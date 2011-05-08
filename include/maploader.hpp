#pragma once

#ifndef _MAP_LOADER_H_
#define _MAP_LOADER_H_

#include <string>

#include "map.hpp"

namespace MapLoader {
  Map LoadMap(std::string name);
}

#endif /* _MAP_LOADER_H_ */
