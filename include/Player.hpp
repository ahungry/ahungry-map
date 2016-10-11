#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>

/**
 * Class for storing the player loc and name
 */
class Player
{
public:
  int x = 0;
  int y = 0;
  std::string name = "Player";
  SDL_Texture* labelImage = nullptr;
  Player (int x, int y);
};

Player::Player (int x, int y)
{
  this->x = x;
  this->y = y;
  std::cout << " player init " << std::endl;
}

#endif
