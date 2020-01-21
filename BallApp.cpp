#include <random>
#include "BallApp.h"
#include "Timer.h"
#include "Ball.h"
#include "BasketBall.h"
#include "BaseBall.h"
#include "TennisBall.h"

using namespace std;

BallApp::BallApp(){
  setKeyboardListener(this);
  setMouseListener(this);
}

BallApp::~BallApp(){
}

void BallApp::init()
{
  random_device rnd;
  uniform_int_distribution<int> d(0, 9);

  balls.resize(100);

  for (auto& b : balls) {
    int p = d(rnd);
    if (p < 1)
      b = new BasketBall;
    else if (p < 5)
      b = new BaseBall;
    else
      b = new TennisBall;

    b->init();
  }
}

void BallApp::update()
{
  for (auto& b : balls)
    b->update();
}

void BallApp::draw()
{
  window.clear(sf::Color::White);

  for (auto& b : balls)
    b->draw();

  window.display();
}

void BallApp::clean()
{
  for (auto& b : balls) {
    b->clean();
    delete b;
  }
}  

void BallApp::onKeyDown(sf::Keyboard::Key key){
  if (key==sf::Keyboard::Escape){
    window.close();
  }
}

void BallApp::onMouseMoved(sf::Event::MouseMoveEvent mouse){
}

void BallApp::onClick(sf::Event::MouseButtonEvent mouse){
}

void BallApp::offClick(sf::Event::MouseButtonEvent mouse){
}




