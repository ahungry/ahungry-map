#ifndef SDL_UTIL_H
#define SDL_UTIL_H

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



/**
 * Collection of SDL related helper methods from
 *   http://www.willusher.io/pages/sdl2/
 * Wrapped into a class for easy use/re-use
 */
class SdlUtil
{
public:
  double scale = 1;

  SdlUtil ();
  void logSDLError (std::ostream &os, const std::string &msg);
  void renderTexture (SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
  SDL_Texture* loadTexture (const std::string &file, SDL_Renderer *ren);
  SDL_Texture* renderText (const std::string &message, const std::string &fontFile,
                           SDL_Color color, int fontSize, SDL_Renderer *renderer);
};

SdlUtil::SdlUtil()
{
}


/**
 * Log an SDL error with some error message to the output stream of our choie
 *
 * @param os The output stream to write the message to
 * @param msg The error message to write, format will be msg error: SDL_GetError ()
 */
void SdlUtil::logSDLError(std::ostream &os, const std::string &msg)
{
  os << msg << " error: " << SDL_GetError () << std::endl;
}

/**
 * Draw an SDL_Texture to an SDL_Renderer at position x,y, preserving the width/height
 *
 * @param tex The source texture we want to draw
 * @param ren The renderer we want to draw to
 * @param x The x coordinate to draw to
 * @param y The y coordinate to draw to
 * @param w The width
 * @param h The height
 */
void SdlUtil::renderTexture (SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
  // Setup the destination rectangle to be at the position we want
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  dst.w = w;
  dst.h = h;

  // If width or height is negative, render as same size of the image
  if (w < 0 || h < 0)
    {
      // Query the texture to get its width and height to use
      SDL_QueryTexture (tex, NULL, NULL, &dst.w, &dst.h);
    }

  SDL_RenderCopy (ren, tex, NULL, &dst);
}

/**
 * Loads a BMP image into a texture on the rendering device
 *
 * @param file The BMP image file to load
 * @param ren The renderer to load the texture onto
 * @return The loaded texture, or nullptr if something went wrong
 */
SDL_Texture* SdlUtil::loadTexture (const std::string &file, SDL_Renderer *ren)
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
 * Render the message we want to display to a texture for drawing
 * @param message The message we want to display
 * @param fontFile The font we want to use to render the text
 * @param color The color we want the text to be
 * @param fontSize The size we want the font to be
 * @param renderer The renderer to load the texture in
 * @return An SDL_Texture containing the rendered message, or nullptr if something went wrong
 */
SDL_Texture* SdlUtil::renderText (const std::string &message, const std::string &fontFile,
                         SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
  //Open the font
  TTF_Font *font = TTF_OpenFont (fontFile.c_str (), fontSize);

  if (font == nullptr)
    {
      logSDLError (std::cout, "TTF_OpenFont");
      return nullptr;
    }

  //We need to first render to a surface as that's what TTF_RenderText
  //returns, then load that surface into a texture
  SDL_Surface *surf = TTF_RenderText_Blended (font, message.c_str (), color);

  if (surf == nullptr)
    {
      TTF_CloseFont (font);
      logSDLError (std::cout, "TTF_RenderText");
      return nullptr;
    }

  SDL_Texture *texture = SDL_CreateTextureFromSurface (renderer, surf);

  if (texture == nullptr)
    {
      logSDLError (std::cout, "CreateTexture");
    }

  //Clean up the surface and font
  SDL_FreeSurface (surf);
  TTF_CloseFont (font);

  return texture;
}

#endif
