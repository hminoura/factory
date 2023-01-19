TARGET = ball

SRCS   = main.cpp App.cpp Timer.cpp Rand.cpp BallApp.cpp TextureManager.cpp Ball.cpp BasketBall.cpp BaseBall.cpp TennisBall.cpp
OBJS   = $(SRCS:%.cpp=%.o)
## for macOS (SFML: brew)
#CXX    = clang++
#CXXFLAGS = -std=c++11 -Wc++11-extensions -g

## for Linux (SfLinux
CXX    = c++
CXXFLAGS = -std=c++11 -g
#INCLUDES = -I/usr/local/include
#LDFLAGS = -L/usr/local/lib
#LIBS     = -lsfml-graphics -lsfml-window -lsfml-system
LIBS    = `pkg-config --libs sfml-all`

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o  $@ $^ $(LDFLAGS) $(LIBS)
	strip $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< 

.PHONY: clean

clean:
	rm -f *.o *~ $(TARGET)

run: $(TARGET)
	./$(TARGET)

App.o: App.h
Ball.o: Ball.h Rand.h BallApp.h TextureManager.h
BallApp.o: BallApp.h Rand.h Ball.h BasketBall.h BaseBall.h TennisBall.h
BaseBall.o: BaseBall.h TextureManager.h
BasketBall.o: BasketBall.h TextureManager.h
Rand.o: Rand.h
TennisBall.o: TennisBall.h TextureManager.h TextureManager.h
Timer.o: Timer.h
main.o: BallApp.h

