
CXX = g++
CXXFLAGS = -std=c++17 -Wall $(shell pkg-config --cflags sdl2 SDL2_image)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_image)
	
TARGET = sdltest
SRCS = main.cpp src/game.cpp src/textureManage.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = src/game.h src/textureManage.h

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: run clean
