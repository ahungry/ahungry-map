CXX = g++

SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib -lSDL2_ttf
SDL_INCLUDE = -I/usr/local/include

CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE) -Iinclude
LDFLAGS = $(SDL_LIB)
EXE = bin/ahungry-map
LOGEXE = bin/log-read

all: $(EXE) $(LOGEXE)

$(EXE): main.o
	$(CXX) $< $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

$(LOGEXE): logRead.o
	$(CXX) $< $(LDFLAGS) -o $@

logRead.o: logRead.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE) && rm $(LOGEXE)
