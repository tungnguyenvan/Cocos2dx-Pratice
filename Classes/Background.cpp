#include <iostream>
#include "cocos2d.h"
#include "Background.h"

using namespace cocos2d;

Background::Background() {
	this->mBackground = Sprite::create("gaERSZ.png");
	this->mBackground->setAnchorPoint(Vec2(0, 0));
}

Background::~Background() {

}

Sprite *Background::GetBackground() {
	return this->mBackground;
}

void Background::RunAction() {
}