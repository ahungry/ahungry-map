# Ahungry Map

This is a rewrite of https://github.com/ahungry/p99-patcher map
portion in C++.

The original p99-patcher is a collection of tools for the Project1999
EverQuest emulator/server.

The general idea of this is that it parses your log file, and draws a
map of the current zone you're in.

## Installation/building
Run the following (only tested on GNU/Linux so far):

```
git clone https://github.com/ahungry/ahungry-map.git
cd ahungry-map
make
./bin/ahungry-map
```

## TODO

This is heavily WIP at the moment, so don't expect to use it
immediately.

I'll update this, but main tasks to go:

- Realtime parsing of the log file
- Dynamic zone/map change
- Precompiled binary downloads
- General code cleanup/refactoring

## License
GPLv3
