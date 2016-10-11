#ifndef LOG_PARSER_H
#define LOG_PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

/**
 * Class for storing the logParser lines and handling scaling values for the logParser we render
 */
class LogParser
{
  FILE *fp;
  char line[255];
  char *c;
  std::string regex = "You have entered";
public:
  char *zone;
  LogParser (std::string fn);
  ~LogParser ();
  void parse ();
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

void LogParser::parse ()
{
  regex_t *preg = (regex_t*) calloc (1, sizeof (regex_t));
  regcomp (preg, regex.c_str (), REG_EXTENDED | REG_NOSUB);
  char found[255];

  do {
    c = fgets (line, 255, fp);
    if (c != NULL && !regexec (preg, c, 0, 0, 0))
      {
        strcpy(found, c);
      }
  } while (c != NULL);

  regfree (preg);

  // Just snag the zone name
  char zone[40];
  strcpy (zone, strstr(found, "You have entered ") + 17);
  zone[strlen(zone) - 3] = '\0';
  this->zone = zone;

  printf ("Last found was '%s'\n", this->zone);
}

#endif
