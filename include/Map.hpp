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
  bool has_loaded_lines = false;
  std::vector<MapLine*> map_lines;
public:
  std::string lastLoaded;
  double scale = 0.15;
  int xOffset = 0;
  int yOffset = 0;
  int xOffsetIncrement = 300;
  int yOffsetIncrement = 300;
  Map (double scale, int xOffset, int yOffset);
  void addLine (MapLine *mapLine);
  uint lineSize ();
  bool isLoaded ();
  double getX (int n);
  double getY (int n);
  MapLine getLine (int n);
};

Map::Map (double scale, int xOffset, int yOffset)
{
  this->scale = scale;
  this->xOffset = xOffset;
  this->yOffset = yOffset;
  std::cout << " map init " << std::endl;
}

void Map::addLine (MapLine *map_line)
{
  has_loaded_lines = true;
  map_lines.push_back (map_line);
}

uint Map::lineSize ()
{
  return map_lines.size ();
}

MapLine Map::getLine (int n)
{
  return *map_lines[n];
}

bool Map::isLoaded ()
{
  return has_loaded_lines;
}

double Map::getX (int n)
{
  return scale * (n + xOffset);
}

double Map::getY (int n)
{
  return scale * (n + yOffset);
}

#endif
