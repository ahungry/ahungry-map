CXX = g++

SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib -lSDL2_ttf
SDL_INCLUDE = -I/usr/local/include

CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE) -Iinclude
LDFLAGS = $(SDL_LIB)
EXE = bin/ahungry-map

all: $(EXE)

$(EXE): main.o
	$(CXX) $< $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
