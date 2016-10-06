#include <string>
#include <SDL2/SDL.h>

/**
 * Class for handling parsed map strings in an EQ file format such as:
 *   File format is as such:
 *   L 1186.0742, -2175.0840, 3.1260,  1215.0065, -2174.9312, 3.1260,  150, 0, 200
 *
 */
class MapLine
{
  std::string type;
  SDL_Point point1;
  SDL_Point point2;
  double z1, z2;
  int r, g, b;
public:
  /**
   * Load in a line of values, parse and store as necessary
   */
  MapLine(
          std::string type,
          double x1,
          double y1,
          double z1,
          double x2,
          double y3,
          double z3,
          int r,
          int g,
          int b
          );
};

MapLine::MapLine(
          std::string type,
          double x1,
          double y1,
          double z1,
          double x2,
          double y2,
          double z2,
          int r,
          int g,
          int b
                 )
{
  point1.x = x1;
  point1.y = y1;
  point2.x = x2;
  point2.y = y2;
  this->type = type;
  this->z1 = z1;
  this->z2 = z2;
  this->r = r;
  this->g = g;
  this->b = b;
}
