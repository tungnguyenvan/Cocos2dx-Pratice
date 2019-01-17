//
// Created by tung on 15/01/2019.
//

#include "util/Definition.h"
#include "model/rock/Rock.h"
#include "cocos2d.h"
#include "util/spriteframe/UtilSpriteFrames.h"

using namespace cocos2d;

Rock::Rock() {

}

Rock::Rock(Scene *layer) {
    mVisibleSize = Director::getInstance()->getVisibleSize();
    mRandomTime = RandomHelper::random_real(ROCK_MIN_FALL_TIME, ROCK_MAX_FALL_TIME);

    int randType =  RandomHelper::random_int(1, 2);
    if (randType == 1) {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ROCK_1_PLIST_FILE_PATH);
        mSpriteFrames = UtilSpriteFrames::GetSpriteFrame(FORMAT_1_ROCK_NAME, 15);
    }else {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ROCK_2_PLIST_FILE_PATH);
        mSpriteFrames = UtilSpriteFrames::GetSpriteFrame(FORMAT_2_ROCK_NAME, 15);
    }

    mAnimation = UtilSpriteFrames::GetAnimationRepeatForever(mSpriteFrames, mRandomTime * 0.7);
    mSprite = Sprite::createWithSpriteFrame(mSpriteFrames.front());
    if (randType == 2) mSprite->setScale(0.5);
    mSprite->setPosition(Vec2(0, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));
    mSprite->runAction(mAnimation);

    Rock::SetInVisible();
    layer->addChild(mSprite);
}

void Rock::Fall() {
    mAlive = true;
    this->SetVisible();

    int x = RandomHelper::random_int(50, (int) mVisibleSize.width - 50);
    mSprite->setPosition(Vec2(x, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));

    auto fall = MoveTo::create(mSprite->getContentSize().width * mRandomTime,
                               Vec2(x, - mSprite->getContentSize().height));

    auto callbackFallSuccess = CallFunc::create([=](){
       Rock::OnFallFinish();
    });

    mAction = Sequence::create(fall, callbackFallSuccess, nullptr);
    mSprite->runAction(mAction);
}

Vec2 Rock::GetLocation() {
    return mSprite->getPosition();
}

void Rock::SetVisible() {
    mSprite->setVisible(true);
}

void Rock::SetInVisible() {
    mSprite->setVisible(false);
}

void Rock::OnFallFinish() {
    mAlive = false;
    this->SetInVisible();
    mSprite->setPosition(Vec2(0, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));
    mSprite->stopAction(mAction);
}

Rect Rock::GetBoundingBox() {
    return mSprite->getBoundingBox();
}

bool Rock::GetAlive() {
    return mAlive;
}