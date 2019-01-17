//
// Created by tung on 17/01/2019.
//

#include "CoreModel.h"
#include "cocos2d.h"

CoreModel::CoreModel() {
    mVisibleSize = Director::getInstance()->getVisibleSize();
}

Vec2 CoreModel::GetLocation() {
    return mSprite->getPosition();
}

Rect CoreModel::GetBoundingBox() {
    return mSprite->getBoundingBox();
}

bool CoreModel::IsAlive() {
    return mAlive;
}

void CoreModel::SetAlive(bool alive) {
    mAlive = alive;
    mSprite->setVisible(mAlive);
}
