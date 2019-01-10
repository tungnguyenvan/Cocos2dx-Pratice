#include <iostream>
#include <vector>
#include "GamePlay.h"
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

GamePlay::GamePlay() {
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("walk.plist");
	this->animationFrames = GamePlay::getAnnimation("spritesheet_0%d.png", 5);
	this->mGamePlay = Sprite::createWithSpriteFrame(animationFrames.front());
}

GamePlay::~GamePlay() {

}

cocos2d::Sprite *GamePlay::GetGamePlay() {
	return this->mGamePlay;
}

Vector<SpriteFrame*> GamePlay::getAnnimation(const char *prefix, int count) {
	auto spritecache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> spriteFrames;
	char str[100];
	for (int i = 1; i < count; i++) {
		sprintf(str, prefix, i);
		CCLOG(str);
		spriteFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}

	return spriteFrames;
}

void GamePlay::SetPosition(float x, float y) {
	this->mGamePlay->setPosition(Vec2(x, y));
}

void GamePlay::Run() {
	auto animation = Animation::createWithSpriteFrames(animationFrames, 0.2);
	this->mGamePlay->runAction(RepeatForever::create(Animate::create(animation)));
}
