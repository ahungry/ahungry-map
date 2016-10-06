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
  double scale = .3;
  int x_offset = 0;
  int y_offset = 0;
  int x_offset_increment = 50;
  int y_offset_increment = 50;
  Map ();
  void addLine (MapLine *mapLine);
  uint lineSize ();
  bool isLoaded ();
  double getX1 (int n);
  double getY1 (int n);
  double getX2 (int n);
  double getY2 (int n);
};

Map::Map()
{
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

bool Map::isLoaded ()
{
  return has_loaded_lines;
}

double Map::getX1 (int n)
{
  return scale * (map_lines[n]->point1.x + x_offset);
}

double Map::getY1 (int n)
{
  return scale * (map_lines[n]->point1.y + y_offset);
}

double Map::getX2 (int n)
{
  return scale * (map_lines[n]->point2.x + x_offset);
}

double Map::getY2 (int n)
{
  return scale * (map_lines[n]->point2.y + y_offset);
}

#endif
