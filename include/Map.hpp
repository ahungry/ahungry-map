#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "MapLine.hpp"

/**
 * Class for storing the map lines and handling scaling values for the map we render
 */
class Map
{
  std::vector<MapLine*> mapLines;
public:
  double scale = .3;
  int x_offset = 0;
  int y_offset = 0;
  int x_offset_increment = 50;
  int y_offset_increment = 50;
  Map();
  void addLine(MapLine *mapLine);
};

Map::Map()
{
  std::cout << " map init " << std::endl;
}

void Map::addLine (MapLine *mapLine)
{
  mapLines.push_back (mapLine);
}

#endif
