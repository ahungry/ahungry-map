#ifndef ZONE_LIST_H
#define ZONE_LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct Zone
{
  char name[100];
  char file[100];
} zone;

/**
 * Class for storing the ZoneList (parser names to file names)
 */
class ZoneList
{
  std::vector<Zone> zones;
public:
  ZoneList (std::string zoneFile);
  std::string get (std::string parseName);
  void parse (std::string zoneFile);
};

ZoneList::ZoneList (std::string zoneFile)
{
  std::cout << " zoneList init " << std::endl;
  parse (zoneFile);
}

void ZoneList::parse (std::string zoneFile)
{
  std::ifstream infile (zoneFile.c_str ());
  std::string line;
  char *zoneName;
  char *fileName;
  char buf[256];

  while (std::getline (infile, line))
    {
      std::cout << "Read" << line << std::endl;

      // Read in line and split on delimiter
      strcpy (buf, line.c_str ());
      zoneName = strtok (buf, ";");
      fileName = strtok (NULL, ";");

      Zone zone;
      strcpy (zone.name, zoneName);
      strcpy (zone.file, fileName);
      zones.push_back (zone);
    }

  printf ("%d zones loaded...\n", (int) zones.size ());
}

std::string ZoneList::get (std::string parseName)
{
  for (uint i = 0; i < zones.size (); i++)
    {
      if (strcmp (zones[i].name, parseName.c_str ()) == 0)
        {
          return zones[i].file;
        }
    }

  return "";
}

#endif
