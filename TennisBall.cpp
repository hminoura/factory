#include "TennisBall.h"
#include "TextureManager.h"

TennisBall::TennisBall()
{
}

TennisBall::~TennisBall()
{
}

void TennisBall::init()
{
  Ball::init();

  texture = TextureManager::getInstance()->get("tennisball.png");

  sprite.setTexture(*texture, true);
  auto size = texture->getSize()/2u;
  sprite.setOrigin(size.x, size.y);
}
