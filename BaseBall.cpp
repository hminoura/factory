#include "BaseBall.h"
#include "TextureManager.h"

BaseBall::BaseBall()
{
}

BaseBall::~BaseBall()
{
}

void BaseBall::init()
{
  Ball::init();

  texture = TextureManager::getInstance()->get("baseball.png");

  sprite.setTexture(*texture, true);
  auto size = texture->getSize()/2u;
  sprite.setOrigin(size.x, size.y);
}
