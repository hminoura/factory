TARGET = main

SRCS   = $(TARGET).cpp App.cpp Timer.cpp Rand.cpp BallApp.cpp TextureManager.cpp Ball.cpp BasketBall.cpp BaseBall.cpp TennisBall.cpp
OBJS   = $(SRCS:%.cpp=%.o)
## for macOS (SFML: brew)
#CXX    = clang++
#CXXFLAGS = -std=c++11 -Wc++11-extensions -g

## for Linux (SfLinux
CXX    = c++
CXXFLAGS = -std=c++11 -g
#INCLUDES = -I/usr/local/include
#LDFLAGS = -L/usr/local/lib
LIBS     = -lsfml-graphics -lsfml-window -lsfml-system

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o  $@ $^ $(LDFLAGS) $(LIBS)
	strip $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< 

.PHONY: clean

clean:
	rm -f *.o *~ $(TARGET)

run:
	export LD_LIBRARY_PATH=/opt/local/SFML-2.3.2/lib && ./$(TARGET)
