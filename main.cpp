#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "res_path.h"
#include "cleanup.h"
#include "Map.hpp"
#include "MapLine.hpp"
#include "SdlUtil.hpp"

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 640;
Map MAP;// = new Map();
SdlUtil SDL_UTIL;
const std::string resPath = getResourcePath ();

/**
 * Read the current map file, and load up the points
 *
 * @return The generated map points
 */
void setMapSingletons (SDL_Renderer *ren)
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
      std::string t, x1, x2, y1, y2, z1, z2, r, g, b, a, label;

      // File format is as such:
      // L 1186.0742, -2175.0840, 3.1260,  1215.0065, -2174.9312, 3.1260,  150, 0, 200
      if (!(iss >> t >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> r >> g >> b))
        {
          // Attempt to reparse line, accounting for P format
          std::istringstream iss (line);

          if (!(iss >> t >> x1 >> y1 >> z1 >> r >> g >> b >> a >> label))
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
                                      label
                                      );

      // If we have a label, make it a font texture/image
      if (label.length () > 0)
        {
          std::cout << "Found a label: " << label << std::endl;

          // Load up the font file
          SDL_Color color = { 255, 255, 255, 255 };
          SDL_Texture *image = SDL_UTIL.renderText (label, resPath + "fonts/kenpixel.ttf",
                                                    color, 32, ren);
          mapLine->labelImage = image;
        }
      else
        {
          mapLine->labelImage = nullptr;
        }

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
      setMapSingletons (ren);
    }

  // Paint background
  SDL_SetRenderDrawBlendMode (ren, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor (ren, 0x00, 0x00, 0x00, 0xAA);
  SDL_Rect rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
  SDL_RenderFillRect (ren, &rect);

  SDL_SetRenderDrawColor (ren, 0xFF, 0xFF, 0xFF, 0xFF);

  double x1, y1, x2, y2;
  for (uint i = 0; i < MAP.lineSize (); i++)
    {
      MapLine ml = MAP.getLine (i);

      // Dynamically set color per line via the map's request
      SDL_SetRenderDrawColor (ren, ~ml.r, ~ml.g, ~ml.b, 0xFF);

      x1 = (int) MAP.getX (ml.point1.x);
      y1 = (int) MAP.getY (ml.point1.y);
      x2 = (int) MAP.getX (ml.point2.x);
      y2 = (int) MAP.getY (ml.point2.y);

      if (ml.type == "L") {
        SDL_RenderDrawLine (ren, x1, y1, x2, y2);
      } else {
        SDL_Rect rect = { (int) x1, (int) y1, (int) MAP.scale * 10, (int) MAP.scale * 10 };
        SDL_RenderFillRect (ren, &rect);

        // @todo draw the font
        if (ml.labelImage != nullptr)
          {
            //std::cout << "Drawing the font? " << ml.label << std::endl;

            int iW, iH;
            SDL_QueryTexture (ml.labelImage, NULL, NULL, &iW, &iH);
            SDL_UTIL.renderTexture (ml.labelImage, ren, x1, y1,
                                    .6 * MAP.scale * iW,
                                    .6 * MAP.scale * iH);
          }
        else
          {
            SDL_UTIL.logSDLError (std::cout, "LabelImage failure...");
          }
      }
    }
  //SDL_RenderDrawLines (ren, singletonMapPoint, singletonMapPointSize);
}

/*
 * Handle drawing a map
 */
int main (int, char**)
{
  if (SDL_Init (SDL_INIT_EVERYTHING) != 0)
    {
      SDL_UTIL.logSDLError (std::cout, "SDL_Init");
      return 1;
    }

  if (TTF_Init () != 0)
    {
      SDL_UTIL.logSDLError (std::cout, "TTF_Init");
      SDL_Quit ();
      return 1;
    }

  SDL_Window *win = SDL_CreateWindow ("Ahungry Map", 100, 100,
                                      SCREEN_WIDTH,
                                      SCREEN_HEIGHT,
                                      SDL_WINDOW_SHOWN);

  if (win == nullptr)
    {
      SDL_UTIL.logSDLError (std::cout, "CreateWindow");
      SDL_Quit ();
      return 1;
    }

  // -1 means, give us the first renderer that meets the requirements
  SDL_Renderer *ren = SDL_CreateRenderer (win, -1,
                                          SDL_RENDERER_ACCELERATED |
                                          SDL_RENDERER_PRESENTVSYNC);

  if (ren == nullptr)
    {
      SDL_UTIL.logSDLError (std::cout, "SDL_CreateRenderer");
      cleanup (win);
      SDL_Quit ();
      return 1;
    }

  // @todo Uncomment the texture loading below, when ready to load images

  // Store these in our SDL_UTIL to avoid having to pass in params all over
  // As we are only working with one renderer/window per instance of SDL_UTIL
  SDL_UTIL.ren = ren;
  SDL_UTIL.win = win;

  SDL_Texture *background = SDL_UTIL.loadTexture (resPath + "img/grass.bmp", ren);
  //SDL_Texture *image = loadTexture (resPath + "image.bmp", ren);

  if (background == nullptr)// || image == nullptr)
    {
      //cleanup (background, image, ren, win);
      cleanup (background, ren, win);
      SDL_Quit ();
      return 1;
    }

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

  //We'll render the string "TTF fonts are cool!" in white
  //Color is in RGBA format
  SDL_Color color = { 255, 255, 255, 255 };
  SDL_Texture *image = SDL_UTIL.renderText ("Ahungry Map", resPath + "fonts/kenpixel.ttf",
                                   color, 12, ren);

  if (image == nullptr)
    {
      cleanup (ren, win);
      TTF_Quit ();
      SDL_Quit ();
      return 1;
    }

  //Get the texture w/h so we can center it in the screen
  int iW, iH;
  SDL_QueryTexture (image, NULL, NULL, &iW, &iH);
  int fx = SCREEN_WIDTH / 2 - iW / 2;
  int fy = SCREEN_HEIGHT / 2 - iH / 2;

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

                case SDLK_h:
                case SDLK_LEFT:
                  MAP.xOffset += MAP.xOffsetIncrement;
                  break;

                case SDLK_l:
                case SDLK_RIGHT:
                  MAP.xOffset -= MAP.xOffsetIncrement;
                  break;

                case SDLK_k:
                case SDLK_UP:
                  MAP.yOffset += MAP.yOffsetIncrement;
                  break;

                case SDLK_j:
                case SDLK_DOWN:
                  MAP.yOffset -= MAP.yOffsetIncrement;
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
      SDL_UTIL.renderTexture (background, ren, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
      renderMapPoints (ren);
      SDL_UTIL.renderTexture (image, ren, 0, SCREEN_HEIGHT - 50, -1, -1);
      SDL_RenderPresent (ren);
      //SDL_Delay (300);
    }

  //cleanup (image, background, ren, win);
  cleanup (ren, win);
  SDL_Quit ();

  return 0;
}
