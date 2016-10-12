#ifndef LOG_PARSER_H
#define LOG_PARSER_H

#define ZONE_MAX 50
#define LOC_MAX 100

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/**
 * Class for storing the logParser lines and handling scaling values for the logParser we render
 */
class LogParser
{
  FILE *fp;
  char line[255];
  char *c;
  std::string regex = "You have entered";
  long fileSize;
public:
  char zone[ZONE_MAX];
  char location[LOC_MAX];
  double x, y;

  LogParser (std::string fn);
  ~LogParser ();
  void parse ();
  void setXandY (char *location);
  bool hasNewSize ();
};

LogParser::LogParser (std::string fn)
{
  std::cout << " logParser init " << std::endl;

  // Open up our file for reading
  fp = fopen (fn.c_str (), "r");

  if (fp == NULL)
    {
      fputs ("Failed to open file\n", stderr);
      exit (EXIT_FAILURE);
    }
}

LogParser::~LogParser ()
{
  fclose (fp);
}

void LogParser::setXandY (char *location)
{
  // @todo This could probably be cleaned up, especially if using some C++ not just C
  printf ("Working on parsing '%s'\n", location);
  char x[10], y[10];
  char c;
  double dx, dy;
  bool comma = false;
  int xi = 0;
  int yi = 0;

  for (uint i = 0; i < strlen (location); i++)
    {
      c = location[i];

      // Abort on second comma
      if (c == ',' && comma)
        {
          y[yi] = '\0';
          break;
        }
      else if (c == ',')
        {
          x[xi] = '\0';
          comma = true;
          continue;
        }

      // Otherwise, read into y
      if (comma)
        {
          y[yi++] = location[i];
        }
      else
        {
          x[xi++] = location[i];
        }
    }

  dx = atof (x);
  dy = atof (y);
  printf ("Found X: %f, and Y: %f\n", dx, dy);

  this->x = dx;
  this->y = dy;
}

/**
 * Check if the file has a different line count or not
 */
bool LogParser::hasNewSize ()
{
  long size;
  rewind (fp);
  fseek (fp, 0, SEEK_END);
  size = ftell (fp);
  rewind (fp);

  if (size == fileSize)
    {
      return false;
    }
  else
    {
      fileSize = size;
      return true;
    }
}

void LogParser::parse ()
{
  if (!hasNewSize ())
    {
      printf ("Skipping log parse, size hasn't changed...\n");
    }

  char *found;
  char zone[ZONE_MAX];
  char location[LOC_MAX];

  do {
    c = fgets (line, 255, fp);

    if (c != NULL)
      {
        // If we hit this, we are changing zones on this line
        if ((found = strstr(c, "You have entered ")) != NULL)//!regexec (preg, c, 0, 0, 0))
          {
            strcpy (zone, found + 17);
            zone[strlen(zone) - 3] = '\0';
          }

        // If we hit this, we are finding coordinates
        if ((found = strstr(c, "Your Location is ")) != NULL)
          {
            strcpy (location, found + 17);
            location[strlen(location) - 2] = '\0';
          }
      }
  } while (c != NULL);

  strcpy (this->zone, zone);
  strcpy (this->location, location);
  setXandY (location);

  printf ("Zone was '%s'\n", this->zone);
  printf ("Location was '%s'\n", this->location);
}

#endif
