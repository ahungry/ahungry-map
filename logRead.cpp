#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "res_path.h"
#include "LogParser.hpp"

using namespace std;

const std::string resPath = getResourcePath ();
LogParser LOG_PARSER = { resPath + "logs/active.log" };

int main (int, char**)
{
  cout << "Read the log" << endl;

  LOG_PARSER.parse ();

  return 0;
}
