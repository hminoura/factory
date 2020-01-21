#include "BasketBall.h"
#include "TextureManager.h"

BasketBall::BasketBall()
{
}

BasketBall::~BasketBall()
{
}

void BasketBall::init()
{
  Ball::init();

  texture = TextureManager::getInstance()->get("basketball.png");

  sprite.setTexture(*texture, true);
  auto size = texture->getSize()/2u;
  sprite.setOrigin(size.x, size.y);
}
