#ifndef RES_PATH_H
#define RES_PATH_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

/*
 * Code samples for this template taken from tutorial at:
 *   http://www.willusher.io/pages/sdl2/
 *
 * Get the resource path for the resources located in res/subDir
 * It's assumed the project directory is structured like:
 * bin/
 *  the executable
 * res/
 *  Lesson1/
 *  Lesson2/
 *
 * Paths returned will be Lessons/res/subDir
 */
std::string getResourcePath(const std::string &subDir = "")
{
  // Path based on OS
#ifdef _WIN32
  const char PATH_SEP = '\\';
#else
  const char PATH_SEP = '/';
#endif

  // Hold base resource path: Lessons/res/
  // Give it a static lifetime
  // so that we only need to call SDL_GetBasePath once to get it
  static std::string baseRes;

  if (baseRes.empty())
    {
      // SDL_GetBasePath will return NULL if something went wrong
      char *basePath = SDL_GetBasePath();

      if (basePath)
        {
          baseRes = basePath;
          SDL_free(basePath);
        }
      else
        {
          std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;

          return "";
        }

      // Replace the last bin/ with res/ to get the resource path
      size_t pos = baseRes.rfind("bin");
      baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
    }

  // If we want a specific subdirectory path in the resource directory
  // append it to the base path.  Something lie Lessons/res/Lesson0
  return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
}
#endif
