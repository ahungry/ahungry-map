#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <SDL2/SDL.h>

#include "res_path.h"
#include "cleanup.h"
#include "Map.hpp"
#include "MapLine.hpp"

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 640;
Map MAP;// = new Map();

/**
 * Log an SDL error with some error message to the output stream of our choie
 *
 * @param os The output stream to write the message to
 * @param msg The error message to write, format will be msg error: SDL_GetError ()
 */
void logSDLError(std::ostream &os, const std::string &msg)
{
  os << msg << " error: " << SDL_GetError () << std::endl;
}

/**
 * Loads a BMP image into a texture on the rendering device
 *
 * @param file The BMP image file to load
 * @param ren The renderer to load the texture onto
 * @return The loaded texture, or nullptr if something went wrong
 */
SDL_Texture* loadTexture (const std::string &file, SDL_Renderer *ren)
{
  // Init to nullptr to avoid dangling pointer issues
  SDL_Texture *texture = nullptr;

  // Load image
  SDL_Surface *loadedImage = SDL_LoadBMP (file.c_str ());

  // If the loading went ok, convert to texture and return the texture
  if (loadedImage != nullptr)
    {
      texture = SDL_CreateTextureFromSurface (ren, loadedImage);
      SDL_FreeSurface (loadedImage);

      // Make sure converting went ok too
      if (texture == nullptr)
        {
          logSDLError (std::cout, "CreateTextureFromSurface");
        }
    }
  else
    {
      logSDLError (std::cout, "LoadBMP");
    }

  return texture;
}

/**
 * Draw an SDL_Texture to an SDL_Renderer at position x,y, preserving the width/height
 *
 * @param tex The source texture we want to draw
 * @param ren The renderer we want to draw to
 * @param x The x coordinate to draw to
 * @param y The y coordinate to draw to
 */
void renderTexture (SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
  // Setup the destination rectangle to be at the position we want
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;

  // Query the texture to get its width and height to use
  SDL_QueryTexture (tex, NULL, NULL, &dst.w, &dst.h);
  SDL_RenderCopy (ren, tex, NULL, &dst);

  // Draw some lines on it
  SDL_SetRenderDrawColor (ren, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderDrawLine (ren, 0, 0, 50, 50);
}

/**
 * Read the current map file, and load up the points
 *
 * @return The generated map points
 */
void setMapSingletons ()
{
  // Read file, loop over lines and draw each
  // @todo Error handle if map file does not exist
  const std::string mapFile = getResourcePath ("maps") + "tox.txt";
  std::cout << "Attempt to open: " << mapFile << std::endl;
  std::ifstream infile(mapFile);
  std::string line;

  while (std::getline (infile, line))
    {
      std::istringstream iss (line);
      std::string t, x1, x2, y1, y2, z1, z2, r, g, b, a, zone;

      // File format is as such:
      // L 1186.0742, -2175.0840, 3.1260,  1215.0065, -2174.9312, 3.1260,  150, 0, 200
      if (!(iss >> t >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> r >> g >> b))
        {
          // Attempt to reparse line, accounting for P format
          std::istringstream iss (line);

          if (!(iss >> t >> x1 >> y1 >> z1 >> r >> g >> b >> a >> zone))
            {
              break;
            }
        }

      // @todo Set these lines up as custom structs/classes so all values are easily parseable
      // Right trim comma/whitespace
      x1.erase (x1.find_last_not_of(" ,") + 1);
      y1.erase (y1.find_last_not_of(" ,") + 1);
      x2.erase (x2.find_last_not_of(" ,") + 1);
      y2.erase (y2.find_last_not_of(" ,") + 1);

      // Load up a new MapLine instance after converting all the line values
      // Barf, need a way to dynamically apply same function set to all values (missing lisp!)
      MapLine *mapLine = new MapLine (
                                      t,
                                      atof(x1.c_str ()),
                                      atof(y1.c_str ()),
                                      atof(z1.c_str ()),
                                      atof(x2.c_str ()),
                                      atof(y2.c_str ()),
                                      atof(z2.c_str ()),
                                      atoi(r.c_str ()),
                                      atoi(g.c_str ()),
                                      atoi(b.c_str ()),
                                      atoi(a.c_str ()),
                                      zone
                                      );
      MAP.addLine (mapLine);
    }
}

/**
 * Draw the map points, use the singleton, or set it, if it is not yet.
 */
void renderMapPoints (SDL_Renderer *ren)
{
  if (! MAP.isLoaded ())
    {
      setMapSingletons ();
    }

  // Paint background
  SDL_SetRenderDrawColor (ren, 0x00, 0x00, 0x00, 0x00);
  SDL_Rect rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
  SDL_RenderFillRect (ren, &rect);

  SDL_SetRenderDrawColor (ren, 0xFF, 0xFF, 0xFF, 0xFF);

  double x1, y1, x2, y2;
  for (uint i = 0; i < MAP.lineSize (); i++)
    {
      MapLine ml = MAP.getLine (i);

      // Dynamically set color per line via the map's request
      SDL_SetRenderDrawColor (ren, ml.r, ml.g, ml.b, 0xFF);

      x1 = MAP.getX (ml.point1.x);
      y1 = MAP.getY (ml.point1.y);
      x2 = MAP.getX (ml.point2.x);
      y2 = MAP.getY (ml.point2.y);

      if (ml.type == "L") {
        SDL_RenderDrawLine (ren, x1, y1, x2, y2);
      } else {
        std::cout << "L TYPE: " << ml.type << std::endl;
        SDL_Rect rect = { (int) x1, (int) y1, 10, 10 };
        SDL_RenderFillRect (ren, &rect);
      }
    }
  //SDL_RenderDrawLines (ren, singletonMapPoint, singletonMapPointSize);
}

/*
 * Lesson 1: Hello world
 */
int main (int, char**)
{
  if (SDL_Init (SDL_INIT_EVERYTHING) != 0)
    {
      logSDLError (std::cout, "SDL_Init");
      return 1;
    }

  SDL_Window *win = SDL_CreateWindow ("Lesson 2", 100, 100,
                                      SCREEN_WIDTH,
                                      SCREEN_HEIGHT,
                                      SDL_WINDOW_SHOWN);

  if (win == nullptr)
    {
      logSDLError (std::cout, "CreateWindow");
      SDL_Quit ();
      return 1;
    }

  // -1 means, give us the first renderer that meets the requirements
  SDL_Renderer *ren = SDL_CreateRenderer (win, -1,
                                          SDL_RENDERER_ACCELERATED |
                                          SDL_RENDERER_PRESENTVSYNC);

  if (ren == nullptr)
    {
      logSDLError (std::cout, "SDL_CreateRenderer");
      cleanup (win);
      SDL_Quit ();
      return 1;
    }

  // @todo Uncomment the texture loading below, when ready to load images
  //const std::string resPath = getResourcePath ("img");
  //SDL_Texture *background = loadTexture (resPath + "background.bmp", ren);
  //SDL_Texture *image = loadTexture (resPath + "image.bmp", ren);

  // if (background == nullptr || image == nullptr)
  //   {
  //     cleanup (background, image, ren, win);
  //     SDL_Quit ();
  //     return 1;
  //   }

  // SDL_RenderClear (ren);

  // int bW, bH;
  // SDL_QueryTexture (background, NULL, NULL, &bW, &bH);

  // // Tile across screen
  // for (int ix = 0; ix < SCREEN_WIDTH; ix += bW)
  //   {
  //     for (int iy = 0; iy < SCREEN_HEIGHT; iy += bH)
  //       {
  //         renderTexture (background, ren, ix, iy);
  //       }
  //   }

  // Get and set the width/height of an image (bmp) loaded
  //int iW, iH;
  //SDL_QueryTexture (image, NULL, NULL, &iW, &iH);
  //int x = SCREEN_WIDTH / 2 - iW / 2;
  //int y = SCREEN_HEIGHT / 2 - iH / 2;
  //renderTexture (image, ren, x, y);

  SDL_Event e;
  bool quit = false;

  while (!quit)
    {
      while (SDL_PollEvent (&e))
        {
          // if user close window
          if (e.type == SDL_QUIT)
            {
              quit = true;
            }

          // key press events
          // https://wiki.libsdl.org/SDL_Keycode
          if (e.type == SDL_KEYDOWN)
            {
              switch (e.key.keysym.sym)
                {
                case SDLK_q:
                  quit = true;
                  break;

                case SDLK_LEFT:
                  MAP.x_offset += MAP.x_offset_increment;
                  break;

                case SDLK_RIGHT:
                  MAP.x_offset -= MAP.x_offset_increment;
                  break;

                case SDLK_UP:
                  MAP.y_offset += MAP.y_offset_increment;
                  break;

                case SDLK_DOWN:
                  MAP.y_offset -= MAP.y_offset_increment;
                  break;

                case SDLK_o:
                  MAP.scale /= 2;
                  break;

                case SDLK_i:
                  MAP.scale *= 2;
                  break;

                default:
                  std::cout << " unmapped key " << e.key.keysym.sym << std::endl;
                  break;
                }
            }

          // mouse click
          if (e.type == SDL_MOUSEBUTTONDOWN)
            {
              quit = true;
            }
        }

      // Present our render as output
      SDL_RenderClear (ren);
      renderMapPoints (ren);
      SDL_RenderPresent (ren);
      //SDL_Delay (300);
    }

  //cleanup (image, background, ren, win);
  cleanup (ren, win);
  SDL_Quit ();

  return 0;
}
