#pragma once
#include "Timer.h"
#include <SFML/Graphics.hpp>

class Ball {
protected:
  double x, y;
  double vx, vy;
  double ax, ay;

  Timer timer;
  Timer rap;

  sf::Texture* texture;
  sf::Sprite sprite;

 public:
  Ball();
  virtual ~Ball();

  virtual void init();
  virtual void update();
  virtual void draw();
  virtual void clean();
};
