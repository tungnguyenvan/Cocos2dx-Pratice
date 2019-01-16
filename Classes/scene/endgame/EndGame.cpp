//
// Created by tung on 16/01/2019.
//

#include "util/Definition.h"
#include "EndGame.h"
#include "cocos2d.h"
#include "model/background/Background.h"

using namespace cocos2d;

cocos2d::Scene* EndGame::createScene(int score) {
    return EndGame::create();
}

bool EndGame::init() {
    if (!Scene::init()) return false;

    mVisibleSize = Director::getInstance()->getVisibleSize();

    mBackground = new Background(this);

    //Create label name game
    mLbNameGame = Label::createWithTTF(GAME_NAME, FONT_PATH, 100);
    mLbNameGame->setPosition(Vec2(mVisibleSize.width * 0.5, mVisibleSize.height * 0.8));
    this->addChild(mLbNameGame);

    return true;
}